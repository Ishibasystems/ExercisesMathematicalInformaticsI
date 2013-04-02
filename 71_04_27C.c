/* 数理情報学演習I 71_04_27C.c */
/* 2011.04.27, 10RU004, Ishibashi Shota */

#include <stdio.h>    /* 標準入力関数の読み込み */
#include <stdlib.h>   /* 標準ライブラリ関数の読み込み */

int plus(int, int);          /* 関数のプロトタイプ宣言 */
int minus(int, int);
int mult(int, int);
double divi(int, int);
int modu(int, int);

int main(void)
{
  int a, b, c;
  char buffer[50];

  printf("整数を入力して下さい:");
  gets(buffer);
  a = atoi(buffer);

  printf("整数を入力して下さい:");
  gets(buffer);
  b = atoi(buffer);

  printf("演算子を入力して下さい:");
  c = getchar();

  switch(c)
    {
    case '+':
      printf("%d + %d = %d\n", a, b, plus(a, b));
      break;

    case '-':
      printf("%d - %d = %d\n", a, b, minus(a, b));
      break;

    case '*':
      printf("%d * %d = %d\n", a, b, mult(a, b));
      break;

    case '/':
      printf("%d / %d = %f\n", a, b, divi(a, b));
      break;

    case '%':
      printf("%d %% %d = %d\n", a, b, modu(a, b));
      break;

    default:
      printf("error!");

    }

  return 0;
}

int plus(int a, int b)     /* 足し算を行う関数 */      
{
  return a + b;
}

int minus(int a, int b)
{
  return a - b;
}

int mult(int a, int b)
{
  return a * b;
}

double divi(int a, int b)
{
  return ((double) a) / b;
}

int modu(int a, int b)
{
  return a % b;
}
