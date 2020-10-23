#pragma once
#include<stdio.h> 
#include<stdlib.h>
#include <windows.h>
#include <conio.h>
#include<time.h>
#include<string.h>
#define iconwide 5000
#define iconhigh 4000



unsigned int undericon[iconhigh][iconwide] = { 0 };
char picture[1000][5000] = { 0 };

void/*清除键盘缓存区*/KBclear()
{
	scanf_s("%*[^\n]%*c");
	fflush(stdin);
	system("cls");
}

void /*数字按位数分解*/xxmathtoolxx(int number, int *pin)
{

	*pin = number;
	for (;*pin > 99999999;*pin -= 100000000, *(pin + 1) += 10000000);
	for (;*pin > 9999999;*pin -= 10000000, *(pin + 1) += 1000000);
	for (;*pin > 999999;*pin -= 1000000, *(pin + 1) += 100000);
	for (;*pin > 99999;*pin -= 100000, *(pin + 1) += 10000);
	for (;*pin > 9999;*pin -= 10000, *(pin + 1) += 1000);
	for (;*pin > 999;*pin -= 1000, *(pin + 1) += 100);
	for (;*pin > 99;*pin -= 100, *(pin + 1) += 10);
	for (;*pin > 9;*pin -= 10, *(pin + 1) += 1);

	

	*pin += '0';

	if (*(++pin) > 9)
	{
		xxmathtoolxx(*pin, pin);
	}
	else
	{
		*(pin) += '0';
		*(pin + 1) = 0;
		*(pin + 2) = 0;
	}

}


//绘制直线
void line(int x0, int y0, int x1, int y1, int numb, char *p, int chan)
{
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2, e2;
	for (char *p1 = p + y0 * chan + x0;;)
	{
		*p1 = numb;
		if (x0 == x1 && y0 == y1)break;
		e2 = err;
		if (e2 > -dx) { err -= dy;x0 += sx;p1 += sx; }
		if (e2 < dy) { err += dx;y0 += sy;p1 += chan *sy; }
	}
}
//绘制三角形
void mkdelta(int x0, int y0, int x1, int y1, int x2, int y2,int numb, char *p, int chan)
{
	/*int x0 = nx[0];
	int y0 = ny[0];
	int x1 = nx[1];
	int y1 = ny[1];
	int x2 = nx[2];
	int y2 = ny[2];*/

	int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
	int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2, edit;
	for (;;)
	{
		//
		int x00 = x0, y00 = y0;

		int dx1 = abs(x1 - x00), sx1 = x00 < x1 ? 1 : -1;
		int dy1 = abs(y1 - y00), sy1 = y00 < y1 ? 1 : -1;
		int err1 = (dx1 > dy1 ? dx1 : -dy1) / 2, edit1;
		for (char *p1 = p + y0 * chan + x0;;)
		{
			//

			*p1 = numb;


			//
			if (x00 == x1 && y00 == y1)break;
			edit1 = err1;
			if (edit1 > -dx1) { err1 -= dy1;x00 += sx1;p1 += sx1; }
			if (edit1 < dy1) { err1 += dx1;y00 += sy1;p1 += chan * sy1;}
		}

		//
		if (x1 == x2 && y1 == y2)break;
		edit = err;
		if (edit > -dx) { err -= dy;x1 += sx; }
		if (edit < dy) { err += dx;y1 += sy; }
	}

}

float /*倒数开方*/InvSqrt(float x)
{
	float xhalf = 0.5f*x;
	int i = *(int*)&x; // get bits for floating VALUE 
	i = 0x5f375a86 - (i >> 1); // gives initial guess y0
	x = *(float*)&i; // convert bits BACK to float
	x = x * (1.5f - xhalf * x*x); // Newton step, repeating increases accuracy
	x = x * (1.5f - xhalf * x*x); // Newton step, repeating increases accuracy
	x = x * (1.5f - xhalf * x*x); // Newton step, repeating increases accuracy

	return 1 / x;
}

