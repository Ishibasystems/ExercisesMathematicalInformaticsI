/* 数理情報学演習I Polish_Notation.h */
/* 2011.05.12, 10RU004, Ishibashi Shota */

#include <stdio.h>	/* 標準入出力関数 */
#include <stdlib.h>	/* 標準ライブラリ関数 */

#ifndef __Polish_Notation_h__

	#define __Polish_Notation_h__

	#define LIMIT 0x1000	/* スタックに入る数の最大値　*/

	int push(int *, int *, const int);
	int pop(const int *, int *);
	int Polish_Notation(const char *);
	int hatfunc(int, int);

#endif