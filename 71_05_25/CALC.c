/* 数理情報学演習I CALC.c */
/* 2011.05.15, 10RU004, Ishibashi Shota */

#include "Polish_Notation.h"

#define NumOfCALC -10	/*式解析の無視マーク(ランクに指定)*/
#define EndOfCALC -20	/*式解析の停止マーク(ランクに指定)*/
#define EnMAX	3		/*演算子の優先順位の最高値*/
#define yLIMIT LIMIT	/* 許される数式内要素の数の最大値　*/

int main(void)
{
	int buffer[yLIMIT][3], cnt, cnt_h, cnt_k, intstack, cnt_s, high_m, high, inv, en, nm;
	char s[LIMIT], u, u_;

	for(;;)
	{
		inv = intstack = cnt_s = high_m = high = 0;

		printf("式を入力してください。(使用できる演算子: +-*/%%^)\n");
		gets(s);

		for(cnt = 0; s[cnt] != '\0'; cnt++)
		{
			u = s[cnt];
			u_ = s[cnt + 1];

			//buffer[x][y]
			//x : 要素の番号
			//y : 0 数値、もしくは記号の文字コード
			//      '0'-'9', '+', '-', '*', '/', '%', '^'
			//    1 数値、演算符号の優先順位のフラグ
			//      0なら数値、1以上なら演算符号の優先順位
			//    2 ランク、もしくは制御符号
			//      0以上ならランク、0未満なら制御符号

			//式の階段の高さ(入れ子深さ)を測定
			if (u == '(') high++;

			buffer[cnt_s][2] = high;

			if (u == ')') high--;

			if (high < 0) break;

			//数字ならば変換(intstackに積む)
			if ('0' <= u && u <= '9')
			{
				intstack = intstack * 10 + u - '0';

				//数字後に非数字が来たらintstackをフラッシュ
				if ('0' > u_ || u_ > '9')
				{
					if (inv == 1) intstack = -intstack;
					buffer[cnt_s][0] = intstack;
					buffer[cnt_s][1] = intstack = inv = 0;
					cnt_s++;
				}
			}

			//算術符号なら
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

			//算術符号でない(正数/負数)ともとれるなら
			if (u == '+' || u == '-')
			{
				if (cnt_s > 0 && buffer[cnt_s - 1][1] != 0)
				{
					//算術符号でないなら
					if (u == '-') inv = 1;
					else inv = 0;
				}
				else
				{
					//算術符号なら
					buffer[cnt_s][0] = u;
					buffer[cnt_s][1] = 1;
					cnt_s++;
				}
			}


			if (cnt_s == yLIMIT) break;	//許される数式内要素の数の最大値に到達してしまった！
		}

		if (high != 0)
		{
			printf("括弧が閉じられていないようです。\n");
			continue;
		}

		//演算子の優先順位に合わせて式の階段の高さ(入れ子深さ)を高く(深く)する
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

		//一番深い入れ子から計算
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

				printf("逆ポーランド記法: %s\n", s);

				buffer[cnt][0] = Polish_Notation(s);
				buffer[cnt][1] = 0;
				buffer[cnt][2] = cnt_h - 1;	//計算結果のランクは一段落とす

				for(cnt_k = cnt + 1; buffer[cnt_k][2] == cnt_h || buffer[cnt_k][2] == NumOfCALC; cnt_k++)
					buffer[cnt_k][2] = NumOfCALC;	//ランクを読み取り無視まで落とす
			}
		}

		printf("Finish!: %d\n\n", buffer[0][0]);
	}
	return 0;
}
