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

int /*绘图防止越界*/iconcheck(int y,int x,int c)//c=0时读取，c=1时写入，c=2时清除
{
	if (y >= 0 && y <= iconwide && x >= 0 && x <= iconhigh)//防止内存越界 
	{
		switch (c) {
		
		case 0: if (undericon[y][x] >= 1) { return 1; }
				else return 0;break;
		case 1: if(undericon[y][x]==0)undericon[y][x] = 1;break;
		case 2: if(undericon[y][x]==1)undericon[y][x] = 0;break;
		default:undericon[y][x] = c;
		}

	}



}

float /*瞎吉儿开方*/hod(float a) {
	
	int k = (a *0.5);float number = -1;
	for (;k>0 ;k/=10)//确定数字位数
	{
		number++;
	}

	double b=a * 0.5,c=0,bid=1;
	if (((int)number - 1) % 2) { number *0.5;if(number>1)number++; }
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
		if (bid < 0.000000001) {break; }
	}
	return b;
}

void /*函数绘制*/icon() {

	unsigned int a,b;
	int X, Y, K, C,BT=10;
	float y1, y2, x1, x2, k1, c1,a1,b1;
	unsigned char iconshow[100][200] = { 0 };
	int iy=iconhigh/2, ix=iconwide/2,gx=ix,gy=iy;//圆点
	mousehide();
	HANDLE hOutput;
	COORD coord = { 0,0 };
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);//SetConsoleCursorPosition(hOutput, coord);画面部分刷新函数


	for (k1 = 0.5, c1 = 30, x1 = -2000;x1 < 2000;x1 += 0.1)
	{
		y1 = k1 * x1 + c1;
		iconcheck((int)y1+iy+1, (int)x1+ix+1, 1);
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
		for(b=0;b<50;b++)
			for (a = 0;a < 150;a++)
			{
				if (iconcheck(b + iy,a + ix, 0))
					switch (undericon[b + iy][a + ix]) {
					case 1:iconshow[b][a] = '#';break;
					case '!':iconshow[b][a] = '!';break;
					case '-':iconshow[b][a] = '-';break;
					case '|':iconshow[b][a] = '|';break;
					}
				else iconshow[b][a] = ' ';
			}
		for (b = 51;b >0;b--)
		{
			printf("%s\n", iconshow[b-1]);
		}
		for (a = 0;a < 4800;a++)
			undericon[iconhigh / 2 + 1][a]='-';
		
		for (a = 0;a < iconhigh;a++)
		{
			iconcheck(a, iconwide / 2 + 1, '|');
			
		}
		for (a1 = 1, b1 = 0, k1 = 1, c1 = 0, x1 = -2000;x1 < 2000;x1 += 0.01)
		{
			y1 = a1 * x1*x1 + b1 * x1 + c1;
			iconcheck((int)(y1*BT) + gy + 1, (int)(x1*BT) + gx + 1, 1);
		}
		if (GetKeyState(65) < 0) { ix-=2; }//a
		if (GetKeyState(68) < 0) { ix+=2; }//d
		if (GetKeyState(87) < 0) { iy++; }//w
		if (GetKeyState(83) < 0) { iy--; }//s
		if (GetKeyState(79) < 0) { BT++;for (b = 0;b < iconhigh;b++)
			for (a = 0;a < iconwide;a++)
				undericon[b][a] = 0;
		}//w
		if (GetKeyState(80) < 0) { if(BT!=1)BT--;for (b = 0;b < iconhigh;b++)
			for (a = 0;a < iconwide;a++)
				undericon[b][a] = 0;
		}//s
		
		

	}



}

