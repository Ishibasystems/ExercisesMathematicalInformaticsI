/* �������w���KI Polish_Notation.h */
/* 2011.05.12, 10RU004, Ishibashi Shota */

#include <stdio.h>	/* �W�����o�͊֐� */
#include <stdlib.h>	/* �W�����C�u�����֐� */

#ifndef __Polish_Notation_h__

	#define __Polish_Notation_h__

	#define LIMIT 0x1000	/* �X�^�b�N�ɓ��鐔�̍ő�l�@*/

	int push(int *, int *, const int);
	int pop(const int *, int *);
	int Polish_Notation(const char *);
	int hatfunc(int, int);

#endif