#include<stdio.h> 
#include<stdlib.h>
#include <windows.h>
#include <conio.h>
#include<time.h>
#include<string.h>
#define 关卡设计 roomdesign()
#define 切图后重置 reroom()
#define 人物操作 movebutton
#define 开场动画 startgame()
#define 开发者调试 if (creater > 0)
#define  空 0
#define  非触发程序 if(0)
#define  一直循环 while(1)
#define  存在 1
#define  玩家 1
#define  已探索 1
#define  台 2
#define  墙 3
#define  箱 4
#define  右门 5
#define  左门 6
#define  前门 7
#define  后门 8
#define  电脑 10
#define  背景 15
#define 大于9000的id  是村民
#define  怪物总数 10000
#define  房间数量 10000
#define  空格键按下 if (GetKeyState(32) < 0) 
#define  ESC键按下 if (GetKeyState(27) < 0) 
#define  回车键按下 if (GetKeyState(13) < 0)
#define  数字0键按下 if (GetKeyState(48) < 0)
#define  数字1键按下 if (GetKeyState(49) < 0) 
#define  数字2键按下 if (GetKeyState(50) < 0) 
#define  数字3键按下 if (GetKeyState(51) < 0) 
#define  数字4键按下 if (GetKeyState(52) < 0)
#define  数字5键按下 if (GetKeyState(53) < 0) 
#define  数字6键按下 if (GetKeyState(54) < 0) 
#define  数字7键按下 if (GetKeyState(55) < 0) 
#define  数字8键按下 if (GetKeyState(56) < 0)
#define  数字9键按下 if (GetKeyState(57) < 0) 
#define  A键按下 if (GetKeyState(65) < 0) 
#define  D键按下 if (GetKeyState(68) < 0) 
#define  W键按下 if (GetKeyState(87) < 0) 
#define  S键按下 if (GetKeyState(83) < 0) 
#define  J键按下 if (GetKeyState(74) < 0) 
#define  K键按下 if (GetKeyState(75) < 0) 
#define  延迟    Sleep
#define  paperx    84



//***************
//*声明的全局变量
//***************

//显示屏坐标 




unsigned char
act1 = 0,
act3 = 0,
ato[怪物总数] = { 空 },
die[怪物总数] = { 空 },
dhurt[怪物总数] = { 空 },
boxid[50] = { 空 },
tac[19][39] = { 15 },//拓麻歌子
dieword = 0,
box[怪物总数] = { 空 },
keyhit[100] = { 空 },
shopper,
choose1[10] = { 0 },//抽卡
choose2[10] = { 0 },
age,
key,
board,
handcard1,
handcard2,
hand1[10],
hand2[10],
key1,
jj1,
creater,
hurteen[怪物总数]//受到伤害时效果 
, meun
, trad
, hdso
, vill
, talk

;
unsigned int  ob[100][3] = { 空 };//物品文本以及数量

unsigned int
x,
y,
cg,
*pt,
tacx = 11,
tacy = 15,
xb[50] = { 空 },
yb[50] = { 空 },
xc1,
yc1,
xcar,
ycar,
r[怪物总数] = { 空 },
room = 0,
comp = 0,
i[怪物总数] = { 空 },
xm[怪物总数] = { 空 },
ym[怪物总数] = { 空 },
ai[怪物总数] = { 空 },
xbox[50] = { 空 },
ybox[50] = { 空 },
fag[40][4] = { 空 },
mop[怪物总数] = { 空 },
bladehurt,

st[500][500] = { 空 },
acttime[100] = { 空 }
, talktime
;

float
ab[20] = { 空 },
vb[20] = { 空 },
vxb[20] = { 空 },
aY[怪物总数],
vY[怪物总数],
axmonst[怪物总数] = { 空 },
V1monst[怪物总数] = { 空 },
ayfly[怪物总数] = { 空 },
Vy1monst[怪物总数] = { 空 };
int
V2monst[怪物总数] = { 空 },
Vy2monst[怪物总数] = { 空 },
heart1 = 10,heart2 = 15,
max, con, m1, nice[怪物总数] = { 空 },
ni[怪物总数],
xoc,
yoc,
conmonst[怪物总数] = { 空 },
actmonst[怪物总数] = { 空 },
cooldown[怪物总数] = { 空 }
;
unsigned int
a,
b,
c = 0,
e,
f, /*f=1为落地0为空中*/
memory[20] = { 0 },
d[1000][5000] = { 空 },
hearp = 0,
ep,
en = 0,
tme = 0,
numbvill,
time0,
time1,
sart,
sop;
float ax, ay;//加速度
unsigned char *p, h, u
, xbotton,
ybotton,
xauto,
ydauto,
xboxz,
yboxz,
eid,
xtrd,
ytrd;//monst[怪物种类][怪物数量]
unsigned char trd;//可对话角色在每关出现的标志
unsigned char f1, f2;//地板
unsigned char down, o2, o3;//comp是地图比较
float L1, R1, V1, Vy1;
int	L2, R2, V2, Vy2;
unsigned char ch1, ch2, ch3 /*任务标识符号*/;
unsigned char n1[10] = "老子";
int   m2, m3, m4, sit, elc, table;/*游戏杂项属性*/
unsigned char i1 = 1, i2 = 0, i3, i4, i5, tip = 0, mps[100], hurttoon;
unsigned int mood[100][100], talkmood[10000], screenx, screeny, monst[100][100] = { 0 }, xmonst[怪物总数] = { 0 }, ymonst[怪物总数] = { 0 };
unsigned int  j2 = 0, j3[100] = { 0 }, j4, j5, tt1, tt2;//任务
unsigned int act2;//人物动作模组
unsigned char day[10], night[10], open[房间数量] = { 0 }, show[100][200] = { 0 };
unsigned char tian = 'b', cartoon/*过场动画标志*/, latern = 0/*白天还是黑夜*/, shootgun;
unsigned int k = 0, youhua;/*刷新数*/







unsigned char
oj[60][65] = { "尚方EX龟速宝剑-----按住j键使用",
"尚方EX龟速宝剑-----按住j键使用",
"s2mple最喜欢的小手gun----按k瞄准，按j发射",
"创可贴（回复5体力）----不要贴在奇怪的地方啊",
"手gun子弹----嗯一般不会卡壳"
};








//物品数量

unsigned char txt[60][100] =
{
	"头疼头疼头疼，老子一醒来咋就到这破地方了              ",
	"头疼头疼头疼，老子一醒来咋就到这破地方了            ",
	"附近黑咕隆咚的，不像啥好地方，先找找出路吧		     ",
	"哎等等，英俊的老子咋变像素人了，wdnmd               ",
	"有病没病走两步（a，d键控制方向，按住可用波纹疾走）  ",
	"停！停！停！停,有东西！（按s可与附近物体互动）      ",
	"老子一小跳，人类一大跳（按w跳跃）                   ",
	"前面个好像有个人，我去问问他吧（靠近后按住s互动）   ",
	"一个箱子，一个按钮，当他们到一起。。。。会发生什么? ",
	"怎么感觉走进了一条死路啊？咋连个门都没有            ",
	"算了先不玩了退游戏歇会吧（按ESC键寻找退游戏的方式） ",
	"回来了。。。。。。。                                ",
	"还真是安静。。。。。                                ",
	"我的面前为什么会有个死人啊                          ",
	"有点恐怖                                            ",
	"感觉此地不宜久留                                    ",
	"等等……                                            ",
	"听到门外有人的声音                                  ",


};

//剧情文本


unsigned char montalk[200][80] =
{

	"哇！你是怎么来到这里的? ",
	"哇！你是怎么来到这里的? ",//1
	"这里很久没有人拜访过了\n     \t\t\t     "
	"    emmmm看你的样子好像不是本地人把",

	"我也不知道怎么就来到了这个世界了，你能告诉我这是哪里吗？（按1）",

	"我最近手头有点紧，你能帮帮我吗？(按3)",

	"                    溜了溜了~~~（按0退出）",//5

	"你是谁！为什么会出现在我家！",//6

	"说！你到底是谁！ ",

	"不说的话我就揍你",

	" Emmmm你这装扮不像本地人·········",

	"估计你应该不是王国的走狗",

	"但也不排除你不是他们的奸细！",

	"说！你到底是来干嘛的",

	"                 我走错了！，我只是来参观的（按1）",

	"                 我是来给小怡送信的，村头小哥让我来的（按3）",//14

	"蛤！这里就是整个大陆最大的明珠！安格斯——浦东！",//15

	"不过看你的样子也不像这片大陆上的人 ",

	"马上这栋房子就要被国王的骑士拆迁了",

	"这里据说是国王最喜欢的土地，果然还说要修建——呢啥·····",

	"偶！对了，叫井屏！咱不是文化人，也不知道那是哈",

	"但是我这次一定能得到国王的赏赐成为男爵吧！",

	"                   好的了解~（按0退出）",//21

	"讲真的我手头上也比较紧",//22

	"毕竟骑士拆迁队还没有来过",

	"但是任务还是有的",

	"这任务比较私密·····",

	"emmmmmm ",

	"你懂的··········",

	"emmmmmmm ",

	"就是······",

	"啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊",

	"欸欸欸欸你别走啊~！",

	"就是我。。我。。我一直喜。。。。。。。。。。",

	"喜欢我们村的小怡！！！！！",

	"md羞死老子了！",

	"不！许！tm！的！给！老！子！笑！",

	"总之就是这样，给老子把“情书”送给ta！！",

	"事成之后奖励大大滴有！",

	"你问奖励有多少？500金币！",

	"md我堂堂拆二代500金币还是出的起的！",

	"总之就是这样了，信给我拿好",

	"开心接受，有钱不赚是傻子（按1）",

	"大噶口头瓦鲁，老夫可是正人君子！（按0）",//42

	"蛤？给小怡的信？",//43

	"我老弟这么出息了吗",

	"我不信",

	"把信给我看看！",

	"。。。。。",

	"。。。。。",

	"。。。。。",

	"还真是我老弟的字!",

	"写的还挺肉麻",

	"什么叫“给这世界上最可爱的小怡”",

	"。。。。。。",

	"蛤蛤蛤，笑死我了",

	"你可千万别告诉他我看过信了",

	"你问我小怡在哪？",

	"那丫头就在我这房子后面的房子里",

	"我俩兄弟打小和ta就是邻居",

	"老熟了",

	"总之就这样吧，一路顺风 ",

	"这份艰巨的任务就交给你了啊，兄嘚！",

	"可千万别被人发现啊",

	"小怡她家就在离这不远处，顺着路走就到了，一路顺风~",//63

	" 正你大爷！你知道了我的秘密，",//64

	"不想去也得去！",

	"要不然，嘿嘿，你就完蛋了~~",

	"哎哎哎大哥别打脸，你就行行好",

	"帮小弟一次吧:)",


	"我的人生幸福可全在你手上拉",

	"有钱赚他不香吗~ ",

	"小怡她家就在离这不远处，顺着路走就到了，一路顺风~ ",

	"还没打算走吗？走吧走吧，走完了就被发现了",

	"我也不知道怎么就来到了这个世界了，你能告诉我这是哪里吗？（按1）",

	"溜了溜了~~~（按0退出）",//74

	"蛤！这里就是整个大陆最大的明珠！安格斯——浦东！",//75

	"不过看你的样子也不像这片大陆上的人",

	"马上这栋房子就要被国王的骑士拆迁了",

	"这里据说是国王最喜欢的土地，果然还说要修建——呢啥·····",

	"但是我这次一定能得到国王的赏赐成为男爵吧！",

	"好的了解~（按0退出）",//80

	"（咂舌）这里可是好久没有来过活人了",//81

	"我！巨人王哈德所，当年可是国王的挚友，为国王立下汗马功劳！",

	"为了击退怪物，我看守这里",

	"不知道外面究竟怎么样了",

	"我其实也不知道，我只是个穿越者（按1）     我可是国王的亲信，你必须得帮助我(按3)",

	"溜了溜了~~~（按0退出）",

	"你好你好你好",//87

	"md终于遇到活人了，这年头生意真不好做，我是这里的商人，请问有什么事吗？",//88
		
		"welcome！ 啊哈是你啊，咱又见面了。",
		
		"我需要购买物品吗？（按1进入物品购买）",//90
		
		"我其实也不大知道",//91
		
		"但我知道你背后肯定是死路了",
		
		"如果你想继续往前走，就穿过我身后的这扇门（在门内按住s进入门）",
		
		"不过据说下面会有可怕的人",
		
		"当然你也别问我下面会有什么人，lxt就是这么设计的，你问他去",
		
		"你问我lxt是谁？，emmmm我刚才什么都没说啊:）",
		
		"好的我说累了（按0结束对话）",//97
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",

};


//unsigned char stxt[1][60] = "攻击卡：对敌人造成5点伤害";








//技能
void userpc(int x2, int y2) //暂定检测id为10
{
	x2 = x2 + 30 + 30;y2 = 600 - y2;
	int id = 电脑;
	if (d[y2][x2 + 14] == 0)d[y2][x2 + 14] = id;//15
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//16
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//17
	if (d[y2][x2 + 17] == 0)d[y2][x2 + 17] = id;//
	y2++;
	if (d[y2][x2] == 0)d[y2][x2] = id;//1
	if (d[y2][x2 + 1] == 0)d[y2][x2 + 1] = id;//2
	if (d[y2][x2 + 2] == 0)d[y2][x2 + 2] = id;//3
	if (d[y2][x2 + 3] == 0)d[y2][x2 + 3] = id;//4
	if (d[y2][x2 + 4] == 0)d[y2][x2 + 4] = id;//5
	if (d[y2][x2 + 5] == 0)d[y2][x2 + 5] = id;//6
	if (d[y2][x2 + 6] == 0)d[y2][x2 + 6] = id;//7
	if (d[y2][x2 + 7] == 0)d[y2][x2 + 7] = id;//8
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//9
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//10
	if (d[y2][x2 + 13] == 0)d[y2][x2 + 13] = id;//18
	if (d[y2][x2 + 18] == 0)d[y2][x2 + 18] = id;//

	y2++;
	if (d[y2][x2] == 0)d[y2][x2] = id;//1
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//10
	if (d[y2][x2 + 14] == 0)d[y2][x2 + 14] = id;//15
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//16
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//17
	if (d[y2][x2 + 17] == 0)d[y2][x2 + 17] = id;//
	if (d[y2][x2 + 13] == 0)d[y2][x2 + 13] = id;//18
	if (d[y2][x2 + 18] == 0)d[y2][x2 + 18] = id;//
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//19
	if (d[y2][x2 + 19] == 0)d[y2][x2 + 19] = id;//
	y2++;
	if (d[y2][x2] == 0)d[y2][x2] = id;//1
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//10
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//16
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//17
	y2++;
	if (d[y2][x2] == 0)d[y2][x2] = id;//1
	if (d[y2][x2 + 1] == 0)d[y2][x2 + 1] = id;//2
	if (d[y2][x2 + 2] == 0)d[y2][x2 + 2] = id;//3
	if (d[y2][x2 + 3] == 0)d[y2][x2 + 3] = id;//4
	if (d[y2][x2 + 4] == 0)d[y2][x2 + 4] = id;//5
	if (d[y2][x2 + 5] == 0)d[y2][x2 + 5] = id;//6
	if (d[y2][x2 + 6] == 0)d[y2][x2 + 6] = id;//7
	if (d[y2][x2 + 7] == 0)d[y2][x2 + 7] = id;//8
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//9
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//10
	if (d[y2][x2 + 14] == 0)d[y2][x2 + 14] = id;//15
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//16
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//17
	if (d[y2][x2 + 17] == 0)d[y2][x2 + 17] = id;//
	y2++;
	if (d[y2][x2] == 0)d[y2][x2] = id;//1
	if (d[y2][x2 + 1] == 0)d[y2][x2 + 1] = id;//2
	if (d[y2][x2 + 2] == 0)d[y2][x2 + 2] = id;//3
	if (d[y2][x2 + 3] == 0)d[y2][x2 + 3] = id;//4
	if (d[y2][x2 + 4] == 0)d[y2][x2 + 4] = id;//5
	if (d[y2][x2 + 5] == 0)d[y2][x2 + 5] = id;//6
	if (d[y2][x2 + 6] == 0)d[y2][x2 + 6] = id;//7
	if (d[y2][x2 + 7] == 0)d[y2][x2 + 7] = id;//8
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//9
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//10
	if (d[y2][x2 + 14] == 0)d[y2][x2 + 14] = id;//15
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//16
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//17
	if (d[y2][x2 + 17] == 0)d[y2][x2 + 17] = id;//
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//13
	if (d[y2][x2 + 13] == 0)d[y2][x2 + 13] = id;//18
	if (d[y2][x2 + 18] == 0)d[y2][x2 + 18] = id;//12
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//19

	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//11
	if (d[y2][x2 + 11] == 0)d[y2][x2 + 11] = id;//12
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//13
	if (d[y2][x2 + 13] == 0)d[y2][x2 + 13] = id;//14
	if (d[y2][x2 + 18] == 0)d[y2][x2 + 18] = id;//
	if (d[y2][x2 - 1] == 0)d[y2][x2 - 1] = id;//-3
	if (d[y2][x2 - 3] == 0)d[y2][x2 - 3] = id;//-5
	if (d[y2][x2 - 5] == 0)d[y2][x2 - 5] = id;//-7
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//
	y2++;
	if (d[y2][x2] == 0)d[y2][x2] = id;//1
	if (d[y2][x2 + 1] == 0)d[y2][x2 + 1] = id;//2
	if (d[y2][x2 + 2] == 0)d[y2][x2 + 2] = id;//3
	if (d[y2][x2 + 3] == 0)d[y2][x2 + 3] = id;//4
	if (d[y2][x2 + 4] == 0)d[y2][x2 + 4] = id;//5
	if (d[y2][x2 + 5] == 0)d[y2][x2 + 5] = id;//6
	if (d[y2][x2 + 6] == 0)d[y2][x2 + 6] = id;//7
	if (d[y2][x2 + 7] == 0)d[y2][x2 + 7] = id;//8
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//9
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//10
	if (d[y2][x2 + 14] == 0)d[y2][x2 + 14] = id;//15
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//16
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//17
	if (d[y2][x2 + 17] == 0)d[y2][x2 + 17] = id;//
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//13
	if (d[y2][x2 + 13] == 0)d[y2][x2 + 13] = id;//18
	if (d[y2][x2 + 18] == 0)d[y2][x2 + 18] = id;//12
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//19

	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//11
	if (d[y2][x2 + 11] == 0)d[y2][x2 + 11] = id;//12
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//13
	if (d[y2][x2 + 13] == 0)d[y2][x2 + 13] = id;//14
	if (d[y2][x2 + 18] == 0)d[y2][x2 + 18] = id;//
	if (d[y2][x2 - 1] == 0)d[y2][x2 - 1] = id;//-3
	if (d[y2][x2 - 3] == 0)d[y2][x2 - 3] = id;//-5
	if (d[y2][x2 - 5] == 0)d[y2][x2 - 5] = id;//-7
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//
	if (d[y2][x2 - 2] == 0)d[y2][x2 - 2] = id;//-4
	if (d[y2][x2 - 4] == 0)d[y2][x2 - 4] = id;//-6
	if (d[y2][x2 - 6] == 0)d[y2][x2 - 6] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//13
	if (d[y2][x2 + 11] == 0)d[y2][x2 + 11] = id;//12
	if (d[y2][x2 + 18] == 0)d[y2][x2 + 18] = id;//12
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//
	if (d[y2][x2 + 14] == 0)d[y2][x2 + 14] = id;//15
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//16
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//17
	if (d[y2][x2 + 17] == 0)d[y2][x2 + 17] = id;//
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//13
	if (d[y2][x2 + 13] == 0)d[y2][x2 + 13] = id;//18
	if (d[y2][x2 + 18] == 0)d[y2][x2 + 18] = id;//12
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//19
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//11
	if (d[y2][x2 + 11] == 0)d[y2][x2 + 11] = id;//12
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//13
	if (d[y2][x2 + 13] == 0)d[y2][x2 + 13] = id;//14
	if (d[y2][x2 + 18] == 0)d[y2][x2 + 18] = id;//
}

void bookrack(int x2, int y2)
{ x2 = x2 + 30 + 30;y2 = 600 - y2;
int id = 15;
d[y2 + 0][x2 + 0] = id;d[y2 + 0][x2 + 1] = id;d[y2 + 0][x2 + 2] = id;d[y2 + 0][x2 + 3] = id;d[y2 + 0][x2 + 4] = id;d[y2 + 0][x2 + 5] = id;d[y2 + 0][x2 + 6] = id;d[y2 + 0][x2 + 7] = id;d[y2 + 0][x2 + 8] = id;
d[y2 + 0][x2 + 9] = id;d[y2 + 0][x2 + 10] = id;d[y2 + 0][x2 + 11] = id;d[y2 + 0][x2 + 12] = id;d[y2 + 0][x2 + 13] = id;d[y2 + 0][x2 + 14] = id;d[y2 + 0][x2 + 15] = id;d[y2 + 0][x2 + 16] = id;d[y2 + 0][x2 + 17] = id;
d[y2 + 0][x2 + 18] = id;d[y2 + 0][x2 + 19] = id;d[y2 + 0][x2 + 20] = id;d[y2 + 1][x2 + 0] = id;d[y2 + 1][x2 + 3] = id;d[y2 + 1][x2 + 4] = id;d[y2 + 1][x2 + 6] = id;d[y2 + 1][x2 + 7] = id;d[y2 + 1][x2 + 10] = id;
d[y2 + 1][x2 + 12] = id;d[y2 + 1][x2 + 13] = id;d[y2 + 1][x2 + 16] = id;d[y2 + 1][x2 + 17] = id;d[y2 + 1][x2 + 18] = id;d[y2 + 1][x2 + 20] = id;d[y2 + 2][x2 + 0] = id;d[y2 + 2][x2 + 3] = id;d[y2 + 2][x2 + 4] = id;
d[y2 + 2][x2 + 6] = id;d[y2 + 2][x2 + 7] = id;d[y2 + 2][x2 + 10] = id;d[y2 + 2][x2 + 12] = id;d[y2 + 2][x2 + 13] = id;d[y2 + 2][x2 + 16] = id;d[y2 + 2][x2 + 17] = id;d[y2 + 2][x2 + 18] = id;d[y2 + 2][x2 + 20] = id;
d[y2 + 3][x2 + 0] = id;d[y2 + 3][x2 + 3] = id;d[y2 + 3][x2 + 4] = id;d[y2 + 3][x2 + 6] = id;d[y2 + 3][x2 + 7] = id;d[y2 + 3][x2 + 10] = id;d[y2 + 3][x2 + 12] = id;d[y2 + 3][x2 + 13] = id;d[y2 + 3][x2 + 16] = id;
d[y2 + 3][x2 + 17] = id;d[y2 + 3][x2 + 18] = id;d[y2 + 3][x2 + 20] = id;d[y2 + 4][x2 + 0] = id;d[y2 + 4][x2 + 1] = id;d[y2 + 4][x2 + 2] = id;d[y2 + 4][x2 + 3] = id;d[y2 + 4][x2 + 4] = id;d[y2 + 4][x2 + 5] = id;
d[y2 + 4][x2 + 6] = id;d[y2 + 4][x2 + 7] = id;d[y2 + 4][x2 + 8] = id;d[y2 + 4][x2 + 9] = id;d[y2 + 4][x2 + 10] = id;d[y2 + 4][x2 + 11] = id;d[y2 + 4][x2 + 12] = id;d[y2 + 4][x2 + 13] = id;d[y2 + 4][x2 + 14] = id;
d[y2 + 4][x2 + 15] = id;d[y2 + 4][x2 + 16] = id;d[y2 + 4][x2 + 17] = id;d[y2 + 4][x2 + 18] = id;d[y2 + 4][x2 + 19] = id;d[y2 + 4][x2 + 20] = id;d[y2 + 5][x2 + 0] = id;d[y2 + 5][x2 + 4] = id;d[y2 + 5][x2 + 5] = id;
d[y2 + 5][x2 + 7] = id;d[y2 + 5][x2 + 8] = id;d[y2 + 5][x2 + 10] = id;d[y2 + 5][x2 + 12] = id;d[y2 + 5][x2 + 13] = id;d[y2 + 5][x2 + 17] = id;d[y2 + 5][x2 + 18] = id;d[y2 + 5][x2 + 20] = id;d[y2 + 6][x2 + 0] = id;
d[y2 + 6][x2 + 3] = id;d[y2 + 6][x2 + 4] = id;d[y2 + 6][x2 + 7] = id;d[y2 + 6][x2 + 8] = id;d[y2 + 6][x2 + 10] = id;d[y2 + 6][x2 + 13] = id;d[y2 + 6][x2 + 14] = id;d[y2 + 6][x2 + 17] = id;d[y2 + 6][x2 + 18] = id;
d[y2 + 6][x2 + 20] = id;d[y2 + 7][x2 + 0] = id;d[y2 + 7][x2 + 2] = id;d[y2 + 7][x2 + 3] = id;d[y2 + 7][x2 + 7] = id;d[y2 + 7][x2 + 8] = id;d[y2 + 7][x2 + 10] = id;d[y2 + 7][x2 + 14] = id;d[y2 + 7][x2 + 15] = id;
d[y2 + 7][x2 + 17] = id;d[y2 + 7][x2 + 18] = id;d[y2 + 7][x2 + 20] = id;d[y2 + 8][x2 + 0] = id;d[y2 + 8][x2 + 1] = id;d[y2 + 8][x2 + 2] = id;d[y2 + 8][x2 + 3] = id;d[y2 + 8][x2 + 4] = id;d[y2 + 8][x2 + 5] = id;
d[y2 + 8][x2 + 6] = id;d[y2 + 8][x2 + 7] = id;d[y2 + 8][x2 + 8] = id;d[y2 + 8][x2 + 9] = id;d[y2 + 8][x2 + 10] = id;d[y2 + 8][x2 + 11] = id;d[y2 + 8][x2 + 12] = id;d[y2 + 8][x2 + 13] = id;d[y2 + 8][x2 + 14] = id;
d[y2 + 8][x2 + 15] = id;d[y2 + 8][x2 + 16] = id;d[y2 + 8][x2 + 17] = id;d[y2 + 8][x2 + 18] = id;d[y2 + 8][x2 + 19] = id;d[y2 + 8][x2 + 20] = id;d[y2 + 9][x2 + 0] = id;d[y2 + 9][x2 + 1] = id;d[y2 + 9][x2 + 2] = id;
d[y2 + 9][x2 + 3] = id;d[y2 + 9][x2 + 4] = id;d[y2 + 9][x2 + 5] = id;d[y2 + 9][x2 + 6] = id;d[y2 + 9][x2 + 7] = id;d[y2 + 9][x2 + 8] = id;d[y2 + 9][x2 + 9] = id;d[y2 + 9][x2 + 10] = id;d[y2 + 9][x2 + 11] = id;
d[y2 + 9][x2 + 12] = id;d[y2 + 9][x2 + 13] = id;d[y2 + 9][x2 + 14] = id;d[y2 + 9][x2 + 15] = id;d[y2 + 9][x2 + 16] = id;d[y2 + 9][x2 + 17] = id;d[y2 + 9][x2 + 18] = id;d[y2 + 9][x2 + 19] = id;d[y2 + 9][x2 + 20] = id;
d[y2 + 10][x2 + 0] = id;d[y2 + 10][x2 + 10] = id;d[y2 + 10][x2 + 20] = id;d[y2 + 11][x2 + 0] = id;d[y2 + 11][x2 + 1] = id;d[y2 + 11][x2 + 2] = id;d[y2 + 11][x2 + 3] = id;d[y2 + 11][x2 + 4] = id;d[y2 + 11][x2 + 5] = id;
d[y2 + 11][x2 + 6] = id;d[y2 + 11][x2 + 7] = id;d[y2 + 11][x2 + 8] = id;d[y2 + 11][x2 + 9] = id;d[y2 + 11][x2 + 10] = id;d[y2 + 11][x2 + 11] = id;d[y2 + 11][x2 + 12] = id;d[y2 + 11][x2 + 13] = id;d[y2 + 11][x2 + 14] = id;
d[y2 + 11][x2 + 15] = id;d[y2 + 11][x2 + 16] = id;d[y2 + 11][x2 + 17] = id;d[y2 + 11][x2 + 18] = id;d[y2 + 11][x2 + 19] = id;d[y2 + 11][x2 + 20] = id;

}

