/* 数理情報学演習I Polish_Notation.c */
/* 2011.05.13, 10RU004, Ishibashi Shota */

#include "Polish_Notation.h"

int Polish_Notation(const char s[])
{
	int cnt, intstack = 0, inv = 0, x, top = 0, stack[LIMIT];
	char u, u_ = '\0';

	for(cnt = 0; s[cnt] != '\0'; cnt++)
	{
		u = s[cnt];
		if ('0' <= u && u <= '9') intstack = intstack * 10 + u - '0';	// 数字が来たらintstackの一の桁に数字追加

		else if ('0' <= u_ && u_ <= '9')	// 数字後に非数字が来たらintstackをスタックにフラッシュ
		{
			if (inv == 1) intstack = -intstack;	// 数字の先頭にマイナスが付いていたら負数

			push(stack, &top, intstack);	// スタックにプッシュ

			intstack = inv = 0;
		}

		else if (u == '-' && '0' <= s[cnt + 1] && s[cnt + 1] <= '9') inv = 1;	// マイナスが付いていて直後に数字が来たら負数

		// 演算子のお仕事
		else if (u == '+' || u == '-' || u == '*' || u == '/' || u == '%' || u == '^')
		{
			if (top > 1)	// 演算はスタックに2つ数があることが条件
			{
				x =  pop(stack, &top);	// 一つ目取り出し
				switch(u)
				{
				// 二つ目取り出し & 演算 & 演算結果をスタックにプッシュ
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
					push(stack, &top, x);	// 一つ目を戻す
					break;
				}
			}
			else printf("Warning: スタックが残っていません。演算子が多すぎるようです。無視します。\n");
		}
		u_ = u;
	}

	if (top > 1)printf("Warning: スタックがまだ残っています。演算子が足りないようです。\n");

	return pop(stack, &top);
}

int hatfunc(int x, int y)
{
	int cnt, c = 1;

	for(cnt = 0; cnt < y; cnt++) c *= x;	// y回xを掛けるだけ

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
