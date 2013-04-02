/* 数理情報学演習I 71_04_27B1_switch.c */
/* 2011.04.27, 10RU004, Ishibashi Shota */

#include <stdio.h>    /* 標準入力関数の読み込み */
#include <stdlib.h>   /* 標準ライブラリ関数の読み込み */

int main(void)
{
  int a, b, c;
  char buffer[0x100];

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
      printf("%d + %d = %d\n", a, b, a + b);
      break;

    case '-':
      printf("%d - %d = %d\n", a, b, a - b);
      break;

     case '*':
      printf("%d * %d = %d\n", a, b, a * b);
      break;

     case '/':
      printf("%d / %d = %f\n", a, b, ((double) a) / b);
      break;

     case '%':
      printf("%d %% %d = %d\n", a, b, a % b);
      break;

    default:
      printf("error!\n");

    }
  return 0;
}