void tree(int x2, int y2)
{
	int id = 背景;
	x2 = x2 + 30 + 30;y2 = 600 - y2;
	if (d[y2][x2 + 1] == 0)d[y2][x2 + 1] = id;//2
	if (d[y2][x2 + 2] == 0)d[y2][x2 + 2] = id;//3
	if (d[y2][x2 + 3] == 0)d[y2][x2 + 3] = id;//
	y2++;
	if (d[y2][x2 + 1] == 0)d[y2][x2 + 1] = id;//2
	if (d[y2][x2 + 2] == 0)d[y2][x2 + 2] = id;//3
	if (d[y2][x2 + 3] == 0)d[y2][x2 + 3] = id;//
	if (d[y2][x2 + 4] == 0)d[y2][x2 + 4] = id;//5
	if (d[y2][x2 + 5] == 0)d[y2][x2 + 5] = id;//6
	if (d[y2][x2 + 6] == 0)d[y2][x2 + 6] = id;//7
	if (d[y2][x2 + 7] == 0)d[y2][x2 + 7] = id;//8
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//9
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//
	if (d[y2][x2 - 1] == 0)d[y2][x2 - 1] = id;//-2
	if (d[y2][x2 - 2] == 0)d[y2][x2 - 2] = id;//-3
	if (d[y2][x2 - 3] == 0)d[y2][x2 - 3] = id;//
	y2++;
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//10
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//11
	if (d[y2][x2 + 11] == 0)d[y2][x2 + 11] = id;//12
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//
	if (d[y2][x2 - 3] == 0)d[y2][x2 - 3] = id;//
	if (d[y2][x2 - 4] == 0)d[y2][x2 - 4] = id;//-5
	if (d[y2][x2 - 5] == 0)d[y2][x2 - 5] = id;//-6
	if (d[y2][x2 - 6] == 0)d[y2][x2 - 6] = id;//-7
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//-8
	if (d[y2][x2 - 8] == 0)d[y2][x2 - 8] = id;//-9
	if (d[y2][x2 - 9] == 0)d[y2][x2 - 9] = id;//-10
	if (d[y2][x2 - 10] == 0)d[y2][x2 - 10] = id;//-11
	if (d[y2][x2 - 11] == 0)d[y2][x2 - 11] = id;//
	y2++;
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//13
	if (d[y2][x2 + 13] == 0)d[y2][x2 + 13] = id;//
	if (d[y2][x2 - 11] == 0)d[y2][x2 - 11] = id;//12
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//13
	if (d[y2][x2 + 13] == 0)d[y2][x2 + 13] = id;//-11
	if (d[y2][x2 - 11] == 0)d[y2][x2 - 11] = id;//-12
	if (d[y2][x2 - 12] == 0)d[y2][x2 - 12] = id;//-13
	if (d[y2][x2 - 13] == 0)d[y2][x2 - 13] = id;//-14
	if (d[y2][x2 - 14] == 0)d[y2][x2 - 14] = id;//-15
	if (d[y2][x2 - 15] == 0)d[y2][x2 - 15] = id;//-16
	if (d[y2][x2 - 16] == 0)d[y2][x2 - 16] = id;//
	y2++;
	if (d[y2][x2 + 14] == 0)d[y2][x2 + 14] = id;//15
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//16
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//
	if (d[y2][x2 - 16] == 0)d[y2][x2 - 16] = id;//-17
	if (d[y2][x2 - 17] == 0)d[y2][x2 - 17] = id;//-18
	if (d[y2][x2 - 18] == 0)d[y2][x2 - 18] = id;//-19
	if (d[y2][x2 - 19] == 0)d[y2][x2 - 19] = id;//-20
	if (d[y2][x2 - 20] == 0)d[y2][x2 - 20] = id;//
	y2++;
	if (d[y2][x2 - 20] == 0)d[y2][x2 - 20] = id;//-21
	if (d[y2][x2 - 21] == 0)d[y2][x2 - 21] = id;//-22
	if (d[y2][x2 - 22] == 0)d[y2][x2 - 22] = id;//
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//17
	if (d[y2][x2 + 17] == 0)d[y2][x2 + 17] = id;//
	y2++;
	if (d[y2][x2 - 22] == 0)d[y2][x2 - 22] = id;//-23
	if (d[y2][x2 - 23] == 0)d[y2][x2 - 23] = id;//
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//17
	if (d[y2][x2 + 17] == 0)d[y2][x2 + 17] = id;//
	y2++;
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//17   
	if (d[y2][x2 - 22] == 0)d[y2][x2 - 22] = id;//-23
	y2++;
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//16
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//
	if (d[y2][x2 - 21] == 0)d[y2][x2 - 21] = id;//-22
	if (d[y2][x2 - 22] == 0)d[y2][x2 - 22] = id;//
	if (d[y2][x2 - 23] == 0)d[y2][x2 - 23] = id;//23
	y2++;
	if (d[y2][x2 - 24] == 0)d[y2][x2 - 24] = id;//
	if (d[y2][x2 - 21] == 0)d[y2][x2 - 21] = id;//-20
	if (d[y2][x2 - 20] == 0)d[y2][x2 - 20] = id;//-19
	if (d[y2][x2 - 19] == 0)d[y2][x2 - 19] = id;//-18
	if (d[y2][x2 - 18] == 0)d[y2][x2 - 18] = id;//
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//16
	y2++;
	if (d[y2][x2 - 24] == 0)d[y2][x2 - 24] = id;//
	if (d[y2][x2 - 25] == 0)d[y2][x2 - 25] = id;//
	if (d[y2][x2 - 16] == 0)d[y2][x2 - 16] = id;//-17
	if (d[y2][x2 - 17] == 0)d[y2][x2 - 17] = id;//-18
	if (d[y2][x2 - 15] == 0)d[y2][x2 - 15] = id;//-14
	if (d[y2][x2 - 14] == 0)d[y2][x2 - 14] = id;//
	if (d[y2][x2 + 14] == 0)d[y2][x2 + 14] = id;//15
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//16
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//-16
	if (d[y2][x2 + 17] == 0)d[y2][x2 + 17] = id;//-22
	y2++;
	if (d[y2][x2 - 25] == 0)d[y2][x2 - 25] = id;//
	if (d[y2][x2 - 26] == 0)d[y2][x2 - 26] = id;//-27
	if (d[y2][x2 - 27] == 0)d[y2][x2 - 27] = id;//
	if (d[y2][x2 + 18] == 0)d[y2][x2 + 18] = id;//19
	if (d[y2][x2 + 19] == 0)d[y2][x2 + 19] = id;//20
	if (d[y2][x2 + 20] == 0)d[y2][x2 + 20] = id;//
	y2++;
	if (d[y2][x2 - 27] == 0)d[y2][x2 - 27] = id;//
	if (d[y2][x2 - 28] == 0)d[y2][x2 - 28] = id;//
	if (d[y2][x2 + 20] == 0)d[y2][x2 + 20] = id;//21
	if (d[y2][x2 + 21] == 0)d[y2][x2 + 21] = id;//22
	if (d[y2][x2 + 22] == 0)d[y2][x2 + 22] = id;//23
	if (d[y2][x2 + 23] == 0)d[y2][x2 + 23] = id;//
	y2++;
	if (d[y2][x2 - 28] == 0)d[y2][x2 - 28] = id;//
	if (d[y2][x2 - 29] == 0)d[y2][x2 - 29] = id;//
	if (d[y2][x2 + 23] == 0)d[y2][x2 + 23] = id;//
	y2++;
	if (d[y2][x2 - 29] == 0)d[y2][x2 - 29] = id;//
	if (d[y2][x2 + 23] == 0)d[y2][x2 + 23] = id;//
	if (d[y2][x2 + 24] == 0)d[y2][x2 + 24] = id;//
	y2++;
	if (d[y2][x2 - 29] == 0)d[y2][x2 - 29] = id;//
	if (d[y2][x2 + 24] == 0)d[y2][x2 + 24] = id;//
	if (d[y2][x2 + 7] == 0)d[y2][x2 + 7] = id;//6
	if (d[y2][x2 + 6] == 0)d[y2][x2 + 6] = id;//
	y2++;
	if (d[y2][x2 - 28] == 0)d[y2][x2 - 28] = id;//
	if (d[y2][x2 + 24] == 0)d[y2][x2 + 24] = id;//
	if (d[y2][x2 + 6] == 0)d[y2][x2 + 6] = id;//5
	if (d[y2][x2 + 5] == 0)d[y2][x2 + 5] = id;//
	y2++;
	if (d[y2][x2 - 28] == 0)d[y2][x2 - 28] = id;//
	if (d[y2][x2 - 29] == 0)d[y2][x2 - 29] = id;//-30
	if (d[y2][x2 - 30] == 0)d[y2][x2 - 30] = id;//
	if (d[y2][x2 + 24] == 0)d[y2][x2 + 24] = id;//25
	if (d[y2][x2 + 25] == 0)d[y2][x2 + 25] = id;//
	if (d[y2][x2 + 6] == 0)d[y2][x2 + 6] = id;//5
	if (d[y2][x2 + 5] == 0)d[y2][x2 + 5] = id;//4
	if (d[y2][x2 + 4] == 0)d[y2][x2 + 4] = id;//3
	if (d[y2][x2 + 3] == 0)d[y2][x2 + 3] = id;//2
	if (d[y2][x2 + 2] == 0)d[y2][x2 + 2] = id;//
	y2++;
	if (d[y2][x2 - 28] == 0)d[y2][x2 - 28] = id;//
	if (d[y2][x2 - 29] == 0)d[y2][x2 - 29] = id;//-30
	if (d[y2][x2 - 30] == 0)d[y2][x2 - 30] = id;//
	if (d[y2][x2 + 2] == 0)d[y2][x2 + 2] = id;//1
	if (d[y2][x2 + 1] == 0)d[y2][x2 + 1] = id;//0
	if (d[y2][x2] == 0)d[y2][x2] = id;//-1
	if (d[y2][x2 - 1] == 0)d[y2][x2 - 1] = id;//-2
	if (d[y2][x2 - 2] == 0)d[y2][x2 - 2] = id;//
	if (d[y2][x2 + 4] == 0)d[y2][x2 + 4] = id;//5
	if (d[y2][x2 + 5] == 0)d[y2][x2 + 5] = id;//7
	if (d[y2][x2 + 7] == 0)d[y2][x2 + 7] = id;//8
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//
	if (d[y2][x2 + 20] == 0)d[y2][x2 + 20] = id;//21
	if (d[y2][x2 + 21] == 0)d[y2][x2 + 21] = id;//22
	if (d[y2][x2 + 22] == 0)d[y2][x2 + 22] = id;//23
	if (d[y2][x2 + 23] == 0)d[y2][x2 + 23] = id;//24
	if (d[y2][x2 + 24] == 0)d[y2][x2 + 24] = id;//
	y2++;
	if (d[y2][x2 - 28] == 0)d[y2][x2 - 28] = id;//
	if (d[y2][x2 - 29] == 0)d[y2][x2 - 29] = id;//-30
	if (d[y2][x2 - 27] == 0)d[y2][x2 - 27] = id;//
	if (d[y2][x2 - 3] == 0)d[y2][x2 - 3] = id;//-4
	if (d[y2][x2 - 4] == 0)d[y2][x2 - 4] = id;//-6
	if (d[y2][x2 - 6] == 0)d[y2][x2 - 6] = id;//-7
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//10
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//11
	if (d[y2][x2 + 11] == 0)d[y2][x2 + 11] = id;//12
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//13
	if (d[y2][x2 + 13] == 0)d[y2][x2 + 13] = id;//14
	if (d[y2][x2 + 14] == 0)d[y2][x2 + 14] = id;//15
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//16
	if (d[y2][x2 + 16] == 0)d[y2][x2 + 16] = id;//17
	if (d[y2][x2 + 17] == 0)d[y2][x2 + 17] = id;//18
	if (d[y2][x2 + 18] == 0)d[y2][x2 + 18] = id;//19
	if (d[y2][x2 + 19] == 0)d[y2][x2 + 19] = id;//
	y2++;
	if (d[y2][x2 - 27] == 0)d[y2][x2 - 27] = id;//-26
	if (d[y2][x2 - 26] == 0)d[y2][x2 - 26] = id;//-25
	if (d[y2][x2 - 25] == 0)d[y2][x2 - 25] = id;//-24
	if (d[y2][x2 - 24] == 0)d[y2][x2 - 24] = id;//-23
	if (d[y2][x2 - 23] == 0)d[y2][x2 - 23] = id;//-22
	if (d[y2][x2 - 22] == 0)d[y2][x2 - 22] = id;//
	if (d[y2][x2 - 18] == 0)d[y2][x2 - 18] = id;//-17
	if (d[y2][x2 - 17] == 0)d[y2][x2 - 17] = id;//-16
	if (d[y2][x2 - 16] == 0)d[y2][x2 - 16] = id;//-15
	if (d[y2][x2 - 15] == 0)d[y2][x2 - 15] = id;//-14
	if (d[y2][x2 - 14] == 0)d[y2][x2 - 14] = id;//-13
	if (d[y2][x2 - 13] == 0)d[y2][x2 - 13] = id;//-12
	if (d[y2][x2 - 12] == 0)d[y2][x2 - 12] = id;//-11
	if (d[y2][x2 - 11] == 0)d[y2][x2 - 11] = id;//-10
	if (d[y2][x2 - 10] == 0)d[y2][x2 - 10] = id;//-9
	if (d[y2][x2 - 9] == 0)d[y2][x2 - 9] = id;//
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//-6
	if (d[y2][x2 - 6] == 0)d[y2][x2 - 6] = id;//-5
	if (d[y2][x2 - 5] == 0)d[y2][x2 - 5] = id;//-4
	if (d[y2][x2 - 4] == 0)d[y2][x2 - 4] = id;//
	if (d[y2][x2 + 11] == 0)d[y2][x2 + 11] = id;//12
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//14
	if (d[y2][x2 + 14] == 0)d[y2][x2 + 14] = id;//15
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//

	y2++;
	if (d[y2][x2 - 22] == 0)d[y2][x2 - 22] = id;//-21
	if (d[y2][x2 - 21] == 0)d[y2][x2 - 21] = id;//-20
	if (d[y2][x2 - 20] == 0)d[y2][x2 - 20] = id;//-19
	if (d[y2][x2 - 19] == 0)d[y2][x2 - 19] = id;//-18
	if (d[y2][x2 - 18] == 0)d[y2][x2 - 18] = id;//-17
	if (d[y2][x2 - 17] == 0)d[y2][x2 - 17] = id;//
	if (d[y2][x2 - 14] == 0)d[y2][x2 - 14] = id;//-13
	if (d[y2][x2 - 13] == 0)d[y2][x2 - 13] = id;//-12
	if (d[y2][x2 - 12] == 0)d[y2][x2 - 12] = id;//-11
	if (d[y2][x2 - 11] == 0)d[y2][x2 - 11] = id;//-10
	if (d[y2][x2 - 10] == 0)d[y2][x2 - 10] = id;//-9
	if (d[y2][x2 + 11] == 0)d[y2][x2 + 11] = id;//12
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//

	y2++;
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//
	if (d[y2][x2 - 10] == 0)d[y2][x2 - 10] = id;//-9
	if (d[y2][x2 - 9] == 0)d[y2][x2 - 9] = id;//-8
	if (d[y2][x2 - 8] == 0)d[y2][x2 - 8] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//
	if (d[y2][x2 - 8] == 0)d[y2][x2 - 8] = id;//
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//9
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//9
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//9
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//9
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//9
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//9
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//9
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//9
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//9
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//9
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//9
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//
	y2++;
	if (d[y2][x2 - 7] == 0)d[y2][x2 - 7] = id;//9
	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//
	if (d[y2][x2 - 8] == 0)d[y2][x2 - 8] = id;//
	y2++;

	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//
	if (d[y2][x2 - 8] == 0)d[y2][x2 - 8] = id;//
	if (d[y2][x2 - 9] == 0)d[y2][x2 - 9] = id;//
	y2++;

	if (d[y2][x2 + 8] == 0)d[y2][x2 + 8] = id;//
	if (d[y2][x2 + 9] == 0)d[y2][x2 + 9] = id;//10
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//
	if (d[y2][x2 - 10] == 0)d[y2][x2 - 10] = id;//-11
	if (d[y2][x2 - 11] == 0)d[y2][x2 - 11] = id;//-12
	if (d[y2][x2 - 12] == 0)d[y2][x2 - 12] = id;//
	if (d[y2][x2 - 9] == 0)d[y2][x2 - 9] = id;//
	y2++;
	if (d[y2][x2 - 12] == 0)d[y2][x2 - 12] = id;//
	if (d[y2][x2 - 13] == 0)d[y2][x2 - 13] = id;//
	if (d[y2][x2 + 10] == 0)d[y2][x2 + 10] = id;//
	if (d[y2][x2 + 11] == 0)d[y2][x2 + 11] = id;//12
	if (d[y2][x2 + 12] == 0)d[y2][x2 + 12] = id;//13
	if (d[y2][x2 + 13] == 0)d[y2][x2 + 13] = id;//14
	if (d[y2][x2 + 14] == 0)d[y2][x2 + 14] = id;//
	y2++;
	if (d[y2][x2 - 13] == 0)d[y2][x2 - 13] = id;//-14
	if (d[y2][x2 - 14] == 0)d[y2][x2 - 14] = id;//-15
	if (d[y2][x2 - 15] == 0)d[y2][x2 - 15] = id;//-16
	if (d[y2][x2 - 16] == 0)d[y2][x2 - 16] = id;//14
	if (d[y2][x2 + 14] == 0)d[y2][x2 + 14] = id;//15
	if (d[y2][x2 + 15] == 0)d[y2][x2 + 15] = id;//
}

void HideCursor()
{  //定义隐藏光标函数
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	SetConsoleCursorInfo(handle, &cursor);
}

void eexit()
{
	if (room > comp) {
		if (room - comp < 50) { x = 12 + 60; } if (room - comp == 50)y = 576;//46-22=24
	}//所有位置都是实际位置移60
	if (room < comp) {
		if (comp - room < 50) { x = 142 + 60; }if (comp - room == 50)y = 591;//46-37=9
	}
}

void physicsengine(int e) 
{
	switch(e) {
	case 0:
		
		{
		//摩擦力系数
		if (f == 1 && (act1 == 0 || act3 > 0))
		{
			V1 = V1 / 1.2;;if (V1<0.1&&V1>-0.1) { V1 = 0; }
		}
		//物理引擎
		//猛汉跳楼模拟器
		if (d[y + 9][x] != 2 && d[y + 9][x + 1] != 2 && d[y + 9][x - 1] != 2 && d[y + 9][x] != 3 && d[y + 9][x + 1] != 3 && d[y + 9][x - 1] != 3)
		{
			if (ay < 2)ay += 0.5;if (Vy1 < 8)Vy1 = Vy1 + ay / 1.2;Vy2 = Vy1;
			for (a = 0;a < Vy2;a++)//下落检测
			{
				y++;if (d[y + 9][x] == 2 || d[y + 9][x + 1] == 2 || d[y + 9][x - 1] == 2 || d[y + 9][x] == 3 || d[y + 9][x + 1] == 3 || d[y + 9][x - 1] == 3)
				{
					f = 1;ay = 0;Vy1 = 0;Vy2 = 0;break;
				}
			}f = 0;
		}
		else { f = 1;ay = 0;Vy1 = 0;Vy2 = 0; }
		//猛汉跳楼模拟器

		if (ax != 0)
		{
			V1 = V1 + ax / 12;
			if (V1 <= -max) { V1 = -max;act1 = 3; }
			else if (V1 >= max) { V1 = max; act1 = 4; }
		}
		V2 = V1;
		if (V2 > 0)
		{
			{for (a = 0;a < V2;a++)
			{
				if (
					d[y + 6][x + 2] == 3 || d[y + 5][x + 2] == 3 || d[y + 4][x + 3] == 3 || d[y + 3][x + 3] == 3 || d[y + 1][x + 2] == 3 || d[y][x + 2] == 3
					)
				{
					act2 = 1;V1 = 0;V2 = 0;ax = 0;x = x - 2;break;
				}
				else act2 = 0;
				if ((d[y + 8][x + 2] == 3 || d[y + 7][x + 2] == 3) && d[y + 6][x + 2] == 0 && (d[y + 5][x + 2] == 3 && d[y + 4][x + 3] == 0 && d[y + 3][x + 3] == 0 && d[y + 1][x + 2] == 0 && d[y][x + 2] == 0))
				{
					y--;//便于上楼梯函数
				}
				x++;
			}
			}

		}
		if (V2 < 0)
		{
			{for (a = 0;a + V2;a++)
			{
				if (
					d[y + 6][x - 2] == 3 || d[y + 5][x - 2] == 3 || d[y + 4][x - 3] == 3 || d[y + 3][x - 3] == 3 || d[y + 1][x - 2] == 3 || d[y][x - 2] == 3
					)
				{
					act2 = 1;V1 = 0;V2 = 0;ax = 0;x = x + 2;break;
				}
				else act2 = 0;
				if ((d[y + 8][x - 2] == 3 || d[y + 7][x - 2] == 3) && (d[y + 6][x - 2] == 0 && d[y + 5][x - 2] == 0 && d[y + 4][x - 3] == 0 && d[y + 3][x - 3] == 0 && d[y + 1][x - 2] == 0 && d[y][x - 2] == 0))
				{
					y--;//便于上楼梯函数
				}
				x--;
			}
			}
		}
	}break;

	case 1:break;
	default:;
	}
}

void startgame() {
	int a, b;
	
	

	
	/*HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buf = { 130,63 };

	
	SetConsoleScreenBufferSize(con, buf);
	system("mode con cols=120 lines=60");*/
	延迟(10);
	HANDLE hOutput;
	COORD coord = { 0,0 };
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);


	HideCursor();//定义隐藏光标函数
	day[0] = ' ';day[1] = '*';
	night[0] = ' ';night[1] = '+';
	ch1 = night[0];
	ch2 = night[1];
	
	
	for (a = 0;a < 5;a++) {
		coord.X = 53;
		coord.Y = 0;
		SetConsoleCursorPosition(hOutput, coord);
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		coord.X = 53;
		coord.Y = 9;
		SetConsoleCursorPosition(hOutput, coord);
		printf("----------------------+-----------------------------------+---------------------\n");
		coord.X = 53;
		coord.Y = 50;
		SetConsoleCursorPosition(hOutput, coord);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		for (a = 10;a < 50;a++)
		{
			coord.Y = a;
			coord.X = 75;
			SetConsoleCursorPosition(hOutput, coord);
			printf("!");
			coord.Y = a;
			coord.X = 111;
			SetConsoleCursorPosition(hOutput, coord);
			printf("!");

		}
		for (a = 0;a < 50;a++)
		{
			coord.Y = a;
			coord.X = 53;
			SetConsoleCursorPosition(hOutput, coord);
			if (a == 18 || a == 32)
				printf("@");
			else printf("+");
			coord.Y = a;
			coord.X = 133;
			SetConsoleCursorPosition(hOutput, coord);
			printf("+");
		}
		coord.X = paperx;
		coord.Y = 2;
		SetConsoleCursorPosition(hOutput, coord);
		printf("&&&&&&&&&&&&&&&&&&\n");
		延迟(75);
		coord.X = paperx;
		coord.Y = 3;
		SetConsoleCursorPosition(hOutput, coord);
		printf("&&&&&&&&&&&&&&&&&&\n");
		延迟(75);
		coord.X = paperx;
		coord.Y = 4;
		SetConsoleCursorPosition(hOutput, coord);
		printf("&&&&&&&&&&&&&&&&&&\n");延迟(75);
		coord.X = paperx;
		coord.Y = 5;
		SetConsoleCursorPosition(hOutput, coord);
		printf("&&&&&&&&&&&&&&&&&&\n");延迟(75);
		coord.X = paperx;
		coord.Y = 6;
		SetConsoleCursorPosition(hOutput, coord);
		printf("&&&&&&&&&&&&&&&&&&\n");延迟(75);
		system("cls");

	}



	coord.X = 53;
	coord.Y = 0;
	SetConsoleCursorPosition(hOutput, coord);
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	coord.X = 53;
	coord.Y = 9;
	SetConsoleCursorPosition(hOutput, coord);
	printf("----------------------+-----------------------------------+---------------------\n");
	coord.X = 53;
	coord.Y = 50;
	SetConsoleCursorPosition(hOutput, coord);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	for (a = 10;a < 50;a++)
	{
		coord.Y = a;
		coord.X = 75;
		SetConsoleCursorPosition(hOutput, coord);
		printf("!");
		coord.Y = a;
		coord.X = 111;
		SetConsoleCursorPosition(hOutput, coord);
		printf("!");

	}
	for (a = 0;a < 50;a++)
	{
		coord.Y = a;
		coord.X = 53;
		SetConsoleCursorPosition(hOutput, coord);
		if (a == 18 || a == 32)
			printf("@");
		else printf("+");
		coord.Y = a;
		coord.X = 133;
		SetConsoleCursorPosition(hOutput, coord);
		printf("+");
	}



	coord.X = 118;
	coord.Y = 2;
	SetConsoleCursorPosition(hOutput, coord);
	printf("绝密*开封前");
	
	/*printf("								⣿⣿⣿⣿⣿⣿⣿⣿⣿⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
	printf("						    	⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠹⢿⣿⣿⣿⣿⣿⡿⠋⣿⣿⣿⣿\n");
	printf("								⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠻⣿⣿⡿⠏⠀⠀⣿⣿⣿⣿\n");
	printf("								⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠙⠋⠀⠀⠀⢀⣿⣿⣿⣿\n");
	printf("								⣿⣿⣷⡈⠉⠉⠉⠉⠉⠀⣀⡤⠴⠶⠶⠶⠤⣄⡀⠸⠿⠿⠛⢛\n");
	printf("								⣿⣿⣿⣿⡄⠀⠀⠀⣰⠚⠁⠀⠀⠀⠀⠀⠀⠀⠳⣄⠀⠀⢠⣾\n");
	printf("								⣿⣿⣿⣿⣷⠀⠀⡜⠁⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⠘⡆⢠⣿⣿\n");
	printf("								⣿⣿⠿⠛⠉⠀⢰⠇⠀⠰⣾⡯⠭⠭⣭⠭⡭⠭⠭⠭⢿⡀⠙⠿\n");
	printf("								⣿⣤⣀⠀⠀⠀⢸⠀⢠⣧⣤⣤⣤⠤⢼⣾⠥⣤⡤⠤⠬⡇⣠⣴\n");
	printf("								⣿⣿⣿⣿⡦⠀⢸⠀⠈⢧⡀⠁⠀⠀⡠⠛⣄⠈⠀⢀⣠⠇⣿⣿\n");
	printf("								⣿⣿⠿⠋⠀⠀⣸⡄⠀⢤⣉⠓⠚⠋⠁⡀⢸⡩⣯⡭⢿⡀⠙⠿\n");
	printf("								⣿⣷⣤⣄⡀⢼⠋⠀⠀⠀⠉⠉⠁⠀⠀⠳⣼⠇⠀⠀⣼⢹⣾⣿\n");
	printf("								⣿⣿⣿⣿⡟⠈⠳⣤⠀⠀⡀⠀⠀⣀⣀⣀⣀⣀⡀⠀⣿⡻⣿⣿\n");
	printf("								⣿⣿⣿⣿⣾⣿⣿⠞⣆⠸⡇⠚⠉⠁⠀⣿⣿⡟⠉⢁⣿⣿⣿⣿\n");
	printf("								⣿⣿⣿⣿⣿⣿⣿⣶⣿⣆⠈⠁⠀⠰⡖⠙⠛⠃⣠⣿⣿⣿⣿⣿\n");
	printf("								⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡦⣄⣀⣀⣠⣴⣾⣿⣿⣿⣿⣿⣿\n");
	printf("								⣿⣿⣿⣿⣿⣿⡿⠿⠟⠛⡛⢷⣤⣀⣠⢾⣛⠛⠿⢿⣿⣿⣿⣿\n");
	printf("								⣿⣿⣿⣿⣿⠃⠀⠀⠀⢰⠃⢸⠀⠀⠀⠘⡟⣆⠀⠀⢹⣿⣿⣿\n");
	*/










	for (a = 0;a < 8;a++) {
		coord.X = 53;
		coord.Y = 0;
		SetConsoleCursorPosition(hOutput, coord);
		printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		coord.X = 53;
		coord.Y = 9;
		SetConsoleCursorPosition(hOutput, coord);
		printf("----------------------+-----------------------------------+---------------------\n");
		coord.X = 53;
		coord.Y = 50;
		SetConsoleCursorPosition(hOutput, coord);
		printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		for (a = 10;a < 50;a++)
		{
			coord.Y = a;
			coord.X = 75;
			SetConsoleCursorPosition(hOutput, coord);
			printf("!");
			coord.Y = a;
			coord.X = 111;
			SetConsoleCursorPosition(hOutput, coord);
			printf("!");

		}
		for (a = 0;a < 50;a++)
		{
			coord.Y = a;
			coord.X = 53;
			SetConsoleCursorPosition(hOutput, coord);
			if (a == 18 || a == 32)
				printf("@");
			else printf("+");
			coord.Y = a;
			coord.X = 133;
			SetConsoleCursorPosition(hOutput, coord);
			printf("+");
		}
		coord.X = paperx;
		coord.Y = 2;
		SetConsoleCursorPosition(hOutput, coord);
		printf(".__/\\       /\\ __   \n");
		延迟(175);
		coord.X = paperx;
		coord.Y = 3;
		SetConsoleCursorPosition(hOutput, coord);
		printf("|  )/___  __)//  |_  \n");
		延迟(175);
		coord.X = paperx;
		coord.Y = 4;
		SetConsoleCursorPosition(hOutput, coord);
		printf("|  | \\  \\/  /\\   __\\  \n");延迟(175);
		coord.X = paperx;
		coord.Y = 5;
		SetConsoleCursorPosition(hOutput, coord);
		printf("|  |__>    <  |  |  \n");延迟(175);
		coord.X = paperx;
		coord.Y = 6;
		SetConsoleCursorPosition(hOutput, coord);
		printf("|____/__/\\__\\ |__|  \n");延迟(175);
		
		coord.X = 55;
		coord.Y = 12;
		SetConsoleCursorPosition(hOutput, coord);

		printf("\tXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXX\n");
		延迟(100);
		coord.X = 55;
		coord.Y = 15;
		SetConsoleCursorPosition(hOutput, coord);
		printf("\tXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXX");
		延迟(100);
		coord.X = 55;
		coord.Y = 18;
		SetConsoleCursorPosition(hOutput, coord);
		printf("\tXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXX\n");
		延迟(100);
		coord.X = 55;
		coord.Y = 21;
		SetConsoleCursorPosition(hOutput, coord);
		printf("\tXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXX");
		延迟(100);
		coord.X = 55;
		coord.Y = 24;
		SetConsoleCursorPosition(hOutput, coord);

		printf("\tXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXX\n");
		延迟(100);
		coord.X = 55;
		coord.Y = 27;
		SetConsoleCursorPosition(hOutput, coord);
		printf("\tXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXX");
		延迟(100);
		coord.X = 55;
		coord.Y = 30;
		SetConsoleCursorPosition(hOutput, coord);
		printf("\tXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXX\n");
		延迟(100);
		coord.X = 55;
		coord.Y = 33;
		SetConsoleCursorPosition(hOutput, coord);
		printf("\tXXXXXXXXXXXXXXXXXXXXXXXXX XXXXXXX");
		延迟(100);
		system("cls");
	}




	coord.X = 53;
	coord.Y = 0;
	SetConsoleCursorPosition(hOutput, coord);
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	coord.X = 53;
	coord.Y = 9;
	SetConsoleCursorPosition(hOutput, coord);
	printf("----------------------+-----------------------------------+---------------------\n");
	coord.X = 53;
	coord.Y = 50;
	SetConsoleCursorPosition(hOutput, coord);
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	for (a = 10;a < 50;a++)
	{
		coord.Y = a;
		coord.X = 75;
		SetConsoleCursorPosition(hOutput, coord);
		printf("!");
		coord.Y = a;
		coord.X = 111;
		SetConsoleCursorPosition(hOutput, coord);
		printf("!");

	}
	for (a = 0;a < 50;a++)
	{
		coord.Y = a;
		coord.X = 53;
		SetConsoleCursorPosition(hOutput, coord);
		if (a == 18 || a == 32)
			printf("@");
		else printf("+");
		coord.Y = a;
		coord.X = 133;
		SetConsoleCursorPosition(hOutput, coord);
		printf("+");
	}
	coord.X = paperx;
	coord.Y = 2;
	SetConsoleCursorPosition(hOutput, coord);
	printf(".__/\\       /\\ __   \n");
	
	coord.X = paperx;
	coord.Y = 3;
	SetConsoleCursorPosition(hOutput, coord);
	printf("|  )/___  __)//  |_  \n");
	
	coord.X = paperx;
	coord.Y = 4;
	SetConsoleCursorPosition(hOutput, coord);
	printf("|  | \\  \\/  /\\   __\\  \n");
	coord.X = paperx;
	coord.Y = 5;
	SetConsoleCursorPosition(hOutput, coord);
	printf("|  |__>    <  |  |  \n");
	coord.X = paperx;
	coord.Y = 6;
	SetConsoleCursorPosition(hOutput, coord);
	printf("|____/__/\\__\\ |__|  \n");



	coord.X = 55;
	coord.Y = 12;
	SetConsoleCursorPosition(hOutput, coord);

	printf("\t正在初始化系统，请稍后\n");
	延迟(100*3);
	coord.X = 55;
	coord.Y = 15;
	SetConsoleCursorPosition(hOutput, coord);
	printf("\t确保你已经将窗口全屏，将系统分辨率调为1920*1080，关闭中文输入法与大写");
	延迟(100 * 3);
	coord.X = 55;
	coord.Y = 18;
	SetConsoleCursorPosition(hOutput, coord);
	printf("\t程序框字体为16号 \n");
	延迟(100 * 3);
	coord.X = 55;
	coord.Y = 21;
	SetConsoleCursorPosition(hOutput, coord);
	printf("\t若win7及以下系统无法全屏");
	延迟(100 * 3);
	coord.X = 55;
	coord.Y = 24;
	SetConsoleCursorPosition(hOutput, coord);
	printf("\t右键程序边框打开属性在窗口或布局中设宽为240高60然后重启程序");
	延迟(100 * 3);
	coord.X = 55;
	coord.Y = 27;
	SetConsoleCursorPosition(hOutput, coord);
	printf("\t进入游戏后如果画面不流畅可以按ESC打开菜单选择设置修改流畅度");
	延迟(100 * 3);
	coord.X = 55;
	coord.Y = 30;
	SetConsoleCursorPosition(hOutput, coord);
	printf("\t本游戏由lxt制作");
	printf("++++++++");
	延迟(100 * 3);
	coord.X = 118;
	coord.Y = 2;
	SetConsoleCursorPosition(hOutput, coord);
	printf("绝密*开封前");

	延迟(100 * 3);
	coord.X = 55;
	coord.Y = 33;
	SetConsoleCursorPosition(hOutput, coord);
	printf("\t初始化成功，请按回车继续\n");

	con = 1;
	act2 = 0;
	time0 = 0;
	time1 = 0;
	ch1 = ' ';
	ch3 = 0;
	table = 0;
	L2 = 0;
	for (b = 0;b < 19;b++)for (a = 0;a < 38;a++)tac[b][a] = '$';//拓麻歌子初始化
	R2 = 0;
	max = 3;
	V2 = 0;
	Vy2 = 0;
	xcar = 0;
	ycar = 0;
	key1 = 0;
	L1 = 0;
	R1 = 0;
	V1 = 0;
	Vy1 = 0;
	f = 1;
	down = 0;
	youhua = 58;
	ax = 0;
	sart = 0;
	sop = 0;
	ay = 0;
	x = 80;
	y = 600 - 11;
	en = y + 13;
	cg = 0;
	sit = 0;
	comp = 0;
	elc = 0;
	cartoon = 0;
	shootgun = 0;
	xtrd = 0;
	ytrd = 0;
	trd = 0;
	numbvill;
	hdso = 0;
	talk = 0;
	shopper = 0;
	m1 = 100;
	age = 0;
	bladehurt = 5,
		talktime = 0
		;
	//time_t start, end;//计时函数开启与结束


	screenx = 0;
	screeny = 0;
	memory[0] = 10;//当前生命值
	memory[1] = 15;//最大生命值
	memory[2] = 100;//金钱
	memory[3] = 0;//上一房间号
	memory[4] = 600 - 11;;//纵坐标




	/*mood[0][9] = txt9;
	mood[0][10] = txt10;*/

	//








	system("color 07");//改变界面颜色



	for (a = 1;a < 10000;a++) {
		if (txt[a][0] == 0) break;
		mood[0][a - 1] = txt[a];//“木（目）”录
	}
	for (a = 0;a < 10000;a++) {
		if (montalk[a][0] == 0) break;
		talkmood[a] = montalk[a];//“木（目）”录
	}


	

	一直循环
	{
		延迟(40);
		if (GetKeyState(13) < 0) { break; }//
		if (GetKeyState(65) < 0 && GetKeyState(68) < 0) { creater = 1;break; }//d

	}



	HideCursor();
}

