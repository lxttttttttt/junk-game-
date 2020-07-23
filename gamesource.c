#include<stdio.h> 
#include <windows.h>
#include <conio.h>
#include"mytool.h"
#include <math.h>

#include"gamepro.h"

//#include<pthread.h>

int main()
{
	
	int ic = 0, px[4] = { 0 }, py[4] = { 0 }, delx = 0, dely = 0,  startx, starty, t = 0, xc, yc,xq,yq;
	char picmeun = 0, k = 0;
	float xstep = 0, ystep = 0;

	POINT pt; // 鼠标坐标储存的结构体
	//icon();
	


	开场动画;//开场
	
	

	HANDLE hOutput;
	COORD coord = { 0,0 };
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	
	开发者调试 
	{
		h = 1;u = 1;j2 = 0;o2 = 0;j4 = 0;tian = 'b';mop[room] = 0;room = 51;comp = room;
	   

	}
			
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
			



			非触发程序 {
			mp:if (room == 0)dicr(100, 14);
				if (room == 51)
				{
					juxing(15, 20, 11, 1);juxing(15, 20, 6, 1);
				}
			}//非持续触发的场景互动


		tableback:system("cls");

			一直循环 //主显示器
			{

				if (mop[room] == tip) { mop[room]++;open[room] = 1;goto mp; }
				if (keyhit[0] == 2){system("cls");keyhit[0] = 0;}//动画刷屏
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
					coord.X = 0;
					coord.Y = 0;
					SetConsoleCursorPosition(hOutput, coord);//局部覆盖更新代码
					printf("\t\t\t\t###########################################################################################################################");printf("\n");
					开发者调试
					{
						GetCursorPos(&pt);
		
					ep = x + 60;
					if ((en > y + 13 && en - y - 13 > 16) || (en < y + 13 && y + 13 - en>1))en = y + 16;
					for (b = en - 31, screeny = 0;en >= b;b++, screeny++)//10
					{
						//--------------------------------------------------------
						//a,b为发生层函数
						//screenx,screeny为投影层函数
						//--------------------------------------------------------
						
						
						for (a = x - 60, screenx = 0;ep >= a;a++, screenx++)
						{
							c = d[b][a];

							if (c == 0) {
								show[screeny][screenx] = ch1; //printf("%c", ch1);
								continue;
							}
							else {
								show[screeny][screenx] = ch2;
								//printf("%c", ch2);
								if (c == 1 || c >= 20)d[b][a] = 0;//清理动态物体
							}
							switch (picture[b][a])
							{
							case 35:show[screeny][screenx] = '#';break;
							case 42:show[screeny][screenx] = '*';break;
							//default:;
							}

						}
						//printf("\n");
					}

					if (picmeun == 0)
					{
						show[10][90] = 35;
						show[10][10] = 35;
						show[30][90] = 35;
						show[30][10] = 35;
						
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
					if (picmeun == 2)
					{

						printf("\t\t\t\t\t\t已确认初始位点            ");
						printf("当前工具");
						switch (t)
						{
						case 0:  printf("  画笔\n");break;
						case 1:  printf("  橡皮\n");break;

						}
						xq = pt.x / xstep - 1;
						yq = pt.y / ystep - 3;
						if (xq > 120)xq = 120;
						if (yq > 40)yq = 40;
						if (xq < 1)xq = 1;
						if (yq < 1)yq = 1;
						show[yq][xq] = '#';

						/*if (GetKeyState(2) < 0) {
							ic = 2;
							switch (t) {
							case 0:picture[y][x] = 42;break;
							case 1:picture[y][x] = 0;break;
							}
						}*/
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

					}


				else {
					ep = x + 60;
					if ((en > y + 13 && en - y - 13 > 16) || (en < y + 13 && y + 13 - en>1))en = y + 16;
					for (b = en - 31, screeny = 0;en >= b;b++, screeny++)//10
					{
						screenx = 0;

						for (a = x - 60, screenx = 0;ep >= a;a++, screenx++)
						{
							c = d[b][a];

							if (c == 0) {
								show[screeny][screenx] = ch1; //printf("%c", ch1);
								continue;
							}
							else {
								show[screeny][screenx] = ch2;
								//printf("%c", ch2);
								if (c == 1 || c >= 20)d[b][a] = 0;//清理动态物体
							}
						}
						//printf("\n");
					}
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
						else if (keyhit[27] > 0) { keyhit[27] = 0;table = 1;_getch();/*清理按键亢余*/goto contable; }
						if (GetKeyState(65) >= 0 && GetKeyState(68) >= 0 && GetKeyState(83) >= 0 && GetKeyState(87) >= 0 && GetKeyState(74) >= 0) { act1 = 0;ax = 0; }//判断是否有摩擦力
					
					
						空格键按下 { j2 = j4;time1 = 0;}//空格键
					}


					
				}break;
				case 1:
				{
					coord.X = 0;
					coord.Y = 0;
					SetConsoleCursorPosition(hOutput, coord);//局部覆盖更新代码
					printf("\t\t\t\t###########################################################################################################################");printf("\n");
					ep = xcar + 60;
					en = ycar + 16;
					for (b = en - 31, screeny = 0;en >= b;b++, screeny++)//10
					{
						screenx = 0;

						for (a = xcar - 60, screenx = 0;ep >= a;a++, screenx++)
						{
							c = d[b][a];

							if (c == 0) {
								show[screeny][screenx] = ch1; //printf("%c", ch1);
								continue;
							}
							else {
								show[screeny][screenx] = ch2;
								//printf("%c", ch2);
								if (c == 1 || c >= 20)d[b][a] = 0;//清理动态物体
							}
						}
						//printf("\n");
					}
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
				//图像显示函数
				for (a = 0;a < 32;a++) {
					p = show[a];
					printf("\t\t\t\t#%s#\n", p);
				}
				//图像显示函数



			
				physicsengine(0);




				//act左奇右偶***
				//操作(旧版本kbhit与getch使用_kbhit与_getch代替)




				//主要东西
				chac( con );
				product();

				//主要东西

				if (open[room] == 1 && d[y][x + 1] == 5 && d[y + 8][x + 1] == 5)
				{
					comp = room; room++;memory[0] = heart1;memory[1] = heart2;memory[2] = m1;memory[3] = comp; memory[4] = y;break;
				}//过门并且储存数据
				if (open[room] == 1 && d[y][x - 1] == 6 && d[y + 8][x - 1] == 6)
				{
					comp = room; room--;memory[0] = heart1;memory[1] = heart2;memory[2] = m1;memory[3] = comp;memory[4] = y;break;
				}//过门并且储存数据











				//if (keyhit[74] == 0)act3 = 0;
				printf("\t\t\t\t###########################################################################################################################\n");
				if (heart1 <= 0) { goto dead; }//死亡函数
				//getchar();
				//任务（对话触发）

				if (act3 > 0) { blade(con); }//攻击放在被攻击目标下，要不然找不到目标造不成伤害
				


				


				
				//检测npc
				if (sit == 1) //检测npc
				{
					sit = 0;
					if (room == 10000)for (a = 0;a < 8;a++) { if (d[y + a][x] == 10) { table = 2;system("cls");goto pcmeun; } } //检测电脑桌子

					if (d[y + 8][x] == 7) { comp = room; room += 50;;memory[0] = heart1;memory[1] = heart2;memory[2] = m1;memory[3] = comp; memory[4] = y;break; }//进门
					if (d[y + 8][x] == 8) { comp = room; room -= 50;;memory[0] = heart1;memory[1] = heart2;memory[2] = m1;memory[3] = comp; memory[4] = y;break; }//出门

					for (a = 0;a < 20;a++)
					{

						if (d[y + 4][x + a] == 19 || d[y + 4][x - a] == 19) { talk = 1;trad = 1; break; }
						if (d[y + 2][x + a] == 24 || d[y + 2][x - a] == 24) { talk = 1;hdso = 1; break; }
						if (d[y + 2][x + a] > 8999 && d[y + 2][x + a] < 10000) { talk = 1;vill = 1;numbvill = d[y + 2][x + a]; break; }
						else
							if (d[y + 2][x - a] > 8999 && d[y + 2][x + a] < 10000) { talk = 1;vill = 1;numbvill = d[y + 2][x - a]; break; }
					}
					if (d[y + 8][x] == 4)//拾取道具函数
					{BOX(0, 0, 1);}
				}
				//检测npc

				if (hearp != heart1) { hearp = heart1;system("cls"); }//受伤函数

				//下显示器
				

				if ( room != 10000)
				{

					coord.X = 0;
					coord.Y = 5;

					if (cartoon == 0) {
						keyhit[0] = 1;
						//第28行
						SetConsoleCursorPosition(hOutput, coord);
						printf("@老子就是%s\n\n%s的体力:%d/%d			\n\n@%s的小钱钱:￥%d  \n\n",n1 ,n1, heart1, heart2, n1, m1);
						if (m1 < 1) { printf("%s现在没有钱", n1); }
						printf("@不要问背包，问就是异次元菊花\n\n@刷新数%d   \n\n@确保你自己没有呗“砸瓦鲁多”）\n\n@ (%d,%d)             ", tme, x,y);
						开发者调试
						{ printf("\n请右键点击 “#” 进行四次定位 \n目前已经定位次数：%d \n", k);
						printf("  %ld   \n   %ld   \n", pt.x, pt.y);
						printf("4点定位的偏差值\n%f  %f\n", xstep, ystep);
						}
						
					}
					else { if(keyhit[0]!=0)keyhit[0] =2; }
					 if (i1 == 1)//人物交互面板
					{
						
						//system("cls");
						if (j4 - j2)
						{//Sleep(300);
							printf("                             ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n                                                                                                              \n");
							printf("                             %s的语录:%s                            \n                                                 (按空格可跳过对话)", n1, mood[jj1][j2]);
							if (time1 == 120) { for (a = 0;a < 40;a++)printf("   ");j2++;time1 = 0; }
							else
							{
								printf("\\");
								for (a = 0;a < time1/12; a++)
								{
									printf("—");
								}
								printf("%d0%%\\", a);
							}
							printf("\n\n");
							time1++;
							i2 = 0;
							if(cartoon == 0)cartoon=2;
							printf("                             ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
							for (a = 0;a < 10;a++)printf("                                                                                                                                         \n");
						}
						else
						{
							if (i2 < 1) { i2 = 1;  system("cls");cartoon = 0; }
						}
					}




					


					if (talk == 1)//如果被检测到了，显示对话框，帧数刷新加快

					{
						coord.X = 0;
						coord.Y = 20;
						SetConsoleCursorPosition(hOutput, coord);
						if (trad >= 存在)trader(2, 1, 1);//显示商人对话
						if (hdso >= 存在)hardso(xmonst[24], ymonst[24], 50, 24, 50, 1);
						if (vill >= 存在)villager(xmonst[a], ymonst[a], 30, numbvill, 50, 1);//上下两端函数中的a用来传递id不可随意替换插入
					}//显示对话框




					instickword();
					

				}
				







				//tme = difftime(end, start);
				time0++;
				for (a = 0;a < 1000;a++)//技能冷却
				{
					if (cooldown[a] > 0)cooldown[a]--;
				}//技能冷却
				if (time0 > 400)
				{
					time0 = 0;/* system("cls");*/
				}//时间系统
				if (tme > 40)youhua -= 2;
				else if (tme <43 )youhua += 2;
				sop = GetTickCount();
				if (tme > 2000)tme = 2000;
				tme = sop - sart;
				sart = GetTickCount();
				延迟(youhua);//3.41的倍率

				//screenedit();

			}//游戏内显示器结尾
		contable:;
		}//游戏本体循环结尾
		break;
		case 1:
		{
			
			SetConsoleCursorPosition(hOutput, coord);
			printf("\n\n\n\n");
			printf("\t\t\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			if (room == 10000) {
				printf("\t\t\t\t\t\t\t\t\t@              -:- -------             @ \n");
			}
			else {
				printf("\t\t\t\t\t\t\t\t\t@       菜   单 (直接按对应数字操作)   @ \n");
			}
			printf("\t\t\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			if (room != 10000)
			{
				printf("\t\t\t\t\t\t\t\t\t@               1设   置               @ \n");
				printf("\t\t\t\t\t\t\t\t\t@               2菜   单               @ \n");
				printf("\t\t\t\t\t\t\t\t\t@               3 DEMO制作名单         @ \n");
				printf("\t\t\t\t\t\t\t\t\t@               0 退出当前游戏         @ \n");
				printf("\t\t\t\t\t\t\t\t\t@               ESC 关闭菜单           @ \n");
				printf("\t\t\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
				if (GetKeyState(27) < 0) { keyhit[27] = 1; }
				else if (keyhit[27] > 0) { keyhit[27] = 0;table = 0;goto tableback; }
				数字0键按下{ keyhit[48] = 1; }
				else if (keyhit[48] > 0) {keyhit[48] = 0;if (room != 10000) {room = 10000;table = 0;comp = room;goto saferoom;}}
				if (_kbhit())
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


					}

			}
			else {

				printf("\t\t\t\t\t\t\t\t\t@         1设   置                     @ \n");
				printf("\t\t\t\t\t\t\t\t\t@         2菜   单    3 DEMO制作名单   @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");

				printf("\t\t\t\t\t\t\t\t\t@         4打开手机游戏《tm鸽子》      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@         5打开游戏垃圾传说            @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				开发者调试
			  { printf("\t\t\t\t\t\t\t\t\t@       按tab局部编辑器                @ \n"); }
					else
				printf("\t\t\t\t\t\t\t\t\t@                                      @ \n");
				printf("\t\t\t\t\t\t\t\t\t@        0  开启/关闭室内照明          @ \n");
				printf("\t\t\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

				printf("\t\t\t\t\t\t\t\t\t@               ESC 放下手机           @ \n");
				printf("\t\t\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
				printf("\t\t\t\t\t\t\t\t\t@                  ---                 @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                || # ||               @ \n");
				printf("\t\t\t\t\t\t\t\t\t@                  ---                 @ \n");
				printf("\t\t\t\t\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");









				if (GetKeyState(27) < 0) { keyhit[27] = 1; }
				else if (keyhit[27] > 0) { keyhit[27] = 0;table = 0;goto tableback; }
				开发者调试{ if (GetKeyState(9) < 0) { keyhit[9] = 1; }
				else if (keyhit[9] > 0) { keyhit[9] = 0;table = 5;system("cls");goto saferoom; } }
				if (_kbhit())
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


					}
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

		case 5:myedit();

			break;
	    }
	}
}//主函数结尾         SetConsoleCursorPosition(hOutput, coord)


			//********************************************************************************
			//*                        主循环                                                *
			//********************************************************************************
