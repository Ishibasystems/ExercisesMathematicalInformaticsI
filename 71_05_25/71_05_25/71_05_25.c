/* �������w���KI 71_05_25.c */
/* 2011.05.29, 10RU004, Ishibashi Shota */

#include "Polish_Notation.h"

void input(char s[], long len)
{
	fgets(s, len, stdin);

	if (strchr(s, '\n') != 0) s[strlen(s) - 1] = '\0';	// ���s�̓L�[�{�[�h���͂̏I�[
	else while(getchar() != '\n');	// ���s���Ȃ��A�ł����s�܂Ńo�b�t�@�𑖂点��

	return;
}

int main(void)
{
	char s[LIMIT];

	for(;;)
	{
		printf("�t�|�[�����h�L�@��(�X�y�[�X��؂�)����͂��Ă��������B(�g�p�ł��鉉�Z�q: +-*/%%^)\n");
		input(s, LIMIT);

		printf("Finish!: %d\n\n", Polish_Notation(s));
	}
	return 0;
}