void house2(int x2, int y2) {//宽68
	int id = 15, a, b, c, y1, x1;
	x2 = x2 + 30 + 30;y2 = 600 - y2;
	d[y2 + 4][x2 + 7] = id;d[y2 + 4][x2 + 8] = id;d[y2 + 4][x2 + 9] = id;d[y2 + 4][x2 + 10] = id;d[y2 + 5][x2 - 14] = id;d[y2 + 5][x2 - 13] = id;
	d[y2 + 5][x2 - 12] = id;d[y2 + 5][x2 - 11] = id;d[y2 + 5][x2 - 10] = id;d[y2 + 5][x2 - 9] = id;d[y2 + 5][x2 - 8] = id;d[y2 + 5][x2 - 7] = id;
	d[y2 + 5][x2 - 6] = id;d[y2 + 5][x2 - 5] = id;d[y2 + 5][x2 - 4] = id;d[y2 + 5][x2 - 3] = id;d[y2 + 5][x2 - 2] = id;d[y2 + 5][x2 - 1] = id;
	d[y2 + 5][x2 + 0] = id;d[y2 + 5][x2 + 1] = id;d[y2 + 5][x2 + 2] = id;d[y2 + 5][x2 + 3] = id;d[y2 + 5][x2 + 4] = id;d[y2 + 5][x2 + 5] = id;
	d[y2 + 5][x2 + 6] = id;d[y2 + 5][x2 + 7] = id;d[y2 + 5][x2 + 8] = id;d[y2 + 5][x2 + 9] = id;d[y2 + 5][x2 + 10] = id;d[y2 + 5][x2 + 11] = id;
	d[y2 + 6][x2 - 12] = id;d[y2 + 6][x2 + 9] = id;d[y2 + 7][x2 - 12] = id;d[y2 + 7][x2 + 9] = id;d[y2 + 8][x2 - 12] = id;d[y2 + 8][x2 + 9] = id;
	d[y2 + 9][x2 - 14] = id;d[y2 + 9][x2 - 13] = id;d[y2 + 9][x2 - 12] = id;d[y2 + 9][x2 + 9] = id;d[y2 + 9][x2 + 10] = id;d[y2 + 9][x2 + 11] = id;
	d[y2 + 10][x2 - 14] = id;d[y2 + 10][x2 - 13] = id;d[y2 + 10][x2 - 12] = id;d[y2 + 10][x2 + 9] = id;d[y2 + 10][x2 + 10] = id;d[y2 + 10][x2 + 11] = id;
	d[y2 + 11][x2 - 14] = id;d[y2 + 11][x2 - 13] = id;d[y2 + 11][x2 - 12] = id;d[y2 + 11][x2 - 11] = id;d[y2 + 11][x2 - 10] = id;d[y2 + 11][x2 - 9] = id;
	d[y2 + 11][x2 - 8] = id;d[y2 + 11][x2 - 7] = id;d[y2 + 11][x2 - 6] = id;d[y2 + 11][x2 - 5] = id;d[y2 + 11][x2 - 4] = id;d[y2 + 11][x2 - 3] = id;
	d[y2 + 11][x2 - 2] = id;d[y2 + 11][x2 - 1] = id;d[y2 + 11][x2 + 0] = id;d[y2 + 11][x2 + 1] = id;d[y2 + 11][x2 + 2] = id;d[y2 + 11][x2 + 3] = id;
	d[y2 + 11][x2 + 4] = id;d[y2 + 11][x2 + 5] = id;d[y2 + 11][x2 + 6] = id;d[y2 + 11][x2 + 7] = id;d[y2 + 11][x2 + 8] = id;d[y2 + 11][x2 + 9] = id;
	d[y2 + 11][x2 + 10] = id;d[y2 + 11][x2 + 11] = id;d[y2 + 12][x2 - 19] = id;d[y2 + 12][x2 - 18] = id;d[y2 + 12][x2 - 17] = id;d[y2 + 12][x2 - 16] = id;
	d[y2 + 12][x2 - 15] = id;d[y2 + 12][x2 - 14] = id;d[y2 + 12][x2 + 11] = id;d[y2 + 12][x2 + 12] = id;d[y2 + 12][x2 + 13] = id;d[y2 + 12][x2 + 14] = id;
	d[y2 + 12][x2 + 15] = id;d[y2 + 12][x2 + 16] = id;d[y2 + 13][x2 - 19] = id;d[y2 + 13][x2 - 18] = id;d[y2 + 13][x2 - 17] = id;d[y2 + 13][x2 - 16] = id;
	d[y2 + 13][x2 + 13] = id;d[y2 + 13][x2 + 14] = id;d[y2 + 13][x2 + 15] = id;d[y2 + 13][x2 + 16] = id;d[y2 + 14][x2 - 19] = id;d[y2 + 14][x2 - 18] = id;
	d[y2 + 14][x2 + 15] = id;d[y2 + 14][x2 + 16] = id;d[y2 + 15][x2 - 19] = id;d[y2 + 15][x2 + 16] = id;d[y2 + 16][x2 - 45] = id;d[y2 + 16][x2 - 44] = id;
	d[y2 + 16][x2 - 43] = id;d[y2 + 16][x2 - 42] = id;d[y2 + 16][x2 - 41] = id;d[y2 + 16][x2 - 40] = id;d[y2 + 16][x2 - 39] = id;d[y2 + 16][x2 - 38] = id;
	d[y2 + 16][x2 - 37] = id;d[y2 + 16][x2 - 36] = id;d[y2 + 16][x2 - 35] = id;d[y2 + 16][x2 - 34] = id;d[y2 + 16][x2 - 33] = id;d[y2 + 16][x2 - 32] = id;
	d[y2 + 16][x2 - 31] = id;d[y2 + 16][x2 - 30] = id;d[y2 + 16][x2 - 29] = id;d[y2 + 16][x2 - 28] = id;d[y2 + 16][x2 - 27] = id;d[y2 + 16][x2 - 26] = id;
	d[y2 + 16][x2 - 25] = id;d[y2 + 16][x2 - 24] = id;d[y2 + 16][x2 - 23] = id;d[y2 + 16][x2 - 22] = id;d[y2 + 16][x2 - 21] = id;d[y2 + 16][x2 - 20] = id;
	d[y2 + 16][x2 - 19] = id;d[y2 + 16][x2 + 16] = id;d[y2 + 16][x2 + 17] = id;d[y2 + 16][x2 + 18] = id;d[y2 + 16][x2 + 19] = id;d[y2 + 16][x2 + 20] = id;
	d[y2 + 16][x2 + 21] = id;d[y2 + 16][x2 + 22] = id;d[y2 + 16][x2 + 23] = id;d[y2 + 16][x2 + 24] = id;d[y2 + 16][x2 + 25] = id;d[y2 + 16][x2 + 26] = id;
	d[y2 + 16][x2 + 27] = id;d[y2 + 16][x2 + 28] = id;d[y2 + 16][x2 + 29] = id;d[y2 + 16][x2 + 30] = id;d[y2 + 16][x2 + 31] = id;d[y2 + 16][x2 + 32] = id;
	d[y2 + 16][x2 + 33] = id;d[y2 + 16][x2 + 34] = id;d[y2 + 16][x2 + 35] = id;d[y2 + 16][x2 + 36] = id;d[y2 + 16][x2 + 37] = id;d[y2 + 16][x2 + 38] = id;
	d[y2 + 16][x2 + 39] = id;d[y2 + 16][x2 + 40] = id;d[y2 + 16][x2 + 41] = id;d[y2 + 16][x2 + 42] = id;d[y2 + 16][x2 + 43] = id;d[y2 + 16][x2 + 44] = id;
	d[y2 + 16][x2 + 45] = id;d[y2 + 16][x2 + 46] = id;d[y2 + 16][x2 + 47] = id;d[y2 + 17][x2 - 47] = id;d[y2 + 17][x2 - 46] = id;d[y2 + 17][x2 - 45] = id;
	d[y2 + 17][x2 - 19] = id;d[y2 + 17][x2 + 16] = id;d[y2 + 17][x2 + 47] = id;d[y2 + 17][x2 + 48] = id;d[y2 + 17][x2 + 49] = id;d[y2 + 18][x2 - 47] = id;
	d[y2 + 18][x2 - 46] = id;d[y2 + 18][x2 - 19] = id;d[y2 + 18][x2 + 16] = id;d[y2 + 18][x2 + 49] = id;d[y2 + 18][x2 + 50] = id;d[y2 + 19][x2 - 47] = id;
	d[y2 + 19][x2 - 23] = id;d[y2 + 19][x2 - 22] = id;d[y2 + 19][x2 - 21] = id;d[y2 + 19][x2 - 20] = id;d[y2 + 19][x2 - 19] = id;d[y2 + 19][x2 - 18] = id;
	d[y2 + 19][x2 - 17] = id;d[y2 + 19][x2 - 16] = id;d[y2 + 19][x2 - 15] = id;d[y2 + 19][x2 - 14] = id;d[y2 + 19][x2 - 13] = id;d[y2 + 19][x2 - 12] = id;
	d[y2 + 19][x2 - 11] = id;d[y2 + 19][x2 - 10] = id;d[y2 + 19][x2 - 9] = id;d[y2 + 19][x2 - 8] = id;d[y2 + 19][x2 - 7] = id;d[y2 + 19][x2 - 6] = id;
	d[y2 + 19][x2 - 5] = id;d[y2 + 19][x2 - 4] = id;d[y2 + 19][x2 - 3] = id;d[y2 + 19][x2 - 2] = id;d[y2 + 19][x2 - 1] = id;d[y2 + 19][x2 + 0] = id;
	d[y2 + 19][x2 + 1] = id;d[y2 + 19][x2 + 2] = id;d[y2 + 19][x2 + 3] = id;d[y2 + 19][x2 + 4] = id;d[y2 + 19][x2 + 5] = id;d[y2 + 19][x2 + 6] = id;
	d[y2 + 19][x2 + 7] = id;d[y2 + 19][x2 + 8] = id;d[y2 + 19][x2 + 9] = id;d[y2 + 19][x2 + 10] = id;d[y2 + 19][x2 + 11] = id;d[y2 + 19][x2 + 12] = id;
	d[y2 + 19][x2 + 13] = id;d[y2 + 19][x2 + 14] = id;d[y2 + 19][x2 + 15] = id;d[y2 + 19][x2 + 16] = id;d[y2 + 19][x2 + 17] = id;d[y2 + 19][x2 + 18] = id;
	d[y2 + 19][x2 + 19] = id;d[y2 + 19][x2 + 50] = id;d[y2 + 20][x2 - 47] = id;d[y2 + 20][x2 - 23] = id;d[y2 + 20][x2 + 18] = id;d[y2 + 20][x2 + 19] = id;
	d[y2 + 20][x2 + 50] = id;d[y2 + 21][x2 - 47] = id;d[y2 + 21][x2 - 23] = id;d[y2 + 21][x2 + 19] = id;d[y2 + 21][x2 + 50] = id;d[y2 + 22][x2 - 47] = id;
	d[y2 + 22][x2 - 23] = id;d[y2 + 22][x2 + 19] = id;d[y2 + 22][x2 + 50] = id;d[y2 + 23][x2 - 47] = id;d[y2 + 23][x2 - 23] = id;d[y2 + 23][x2 + 19] = id;
	d[y2 + 23][x2 + 50] = id;d[y2 + 24][x2 - 47] = id;d[y2 + 24][x2 - 23] = id;d[y2 + 24][x2 + 19] = id;d[y2 + 24][x2 + 50] = id;d[y2 + 25][x2 - 47] = id;
	d[y2 + 25][x2 - 23] = id;d[y2 + 25][x2 + 19] = id;d[y2 + 25][x2 + 50] = id;d[y2 + 26][x2 - 47] = id;d[y2 + 26][x2 - 23] = id;d[y2 + 26][x2 + 19] = id;
	d[y2 + 26][x2 + 50] = id;d[y2 + 27][x2 - 47] = id;d[y2 + 27][x2 - 26] = id;d[y2 + 27][x2 - 25] = id;d[y2 + 27][x2 - 24] = id;d[y2 + 27][x2 - 23] = id;
	d[y2 + 27][x2 - 22] = id;d[y2 + 27][x2 - 21] = id;d[y2 + 27][x2 - 20] = id;d[y2 + 27][x2 - 19] = id;d[y2 + 27][x2 - 18] = id;d[y2 + 27][x2 - 17] = id;
	d[y2 + 27][x2 + 15] = id;d[y2 + 27][x2 + 16] = id;d[y2 + 27][x2 + 17] = id;d[y2 + 27][x2 + 18] = id;d[y2 + 27][x2 + 19] = id;d[y2 + 27][x2 + 20] = id;
	d[y2 + 27][x2 + 21] = id;d[y2 + 27][x2 + 22] = id;d[y2 + 27][x2 + 23] = id;d[y2 + 27][x2 + 50] = id;d[y2 + 28][x2 - 47] = id;d[y2 + 28][x2 - 46] = id;
	d[y2 + 28][x2 - 45] = id;d[y2 + 28][x2 - 44] = id;d[y2 + 28][x2 - 43] = id;d[y2 + 28][x2 - 42] = id;d[y2 + 28][x2 - 41] = id;d[y2 + 28][x2 - 40] = id;
	d[y2 + 28][x2 - 39] = id;d[y2 + 28][x2 - 38] = id;d[y2 + 28][x2 - 37] = id;d[y2 + 28][x2 - 36] = id;d[y2 + 28][x2 - 35] = id;d[y2 + 28][x2 - 34] = id;
	d[y2 + 28][x2 - 33] = id;d[y2 + 28][x2 - 32] = id;d[y2 + 28][x2 - 31] = id;d[y2 + 28][x2 - 30] = id;d[y2 + 28][x2 - 29] = id;d[y2 + 28][x2 - 28] = id;
	d[y2 + 28][x2 - 27] = id;d[y2 + 28][x2 - 26] = id;d[y2 + 28][x2 - 25] = id;d[y2 + 28][x2 - 24] = id;d[y2 + 28][x2 - 23] = id;d[y2 + 28][x2 - 22] = id;
	d[y2 + 28][x2 - 21] = id;d[y2 + 28][x2 - 20] = id;d[y2 + 28][x2 - 19] = id;d[y2 + 28][x2 - 18] = id;d[y2 + 28][x2 - 17] = id;d[y2 + 28][x2 - 16] = id;
	d[y2 + 28][x2 - 15] = id;d[y2 + 28][x2 - 14] = id;d[y2 + 28][x2 - 13] = id;d[y2 + 28][x2 - 12] = id;d[y2 + 28][x2 - 11] = id;d[y2 + 28][x2 - 10] = id;
	d[y2 + 28][x2 - 9] = id;d[y2 + 28][x2 - 8] = id;d[y2 + 28][x2 - 7] = id;d[y2 + 28][x2 - 6] = id;d[y2 + 28][x2 - 5] = id;d[y2 + 28][x2 - 4] = id;
	d[y2 + 28][x2 - 3] = id;d[y2 + 28][x2 - 2] = id;d[y2 + 28][x2 - 1] = id;d[y2 + 28][x2 + 0] = id;d[y2 + 28][x2 + 1] = id;d[y2 + 28][x2 + 2] = id;
	d[y2 + 28][x2 + 3] = id;d[y2 + 28][x2 + 4] = id;d[y2 + 28][x2 + 5] = id;d[y2 + 28][x2 + 6] = id;d[y2 + 28][x2 + 7] = id;d[y2 + 28][x2 + 8] = id;
	d[y2 + 28][x2 + 9] = id;d[y2 + 28][x2 + 10] = id;d[y2 + 28][x2 + 11] = id;d[y2 + 28][x2 + 12] = id;d[y2 + 28][x2 + 13] = id;d[y2 + 28][x2 + 14] = id;
	d[y2 + 28][x2 + 15] = id;d[y2 + 28][x2 + 16] = id;d[y2 + 28][x2 + 17] = id;d[y2 + 28][x2 + 18] = id;d[y2 + 28][x2 + 19] = id;d[y2 + 28][x2 + 20] = id;
	d[y2 + 28][x2 + 21] = id;d[y2 + 28][x2 + 22] = id;d[y2 + 28][x2 + 23] = id;d[y2 + 28][x2 + 24] = id;d[y2 + 28][x2 + 25] = id;d[y2 + 28][x2 + 26] = id;
	d[y2 + 28][x2 + 27] = id;d[y2 + 28][x2 + 28] = id;d[y2 + 28][x2 + 29] = id;d[y2 + 28][x2 + 30] = id;d[y2 + 28][x2 + 31] = id;d[y2 + 28][x2 + 32] = id;
	d[y2 + 28][x2 + 33] = id;d[y2 + 28][x2 + 34] = id;d[y2 + 28][x2 + 35] = id;d[y2 + 28][x2 + 36] = id;d[y2 + 28][x2 + 37] = id;d[y2 + 28][x2 + 38] = id;
	d[y2 + 28][x2 + 39] = id;d[y2 + 28][x2 + 40] = id;d[y2 + 28][x2 + 41] = id;d[y2 + 28][x2 + 42] = id;d[y2 + 28][x2 + 43] = id;d[y2 + 28][x2 + 44] = id;
	d[y2 + 28][x2 + 45] = id;d[y2 + 28][x2 + 46] = id;d[y2 + 28][x2 + 47] = id;d[y2 + 28][x2 + 48] = id;d[y2 + 28][x2 + 49] = id;d[y2 + 28][x2 + 50] = id;
}

void house(int x2, int y2) {//宽68
	int id = 15, a, b, c, y1, x1;
	x2 = x2 + 30 + 30;y2 = 600 - y2;
	//屋顶高11
	c = 68;
	for (b = 0;b < 12;b++)
	{
		for (a = ((c - b * 6) / 2);a < 69 - ((c - b * 6) / 2);a++)
		{
			d[y2 + b][x2 + a] = 台;
		}
	}
	for (b = 11;b < 28;b++)

		for (a = 0;a < 68;a++)
			if (b < 27) { if (a == 0 || a == 67) d[y2 + b][x2 + a] = 背景; }
			else d[y2 + b][x2 + a] = 背景;
	for (b = 13;b < 19;b++)
	{
		for (a = 6;a < 22;a++)
		{
			if (b == 13 || b == 18) { d[y2 + b][x2 + a] = 背景; }
			else if (a == 6 || a == 21)d[y2 + b][x2 + a] = 背景;
			if (b == 14 && (a == 9)) d[y2 + b][x2 + a] = 背景;
			else if (b == 15 && (a == 9 || a == 8 || a == 20 || a == 19))d[y2 + b][x2 + a] = 背景;
			else if (b == 16 && (a == 7 || a == 8 || a == 18 || a == 19 || a == 17))d[y2 + b][x2 + a] = 背景;
			else if (b == 17 && (a == 17 || a == 18))d[y2 + b][x2 + a] = 背景;
		}
	}
	for (b = 13;b < 19;b++)
	{
		for (a = 46;a < 62;a++) {
			if (b == 13 || b == 18) { d[y2 + b][x2 + a] = 背景; }
			else if (a == 46 || a == 61)d[y2 + b][x2 + a] = 背景;
			if (b == 14 && (a == 49)) d[y2 + b][x2 + a] = 背景;
			else if (b == 15 && (a == 49 || a == 48 || a == 60 || a == 59))d[y2 + b][x2 + a] = 背景;
			else if (b == 16 && (a == 47 || a == 48 || a == 58 || a == 59 || a == 17))d[y2 + b][x2 + a] = 背景;
			else if (b == 17 && (a == 57 || a == 58))d[y2 + b][x2 + a] = 背景;
		}
	}
	x1 = x2 + 30;
	y1 = y2 + b + 8;
	for (a = 0;a < 10;a++)
		d[y1][x1 + a] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;

	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	d[y1][x1 + 3] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	for (a = 0;a < 10;a++)
		d[y1][x1 + a] = 前门;
}

void doorr(int x1, int y1)
{
	x1 = x1 + 30 + 30;
	y1 = 600 - y1;
	d[y1][x1 + 1] = 右门;
	d[y1][x1] = 右门;
	d[y1][x1 - 1] = 右门;
	y1--;
	d[y1][x1] = 右门;d[y1][x1 + 1] = 右门;
	y1--;
	d[y1][x1] = 右门;d[y1][x1 + 1] = 右门;
	y1--;
	d[y1][x1] = 右门;d[y1][x1 + 1] = 右门;
	y1--;
	d[y1][x1] = 右门;d[y1][x1 - 1] = 右门;
	y1--;
	d[y1][x1] = 右门;d[y1][x1 + 1] = 右门;
	y1--;
	d[y1][x1] = 右门;d[y1][x1 + 1] = 右门;
	y1--;
	d[y1][x1] = 右门;d[y1][x1 + 1] = 右门;
	y1--;
	d[y1][x1] = 右门;
	d[y1][x1 + 1] = 右门;
	d[y1][x1 - 1] = 右门;


}

void doorl(int x1, int y1)
{
	x1 = x1 + 30 + 30;
	y1 = 600 - y1;
	d[y1][x1 + 1] = 左门;
	d[y1][x1] = 左门;
	d[y1][x1 - 1] = 左门;
	y1--;
	d[y1][x1] = 左门;;d[y1][x1 - 1] = 左门;
	y1--;
	d[y1][x1] = 左门;;d[y1][x1 - 1] = 左门;
	y1--;
	d[y1][x1] = 左门;;d[y1][x1 - 1] = 左门;
	y1--;
	d[y1][x1] = 左门;;d[y1][x1 + 1] = 左门;
	y1--;
	d[y1][x1] = 左门;;d[y1][x1 - 1] = 左门;
	y1--;
	d[y1][x1] = 左门;;d[y1][x1 - 1] = 左门;
	y1--;
	d[y1][x1] = 左门;;d[y1][x1 - 1] = 左门;
	y1--;
	d[y1][x1] = 左门;
	d[y1][x1 + 1] = 左门;
	d[y1][x1 - 1] = 左门;


}

void doorf(int x1, int y1) {
	int a, b;
	x1 = x1 + 30 + 30;
	y1 = 600 - y1;
	for (a = 0;a < 10;a++)
		d[y1][x1 + a] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;

	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	d[y1][x1 + 3] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	y1--;
	d[y1][x1] = 前门;
	d[y1][x1 + 9] = 前门;
	for (a = 0;a < 10;a++)
		d[y1][x1 + a] = 前门;


}

void doorb(int x1, int y1) {
	int a, b;
	x1 = x1 + 30 + 30;
	y1 = 600 - y1;
	for (a = 0;a < 10;a++)
		d[y1][x1 + a] = 后门;
	y1--;
	d[y1][x1] = 后门;
	d[y1][x1 + 9] = 后门;
	y1--;
	d[y1][x1] = 后门;
	d[y1][x1 + 9] = 后门;
	y1--;
	d[y1][x1] = 后门;
	d[y1][x1 + 9] = 后门;

	y1--;
	d[y1][x1] = 后门;
	d[y1][x1 + 9] = 后门;
	d[y1][x1 + 6] = 后门;
	y1--;
	d[y1][x1] = 后门;
	d[y1][x1 + 9] = 后门;
	y1--;
	d[y1][x1] = 后门;
	d[y1][x1 + 9] = 后门;
	y1--;
	d[y1][x1] = 后门;
	d[y1][x1 + 9] = 后门;
	y1--;
	d[y1][x1] = 后门;
	d[y1][x1 + 9] = 后门;
	for (a = 0;a < 10;a++)
		d[y1][x1 + a] = 后门;
}

void juxing(int x1, int l1, int y1, int l2)
{
	x1 = x1 + 30 + 30;
	int f2, f1, c = l1;

	y1 = 600 - y1;
	for (f2 = y1;y1 + l2 - f2; f2++)
	{
		for (f1 = x1;x1 + l1 - f1; f1++)
		{

			d[f2][f1] = 台;
		}
	}
}

void wall(int x1, int l1, int y1, int l2)
{
	x1 = x1 + 30 + 30;
	int f2, f1, c = l1;
	y1 = 600 - y1;
	for (f2 = y1;y1 + l2 - f2; f2++)
	{
		for (f1 = x1;x1 + l1 - f1; f1++)
		{
			d[f2][f1] = 墙;

		}
	}
}

void mission(int x1, int l1, int y1)
{
	x1 = x1 + 30 + 30;
	int f2, f1, c = l1;
	y1 = 600 - y1;
	if ((x1 + l1) > 220)l1 = 220 - x1;
}
void computergraphics(int e)
{
	switch (e) 
	{
	case 1:

		
		break;
	
	}
}

void BOX(int x1, int y1, int e)
{
	if (box[room] == 0) {
		x1 = x1 + 30 + 30;
		int a = 0, b = 0;
		if (e == 0)
		{
			y1 = 600 - y1;

			d[y1][x1] = 箱;
			d[y1][x1 + 1] = 箱;
			d[y1][x1 + 2] = 箱;
			d[y1][x1 - 1] = 箱;
			d[y1][x1 - 2] = 箱;
			d[y1][x1 + 3] = 箱;
			d[y1][x1 - 3] = 箱;
			y1--;
			d[y1][x1] = 箱;

			d[y1][x1 + 2] = 箱;

			d[y1][x1 - 2] = 箱;
			d[y1][x1 + 3] = 箱;
			d[y1][x1 - 3] = 箱;
			y1--;
			d[y1][x1] = 箱;
			d[y1][x1 + 1] = 箱;
			d[y1][x1 + 2] = 箱;
			d[y1][x1 - 1] = 箱;
			d[y1][x1 - 2] = 箱;
			d[y1][x1 + 3] = 箱;
			d[y1][x1 - 3] = 箱;
			y1--;
			d[y1][x1] = 箱;
			d[y1][x1 + 1] = 箱;
			d[y1][x1 - 1] = 箱;
		}

		else {
			printf("\n\n\n\n\n\n");
			switch (room)
			{
			case 0: printf("\n\n\n                                                     获得 尚方EX龟速宝剑-----按住j键使用（按空格继续游戏）");break;
			case 1: printf("\n\n\n                                                     获得 100金币（按空格继续游戏）                       ");m1 += 50;break;
				/*case 1: printf("\n\n\n                                                     获得 %s（按回车继续游戏）");break;
				case 1: printf("\n\n\n                                                     获得 %s（按回车继续游戏）");break;
				case 1: printf("\n\n\n                                                     获得 %s（按回车继续游戏）");break;
				case 1: printf("\n\n\n                                                     获得 %s（按回车继续游戏）");break;
				case 1: printf("\n\n\n                                                     获得 %s（按回车继续游戏）");break;
				case 1: printf("\n\n\n                                                     获得 %s（按回车继续游戏）");break;
				*/
			}


			for (a = 5;a < 12;a++)
			{
				for (b = 0;b < 8;b++)
				{
					if (d[y + a][x + b] == 箱)d[y + a][x + b] = 空;//搜索箱子
				}
				for (;b > 0;b--)
				{
					if (d[y + a][x - b] == 箱) { d[y + a][x - b] = 空; }//将用过的箱子图形去除
				}
				box[room] = 已探索;
			}

			一直循环
			{
				延迟(40);
				if (GetKeyState(32) < 0) { break; }//a

			}system("cls");
		}
	}

}

void 人物操作(int ha)
{
	if (ha) { ax = 0;V1 = 0;V2 = 0; }
	else {
		A键按下{ ax = 0; ax = ax - 4;if (ax <= -12)ax = -12;if (V1 > 0)V1/=2;con = -1;if (act1 == 0)act1 = 1; }//a
		D键按下{ ax = 0;ax = ax + 4;if (ax >= 12)ax = 12;if (V1 < 0)V1/=2; con = 1;if (act1 == 0)act1 = 1; }//d
		W键按下{ if (f == 1 && room != 10000)y = y - 8; }//w
		J键按下{ keyhit[74] = 1;if (act1 == 0)act1 = 1;if (act3 < 3)ax = 0;act3++;if (act3 > 190)act3 = 0; }//j
						else {
						if (act1 == 7)act1 = 1;
						if (keyhit[74] > 0)
						{


							/*蓄力剑伤害结算函数*/
							for (a = 20;a < 1000;a++)
							{
								if (dhurt[a] > 0)
								{
									switch (dhurt[a])
									{
									case 1:dhurt[a] = 0;
										for (c = 0;c < 2 * bladehurt;c++) //bladehurt蓄力剑攻击伤害
										{
											if (i[a] > 1) { i[a]--; nice[a] = -1; }
											else break;
										}break;
									}
								}
							}
							/*蓄力剑伤害结算函数*/



							keyhit[74] = 0;
							if (act3 < 5)
							{
								act3 = 150;

							}
						}
						else act3 = 0;
						}
						S键按下{ if (act1 == 0)act1 = 1;keyhit[83] = 1;V1 = 0;V2 = 0;ax = 0;
						}
						else { if (f == 1 && keyhit[83] == 1) { keyhit[83] = 0; sit = 1; } }//s
						K键按下{ keyhit[75] = 1;keyhit[75] = 0;shootgun = 1;ax = 0;ay = 0;V1 = 0;V2 = 0; }
						else if (keyhit[75] > 0) { keyhit[75] = 0;shootgun = 0; }//k

	}
	if (act1 == 7) { ax = 0;V1 = 0; }//当动作是蓄力斩时，主角无法移动
}

/*if (_kbhit()){
						act1 = 1;switch (_getch()) {
						case'a': {if (act2 == 0 && V2 > -2)x--;if (d[y + 4][x - 3] == 3 || d[y + 8][x - 3] == 3 || d[y + 8][x - 2] == 3)x++; ax = 0; ax = ax - 6;if (ax <= -12)ax = -12;con = -1;act3 = 0;break;}
						case'd': { if (act2 == 0 && V2 < 2)x++;if (d[y + 4][x + 3] == 3 || d[y + 8][x + 3] == 3 || d[y + 8][x + 2] == 3)x--;ax = 0;ax = ax + 6;if (ax >= 12)ax = 12; con = 1;act3 = 0;break;}
						case's':if (f == 1) { V1 = 0;V2 = 0;ax = 0;sit = 1;break; }
						case'w': { if (f == 1 && room != 10000)y = y - 8; }break;
						case'j': { ax = 0;act3++;break;}
						case'1': meun = 1;break;
						case'2':meun = 2;break;
						case'3':meun = 3;break;
						case'4':meun = 4;break;
						case'5':meun = 5;break;
						case'6':meun = 6;break;
						case'7':meun = 7;break;
						case'8':meun = 8;break;
						case'9':meun = 9;break;
						case'0':meun = 0;break;
						case'x':y = 0;break;
						case'\n':meun = '*';break;
						case'k':shootgun = 1;ax = 0;ay = 0;V1 = 0;V2 = 0;break;
						case 0x1b:table = 1;goto contable;break;

						}
					}
					else { act1 = 0;ax = 0;act3 = 0;sit = 0;meun = 168; }*/

void 切图后重置{
	mop[room] = 0;//每次返回任务重置数据点
			down = 0;//下屏刷新初始化
			talktime = 0;
			trad = 0;
			hdso = 0;
			vill = 0;
			j2 = j4;
			//****************
			//*切图后重置怪物*
			//****************
			for (b = 1;b < 60;b++)
				for (a = 0;a < 100;a++)
				{
					if (monst[b][a] > 0)
					{
						monst[b][a] = 0;
					}
					if (die[a] == 1)die[a] = 2;
				}
			//****************
			//*切图后重置怪物*
			//****************

			//******
			//*清屏*
			//******
			for (a = 0;a < 1000;a++)
				for (b = 0;b < 5000;b++)
				{
					d[a][b] = 0;
				}
			//******
			//*清屏*
			//******
			talktime = 0;
			dieword = 0;



			o2 = 0;//每次场景更换后对话刷新的标志
			talk = 0;//更换场景后面板刷新
			//任务，场景
}

void stcard(int xs, int ys, int large, int agree, int id)
{
	int a, b, magic, attack, live;

	switch (id)
	{
	case 1: magic = 4;live = 5;attack = 3;break;

	}

	if (agree == 0)
	{
		if (large == 0)
		{
			for (a = 0;a < 12;a++)
			{
				st[ys - 6][xs - 6 + a] = '+';
				st[ys + 6][xs - 6 + a] = '+';
				for (b = 0;b < 11;b++)
					st[ys - 5 + b][xs - 6 + a] = 0;
			}
			for (b = 0;b < 13;b++)
			{
				st[ys - 6 + b][xs + 6] = '+';
				st[ys - 6 + b][xs - 6] = '+';
			}
			st[ys - 4][xs - 4] = magic;
			st[ys + 4][xs + 4] = live;
			st[ys + 4][xs - 4] = attack;
		}
		else
		{
			for (a = 0;a < 20;a++)
			{
				st[ys - 8][xs - 10 + a] = '+';
				st[ys + 8][xs - 10 + a] = '+';
				for (b = 0;b < 14;b++)
					st[ys - 7 + b][xs - 10 + a] = 0;
			}
			for (b = 0;b < 16;b++)
			{
				st[ys - 8 + b][xs + 10] = '+';
				st[ys - 8 + b][xs - 10] = '+';
			}
			st[ys - 6][xs - 6] = magic;
			st[ys + 6][xs + 6] = live;
			st[ys + 6][xs - 6] = attack;
		}
	}
	else
	{
		if (large == 0)
		{
			for (a = 0;a < 12;a++)
			{
				st[ys - 6][xs - 6 + a] = '+';
				st[ys + 6][xs - 6 + a] = '+';
				for (b = 0;b < 11;b++)
					st[ys - 5 + b][xs - 6 + a] = '0';
			}
			for (b = 0;b < 13;b++)
			{
				st[ys - 6 + b][xs + 6] = '+';
				st[ys - 6 + b][xs - 6] = '+';
			}
		}
		else {}
	}
}

void instickword() {
	if (dieword > 0)
	{
		if (dieword == 24)
		{
			talktime++;
			printf("#######################################################################################################################################################################\n");

			if (talktime > 0)
			{
				printf("                                 年轻人。。。。。（大喘气）                                                           \n");
				nice[24] = 0;
			}//
			if (talktime > 5 * 12) {
				printf("                                 我承认你很厉害                                                           \n");
				nice[24] = 0;
			}//
			if (talktime > 10 * 12)printf("                                 做人留一线，事后好相见                                                           \n");//printf("\n");得饶人处且饶人啊
			if (talktime > 15 * 12)printf("                                 得饶人处且饶人啊                                                           \n");//printf("\n");
			printf("#######################################################################################################################################################################\n");
			if (talktime > 20 * 12) { talktime = 0;dieword = 0;system("cls"); }

		}
		if (dieword == 9000)
		{
			talktime++;
			printf("#######################################################################################################################################################################\n");

			if (talktime > 0)
			{
				printf("                                 md你打我干蛤？！                                                           \n");
				printf("#######################################################################################################################################################################\n");
			}//



			if (talktime > 20 * 12) { talktime = 0;dieword = 0;system("cls"); }

		}

	}
}

void tachi()
{
	int a, b;
	//结界
	if (tacx < 6)tacx = 7;
	if (tacx > 14)tacx = 13;
	if (tacy < 3)tacy = 4;
	if (tacy > 30)tacy = 29;
	//结界
		//建模
	switch (age)
	{
	case 0:
		tac[tacy][tacx] = '-';tac[tacy][tacx + 1] = '+';tac[tacy][tacx - 1] = '+';
		tac[tacy + 1][tacx] = '-';tac[tacy + 1][tacx + 1] = '+';tac[tacy + 1][tacx - 1] = '+';
		break;

	case 1:
		tac[tacy][tacx] = '^';tac[tacy][tacx + 1] = '~';
		tac[tacy][tacx - 1] = '~';tac[tacy][tacx + 2] = '/';tac[tacy][tacx - 2] = '\\';
		tac[tacy + 1][tacx + 1] = '^';tac[tacy + 1][tacx - 1] = '^';

		break;
	}

}

int talkf(int a, int b)//第一个数是起点第二个是终点 
{
	unsigned int c, e = 0;
	if (talktime > (b - a) * 20 + 1) talktime = (b - a) * 20 + 1;
	else talktime++;

	c = talktime / 20;
	while (c > 5) { a += 5;c -= 5; }
	if (b >= a + c) {
		b = a + c;
		for (;b >= a;a++) {
			printf(
				"                                 %s                                                      \n", talkmood[a]);
		}

		for (a = 5;a - c > e;e++)
			printf("                                                                                                                                 \n");
	}
}

