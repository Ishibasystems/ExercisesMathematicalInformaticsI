/* �������w���KI CALC.c */
/* 2011.05.15, 10RU004, Ishibashi Shota */

#include "Polish_Notation.h"

#define NumOfCALC -10	/*����̖͂����}�[�N(�����N�Ɏw��)*/
#define EndOfCALC -20	/*����͂̒�~�}�[�N(�����N�Ɏw��)*/
#define EnMAX	3		/*���Z�q�̗D�揇�ʂ̍ō��l*/
#define yLIMIT LIMIT	/* ������鐔�����v�f�̐��̍ő�l�@*/

int main(void)
{
	int buffer[yLIMIT][3], cnt, cnt_h, cnt_k, intstack, cnt_s, high_m, high, inv, en, nm;
	char s[LIMIT], u, u_;

	for(;;)
	{
		inv = intstack = cnt_s = high_m = high = 0;

		printf("������͂��Ă��������B(�g�p�ł��鉉�Z�q: +-*/%%^)\n");
		gets(s);

		for(cnt = 0; s[cnt] != '\0'; cnt++)
		{
			u = s[cnt];
			u_ = s[cnt + 1];

			//buffer[x][y]
			//x : �v�f�̔ԍ�
			//y : 0 ���l�A�������͋L���̕����R�[�h
			//      '0'-'9', '+', '-', '*', '/', '%', '^'
			//    1 ���l�A���Z�����̗D�揇�ʂ̃t���O
			//      0�Ȃ琔�l�A1�ȏ�Ȃ牉�Z�����̗D�揇��
			//    2 �����N�A�������͐��䕄��
			//      0�ȏ�Ȃ烉���N�A0�����Ȃ琧�䕄��

			//���̊K�i�̍���(����q�[��)�𑪒�
			if (u == '(') high++;

			buffer[cnt_s][2] = high;

			if (u == ')') high--;

			if (high < 0) break;

			//�����Ȃ�Εϊ�(intstack�ɐς�)
			if ('0' <= u && u <= '9')
			{
				intstack = intstack * 10 + u - '0';

				//������ɔ񐔎���������intstack���t���b�V��
				if ('0' > u_ || u_ > '9')
				{
					if (inv == 1) intstack = -intstack;
					buffer[cnt_s][0] = intstack;
					buffer[cnt_s][1] = intstack = inv = 0;
					cnt_s++;
				}
			}

			//�Z�p�����Ȃ�
			if (u == '^')
			{
				buffer[cnt_s][0] = u;
				buffer[cnt_s][1] = 3;
				cnt_s++;
			}

			if (u == '*' || u == '/' || u == '%')
			{
				buffer[cnt_s][0] = u;
				buffer[cnt_s][1] = 2;
				cnt_s++;
			}

			//�Z�p�����łȂ�(����/����)�Ƃ��Ƃ��Ȃ�
			if (u == '+' || u == '-')
			{
				if (cnt_s > 0 && buffer[cnt_s - 1][1] != 0)
				{
					//�Z�p�����łȂ��Ȃ�
					if (u == '-') inv = 1;
					else inv = 0;
				}
				else
				{
					//�Z�p�����Ȃ�
					buffer[cnt_s][0] = u;
					buffer[cnt_s][1] = 1;
					cnt_s++;
				}
			}


			if (cnt_s == yLIMIT) break;	//������鐔�����v�f�̐��̍ő�l�ɓ��B���Ă��܂����I
		}

		if (high != 0)
		{
			printf("���ʂ������Ă��Ȃ��悤�ł��B\n");
			continue;
		}

		//���Z�q�̗D�揇�ʂɍ��킹�Ď��̊K�i�̍���(����q�[��)������(�[��)����
		for(cnt_k = EnMAX; cnt_k > 1; cnt_k--)
			for(cnt = 0; cnt < cnt_s; cnt++)
				if (buffer[cnt][1] == cnt_k)
				{
					if (buffer[cnt][2] < buffer[cnt - 1][2])
						for(cnt_h = cnt - 1; buffer[cnt_h][2] > buffer[cnt][2] && cnt_h >= 0; cnt_h--)
							buffer[cnt_h][2]++;
					else buffer[cnt - 1][2]++;

					if (buffer[cnt][2] < buffer[cnt + 1][2])
						for(cnt_h = cnt + 1; buffer[cnt_h][2] > buffer[cnt][2]; cnt_h++)
							buffer[cnt_h][2]++;
					else
						for(cnt_h = cnt + 1; buffer[cnt_h][1] == buffer[cnt][1] || buffer[cnt_h][1] == 0; cnt_h++)
							buffer[cnt_h][2]++;

					buffer[cnt][2]++;
				}

		for(cnt = 0; cnt < cnt_s; cnt++)
			if (high_m < buffer[cnt][2])
				high_m = buffer[cnt][2];

		buffer[cnt_s][2] = EndOfCALC;

		//DEBUG START//
		for(cnt_k = 0; buffer[cnt_k][2] != EndOfCALC; cnt_k++) printf("%d", buffer[cnt_k][2]);
		printf("\n");
		//DEBUG END//

		//��Ԑ[������q����v�Z
		for(cnt_h = high_m; cnt_h >= 0; cnt_h--)
		{
			for(cnt = 0; cnt < cnt_s; cnt++)
			{
				if (cnt_h != buffer[cnt][2]) continue;

				en = nm = u = 0;
				s[0] = '\0';
				for(cnt_k = cnt; buffer[cnt_k][2] == cnt_h || buffer[cnt_k][2] == NumOfCALC; cnt_k++)
					if (buffer[cnt_k][2] != NumOfCALC)
						if (buffer[cnt_k][1] == 0)
						{
							if (u == '-' && nm == en)
							{
								sprintf(s, "%s0 ", s);
								nm++;
							}

							sprintf(s, "%s%d ", s, buffer[cnt_k][0]);
							nm++;

							if (u != 0)
							{
								sprintf(s, "%s%c ", s, u);
								en++;
								u = 0;
							}
						}
						else u = (char)buffer[cnt_k][0];

				printf("�t�|�[�����h�L�@: %s\n", s);

				buffer[cnt][0] = Polish_Notation(s);
				buffer[cnt][1] = 0;
				buffer[cnt][2] = cnt_h - 1;	//�v�Z���ʂ̃����N�͈�i���Ƃ�

				for(cnt_k = cnt + 1; buffer[cnt_k][2] == cnt_h || buffer[cnt_k][2] == NumOfCALC; cnt_k++)
					buffer[cnt_k][2] = NumOfCALC;	//�����N��ǂݎ�薳���܂ŗ��Ƃ�
			}
		}

		printf("Finish!: %d\n\n", buffer[0][0]);
	}
	return 0;
}
