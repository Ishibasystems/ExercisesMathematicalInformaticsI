/* �������w���KI 71_04_27C.c */
/* 2011.04.27, 10RU004, Ishibashi Shota */

#include <stdio.h>    /* �W�����͊֐��̓ǂݍ��� */
#include <stdlib.h>   /* �W�����C�u�����֐��̓ǂݍ��� */

int plus(int, int);          /* �֐��̃v���g�^�C�v�錾 */
int minus(int, int);
int mult(int, int);
double divi(int, int);
int modu(int, int);

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

int plus(int a, int b)     /* �����Z���s���֐� */      
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