void pad(int x1, int y1, int xd2, int yd2, int xb3, int yb3, int e) {
	//************************
	//*x1,y1为按钮坐标       *
	//*xd2,yd2为可动门坐标   *
	//*xb3,yb3为箱子初始坐标 *
	//************************
	if (boxid[e] == 0) { xb3 += 60;yb3 = 600 - yb3;boxid[e] = 1;xbox[e] = xb3;ybox[e] = yb3; }
	unsigned int xb, yb, a, b, vb2;
	xb = xbox[e];yb = ybox[e];
	y1 = 600 - y1;x1 = x1 + 30 + 30;yd2 = 600 - yd2;xd2 += 60;
	if (d[yb + 5][xb] != 2 && d[yb + 5][xb + 1] != 2 && d[yb + 5][xb - 1] != 2)
	{

		if (ab[e] <= 2) { ab[e] += 0.5; }
		if (vb[e] < 8)vb[e] = vb[e] + ab[e];
		vb2 = vb[e];

		for (a = 0;a < vb2;a++)//下落检测
		{
			ybox[e]++;
			if (d[ybox[e] + 5][xb] == 2 || d[ybox[e] + 5][xb + 1] == 2 || d[ybox[e] + 5][xb - 1] == 3|| d[ybox[e] + 5][xb] == 3 || d[ybox[e] + 5][xb + 1] == 3 || d[ybox[e] + 5][xb - 1] == 3)
			{
				ab[e] = 0;vb[e] = 0;vb2 = 0;break;
			}
		}





	}

	if ((y1 - ybox[e] == 4) && ((xbox[e] < x1 &&x1 - xbox[e] < 10) || (xbox[e] < x1 &&xbox[e] - x1 < 5)))ybox[e]--;
	//如果箱子碰到按钮


	if ((ybox[e] > y&& ybox[e] - y <= 8) || (y > ybox[e] && y - ybox[e] < 4))//如果人碰到箱子
	{
		if (d[ybox[e]][xbox[e] - 1] == 3 || d[ybox[e] + 4][xbox[e] - 1] == 3 || d[ybox[e]][xbox[e] + 10] == 3 || d[ybox[e] + 4][xbox[e] + 10] == 3)
		{
			if (d[ybox[e] + 1][xbox[e] - 1] == 1 && d[ybox[e] + 4][xbox[e] - 1] != 1 && ybox[e] - y > 4)xbox[e] += 2;
			if (d[ybox[e] + 1][xbox[e] + 10] == 1 && d[ybox[e] + 4][xbox[e] + 10] != 1 && ybox[e] - y > 4)xbox[e] -= 2;
		}//防止箱子出轨
		else
			if (x + 3 == xbox[e]) { if (con > 0)xbox[e]++; }
			else if (x - 12 == xbox[e]) { if (con < 0)xbox[e]--; }
			else if (x - 11 == xbox[e]) { if (con < 0)xbox[e] -= 2; }
			else if (x + 2 == xbox[e]) { if (con > 0)xbox[e] += 2; }
	}//如果人碰到箱子
	for (b = 0;b < 5;b++)
	{
		for (a = 0;a < 10;a++)
		{
			if (d[yb + b][xb + a] == 0)d[yb + b][xb + a] = 1;
		}//输出箱子图像
	}
	if ((d[y1 - 2][x1] != 0) || (d[y1 - 2][x1 + 2] != 0) || (d[y1 - 2][x1 + 4] != 0) || (d[y1 - 2][x1 + 1] != 0)) //如果按钮上有东西，触发机关
	{
		for (a = 0;a < 5;a++) { if (d[y1][x1 + a] == 0)d[y1][x1 + a] = 2; }//按钮的图形显示
		for (a = 1;a < 4;a++) { if (d[y1 - 1][x1 + a] == 2)d[y1 - 1][x1 + a] = 0; }//按钮的图形被按下
		d[yd2][xd2] = 0;
		d[yd2 - 1][xd2] = 0;
		d[yd2 - 2][xd2] = 0;d[yd2 - 2][xd2 + 1] = 0;d[yd2 - 2][xd2 - 1] = 0;
		d[yd2 - 3][xd2] = 0;
		d[yd2 - 4][xd2] = 0;d[yd2 - 4][xd2 + 1] = 0;d[yd2 - 4][xd2 - 1] = 0;
		d[yd2 - 5][xd2] = 0;
		d[yd2 - 6][xd2] = 0;d[yd2 - 6][xd2 + 1] = 0;d[yd2 - 6][xd2 - 1] = 0;
		d[yd2 - 7][xd2] = 0;
		d[yd2 - 8][xd2] = 0;d[yd2 - 8][xd2 + 1] = 0;d[yd2 - 8][xd2 - 1] = 0;
		d[yd2 - 9][xd2] = 0;
	}
	else {
		d[yd2][xd2] = 3;
		d[yd2 - 1][xd2] = 3;
		d[yd2 - 2][xd2] = 3;d[yd2 - 2][xd2 + 1] = 3;d[yd2 - 2][xd2 - 1] = 3;
		d[yd2 - 3][xd2] = 3;
		d[yd2 - 4][xd2] = 3;d[yd2 - 4][xd2 + 1] = 3;d[yd2 - 4][xd2 - 1] = 3;
		d[yd2 - 5][xd2] = 3;
		d[yd2 - 6][xd2] = 3;d[yd2 - 6][xd2 + 1] = 3;d[yd2 - 6][xd2 - 1] = 3;
		d[yd2 - 7][xd2] = 3;
		d[yd2 - 8][xd2] = 3;d[yd2 - 8][xd2 + 1] = 3;d[yd2 - 8][xd2 - 1] = 3;
		d[yd2 - 9][xd2] = 3;
		for (a = 0;a < 5;a++) { if (d[y1][x1 + a] == 0)d[y1][x1 + a] = 2; }//按钮的图形显示
		for (a = 1;a < 4;a++) { if (d[y1 - 1][x1 + a] == 0)d[y1 - 1][x1 + a] = 2; }//按钮的图形显示
	}






}

void dicr(int x1, int y1)
{
	x1 = x1 + 30 + 30;
	int a, b;
	y1 = 600 - y1;

	for (a = 0;a < 2;a++) { d[y1 - 3][x1 - a] = 背景; }
	for (a = 1;a < 5;a++) { d[y1 - 3][x1 + a] = 背景; }
	for (a = 0;a < 6;a++) { d[y1 - 4][x1 - a] = 背景; }
	for (a = 1;a < 6;a++) { d[y1 - 4][x1 + a] = 背景; }
	for (a = 1;a < 7;a++) { d[y1 - 5][x1 + a] = 背景; }
	for (a = 0;a < 6;a++) { d[y1 - 6][x1 - a] = 背景; }
	for (a = 1;a < 6;a++) { d[y1 - 6][x1 + a] = 背景; }
	for (a = 0;a < 2;a++) { d[y1 - 7][x1 - a] = 背景; }
	for (a = 1;a < 5;a++) { d[y1 - 7][x1 + a] = 背景; }
}

void chac(int l)
{
	int Ay;
	if (act1 < 5)
	{
		char Ay = 0;
		if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;
		if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;
		if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;
		Ay++;
		if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;
		if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;
		if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;
		Ay++;
		//2

		if (act1 == 1 || act1 == 0) { if (d[y + Ay][x] == 0)d[y + Ay][x] = 1; }

		else if (act1 == 3) { if (d[y + Ay][x + 4] == 0) d[y + Ay][x + 4] = 1;if (d[y + Ay][x] == 0)d[y + Ay][x] = 1; }

		else if (act1 == 4) {
			if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;
			if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;
		}
		Ay++;//3        if(d[y + Ay][x]==0)
		if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;
		if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;
		if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;
		if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;
		if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;

		if (act1 == 3)
		{
			if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;
			if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;
			if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;
			if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;
		}
		else     if (act1 == 4)
		{
			if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;
			if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;
			if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;
			if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;
		}
		Ay++;//4
		if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;
		if (act1 == 1 || act1 == 0) {
			if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;
			if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;
		}
		Ay++;//5
		if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;
		if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;
		if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;
		Ay++;//6

		if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;
		if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;
		Ay++;//6

		if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;
		if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;
		Ay++;//7

		if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;
		if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//8
	}
	if (act3 > 0) {
		acttime[1] = 8;

		if (act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++)//15

		{

			if (l == 1) {
				Ay = 1;//
				Ay++;//

				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//-3
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// -1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//}
			}
			else {
				Ay = 1;//
				Ay++;//

				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//-3
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// -1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;
			}
		}
		if (act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++)//19
		{
			act1 = 7;
			if (l == 1) {
				Ay = 1;//
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;//

				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//-3
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// -1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//}
			}
			else {
				Ay = 1;//
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;//

				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//-3
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// -1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//}
			}
		}
		if (act3 == acttime[1]++)//20
		{

			if (l == 1) {





				Ay = 1;
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//-5
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-5
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//-6
				if (d[y + Ay][x - 6] == 0)d[y + Ay][x - 6] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//-6
				if (d[y + Ay][x - 6] == 0)d[y + Ay][x - 6] = 1;//-7
				if (d[y + Ay][x - 7] == 0)d[y + Ay][x - 7] = 1;//
			}
			else {

				Ay = 1;//
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-5
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-5
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//-6
				if (d[y + Ay][x + 6] == 0)d[y + Ay][x + 6] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//-6
				if (d[y + Ay][x + 6] == 0)d[y + Ay][x + 6] = 1;//-7
				if (d[y + Ay][x + 7] == 0)d[y + Ay][x + 7] = 1;//
			}
		}
		if (act3 == acttime[1]++ || act3 == acttime[1]++)//22
		{

			if (l == 1) {

				Ay = 0;
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//5
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//5
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//6
				if (d[y + Ay][x + 6] == 0)d[y + Ay][x + 6] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//6
				if (d[y + Ay][x + 6] == 0)d[y + Ay][x + 6] = 1;//7
				if (d[y + Ay][x + 7] == 0)d[y + Ay][x + 7] = 1;//8
				if (d[y + Ay][x + 8] == 0)d[y + Ay][x + 8] = 1;//9
				if (d[y + Ay][x + 9] == 0)d[y + Ay][x + 9] = 1;//10
				if (d[y + Ay][x + 10] == 0)d[y + Ay][x + 10] = 1;//Ay++;
				Ay++;// -1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//9
				if (d[y + Ay][x + 9] == 0)d[y + Ay][x + 9] = 1;//10
				if (d[y + Ay][x + 10] == 0)d[y + Ay][x + 10] = 1;//11
				if (d[y + Ay][x + 11] == 0)d[y + Ay][x + 11] = 1;//Ay++;
				Ay++;// -2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//12
				if (d[y + Ay][x + 12] == 0)d[y + Ay][x + 12] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//
			}
			else {

				Ay = 0;
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//5
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//5
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//6
				if (d[y + Ay][x - 6] == 0)d[y + Ay][x - 6] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x - 2] = 1;//6
				if (d[y + Ay][x - 6] == 0)d[y + Ay][x - 6] = 1;//7
				if (d[y + Ay][x - 7] == 0)d[y + Ay][x - 7] = 1;//8
				if (d[y + Ay][x - 8] == 0)d[y + Ay][x - 8] = 1;//9
				if (d[y + Ay][x - 9] == 0)d[y + Ay][x - 9] = 1;//10
				if (d[y + Ay][x - 10] == 0)d[y + Ay][x - 10] = 1;//Ay++;
				Ay++;// -1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//9
				if (d[y + Ay][x - 9] == 0)d[y + Ay][x - 9] = 1;//10
				if (d[y + Ay][x - 10] == 0)d[y + Ay][x - 10] = 1;//11
				if (d[y + Ay][x - 11] == 0)d[y + Ay][x - 11] = 1;//Ay++;
				Ay++;// -2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//12
				if (d[y + Ay][x - 12] == 0)d[y + Ay][x - 12] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//
			}
		}
		if (act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++)//25
		{

			if (l == 1) {

				Ay = 0;
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//9
				if (d[y + Ay][x + 10] == 0)d[y + Ay][x + 10] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//8
				if (d[y + Ay][x + 8] == 0)d[y + Ay][x + 8] = 1;//7
				if (d[y + Ay][x + 7] == 0)d[y + Ay][x + 7] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//7
				if (d[y + Ay][x + 7] == 0)d[y + Ay][x + 7] = 1;//6
				if (d[y + Ay][x + 6] == 0)d[y + Ay][x + 6] = 1;//5
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//5
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//
			}
			else {

				Ay = 0;
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//9
				if (d[y + Ay][x - 10] == 0)d[y + Ay][x - 10] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//8
				if (d[y + Ay][x - 8] == 0)d[y + Ay][x - 8] = 1;//7
				if (d[y + Ay][x - 7] == 0)d[y + Ay][x - 7] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//7
				if (d[y + Ay][x - 7] == 0)d[y + Ay][x - 7] = 1;//6
				if (d[y + Ay][x - 6] == 0)d[y + Ay][x - 6] = 1;//5
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//5
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//
			}

		}
	}
}

