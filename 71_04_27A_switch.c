/* �������w���KI sample0427-2.c */
/* 2011.04.27, 10RU999, Harue Dendai */

#include <stdio.h>    /* �W�����͊֐��̓ǂݍ��� */
#include <stdlib.h>   /* �W�����C�u�����֐��̓ǂݍ��� */

int main(void)
{
  int a, b, c;
  char buffer[50];
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
      printf("%d + %d = %d\n", a, b, a+b);
      break;
    case '-':
      printf("%d - %d = %d\n", a, b, a-b);
      break;
    default:
      printf("error!");
    }
  return 0;
}
