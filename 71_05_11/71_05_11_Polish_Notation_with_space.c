/* �������w���KI 71_05_11_Polish_Notation_with_space.c */
/* 2011.05.12, 10RU004, Ishibashi Shota */

#include <stdio.h>	/* �W�����o�͊֐� */
#include <stdlib.h>	/* �W�����C�u�����֐� */

#define LIMIT		20		/* �X�^�b�N�ɓ��鐔�̍ő�l�@*/
#define OVERFLOW	-10000
#define UNDERFLOW	-20000
#define LINEMAX		0x100

int push(int *, int *, int);	/* �֐��̃v���g�^�C�v�錾 */
int pop(int *, int *);			/* �֐��̃v���g�^�C�v�錾 */

int main(void)
{
	int action, x, y, top, stack[LIMIT], cnt, intstack = 0, inv = 0;
	char s[LINEMAX], u = '\0', u_;
	top = 0;
	printf("�t�|�[�����h�L�@�̎�����͂��Ă��������B���Z�q��+-*/%%�ɑΉ��B\n�X�y�[�X��؂���g�p���Đ���2147483647�`-2147483648�܂ň������Ƃ��ł��܂�\n��) 2147483647 12 / 78 -\n");
	gets(s);
	for(cnt = 0; s[cnt] != '\0'; cnt++)
	{
		//START
		u = s[cnt];
		if ('0' <= u && u <= '9') intstack = intstack * 10 + u - '0';

		if (u == ' ' && '0' <= u_ && u_ <= '9')
		{
			if (inv == 1)
			{
				inv = 0;
				intstack = -intstack;
			}
			if (push(stack, &top, intstack) == OVERFLOW) printf("stack overflow\n");
			intstack = 0;
		}

		if (u == '+' || u == '-' || u == '*' || u == '/' || u == '%')
		{
			if (top > 1)
			{
				x =  pop(stack, &top);
				switch(u)
				{
				case '+':
					push(stack, &top, pop(stack, &top) + x);
					break;

				case '-':
					if ('0' <= s[cnt + 1] && s[cnt + 1] <= '9')
					{
						inv = 1;
						break;
					}
					push(stack, &top, pop(stack, &top) - x);
					break;

				case '*':
					push(stack, &top, pop(stack, &top) * x);
					break;

				case '/':
					push(stack, &top, pop(stack, &top) / x);
					break;

				case '%':
					push(stack, &top, pop(stack, &top) % x);
					break;

				default:
					push(stack, &top, x);
					break;
				}
			}
			else printf("Warning: �X�^�b�N���c���Ă��܂���B���Z�q����������悤�ł��B�������܂��B\n");
		}
		u_ = u;
		//END
	}
	printf("Finish!: �v�Z�����I\n");
	if (top > 1)printf("Warning: �X�^�b�N���܂��c���Ă��܂��B���Z�q������Ȃ��悤�ł��B\n");
	for(cnt = top; cnt > 0; cnt--) printf("STACK %02d: %d\n", cnt, pop(stack, &top));
}

int push(int stack[], int *top, int x)
{
	if (*top >= LIMIT) return OVERFLOW;

	stack[(*top)++] = x;
	return 0;
}

int pop(int stack[], int *top)
{
	if (*top <= 0) return UNDERFLOW;

	return stack[--(*top)];
}