void blade(int l)
{
	if (room != 10000)
	{
		int a, b, c = 0, e = 0, f = 0;
		char Ay = 0;
		//l就是con的局部变量

		if (cooldown[0] > 0)act3 = 0;
		if (act3 == 2 || act3 == 1)
		{
			if (l == 1 && d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;
			if (l == -1 && d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;
		}
		Ay++;
		//2

		if (act3 == 2 || act3 == 1||act3 == 3  )
		{
			if (l == 1 && d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;
			if (l == -1 && d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;
		}
		if (act3 == 150)
		{
			if (l == 1)
			{
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;
				if (d[y + Ay][x + 7] == 0)d[y + Ay][x + 7] = 1;
				if (d[y + Ay][x + 6] == 0)d[y + Ay][x + 6] = 1;
				if (d[y + Ay][x + 8] == 0)d[y + Ay][x + 8] = 1;
				if (d[y + Ay][x + 9] == 0)d[y + Ay][x + 9] = 1;
			}
			if (l == -1)
			{

				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;
				if (d[y + Ay][x - 7] == 0)d[y + Ay][x - 7] = 1;
				if (d[y + Ay][x - 6] == 0)d[y + Ay][x - 6] = 1;
				if (d[y + Ay][x - 8] == 0)d[y + Ay][x - 8] = 1;
				if (d[y + Ay][x - 9] == 0)d[y + Ay][x - 9] = 1;
			}
		}
		Ay++;
		//3        if(d[y + Ay][x]==0)

		if (act3 == 2 || act3 == 1 || act3 == 3)
		{
			if (l == 1 && d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;
			if (l == -1 && d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;
		}
		if (act3 == 150)
		{
			if (l == 1)
			{
				for (a = 6;a < 15;a++)
					if (d[y + Ay][x + a] == 0)d[y + Ay][x + a] = 1;


			}
			if (l == -1)
			{
				for (a = 6;a < 15;a++)
					if (d[y + Ay][x - a] == 0)d[y + Ay][x - a] = 1;


			}
		}


		Ay++;//4

		if (act3 == 2 || act3 == 1 || act3 == 3)
		{

			if (l == 1 && d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;
			if (l == -1 && d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;
		}

		if (act3 == 150)
		{
			if (l == 1)
			{
				for (a = 8;a < 17;a++)
					if (d[y + Ay][x + a] == 0)d[y + Ay][x + a] = 1;
				//if (d[y + Ay][x + 12] == 0)d[y + Ay][x + 12] = 1;

			}
			if (l == -1)
			{
				for (a = 8;a < 17;a++)
					if (d[y + Ay][x - a] == 0)d[y + Ay][x - a] = 1;
				//if (d[y + Ay][x - 12] == 0)d[y + Ay][x - 12] = 1;

			}
		}

		Ay++;//5
		if (act3 == 2 || act3 == 1 || act3 == 3)
		{
			if (l == 1)
			{
				if (d[y + Ay][x + 2] == 1)d[y + Ay][x + 2] = 0;
				if (d[y + Ay][x + 3] == 1)d[y + Ay][x + 3] = 1;
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;
			}
			if (l == -1)
			{
				if (d[y + Ay][x - 2] == 1)d[y + Ay][x - 2] = 0;
				if (d[y + Ay][x - 3] == 1)d[y + Ay][x - 3] = 1;
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;
			}
		}
		else if (act3 == 150)
		{


			if (l == 1)
			{
				for (a = 6;a < 15;a++)
					if (d[y + Ay][x + a] == 0)d[y + Ay][x + a] = 1;


			}
			if (l == -1)
			{
				for (a = 6;a < 15;a++)
					if (d[y + Ay][x - a] == 0)d[y + Ay][x - a] = 1;


			}

			Ay++;//6
			if (l == 1)
			{
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;
				if (d[y + Ay][x + 6] == 0)d[y + Ay][x + 6] = 1;
				if (d[y + Ay][x + 7] == 0)d[y + Ay][x + 7] = 1;
			}
			if (l == -1)
			{

				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;
				if (d[y + Ay][x - 6] == 0)d[y + Ay][x - 6] = 1;
				if (d[y + Ay][x - 7] == 0)d[y + Ay][x - 7] = 1;

			}

		}
		if (act3 == 150)//伤害判定
		{
			延迟(200);
			if (l == 1)//向右攻击
			{
				for (b = 2;b < 8;b++)//纵向范围
				{
					for (a = 0;a < 16;a++)//横向范围
					{
						if (d[y + b][x + a] > 19 && i[d[y + b][x + a]] != 0)
						{
							e = d[y + b][x + a];//判定只造成一次伤害
							for (c = 0;c < bladehurt;c++) //bladehurt蓄力剑攻击伤害
							{
								if (i[e] > 1) { i[e]--; nice[e] = -1; }
								else break;
							}goto stophurt;//造成伤害后跳出伤害判定
						}//伤害函数 i[d[y + b][x + a]]

					}
				}
			}
			if (l == -1)//向左攻击
			{
				for (b = 2;b < 8;b++)//纵向范围
				{
					for (a = 0;a < 16;a++)//横向范围
					{
						if (d[y + b][x - a] > 19 && i[d[y + b][x - a]] != 0)
						{
							e = d[y + b][x - a];//判定只造成一次伤害
							for (c = 0;c < bladehurt;c++)//bladehurt蓄力剑攻击伤害
							{
								if (i[e] > 1)
								{
									i[e]--;nice[e] = -1;
								}
								else break;
							}goto stophurt;//造成伤害后跳出伤害判定
						}
					}if (f != i[e])break;
				}//伤害函数 i[d[y - b][x - a]]
			}
		stophurt:;//停止伤害标志
		}
		if (act3 == 150)
		{
			act3 = 0;cooldown[0] = 8;
		}
		//平a结束
		acttime[1] = 8;
		if (act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++)//15
		{
			act1 = 7;
			if (l == 1) {
				Ay = 1;//
				Ay++;//

				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//-3
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// -1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//}
			}
			else {
				Ay = 1;//
				Ay++;//

				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//-3
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// -1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;
			}
		}
		if (act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++)//19
		{
			act1 = 7;
			if (l == 1) {
				Ay = 1;//
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;//

				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//-3
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// -1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//}
			}
			else {
				Ay = 1;//
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;//

				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//-3
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// -1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//}
			}
		}
		if (act3 == acttime[1]++)//20
		{
			act1 = 7;
			if (l == 1) {

				for (b = 0;b < 19;b++)
				{
					if (d[y][x + 3] == 3 || d[y + 2][x + 3] == 3 || d[y + 4][x + 3] == 3 || d[y + 8][x + 3] == 3)break;x++;
					for (a = -1;a < 9;a++)
					{
						if (d[y + a][x + 5] >= 20) { dhurt[d[y + a][x + 5]] = 1;break; }
					}//伤害判定
				}



				Ay = 1;
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//-5
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-5
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//-6
				if (d[y + Ay][x - 6] == 0)d[y + Ay][x - 6] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//-6
				if (d[y + Ay][x - 6] == 0)d[y + Ay][x - 6] = 1;//-7
				if (d[y + Ay][x - 7] == 0)d[y + Ay][x - 7] = 1;//
			}
			else {
				for (b = 0;b < 19;b++)
				{
					if (d[y][x - 3] == 3 || d[y + 2][x - 3] == 3 || d[y + 4][x - 3] == 3 || d[y + 8][x - 3] == 3)break;x--;
					for (a = -1;a < 9;a++)
					{
						if (d[y + a][x - 5] >= 20) { dhurt[d[y + a][x - 5]] = 1;break; }
					}//伤害判定
				}
				Ay = 1;//
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//-5
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-5
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//-6
				if (d[y + Ay][x + 6] == 0)d[y + Ay][x + 6] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//-6
				if (d[y + Ay][x + 6] == 0)d[y + Ay][x + 6] = 1;//-7
				if (d[y + Ay][x + 7] == 0)d[y + Ay][x + 7] = 1;//
			}
		}
		if (act3 == acttime[1]++ || act3 == acttime[1]++)//22
		{
			act1 = 7;
			if (l == 1) {
				for (b = 0;b < 8;b++)
				{
					if (d[y][x + 3] == 3 || d[y + 2][x + 3] == 3 || d[y + 4][x + 3] == 3 || d[y + 8][x + 3] == 3)break;x++;
					for (a = -1;a < 9;a++)
					{
						if (d[y + a][x + 9] >= 20) { dhurt[d[y + a][x + 9]] = 1;break; }
					}//伤害判定
				}
				Ay = 0;
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//5
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//5
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//6
				if (d[y + Ay][x + 6] == 0)d[y + Ay][x + 6] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//6
				if (d[y + Ay][x + 6] == 0)d[y + Ay][x + 6] = 1;//7
				if (d[y + Ay][x + 7] == 0)d[y + Ay][x + 7] = 1;//8
				if (d[y + Ay][x + 8] == 0)d[y + Ay][x + 8] = 1;//9
				if (d[y + Ay][x + 9] == 0)d[y + Ay][x + 9] = 1;//10
				if (d[y + Ay][x + 10] == 0)d[y + Ay][x + 10] = 1;//Ay++;
				Ay++;// -1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//9
				if (d[y + Ay][x + 9] == 0)d[y + Ay][x + 9] = 1;//10
				if (d[y + Ay][x + 10] == 0)d[y + Ay][x + 10] = 1;//11
				if (d[y + Ay][x + 11] == 0)d[y + Ay][x + 11] = 1;//Ay++;
				Ay++;// -2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//12
				if (d[y + Ay][x + 12] == 0)d[y + Ay][x + 12] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//
			}
			else {
				for (b = 0;b < 8;b++)
				{
					if (d[y][x - 3] == 3 || d[y + 2][x - 3] == 3 || d[y + 4][x - 3] == 3 || d[y + 8][x - 3] == 3)break;x--;
					for (a = -1;a < 9;a++)
					{
						if (d[y + a][x - 9] >= 20) { dhurt[d[y + a][x - 9]] = 1;break; }
					}//伤害判定
				}
				Ay = 0;
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//5
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//5
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//6
				if (d[y + Ay][x - 6] == 0)d[y + Ay][x - 6] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x - 2] = 1;//6
				if (d[y + Ay][x - 6] == 0)d[y + Ay][x - 6] = 1;//7
				if (d[y + Ay][x - 7] == 0)d[y + Ay][x - 7] = 1;//8
				if (d[y + Ay][x - 8] == 0)d[y + Ay][x - 8] = 1;//9
				if (d[y + Ay][x - 9] == 0)d[y + Ay][x - 9] = 1;//10
				if (d[y + Ay][x - 10] == 0)d[y + Ay][x - 10] = 1;//Ay++;
				Ay++;// -1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//9
				if (d[y + Ay][x - 9] == 0)d[y + Ay][x - 9] = 1;//10
				if (d[y + Ay][x - 10] == 0)d[y + Ay][x - 10] = 1;//11
				if (d[y + Ay][x - 11] == 0)d[y + Ay][x - 11] = 1;//Ay++;
				Ay++;// -2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//12
				if (d[y + Ay][x - 12] == 0)d[y + Ay][x - 12] = 1;//Ay++;
				Ay++;// 3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//-3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//
			}
		}
		if (act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++ || act3 == acttime[1]++)//25
		{
			act1 = 7;
			if (l == 1) {
				for (b = 0;b < 2;b++)
				{
					if (d[y][x + 3] == 3 || d[y + 2][x + 3] == 3 || d[y + 4][x + 3] == 3 || d[y + 8][x + 3] == 3)break;x++;
					for (a = -1;a < 9;a++)
					{
						if (d[y + a][x + 8] >= 20) { dhurt[d[y + a][x + 8]] = 1;break; }
					}//伤害判定
				}
				Ay = 0;
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//9
				if (d[y + Ay][x + 10] == 0)d[y + Ay][x + 10] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//8
				if (d[y + Ay][x + 8] == 0)d[y + Ay][x + 8] = 1;//7
				if (d[y + Ay][x + 7] == 0)d[y + Ay][x + 7] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//7
				if (d[y + Ay][x + 7] == 0)d[y + Ay][x + 7] = 1;//6
				if (d[y + Ay][x + 6] == 0)d[y + Ay][x + 6] = 1;//5
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//4
				if (d[y + Ay][x + 4] == 0)d[y + Ay][x + 4] = 1;//5
				if (d[y + Ay][x + 5] == 0)d[y + Ay][x + 5] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x + 3] == 0)d[y + Ay][x + 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//
			}
			else {
				for (b = 0;b < 2;b++)
				{
					if (d[y][x - 3] == 3 || d[y + 2][x - 3] == 3 || d[y + 4][x - 3] == 3 || d[y + 8][x - 3] == 3)break;x--;
					for (a = -1;a < 9;a++)
					{
						if (d[y + a][x - 8] >= 20) { dhurt[d[y + a][x - 8]] = 1;break; }
					}//伤害判定
				}
				Ay = 0;
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//9
				if (d[y + Ay][x - 10] == 0)d[y + Ay][x - 10] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//8
				if (d[y + Ay][x - 8] == 0)d[y + Ay][x - 8] = 1;//7
				if (d[y + Ay][x - 7] == 0)d[y + Ay][x - 7] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//7
				if (d[y + Ay][x - 7] == 0)d[y + Ay][x - 7] = 1;//6
				if (d[y + Ay][x - 6] == 0)d[y + Ay][x - 6] = 1;//5
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//4
				if (d[y + Ay][x - 4] == 0)d[y + Ay][x - 4] = 1;//5
				if (d[y + Ay][x - 5] == 0)d[y + Ay][x - 5] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x - 2] == 0)d[y + Ay][x - 2] = 1;//3
				if (d[y + Ay][x - 3] == 0)d[y + Ay][x - 3] = 1;//Ay++;
				Ay++;// 0
				if (d[y + Ay][x] == 0)d[y + Ay][x] = 1;//1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x + 1] == 0)d[y + Ay][x + 1] = 1;//-1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//Ay++;
				Ay++;// 1
				if (d[y + Ay][x - 1] == 0)d[y + Ay][x - 1] = 1;//-2
				if (d[y + Ay][x + 2] == 0)d[y + Ay][x + 2] = 1;//
			}

		}
		if (act3 >= 33) {
			act3 = 0; act1 = 0; cooldown[0] = 10;
		}//防止误判

	}
}

float sina(int x1, int y1)
{
	int b;
	float all, c, d, e, f, g;
	c = x1;
	d = y1;
	x1 *= x1;
	y1 *= y1;
	e = x1 + y1;
	f = c + d;
	if (c > d) { for (b = c;b < f;b++) { all = b * b;if (e - all < 0)break; } }
	else { for (b = d;b < f;b++) { all = b * b;if (e - all < 0)break; } }
	g = c / b;//g需要定义为全局变量
}

void gametable()
{
	int a, b;
	//for (b = 0;b < 15;b++) 
	for (a = 0;a < 120;a++) { st[15][a] = '+'; }
	for (a = 0;a < 120;a++) { st[28][a] = '+'; }
	for (a = 0;a < 120;a++) { st[32][a] = '+'; }
	for (a = 0;a < 120;a++) { st[45][a] = '+'; }


}

void trader(int x1, int y1, char e) {
	if (e == 0) {
		char Ay = 0;
		y1 = 600 - y1;x1 = x1 + 60;
		if (d[y1][x1] == 0)d[y1][x1] = 19;
		if (d[y1][x1 + 1] == 0)d[y1][x1 + 1] = 19;
		if (d[y1][x1 - 1] == 0)d[y1][x1 - 1] = 19;
		y1++;
		if (d[y1][x1 + 2] == 0)d[y1][x1 + 2] = 19;
		if (d[y1][x1 - 2] == 0)d[y1][x1 - 2] = 19;
		if (d[y1][x1] == 0)d[y1][x1] = 19;
		y1++;
		if (d[y1][x1] == 0)d[y1][x1] = 19;//三层
		if (d[y1][x1 + 1] == 0)d[y1][x1 + 1] = 19;
		if (d[y1][x1 + 2] == 0)d[y1][x1 + 2] = 19;
		if (d[y1][x1 + 3] == 0)d[y1][x1 + 3] = 19;
		if (d[y1][x1 + 4] == 0)d[y1][x1 + 4] = 19;
		if (d[y1][x1 + 5] == 0)d[y1][x1 + 5] = 19;
		if (d[y1][x1 - 1] == 0)d[y1][x1 - 1] = 19;
		if (d[y1][x1 - 2] == 0)d[y1][x1 - 2] = 19;
		y1++;
		if (d[y1][x1] == 0)d[y1][x1] = 19;//四层
		if (d[y1][x1 - 2] == 0)d[y1][x1 - 2] = 19;
		if (d[y1][x1 + 2] == 0)d[y1][x1 + 2] = 19;
		if (d[y1][x1 + 3] == 0)d[y1][x1 + 3] = 19;
		if (d[y1][x1 - 3] == 0)d[y1][x1 - 3] = 19;
		if (d[y1][x1 + 5] == 0)d[y1][x1 + 5] = 19;
		y1++;
		if (d[y1][x1] == 0)d[y1][x1] = 19;//五层
		if (d[y1][x1 + 1] == 0)d[y1][x1 + 1] = 19;
		if (d[y1][x1 - 1] == 0)d[y1][x1 - 1] = 19;
		if (d[y1][x1 - 2] == 0)d[y1][x1 - 2] = 19;
		if (d[y1][x1 + 2] == 0)d[y1][x1 + 2] = 19;
		if (d[y1][x1 + 3] == 0)d[y1][x1 + 3] = 19;
		if (d[y1][x1 - 3] == 0)d[y1][x1 - 3] = 19;
		if (d[y1][x1 + 5] == 0)d[y1][x1 + 5] = 19;
		y1++;
		if (d[y1][x1] == 0)d[y1][x1] = 19;//六层
		if (d[y1][x1 - 2] == 0)d[y1][x1 - 2] = 19;
		if (d[y1][x1 + 2] == 0)d[y1][x1 + 2] = 19;
		if (d[y1][x1 + 3] == 0)d[y1][x1 + 3] = 19;
		if (d[y1][x1 - 3] == 0)d[y1][x1 - 3] = 19;
		if (d[y1][x1 + 4] == 0)d[y1][x1 + 4] = 19;
		if (d[y1][x1 + 5] == 0)d[y1][x1 + 5] = 19;
		y1++;
		//七层
		if (d[y1][x1 - 1] == 0)d[y1][x1 - 1] = 19;
		if (d[y1][x1 + 1] == 0)d[y1][x1 + 1] = 19;
		if (d[y1][x1 + 3] == 0)d[y1][x1 + 3] = 19;
		if (d[y1][x1 - 3] == 0)d[y1][x1 - 3] = 19;

		y1++;//八层
		if (d[y1][x1 - 1] == 0)d[y1][x1 - 1] = 19;
		if (d[y1][x1 + 1] == 0)d[y1][x1 + 1] = 19;
		if (d[y1][x1 + 3] == 0)d[y1][x1 + 3] = 19;
		if (d[y1][x1 - 2] == 0)d[y1][x1 - 2] = 19;
		if (d[y1][x1 + 2] == 0)d[y1][x1 + 2] = 19;
		y1++;//九层
		if (d[y1][x1 - 1] == 0)d[y1][x1 - 1] = 19;
		if (d[y1][x1 + 1] == 0)d[y1][x1 + 1] = 19;
		if (d[y1][x1 + 3] == 0)d[y1][x1 + 3] = 19;
		if (d[y1][x1 - 2] == 0)d[y1][x1 - 2] = 19;
		if (d[y1][x1 + 2] == 0)d[y1][x1 + 2] = 19;
		if (d[y1][x1 - 3] == 0)d[y1][x1 - 3] = 19;
	}
	else //商人对话
	{

		printf("#############################################################################################################################################\n");
		if (trad == 1)
		{
			if (2 == room)
				printf("                                                     md终于遇到活人了，这年头生意真不好做，我是这里的商人，请问有什么事吗？\n");
			else
				printf("                                                     welcome！ 啊哈是你啊，咱又见面了。\n");
			printf("\n");
			printf("                                                     我需要购买物品吗？（按1进入物品购买）                                                \n");
			//房间2特有剧情
			if (2 == room)
			{
				printf("\n");
				printf("                                                     该如何离开这里？（按3询问）                                                \n");
			}
			//房间2特有剧情
			printf("\n");
			printf("                                                     溜了溜了~~~（按0退出）\n");
			if (meun == 1) { trad++;system("cls");meun = '?'; }
			if (meun == 0) { trad--;talk = 0;system("cls");exit; }//如果talk=0则将不显示与商人对话
			if (meun == 3) { trad = 3;system("cls");meun = '?'; }
		}
		if (trad == 2)
		{
			printf("                                                      按对应数字键即可购买\n");printf("\n");
			printf("                              1云南白药膏               2万能剑油                  3手gun             4中华大补丸");
			printf("\n");
			printf("\n");
			printf("                                                     不想买了~~~（按0退出）\n");
			switch (shopper)
			{
			case 0:
			{
				switch (meun)
				{
				case 0:trad--;system("cls");meun = '?';               break;
				case 1:shopper = 1;meun = '?';        break;
				case 2:shopper = 2;meun = '?';        break;
				case 3:shopper = 3;meun = '?';        break;
				case 4:shopper = 4;meun = '?';        break;
				default:break;
				}
			}break;
			case 1:
			{
				printf("\n                                 云南白药膏：回复10体力，有了它妈妈再也不用担心我作死了，购买后直接使用。              \n");
				printf("                                 现在不需要998，不需要888，只要8元              \n");
				printf("\n");
				printf("                    是否购买            1确定                                    2取消                                   \n");
				if (meun == 1) {
					shopper = 0;meun = '?';
					if (m1 >= 8)
					{
						m1 -= 8;//交钱;
						heart1 += 10;//加血
						if (heart1 > heart2)heart1 = heart2;//如果生命超了 
						printf("                                             大爷您收好！(按任意键继续)\n");
						_getch();//停顿一下
					}
					else {
						printf("                                   没钱你买个毛！(按任意键继续)\n");
						_getch();//停顿一下
					}
					system("cls");

				}//确定交易
				if (meun == 2) { shopper = 0;system("cls");meun = '?'; }//取消交易
			}break;
			case 2:
			{
				printf("\n                                 万能剑油：利维亚网红裂膜人gay洛特的御用剑油，使你的剑增加永久锋利，购买后直接使用。              \n");
				printf("                                 用完你不会吃亏，不会上当，只要30元              \n");
				printf("\n");
				printf("                    是否购买            1确定                                    2取消                                   \n");
				if (meun == 1) {
					shopper = 0;meun = '?';
					if (m1 >= 30)
					{
						m1 -= 30;//交钱;
						bladehurt += 2;//加攻击 
						printf("                                             大爷您涂好！(按任意键继续)\n");
						_getch();//停顿一下
					}
					else {
						printf("                                   没钱你买个毛！(按任意键继续)\n");
						_getch();//停顿一下
					}
					system("cls");

				}//确定交易
				if (meun == 2) { shopper = 0;system("cls");meun = '?'; }//取消交易
			}break;
			case 3: {printf("\n                                 没货，下一个              \n");shopper = 0;_getch();system("cls");meun = '?';}
			case 4:
			{
				printf("\n                                 中华大补丸：雄氏老方鼎力推荐，让透支的补起来，永久增加体力，购买后直接使用。              \n");
				printf("                                      他好，我也好~~，只要40元              \n");
				printf("\n");
				printf("                    是否购买            1确定                                    2取消                                   \n");
				if (meun == 1) {
					shopper = 0;meun = '?';
					if (m1 >= 40)
					{
						m1 -= 40;//交钱;
						heart2 += 10;//加血上限 
						printf("                                             大爷您肾好！(按任意键继续)\n");
						_getch();//停顿一下
					}
					else {
						printf("                                   没钱你买个毛！(按任意键继续)\n");
						_getch();//停顿一下
					}
					system("cls");

				}//确定交易
				if (meun == 2) { shopper = 0;system("cls");meun = '?'; }//取消交易
			}break;








			default:break;

			}


		}

		if (room == 2 && trad == 3)
		{
			talkf(91, 97);
			if (meun == 0) {
				trad = 1;talktime = 0;system("cls");meun = '?';
			}




		}





		printf("#############################################################################################################################################\n");
	}

}

void slim(int x2, int y2, int h1, int id, int r)
{/*
  ---------------------------------------------------------------------------------------------------------------------------------------------
                           函数分为逻辑区与对话区
   常用参数 a,b，Ay
   x2					初始化横坐标													y2					初始化纵坐标 
   h1					初始化生命														id					怪物逻辑编号 
   r					怪物寻敌半径													e					是否为逻辑/对话
   die[id]				怪物死亡不在运行标志											i[id]				怪物的实际生命值+1
   x1					怪物横坐标														y1					怪物纵坐标 
   xm[id]				怪物实际横坐标											    	ym[id]				怪物实际纵坐标
   Vy2					怪物当前速度（整型）											max					最大速度 
   yfork				武器横坐标														xfork				武器纵坐标
   nice[id]				怪物善恶值													    ato[id]				怪物当前状态为巡逻/发现敌人
   fag[0]				是前往目标的标志												fag[1]				是第一个目标坐标 
   fag[2]				是第二个目标坐标												fag[3]				是怪物是否落地  
   aY[id]				怪物纵向加速度													axmonst[id]			怪物横向加速度
   actmonst[id]			怪物当前动作模型                                                d[][]=id            怪物在游戏中逻辑层的模型
   vY[id]               怪物当前纵向速度(浮点数)										Vy2[id]				怪物当前纵向速度（整型）
   hurteen[id]          怪物受伤标志                                                    dieword[id]         当怪物战斗中途触发的对话
   axmonst[id]          怪物横向加速度                                                  conmonst[id]        怪物左右朝向
   V1monst[id]          怪物横向速度（浮点数）                                          V2monst[id]         怪物横向速度整型数
   meun                 怪物对话深度（层次）                                            acttime[id]         当前动作持续的帧数（时间）
  ----------------------------------------------------------------------------------------------------------------------------------------------
  */
	x2 = x2 + 30 + 30;
	int x1 = 0, y1 = 0, a = 0, b = 0, Vy2 = 0;
	if (die[id] < 1) {
		if (i[id] == 0)//怪物数据函数初始化 
		{
			xm[id] = x2;ym[id] = y2;i[id] = h1 + 1;ym[id] = 600 - ym[id];fag[id][1] = xm[id] + r;fag[id][2] = xm[id] - r;ato[id] = 1;aY[id] = 0;hurteen[id] = i[id];
			actmonst[id] = 0;
		}
		y1 = ym[id];
		//寻敌
		if (y1 - y >= 0 && y1 - y < 15)
		{

			if ((x >= xm[id] && x - xm[id] < 30) || (x < xm[id] && xm[id] - x < 30)) { if (fag[id][3] == 1)ato[id] = 0; }
			else { if (fag[id][3] == 1)ato[id] = 1; }
		}
		else { if (fag[id][3] == 1)ato[id] = 1; }


		actmonst[id]++;
		if (actmonst[id] > 32)actmonst[id] = 0;

		if (ato[id] == 1)//巡航，巡逻
		{
			if (fag[id][0] == 1|| fag[id][0] == 2)
				if ((actmonst[id] == 0&& fag[id][3] == 1) || (actmonst[id] == 10 && fag[id][3] == 1 )|| (actmonst[id] == 20 && fag[id][3] == 1) ||
				actmonst[id] == 1 || actmonst[id] == 11  || actmonst[id] == 21  ||
				actmonst[id] == 2 || actmonst[id] == 12  || actmonst[id] == 22 ) {
					ym[id] -= 2; vY[id] = 0;aY[id] = 0;
			}
			//蹦蹦跳

			//*************************
			//*fag[0]是前往目标的标志 *
			//*fag[1]是第一个目标坐标 *
			//*fag[2]是第二个目标坐标 *
			//*fag[3]是怪物是否落地   *
			//*************************
			if (fag[id][0] == 0) { fag[id][0]=1; }
			
				if (fag[id][0] == 1)
				{
					if (fag[id][1] != xm[id])
					{
						if (fag[id][1] > xm[id])  if (actmonst[id] == 0 || actmonst[id] == 10  || actmonst[id] == 20  ||
							actmonst[id] == 1 || actmonst[id] == 11  || actmonst[id] == 21  ||
							actmonst[id] == 2 || actmonst[id] == 12  || actmonst[id] == 22 ) { xm[id]++; }
						if (fag[id][1] < xm[id]) if (actmonst[id] == 0 || actmonst[id] == 10  || actmonst[id] == 20 ||
							actmonst[id] == 1 || actmonst[id] == 11  || actmonst[id] == 21  ||
							actmonst[id] == 2 || actmonst[id] == 12  || actmonst[id] == 22 ) { xm[id]--; }
					}
					else { fag[id][0]++; }
				}
			
			if (fag[id][0] == 2)
			{
				if (fag[id][2] != xm[id])
				{
					if (fag[id][2] > xm[id])  if (actmonst[id] == 0 || actmonst[id] == 10 || actmonst[id] == 20 ||
						actmonst[id] == 1 || actmonst[id] == 11 || actmonst[id] == 21 ||
						actmonst[id] == 2 || actmonst[id] == 12 || actmonst[id] == 22) {
						xm[id]++;
					}
					if (fag[id][2] < xm[id]) if (actmonst[id] == 0 || actmonst[id] == 10 || actmonst[id] == 20 ||
						actmonst[id] == 1 || actmonst[id] == 11 || actmonst[id] == 21 ||
						actmonst[id] == 2 || actmonst[id] == 12 || actmonst[id] == 22) {
						xm[id]--;
					}
				}
				else { fag[id][0] = 0; }
			}

		}
		else
		{
			if (x > xm[id])xm[id]++;else xm[id]--;
			if (fag[id][3] == 1)ym[id] -= 4;//蹦蹦跳
			
		}



		//猛汉跳楼模拟器
		if (d[ym[id] + 1][xm[id]] != 2 && d[ym[id] + 1][xm[id] + 1] != 2 && d[ym[id] + 1][xm[id] - 1] != 2)
		{

			if (aY[id] <= 2) { aY[id] += 0.5; }
			if (vY[id] < 8)vY[id] = vY[id] + aY[id]/1.5;
			Vy2 = vY[id];

			for (a = 0;a < Vy2;a++)//下落检测
			{
				ym[id]++;
				if (d[ym[id] + 1][xm[id]] == 2 || d[ym[id] + 1][xm[id] + 1] == 2 || d[ym[id] + 1][xm[id] - 1] == 2)
				{
					aY[id] = 0;vY[id] = 0;Vy2 = 0;fag[id][3]=1;break;
				}
				else fag[id][3] = 0;
			}


		}
		if (hurteen[id] != i[id])
		{
			hurteen[id] = i[id];
			延迟(300);
		}

		if (i[id] > 1)
		{//生命等于0时
			if (i[id] < 10000) {
				if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
				if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
				if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
				if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
				if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
				y1--;
				if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;

				if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;

				if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
				y1--;
				if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
				if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
				if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
				if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
				if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
				y1--;
				if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
				if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
				if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;

			}
			else {
				if (i[id] < 10001) { i[id]++;die[id]++; }
			}
		}
		else
		{
			if (d[y1][xm[id]] == id)d[y1][xm[id]] = 0;
			if (d[y1][xm[id] + 1] == id)d[y1][xm[id] + 1] = 0;
			if (d[y1][xm[id] + 2] == id)d[y1][xm[id] + 2] = 0;
			if (d[y1][xm[id] - 1] == id)d[y1][xm[id] - 1] = 0;
			if (d[y1][xm[id] - 2] == id)d[y1][xm[id] - 2] = 0;
			y1--;
			if (d[y1][xm[id]] == id)d[y1][xm[id]] = 0;

			if (d[y1][xm[id] + 2] == id)d[y1][xm[id] + 2] = 0;

			if (d[y1][xm[id] - 2] == id)d[y1][xm[id] - 2] = 0;
			y1--;
			if (d[y1][xm[id]] == id)d[y1][xm[id]] = 0;
			if (d[y1][xm[id] + 1] == id)d[y1][xm[id] + 1] = 0;
			if (d[y1][xm[id] + 2] == id)d[y1][xm[id] + 2] = 0;
			if (d[y1][xm[id] - 1] == id)d[y1][xm[id] - 1] = 0;
			if (d[y1][xm[id] - 2] == id)d[y1][xm[id] - 2] = 0;
			y1--;
			if (d[y1][xm[id]] == id)d[y1][xm[id]] = 0;
			if (d[y1][xm[id] + 1] == id)d[y1][xm[id] + 1] = 0;
			if (d[y1][xm[id] - 1] == id)d[y1][xm[id] - 1] = 0;
			i[id] = 10000;
			mop[room]++;//怪物死亡对关卡的回馈

		}
		
	}
}

void manbat(int x2, int y2, int h1, int id, int r)
{/*
  ---------------------------------------------------------------------------------------------------------------------------------------------
                           函数分为逻辑区与对话区
   常用参数 a,b，Ay
   x2					初始化横坐标													y2					初始化纵坐标 
   h1					初始化生命														id					怪物逻辑编号 
   r					怪物寻敌半径													e					是否为逻辑/对话
   die[id]				怪物死亡不在运行标志											i[id]				怪物的实际生命值+1
   x1					怪物横坐标														y1					怪物纵坐标 
   xm[id]				怪物实际横坐标											    	ym[id]				怪物实际纵坐标
   Vy2					怪物当前速度（整型）											max					最大速度 
   yfork				武器横坐标														xfork				武器纵坐标
   nice[id]				怪物善恶值													    ato[id]				怪物当前状态为巡逻/发现敌人
   fag[0]				是前往目标的标志												fag[1]				是第一个目标坐标 
   fag[2]				是第二个目标坐标												fag[3]				是怪物是否落地  
   aY[id]				怪物纵向加速度													axmonst[id]			怪物横向加速度
   actmonst[id]			怪物当前动作模型                                                d[][]=id            怪物在游戏中逻辑层的模型
   vY[id]               怪物当前纵向速度(浮点数)										Vy2[id]				怪物当前纵向速度（整型）
   hurteen[id]          怪物受伤标志                                                    dieword[id]         当怪物战斗中途触发的对话
   axmonst[id]          怪物横向加速度                                                  conmonst[id]        怪物左右朝向
   V1monst[id]          怪物横向速度（浮点数）                                          V2monst[id]         怪物横向速度整型数
   meun                 怪物对话深度（层次）                                            acttime[id]         当前动作持续的帧数（时间）
  ----------------------------------------------------------------------------------------------------------------------------------------------
  */
	int x1 = 0, y1 = 0, a = 0, b = 0, Vy2 = 0, max = 3, atk = 3;
	if (die[id] < 1) {
		if (i[id] == 0)//怪物数据函数初始化 
		{
			x2 = x2 + 30 + 30;
			xm[id] = x2;ym[id] = y2;i[id] = h1 + 1;ym[id] = 600 - ym[id];fag[id][1] = xm[id] + r;fag[id][2] = xm[id] - r;ato[id] = 1;aY[id] = 0;
		}

		//寻敌


		if ((x >= xm[id] && x - xm[id] < 80) || (x < xm[id] && xm[id] - x < 80)) { ato[id] = 0; }
		else { ato[id] = 1; }





		if (ato[id] == 1)//巡航，巡逻
		{
			axmonst[id] = 0;V2monst[id] = 0;V1monst[id] = 0;

		}
		else
		{
			if (x > xm[id]) { if (axmonst[id] < 0)axmonst[id] = 0;axmonst[id]++; }
			else { if (axmonst[id] > 0)axmonst[id] = 0;axmonst[id]--; }
			if (y + 4 > ym[id]) { if (ayfly[id] < 0)ayfly[id] = 0;ayfly[id]++; }
			else { if (ayfly[id] > 0)ayfly[id] = 0;ayfly[id]--; }
			if ((y + 5 - ym[id]<5 && y + 5>ym[id]) || (ym[id] - y - 5 - ym[id]<5 && ym[id]>y + 5))
				if ((x - xm[id]<5 && x > xm[id]) || (xm[id] - x < 5 && x < xm[id])) { heart1 = heart1 - atk; }

		}






		if (axmonst[id] != 0)
		{
			V1monst[id] = V1monst[id] + axmonst[id] / 10;V2monst[id] = V1monst[id];
			if (V1monst[id] <= -max) { V1monst[id] = -max; }
			else if (V1monst[id] >= max) { V1monst[id] = max; }
		}
		if (V2monst[id] > 0)
		{
			{for (a = 0;a < V2monst[id];a++)
			{
				if (
					d[y - 8][x + 2] == 4 || d[y - 7][x + 2] == 4 || d[y - 6][x + 2] == 4 || d[y - 5][x - 2] == 4 || d[y - 4][x + 3] == 4 || d[y - 3][x - 3] == 4 || d[y - 1][x - 2] == 4 || d[y][x - 2] == 4
					)
				{
					V1monst[id] = 0;V2monst[id] = 0;axmonst[id] = 0;xm[id] = xm[id] - 3;break;
				}

				xm[id]++;
			}
			}

		}
		if (V2monst[id] < 0)
		{
			{for (a = 0;a + V2monst[id];a++)
			{
				if (
					d[y - 8][x - 2] == 4 || d[y - 7][x - 2] == 4 || d[y - 6][x - 2] == 4 || d[y - 5][x - 2] == 4 || d[y - 4][x - 3] == 4 || d[y - 3][x - 3] == 4 || d[y - 1][x - 2] == 4 || d[y][x - 2] == 4
					)
				{
					V1monst[id] = 0;V2monst[id] = 0;axmonst[id] = 0;xm[id] = xm[id] + 3;break;
				}

				xm[id]--;
			}
			}

		}



		if (ayfly[id] != 0)
		{
			Vy1monst[id] = Vy1monst[id] + ayfly[id] / 10;Vy2monst[id] = Vy1monst[id];
			if (Vy1monst[id] <= -max) { Vy1monst[id] = -max; }
			else if (Vy1monst[id] >= max) { Vy1monst[id] = max; }
		}
		if (Vy2monst[id] > 0)
		{
			{for (a = 0;a < Vy2monst[id];a++)
			{

				if (ym[id] > y + 10) { Vy2monst[id] = 0; Vy1monst[id] = 0;ayfly[id] = 0;ym[id] = ym[id] - 1;break; }
				ym[id]++;
			}
			}

		}
		if (Vy2monst[id] < 0)
		{
			{for (a = 0;a + Vy2monst[id];a++)
			{
				if (ym[id] < y - 20) { Vy2monst[id] = 0;Vy1monst[id] = 0;ayfly[id] = 0;ym[id] = ym[id] + 1;break; }

				ym[id]--;
			}
			}

		}







		y1 = ym[id];
		if (hurteen[id] != i[id])//伤害动画
		{
			hurteen[id] = i[id];
			延迟(300);
		}
		if (i[id] > 1)
		{//生命等于0时
			if (i[id] < 10000) {
				if (d[y1][xm[id]] == 0)d[y1][xm[id]] = 0;
				if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
				if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
				if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
				y1--;
				if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
				if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
				y1--;
				if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;//三层
				if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
				if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
				if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
				if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
				if (d[y1][xm[id] + 5] == 0)d[y1][xm[id] + 5] = id;
				if (d[y1][xm[id] + 6] == 0)d[y1][xm[id] + 6] = id;
				if (d[y1][xm[id] + 7] == 0)d[y1][xm[id] + 7] = id;
				if (d[y1][xm[id] + 8] == 0)d[y1][xm[id] + 8] = id;
				if (d[y1][xm[id] + 9] == 0)d[y1][xm[id] + 9] = id;
				if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
				if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
				if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
				if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
				if (d[y1][xm[id] - 5] == 0)d[y1][xm[id] - 5] = id;
				if (d[y1][xm[id] - 6] == 0)d[y1][xm[id] - 6] = id;
				if (d[y1][xm[id] - 7] == 0)d[y1][xm[id] - 7] = id;
				if (d[y1][xm[id] - 8] == 0)d[y1][xm[id] - 8] = id;
				y1--;
				if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;//四层
				if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
				if (d[y1][xm[id] - 8] == 0)d[y1][xm[id] - 8] = id;
				if (d[y1][xm[id] + 9] == 0)d[y1][xm[id] + 9] = id;
				y1--;
				if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;//五层
				if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
				if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
				if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
				if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
				if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
				if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
				if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
				if (d[y1][xm[id] - 8] == 0)d[y1][xm[id] - 8] = id;
				if (d[y1][xm[id] + 9] == 0)d[y1][xm[id] + 9] = id;
				y1--;
				if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
				if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;//六层
				if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
				if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
				if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
				if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
				if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
				if (d[y1][xm[id] + 5] == 0)d[y1][xm[id] + 5] = id;
				if (d[y1][xm[id] - 7] == 0)d[y1][xm[id] - 7] = id;
				if (d[y1][xm[id] + 8] == 0)d[y1][xm[id] + 8] = id;
				y1--;
				if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
				if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
				if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
				if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
				if (d[y1][xm[id] - 6] == 0)d[y1][xm[id] - 6] = id;
				if (d[y1][xm[id] - 5] == 0)d[y1][xm[id] - 5] = id;
				if (d[y1][xm[id] + 6] == 0)d[y1][xm[id] + 6] = id;
				if (d[y1][xm[id] + 7] == 0)d[y1][xm[id] + 7] = id;
				y1--;
				if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
				if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
			}
			else {
				if (i[id] < 10001) { i[id]++;die[id]++; }
			}
		}
		else
		{
			if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
			if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = 0;
			if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = 0;
			if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = 0;
			y1--;
			if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = 0;
			if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = 0;
			y1--;
			if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;//三层
			if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = 0;
			if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = 0;
			if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = 0;
			if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = 0;
			if (d[y1][xm[id] + 5] == 0)d[y1][xm[id] + 5] = 0;
			if (d[y1][xm[id] + 6] == 0)d[y1][xm[id] + 6] = 0;
			if (d[y1][xm[id] + 7] == 0)d[y1][xm[id] + 7] = 0;
			if (d[y1][xm[id] + 8] == 0)d[y1][xm[id] + 8] = 0;
			if (d[y1][xm[id] + 9] == 0)d[y1][xm[id] + 9] = 0;
			if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = 0;
			if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = 0;
			if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = 0;
			if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = 0;
			if (d[y1][xm[id] - 5] == 0)d[y1][xm[id] - 5] = 0;
			if (d[y1][xm[id] - 6] == 0)d[y1][xm[id] - 6] = 0;
			if (d[y1][xm[id] - 7] == 0)d[y1][xm[id] - 7] = 0;
			if (d[y1][xm[id] - 8] == 0)d[y1][xm[id] - 8] = 0;
			y1--;
			if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;//四层
			if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = 0;
			if (d[y1][xm[id] - 8] == 0)d[y1][xm[id] - 8] = 0;
			if (d[y1][xm[id] + 9] == 0)d[y1][xm[id] + 9] = 0;
			y1--;
			if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;//五层
			if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = 0;
			if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = 0;
			if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = 0;
			if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = 0;
			if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = 0;
			if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = 0;
			if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = 0;
			if (d[y1][xm[id] - 8] == 0)d[y1][xm[id] - 8] = 0;
			if (d[y1][xm[id] + 9] == 0)d[y1][xm[id] + 9] = 0;
			y1--;
			if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
			if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = 0;//六层
			if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = 0;
			if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = 0;
			if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = 0;
			if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = 0;
			if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = 0;
			if (d[y1][xm[id] + 5] == 0)d[y1][xm[id] + 5] = 0;
			if (d[y1][xm[id] - 7] == 0)d[y1][xm[id] - 7] = 0;
			if (d[y1][xm[id] + 8] == 0)d[y1][xm[id] + 8] = 0;
			y1--;
			if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = 0;
			if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = 0;
			if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = 0;
			if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = 0;
			if (d[y1][xm[id] - 6] == 0)d[y1][xm[id] - 6] = 0;
			if (d[y1][xm[id] - 5] == 0)d[y1][xm[id] - 5] = 0;
			if (d[y1][xm[id] + 6] == 0)d[y1][xm[id] + 6] = 0;
			if (d[y1][xm[id] + 7] == 0)d[y1][xm[id] + 7] = 0;
			y1--;
			if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = 0;
			if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = 0;
			i[id] = 10000;
			mop[room]++;//怪物死亡对关卡的回馈

		}
		if (fag[id][3] > 1)fag[id][3] = 0;
	}
}

void hardso(int x2, int y2, int h1, int id, int r, int e)
{/*
  ---------------------------------------------------------------------------------------------------------------------------------------------
                           函数分为逻辑区与对话区
   常用参数 a,b，Ay
   x2					初始化横坐标													y2					初始化纵坐标 
   h1					初始化生命														id					怪物逻辑编号 
   r					怪物寻敌半径													e					是否为逻辑/对话
   die[id]				怪物死亡不在运行标志											i[id]				怪物的实际生命值+1
   x1					怪物横坐标														y1					怪物纵坐标 
   xm[id]				怪物实际横坐标											    	ym[id]				怪物实际纵坐标
   Vy2					怪物当前速度（整型）											max					最大速度 
   yfork				武器横坐标														xfork				武器纵坐标
   nice[id]				怪物善恶值													    ato[id]				怪物当前状态为巡逻/发现敌人
   fag[0]				是前往目标的标志												fag[1]				是第一个目标坐标 
   fag[2]				是第二个目标坐标												fag[3]				是怪物是否落地  
   aY[id]				怪物纵向加速度													axmonst[id]			怪物横向加速度
   actmonst[id]			怪物当前动作模型                                                d[][]=id            怪物在游戏中逻辑层的模型
   vY[id]               怪物当前纵向速度(浮点数)										Vy2[id]				怪物当前纵向速度（整型）
   hurteen[id]          怪物受伤标志                                                    dieword[id]         当怪物战斗中途触发的对话
   axmonst[id]          怪物横向加速度                                                  conmonst[id]        怪物左右朝向
   V1monst[id]          怪物横向速度（浮点数）                                          V2monst[id]         怪物横向速度整型数
   meun                 怪物对话深度（层次）                                            acttime[id]         当前动作持续的帧数（时间）
  ----------------------------------------------------------------------------------------------------------------------------------------------
  */
	int x1 = 0, y1 = 0, a = 0, b = 0, Vy2 = 0, c = 0, max = 3, atk = 3, yfork = 0, xfork = 0;
	if (die[id] < 1)
	{
		if (e == 0)
		{
			if (i[id] == 0)//怪物数据函数初始化 
			{
				x2 = x2 + 30 + 30;
				xm[id] = x2;ym[id] = y2;i[id] = h1 + 1;ym[id] = 600 - ym[id];fag[id][1] = xm[id] + r;fag[id][2] = xm[id] - r;ato[id] = 1;aY[id] = 0;ni[id] = -1;
			}

			//寻敌

			if (nice[id] < 0)
			{
				if ((x >= xm[id] && x - xm[id] < 600) || (x < xm[id] && xm[id] - x < 600)) { ato[id] = 0;hdso = 0;talk = 0; }
				else { ato[id] = 1; }
			}
			else { ato[id] = 1; }





			if (ato[id] == 1)//巡航，巡逻,待命
			{
				axmonst[id] = 0;V2monst[id] = 0;V1monst[id] = 0;actmonst[id] = 0;

			}
			else
			{
				if (actmonst[id] != 3)if (x >= xm[id]) { conmonst[id] = 1; }
				else { conmonst[id] = -1; }//自身朝向位置
				if (x > xm[id])//对敌人位置的判断
				{
					if (x > xm[id] + 33)
					{
						if (actmonst[id] == 1 || actmonst[id] == 0) { if (axmonst[id] < 0)axmonst[id] = 0;axmonst[id]++; }
					}
					else
					{
						if (x > xm[id] + 17)
						{
							if (actmonst[id] < 2)actmonst[id] = 1;
							axmonst[id] = 0;
							V2monst[id] = 0;
						}
						else { axmonst[id]--; }
					}
				}
				else
				{
					if (x < xm[id] - 33) {
						if (actmonst[id] == 1 || actmonst[id] == 0) { if (axmonst[id] > 0)axmonst[id] = 0;axmonst[id]--; }
					}
					else
					{
						if (x < xm[id] - 17)
						{
							axmonst[id] = 0;
							V2monst[id] = 0;
							if (actmonst[id] < 2)actmonst[id] = 1;
						}
						else { axmonst[id]++; }
					}

				}
				/*if (y + 4 > ym[id]) { if (ayfly[id] < 0)ayfly[id] = 0;ayfly[id]++; }
				else { if (ayfly[id] > 0)ayfly[id] = 0;ayfly[id]--; }
				if ((y + 5 - ym[id]<5 && y + 5>ym[id]) || (ym[id] - y - 5 - ym[id]<5 && ym[id]>y + 5))
					if ((x - xm[id]<5 && x > xm[id]) || (xm[id] - x < 5 && x < xm[id])) { heart1 = heart1 - atk; }*/

			}
			{//怪物动作与时间
				if (actmonst[id] == 1)
				{
					acttime[id]++;
					if (acttime[id] > 17)
					{
						actmonst[id] = 2;acttime[id] = 0;
					}
				}//怪物动作及时间判定

				if (actmonst[id] == 2)
				{
					acttime[id]++;
					if (acttime[id] > 1) {
						acttime[id] = 0;actmonst[id] = 3;
						if (conmonst[id] == -1)
						{
							for (b = -5;b < 18;b++)
							{
								c = b / 2;
								for (a = 3;a < 32 + c;a++)

									if (d[ym[id] + b][xm[id] - a] == 1) { heart1 = heart1 - 9;goto hardsobreak; }
							}
						}
						else
						{
							for (b = -5;b < 18;b++)
							{
								c = b / 2;
								for (a = 3;a < 32 + c;a++)

									if (d[ym[id] + b][xm[id] + a] == 1) { heart1 = heart1 - 9;goto hardsobreak; }
							}
						}

					}
				}
			hardsobreak:;
				if (actmonst[id] == 3)
				{
					acttime[id]++;
					axmonst[id] = 0;
					V2monst[id] = 0;
					if (acttime[id] > 45) {
						acttime[id] = 0;actmonst[id] = 0;
					}
				}
			}//怪物动作与时间

			if (axmonst[id] != 0)
			{
				V1monst[id] = V1monst[id] + axmonst[id] / 10;V2monst[id] = V1monst[id];
				if (V1monst[id] <= -2) {
					V1monst[id] = -0;
				}
				else if (V1monst[id] >= 2) {
					V1monst[id] = 0;
				}
			}
			if (V2monst[id] > 0)
			{

				{for (a = 0;a < V2monst[id];a++)
				{
					if (
						d[ym[id] - 8][xm[id] + 2] == 3 || d[ym[id] - 7][xm[id] + 2] == 3 || d[ym[id] - 6][xm[id] + 2] == 3 || d[ym[id] - 5][xm[id] - 2] == 3 || d[ym[id] - 4][xm[id] + 3] == 3 || d[ym[id] - 3][xm[id] - 3] == 3 || d[ym[id] - 1][xm[id] - 2] == 3 || d[ym[id]][xm[id] - 2] == 3
						)
					{
						V1monst[id] = 0;V2monst[id] = 0;axmonst[id] = 0;xm[id] = xm[id] - 3;break;
					}

					xm[id]++;
				}
				}

			}
			if (V2monst[id] < 0)
			{

				{for (a = 0;a + V2monst[id];a++)
				{
					if (
						d[ym[id] - 8][xm[id] - 2] == 3 || d[ym[id] - 7][xm[id] - 2] == 3 || d[ym[id] - 6][xm[id] - 2] == 3 || d[ym[id] - 5][xm[id] - 2] == 3 || d[ym[id] - 4][xm[id] - 3] == 3 || d[ym[id] - 3][xm[id] - 3] == 3 || d[ym[id] - 1][xm[id] - 2] == 3 || d[ym[id]][xm[id] - 2] == 3
						)
					{
						V1monst[id] = 0;V2monst[id] = 0;axmonst[id] = 0;xm[id] = xm[id] + 3;break;
					}

					xm[id]--;
				}
				}

			}
			//猛汉跳楼模拟器
			if (d[ym[id] + 19][xm[id]] != 2 && d[ym[id] + 19][xm[id] + 1] != 2 && d[ym[id] + 19][xm[id] - 1] != 2)
			{

				if (aY[id] <= 2) { aY[id] += 0.5; }
				if (vY[id] < 8)vY[id] = vY[id] + aY[id] / 1.5;
				Vy2 = vY[id];

				for (a = 0;a < Vy2;a++)//下落检测
				{
					ym[id]++;
					if (d[ym[id] + 19][xm[id]] == 2 || d[ym[id] + 19][xm[id] + 1] == 2 || d[ym[id] + 19][xm[id] - 1] == 2)
					{
						aY[id] = 0;vY[id] = 0;Vy2 = 0;fag[id][3] = 1;break;
					}
					else fag[id][3] = 0;
				}


			}

			
			y1 = ym[id];
			if (hurteen[id] != i[id])//伤害动画
			{
				hurteen[id] = i[id];
				延迟(300);
			}
			if (i[id] > 1)
			{//生命等于0时
				//怪物图像
				if (i[id] < 10000)
				{

					{


						if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;//1
						if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
						if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						y1++;
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;//2
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;

						y1++;
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;//3
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
						y1++;
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;//4
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
						if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
						if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
						if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						y1++;
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;//5
						if (d[y1][xm[id] + 7] == 0)d[y1][xm[id] + 7] = id;
						if (d[y1][xm[id] + 8] == 0)d[y1][xm[id] + 8] = id;
						if (d[y1][xm[id] + 9] == 0)d[y1][xm[id] + 9] = id;
						if (d[y1][xm[id] + 10] == 0)d[y1][xm[id] + 10] = id;
						if (d[y1][xm[id] + 11] == 0)d[y1][xm[id] + 11] = id;
						if (d[y1][xm[id] + 12] == 0)d[y1][xm[id] + 12] = id;
						if (d[y1][xm[id] - 7] == 0)d[y1][xm[id] - 7] = id;
						if (d[y1][xm[id] - 8] == 0)d[y1][xm[id] - 8] = id;
						if (d[y1][xm[id] - 9] == 0)d[y1][xm[id] - 9] = id;
						if (d[y1][xm[id] - 10] == 0)d[y1][xm[id] - 10] = id;
						if (d[y1][xm[id] - 11] == 0)d[y1][xm[id] - 11] = id;//5
						if (d[y1][xm[id] - 12] == 0)d[y1][xm[id] - 12] = id;
						y1++;
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;//6
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
						if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
						if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
						if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
						if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						if (d[y1][xm[id] + 6] == 0)d[y1][xm[id] + 6] = id;
						if (d[y1][xm[id] - 6] == 0)d[y1][xm[id] - 6] = id;
						if (d[y1][xm[id] + 5] == 0)d[y1][xm[id] + 5] = id;
						if (d[y1][xm[id] - 5] == 0)d[y1][xm[id] - 5] = id;
						if (d[y1][xm[id] - 7] == 0)d[y1][xm[id] - 7] = id;
						if (d[y1][xm[id] + 7] == 0)d[y1][xm[id] + 7] = id;
						if (d[y1][xm[id] - 13] == 0)d[y1][xm[id] - 13] = id;
						if (d[y1][xm[id] + 13] == 0)d[y1][xm[id] + 13] = id;
						y1++;
						//七层
						if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
						if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
						if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
						if (d[y1][xm[id] + 6] == 0)d[y1][xm[id] + 6] = id;
						if (d[y1][xm[id] - 6] == 0)d[y1][xm[id] - 6] = id;
						if (d[y1][xm[id] - 7] == 0)d[y1][xm[id] - 7] = id;
						if (d[y1][xm[id] + 7] == 0)d[y1][xm[id] + 7] = id;
						if (d[y1][xm[id] - 13] == 0)d[y1][xm[id] - 13] = id;
						if (d[y1][xm[id] + 13] == 0)d[y1][xm[id] + 13] = id;


						y1++;//八层
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
						if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
						if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
						if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
						if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						if (d[y1][xm[id] + 6] == 0)d[y1][xm[id] + 6] = id;
						if (d[y1][xm[id] - 6] == 0)d[y1][xm[id] - 6] = id;
						if (d[y1][xm[id] + 5] == 0)d[y1][xm[id] + 5] = id;
						if (d[y1][xm[id] - 5] == 0)d[y1][xm[id] - 5] = id;
						if (d[y1][xm[id] - 8] == 0)d[y1][xm[id] - 8] = id;
						if (d[y1][xm[id] - 9] == 0)d[y1][xm[id] - 9] = id;
						if (d[y1][xm[id] - 10] == 0)d[y1][xm[id] - 10] = id;
						if (d[y1][xm[id] - 11] == 0)d[y1][xm[id] - 11] = id;
						if (d[y1][xm[id] - 12] == 0)d[y1][xm[id] - 12] = id;
						if (d[y1][xm[id] + 8] == 0)d[y1][xm[id] + 8] = id;
						if (d[y1][xm[id] + 9] == 0)d[y1][xm[id] + 9] = id;
						if (d[y1][xm[id] + 10] == 0)d[y1][xm[id] + 10] = id;
						if (d[y1][xm[id] + 11] == 0)d[y1][xm[id] + 11] = id;
						if (d[y1][xm[id] + 12] == 0)d[y1][xm[id] + 12] = id;
						if (d[y1][xm[id] - 13] == 0)d[y1][xm[id] - 13] = id;
						if (d[y1][xm[id] + 13] == 0)d[y1][xm[id] + 13] = id;
						y1++;//九层
						if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
						if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
						if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
						if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
						if (d[y1][xm[id] + 5] == 0)d[y1][xm[id] + 5] = id;
						if (d[y1][xm[id] - 5] == 0)d[y1][xm[id] - 5] = id;
						if (d[y1][xm[id] - 9] == 0)d[y1][xm[id] - 9] = id;
						if (d[y1][xm[id] + 9] == 0)d[y1][xm[id] + 9] = id;
						if (d[y1][xm[id] + 12] == 0)d[y1][xm[id] + 12] = id;
						if (d[y1][xm[id] - 12] == 0)d[y1][xm[id] - 12] = id;

						if (conmonst[id] < 0)//左
						{
							if (actmonst[id] == 0 || actmonst[id] == 2 || actmonst[id] == 4) { if (d[y1][xm[id] - 20] == 0)d[y1][xm[id] - 20] = id + 1; }
							else if (actmonst[id] == 1)
							{
								if (d[y1][xm[id] - 12] == id)d[y1][xm[id] - 12] = 0;
								if (d[y1][xm[id] - 9] == id)d[y1][xm[id] - 9] = 0;
							}

						}
						else//右
						{
							if (actmonst[id] == 0 || actmonst[id] == 2 || actmonst[id] == 4) {
								if (d[y1][xm[id] + 20] == 0)d[y1][xm[id] + 20] = id + 1;
							}
							else if (actmonst[id] == 1)
							{
								if (d[y1][xm[id] + 12] == id)d[y1][xm[id] + 12] = 0;
								if (d[y1][xm[id] + 9] == id)d[y1][xm[id] + 9] = 0;
							}
						}
						y1++;//10
						if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
						if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;

						if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
						if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
						if (d[y1][xm[id] - 8] == 0)d[y1][xm[id] - 8] = id;
						if (d[y1][xm[id] + 8] == 0)d[y1][xm[id] + 8] = id;
						if (d[y1][xm[id] - 9] == 0)d[y1][xm[id] - 9] = id;
						if (d[y1][xm[id] + 9] == 0)d[y1][xm[id] + 9] = id;
						if (d[y1][xm[id] + 12] == 0)d[y1][xm[id] + 12] = id;
						if (d[y1][xm[id] - 12] == 0)d[y1][xm[id] - 12] = id;
						if (d[y1][xm[id] - 13] == 0)d[y1][xm[id] - 13] = id;
						if (d[y1][xm[id] + 13] == 0)d[y1][xm[id] + 13] = id;

						if (actmonst[id] == 0 || actmonst[id] == 2 || actmonst[id] == 4)
						{
							if (conmonst[id] < 0)//左
							{
								if (d[y1][xm[id] - 20] == 0)d[y1][xm[id] - 20] = id + 1;
								if (d[y1][xm[id] - 21] == 0)d[y1][xm[id] - 21] = id + 1;

							}
							else//右
							{

								if (d[y1][xm[id] + 20] == 0)d[y1][xm[id] + 20] = id + 1;
								if (d[y1][xm[id] + 21] == 0)d[y1][xm[id] + 21] = id + 1;


							}
						}

						if (actmonst[id] == 1)
						{
							if (conmonst[id] < 0) {
								if (d[y1][xm[id] - 12] == id)d[y1][xm[id] - 12] = 0;
								if (d[y1][xm[id] - 9] == id)d[y1][xm[id] - 9] = 0;
								if (d[y1][xm[id] - 13] == id)d[y1][xm[id] - 13] = 0;
								if (d[y1][xm[id] - 8] == id)d[y1][xm[id] - 8] = 0;
							}
							else {

								if (d[y1][xm[id] + 12] == id)d[y1][xm[id] + 12] = 0;
								if (d[y1][xm[id] + 9] == id)d[y1][xm[id] + 9] = 0;
								if (d[y1][xm[id] + 13] == id)d[y1][xm[id] + 13] = 0;
								if (d[y1][xm[id] + 8] == id)d[y1][xm[id] + 8] = 0;
							}
						}
						y1++;//11
						if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
						if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;

						if (d[y1][xm[id] - 7] == 0)d[y1][xm[id] - 7] = id;
						if (d[y1][xm[id] + 7] == 0)d[y1][xm[id] + 7] = id;
						if (d[y1][xm[id] - 8] == 0)d[y1][xm[id] - 8] = id;
						if (d[y1][xm[id] + 8] == 0)d[y1][xm[id] + 8] = id;
						if (d[y1][xm[id] - 9] == 0)d[y1][xm[id] - 9] = id;
						if (d[y1][xm[id] + 9] == 0)d[y1][xm[id] + 9] = id;
						if (d[y1][xm[id] + 10] == 0)d[y1][xm[id] + 10] = id;
						if (d[y1][xm[id] - 10] == 0)d[y1][xm[id] - 10] = id;
						if (d[y1][xm[id] + 11] == 0)d[y1][xm[id] + 11] = id;
						if (d[y1][xm[id] - 11] == 0)d[y1][xm[id] - 11] = id;
						if (d[y1][xm[id] + 12] == 0)d[y1][xm[id] + 12] = id;
						if (d[y1][xm[id] - 12] == 0)d[y1][xm[id] - 12] = id;
						if (d[y1][xm[id] - 13] == 0)d[y1][xm[id] - 13] = id;
						if (d[y1][xm[id] + 13] == 0)d[y1][xm[id] + 13] = id;
						if (d[y1][xm[id] - 14] == 0)d[y1][xm[id] - 14] = id;
						if (d[y1][xm[id] + 14] == 0)d[y1][xm[id] + 14] = id;

						if (actmonst[id] == 0 || actmonst[id] == 2 || actmonst[id] == 4) {


							if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
							if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
							if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
							if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
							if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
							if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
							if (d[y1][xm[id] + 5] == 0)d[y1][xm[id] + 5] = id;
							if (d[y1][xm[id] - 5] == 0)d[y1][xm[id] - 5] = id;
							if (d[y1][xm[id] + 6] == 0)d[y1][xm[id] + 6] = id;
							if (d[y1][xm[id] - 6] == 0)d[y1][xm[id] - 6] = id;


							//右
							if (conmonst[id] < 0)
							{
								if (d[y1][xm[id] - 15] == 0)d[y1][xm[id] - 15] = id + 1;
								if (d[y1][xm[id] - 16] == 0)d[y1][xm[id] - 16] = id + 1;
								if (d[y1][xm[id] - 17] == 0)d[y1][xm[id] - 17] = id + 1;
								if (d[y1][xm[id] - 18] == 0)d[y1][xm[id] - 18] = id + 1;
								if (d[y1][xm[id] - 19] == 0)d[y1][xm[id] - 19] = id + 1;
								if (d[y1][xm[id] - 20] == 0)d[y1][xm[id] - 20] = id + 1;
								if (d[y1][xm[id] - 21] == 0)d[y1][xm[id] - 21] = id + 1;
								if (d[y1][xm[id] - 22] == 0)d[y1][xm[id] - 22] = id + 1;
								if (d[y1][xm[id] - 23] == 0)d[y1][xm[id] - 23] = id + 1;
								if (d[y1][xm[id] - 24] == 0)d[y1][xm[id] - 24] = id + 1;
								if (d[y1][xm[id] - 25] == 0)d[y1][xm[id] - 25] = id + 1;
								if (d[y1][xm[id] - 26] == 0)d[y1][xm[id] - 26] = id + 1;
								if (d[y1][xm[id] - 27] == 0)d[y1][xm[id] - 27] = id + 1;
								if (d[y1][xm[id] - 28] == 0)d[y1][xm[id] - 28] = id + 1;
								if (d[y1][xm[id] - 29] == 0)d[y1][xm[id] - 29] = id + 1;
								if (d[y1][xm[id] - 30] == 0)d[y1][xm[id] - 30] = id + 1;
								if (d[y1][xm[id] - 31] == 0)d[y1][xm[id] - 31] = id + 1;
								if (d[y1][xm[id] - 32] == 0)d[y1][xm[id] - 32] = id + 1;
								if (d[y1][xm[id] - 33] == 0)d[y1][xm[id] - 33] = id + 1;
								if (d[y1][xm[id] - 34] == 0)d[y1][xm[id] - 34] = id + 1;
								if (d[y1][xm[id] - 35] == 0)d[y1][xm[id] - 35] = id + 1;
							}
							else
							{



								if (d[y1][xm[id] + 15] == 0)d[y1][xm[id] + 15] = id + 1;
								if (d[y1][xm[id] + 16] == 0)d[y1][xm[id] + 16] = id + 1;
								if (d[y1][xm[id] + 17] == 0)d[y1][xm[id] + 17] = id + 1;
								if (d[y1][xm[id] + 18] == 0)d[y1][xm[id] + 18] = id + 1;
								if (d[y1][xm[id] + 19] == 0)d[y1][xm[id] + 19] = id + 1;
								if (d[y1][xm[id] + 20] == 0)d[y1][xm[id] + 20] = id + 1;
								if (d[y1][xm[id] + 21] == 0)d[y1][xm[id] + 21] = id + 1;
								if (d[y1][xm[id] + 22] == 0)d[y1][xm[id] + 22] = id + 1;
								if (d[y1][xm[id] + 23] == 0)d[y1][xm[id] + 23] = id + 1;
								if (d[y1][xm[id] + 24] == 0)d[y1][xm[id] + 24] = id + 1;
								if (d[y1][xm[id] + 25] == 0)d[y1][xm[id] + 25] = id + 1;
								if (d[y1][xm[id] + 26] == 0)d[y1][xm[id] + 26] = id + 1;
								if (d[y1][xm[id] + 27] == 0)d[y1][xm[id] + 27] = id + 1;
								if (d[y1][xm[id] + 28] == 0)d[y1][xm[id] + 28] = id + 1;
								if (d[y1][xm[id] + 29] == 0)d[y1][xm[id] + 29] = id + 1;
								if (d[y1][xm[id] + 30] == 0)d[y1][xm[id] + 30] = id + 1;
								if (d[y1][xm[id] + 31] == 0)d[y1][xm[id] + 31] = id + 1;
								if (d[y1][xm[id] + 32] == 0)d[y1][xm[id] + 32] = id + 1;
								if (d[y1][xm[id] + 33] == 0)d[y1][xm[id] + 33] = id + 1;
								if (d[y1][xm[id] + 34] == 0)d[y1][xm[id] + 34] = id + 1;
								if (d[y1][xm[id] + 35] == 0)d[y1][xm[id] + 35] = id + 1;
							}
						}

						if (actmonst[id] == 1)
						{
							if (conmonst[id] < 0) {
								if (d[y1][xm[id] - 12] == id)d[y1][xm[id] - 12] = 0;
								if (d[y1][xm[id] - 9] == id)d[y1][xm[id] - 9] = 0;
								if (d[y1][xm[id] - 13] == id)d[y1][xm[id] - 13] = 0;
								if (d[y1][xm[id] - 8] == id)d[y1][xm[id] - 8] = 0;
								if (d[y1][xm[id] - 10] == id)d[y1][xm[id] - 10] = 0;
								if (d[y1][xm[id] - 11] == id)d[y1][xm[id] - 11] = 0;
								if (d[y1][xm[id] - 7] == id)d[y1][xm[id] - 7] = 0;
								if (d[y1][xm[id] - 14] == id)d[y1][xm[id] - 14] = 0;
							}
							else {

								if (d[y1][xm[id] + 12] == id)d[y1][xm[id] + 12] = 0;
								if (d[y1][xm[id] + 9] == id)d[y1][xm[id] + 9] = 0;
								if (d[y1][xm[id] + 13] == id)d[y1][xm[id] + 13] = 0;
								if (d[y1][xm[id] + 8] == id)d[y1][xm[id] + 8] = 0;
								if (d[y1][xm[id] + 10] == id)d[y1][xm[id] + 10] = 0;
								if (d[y1][xm[id] + 11] == id)d[y1][xm[id] + 11] = 0;
								if (d[y1][xm[id] + 7] == id)d[y1][xm[id] + 7] = 0;
								if (d[y1][xm[id] + 14] == id)d[y1][xm[id] + 14] = 0;
							}
						}




						y1++;//12
						if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
						if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
						if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						if (d[y1][xm[id] - 8] == 0)d[y1][xm[id] - 8] = id;
						if (d[y1][xm[id] + 8] == 0)d[y1][xm[id] + 8] = id;
						if (d[y1][xm[id] - 9] == 0)d[y1][xm[id] - 9] = id;
						if (d[y1][xm[id] + 9] == 0)d[y1][xm[id] + 9] = id;
						if (d[y1][xm[id] + 10] == 0)d[y1][xm[id] + 10] = id;
						if (d[y1][xm[id] - 10] == 0)d[y1][xm[id] - 10] = id;
						if (d[y1][xm[id] + 11] == 0)d[y1][xm[id] + 11] = id;
						if (d[y1][xm[id] - 11] == 0)d[y1][xm[id] - 11] = id;
						if (d[y1][xm[id] + 12] == 0)d[y1][xm[id] + 12] = id;
						if (d[y1][xm[id] - 12] == 0)d[y1][xm[id] - 12] = id;
						if (d[y1][xm[id] - 13] == 0)d[y1][xm[id] - 13] = id;
						//右
						if (conmonst[id] < 0)
						{
							if (actmonst[id] == 0 || actmonst[id] == 2 || actmonst[id] == 4)
							{
								if (d[y1][xm[id] - 20] == 0)d[y1][xm[id] - 20] = id + 1;
								if (d[y1][xm[id] - 21] == 0)d[y1][xm[id] - 21] = id + 1;
								if (d[y1][xm[id] - 24] == 0)d[y1][xm[id] - 24] = id + 1;
								if (d[y1][xm[id] - 25] == 0)d[y1][xm[id] - 25] = id + 1;
								if (d[y1][xm[id] - 26] == 0)d[y1][xm[id] - 26] = id + 1;
								if (d[y1][xm[id] - 27] == 0)d[y1][xm[id] - 27] = id + 1;
								if (d[y1][xm[id] - 28] == 0)d[y1][xm[id] - 28] = id + 1;
								if (d[y1][xm[id] - 29] == 0)d[y1][xm[id] - 29] = id + 1;
								if (d[y1][xm[id] - 30] == 0)d[y1][xm[id] - 30] = id + 1;
								if (d[y1][xm[id] - 31] == 0)d[y1][xm[id] - 31] = id + 1;
								if (d[y1][xm[id] - 32] == 0)d[y1][xm[id] - 32] = id + 1;
								if (d[y1][xm[id] - 33] == 0)d[y1][xm[id] - 33] = id + 1;
							}
						}
						else//左
						{
							if (actmonst[id] == 0 || actmonst[id] == 2 || actmonst[id] == 4)
							{
								if (d[y1][xm[id] + 20] == 0)d[y1][xm[id] + 20] = id + 1;
								if (d[y1][xm[id] + 21] == 0)d[y1][xm[id] + 21] = id + 1;
								if (d[y1][xm[id] + 24] == 0)d[y1][xm[id] + 24] = id + 1;
								if (d[y1][xm[id] + 25] == 0)d[y1][xm[id] + 25] = id + 1;
								if (d[y1][xm[id] + 26] == 0)d[y1][xm[id] + 26] = id + 1;
								if (d[y1][xm[id] + 27] == 0)d[y1][xm[id] + 27] = id + 1;
								if (d[y1][xm[id] + 28] == 0)d[y1][xm[id] + 28] = id + 1;
								if (d[y1][xm[id] + 29] == 0)d[y1][xm[id] + 29] = id + 1;
								if (d[y1][xm[id] + 30] == 0)d[y1][xm[id] + 30] = id + 1;
								if (d[y1][xm[id] + 31] == 0)d[y1][xm[id] + 31] = id + 1;
								if (d[y1][xm[id] + 32] == 0)d[y1][xm[id] + 32] = id + 1;
								if (d[y1][xm[id] + 33] == 0)d[y1][xm[id] + 33] = id + 1;
							}
						}
						if (actmonst[id] == 1)
						{
							if (conmonst[id] < 0) {
								if (d[y1][xm[id] - 12] == id)d[y1][xm[id] - 12] = 0;
								if (d[y1][xm[id] - 9] == id)d[y1][xm[id] - 9] = 0;
								if (d[y1][xm[id] - 13] == id)d[y1][xm[id] - 13] = 0;
								if (d[y1][xm[id] - 8] == id)d[y1][xm[id] - 8] = 0;
								if (d[y1][xm[id] - 10] == id)d[y1][xm[id] - 10] = 0;
								if (d[y1][xm[id] - 11] == id)d[y1][xm[id] - 11] = 0;
							}
							else {

								if (d[y1][xm[id] + 12] == id)d[y1][xm[id] + 12] = 0;
								if (d[y1][xm[id] + 9] == id)d[y1][xm[id] + 9] = 0;
								if (d[y1][xm[id] + 13] == id)d[y1][xm[id] + 13] = 0;
								if (d[y1][xm[id] + 8] == id)d[y1][xm[id] + 8] = 0;
								if (d[y1][xm[id] + 10] == id)d[y1][xm[id] + 10] = 0;
								if (d[y1][xm[id] + 11] == id)d[y1][xm[id] + 11] = 0;
							}
						}
						y1++;//13
						if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
						if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
						if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
						//右
						if (conmonst[id] < 0)
						{
							if (actmonst[id] == 0 || actmonst[id] == 2 || actmonst[id] == 4) {
								if (d[y1][xm[id] - 20] == 0)d[y1][xm[id] - 20] = id + 1;
								if (d[y1][xm[id] - 24] == 0)d[y1][xm[id] - 24] = id + 1;
								if (d[y1][xm[id] - 25] == 0)d[y1][xm[id] - 25] = id + 1;
								if (d[y1][xm[id] - 26] == 0)d[y1][xm[id] - 26] = id + 1;
								if (d[y1][xm[id] - 27] == 0)d[y1][xm[id] - 27] = id + 1;
								if (d[y1][xm[id] - 28] == 0)d[y1][xm[id] - 28] = id + 1;
								if (d[y1][xm[id] - 29] == 0)d[y1][xm[id] - 29] = id + 1;
							}
						}
						else//左
						{
							if (actmonst[id] == 0 || actmonst[id] == 2 || actmonst[id] == 4)
							{
								if (d[y1][xm[id] + 20] == 0)d[y1][xm[id] + 20] = id + 1;
								if (d[y1][xm[id] + 24] == 0)d[y1][xm[id] + 24] = id + 1;
								if (d[y1][xm[id] + 25] == 0)d[y1][xm[id] + 25] = id + 1;
								if (d[y1][xm[id] + 26] == 0)d[y1][xm[id] + 26] = id + 1;
								if (d[y1][xm[id] + 27] == 0)d[y1][xm[id] + 27] = id + 1;
								if (d[y1][xm[id] + 28] == 0)d[y1][xm[id] + 28] = id + 1;
								if (d[y1][xm[id] + 29] == 0)d[y1][xm[id] + 29] = id + 1;
							}
						}
						y1++;//14
						if (d[y1][xm[id]] == 0)d[y1][xm[id]] = id;
						if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
						if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
						if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
						if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
						y1++;//15
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
						if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
						if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
						y1++;//16
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
						if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
						if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
						y1++;//17
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
						if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
						if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
						y1++;//18
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
						if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
						if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
						//右
						if (conmonst[id] < 0)
						{
							if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
							if (d[y1][xm[id] - 5] == 0)d[y1][xm[id] - 5] = id;
						}
						else//左 
						{
							if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
							if (d[y1][xm[id] + 5] == 0)d[y1][xm[id] + 5] = id;
						}
						y1++;//19
						if (d[y1][xm[id] + 2] == 0)d[y1][xm[id] + 2] = id;
						if (d[y1][xm[id] - 2] == 0)d[y1][xm[id] - 2] = id;
						if (d[y1][xm[id] + 3] == 0)d[y1][xm[id] + 3] = id;
						if (d[y1][xm[id] - 3] == 0)d[y1][xm[id] - 3] = id;
						if (d[y1][xm[id] + 4] == 0)d[y1][xm[id] + 4] = id;
						if (d[y1][xm[id] - 4] == 0)d[y1][xm[id] - 4] = id;
						//右
						if (conmonst[id] < 0)
						{
							if (d[y1][xm[id] + 1] == 0)d[y1][xm[id] + 1] = id;
							if (d[y1][xm[id] - 5] == 0)d[y1][xm[id] - 5] = id;
						}
						else//左 
						{
							if (d[y1][xm[id] - 1] == 0)d[y1][xm[id] - 1] = id;
							if (d[y1][xm[id] + 5] == 0)d[y1][xm[id] + 5] = id;
						}
					}
					if (actmonst[id] == 1)//持有的武器
					{
						yfork = ym[id];
						xfork = xm[id];
						yfork -= 2;
						if (conmonst[id] > 0)
						{
							//右

							if (d[yfork][xfork + 34] == 0)d[yfork][xfork + 34] = id + 1;
							if (d[yfork][xfork + 33] == 0)d[yfork][xfork + 33] = id + 1;
							if (d[yfork][xfork + 32] == 0)d[yfork][xfork + 32] = id + 1;
							if (d[yfork][xfork + 31] == 0)d[yfork][xfork + 31] = id + 1;
							yfork++;
							//右
							if (d[yfork][xfork + 34] == 0)d[yfork][xfork + 34] = id + 1;
							if (d[yfork][xfork + 32] == 0)d[yfork][xfork + 32] = id + 1;
							if (d[yfork][xfork + 31] == 0)d[yfork][xfork + 31] = id + 1;
							if (d[yfork][xfork + 30] == 0)d[yfork][xfork + 30] = id + 1;
							if (d[yfork][xfork + 29] == 0)d[yfork][xfork + 29] = id + 1;
							if (d[yfork][xfork + 28] == 0)d[yfork][xfork + 28] = id + 1;
							yfork++;
							if (d[yfork][xfork + 34] == 0)d[yfork][xfork + 34] = id + 1;//33
							if (d[yfork][xfork + 33] == 0)d[yfork][xfork + 33] = id + 1;//32
							if (d[yfork][xfork + 32] == 0)d[yfork][xfork + 32] = id + 1;//31
							if (d[yfork][xfork + 31] == 0)d[yfork][xfork + 31] = id + 1;//30
							if (d[yfork][xfork + 30] == 0)d[yfork][xfork + 30] = id + 1;//29
							if (d[yfork][xfork + 29] == 0)d[yfork][xfork + 29] = id + 1;//28
							if (d[yfork][xfork + 28] == 0)d[yfork][xfork + 28] = id + 1;//27
							if (d[yfork][xfork + 27] == 0)d[yfork][xfork + 27] = id + 1;//26
							if (d[yfork][xfork + 26] == 0)d[yfork][xfork + 26] = id + 1;//25
							if (d[yfork][xfork + 25] == 0)d[yfork][xfork + 25] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 33] == 0)d[yfork][xfork + 33] = id + 1;//32
							if (d[yfork][xfork + 32] == 0)d[yfork][xfork + 32] = id + 1;//31
							if (d[yfork][xfork + 31] == 0)d[yfork][xfork + 31] = id + 1;//30
							if (d[yfork][xfork + 30] == 0)d[yfork][xfork + 30] = id + 1;//29
							if (d[yfork][xfork + 29] == 0)d[yfork][xfork + 29] = id + 1;//28
							if (d[yfork][xfork + 28] == 0)d[yfork][xfork + 28] = id + 1;//27
							if (d[yfork][xfork + 27] == 0)d[yfork][xfork + 27] = id + 1;//26
							if (d[yfork][xfork + 26] == 0)d[yfork][xfork + 26] = id + 1;//24
							if (d[yfork][xfork + 24] == 0)d[yfork][xfork + 24] = id + 1;//23
							if (d[yfork][xfork + 23] == 0)d[yfork][xfork + 23] = id + 1;//22
							if (d[yfork][xfork + 22] == 0)d[yfork][xfork + 22] = id + 1;//21
							if (d[yfork][xfork + 21] == 0)d[yfork][xfork + 21] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 31] == 0)d[yfork][xfork + 31] = id + 1;//30
							if (d[yfork][xfork + 30] == 0)d[yfork][xfork + 30] = id + 1;//29
							if (d[yfork][xfork + 29] == 0)d[yfork][xfork + 29] = id + 1;//28
							if (d[yfork][xfork + 28] == 0)d[yfork][xfork + 28] = id + 1;//27
							if (d[yfork][xfork + 27] == 0)d[yfork][xfork + 27] = id + 1;//26
							if (d[yfork][xfork + 26] == 0)d[yfork][xfork + 26] = id + 1;//25
							if (d[yfork][xfork + 25] == 0)d[yfork][xfork + 25] = id + 1;//24
							if (d[yfork][xfork + 24] == 0)d[yfork][xfork + 24] = id + 1;//23
							if (d[yfork][xfork + 23] == 0)d[yfork][xfork + 23] = id + 1;//22
							if (d[yfork][xfork + 22] == 0)d[yfork][xfork + 22] = id + 1;//21
							if (d[yfork][xfork + 21] == 0)d[yfork][xfork + 21] = id + 1;//20
							if (d[yfork][xfork + 20] == 0)d[yfork][xfork + 20] = id + 1;//19
							if (d[yfork][xfork + 19] == 0)d[yfork][xfork + 19] = id + 1;//18
							if (d[yfork][xfork + 18] == 0)d[yfork][xfork + 18] = id + 1;//17
							if (d[yfork][xfork + 17] == 0)d[yfork][xfork + 17] = id + 1;//16
							if (d[yfork][xfork + 16] == 0)d[yfork][xfork + 16] = id + 1;//15
							if (d[yfork][xfork + 15] == 0)d[yfork][xfork + 15] = id + 1;//14
							if (d[yfork][xfork + 14] == 0)d[yfork][xfork + 14] = id + 1;//13
							if (d[yfork][xfork + 13] == 0)d[yfork][xfork + 13] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 26] == 0)d[yfork][xfork + 26] = id + 1;//25
							if (d[yfork][xfork + 25] == 0)d[yfork][xfork + 25] = id + 1;//24
							if (d[yfork][xfork + 24] == 0)d[yfork][xfork + 24] = id + 1;//23
							if (d[yfork][xfork + 23] == 0)d[yfork][xfork + 23] = id + 1;//21
							if (d[yfork][xfork + 21] == 0)d[yfork][xfork + 21] = id + 1;//20
							if (d[yfork][xfork + 20] == 0)d[yfork][xfork + 20] = id + 1;//19
							if (d[yfork][xfork + 19] == 0)d[yfork][xfork + 19] = id + 1;//18
							if (d[yfork][xfork + 18] == 0)d[yfork][xfork + 18] = id + 1;//17
							if (d[yfork][xfork + 17] == 0)d[yfork][xfork + 17] = id + 1;//16
							if (d[yfork][xfork + 16] == 0)d[yfork][xfork + 16] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 14] == 0)d[yfork][xfork + 14] = id + 1;//15
							if (d[yfork][xfork + 15] == 0)d[yfork][xfork + 15] = id + 1;//16
							if (d[yfork][xfork + 16] == 0)d[yfork][xfork + 16] = id + 1;//18
							if (d[yfork][xfork + 18] == 0)d[yfork][xfork + 18] = id + 1;//19
							if (d[yfork][xfork + 19] == 0)d[yfork][xfork + 19] = id + 1;//20
							if (d[yfork][xfork + 20] == 0)d[yfork][xfork + 20] = id + 1;//21
							if (d[yfork][xfork + 21] == 0)d[yfork][xfork + 21] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 10] == 0)d[yfork][xfork + 10] = id + 1;//11
							if (d[yfork][xfork + 11] == 0)d[yfork][xfork + 11] = id + 1;//12
							if (d[yfork][xfork + 12] == 0)d[yfork][xfork + 12] = id + 1;//20
							if (d[yfork][xfork + 20] == 0)d[yfork][xfork + 20] = id + 1;//21
							if (d[yfork][xfork + 21] == 0)d[yfork][xfork + 21] = id + 1;//22
							if (d[yfork][xfork + 22] == 0)d[yfork][xfork + 22] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 8] == 0)d[yfork][xfork + 8] = id + 1;//9
							if (d[yfork][xfork + 9] == 0)d[yfork][xfork + 9] = id + 1;//10
							if (d[yfork][xfork + 10] == 0)d[yfork][xfork + 10] = id + 1;//22
							if (d[yfork][xfork + 22] == 0)d[yfork][xfork + 22] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 7] == 0)d[yfork][xfork + 7] = id + 1;//
							yfork++;

						}
						else
						{
							//左

							if (d[yfork][xfork - 34] == 0)d[yfork][xfork - 34] = id + 1;
							if (d[yfork][xfork - 33] == 0)d[yfork][xfork - 33] = id + 1;
							if (d[yfork][xfork - 32] == 0)d[yfork][xfork - 32] = id + 1;
							if (d[yfork][xfork - 31] == 0)d[yfork][xfork - 31] = id + 1;
							yfork++;
							//右
							if (d[yfork][xfork - 34] == 0)d[yfork][xfork - 34] = id + 1;
							if (d[yfork][xfork - 32] == 0)d[yfork][xfork - 32] = id + 1;
							if (d[yfork][xfork - 31] == 0)d[yfork][xfork - 31] = id + 1;
							if (d[yfork][xfork - 30] == 0)d[yfork][xfork - 30] = id + 1;
							if (d[yfork][xfork - 29] == 0)d[yfork][xfork - 29] = id + 1;
							if (d[yfork][xfork - 28] == 0)d[yfork][xfork - 28] = id + 1;
							yfork++;
							if (d[yfork][xfork - 34] == 0)d[yfork][xfork - 34] = id + 1;//33
							if (d[yfork][xfork - 33] == 0)d[yfork][xfork - 33] = id + 1;//32
							if (d[yfork][xfork - 32] == 0)d[yfork][xfork - 32] = id + 1;//31
							if (d[yfork][xfork - 31] == 0)d[yfork][xfork - 31] = id + 1;//30
							if (d[yfork][xfork - 30] == 0)d[yfork][xfork - 30] = id + 1;//29
							if (d[yfork][xfork - 29] == 0)d[yfork][xfork - 29] = id + 1;//28
							if (d[yfork][xfork - 28] == 0)d[yfork][xfork - 28] = id + 1;//27
							if (d[yfork][xfork - 27] == 0)d[yfork][xfork - 27] = id + 1;//26
							if (d[yfork][xfork - 26] == 0)d[yfork][xfork - 26] = id + 1;//25
							if (d[yfork][xfork - 25] == 0)d[yfork][xfork - 25] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 33] == 0)d[yfork][xfork - 33] = id + 1;//32
							if (d[yfork][xfork - 32] == 0)d[yfork][xfork - 32] = id + 1;//31
							if (d[yfork][xfork - 31] == 0)d[yfork][xfork - 31] = id + 1;//30
							if (d[yfork][xfork - 30] == 0)d[yfork][xfork - 30] = id + 1;//29
							if (d[yfork][xfork - 29] == 0)d[yfork][xfork - 29] = id + 1;//28
							if (d[yfork][xfork - 28] == 0)d[yfork][xfork - 28] = id + 1;//27
							if (d[yfork][xfork - 27] == 0)d[yfork][xfork - 27] = id + 1;//26
							if (d[yfork][xfork - 26] == 0)d[yfork][xfork - 26] = id + 1;//24
							if (d[yfork][xfork - 24] == 0)d[yfork][xfork - 24] = id + 1;//23
							if (d[yfork][xfork - 23] == 0)d[yfork][xfork - 23] = id + 1;//22
							if (d[yfork][xfork - 22] == 0)d[yfork][xfork - 22] = id + 1;//21
							if (d[yfork][xfork - 21] == 0)d[yfork][xfork - 21] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 31] == 0)d[yfork][xfork - 31] = id + 1;//30
							if (d[yfork][xfork - 30] == 0)d[yfork][xfork - 30] = id + 1;//29
							if (d[yfork][xfork - 29] == 0)d[yfork][xfork - 29] = id + 1;//28
							if (d[yfork][xfork - 28] == 0)d[yfork][xfork - 28] = id + 1;//27
							if (d[yfork][xfork - 27] == 0)d[yfork][xfork - 27] = id + 1;//26
							if (d[yfork][xfork - 26] == 0)d[yfork][xfork - 26] = id + 1;//25
							if (d[yfork][xfork - 25] == 0)d[yfork][xfork - 25] = id + 1;//24
							if (d[yfork][xfork - 24] == 0)d[yfork][xfork - 24] = id + 1;//23
							if (d[yfork][xfork - 23] == 0)d[yfork][xfork - 23] = id + 1;//22
							if (d[yfork][xfork - 22] == 0)d[yfork][xfork - 22] = id + 1;//21
							if (d[yfork][xfork - 21] == 0)d[yfork][xfork - 21] = id + 1;//20
							if (d[yfork][xfork - 20] == 0)d[yfork][xfork - 20] = id + 1;//19
							if (d[yfork][xfork - 19] == 0)d[yfork][xfork - 19] = id + 1;//18
							if (d[yfork][xfork - 18] == 0)d[yfork][xfork - 18] = id + 1;//17
							if (d[yfork][xfork - 17] == 0)d[yfork][xfork - 17] = id + 1;//16
							if (d[yfork][xfork - 16] == 0)d[yfork][xfork - 16] = id + 1;//15
							if (d[yfork][xfork - 15] == 0)d[yfork][xfork - 15] = id + 1;//14
							if (d[yfork][xfork - 14] == 0)d[yfork][xfork - 14] = id + 1;//13
							if (d[yfork][xfork - 13] == 0)d[yfork][xfork - 13] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 26] == 0)d[yfork][xfork - 26] = id + 1;//25
							if (d[yfork][xfork - 25] == 0)d[yfork][xfork - 25] = id + 1;//24
							if (d[yfork][xfork - 24] == 0)d[yfork][xfork - 24] = id + 1;//23
							if (d[yfork][xfork - 23] == 0)d[yfork][xfork - 23] = id + 1;//21
							if (d[yfork][xfork - 21] == 0)d[yfork][xfork - 21] = id + 1;//20
							if (d[yfork][xfork - 20] == 0)d[yfork][xfork - 20] = id + 1;//19
							if (d[yfork][xfork - 19] == 0)d[yfork][xfork - 19] = id + 1;//18
							if (d[yfork][xfork - 18] == 0)d[yfork][xfork - 18] = id + 1;//17
							if (d[yfork][xfork - 17] == 0)d[yfork][xfork - 17] = id + 1;//16
							if (d[yfork][xfork - 16] == 0)d[yfork][xfork - 16] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 14] == 0)d[yfork][xfork - 14] = id + 1;//15
							if (d[yfork][xfork - 15] == 0)d[yfork][xfork - 15] = id + 1;//16
							if (d[yfork][xfork - 16] == 0)d[yfork][xfork - 16] = id + 1;//18
							if (d[yfork][xfork - 18] == 0)d[yfork][xfork - 18] = id + 1;//19
							if (d[yfork][xfork - 19] == 0)d[yfork][xfork - 19] = id + 1;//20
							if (d[yfork][xfork - 20] == 0)d[yfork][xfork - 20] = id + 1;//21
							if (d[yfork][xfork - 21] == 0)d[yfork][xfork - 21] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 10] == 0)d[yfork][xfork - 10] = id + 1;//11
							if (d[yfork][xfork - 11] == 0)d[yfork][xfork - 11] = id + 1;//12
							if (d[yfork][xfork - 12] == 0)d[yfork][xfork - 12] = id + 1;//20
							if (d[yfork][xfork - 20] == 0)d[yfork][xfork - 20] = id + 1;//21
							if (d[yfork][xfork - 21] == 0)d[yfork][xfork - 21] = id + 1;//22
							if (d[yfork][xfork - 22] == 0)d[yfork][xfork - 22] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 8] == 0)d[yfork][xfork - 8] = id + 1;//9
							if (d[yfork][xfork - 9] == 0)d[yfork][xfork - 9] = id + 1;//10
							if (d[yfork][xfork - 10] == 0)d[yfork][xfork - 10] = id + 1;//22
							if (d[yfork][xfork - 22] == 0)d[yfork][xfork - 22] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 7] == 0)d[yfork][xfork - 7] = id + 1;//
							yfork++;
						}
					}
					if (actmonst[id] == 3)//持有的武器
					{
						yfork = ym[id] + 8;
						xfork = xm[id];

						if (conmonst[id] > 0)
						{
							if (d[yfork][xfork - 14] == 0)d[yfork][xfork - 14] = id + 1;//15
							if (d[yfork][xfork - 15] == 0)d[yfork][xfork - 15] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 11] == 0)d[yfork][xfork - 11] = id + 1;//10
							if (d[yfork][xfork - 10] == 0)d[yfork][xfork - 10] = id + 1;//14
							if (d[yfork][xfork - 14] == 0)d[yfork][xfork - 14] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 3] == 0)d[yfork][xfork - 3] = id + 1;//4
							if (d[yfork][xfork - 4] == 0)d[yfork][xfork - 4] = id + 1;//5
							if (d[yfork][xfork - 5] == 0)d[yfork][xfork - 5] = id + 1;//6
							if (d[yfork][xfork - 6] == 0)d[yfork][xfork - 6] = id + 1;//7
							if (d[yfork][xfork - 7] == 0)d[yfork][xfork - 7] = id + 1;//8
							if (d[yfork][xfork - 8] == 0)d[yfork][xfork - 8] = id + 1;//9
							if (d[yfork][xfork - 9] == 0)d[yfork][xfork - 9] = id + 1;//10
							if (d[yfork][xfork - 10] == 0)d[yfork][xfork - 10] = id + 1;//11
							if (d[yfork][xfork - 11] == 0)d[yfork][xfork - 11] = id + 1;//12
							if (d[yfork][xfork - 12] == 0)d[yfork][xfork - 12] = id + 1;//13
							if (d[yfork][xfork - 13] == 0)d[yfork][xfork - 13] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 3] == 0)d[yfork][xfork - 3] = id + 1;//
							if (d[yfork][xfork + 3] == 0)d[yfork][xfork + 3] = id + 1;//-3
							if (d[yfork][xfork + 25] == 0)d[yfork][xfork + 25] = id + 1;//
							yfork++;

							if (d[yfork][xfork + 5] == 0)d[yfork][xfork + 5] = id + 1;//7
							if (d[yfork][xfork + 7] == 0)d[yfork][xfork + 7] = id + 1;//8
							if (d[yfork][xfork + 8] == 0)d[yfork][xfork + 8] = id + 1;//9
							if (d[yfork][xfork + 9] == 0)d[yfork][xfork + 9] = id + 1;//10
							if (d[yfork][xfork + 10] == 0)d[yfork][xfork + 10] = id + 1;//11
							if (d[yfork][xfork + 11] == 0)d[yfork][xfork + 11] = id + 1;//12
							if (d[yfork][xfork + 12] == 0)d[yfork][xfork + 12] = id + 1;//13
							if (d[yfork][xfork + 13] == 0)d[yfork][xfork + 13] = id + 1;//14
							if (d[yfork][xfork + 14] == 0)d[yfork][xfork + 14] = id + 1;//
							if (d[yfork][xfork + 24] == 0)d[yfork][xfork + 24] = id + 1;//25
							if (d[yfork][xfork + 25] == 0)d[yfork][xfork + 25] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 9] == 0)d[yfork][xfork + 9] = id + 1;//10
							if (d[yfork][xfork + 10] == 0)d[yfork][xfork + 10] = id + 1;//11
							if (d[yfork][xfork + 11] == 0)d[yfork][xfork + 11] = id + 1;//12
							if (d[yfork][xfork + 12] == 0)d[yfork][xfork + 12] = id + 1;//13
							if (d[yfork][xfork + 13] == 0)d[yfork][xfork + 13] = id + 1;//14
							if (d[yfork][xfork + 14] == 0)d[yfork][xfork + 14] = id + 1;//15
							if (d[yfork][xfork + 15] == 0)d[yfork][xfork + 15] = id + 1;//16
							if (d[yfork][xfork + 16] == 0)d[yfork][xfork + 16] = id + 1;//17
							if (d[yfork][xfork + 17] == 0)d[yfork][xfork + 17] = id + 1;//18
							if (d[yfork][xfork + 18] == 0)d[yfork][xfork + 18] = id + 1;//19
							if (d[yfork][xfork + 19] == 0)d[yfork][xfork + 19] = id + 1;//20
							if (d[yfork][xfork + 20] == 0)d[yfork][xfork + 20] = id + 1;//21
							if (d[yfork][xfork + 21] == 0)d[yfork][xfork + 21] = id + 1;//
							if (d[yfork][xfork + 23] == 0)d[yfork][xfork + 23] = id + 1;//24
							if (d[yfork][xfork + 24] == 0)d[yfork][xfork + 24] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 20] == 0)d[yfork][xfork + 20] = id + 1;//21
							if (d[yfork][xfork + 21] == 0)d[yfork][xfork + 21] = id + 1;//22
							if (d[yfork][xfork + 22] == 0)d[yfork][xfork + 22] = id + 1;//23
							if (d[yfork][xfork + 23] == 0)d[yfork][xfork + 23] = id + 1;//24
							if (d[yfork][xfork + 24] == 0)d[yfork][xfork + 24] = id + 1;//25
							if (d[yfork][xfork + 25] == 0)d[yfork][xfork + 25] = id + 1;//26
							if (d[yfork][xfork + 26] == 0)d[yfork][xfork + 26] = id + 1;//27
							if (d[yfork][xfork + 27] == 0)d[yfork][xfork + 27] = id + 1;//28
							if (d[yfork][xfork + 28] == 0)d[yfork][xfork + 28] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 20] == 0)d[yfork][xfork + 20] = id + 1;//21
							if (d[yfork][xfork + 21] == 0)d[yfork][xfork + 21] = id + 1;//
							if (d[yfork][xfork + 23] == 0)d[yfork][xfork + 23] = id + 1;//24
							if (d[yfork][xfork + 24] == 0)d[yfork][xfork + 24] = id + 1;//25
							if (d[yfork][xfork + 25] == 0)d[yfork][xfork + 25] = id + 1;//26
							if (d[yfork][xfork + 26] == 0)d[yfork][xfork + 26] = id + 1;//27
							if (d[yfork][xfork + 27] == 0)d[yfork][xfork + 27] = id + 1;//28
							if (d[yfork][xfork + 28] == 0)d[yfork][xfork + 28] = id + 1;//29
							if (d[yfork][xfork + 29] == 0)d[yfork][xfork + 29] = id + 1;//30
							if (d[yfork][xfork + 30] == 0)d[yfork][xfork + 30] = id + 1;//31
							if (d[yfork][xfork + 31] == 0)d[yfork][xfork + 31] = id + 1;//32
							if (d[yfork][xfork + 32] == 0)d[yfork][xfork + 32] = id + 1;//33
							if (d[yfork][xfork + 33] == 0)d[yfork][xfork + 33] = id + 1;//34
							if (d[yfork][xfork + 34] == 0)d[yfork][xfork + 34] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 18] == 0)d[yfork][xfork + 18] = id + 1;//19
							if (d[yfork][xfork + 19] == 0)d[yfork][xfork + 19] = id + 1;//20
							if (d[yfork][xfork + 20] == 0)d[yfork][xfork + 20] = id + 1;//
							if (d[yfork][xfork + 25] == 0)d[yfork][xfork + 25] = id + 1;//26
							if (d[yfork][xfork + 26] == 0)d[yfork][xfork + 26] = id + 1;//27
							if (d[yfork][xfork + 27] == 0)d[yfork][xfork + 27] = id + 1;//28
							if (d[yfork][xfork + 28] == 0)d[yfork][xfork + 28] = id + 1;//29
							if (d[yfork][xfork + 29] == 0)d[yfork][xfork + 29] = id + 1;//30
							if (d[yfork][xfork + 30] == 0)d[yfork][xfork + 30] = id + 1;//31
							if (d[yfork][xfork + 31] == 0)d[yfork][xfork + 31] = id + 1;//32
							if (d[yfork][xfork + 32] == 0)d[yfork][xfork + 32] = id + 1;//
							if (d[yfork][xfork + 34] == 0)d[yfork][xfork + 34] = id + 1;//35
							if (d[yfork][xfork + 35] == 0)d[yfork][xfork + 35] = id + 1;//36
							if (d[yfork][xfork + 36] == 0)d[yfork][xfork + 36] = id + 1;//37
							if (d[yfork][xfork + 37] == 0)d[yfork][xfork + 37] = id + 1;//38
							if (d[yfork][xfork + 38] == 0)d[yfork][xfork + 38] = id + 1;//39
							if (d[yfork][xfork + 39] == 0)d[yfork][xfork + 39] = id + 1;//40
							if (d[yfork][xfork + 40] == 0)d[yfork][xfork + 40] = id + 1;//41
							if (d[yfork][xfork + 41] == 0)d[yfork][xfork + 41] = id + 1;//42
							if (d[yfork][xfork + 42] == 0)d[yfork][xfork + 42] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 28] == 0)d[yfork][xfork + 28] = id + 1;//29
							if (d[yfork][xfork + 29] == 0)d[yfork][xfork + 29] = id + 1;//30
							if (d[yfork][xfork + 30] == 0)d[yfork][xfork + 30] = id + 1;//31
							if (d[yfork][xfork + 31] == 0)d[yfork][xfork + 31] = id + 1;//32
							if (d[yfork][xfork + 32] == 0)d[yfork][xfork + 32] = id + 1;//33
							if (d[yfork][xfork + 33] == 0)d[yfork][xfork + 33] = id + 1;//34
							if (d[yfork][xfork + 34] == 0)d[yfork][xfork + 34] = id + 1;//35
							if (d[yfork][xfork + 35] == 0)d[yfork][xfork + 35] = id + 1;//36
							if (d[yfork][xfork + 36] == 0)d[yfork][xfork + 36] = id + 1;//37
							if (d[yfork][xfork + 37] == 0)d[yfork][xfork + 37] = id + 1;//38
							if (d[yfork][xfork + 38] == 0)d[yfork][xfork + 38] = id + 1;//39
							if (d[yfork][xfork + 39] == 0)d[yfork][xfork + 39] = id + 1;//40
							if (d[yfork][xfork + 40] == 0)d[yfork][xfork + 40] = id + 1;//41
							if (d[yfork][xfork + 41] == 0)d[yfork][xfork + 41] = id + 1;//42
							if (d[yfork][xfork + 42] == 0)d[yfork][xfork + 42] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 35] == 0)d[yfork][xfork + 35] = id + 1;//36
							if (d[yfork][xfork + 36] == 0)d[yfork][xfork + 36] = id + 1;//37
							if (d[yfork][xfork + 37] == 0)d[yfork][xfork + 37] = id + 1;//38
							if (d[yfork][xfork + 38] == 0)d[yfork][xfork + 38] = id + 1;//

						}
						else
						{
							if (d[yfork][xfork + 14] == 0)d[yfork][xfork + 14] = id + 1;//15
							if (d[yfork][xfork + 15] == 0)d[yfork][xfork + 15] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 11] == 0)d[yfork][xfork + 11] = id + 1;//10
							if (d[yfork][xfork + 10] == 0)d[yfork][xfork + 10] = id + 1;//14
							if (d[yfork][xfork + 14] == 0)d[yfork][xfork + 14] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 3] == 0)d[yfork][xfork + 3] = id + 1;//4
							if (d[yfork][xfork + 4] == 0)d[yfork][xfork + 4] = id + 1;//5
							if (d[yfork][xfork + 5] == 0)d[yfork][xfork + 5] = id + 1;//6
							if (d[yfork][xfork + 6] == 0)d[yfork][xfork + 6] = id + 1;//7
							if (d[yfork][xfork + 7] == 0)d[yfork][xfork + 7] = id + 1;//8
							if (d[yfork][xfork + 8] == 0)d[yfork][xfork + 8] = id + 1;//9
							if (d[yfork][xfork + 9] == 0)d[yfork][xfork + 9] = id + 1;//10
							if (d[yfork][xfork + 10] == 0)d[yfork][xfork + 10] = id + 1;//11
							if (d[yfork][xfork + 11] == 0)d[yfork][xfork + 11] = id + 1;//12
							if (d[yfork][xfork + 12] == 0)d[yfork][xfork + 12] = id + 1;//13
							if (d[yfork][xfork + 13] == 0)d[yfork][xfork + 13] = id + 1;//
							yfork++;
							if (d[yfork][xfork + 3] == 0)d[yfork][xfork + 3] = id + 1;//
							if (d[yfork][xfork - 3] == 0)d[yfork][xfork - 3] = id + 1;//-3
							if (d[yfork][xfork - 25] == 0)d[yfork][xfork - 25] = id + 1;//
							yfork++;

							if (d[yfork][xfork - 5] == 0)d[yfork][xfork - 5] = id + 1;//7
							if (d[yfork][xfork - 7] == 0)d[yfork][xfork - 7] = id + 1;//8
							if (d[yfork][xfork - 8] == 0)d[yfork][xfork - 8] = id + 1;//9
							if (d[yfork][xfork - 9] == 0)d[yfork][xfork - 9] = id + 1;//10
							if (d[yfork][xfork - 10] == 0)d[yfork][xfork - 10] = id + 1;//11
							if (d[yfork][xfork - 11] == 0)d[yfork][xfork - 11] = id + 1;//12
							if (d[yfork][xfork - 12] == 0)d[yfork][xfork - 12] = id + 1;//13
							if (d[yfork][xfork - 13] == 0)d[yfork][xfork - 13] = id + 1;//14
							if (d[yfork][xfork - 14] == 0)d[yfork][xfork - 14] = id + 1;//
							if (d[yfork][xfork - 24] == 0)d[yfork][xfork - 24] = id + 1;//25
							if (d[yfork][xfork - 25] == 0)d[yfork][xfork - 25] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 9] == 0)d[yfork][xfork - 9] = id + 1;//10
							if (d[yfork][xfork - 10] == 0)d[yfork][xfork - 10] = id + 1;//11
							if (d[yfork][xfork - 11] == 0)d[yfork][xfork - 11] = id + 1;//12
							if (d[yfork][xfork - 12] == 0)d[yfork][xfork - 12] = id + 1;//13
							if (d[yfork][xfork - 13] == 0)d[yfork][xfork - 13] = id + 1;//14
							if (d[yfork][xfork - 14] == 0)d[yfork][xfork - 14] = id + 1;//15
							if (d[yfork][xfork - 15] == 0)d[yfork][xfork - 15] = id + 1;//16
							if (d[yfork][xfork - 16] == 0)d[yfork][xfork - 16] = id + 1;//17
							if (d[yfork][xfork - 17] == 0)d[yfork][xfork - 17] = id + 1;//18
							if (d[yfork][xfork - 18] == 0)d[yfork][xfork - 18] = id + 1;//19
							if (d[yfork][xfork - 19] == 0)d[yfork][xfork - 19] = id + 1;//20
							if (d[yfork][xfork - 20] == 0)d[yfork][xfork - 20] = id + 1;//21
							if (d[yfork][xfork - 21] == 0)d[yfork][xfork - 21] = id + 1;//
							if (d[yfork][xfork - 23] == 0)d[yfork][xfork - 23] = id + 1;//24
							if (d[yfork][xfork - 24] == 0)d[yfork][xfork - 24] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 20] == 0)d[yfork][xfork - 20] = id + 1;//21
							if (d[yfork][xfork - 21] == 0)d[yfork][xfork - 21] = id + 1;//22
							if (d[yfork][xfork - 22] == 0)d[yfork][xfork - 22] = id + 1;//23
							if (d[yfork][xfork - 23] == 0)d[yfork][xfork - 23] = id + 1;//24
							if (d[yfork][xfork - 24] == 0)d[yfork][xfork - 24] = id + 1;//25
							if (d[yfork][xfork - 25] == 0)d[yfork][xfork - 25] = id + 1;//26
							if (d[yfork][xfork - 26] == 0)d[yfork][xfork - 26] = id + 1;//27
							if (d[yfork][xfork - 27] == 0)d[yfork][xfork - 27] = id + 1;//28
							if (d[yfork][xfork - 28] == 0)d[yfork][xfork - 28] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 20] == 0)d[yfork][xfork - 20] = id + 1;//21
							if (d[yfork][xfork - 21] == 0)d[yfork][xfork - 21] = id + 1;//
							if (d[yfork][xfork - 23] == 0)d[yfork][xfork - 23] = id + 1;//24
							if (d[yfork][xfork - 24] == 0)d[yfork][xfork - 24] = id + 1;//25
							if (d[yfork][xfork - 25] == 0)d[yfork][xfork - 25] = id + 1;//26
							if (d[yfork][xfork - 26] == 0)d[yfork][xfork - 26] = id + 1;//27
							if (d[yfork][xfork - 27] == 0)d[yfork][xfork - 27] = id + 1;//28
							if (d[yfork][xfork - 28] == 0)d[yfork][xfork - 28] = id + 1;//29
							if (d[yfork][xfork - 29] == 0)d[yfork][xfork - 29] = id + 1;//30
							if (d[yfork][xfork - 30] == 0)d[yfork][xfork - 30] = id + 1;//31
							if (d[yfork][xfork - 31] == 0)d[yfork][xfork - 31] = id + 1;//32
							if (d[yfork][xfork - 32] == 0)d[yfork][xfork - 32] = id + 1;//33
							if (d[yfork][xfork - 33] == 0)d[yfork][xfork - 33] = id + 1;//34
							if (d[yfork][xfork - 34] == 0)d[yfork][xfork - 34] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 18] == 0)d[yfork][xfork - 18] = id + 1;//19
							if (d[yfork][xfork - 19] == 0)d[yfork][xfork - 19] = id + 1;//20
							if (d[yfork][xfork - 20] == 0)d[yfork][xfork - 20] = id + 1;//
							if (d[yfork][xfork - 25] == 0)d[yfork][xfork - 25] = id + 1;//26
							if (d[yfork][xfork - 26] == 0)d[yfork][xfork - 26] = id + 1;//27
							if (d[yfork][xfork - 27] == 0)d[yfork][xfork - 27] = id + 1;//28
							if (d[yfork][xfork - 28] == 0)d[yfork][xfork - 28] = id + 1;//29
							if (d[yfork][xfork - 29] == 0)d[yfork][xfork - 29] = id + 1;//30
							if (d[yfork][xfork - 30] == 0)d[yfork][xfork - 30] = id + 1;//31
							if (d[yfork][xfork - 31] == 0)d[yfork][xfork - 31] = id + 1;//32
							if (d[yfork][xfork - 32] == 0)d[yfork][xfork - 32] = id + 1;//
							if (d[yfork][xfork - 34] == 0)d[yfork][xfork - 34] = id + 1;//35
							if (d[yfork][xfork - 35] == 0)d[yfork][xfork - 35] = id + 1;//36
							if (d[yfork][xfork - 36] == 0)d[yfork][xfork - 36] = id + 1;//37
							if (d[yfork][xfork - 37] == 0)d[yfork][xfork - 37] = id + 1;//38
							if (d[yfork][xfork - 38] == 0)d[yfork][xfork - 38] = id + 1;//39
							if (d[yfork][xfork - 39] == 0)d[yfork][xfork - 39] = id + 1;//40
							if (d[yfork][xfork - 40] == 0)d[yfork][xfork - 40] = id + 1;//41
							if (d[yfork][xfork - 41] == 0)d[yfork][xfork - 41] = id + 1;//42
							if (d[yfork][xfork - 42] == 0)d[yfork][xfork - 42] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 28] == 0)d[yfork][xfork - 28] = id + 1;//29
							if (d[yfork][xfork - 29] == 0)d[yfork][xfork - 29] = id + 1;//30
							if (d[yfork][xfork - 30] == 0)d[yfork][xfork - 30] = id + 1;//31
							if (d[yfork][xfork - 31] == 0)d[yfork][xfork - 31] = id + 1;//32
							if (d[yfork][xfork - 32] == 0)d[yfork][xfork - 32] = id + 1;//33
							if (d[yfork][xfork - 33] == 0)d[yfork][xfork - 33] = id + 1;//34
							if (d[yfork][xfork - 34] == 0)d[yfork][xfork - 34] = id + 1;//35
							if (d[yfork][xfork - 35] == 0)d[yfork][xfork - 35] = id + 1;//36
							if (d[yfork][xfork - 36] == 0)d[yfork][xfork - 36] = id + 1;//37
							if (d[yfork][xfork - 37] == 0)d[yfork][xfork - 37] = id + 1;//38
							if (d[yfork][xfork - 38] == 0)d[yfork][xfork - 38] = id + 1;//39
							if (d[yfork][xfork - 39] == 0)d[yfork][xfork - 39] = id + 1;//40
							if (d[yfork][xfork - 40] == 0)d[yfork][xfork - 40] = id + 1;//41
							if (d[yfork][xfork - 41] == 0)d[yfork][xfork - 41] = id + 1;//42
							if (d[yfork][xfork - 42] == 0)d[yfork][xfork - 42] = id + 1;//
							yfork++;
							if (d[yfork][xfork - 35] == 0)d[yfork][xfork - 35] = id + 1;//36
							if (d[yfork][xfork - 36] == 0)d[yfork][xfork - 36] = id + 1;//37
							if (d[yfork][xfork - 37] == 0)d[yfork][xfork - 37] = id + 1;//38
							if (d[yfork][xfork - 38] == 0)d[yfork][xfork - 38] = id + 1;//

						}
					}


				}
				//怪物图像
				else
				{
					if (i[id] < 10001) {
						i[id]++;die[id]++; mop[room]++;
					}
				}


				if (i[id] < 20 && ni[id] == -1) { dieword = id;nice[id] = 0;ni[id] = -2;mop[room]++; }//当怪物体力掉到一定程度求饶时,ni用来防止触发第二次



			}

			if (fag[id][3] > 1)fag[id][3] = 0;//怪物动作状态







		}
		else//对话栏
		{
			if (nice[id] == 0)
			{
				if (nice[id] == 5)
				{


				}

				printf("#############################################################################################################################################\n");
				if (hdso == 1)
				{
					if (51 == room) {



						talkf(81, 86);

						//房间2特有剧情

						if (meun == 1)
						{
							hdso++;system("cls");talktime = 0;meun = '?'; mop[room]++;
						}
						if (meun == 3) { hdso = 3;system("cls");talktime = 0;meun = '?'; }
						if (meun == 0) { hdso--;hdso = 0;system("cls");talktime = 0;exit; }//如果talk=0则将不显示与商人对话}
					}
				}
				if (hdso == 2)
				{
					if (51 == room)
					{
						talktime++;
						if (talktime > 0)printf("                                 穿越者吗？有点意思。。。。。。                                                           \n");//
						if (talktime > 20)printf("                                 不过看你的样子也不像这片大陆上的人                                                           \n");//
						if (talktime > 40)printf("                                 小子，我姑且就信你一回                                                           \n");//
						if (talktime > 60)printf("                                 向我背后走去，那里便是出口                                                           \n");//
						if (talktime > 80)printf("                                 如果你见到国王，记得替我向他问好                                                           \n");//
						if (talktime > 100)printf("                                 咱有缘再见                                                           \n");//
						if (talktime > 120)printf("                                                     溜了溜了~~~（按0退出）\n");
						if (talktime > 120)talktime = 120;
						if (meun == 0) { hdso--;hdso = 0;system("cls");talktime = 0;talk = 0;nice[id] = 1;exit; }//如果talk=0则将不显示与商人对话}
					}
				}

				if (room == 51 && hdso == 3)
				{
					talktime++;
					if (talktime > 0)printf("                                 国王的亲信？                                                                                                                                                                                        \n");//printf("\n");小子，就凭你还想戏弄我？
					if (talktime > 20)printf("                                 小子，就凭你还想戏弄我？                                                                                                                                                                                        \n");//printf("\n");找死
					if (talktime > 40)printf("                                 找死                                                                                                                                                                                        \n");//printf("\n");
					if (talktime > 60) { hdso = 0;talktime = 0;system("cls");talk = 0;nice[id] = ni[id];meun = '?'; }





				}





				printf("#############################################################################################################################################\n");
			}
			if (nice[id] == 1) { printf("走吧，年轻人，不要忘记带上上面宝箱里的奖励"); }

		}

	}
}

