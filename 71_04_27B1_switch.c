/* �������w���KI 71_04_27B1_switch.c */
/* 2011.04.27, 10RU004, Ishibashi Shota */

#include <stdio.h>    /* �W�����͊֐��̓ǂݍ��� */
#include <stdlib.h>   /* �W�����C�u�����֐��̓ǂݍ��� */

int main(void)
{
  int a, b, c;
  char buffer[0x100];

  printf("��������͂��ĉ�����:");
  gets(buffer);
  a = atoi(buffer);

  printf("��������͂��ĉ�����:");
  gets(buffer);
  b = atoi(buffer);

  printf("���Z�q����͂��ĉ�����:");
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