void /*鼠标隐藏*/mousehide()
{  //定义隐藏光标函数
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	SetConsoleCursorInfo(handle, &cursor);

}

int /*绘图防止越界*/iconcheck(int y, int x, int c)//c=0时读取，c=1时写入，c=2时清除
{
	if (y >= 0 && y <= iconwide && x >= 0 && x <= iconhigh)//防止内存越界 
	{
		switch (c) {

		case 0: if (undericon[y][x] >= 1) { return 1; }
				else return 0;break;
		case 1: if (undericon[y][x] == 0)undericon[y][x] = 1;break;
		case 2: if (undericon[y][x] == 1)undericon[y][x] = 0;break;
		default:undericon[y][x] = c;
		}

	}



}

double /*瞎吉儿开方*/hod(float a) {

	int k = (a *0.5);float number = -1;
	for (;k > 0;k /= 10)//确定数字位数
	{
		number++;
	}

	double b = a * 0.5, c = 0, bid = 1;
	if (((int)number - 1) % 2) { number *0.5;if (number > 1)number++; }
	//printf("位数%f\n", number);
	while (1) {
		for (;b*b > a;b -= bid)
		{
			for (;number > 0;number--)bid *= 10;
			//printf("b值%lf\n", b);
			//printf("差值%lf\n", bid);

			if (b < bid) { break; }
		}
		b += bid;
		bid /= 10;
		//printf("                                                   %f\n",b );
		if (bid < 0.000000001) { break; }
	}
	return b;
}

void /*函数绘制*/icon() {

	unsigned int a, b;
	int X, Y, K, C, BT = 10;
	float y1, y2, x1, x2, k1, c1, a1, b1;
	unsigned char iconshow[100][200] = { 0 };
	int iy = iconhigh / 2, ix = iconwide / 2, gx = ix, gy = iy;//圆点
	mousehide();
	HANDLE hOutput;
	COORD coord = { 0,0 };
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//SetConsoleCursorPosition(hOutput, coord);画面部分刷新函数


	for (k1 = 0.5, c1 = 30, x1 = -2000;x1 < 2000;x1 += 0.1)
	{
		y1 = k1 * x1 + c1;
		iconcheck((int)y1 + iy + 1, (int)x1 + ix + 1, 1);
	}
	/*for (a1=1,b1=0,k1 = 1, c1 = 0, x1 = -2000;x1 < 2000;x1 += 0.01)
	{
		y1 = a1 * x1*x1 +b1*x1+ c1;
		iconcheck((int)y1 + iy+1, (int)x1 + ix+1, 1);
	}*/

	while (1)
	{

		Sleep(40);
		SetConsoleCursorPosition(hOutput, coord);
		for (b = 0;b < 50;b++)
			for (a = 0;a < 150;a++)
			{
				if (iconcheck(b + iy, a + ix, 0))
					switch (undericon[b + iy][a + ix]) {
					case 1:iconshow[b][a] = '#';break;
					case '!':iconshow[b][a] = '!';break;
					case '-':iconshow[b][a] = '-';break;
					case '|':iconshow[b][a] = '|';break;
					}
				else iconshow[b][a] = ' ';
			}
		for (b = 51;b > 0;b--)
		{
			printf("%s\n", iconshow[b - 1]);
		}
		for (a = 0;a < 4800;a++)
			undericon[iconhigh / 2 + 1][a] = '-';

		for (a = 0;a < iconhigh;a++)
		{
			iconcheck(a, iconwide / 2 + 1, '|');

		}
		for (a1 = 1, b1 = 0, k1 = 1, c1 = 0, x1 = -2000;x1 < 2000;x1 += 0.01)
		{
			y1 = a1 * x1*x1 + b1 * x1 + c1;
			iconcheck((int)(y1*BT) + gy + 1, (int)(x1*BT) + gx + 1, 1);
		}
		if (GetKeyState(65) < 0) { ix -= 2; }//a
		if (GetKeyState(68) < 0) { ix += 2; }//d
		if (GetKeyState(87) < 0) { iy++; }//w
		if (GetKeyState(83) < 0) { iy--; }//s
		if (GetKeyState(79) < 0) {
			BT++;for (b = 0;b < iconhigh;b++)
				for (a = 0;a < iconwide;a++)
					undericon[b][a] = 0;
		}//w
		if (GetKeyState(80) < 0) {
			if (BT != 1)BT--;for (b = 0;b < iconhigh;b++)
				for (a = 0;a < iconwide;a++)
					undericon[b][a] = 0;
		}//s



	}



}

