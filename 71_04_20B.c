/* 数理情報学演習I kadai0420.c */
/* 2011.04.20, 10RU999, Taro Dendai */

#include <stdio.h>    /* 標準入力関数の読み込み */
#include <stdlib.h>   /* 標準ライブラリ関数の読み込み */

int main(void)
{
	int i, n, border, high = 0, low = 100;	                /* nは配列の要素数 */
	int array[100];			/* 配列の定義 */

	printf("クラスの人数を入力して下さい (1-100): ");
	scanf("%d", &n);

	if ( n < 1 || n > 100 ) {
		printf("人数を正しく入力して下さい．\n");
		return 0;
	}

	printf("点数を入力して下さい (0-100): \n");

	for ( i = 0; i < n; i++ ) {		/* 配列の要素を入力 */
		scanf("%d", &array[i]);
		if ( array[i] < 0 || array[i] > 100 ) {
			printf("点数を正しく入力して下さい．\n");
			return 0;
		}
	}

	printf("合格点を入力して下さい (0-100): \n");
	scanf("%d", &border);

	if ( border < 0 || border > 100 ) {
		printf("点数を正しく入力して下さい．\n");
		return 0;
	}

	printf("合格者一覧----------------- \n");
	for ( i = 0; i < n; i++ ) {		/* 合格者 */
		if ( high < array[i] ) high = array[i];
		if ( low > array[i] ) low = array[i];
		if ( array[i] >= border )
			printf("No.%d：%d点\n", i + 1, array[i]);
	}

	printf("最高点 %d点\n最低点 %d点\n", high, low);

	return 0;
}