void /*游戏编辑器*/myedit()
{
#define N 100
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
	char  photo[60][120] = { 0 };
	int i = 0, a, b, px[4] = { 0 }, py[4] = { 0 }, delx = 0, dely = 0, x, y, startx, starty, t = 0, xc, yc;
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
			for (a = 0;a < 100;a++)
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
		{backacce:

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
			printf(" 按W打开画笔 按E打开橡皮 按L打开直线工具 按R重置画面 按m打开镜像工具 按d输出模型\n");
			x = pt.x / xstep - 1;
			y = pt.y / ystep - 3;
			if (x > 100)x = 100;
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
					if (x4 > x) 
					{ 
						if ((float)(y4 - y) / (x4 - x) < 0.5 && (float)(y4 - y) / (x4 - x) > -0.5) 
						{
							for (int x2 = x;x2 < x4;x2++)
							{

								photo[(int)((float)(y4 - y) / (x4 - x)*(x2 - x4) + y4)][x2] = 35;

							}
						}
						else 
						{
							if (y4 > y) //纵坐标是反过来的
							{
								for (int y2 = y;y2 < y4;y2++)

								{

									photo[y2][(int)((float)(x - x4) / (y4 - y)*(y4 - y2) + x4)] = 35;

								}
							}
							else 
							{
								for (int y2 = y;y2 > y4;y2--)

								{

									photo[y2][(int)((float)(x4 - x) / (y - y4)*(y4 - y2) + x4)] = 35;

								}
							}
					
						}
					}
					else 
					{
						for (int x2 = x;x2 > x4;x2--)
						{
							photo[(int)((float)(y4 - y) / (x - x4)*(x4 - x2) + y4)][x2] = 35;
						}
					}
					
					
					
					
					break;
				}
			}
			else
			{ 
				if (mousetouch > 0) 
				{
					if (mousetouch > 1) {}mousetouch = 0;
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
			}//e
			if (GetKeyState(77) < 0) {
				t = 3;
			}

			if (GetKeyState(82) < 0) {
				t = 0;picmeun = 1;
				for (b = 0;b < 60;b++)
					for (a = 0;a < 100;a++)picture[b][a] = 0;
			}//r
			if (GetKeyState(68) < 0) {
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
			for (a = 0;a < 100;a++)photo[b][a] = ' ';
		printf("              4点定位的偏差值%f  %f\n", xstep, ystep);





		GetCursorPos(&pt);
		printf("  %ld   \n   %ld   \n", pt.x, pt.y);


		if (0) { again:system("cls"); }



		if (picmeun == 3)
		{
			char word[100] = {0};
			printf("请输入文件名");
			scanf_s("%s", word);
			int mount = 0;

			while (word[mount] != '\0')
			{
				mount++;
			}
			word[mount] = '.';
			word[mount + 1] = 't';
			word[mount + 2] = 'x';
			word[mount + 3] = 't';

			



			SetConsoleCursorPosition(hOutput, coord);
			i = 0;
			if (fopen_s(&fp, word, "r+")) {
				puts("已经新建模型存放文件");
				fopen_s(&fp, word, "w+");
			}
			for (b = 0;b < 40;b++)
				for (a = 0;a < 100;a++)
				{
					if (picture[b][a] == 42)	
					{
						i++;
						xc = a - startx;
						yc = b - starty;
						if (yc >= 0)
							fprintf(fp,"dx[0][y2+%d]", yc);
						else
							fprintf(fp,"dx[0][y2%d]", yc);
						if (xc >= 0)
							fprintf(fp,"[x2+%d]", xc);
						else
							fprintf(fp,"[x2%d]", xc);
						fprintf(fp,"=id;");
						if (i == 9) { fprintf(fp,"\n"); i = 0; }
					}
				}
			fclose(fp);
			printf("已建立模型存放文件%s\n按m输出镜像代码",word);
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

			if (fopen_s(&fp, word, "r+")) {
				puts("已经新建模型存放文件");
				fopen_s(&fp, word, "w+");
			}
			for (b = 0;b < 40;b++)
				for (a = 0;a < 100;a++)
				{
					if (picture[b][a] == 42)
					{
						i++;
						xc = a - startx;
						yc = b - starty;
						if (yc >= 0)
							fprintf(fp,"dx[0][y2+%d]", yc);
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
				for (a = 0;a < 100;a++)
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
			printf("已建立模型存放文件%s\n按m输出镜像代码",word);
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
				for (a = 0;a < 100;a++)
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


//武器绘制
/*
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
*/