void villager(int x2, int y2, int h1, int id, int r, int e)
{/*
  ---------------------------------------------------------------------------------------------------------------------------------------------
                           函数分为逻辑区与对话区
   常用参数 a,b，Ay
   x2					初始化横坐标													y2					初始化纵坐标 
   h1					初始化生命														id					怪物逻辑编号 
   r					怪物寻敌半径													e					是否为逻辑/对话
   die[id]				怪物死亡不在运行标志											i[id]				怪物的实际生命值+1
   x1					怪物横坐标														y1					怪物纵坐标 
   xm[id]				怪物实际横坐标											    	ym[id]				怪物实际纵坐标
   Vy2					怪物当前速度（整型）											max					最大速度 
   yfork				武器横坐标														xfork				武器纵坐标
   nice[id]				怪物善恶值													    ato[id]				怪物当前状态为巡逻/发现敌人
   fag[0]				是前往目标的标志												fag[1]				是第一个目标坐标 
   fag[2]				是第二个目标坐标												fag[3]				是怪物是否落地  
   aY[id]				怪物纵向加速度													axmonst[id]			怪物横向加速度
   actmonst[id]			怪物当前动作模型                                                d[][]=id            怪物在游戏中逻辑层的模型
   vY[id]               怪物当前纵向速度(浮点数)										Vy2[id]				怪物当前纵向速度（整型）
   hurteen[id]          怪物受伤标志                                                    dieword[id]         当怪物战斗中途触发的对话
   axmonst[id]          怪物横向加速度                                                  conmonst[id]        怪物左右朝向
   V1monst[id]          怪物横向速度（浮点数）                                          V2monst[id]         怪物横向速度整型数
   meun                 怪物对话深度（层次）
  ----------------------------------------------------------------------------------------------------------------------------------------------
  */
	int x1 = 0, y1 = 0, a = 0, b = 0, Vy2 = 0, c = 0, max = 3, atk = 3, yfork = 0, xfork = 0;
	if (die[id] < 1)
	{
		if (e == 0)
		{
			if (i[id] == 0)//怪物数据函数初始化 
			{
				x2 = x2 + 30 + 30;
				xm[id] = x2;ym[id] = y2;i[id] = h1 + 1;ym[id] = 600 - ym[id];fag[id][1] = xm[id] + r;fag[id][2] = xm[id] - r;ato[id] = 1;aY[id] = 0;ni[id] = -1;
			}

			//寻敌

			if (nice[id] < 0)
			{

				{ ato[id] = 0;hdso = 0;talk = 0;dieword = id;nice[id] = 0;ni[id] = -2;
				}

			}
			else { ato[id] = 1; }





			if (ato[id] == 1)//巡航，巡逻,待命
			{
				axmonst[id] = 0;V2monst[id] = 0;V1monst[id] = 0;actmonst[id] = 0;

			}
			else
			{




			}



			if (axmonst[id] != 0)
			{
				V1monst[id] = V1monst[id] + axmonst[id] / 10;V2monst[id] = V1monst[id];
				if (V1monst[id] <= -4) {
					V1monst[id] = -4;
				}
				else if (V1monst[id] >= 4) {
					V1monst[id] = 4;
				}
			}
			if (V2monst[id] > 0)
			{

				{for (a = 0;a < V2monst[id];a++)
				{
					if (
						d[ym[id] - 8][xm[id] + 2] == 3 || d[ym[id] - 7][xm[id] + 2] == 3 || d[ym[id] - 6][xm[id] + 2] == 3 || d[ym[id] - 5][xm[id] - 2] == 3 || d[ym[id] - 4][xm[id] + 3] == 3 || d[ym[id] - 3][xm[id] - 3] == 3 || d[ym[id] - 1][xm[id] - 2] == 3 || d[ym[id]][xm[id] - 2] == 3
						)
					{
						V1monst[id] = 0;V2monst[id] = 0;axmonst[id] = 0;xm[id] = xm[id] - 3;break;
					}

					xm[id]++;
				}
				}

			}
			if (V2monst[id] < 0)
			{

				{for (a = 0;a + V2monst[id];a++)
				{
					if (
						d[ym[id] - 8][xm[id] - 2] == 3 || d[ym[id] - 7][xm[id] - 2] == 3 || d[ym[id] - 6][xm[id] - 2] == 3 || d[ym[id] - 5][xm[id] - 2] == 3 || d[ym[id] - 4][xm[id] - 3] == 3 || d[ym[id] - 3][xm[id] - 3] == 3 || d[ym[id] - 1][xm[id] - 2] == 3 || d[ym[id]][xm[id] - 2] == 3
						)
					{
						V1monst[id] = 0;V2monst[id] = 0;axmonst[id] = 0;xm[id] = xm[id] + 3;break;
					}

					xm[id]--;
				}
				}

			}


			if (d[ym[id] + 9][xm[id]] != 2 && d[ym[id] + 9][xm[id] + 1] != 2 && d[ym[id] + 9][xm[id] - 1] != 2)//重力函数
			{

				if (aY[id] <= 2) { aY[id] += 0.5; }
				if (vY[id] < 8)vY[id] = vY[id] + aY[id];
				Vy2 = vY[id];

				for (a = 0;a < Vy2;a++)//下落检测
				{
					ym[id]++;
					if (d[ym[id] + 9][xm[id]] == 2 || d[ym[id] + 9][xm[id] + 1] == 2 || d[ym[id] + 9][xm[id] - 1] == 2)
					{
						aY[id] = 0;vY[id] = 0;Vy2 = 0;fag[id][3]++;break;
					}
				}


			}
			y1 = ym[id];
			if (hurteen[id] != i[id])//伤害动画
			{
				hurteen[id] = i[id];
				延迟(300);
			}
			if (i[id] > 1)
			{//生命等于0时
				//怪物图像
				if (i[id] < 10000)
				{

					char Ay = -2;
					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					Ay++;
					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					Ay++;

					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					if (d[ym[id] + Ay][xm[id] + 2] == 0)d[ym[id] + Ay][xm[id] + 2] = id;
					if (d[ym[id] + Ay][xm[id] - 2] == 0)d[ym[id] + Ay][xm[id] - 2] = id;
					if (d[ym[id] + Ay][xm[id] + 3] == 0)d[ym[id] + Ay][xm[id] + 3] = id;
					if (d[ym[id] + Ay][xm[id] - 3] == 0)d[ym[id] + Ay][xm[id] - 3] = id;
					Ay++;
					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					Ay++;
					//2

					{ if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id; }

					//else if (act1 == 3) { if (d[ym[id] + Ay][xm[id] + 4] == 0) d[ym[id] + Ay][xm[id] + 4] = id;if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id; }

					//else if (act1 == 4) {if (d[ym[id] + Ay][xm[id] - 4] == 0)d[ym[id] + Ay][xm[id] - 4] = id;if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;}
					Ay++;//3        if(d[y + Ay][x]==0)
					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					if (d[ym[id] + Ay][xm[id] + 2] == 0)d[ym[id] + Ay][xm[id] + 2] = id;
					if (d[ym[id] + Ay][xm[id] - 2] == 0)d[ym[id] + Ay][xm[id] - 2] = id;

					/*if (act1 == 3)
					{
						if (d[ym[id] + Ay][xm[id] + 3] == 0)d[ym[id] + Ay][xm[id] + 3] = id;
						if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
						if (d[ym[id] + Ay][xm[id] + 2] == 0)d[ym[id] + Ay][xm[id] + 2] = id;
						if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					}
					else     if (act1 == 4)
					{
						if (d[ym[id] + Ay][xm[id] - 3] == 0)d[ym[id] + Ay][xm[id] - 3] = id;
						if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
						if (d[ym[id] + Ay][xm[id] - 2] == 0)d[ym[id] + Ay][xm[id] - 2] = id;
						if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					}*/
					Ay++;//4
					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					{
						if (d[ym[id] + Ay][xm[id] + 2] == 0)d[ym[id] + Ay][xm[id] + 2] = id;
						if (d[ym[id] + Ay][xm[id] - 2] == 0)d[ym[id] + Ay][xm[id] - 2] = id;
					}
					Ay++;//5
					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					Ay++;//6

					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					Ay++;//6

					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					Ay++;//7

					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;//8



				}
				//怪物图像
				else
				{
					if (i[id] < 10001) {
						i[id]++;die[id]++;
					}
				}


				//if (i[id] < 20 && ni[id] == -1) { dieword = id;nice[id] = 0;ni[id] = -2; }//当怪物体力掉到一定程度求饶时



			}









		}
		else
		{
			if (nice[id] == 0)
			{
				if (nice[id] == 5)
				{


				}

				printf("#############################################################################################################################################\n");
				if (vill == 1)
				{
					if (id == 9000)
					{
						talkf(1, 5);
						if (meun == 1) { vill++;system("cls");talktime = 0;meun = '?'; mop[room]++; }
						if (meun == 3) { vill = 3;system("cls");talktime = 0;meun = '?'; }
						if (meun == 0) { vill--;vill = 0;system("cls");talktime = 0;exit; }
					}
					if (id == 9001)
					{
						talkf(6, 14);
						if (meun == 1) { vill++;system("cls");talktime = 0;meun = '?'; mop[room]++; }
						if (meun == 3) { vill = 3;system("cls");talktime = 0;meun = '?'; }
					}
				}
				if (vill == 2)
				{
					if (id == 9000)
					{
						talkf(15, 21);
						if (meun == 0) { vill--;system("cls");talktime = 0;exit; }//如果talk=0则将不显示与商人对话}
					}
					if (id == 9001)
					{
						talktime++;
						if (talktime > 0)printf("                                 Wdnmd走错了还能走到我家里来，                                                           \n");//
						if (talktime > 20)printf("                                 赶紧给我滚出去                                                           \n");//
						if (talktime > 40)printf("                                 要不然让你吃不完兜着走                                                           \n");//

						if (talktime > 60)printf("                                                     开溜~（按0退出）\n");
						if (talktime > 120)talktime = 120;
						if (meun == 0) { vill = 0;system("cls");talktime = 0;exit; }
					}
				}
				if (vill == 3) {
					if (id == 9000)
					{
						talkf(22, 42);
						if (talktime > 450)talktime = 450;
						if (meun == 0) {
							vill = 5;system("cls");talktime = 0; meun = '?';
						}
						if (meun == 1) {
							vill = 6;system("cls");talktime = 0;meun = '?';
						}

					}
					if (id == 9001)
					{
						talktime++;
						if (talktime < 200) {
							if (talktime > 0)printf("                                 蛤？给小怡的信？                                                                                                                                                                                       \n");//printf("\n");小子，就凭你还想戏弄我？
							if (talktime > 20)printf("                                 我老弟这么出息了吗                                                                                                                                                                                        \n");//printf("\n");找死
							if (talktime > 40)printf("                                 我不信                                                                                                                                                                                        \n");//printf("\n");
							if (talktime > 60)printf("                                 把信给我看看！                                                           \n");//printf("\n");emmmmmm
							if (talktime > 80)printf("                                 。。。。。                                                           \n");//printf("\n");你懂的··········
							if (talktime > 100)printf("                                 。。。。。                                                           \n");//printf("\n");emmmmmmm
							if (talktime > 120)printf("                                 。。。。。                                                          \n");//printf("\n");就是······
							if (talktime > 140)printf("                                 还真是我老弟的字!                                                           \n");//printf("\n");啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
							if (talktime > 160)printf("                                 写的还挺肉麻                                                           \n");//printf("\n");欸欸欸欸你别走啊~！
							if (talktime > 180)printf("                                 什么叫“给这世界上最可爱的小怡”                                                           \n");//printf("\n");就是我。。我。。我一直喜。。。。。。。。。。
						}
						else
						{
							if (talktime == 200) { system("cls"); }
							if (talktime > 200)printf("                                 。。。。。。                                                           \n");//printf("\n");喜欢我们村的小怡！！！！！
							if (talktime > 230)printf("                                 蛤蛤蛤，笑死我了                                                           \n");//printf("\n");md羞死老子了！
							if (talktime > 250)printf("                                 你可千万别告诉他我看过信了                                                           \n");//printf("\n");不！许！tm！的！给！老！子！笑！
							if (talktime > 270)printf("                                 你问我小怡在哪？                                                           \n");//printf("\n");
							if (talktime > 290)printf("                                 那丫头就在我这房子后面的房子里                                                           \n");//printf("\n");事成之后奖励大大滴有！
							if (talktime > 310)printf("                                 我俩兄弟打小和ta就是邻居                                                           \n");//printf("\n");你问奖励有多少？500金币！
							if (talktime > 330)printf("                                 老熟了                                                           \n");//printf("\n");md我堂堂拆二代500金币还是出的起的！
							if (talktime > 350)printf("                                 总之就这样吧，一路顺风                                                           \n");//printf("\n");总之就是这样了，信给我拿好
						}

						if (talktime > 380) {
							talktime = 0;vill = 0;system("cls");talktime = 0;nice[9001] = 1;meun = '?';
						}

					}
				}
				if (vill == 6)
				{
					if (id == 9000) {
						talktime++;

						if (talktime > 0)printf("                                 这份艰巨的任务就交给你了啊，兄嘚！                                                           \n");//printf("\n");可千万别被人发现啊
						if (talktime > 20)printf("                                 可千万别被人发现啊                                                           \n");//printf("\n");

						if (talktime > 40)printf("                                 小怡她家就在离这不远处，顺着路走就到了，一路顺风~                                                           \n");
						if (talktime > 60) { vill = 0;system("cls");talktime = 0;talk = 0;nice[id] = 1;exit; }
					}
				}
				if (vill == 5)
				{
					if (id == 9000) {
						talktime++;

						if (talktime > 0)printf("                                 正你大爷！你知道了我的秘密，                                                           \n");//printf("\n");可千万别被人发现啊
						if (talktime > 20)printf("                                 不想去也得去！                                                           \n");//printf("\n");
						if (talktime > 40)printf("                                 要不然，嘿嘿，你就完蛋了~~                                                           \n");
						if (talktime > 60)printf("                                 哎哎哎大哥别打脸，你就行行好                                                           \n");
						if (talktime > 80)printf("                                 帮小弟一次吧:)                                                           \n");
						if (talktime > 100)printf("                                 我的人生幸福可全在你手上拉                                                           \n");
						if (talktime > 120)printf("                                 有钱赚他不香吗~                                                           \n");
						if (talktime > 140)printf("                                 小怡她家就在离这不远处，顺着路走就到了，一路顺风~                                                           \n");
						if (talktime > 160) { vill = 0;system("cls");talktime = 0;talk = 0;nice[id] = 1;exit; }
					}
				}


				printf("#############################################################################################################################################\n");
			}
			if (nice[id] == 1)
			{
				printf("#############################################################################################################################################\n");
				if (vill == 1)
				{
					if (id == 9000)
					{
						talktime++;

						if (talktime > 0)printf("                                 还没打算走吗？走吧走吧，走完了就被发现了                                                           \n");//不知道外面究竟怎么样了

						if (talktime > 20)printf("                                 我也不知道怎么就来到了这个世界了，你能告诉我这是哪里吗？（按1）                                                           \n");//我可是国王的亲信，你必须得帮助我


						if (meun == 1) { vill++;system("cls");talktime = 0;meun = '?'; mop[room]++; }
						if (talktime > 120)talktime = 120;
						printf("                                                     溜了溜了~~~（按0退出）\n");
						if (meun == 0) { vill--;vill = 0;system("cls");talktime = 0;exit; }
					}
				}
				if (vill == 2)
				{
					if (id == 9000)
					{
						talktime++;
						if (talktime > 0)printf("                                 蛤！这里就是整个大陆最大的明珠！安格斯——浦东！                                                           \n");//
						if (talktime > 20)printf("                                 不过看你的样子也不像这片大陆上的人                                                           \n");//
						if (talktime > 40)printf("                                 马上这栋房子就要被国王的骑士拆迁了                                                           \n");//
						if (talktime > 60)printf("                                 这里据说是国王最喜欢的土地，果然还说要修建——呢啥·····                                                           \n");//
						if (talktime > 80)printf("                                 偶！对了，叫井屏！咱不是文化人，也不知道那是哈                                                           \n");//
						if (talktime > 100)printf("                                 但是我这次一定能得到国王的赏赐成为男爵吧！                                                           \n");//
						if (talktime > 120)printf("                                                     好的了解~（按0退出）\n");
						if (talktime > 120)talktime = 120;
						if (meun == 0) { vill--;system("cls");talktime = 0;exit; }//如果talk=0则将不显示与商人对话}
					}
				}
				printf("#############################################################################################################################################\n");
			}

		}

	}
}

