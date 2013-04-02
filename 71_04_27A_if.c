/* 数理情報学演習I sample0427-1.c */
/* 2011.04.27, 10RU999, Hanako Dendai */

#include <stdio.h>    /* 標準入力関数の読み込み */
#include <stdlib.h>   /* 標準ライブラリ関数の読み込み */

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
  if ( c == '+')
    {
      printf("%d + %d = %d\n", a, b, a+b);
    }
  else if ( c == '-')
    {
      printf("%d - %d = %d\n", a, b, a-b);
    }
  else
    {
      printf("error!");
    }
  return 0;
}