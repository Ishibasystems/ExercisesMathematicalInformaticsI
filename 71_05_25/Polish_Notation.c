/* �������w���KI Polish_Notation.c */
/* 2011.05.13, 10RU004, Ishibashi Shota */

#include "Polish_Notation.h"

int Polish_Notation(const char s[])
{
	int cnt, intstack = 0, inv = 0, x, top = 0, stack[LIMIT];
	char u, u_ = '\0';

	for(cnt = 0; s[cnt] != '\0'; cnt++)
	{
		u = s[cnt];
		if ('0' <= u && u <= '9') intstack = intstack * 10 + u - '0';

		else if ('0' <= u_ && u_ <= '9')	//������ɔ񐔎���������intstack���X�^�b�N�Ƀt���b�V��
		{
			if (inv == 1) intstack = -intstack;	//�����̐擪�Ƀ}�C�i�X���t���Ă����畉��

			push(stack, &top, intstack);

			intstack = inv = 0;
		}

		else if (u == '-' && '0' <= s[cnt + 1] && s[cnt + 1] <= '9')	//�}�C�i�X���t���Ă��ăX�y�[�X�����Ő����������畉��
			inv = 1;

		else if (u == '+' || u == '-' || u == '*' || u == '/' || u == '%' || u == '^')
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

				case '^':
					push(stack, &top, hatfunc(pop(stack, &top), x));
					break;

				default:
					push(stack, &top, x);
					break;
				}
			}
			else printf("Warning: �X�^�b�N���c���Ă��܂���B���Z�q����������悤�ł��B�������܂��B\n");
		}
		u_ = u;
	}

	if (top > 1)printf("Warning: �X�^�b�N���܂��c���Ă��܂��B���Z�q������Ȃ��悤�ł��B\n");

	return pop(stack, &top);
}

int hatfunc(int x, int y)
{
	int cnt, c = 1;

	for(cnt = 0; cnt < y; cnt++) c *= x;

	return c;
}

int push(int stack[], int *top, const int x)
{
	if (*top >= LIMIT)
	{
		printf("stack break!\n");
		return 0;
	}

	stack[(*top)++] = x;
	return 0;
}

int pop(const int stack[], int *top)
{
	if (*top <= 0)
	{
		printf("stack break!\n");
		return 0;
	}

	return stack[--(*top)];
}