void gard(int x2, int y2, int h1, int id, int r, int e)
{
  /*
  ---------------------------------------------------------------------------------------------------------------------------------------------
                           函数分为逻辑区与对话区
   常用参数 a,b，Ay
   x2					初始化横坐标													y2					初始化纵坐标 
   h1					初始化生命														id					怪物逻辑编号 
   r					怪物寻敌半径													e					是否为逻辑/对话
   die[id]				怪物死亡不在运行标志											i[id]				怪物的实际生命值+1
   x1					怪物横坐标														y1					怪物纵坐标 
   xm[id]				怪物实际横坐标											    	ym[id]				怪物实际纵坐标
   Vy2					怪物当前速度（整型）											max					最大速度 
   yfork				武器横坐标														xfork				武器纵坐标
   nice[id]				怪物善恶值													    ato[id]				怪物当前状态为巡逻/发现敌人
   fag[0]				是前往目标的标志												fag[1]				是第一个目标坐标 
   fag[2]				是第二个目标坐标												fag[3]				是怪物是否落地  
   aY[id]				怪物纵向加速度													axmonst[id]			怪物横向加速度
   actmonst[id]			怪物当前动作模型                                                d[][]=id            怪物在游戏中逻辑层的模型
   vY[id]               怪物当前纵向速度(浮点数)										Vy2[id]				怪物当前纵向速度（整型）
   hurteen[id]          怪物受伤标志                                                    dieword[id]         当怪物战斗中途触发的对话
   axmonst[id]          怪物横向加速度                                                  conmonst[id]        怪物左右朝向
   V1monst[id]          怪物横向速度（浮点数）                                          V2monst[id]         怪物横向速度整型数
  ----------------------------------------------------------------------------------------------------------------------------------------------
  */
	int x1 = 0, y1 = 0, a = 0, b = 0, Vy2 = 0, c = 0, max = 3, atk = 3, yfork = 0, xfork = 0;
	if (die[id] < 1)
	{
		//---------------------------------------------------------------------------
		//                             怪物逻辑区域
		//---------------------------------------------------------------------------
		if (e == 0)
		{
			if (i[id] == 0)//怪物数据函数初始化 
			{
				x2 = x2 + 30 + 30;
				xm[id] = x2;ym[id] = y2;
				i[id] = h1 + 1;
				ym[id] = 600 - ym[id];
				fag[id][1] = xm[id] + r;
				fag[id][2] = xm[id] - r;
				ato[id] = 1;
				aY[id] = 0;ni[id] = -1;
			}

			//寻敌

			if (nice[id] < 0)
			{

				{ ato[id] = 0;hdso = 0;talk = 0;dieword = id;ni[id] = -2;
				}

			}
			else { ato[id] = 1; }





			if (ato[id] == 1)//巡航，巡逻,待命
			{
				axmonst[id] = 0;V2monst[id] = 0;V1monst[id] = 0;actmonst[id] = 0;

			}
			else
			{




			}

			if (axmonst[id] >= 0) { conmonst[id] = 1; }
			else { conmonst[id] = -1; }

			if (axmonst[id] != 0)
			{
				V1monst[id] = V1monst[id] + axmonst[id] / 10;V2monst[id] = V1monst[id];
				if (V1monst[id] <= -3) {
					V1monst[id] = -3;
				}
				else if (V1monst[id] >= 3) {
					V1monst[id] = 3;
				}
			}
			if (V2monst[id] > 0)
			{

				{for (a = 0;a < V2monst[id];a++)
				{
					if (
						d[ym[id] - 8][xm[id] + 2] == 3 || d[ym[id] - 7][xm[id] + 2] == 3 || d[ym[id] - 6][xm[id] + 2] == 3 || d[ym[id] - 5][xm[id] - 2] == 3 || d[ym[id] - 4][xm[id] + 3] == 3 || d[ym[id] - 3][xm[id] - 3] == 3 || d[ym[id] - 1][xm[id] - 2] == 3 || d[ym[id]][xm[id] - 2] == 3
						)
					{
						V1monst[id] = 0;V2monst[id] = 0;axmonst[id] = 0;xm[id] = xm[id] - 3;break;
					}

					xm[id]++;
				}
				}

			}
			if (V2monst[id] < 0)
			{

				{for (a = 0;a + V2monst[id];a++)
				{
					if (
						d[ym[id] - 8][xm[id] - 2] == 3 || d[ym[id] - 7][xm[id] - 2] == 3 || d[ym[id] - 6][xm[id] - 2] == 3 || d[ym[id] - 5][xm[id] - 2] == 3 || d[ym[id] - 4][xm[id] - 3] == 3 || d[ym[id] - 3][xm[id] - 3] == 3 || d[ym[id] - 1][xm[id] - 2] == 3 || d[ym[id]][xm[id] - 2] == 3
						)
					{
						V1monst[id] = 0;V2monst[id] = 0;axmonst[id] = 0;xm[id] = xm[id] + 3;break;
					}

					xm[id]--;
				}
				}

			}


			if (d[ym[id] + 9][xm[id]] != 2 && d[ym[id] + 9][xm[id] + 1] != 2 && d[ym[id] + 9][xm[id] - 1] != 2)//重力函数
			{

				if (aY[id] <= 2) { aY[id] += 0.5; }
				if (vY[id] < 8)vY[id] = vY[id] + aY[id];
				Vy2 = vY[id];

				for (a = 0;a < Vy2;a++)//下落检测
				{
					ym[id]++;
					if (d[ym[id] + 9][xm[id]] == 2 || d[ym[id] + 9][xm[id] + 1] == 2 || d[ym[id] + 9][xm[id] - 1] == 2)
					{
						aY[id] = 0;vY[id] = 0;Vy2 = 0;fag[id][3]++;break;
					}
				}


			}
			y1 = ym[id];
			if (hurteen[id] != i[id])//伤害动画
			{
				hurteen[id] = i[id];
				延迟(300);
			}
			if (i[id] > 1)
			{//生命等于0时
				//怪物图像
				if (i[id] < 10000)
				{

					char Ay = -1;

					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;

					Ay++;

					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					if (d[ym[id] + Ay][xm[id] + 2] == 0)d[ym[id] + Ay][xm[id] + 2] = id;
					if (d[ym[id] + Ay][xm[id] - 2] == 0)d[ym[id] + Ay][xm[id] - 2] = id;
					Ay++;
					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					Ay++;
					//2

					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;

					if (actmonst[id] == 3) {
						if (d[ym[id] + Ay][xm[id] + 4] == 0) d[ym[id] + Ay][xm[id] + 4] = id;
						if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					}

					else if (actmonst[id] == 4) {
						if (d[ym[id] + Ay][xm[id] - 4] == 0)d[ym[id] + Ay][xm[id] - 4] = id;
						if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					}
					Ay++;//3        if(d[y + Ay][x]==0)
					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					if (d[ym[id] + Ay][xm[id] + 2] == 0)d[ym[id] + Ay][xm[id] + 2] = id;
					if (d[ym[id] + Ay][xm[id] - 2] == 0)d[ym[id] + Ay][xm[id] - 2] = id;

					if (actmonst[id] == 3)
					{
						if (d[ym[id] + Ay][xm[id] + 3] == 0)d[ym[id] + Ay][xm[id] + 3] = id;
						if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
						if (d[ym[id] + Ay][xm[id] + 2] == 0)d[ym[id] + Ay][xm[id] + 2] = id;
						if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					}
					else     if (actmonst[id] == 4)
					{
						if (d[ym[id] + Ay][xm[id] - 3] == 0)d[ym[id] + Ay][xm[id] - 3] = id;
						if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
						if (d[ym[id] + Ay][xm[id] - 2] == 0)d[ym[id] + Ay][xm[id] - 2] = id;
						if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					}
					Ay++;//4
					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					if (actmonst[id] == 1 || actmonst[id] == 0) {
						if (d[ym[id] + Ay][xm[id] + 2] == 0)d[ym[id] + Ay][xm[id] + 2] = id;
						if (d[ym[id] + Ay][xm[id] - 2] == 0)d[ym[id] + Ay][xm[id] - 2] = id;
						if (d[ym[id] + Ay][xm[id] + 3] == 0)d[ym[id] + Ay][xm[id] + 3] = id;
						if (d[ym[id] + Ay][xm[id] - 3] == 0)d[ym[id] + Ay][xm[id] - 3] = id;

					}
					Ay++;//5
					if (d[ym[id] + Ay][xm[id]] == 0)d[ym[id] + Ay][xm[id]] = id;
					if (conmonst[id] < 0)if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					else if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					Ay++;//6

					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					Ay++;//6

					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;
					Ay++;//7

					if (d[ym[id] + Ay][xm[id] + 1] == 0)d[ym[id] + Ay][xm[id] + 1] = id;
					if (d[ym[id] + Ay][xm[id] - 1] == 0)d[ym[id] + Ay][xm[id] - 1] = id;//8

					if (actmonst[id] == 0)
					{
						Ay = 0;
						if (conmonst[id] >= 0)
						{

						}
						else {
							if (d[ym[id] + Ay][xm[id] - 5] == 0)d[ym[id] + Ay][xm[id] - 5] = id;
							if (d[ym[id] + Ay][xm[id] - 6] == 0)d[ym[id] + Ay][xm[id] - 6] = id;
							Ay++;
							if (d[ym[id] + Ay][xm[id] - 5] == 0)d[ym[id] + Ay][xm[id] - 5] = id;
							if (d[ym[id] + Ay][xm[id] - 7] == 0)d[ym[id] + Ay][xm[id] - 7] = id;
							Ay++;
							if (d[ym[id] + Ay][xm[id] - 5] == 0)d[ym[id] + Ay][xm[id] - 5] = id;
							if (d[ym[id] + Ay][xm[id] - 7] == 0)d[ym[id] + Ay][xm[id] - 7] = id;
							Ay++;
							if (d[ym[id] + Ay][xm[id] - 5] == 0)d[ym[id] + Ay][xm[id] - 5] = id;
							if (d[ym[id] + Ay][xm[id] - 7] == 0)d[ym[id] + Ay][xm[id] - 7] = id;
							if (d[ym[id] + Ay][xm[id] - 6] == 0)d[ym[id] + Ay][xm[id] - 6] = id;
							Ay++;
							if (d[ym[id] + Ay][xm[id] - 5] == 0)d[ym[id] + Ay][xm[id] - 5] = id;
							Ay++;
							if (d[ym[id] + Ay][xm[id] - 5] == 0)d[ym[id] + Ay][xm[id] - 5] = id;
							Ay++;
							if (d[ym[id] + Ay][xm[id] - 5] == 0)d[ym[id] + Ay][xm[id] - 5] = id;
							Ay++;
							if (d[ym[id] + Ay][xm[id] - 5] == 0)d[ym[id] + Ay][xm[id] - 5] = id;
							Ay++;
							if (d[ym[id] + Ay][xm[id] - 5] == 0)d[ym[id] + Ay][xm[id] - 5] = id;
							Ay++;
							if (d[ym[id] + Ay][xm[id] - 5] == 0)d[ym[id] + Ay][xm[id] - 5] = id;

						}
					}



				}
				//怪物图像
				else
				{
					if (i[id] < 10001) {
						i[id]++;die[id]++;
					}
				}


				//if (i[id] < 20 && ni[id] == -1) { dieword = id;nice[id] = 0;ni[id] = -2; }//当怪物体力掉到一定程度求饶时



			}









		}
		//---------------------------------------------------------------------------
		//                               对话框
		//---------------------------------------------------------------------------
		else
		{


		}
	}
}

