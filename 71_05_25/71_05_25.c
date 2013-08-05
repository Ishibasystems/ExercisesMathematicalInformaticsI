/* 数理情報学演習I 71_05_25.c */
/* 2011.05.29, 10RU004, Ishibashi Shota */

#include "Polish_Notation.h"

void input(char s[], long len)
{
	fgets(s, len, stdin);

	if (strchr(s, '\n') != NULL) s[strlen(s) - 1] = '\0';
	else while(getchar() != '\n');

	return;
}

int main(void)
{
	char s[LIMIT];

	for(;;)
	{
		printf("逆ポーランド記法式(スペース区切り)を入力してください。(使用できる演算子: +-*/%%^)\n");
		input(s, LIMIT);

		printf("Finish!: %d\n\n", Polish_Notation(s));
	}
	return 0;
}
