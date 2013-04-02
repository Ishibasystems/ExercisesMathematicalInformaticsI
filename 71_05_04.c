/* 数理情報学演習I 71_05_04.c */
/* 2011.05.04, 10RU004, Ishibashi Shota */

#include <stdio.h>	/* 標準入出力関数 */
#include <stdlib.h>	/* 標準ライブラリ関数 */

#define LIMIT		3		/* スタックに入る数の最大値　*/
#define OVERFLOW	-10000
#define UNDERFLOW	-20000

int push(int *, int *, int);	/* 関数のプロトタイプ宣言 */
int pop(int *, int *);			/* 関数のプロトタイプ宣言 */

int main(void)
{
	int action, x, y, top, stack[LIMIT];
	top = 0;
	while(1)
	{
		printf("\n現在のデータ数：%d\n", top);
		printf("(1) push (2) pop (3) finish (4) CALC: ");
		scanf("%d", &action);

		switch(action)
		{
		case 1:
			printf("input data: ");
			scanf("%d", &x);
			if (push(stack, &top, x) == OVERFLOW) printf("stack overflow\n");
			break;

		case 2:
			x = pop(stack, &top);
			if (x == UNDERFLOW) printf("stack underflow\n");
			else printf("poped data: %d", x);
			break;

		case 3:
			return 0;

		case 4:
			x = pop(stack, &top);
			printf("CALC: ");
			getchar();
			y = getchar();
			switch(y)
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
				printf("please input +, -, *, / or %%");
				push(stack, &top, x);
				break;
			}
			break;

		default:
			puts("please input 1, 2, 3 or 4");
			break;
		}
	}
}
int push(int stack[], int *top, int x)
{
	if (*top < LIMIT)
	{
		stack[*top] = x;
		(*top)++;
		return 0;
	}
	else return OVERFLOW;
}

int pop(int stack[], int *top)
{
	if (*top != 0)
	{
		(*top)--;
		return stack[*top];
	}
	else return UNDERFLOW;
}