void /*游戏编辑器*/myedit()
{
#define N 100
#define 宽最大值 130
	FILE *fp;
	char str[N + 1];
	int er = 0;
	//判断文件是否打开失败
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	SetConsoleCursorInfo(handle, &cursor);

	HANDLE hOutput;
	COORD coord = { 0,0 };
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	char mousetouch = 0;
	char  photo[60][宽最大值 + 10] = { 0 };

	int i = 0, a, b, px[4] = { 0 }, py[4] = { 0 }, delx = 0, dely = 0, x=0, y=0, startx, starty, t = 0, xc, yc;
	char picmeun = 0, k = 0;
	float xstep = 0, ystep = 0;
	int x4 = 0, y4 = 0;
	POINT pt;//鼠标坐标储存的结构体
	mousehide();
	while (1)
	{

		coord.X = 0;  coord.Y = 0;
		SetConsoleCursorPosition(hOutput, coord);
		for (b = 0;b < 60;b++)
			for (a = 0;a < 宽最大值;a++)
			{

				switch (picture[b][a])
				{
				case 35:photo[b][a] = '#';break;
				case 42:photo[b][a] = '*';break;
				default: photo[b][a] = ' ';
				}

			}


		if (picmeun == 0)
		{
			photo[10][90] = 35;
			photo[10][10] = 35;
			photo[30][90] = 35;
			photo[30][10] = 35;
			printf("请右键点击 “#” 进行四次定位 目前已经定位次数：%d \n", k);
			if (GetKeyState(2) < 0) { i = 2; }
			else
			{
				if (i == 2 && k < 4)
				{
					i = 0;
					px[k] = pt.x;
					py[k] = pt.y;
					k++;
				}
				if (k > 3)
				{
					for (a = 1;a < 4;a++)
					{
						if (px[0] - px[a]<10 && px[0] - px[a] > -10)
						{
							if (py[0] > py[a])
							{
								dely = py[0] - py[a];
								int a1, b1;
								switch (a)
								{
								case 1: a1 = 2;b1 = 3;break;
								case 2: a1 = 1;b1 = 3;break;
								case 3: a1 = 1;b1 = 2;break;
								}
							}
							else
							{
								dely = py[a] - py[0];
							}


						}
						if (py[0] - py[a]<10 && py[0] - py[a] > -10)
						{
							if (px[0] > px[a])
							{
								delx = px[0] - px[a];
							}
							else
							{
								delx = px[a] - px[0];
							}


						}
					}
					xstep = (float)delx / (float)80;
					ystep = (float)dely / (float)20;

					picmeun++;

				}
			}



		}
		if (picmeun == 1)
		{
			startx = 0;starty = 0;
			printf("                               确定初始点位                                \n");
			x = (float)pt.x / xstep - 1;
			y = (float)pt.y / ystep - 3;
			if (x > 宽最大值 - 1)x = 宽最大值 - 1;
			if (y > 40)y = 40;
			if (x < 1)x = 1;
			if (y < 1)y = 1;
			photo[y][x] = 35;

			if (GetKeyState(2) < 0) { i = 2; }
			else
			{
				if (i == 2) {
					i = 0;startx = x;starty = y;picmeun++;
					picture[y][x] = 42;
				}

			}




		}
		if (picmeun == 2)
		{
		backacce:

			printf("\t\t\t\t\t\t已确认初始位点            ");
			printf("当前工具");
			switch (t)
			{
			case 0:  printf("  画笔     \n");break;
			case 1:  printf("  橡皮     \n");break;
			case 2:  printf("  直线工具 \n");break;
			case 3:  printf("  镜像工具 \n");break;

			}


			coord.X = 98;  coord.Y = 0;
			SetConsoleCursorPosition(hOutput, coord);
			printf(" 按W打开画笔 按E打开橡皮 按L打开直线工具 按R重置画面 按m打开镜像工具 按回车输出模型\n");
			x = pt.x / xstep - 1;
			y = pt.y / ystep - 3;
			if (x > 宽最大值 - 1)x = 宽最大值 - 1;
			if (y > 40)y = 40;
			if (x < 1)x = 1;
			if (y < 1)y = 1;
			photo[y][x] = 35;

			if (GetKeyState(2) < 0) {
				i = 2;
				//临时存放区
				//mousetouch = 1;

				switch (t) {
				case 0:picture[y][x] = 42;break;
				case 1:picture[y][x] = 0;break;
				case 2:
					if (mousetouch < 2)
					{
						mousetouch = 2;
						y4 = y;x4 = x;

					}
					int y3 = y4, x3 = x4;
					int dx = abs(x - x3), sx = x3 < x ? 1 : -1;
					int dy = abs(y - y3), sy = y3 < y ? 1 : -1;
					int err = (dx > dy ? dx : -dy) / 2, e2;
					for (;;)
					{
						photo[y3][x3] = 35;
						if (x3 == x && y3 == y)break;
						e2 = err;
						if (e2 > -dx) { err -= dy;x3 += sx; }
						if (e2 < dy) { err += dx;y3 += sy; }
					}




					break;
				}
			}
			else
			{
				if (mousetouch > 0)
				{
					if (mousetouch > 1)
					{
						if (x4 > x)
						{
							if ((float)(y4 - y) / (x4 - x) < 0.5 && (float)(y4 - y) / (x4 - x) > -0.5)
							{
								for (int x2 = x;x2 < x4;x2++)
								{

									picture[(int)((float)(y4 - y) / (x4 - x)*(x2 - x4) + y4)][x2] = 42;

								}
							}
							else
							{
								if (y4 > y) //纵坐标是反过来的
								{
									for (int y2 = y;y2 < y4;y2++)

									{

										picture[y2][(int)((float)(x - x4) / (y4 - y)*(y4 - y2) + x4)] = 42;

									}
								}
								else
								{
									for (int y2 = y;y2 > y4;y2--)

									{

										picture[y2][(int)((float)(x4 - x) / (y - y4)*(y4 - y2) + x4)] = 42;

									}
								}

							}
						}
						else
						{
							if ((float)(y4 - y) / (x4 - x) < 0.5 && (float)(y4 - y) / (x4 - x) > -0.5)
							{
								for (int x2 = x;x2 > x4;x2--)
								{
									picture[(int)((float)(y4 - y) / (x - x4)*(x4 - x2) + y4)][x2] = 42;
								}
							}
							else
							{
								if (y4 > y) //纵坐标是反过来的
								{
									for (int y2 = y;y2 < y4;y2++)

									{

										picture[y2][(int)((float)(x - x4) / (y4 - y)*(y4 - y2) + x4)] = 42;

									}
								}
								else
								{
									for (int y2 = y;y2 > y4;y2--)

									{

										picture[y2][(int)((float)(x4 - x) / (y - y4)*(y4 - y2) + x4)] = 42;

									}
								}
							}

						}
					}
					mousetouch = 0;
				}
			}
			if (GetKeyState(87) < 0) {
				t = 0;
			}//w
			if (GetKeyState(69) < 0) {
				t = 1;
			}//e
			if (GetKeyState(76) < 0) {
				t = 2;
			}//l
			if (GetKeyState(77) < 0) {
				t = 3;
			}

			if (GetKeyState(82) < 0) {
				t = 0;picmeun = 1;
				for (b = 0;b < 60;b++)
					for (a = 0;a < 宽最大值;a++)picture[b][a] = 0;
			}//r
			if (GetKeyState(13) < 0) {
				t = 0;picmeun = 3;

			}//r




		}


		coord.X = 0;  coord.Y = 1;
		SetConsoleCursorPosition(hOutput, coord);
		for (b = 0;b < 40;b++)
		{
			printf("|%s| \n", photo[b]);
		}
		for (b = 0;b < 60;b++)
			for (a = 0;a < 宽最大值;a++)photo[b][a] = ' ';
		printf("              4点定位的偏差值%f  %f\n", xstep, ystep);





		GetCursorPos(&pt);
		printf("  %ld  鼠标相对坐标 %d \n   %ld  鼠标相对坐标 %d \n", pt.x, x, pt.y, y);


		if (0) { again:system("cls"); }



		if (picmeun == 3)
		{
			char word[100] = { 0 };

			KBclear();
			system("cls");
			printf("确定要生成文件吗？");
			system("pause");
			printf("请输入文件名");
			scanf_s("%10s", word);
			int mount = 0;

			while (word[mount] != '\0')
			{
				mount++;
			}
			word[mount] = '.';
			word[mount + 1] = 't';
			word[mount + 2] = 'x';
			word[mount + 3] = 't';
			word[mount + 4] = '\0';





			SetConsoleCursorPosition(hOutput, coord);
			i = 0;
			if (fopen_s(&fp, word, "r+")) {
				puts("已经新建模型存放文件");
				fopen_s(&fp, word, "w+");
			}
			for (b = 0;b < 40;b++)
				for (a = 0;a < 宽最大值;a++)
				{
					if (picture[b][a] == 42)
					{
						i++;
						xc = a - startx;
						yc = b - starty;
						if (yc >= 0)
							fprintf(fp, "dx[0][y2+%d]", yc);
						else
							fprintf(fp, "dx[0][y2%d]", yc);
						if (xc >= 0)
							fprintf(fp, "[x2+%d]", xc);
						else
							fprintf(fp, "[x2%d]", xc);
						fprintf(fp, "=id;");
						if (i == 9) { fprintf(fp, "\n"); i = 0; }
					}
				}
			fclose(fp);
			printf("已建立模型存放文件%s\n按m输出镜像代码", word);
			while (1) {
				if (GetKeyState(90) < 0) { picmeun = 2; goto backacce; }
				if (GetKeyState(77) < 0)
				{
					system("cls");
					break;
					Sleep(500);
				}//space
			}
			SetConsoleCursorPosition(hOutput, coord);
			i = 0;
			mount = 0;
			while (word[mount] != '\0')
			{
				mount++;
			}word[mount] = '(';
			word[mount + 1] = 'm';
			word[mount + 2] = 'i';
			word[mount + 3] = 'r';
			word[mount + 4] = ')';
			word[mount + 5] = '.';
			word[mount + 6] = 't';
			word[mount + 7] = 'x';
			word[mount + 8] = 't';
			word[mount + 9] = '\0';

			if (fopen_s(&fp, word, "r+")) {
				puts("已经新建模型存放文件");
				fopen_s(&fp, word, "w+");
			}
			for (b = 0;b < 40;b++)
				for (a = 0;a < 宽最大值;a++)
				{
					if (picture[b][a] == 42)
					{
						i++;
						xc = a - startx;
						yc = b - starty;
						if (yc >= 0)
							fprintf(fp, "dx[0][y2+%d]", yc);
						else
							fprintf(fp, "dx[0][y2%d]", yc);
						if (xc >= 0)
							fprintf(fp, "[x2-%d]", xc);
						else
							fprintf(fp, "[x2+%d]", -xc);
						fprintf(fp, "=id;");
						if (i == 9) { fprintf(fp, "\n"); i = 0; }
					}
				}
			fclose(fp);
			while (1) {
				if (GetKeyState(32) < 0)
				{
					system("cls");
					break;
					Sleep(500);

				}//space
			}
			SetConsoleCursorPosition(hOutput, coord);
			i = 0;

			for (b = 0;b < 40;b++)
				for (a = 0;a < 宽最大值;a++)
				{
					if (picture[b][a] == 42)
					{
						i++;
						xc = a - startx;
						yc = b - starty;
						printf("if(");
						if (yc >= 0)
							printf("dx[1][y2+%d]", yc);
						else
							printf("dx[1][y2%d]", yc);
						if (xc >= 0)
							printf("[x2+%d]", xc);
						else
							printf("[x2%d]", xc);
						printf("==0)");
						if (yc >= 0)
							printf("dx[1][y2+%d]", yc);
						else
							printf("dx[1][y2%d]", yc);
						if (xc >= 0)
							printf("[x2+%d]", xc);
						else
							printf("[x2%d]", xc);
						printf("=id;");
						if (i == 9) { printf("\n"); i = 0; }
					}
				}
			printf("已建立模型存放文件%s\n按m输出镜像代码", word);
			while (1) {
				if (GetKeyState(90) < 0) { picmeun = 2;goto backacce; }
				if (GetKeyState(77) < 0)
				{
					system("cls");
					break;
					Sleep(500);

				}//space
			}
			SetConsoleCursorPosition(hOutput, coord);
			i = 0;

			for (b = 0;b < 40;b++)
				for (a = 0;a < 宽最大值;a++)
				{
					if (picture[b][a] == 42)
					{
						i++;
						xc = a - startx;
						yc = b - starty;
						printf("if(");
						if (yc >= 0)
							printf("dx[1][y2+%d]", yc);
						else
							printf("dx[1][y2%d]", yc);
						if (xc >= 0)
							printf("[x2-%d]", xc);
						else
							printf("[x2+%d]", -xc);
						printf("==0)");
						if (yc >= 0)
							printf("dx[1][y2+%d]", yc);
						else
							printf("dx[1][y2%d]", yc);
						if (xc >= 0)
							printf("[x2-%d]", xc);
						else
							printf("[x2+%d]", -xc);
						printf("=id;");
						if (i == 9) { printf("\n"); i = 0; }
					}
				}



			while (1)if (GetKeyState(82) < 0) {
				goto again;
			}//r
		}
	}
	return 0;
}







