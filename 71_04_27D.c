/* 数理情報学演習I 71_04_27D.c */
/* 2011.04.27, 10RU004, Ishibashi Shota */

#include <stdio.h>    /* 標準入力関数の読み込み */
#include <stdlib.h>   /* 標準ライブラリ関数の読み込み */


void plus(double *, const double *);
void minus(double *, const double *);
void mult(double *, const double *);
void divi(double *, const double *);

double main(void)
{
  double a[2], b[2];
  int c;
  char buffer[0x100];

  printf("Aの複素数(実数部)を入力して下さい:");
  gets(buffer);
  a[0] = atof(buffer);

  printf("Aの複素数(虚数部)を入力して下さい:");
  gets(buffer);
  a[1] = atof(buffer);

  printf("Bの複素数(実数部)を入力して下さい:");
  gets(buffer);
  b[0] = atof(buffer);

  printf("Bの複素数(虚数部)を入力して下さい:");
  gets(buffer);
  b[1] = atof(buffer);

  printf("演算子を入力して下さい:");
  c = getchar();

  if (a[0] != 0)
  {
	  if (a[1] != 0) printf("(%f%+fi)", a[0], a[1]);
	  else printf("%f", a[0]);
  }
  else if (a[1] != 0) printf("%fi", a[1]);

  putchar(c);

  if (b[0] != 0)
  {
	  if (b[1] != 0) printf("(%f%+fi)", b[0], b[1]);
	  else printf("%f", b[0]);
  }
  else if (b[1] != 0) printf("%fi", b[1]);

  printf("=");

  switch(c)
	{
	case '+':
	  plus(a, b);
	  break;

	case '-':
	  minus(a, b);
	  break;

	case '*':
	  mult(a, b);
	  break;

	case '/':
	  divi(a, b);
	  break;

	default:
	  printf("error!");

	}

  if (a[0] != 0)
  {
	  if (a[1] != 0) printf("(%f%+fi)", a[0], a[1]);
	  else printf("%f", a[0]);
  }
  else if (a[1] != 0) printf("%fi", a[1]);

  printf("\n");

  return 0;
}

void plus(double a[], const double b[])
{
	int cnt;
	for(cnt = 0; cnt < 2; cnt++) a[cnt] += b[cnt];
	return;
}

void minus(double a[], const double b[])
{
	int cnt;
	for(cnt = 0; cnt < 2; cnt++) a[cnt] -= b[cnt];
	return;
}

void mult(double a[], const double b[])
{
	int cnt;
	double c[2] = {a[0] * b[0] - a[1] * b[1], a[1] * b[0] + a[0] * b[1]};
	for(cnt = 0; cnt < 2; cnt++) a[cnt] = c[cnt];
	return;
}

void divi(double a[], const double b[])
{
	int cnt;
	double c[2] = {a[0] * b[0] + a[1] * b[1], a[1] * b[0] - a[0] * b[1]};
	for(cnt = 0; cnt < 2; cnt++) a[cnt] = c[cnt] / (b[0] * b[0] + b[1] * b[1]);
	return;
}
