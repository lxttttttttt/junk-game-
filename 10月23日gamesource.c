#include<stdio.h> 
#include <windows.h>
#include <conio.h>
#include"mytool.h"
#include <math.h>
#include"gamepro.h"

//#include<pthread.h>

int main()
{ 
	unsigned char show[100][200] = { 0 }, showb[100][200] = { 2 }, showt[100][100] = { ' ' },showtmir[35][32] = { ' ' };
	register short int a, b;
	register int *c1,*c2;
	int ic = 0, px[4] = { 0 }, py[4] = { 0 }, delx = 0, dely = 0, startx, starty, t = 0 ;
	int xc, yc,xq,yq,ep,en,c,movex,movey,x4,y4,tablestep=0,swin=0,tablex=30,tabley=0, nx[3], ny[3];
	char picmeun = 0, k = 0,mousetouch,mode=0,numdel=0;
	float xstep = 0, ystep = 0;
	deliver = &showb;

	POINT pt; // 鼠标坐标储存的结构体
	//icon();
	


	开场动画;//开场
	
	
	FILE *fp;
	HANDLE hOutput;
	COORD coord = { 0,0 };
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	开发者调试 
	{
		h = 1;u = 1;j2 = 0;o2 = 0;j4 = 0;tian = 'b';mop[room] = 0;room = 15000;comp = room;max = 5;x = 1638;
	   
	
	}
	//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
	//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------		
	 一直循环
	{
	saferoom:
		

		switch (table)
		{
		case 0:
		{
			//************
			//*死亡后函数*
			//************

			非触发程序
			{dead:for (a = 0;a < 100;a++)
			{
				if (a < 60) {
					printf(" 死了  死了  死了      \n");
					延迟(150);
				}
				if (die[a] == 1) { die[a] = 0; i[a] = 0; }
			}
				 heart1 = memory[0];  heart2 = memory[1];  m1 = memory[2];comp = memory[3];y = memory[4];
			}
			//************
			//*死亡后函数*
			//************
			
			切图后重置;

	      			        //******
			关卡设计;		//*关卡*
					        //******
			



			非触发程序 
			{
			mp:
				if (room == 0)dicr(100, 14);
				if (room == 51)
				{
					juxing(15, 20, 11, 1);juxing(15, 20, 6, 1);
				}
			}//非持续触发的场景互动

				非触发程序{
			tableback:
			system("cls");
			}

			一直循环 //主显示器
			{

				if (mop[room] == tip) { mop[room]++;open[room] = 1;goto mp; }
				if (keyhit[0] == 2){system("cls");keyhit[0] = 0;}//动画刷屏

				coord.X = 0;
				coord.Y = 0;
				SetConsoleCursorPosition(hOutput, coord);//局部覆盖更新代码

				

				
				switch (cartoon)//视角控制
				{
				case 0:
					{
						ep = x + 60;
						if ((en > y + 13 && en - y - 13 > 16) || (en < y + 13 && y + 13 - en>1))en = y + 16;
						cgx = ep - 60;//即时储存动画坐标x
						cgy = en;     //即时储存动画坐标y
						
						
							
						


					}break;//视角控制
				case 1:
				{
					ep = cgx + 60;
					en = cgy;
				}break;
				}

				switch (shootgun)
				{
				case 0:
				{
					if (con > 0)
					{
						xcar = x + 10;//保留cg视角
						ycar = y - 2;//保留cg视角
					}
					else
					{
						xcar = x - 10;//保留cg视角
						ycar = y - 2;//保留cg视角
					}
					
					
					开发者调试
					{
						GetCursorPos(&pt);//获取鼠标坐标
		
					watcb(&show,creater,ep,en,ch1,ch2,&showb);
					

					if (picmeun == 0)
					{
						switch (k)
						{
						case 0:show[10][10] = 35;break;//点1
						case 1:show[10][90] = 35;break;//点2
						case 2:show[30][10] = 35;break;//点3
						case 3:show[30][90] = 35;break;//点4
						}
						if (GetKeyState(2) < 0) { ic = 2; }
						else
						{
							if (ic == 2 && k < 4)
							{
								ic = 0;
								px[k] = pt.x;
								py[k] = pt.y;
								k++;
							}
							if (k > 3)
							{
								/*delx=(int)(px[0]+px[1]+px[2]+px[3] - 10 - 90 - 10 - 90)/4;
								dely = (int)(py[0] + py[1] + py[2] + py[3] - 20 - 60) / 4;*/

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


								movex = (px[0] + px[2] - 20 * xstep) / (xstep * 2);
								movey = (py[0] + py[1] - 20 * ystep) / (ystep * 2);



								picmeun++;

							}
						}



					}
					if (picmeun == 1)
					{

						xq = pt.x / xstep - movex;
						yq = pt.y / ystep - movey;
						if (xq > 120)xq = 120;
						if (yq > 40)yq = 40;
						if (xq < 1)xq = 1;
						if (yq < 1)yq = 1;
						show[yq][xq] = '#';
						if (GetKeyState(2) < 0) { ic = 2; }
						else
						{ 
							if (ic == 2) {
								ic = 0;startx = xq + ep - 120;starty = yq + en - 31;picmeun++;
								picture[yq+en-31][xq+ep-120] = 42;
							}

						}

					}
					if (picmeun == 2)
						//if()
					{
					backacce:
						for (b = en - 31;en >= b;b++)//10
						
							//--------------------------------------------------------
							//a,b为发生层函数
							//screenx,screeny为投影层函数
							//--------------------------------------------------------
							for (a = ep - 120;ep >= a;a++)
						switch (picture[b][a])
						{
						case 35:show[b - en + 31][a - ep + 120] = '#';break;
						case 42:show[b - en + 31][a - ep + 120] = '*';break;
						case 30:show[b - en + 31][a - ep + 120] = 't';dx[0][b][a] = 2;break;
						default: continue;//防止被画
						}
						
						xq = pt.x / xstep - movex;
						yq = pt.y / ystep - movey;
						if (xq > 120)xq = 120;
						if (yq > 40)yq = 40;
						if (xq < 1)xq = 1;
						if (yq < 1)yq = 1;
						show[yq][xq] = '#';
						if (GetKeyState(2) < 0) {
							ic = 2;
							//临时存放区
							//mousetouch = 1;

							switch (t) 
							{
							case 0:picture[yq + en - 31][xq + ep - 120] = 42;break;
							case 1:picture[yq + en - 31][xq + ep - 120] = 0;break;
							case 2:{
								if (mousetouch < 2){mousetouch = 2;y4 = yq;x4 = xq;}//初始点初始化
								//直线准线数据为35


								line(xq, yq, x4, y4, 35, 显示屏幕参数);
								//int y3 = y4, x3 = x4;
								//int dx = abs(xq - x3), sx = x3 < xq ? 1 : -1;//蜜汁计算机图形学
								//int dy = abs(yq - y3), sy = y3 < yq ? 1 : -1;
								//int err = (dx > dy ? dx : -dy) / 2, e2;
								//for (;;)
								//{
								//	show[y3][x3] = 35;
								//	if (x3 == xq && y3 == yq)break;
								//	e2 = err;
								//	if (e2 > -dx) { err -= dy;x3 += sx; }
								//	if (e2 < dy) { err += dx;y3 += sy; }
								//}



								
							}break;
							case 4:picture[yq + en - 31][xq + ep - 120]=30; break;
							case 5:
								if (mousetouch < 3)
								{
									mousetouch = 3;

									nx[numdel] = x;
									ny[numdel] = y;

									if (numdel < 3)
										numdel++;



								}
								break;
							}
						}
						else {

							//[yq + en - 31][xq + ep - 120]



							if (ic == 2) 
							{ ic = 0; }
							if (mousetouch > 0)
							{
								//mkdelta( nx[0] + ep - 120, ny[0] + en - 31, nx[1] + ep - 120, ny[1] + en - 31, nx[2] + ep - 120, ny[2] + en - 31, 42, 绘画底板参数);

								switch (mousetouch)
								{

								case 2:{
									if (numdel > 2)
									{
										numdel = 0;
										line(xq + ep - 120, yq + en - 31, x4 + ep - 120, y4 + en - 31, 42, 绘画底板参数);
										//int y3 = y4, x3 = x4;
										//int dx = abs(xq - x3), sx = x3 < xq ? 1 : -1;//蜜汁计算机图形学
										//int dy = abs(yq - y3), sy = y3 < yq ? 1 : -1;
										//int err = (dx > dy ? dx : -dy) / 2, e2;
										//for (;;)
										//{
										//	picture[y3 + en - 31][x3 +ep - 120] = 42;
										//	if (x3 == xq && y3 == yq)break;
										//	e2 = err;
										//	if (e2 > -dx) { err -= dy;x3 += sx; }
										//	if (e2 < dy) { err += dx;y3 += sy; }
										//}
									}



									}
									   mousetouch = 0;break;
								case 3:{mkdelta(nx[0] + ep - 120, ny[0] + en - 31, nx[1] + ep - 120, ny[1] + en - 31, nx[2] + ep - 120, ny[2] + en - 31, 42, 绘画底板参数);}  mousetouch = 0;break;
								}
							}
						}
						/*if (GetKeyState(2) < 0) {
							ic = 2;
							switch (t) {
							case 0:picture[y][x] = 42;break;
							case 1:picture[y][x] = 0;break;
							}
						}*/
						if (GetKeyState(17) < 0) {
							//如果左CTRL键被按下
							if (GetKeyState(87) < 0) {
								t = 0;
							}//w
							if (GetKeyState(69) < 0) {
								t = 1;
							}//e
							if (GetKeyState(82) < 0) {
								t = 0;picmeun = 1;
								for (a = 0;a < 1000;a++)
									for (b = 0;b < 5000;b++)picture[b][a] = 0;
							}//r
							if (GetKeyState(76) < 0) {
								t = 2;
							}//l

							if (GetKeyState(77) < 0) {
								t = 3;
							}//m
							if (GetKeyState(84) < 0) {
								t = 4;
							}//t键 搭建临时站立平台
							if (GetKeyState(68) < 0) {
								t = 5;
							}//d键 绘制三角形
						}
						if (GetKeyState(13) < 0) {
							t = 0;picmeun = 3;

						}//r


					}
					if (picmeun == 3)
					{

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
						 	int i = 0;
							if (fopen_s(&fp, word, "r+")) {
								puts("已经新建模型存放文件");
								fopen_s(&fp, word, "w+");
							}
							for (b = 0;b < 1000;b++)
								for (a = 0;a < 5000;a++)
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
							for (b = 0;b < 1000;b++)
								for (a = 0;a < 5000;a++)
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

							for (b = 0;b < 1000;b++)
								for (a = 0;a < 5000;a++)
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

							for (b = 0;b < 1000;b++)
								for (a = 0;a < 5000;a++)
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
								//goto again;
							}//r
						}
					}

					}


				else 
                {
				watcb(&show, creater, ep, en,ch1,ch2, &showb);
				}
					
					人物操作(cartoon);//没有过场动画，当前可以操作

					{
						meun = 168;
						数字0键按下 { keyhit[48] = 1; }//按键1
						else if (keyhit[48] > 0) { keyhit[48] = 0;meun = 0; }
					    数字1键按下 { keyhit[49] = 1; }
						else if (keyhit[49] > 0) { keyhit[49] = 0;meun = 1; }
						数字2键按下 { keyhit[50] = 1; }
						else if (keyhit[50] > 0) { keyhit[50] = 0;meun = 2; }
						数字3键按下 { keyhit[51] = 1; }
						else if (keyhit[51] > 0) { keyhit[51] = 0;meun = 3; }
						数字4键按下 { keyhit[52] = 1; }
						else if (keyhit[52] > 0) { keyhit[52] = 0;meun = 4; }
						数字5键按下 { keyhit[53] = 1; }
						else if (keyhit[53] > 0) { keyhit[53] = 0;meun = 5; }
						数字6键按下 { keyhit[54] = 1; }
						else if (keyhit[54] > 0) { keyhit[54] = 0;meun = 6; }
						数字7键按下 { keyhit[55] = 1; }
						else if (keyhit[55] > 0) { keyhit[55] = 0;meun = 7; }
						数字8键按下 { keyhit[56] = 1; }
						else if (keyhit[56] > 0) { keyhit[56] = 0;meun = 8; }
						数字9键按下 { keyhit[57] = 1; }
						else if (keyhit[57] > 0) { keyhit[57] = 0;meun = 9; }//按键9
						ESC键按下 { keyhit[27] = 1; }
						else if (keyhit[27] > 0) { keyhit[27] = 0;table = 1;_getch();/*清理按键亢余*/swin = rand() % 2;goto contable; }
						if (GetKeyState(65) >= 0 && GetKeyState(68) >= 0 && GetKeyState(83) >= 0 && GetKeyState(87) >= 0 && GetKeyState(74) >= 0) { act1 = 0;ax = 0; }//判断是否有摩擦力
					
						空格键按下 { j2 = j4;time1 = 0;}//空格键
					}


					
				}break;
				case 1:
				{
					watcb(&show[0][0], creater, xcar + 60, ycar + 16,ch1,ch2, &showb);
					/************
					*   准星    *
					*************/
					show[16][60] = '+';
					show[15][60] = '+';
					show[17][60] = '+';
					show[16][62] = '+';
					show[16][58] = '+';
					/************
					*   准星    *
					*************/
					xoc = xcar - x;
					yoc = ycar - y;
					//新人物分界
					a = 20;
					A键按下 {
						if (1 < (float)(xoc*xoc) / (4 * a*a) + (float)(yoc*yoc) / (a*a))
							if (xoc < 0) { if (yoc < 0) { ycar += 2;xcar += 3; } else { ycar -= 2;xcar += 3; } } xcar -= 3;
					}//a
					D键按下 {
						if (1 < (float)(xoc*xoc) / (4 * a*a) + (float)(yoc*yoc) / (a*a))
							if (xoc > 0) { if (yoc < 0) { ycar += 2;xcar -= 3;; } else { ycar -= 2;xcar -= 3;; } } xcar += 3;
					}//d
					 W键按下{
						if (1 < (float)(xoc*xoc) / (4 * a*a) + (float)(yoc*yoc) / (a*a))
							if (yoc < 0) { if (xoc < 0) { xcar += 3; ycar += 2; } else { xcar -= 3;;ycar += 2; } } ycar -= 2;
					}//w
					J键按下 { act1 = 1;ax = 0;act3++; }//j
					S键按下{

						if (1 < (float)(xoc*xoc) / (4 * a*a) + (float)(yoc*yoc) / (a*a))
							if (yoc > 0) { if (xoc < 0) { xcar += 3;ycar -= 2; } else { xcar -= 3;; ycar -= 2; } } ycar += 2;
					}//s
					K键按下 { keyhit[75] = 1; }
					else  { keyhit[75] = 0;shootgun = 0; }//k
					if (GetKeyState(65) >= 0 && GetKeyState(68) >= 0 && GetKeyState(83) >= 0 && GetKeyState(87) >= 0 && GetKeyState(74) >= 0) { act1 = 0;ax = 0;act3 = 0; }//判断是否有摩擦力
					
				}break;
				}
				//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
				//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
				printf("\t\t\t\t###########################################################################################################################\n");
				if (hearp != heart1) 
				{ hearp = heart1;
				for (a = 0;a < 32;a++) 
				{
					if(a%2)coord.X = 0;else coord.X = 15;  coord.Y = a + 1;
					SetConsoleCursorPosition(hOutput, coord);//局部覆盖更新代码
					p = show[a];
					//
					//nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
					//hhhhhhhhhhhhhhhhh  hhhhhhhhhhhhhhhhh
					//ooooooooooooooo  oo  ooooooooooooooo
					//ppppppppppppp  ppppp  pppppppppppppp
					//iiiiiiiiii  iiiiiiiii  iiiiiiiiiiiii
					//ccccccccc  ccccccccccc  cccccccccccc
					//qqqqqqqq  qqqqqqqqqqqqq  qqqqqqqqqqq
					//dddddddd                 ddddddddddd
					//eeeeeeeeeeeeeeee  eeeeeeeeeeeeeeeeee
					//rrrrrrrrrrrrrrrr  rrrrrrrrrrrrrrrrrr
					//tttttttttttttttt  tttttttttttttttttt
					
					printf("%s #%s#\n",showtmir[a], p);//真正的桌面显示
					
					//
					//nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
					//hhhhhhhhhhhhhhhhh  hhhhhhhhhhhhhhhhh
					//ooooooooooooooo  oo  ooooooooooooooo
					//ppppppppppppp  ppppp  pppppppppppppp
					//iiiiiiiiii  iiiiiiiii  iiiiiiiiiiiii
					//ccccccccc  ccccccccccc  cccccccccccc
					//qqqqqqqq  qqqqqqqqqqqqq  qqqqqqqqqqq
					//dddddddd                 ddddddddddd
					//eeeeeeeeeeeeeeee  eeeeeeeeeeeeeeeeee
					//rrrrrrrrrrrrrrrr  rrrrrrrrrrrrrrrrrr
					//tttttttttttttttt  tttttttttttttttttt
				}
				延迟(20);
				system("cls");
				}//受伤函数
				else//图像显示函数
				for (a = 0;a < 32;a++) 
				{
					p = show[a];
					printf(" %s#%s#\n", showtmir[a], p);
				}
				printf("\t\t\t\t###########################################################################################################################\n");
				//图像显示函数
				//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
				//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				
				
				//特效层


			
				




				//act左奇右偶***
				//操作(旧版本kbhit与getch使用_kbhit与_getch代替)




				//主要东西
				
				physicsengine(0,0);
				
				chac(con, 0);
				
				
				product(0);

				//主要东西

				if (open[room] == 1 && dx[0][y][x + 1] == 5 && dx[0][y + 8][x + 1] == 5)
				{
					comp = room; room++;memory[0] = heart1;memory[1] = heart2;memory[2] = m1;memory[3] = comp; memory[4] = y;break;
				}//过门并且储存数据
				if (open[room] == 1 && dx[0][y][x - 1] == 6 && dx[0][y + 8][x - 1] == 6)
				{
					comp = room; room--;memory[0] = heart1;memory[1] = heart2;memory[2] = m1;memory[3] = comp;memory[4] = y;break;
				}//过门并且储存数据











				//if (keyhit[74] == 0)act3 = 0;
				
				if (heart1 <= 0) { goto dead; }//死亡函数
				if (act3 > 0) { blade(con); }//攻击放在被攻击目标下，要不然找不到目标造不成伤害
				


				


				
				//检测npc
				if (sit == 1) //检测npc
				{
					sit = 0;
					if (room == 10000)for (a = 0;a < 8;a++) { if (dx[0][y + a][x] == 10) { table = 2;system("cls");goto pcmeun; } } //检测电脑桌子

					if (dx[0][y + 8][x] == 7) { comp = room; room += 50;;memory[0] = heart1;memory[1] = heart2;memory[2] = m1;memory[3] = comp; memory[4] = y;break; }//进门
					if (dx[0][y + 8][x] == 8) { comp = room; room -= 50;;memory[0] = heart1;memory[1] = heart2;memory[2] = m1;memory[3] = comp; memory[4] = y;break; }//出门

					for (a = 0;a < 20;a++)
					{

						if (dx[0][y + 4][x + a] == 19 || dx[0][y + 4][x - a] == 19) { talk = 1;trad = 1; break; }
						if (dx[1][y + 2][x + a] == 24 || dx[1][y + 2][x - a] == 24) { talk = 1;hdso = 1; break; }
						if (dx[1][y + 2][x + a] > 8999 && dx[1][y + 2][x + a] < 10000) { talk = 1;vill = 1;numbvill = dx[1][y + 2][x + a]; break; }
						else
							if (dx[1][y + 2][x - a] > 8999 && dx[1][y + 2][x - a] < 10000) { talk = 1;vill = 1;numbvill = dx[1][y + 2][x - a]; break; }
					}
					if (dx[0][y + 8][x] == 4)//拾取道具函数
					{BOX(0, 0, 1);}
				}
				//检测npc

				//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
				//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

				//其他显示器
				if (mode == 0)
				{
					if (tablex > 30)
						if(tablex>34)
						tablex-=2;
						else tablex --;
				}
				else {
					for (int b = 0;b < 34;b++)
						for (int a = 0;a < 31;a++)
						{
							showtmir[b][a] = ' ';
						} 
					if (tablex < 60)
						if (tablex < 56)
							tablex += 2;
						else tablex++;
				}


				//左侧显示器纵34横30
				if ( room != 10000)
				{
					mode = 0;
				
					

					if (cartoon == 0) 
					{
						keyhit[0] = 1;
						//第28行
						
						for(int b=0;b<100;b++)
							for (int a=0;a<100;a++) 
							{
								showt[b ][a ]=' ';
							}//人物面板刷新
						for (int a = 0;a < 34;a++)
							showt[a + tabley][0+tablex] = '{';
							for (int a = 0;a < 34;a++)
								showt[a + tabley][30+tablex] = '}';
							for (int a = 1;a < 30;a++)
								showt[0+tabley][a + tablex] = '~';
							for (int a = 1;a < 30;a++)
								showt[31+tabley][a + tablex] = '_';

						tabledit(n1, &showt, 1+tabley, 1+tablex, 1);
						tabledit("就是kazi", &showt, 1 + tabley, 5 + tablex, 1);
						tabledit(n1, &showt, 4 + tabley, 1 + tablex, 1);
						tabledit("的小钱钱￥%d ", &showt, 4 + tabley, 5 + tablex,1,m1);
						tabledit(n1, &showt, 5 + tabley, 1 + tablex, 1);
						tabledit("的体力%d/%d ", &showt, 5 + tabley, 5 + tablex, 2, heart1, heart2);
						tabledit("不要问背包,问就是异次元菊花 ", &showt, 6 + tabley, 1 + tablex, 0);
						tabledit("刷新数%d ", &showt, 7 + tabley, 1 + tablex, 1, 1000 / (tme + 1));
						tabledit("(%d,%d) ", &showt, 8 + tabley, 1 + tablex, 2, x, y);

					
						开发者调试
						{ 
							tabledit("请右键点击 “#” 进行四次定位", &showt, 9 + tabley, 1 + tablex, 1);
						    tabledit("目前已经定位次数：%d ", &showt, 10 + tabley, 1 + tablex, 1,k);
							tabledit("鼠标当前坐标%d,%d  ", &showt, 11 + tabley, 1 + tablex, 2, pt.x, pt.y);
							tabledit(" 4点定位的偏差值%d,%d  ", &showt, 12 + tabley, 1 + tablex, 2, (int)xstep*1000, (int)ystep*1000);
							
						

						if (picmeun == 2)
						{
					
							tabledit("已确认初始位点 ", &showt, 13 + tabley, 1 + tablex, 0);
							tabledit("按(ctrl)当前工具 ", &showt, 14 + tabley, 1 + tablex, 0);
							
							switch (t)
							{
							case 0:  tabledit("  画笔 ",&showt, 15 + tabley, 1 + tablex, 0);break;
							case 1:  tabledit("  橡皮 ", &showt, 15 + tabley, 1 + tablex, 0);break;
							case 2:  tabledit("  直线工具 ", &showt, 15 + tabley, 1 + tablex, 0);break;
							case 3:  tabledit("  镜像工具 ", &showt, 15 + tabley, 1 + tablex, 0);break;
							case 4:  tabledit("  临时台阶工具 ", &showt, 15 + tabley, 1 + tablex, 0);break;
							case 5:  tabledit("  三角形工具 ", &showt, 15 + tabley, 1 + tablex, 0);break;
							}


						}
						
						}
						for (int b = 0 ;b < 34;b++)
							for (int a = 0 ;a < 31;a++)
							{

								showtmir[b][a]=showt[b][a+30];
							}


					}//显示侧面显示屏
					else { 
						
						
						if(keyhit[0]!=0)keyhit[0] =2; }
					 if (i1 == 1)//人物交互面板
					{
						
						//system("cls");
						if (j4 - j2)
						{//Sleep(300);
							mode = 1;
							watce("！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！", &showb,20,2,1 );
							watce(n1, &showb, 21, 2, 1);watce("的语录:", &showb, 21, 6, 1);watce(mood[jj1][j2], &showb,21,18,1 );
							/*watce("！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！", &showb, );
							watce("！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！", &showb, );
							watce("！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！", &showb, );*/
							
							
							if (time1 == 150) { j2++;time1 = 0; }
							else
							{
								invboard(&showb,21,18+time1/2,70 );
							}
							
							time1++;
							i2 = 0;
							if(cartoon == 0)cartoon=2;
							watce("！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！",&showb,22,2,1);
							for (a = 0;a < 10;a++);
						}
						else
						{
							if (i2 < 1) { i2 = 1; cartoon = 0; }
						}
					}




					

					 coord.X = 0;
					 coord.Y = 25;
					 SetConsoleCursorPosition(hOutput, coord);
					if (talk == 1)//如果被检测到了，显示对话框，帧数刷新加快
					{
						
						if (trad >= 存在)trader(2, 1, 1);//显示商人对话
						if (hdso >= 存在)hardso(xmonst[24], ymonst[24], 50, 24, 50, 1);
						if (vill >= 存在)villager(xmonst[a], ymonst[a], 30, numbvill, 50, 1);//上下两端函数中的a用来传递id不可随意替换插入
					}//显示对话框

					product(2);

					instickword();//亡语

					product(3);
					

				}
				else//在安全房子里 
                {
				mode = 1;
				
				}







				//tme = difftime(end, start);
				time0++;
				for (a = 0;a < 100;a++)//技能冷却
				{
					/*
					0是普攻cd
					1是眩晕状态cd
					*/
					if (cooldown[a] > 0)cooldown[a]--;
				}//技能冷却
				if (time0 > 400)
				{
					time0 = 0;/* system("cls");*/
				}//时间系统
				if (tme > 40) { youhua -= 1;if (tme > 2000)tme = 2000;}
				else if (tme <42 )youhua += 1;
				sop = GetTickCount();
				tme = sop - sart;
				if (firepot) { firepot = 0; goto saferoom; }//断点器
				sart = GetTickCount();
				延迟(youhua);//3.41的倍率

				//screenedit();

			}//游戏内显示器结尾
		contable:;
		}//游戏本体循环结尾
		break;
		case 1:
		{
			char showb[100][200] ;
			for (int a = 0;a < 100;a++)
				for (int b = 0;b < 200;b++)
					showb[a][b] = show[a][b];
			
			
			
			
			
			if (room != 10000)
			{
				int deepx = 40,
					deepy = -6 + tablestep / 20;

				if (tablestep < (17+swin/2) * 20) {
					tablestep++; if (rand() % 2)swin += rand() % 2;else swin -= rand() % 2;if (swin > 20)swin = 20;if (swin < -20)swin = -20;
				}
				deepx += swin;
				
				watce("{~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~}", &showb, deepy++, deepx,-1);
				watce("{         菜  单(按下对应键操作)       }", &showb, deepy++, deepx,-1);
				watce("{++++++++++++++++++++++++++++++++++++++}", &showb, deepy++, deepx,-1);
				watce("{      |        1 设   置         |    }", &showb, deepy++, deepx,-1);
				watce("{      |        2 菜   单         |    }", &showb, deepy++, deepx,-1);
				watce("{      |        3 DEMO制作名单    |    }", &showb, deepy++, deepx,-1);
				watce("{      |        0 退出当前游戏    |    }", &showb, deepy++, deepx,-1);
				watce("{      |        Esc 关闭菜单      |    }", &showb, deepy++, deepx,-1);
				watce("{______________________________________}", &showb, deepy++, deepx,-1);
				if (GetKeyState(27) < 0) { keyhit[27] = 1; }
				else if (keyhit[27] > 0) { keyhit[27] = 0;table = 0;tablestep = 0;goto tableback; }
				数字0键按下{ keyhit[48] = 1; }
				else if (keyhit[48] > 0) {keyhit[48] = 0;if (room != 10000) {room = 10000;table = 0;comp = room;tablestep = 0;goto saferoom;}}
				/*if (_kbhit())
					switch (_getch()) {
					case'1':
						printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t按q使游戏载入速度变慢 \n");
						printf("\t\t\t\t\t\t\t\t\t按w使游戏载入速度变快 \n");

						break;

					case '3':
						printf("n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t制作人 lxt(善恶盒心) \n");
						printf("\t\t\t\t\t\t\t\t\tqq号849053854 \n");
						printf("\t\t\t\t\t\t\t\t\tqq邮箱849053854@qq.com \n");



						break;
					case'q':youhua = 58;break;
					case'w':youhua = 40;break;
					case'0':break;


					}*/

			}
			else {
				if (tablestep < (12+10) * 6)tablestep++;
				int deepx = 40,
					deepy = -(10+10) + tablestep / 6;

				watce("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", &showb, deepy++, deepx,-1);
				watce("@              -:- -------             @", &showb, deepy++, deepx,-1);
				watce("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", &showb, deepy++, deepx,-1);
				watce("@         1设   置                     @", &showb, deepy++, deepx,-1);
				watce("@         2菜   单    3 DEMO制作名单   @", &showb, deepy++, deepx,-1);
				watce("@         4打开手机游戏《tm鸽子》      @", &showb, deepy++, deepx,-1);
				watce("@         5打开游戏垃圾传说            @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@                                      @", &showb, deepy++, deepx,-1);
				开发者调试
				{
					watce("@       按tab局部编辑器                @", &showb, deepy++, deepx,-1);
				 }
					else
				watce("@                                      @", &showb, deepy++, deepx,-1);
				watce("@        0  开启/关闭室内照明          @", &showb, deepy++, deepx,-1);
				watce("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", &showb, deepy++, deepx,-1);
				watce("@               ESC 放下手机           @", &showb, deepy++, deepx,-1);
				watce("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", &showb, deepy++, deepx,-1);
				watce("@                  ---                 @", &showb, deepy++, deepx,-1);
				watce("@                || # ||               @", &showb, deepy++, deepx,-1);
				watce("@                  ---                 @", &showb, deepy++, deepx,-1);
				watce("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", &showb, deepy++, deepx,-1);
				



			






				if(GetKeyState(48) < 0) { keyhit[48] = 1; }
				else if (keyhit[48] > 0) {
					keyhit[48] = 0;
					if (latern == 0)
					{
						system("color 70");latern = 1;
					}
					else { system("color 07");latern = 0; }
				}
				if (GetKeyState(27) < 0) { keyhit[27] = 1; }
				else if (keyhit[27] > 0) { keyhit[27] = 0;table = 0;tablestep = 0;goto tableback; }
				开发者调试{ if (GetKeyState(9) < 0) { keyhit[9] = 1; }
				else if (keyhit[9] > 0) { keyhit[9] = 0;table = 5;system("cls");goto saferoom; } }
				/*if (_kbhit())
					switch (_getch()) {
					case'1':
						printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t按q使游戏载入速度变慢 \n");
						printf("\t\t\t\t\t\t\t\t\t按w使游戏载入速度变快 \n");

						break;

					case '3':
						printf("n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t制作人 lxt(善恶盒心) \n");
						printf("\t\t\t\t\t\t\t\t\tqq号849053854 \n");
						printf("\t\t\t\t\t\t\t\t\tqq邮箱849053854@qq.com \n");break;
					case '4':system("cls");table = 3;break;
					case'5':system("cls");table = 4;break;
					case'q':youhua = 58;break;
					case'w':youhua = 40;break;
					case'0': {
						if (latern == 0)
						{
							system("color 70");latern = 1;
						}
						else { system("color 07");latern = 0; }

					}break;


					}*/
			}

			coord.X = 0;
			coord.Y = 0;
			SetConsoleCursorPosition(hOutput, coord);
			printf("\n");
			for (a = 0;a < 32;a++)
			{
				p = showb[a];
				printf("\t\t\t\t#%s#\n", p);
			}


		}break;
		case 2://电脑界面
		{
		pcmeun:
			SetConsoleCursorPosition(hOutput, coord);
			printf("\t+--------------------------------------------------------------------------------------------------------------------------------------------------+\n");
			printf("\t|                                                                                                                                                  |\n");
			printf("\t|  +-------------------------------------------------+------------------------------------------------+-----------------------------------------+  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                  _________     |                                         |  |\n");
			printf("\t|  |                                                 |             ___   ___  _  _            @ /     |                  _____________          |  |\n");
			printf("\t|  |            /^\\____/^\\                           |            |___  |___   \\/              /      |                  |___________ \\         |  |\n");
			printf("\t|  |           |          |                          |             ___| |___  _/\\_            /       |                             \\  \\        |  |\n");
			printf("\t|  |           | @    @   |                          |                                       / @      |                              \\  \\       |  |\n");
			printf("\t|  |         ___\\_      _/____                       |                                      /         |                              |   |      |  |\n");
			printf("\t|  |       /   ___\\___/_____  |                      |                ___    ___           /          |                              |   |      |  |\n");
			printf("\t|  |      /   / |          | |  |                    |               |___|  |___|                     |                              /   |      |  |\n");
			printf("\t|  |     /___/   \\        /   |__|                   |                ___|                            |                             /   /       |  |\n");
			printf("\t|  |             \\______/                            |                                                |                            /  /         |  |\n");
			printf("\t|  |             /      \\                            |                                                |                           /  /          |  |\n");
			printf("\t|  |           污师三：自由城风云                    |              性感七号：全球白给                |                          /  /           |  |\n");
			printf("\t|  |              (按1进入)                          |                                                |                        /  /             |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                      ___                |  |\n");
			printf("\t|  |                                                 |                                                |                     |___|               |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  |                                                 |                                                |                                         |  |\n");
			printf("\t|  +---__- -__----__---+-+---------------------------+------------------------------------------------+---------------------------___-----------+  |\n");
			printf("\t|  |  |__  |__   |     | |                                                                                                        \\|/   |       |  |\n");
			printf("\t|  |  |__   __|  |__   | |                                                                                                         | |  |       |  |\n");
			printf("\t|  +-------------------+-+----------------------------------------------------------------------------------------------------------------------+  |\n");
			printf("\t|                                                            c is the best                                                                         |\n");
			printf("\t+--------------------------------------------------------------------------------------------------------------------------------------------------+\n");
			if (GetKeyState(27) < 0) { keyhit[27] = 1; }
			else if (keyhit[27] > 0) { keyhit[27] = 0;table = 0;system("cls");goto tableback; }

			if (_kbhit())
				switch (_getch())
				{

				case '1':table = 0;room = 4;comp = room;system("cls");break;

				}
		}break;

		case 3://拓麻歌子
		{
			SetConsoleCursorPosition(hOutput, coord);

			printf("                                                                        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			printf("                                                                        @              -:- -------             @ \n");
			printf("                                                                        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			for (b = 0;b < 19;b++) {
				p = tac[b];
				printf("                                                                        @%s@\n", p);
			}
			printf("                                                                        @               ESC 关闭手机           @ \n");
			printf("                                                                        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			printf("                                                                        @                  ---                 @ \n");
			printf("                                                                        @                || # ||               @ \n");
			printf("                                                                        @                  ---                 @ \n");
			printf("                                                                        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			for (b = 0;b < 19;b++)for (a = 0;a < 38;a++)tac[b][a] = ' ';//拓麻歌子清屏

			//ai



			tachi();//拓麻歌子建模


			/*switch (_getch())
			{
			case 0x1b:table = 0;goto tableback;break;


			}*/
		}break;

		case 4: //卡牌游戏
		{
			SetConsoleCursorPosition(hOutput, coord);//局部覆盖更新代码
			printf("                             ###########################################################################################################################");printf("\n");

			
			for (screeny = 0;screeny < 60; screeny++)//10
			{


				for (screenx = 0;screenx < 120; screenx++)
				{
					c = st[screeny][screenx];
					st[screeny][screenx] = 0;
					

					if (c == 0) {
						show[screeny][screenx] = ch1; //printf("%c", ch1);
						continue;
					}
					else {
						show[screeny][screenx] = ch2;
						//printf("%c", ch2);
						switch (c)
						{
						case 1:show[screeny][screenx] = '1';break;
						case 2:show[screeny][screenx] = '2';break;
						case 3:show[screeny][screenx] = '3';break;
						case 4:show[screeny][screenx] = '4';break;
						case 5:show[screeny][screenx] = '5';break;
						case 6:show[screeny][screenx] = '6';break;
						case 7:show[screeny][screenx] = '7';break;
						case 8:show[screeny][screenx] = '8';break;
						case 9:show[screeny][screenx] = '9';break;
						default:show[screeny][screenx] = '+';

						}
						st[b][a] = 0;
					}
				}
				

				//printf("\n");
			}
			for (a = 0;a < 60;a++) {
				p = show[a];
				printf("                             #%s#\n", p);



			}
			printf("                             ###########################################################################################################################");printf("\n");
			 gametable();//显示桌子

			 //stcard(int xs, int ys, int large, int agree, int id)//



			 for (a = 0;a < 10;a++)
			 {
				 hand1[a] = 1;handcard1 = 5; hand2[a] = 1;handcard2 = 3;
			 }
			
			for (b = 0;b < handcard1;b++)
				switch (choose1[b]) 
				{
				case 0:stcard(14 * (b)+6, 53, 0, 0, hand1[b]);break;
				case 1:stcard(14 * (b)+6, 49, 0, 0, hand1[b]);break;
				case 2:stcard(60, 35, 1, 0, hand1[b]);break;
				}
			for (b = 0;b < handcard2;b++)
				switch (choose2[b])
				{
				case 0:stcard(14 * (b)+6, 6, 0, 1, hand2[b]);break;
				case 1: stcard(14 * (b)+6, 10, 0, 1, hand2[b]);break;
				case 2:stcard(60, 25, 1, 1, hand2[b]);break;
				}
			


			 
			 if (GetKeyState(48) < 0) { keyhit[48] = 1; }//按键1
			 else if (keyhit[48] > 0) {
				  keyhit[48] = 0;a = 9;for (b = 0;b < 10;b++)if (a == b)choose1[b] = 1;else choose1[b] = 0;
			 }
			 if (GetKeyState(49) < 0) { keyhit[49] = 1; }
			 else if (keyhit[49] > 0) {
				 keyhit[49] = 0;a = 0;for (b = 0;b < 10;b++)if (a == b)choose1[b] = 1;else choose1[b] = 0;
			 }
			 if (GetKeyState(50) < 0) { keyhit[50] = 1; }
			 else if (keyhit[50] > 0) {
				 keyhit[50] = 0;a = 1;for (b = 0;b < 10;b++)if (a == b)choose1[b] = 1;else choose1[b] = 0;
			 }
			 if (GetKeyState(51) < 0) { keyhit[51] = 1; }
			 else if (keyhit[51] > 0) {
				 keyhit[51] = 0;a = 2;for (b = 0;b < 10;b++)if (a == b)choose1[b] = 1;else choose1[b] = 0;
			 }
			 if (GetKeyState(52) < 0) { keyhit[52] = 1; }
			 else if (keyhit[52] > 0) {
				  keyhit[52] = 0;a = 3;for (b = 0;b < 10;b++)if (a == b)choose1[b] = 1;else choose1[b] = 0;
			 }
			 if (GetKeyState(53) < 0) { keyhit[53] = 1; }
			 else if (keyhit[53] > 0) {
				  keyhit[53] = 0;a = 4;for (b = 0;b < 10;b++)if (a == b)choose1[b] = 1;else choose1[b] = 0;
			 }
			 if (GetKeyState(54) < 0) { keyhit[54] = 1; }
			 else if (keyhit[54] > 0) {
				  keyhit[54] = 0;a = 5;for (b = 0;b < 10;b++)if (a == b)choose1[b] = 1;else choose1[b] = 0;
			 }
			 if (GetKeyState(55) < 0) { keyhit[55] = 1; }
			 else if (keyhit[55] > 0) {
				 keyhit[55] = 0;a = 6;for (b = 0;b < 10;b++)if (a == b)choose1[b] = 1;else choose1[b] = 0;
			 }
			 if (GetKeyState(56) < 0) { keyhit[56] = 1; }
			 else if (keyhit[56] > 0) {
				 keyhit[56] = 0;a = 7;for (b = 0;b < 10;b++)if (a == b)choose1[b] = 1;else choose1[b] = 0;
			 }
			 if (GetKeyState(57) < 0) { keyhit[57] = 1; }
			 else if (keyhit[57] > 0) {
				  keyhit[57] = 0;a = 8;for (b = 0;b < 10;b++)if (a == b)choose1[b] = 1;else choose1[b] = 0;
			 }//按键9
			 if (GetKeyState(32) < 0) { keyhit[32] = 1; }
			 else if (keyhit[32] > 0) {
				 keyhit[32] = 0;for (b = 0;b < 10;b++)if (choose1[b] ==1)choose1[b] = 2;else choose1[b] = 0;
			 }//空格键

			 if (GetKeyState(32) < 0) { keyhit[32] = 1; }
			 else if (keyhit[32] > 0) {
				 keyhit[32] = 0;for (b = 0;b < 10;b++)if (choose1[b] == 1)choose1[b] = 2;else choose1[b] = 0;
			 }//空格键



		}break;
		延迟(5);
		break;

		case 5:mousehide();myedit();

			break;
	    }
	}
}//主函数结尾         SetConsoleCursorPosition(hOutput, coord)


			//********************************************************************************
			//*                        主循环                                                *
			//********************************************************************************