void /*内置编辑器*/screenedit()
{


	HANDLE hOutput;
	COORD coord = { 0,0 };
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	char  photo[60][120] = { 0 };
	int i = 0, a, b, px[4] = { 0 }, py[4] = { 0 }, delx = 0, dely = 0, x, y, startx, starty, t = 0, xc, yc;
	char picmeun = 0, k = 0;
	float xstep = 0, ystep = 0;
	POINT pt;//鼠标坐标储存的结构体
	while (1)
	{
		SetConsoleCursorPosition(hOutput, coord);
		for (b = 0;b < 60;b++)
			for (a = 0;a < 100;a++)
			{

				switch (picture[b][a])
				{
				case 35:photo[b][a] = '#';break;
				case 42:photo[b][a] = '*';break;
				default: photo[b][a] = '\0';
				}

			}


		if (picmeun == 0)
		{
			photo[10][90] = 35;
			photo[10][10] = 35;
			photo[30][90] = 35;
			photo[30][10] = 35;
			printf("请右键点击 “#” 进行四次定位 目前已经定位次数：%d \n", k);
			if (GetKeyState(2) < 0) { i = 2; }
			else
			{
				if (i == 2 && k < 4)
				{
					i = 0;
					px[k] = pt.x;
					py[k] = pt.y;
					k++;
				}
				if (k > 3)
				{
					for (a = 1;a < 4;a++)
					{
						if (px[0] - px[a]<10 && px[0] - px[a] > -10)
						{
							if (py[0] > py[a])
							{
								dely = py[0] - py[a];
							}
							else
							{
								dely = py[a] - py[0];
							}


						}
						if (py[0] - py[a]<10 && py[0] - py[a] > -10)
						{
							if (px[0] > px[a])
							{
								delx = px[0] - px[a];
							}
							else
							{
								delx = px[a] - px[0];
							}


						}
					}
					xstep = (float)delx / (float)80;
					ystep = (float)dely / (float)20;

					picmeun++;

				}
			}



		}
		if (picmeun == 1)
		{
			startx = 0;starty = 0;
			printf("\t\t\t\t\t\t确定初始点位\t\t\t\t\t\t\t\t\n");
			x = (float)pt.x / xstep - 1;
			y = (float)pt.y / ystep - 3;
			if (x > 100)x = 100;
			if (y > 40)y = 40;
			if (x < 1)x = 1;
			if (y < 1)y = 1;
			photo[y][x] = 35;

			if (GetKeyState(2) < 0) { i = 2; }
			else
			{
				if (i == 2) {
					i = 0;startx = x;starty = y;picmeun++;
					picture[y][x] = 42;
				}

			}




		}
		if (picmeun == 2)
		{

			printf("\t\t\t\t\t\t已确认初始位点            ");
			printf("当前工具");
			switch (t)
			{
			case 0:  printf("  画笔\n");break;
			case 1:  printf("  橡皮\n");break;

			}
			x = pt.x / xstep - 1;
			y = pt.y / ystep - 3;
			if (x > 100)x = 100;
			if (y > 40)y = 40;
			if (x < 1)x = 1;
			if (y < 1)y = 1;
			photo[y][x] = 35;

			if (GetKeyState(2) < 0) {
				i = 2;
				switch (t) {
				case 0:picture[y][x] = 42;break;
				case 1:picture[y][x] = 0;break;
				}
			}
			if (GetKeyState(87) < 0) {
				t = 0;
			}//w
			if (GetKeyState(69) < 0) {
				t = 1;
			}//e
			if (GetKeyState(82) < 0) {
				t = 0;picmeun = 1;
				for (b = 0;b < 60;b++)
					for (a = 0;a < 100;a++)picture[b][a] = 0;
			}//r
			if (GetKeyState(68) < 0) {
				t = 0;picmeun = 3;

			}//r




		}



		for (b = 0;b < 40;b++)
		{
			printf("\t\t\t\t\t|%s|\n", photo[b]);
		}
		for (b = 0;b < 60;b++)
			for (a = 0;a < 100;a++)photo[b][a] = ' ';
		printf("              4点定位的偏差值%f  %f\n", xstep, ystep);





		GetCursorPos(&pt);
		printf("  %ld   \n   %ld   \n", pt.x, pt.y);
		if (picmeun == 3)
		{
			SetConsoleCursorPosition(hOutput, coord);
			i = 0;

			for (b = 0;b < 40;b++)
				for (a = 0;a < 100;a++)
				{
					if (picture[b][a] == 42)
					{
						i++;
						xc = a - startx;
						yc = b - starty;
						if (yc >= 0)
							printf("d[y2+%d]", yc);
						else
							printf("d[y2%d]", yc);
						if (xc >= 0)
							printf("[x2+%d]", xc);
						else
							printf("[x2%d]", xc);
						printf("=id;");
						if (i == 9) { printf("\n"); i = 0; }
					}
				}
			printf("\n按空格输出镜像代码");
			while (1) {
				if (GetKeyState(32) < 0)
				{
					system("cls");
					break;

				}//space
			}
			SetConsoleCursorPosition(hOutput, coord);
			i = 0;

			for (b = 0;b < 40;b++)
				for (a = 0;a < 100;a++)
				{
					if (picture[b][a] == 42)
					{
						i++;
						xc = a - startx;
						yc = b - starty;
						if (yc >= 0)
							printf("d[y2+%d]", yc);
						else
							printf("d[y2%d]", yc);
						if (xc >= 0)
							printf("[x2-%d]", xc);
						else
							printf("[x2+%d]", -xc);
						printf("=id;");
						if (i == 9) { printf("\n"); i = 0; }
					}
				}

			while (1);
		}
	}
	return 0;
}