void dieman(int x2,int y2) {
	int id = 15;
	x2 = x2 + 30 + 30;y2 = 600 - y2;
	d[y2 - 2][x2 - 9] = id;d[y2 - 2][x2 - 8] = id;d[y2 - 2][x2 - 7] = id;d[y2 - 2][x2 - 6] = id;d[y2 - 2][x2 - 5] = id;d[y2 - 2][x2 - 4] = id;
	d[y2 - 2][x2 - 3] = id;d[y2 - 2][x2 - 2] = id;d[y2 - 1][x2 - 17] = id;d[y2 - 1][x2 - 16] = id;d[y2 - 1][x2 - 15] = id;d[y2 - 1][x2 - 14] = id;
	d[y2 - 1][x2 - 13] = id;d[y2 - 1][x2 - 12] = id;d[y2 - 1][x2 - 11] = id;d[y2 - 1][x2 - 10] = id;d[y2 - 1][x2 - 9] = id;d[y2 - 1][x2 - 8] = id;
	d[y2 - 1][x2 - 7] = id;d[y2 - 1][x2 - 6] = id;d[y2 - 1][x2 - 5] = id;d[y2 - 1][x2 - 4] = id;d[y2 - 1][x2 - 3] = id;d[y2 - 1][x2 - 2] = id;
	d[y2 - 1][x2 + 1] = id;d[y2 - 1][x2 + 2] = id;d[y2 - 1][x2 + 3] = id;d[y2 - 1][x2 + 4] = id;d[y2 - 1][x2 + 5] = id;d[y2 + 0][x2 - 11] = id;
	d[y2 + 0][x2 - 10] = id;d[y2 + 0][x2 - 9] = id;d[y2 + 0][x2 - 8] = id;d[y2 + 0][x2 - 7] = id;d[y2 + 0][x2 - 6] = id;d[y2 + 0][x2 - 5] = id;
	d[y2 + 0][x2 - 4] = id;d[y2 + 0][x2 - 3] = id;d[y2 + 0][x2 - 2] = id;d[y2 + 0][x2 - 1] = id;d[y2 + 0][x2 + 0] = id;d[y2 + 0][x2 + 1] = id;
	d[y2 + 0][x2 + 2] = id;d[y2 + 0][x2 + 3] = id;d[y2 + 0][x2 + 4] = id;d[y2 + 0][x2 + 5] = id;d[y2 + 1][x2 - 17] = id;d[y2 + 1][x2 - 16] = id;
	d[y2 + 1][x2 - 15] = id;d[y2 + 1][x2 - 14] = id;d[y2 + 1][x2 - 13] = id;d[y2 + 1][x2 - 12] = id;d[y2 + 1][x2 - 11] = id;d[y2 + 1][x2 - 10] = id;
	d[y2 + 1][x2 - 9] = id;d[y2 + 1][x2 - 8] = id;d[y2 + 1][x2 - 7] = id;d[y2 + 1][x2 - 6] = id;d[y2 + 1][x2 - 5] = id;d[y2 + 1][x2 - 4] = id;
	d[y2 + 1][x2 - 3] = id;d[y2 + 1][x2 - 2] = id;d[y2 + 1][x2 + 1] = id;d[y2 + 1][x2 + 2] = id;d[y2 + 1][x2 + 3] = id;d[y2 + 1][x2 + 4] = id;
	d[y2 + 1][x2 + 5] = id;d[y2 + 2][x2 - 8] = id;d[y2 + 2][x2 - 7] = id;d[y2 + 2][x2 - 6] = id;d[y2 + 2][x2 - 5] = id;d[y2 + 2][x2 - 4] = id;
	d[y2 + 2][x2 - 3] = id;d[y2 + 2][x2 - 2] = id;

}

void product()
{
	/*关卡设计id表
----------------------------------------------------------------------------------------
|怪物                        monst[][]
|史莱姆                      monst[1]
|蝙蝠                        monst[2]
|韩德索                      monst[10][0]
|守卫                        monst[12]
|村民                        monst[11]
|
|
|
----------------------------------------------------------------------------------------
*/
	if (monst[1][1] > 0)//刷怪史莱姆
		for (a = 1;a < 60;a++)
		{
			if (monst[1][a] > 0)
			{
				slim(xmonst[monst[1][a]], ymonst[monst[1][a]], 10, monst[1][a], 20);
			}
			else break;
		}
	if (monst[2][1] > 0)//刷怪慢百特
		for (a = 1;a < 60;a++)
		{
			if (monst[2][a] > 0)
			{
				manbat(xmonst[monst[2][a]], ymonst[monst[2][a]], 5, monst[2][a], 20);
			}
			else break;
		}
	if (monst[10][0] > 0)//刷npc哈德所
	{
		hardso(xmonst[24], ymonst[24], 50, 24, 50, 0);
	}
	if (monst[10][1] > 0)//刷怪普通巨人
		for (a = 1;a < 60;a++)
		{
			if (monst[10][a] > 0)
			{
				villager(xmonst[monst[11][a]], ymonst[monst[11][a]], 30, monst[11][a], 50, 0);
			}
			else break;
		}
	if (monst[11][1] > 0)//刷怪村民
		for (a = 1;a < 60;a++)
		{
			if (monst[11][a] > 0)
			{
				villager(xmonst[monst[11][a]], ymonst[monst[11][a]], 30, monst[11][a], 50, 0);
			}
			else break;
		}
	if (monst[12][1] > 0)//刷怪卫兵
		for (a = 1;a < 60;a++)
		{
			if (monst[12][a] > 0)
			{
				gard(xmonst[monst[12][a]], ymonst[monst[12][a]], 30, monst[12][a], 50, 0);
			}
			else break;
		}
	//管卡内重置与显示
	if (elc > 0) {
		elc = 1;pad(xbotton, ybotton, xauto, ydauto, xboxz, yboxz, eid);
	}
	if (trd > 0) {
		trd = 1; trader(xtrd, ytrd, 0);
	}
}
/*关卡设计id表
----------------------------------------------------------------------------------------
|id                  怪物                        monst[][]顺序
|21                  史莱姆                      monst[1]
|22                  史莱姆                      monst[1]
|23                  蝙蝠                        monst[2]
|24                  韩德索                      monst[10][0]
|25                  韩德索武器                      
|26                  史莱姆                      monst[1]
|27                  史莱姆                      monst[1]
|28                  史莱姆                      monst[1]
|29                  守卫                        monst[12]
|9000                村民                        monst[11]
|9001                村民                        monst[11]
|
|
|
----------------------------------------------------------------------------------------
*/

void 关卡设计
{
	/*关卡设计规则
----------------------------------------------------------------------------------------
|room      房间id
|eexit     从房间中进出                                      规则变换坐标
|juxing   (横坐标x,长度，纵坐标y，高度)						 产生一个可以横向透过的平台
|wall     (横坐标x,长度，纵坐标y，高度)						 产生一个无法穿过的区域
|BOX      (横坐标x,纵坐标y,0)								 产生一个带奖励的盒子
|doorr    (横坐标x, 纵坐标y)								 向右走的门
|doorl    (横坐标x, 纵坐标y)								 向左走的门
|doorf    (横坐标x, 纵坐标y)								 进来的门
|doorb    (横坐标x, 纵坐标y)								 出去的门
|xtrd =    商人横坐标                                        商人 
|ytrd =    商人纵坐标                                        商人
|monst     [种类][第几个]                                    第几个什么怪物的id
|xmonst    [id]                                              怪物横坐标x 
|ymonst    [id]                                              怪物横坐标x 
|trd=2     初始化一般为2                                     本关有商人的标志
|elc=2     初始化一般为2									 本关有机关的标志
|xbotton = 按钮横坐标										 机关的参数
|ybotton = 按钮纵坐标 										 机关的参数
|xauto =   自动门横坐标										 机关的参数
|ydauto =  自动门纵坐标 									 机关的参数
|xboxz =   重力物块位置 									 机关的参数
|yboxz =   重力物块的位置									 机关的参数
|eid = 	   重力物块的id									     机关的参数
|userpc   (横坐标x, 纵坐标y)                                 玩家电脑
|bookrack (横坐标x, 纵坐标y)                                 书架
|house    (横坐标x, 纵坐标y)                                 村民小屋 
|tree     (横坐标x, 纵坐标y)                                （类似蘑菇云的）树
|tip       门打开的条件，杀死怪物可达成                      门目前是否打开      
----------------------------------------------------------------------------------------
*/
	if (room == 0)
	{
		eexit();//需要转换时
		juxing(0, 220, 0, 1);//地板
		juxing(19, 20, 12, 1);
		juxing(45, 220 - 45, 13, 1);
		juxing(29, 5, 6, 1);
		wall(0, 2, 40, 40);
		wall(149, 2, 40, 40);
		BOX(142, 1, 0);
		doorr(147, 14);//如果门在最左边一般为147
		tip = 2;//完成条件，杀怪数或者触发机关


		monst[1][1] = 21;//monst[1][x]是史莱姆
		xmonst[21] = 80;
		ymonst[21] = 16;
		monst[1][2] = 22;
		xmonst[22] = 80;
		ymonst[22] = 8;


		tian = 'b';//时间
		h = 1;//箱子中的物品id
		u = 1;//给的物品数量

		if (jj1 == 0 && j3[room] == 0)//此房间有剧本
		{
			j3[room]++;//已经触发标识
			j2 = 0;
			j4 = 6;//对话文本数
		}
	}

	if (room == 1)
	{
		eexit();
		juxing(0, 220, 0, 1);//地板
		juxing(80, 5, 6, 1);
		wall(0, 2, 40, 40);
		wall(149, 2, 40, 40);
		juxing(0, 100, 13, 1);
		doorl(3, 14);
		doorr(147, 1);
		doorf(10, 1);
		wall(50, 1, 12, 12);
		tip = 0;
		monst[2][1] = 23;//monst[2][x]是蝙蝠怪
		xmonst[23] = 80;
		ymonst[23] = 20;
		BOX(40, 1, 0);



	}

	if (room == 2)
	{

		eexit();

		wall(0, 2, 40, 40);
		wall(500, 2, 40, 40);
		juxing(0, 3000, 0, 1);
		doorl(3, 1);
		doorf(75, 1);
		tip = 0;
		trd = 2;//出现商人
		xtrd = 50;ytrd = 9;
		if (jj1 == 0 && j3[room] == 0)//此房间有剧本
		{
			j3[room]++;//已经触发标识
			j2 = 6;
			j4 = 7;//对话文本数
		}

	}
	if (room == 52)
	{

		eexit();
		wall(0, 2, 40, 40);
		wall(149, 2, 40, 40);
		juxing(0, 220, 0, 1);
		juxing(70, 20, 15, 1);
		juxing(98, 15, 15, 1);
		juxing(102, 5, 10, 1);
		juxing(102, 5, 5, 1);
		doorb(75, 16);
		doorl(3, 1);
		juxing(0, 12, 11, 1);
		elc = 2;//使用机关
		xbotton = 140;ybotton = 1; xauto = 10; ydauto = 1; xboxz = 105; yboxz = 15; eid = 1;//机关的各个参数
		//juxing(30, 5, 3, 1);
		wall(30, 5, 3, 3);
		tip = 0;
		if (jj1 == 0 && j3[room] == 0)//此房间有剧本
		{
			j3[room]++;//已经触发标识
			j2 = 7;
			j4 = 8;//对话文本数
		}

	}
	if (room == 51)
	{


		eexit();
		wall(0, 2, 40, 40);
		wall(149, 2, 40, 40);
		juxing(0, 220, 0, 1);
		juxing(8, 20, 15, 1);
		doorr(147, 1);
		doorl(3, 1);
		doorb(10, 16);
		tip = 0;
		monst[10][0] = 24;//monst[10][x]是重甲兵[x][0]有对话的npc、boss
		xmonst[24] = 80;
		ymonst[24] = 24;//monst id=25已经被重甲兵的武器给占了

		tip = 1;
	}
	if (room == 50)
	{


		eexit();
		wall(0, 2, 40, 40);
		wall(149, 2, 40, 40);
		juxing(0, 220, 0, 1);



		tip = 0;
		if (jj1 == 0 && j3[room] == 0)//此房间有剧本
		{
			j3[room]++;//已经触发标识
			j2 = 8;
			j4 = 10;//对话文本数
		}
	}





	if (room == 10000)//安全屋
	{


		x = 250;y = 600 - 11;//重新定位人物出生时的坐标

		juxing(80, 220, 0, 1);

		wall(100, 2, 60, 45);

		wall(100, 2, 3, 400);

		wall(249, 2, 60, 400);
		juxing(100, 149, 20, 1);
		userpc(160, 9);
		bookrack(195, 12);
		system("cls");

	}
	if (room == 4)
	{
	op:
		eexit();
		juxing(0, 2200, 0, 1);
		juxing(0, 2200, -1, 1);
		juxing(0, 2200, -2, 1);
		juxing(0, 2200, -3, 1);
		juxing(0, 2200, -4, 1);
		wall(0, 2, 40, 40);
		tree(200, 39);
		tian = 'w';
		trd = 2;//出现商人
		xtrd = 250;ytrd = 9;
		monst[1][1] = 26;//怪物的出场顺序与种类
		xmonst[monst[1][1]] = 600;//横坐标
		ymonst[monst[1][1]] = 8;//纵坐标
		monst[1][2] = 27;
		xmonst[monst[1][2]] = 800;
		ymonst[monst[1][2]] = 8;
		monst[1][3] = 28;
		xmonst[monst[1][3]] = 1000;
		ymonst[monst[1][3]] = 8;
		house(300, 28);
		tree(600, 39);
		tree(900, 39);
		tree(1200, 39);
		house(1300, 28);
		house(1500, 28);
		//house2(1100, 28);
		//dieman(1100, 4);
	}
	if (room == 54)
	{//eexit();op:
		juxing(279, 120, 0, 1);
		tian = 'b';
		wall(279, 2, 40, 40);
		wall(279 + 118, 2, 40, 40);
		doorb(329, 1);
		doorb(1329, 1);
		doorb(1532, 1);
		dieman(1545+35, 3);
		wall(279 + 1000, 2, 40, 40);
		wall(279 + 1000 + 118, 2, 40, 40);
		juxing(279 + 1000, 120, 0, 1);
		wall(1492, 2, 40, 40);
		wall(492 + 1000 + 118, 2, 40, 40);
		juxing(1492, 120, 0, 1);
		monst[11][1] = 9000;
		xmonst[monst[11][1]] = 300;
		ymonst[monst[11][1]] = 9;
		monst[11][2] = 9001;
		xmonst[monst[11][2]] = 1300;
		ymonst[monst[11][2]] = 9;

		monst[12][1] = 29;
		xmonst[monst[12][1]] = 1580;
		ymonst[monst[12][1]] = 9;
		if (x>1590+10&&x<1600+10)//此房间有剧本
		{
			//j3[room]++;//已经触发标识
			//j2 = 12;
			//j4 = 17;//对话文本数
			cg = 1;
		}

	}





	if (tian == 'w')//场景光照 
	{
		ch1 = day[0];
		ch2 = day[1];
		system("color 70");
	}
	else
	{
		ch1 = night[0];
		ch2 = night[1];
		system("color 07");
	}
	if (elc != 2)elc = 0;//检测本关是否需要pad
	if (trd != 2)trd = 0;//检测是否有商人
}
