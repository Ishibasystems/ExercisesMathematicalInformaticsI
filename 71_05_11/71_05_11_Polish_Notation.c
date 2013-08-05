/* 数理情報学演習I 71_05_11_Polish_Notation.c */
/* 2011.05.12, 10RU004, Ishibashi Shota */

#include <stdio.h>	/* 標準入出力関数 */
#include <stdlib.h>	/* 標準ライブラリ関数 */

#define LIMIT		20		/* スタックに入る数の最大値　*/
#define OVERFLOW	-10000
#define UNDERFLOW	-20000
#define LINEMAX		0x100

int push(int *, int *, int);	/* 関数のプロトタイプ宣言 */
int pop(int *, int *);			/* 関数のプロトタイプ宣言 */

int main(void)
{
	int action, x, y, top, stack[LIMIT], cnt;
	char s[LINEMAX], u = '\0';
	top = 0;
	printf("逆ポーランド記法の式を入力してください。数字は0-9、演算子は+-*/%%に対応。\n");
	gets(s);
	for(cnt = 0; s[cnt] != '\0'; cnt++)
	{
		//START
		u = s[cnt];
		if ('0' <= u && u <= '9') if (push(stack, &top, atoi(&u)) == OVERFLOW) printf("stack overflow\n");

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
			else printf("Warning: スタックが残っていません。演算子が多すぎるようです。無視します。\n");
		}
		//END
	}
	printf("Finish!: 計算完了！\n");
	if (top > 1)printf("Warning: スタックがまだ残っています。演算子が足りないようです。\n");
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
