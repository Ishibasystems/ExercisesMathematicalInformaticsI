/* �������w���KI kadai0420.c */
/* 2011.04.20, 10RU999, Taro Dendai */

#include <stdio.h>    /* �W�����͊֐��̓ǂݍ��� */
#include <stdlib.h>   /* �W�����C�u�����֐��̓ǂݍ��� */

int main(void)
{
	int i, n, border, high = 0, low = 100;	                /* n�͔z��̗v�f�� */
	int array[100];			/* �z��̒�` */

	printf("�N���X�̐l������͂��ĉ����� (1-100): ");
	scanf("%d", &n);

	if ( n < 1 || n > 100 ) {
		printf("�l���𐳂������͂��ĉ������D\n");
		return 0;
	}

	printf("�_������͂��ĉ����� (0-100): \n");

	for ( i = 0; i < n; i++ ) {		/* �z��̗v�f����� */
		scanf("%d", &array[i]);
		if ( array[i] < 0 || array[i] > 100 ) {
			printf("�_���𐳂������͂��ĉ������D\n");
			return 0;
		}
	}

	printf("���i�_����͂��ĉ����� (0-100): \n");
	scanf("%d", &border);

	if ( border < 0 || border > 100 ) {
		printf("�_���𐳂������͂��ĉ������D\n");
		return 0;
	}

	printf("���i�҈ꗗ----------------- \n");
	for ( i = 0; i < n; i++ ) {		/* ���i�� */
		if ( high < array[i] ) high = array[i];
		if ( low > array[i] ) low = array[i];
		if ( array[i] >= border )
			printf("No.%d�F%d�_\n", i + 1, array[i]);
	}

	printf("�ō��_ %d�_\n�Œ�_ %d�_\n", high, low);

	return 0;
}
