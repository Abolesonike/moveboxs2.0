#include"graphics.h"
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>

#define maps_num 35//总共的关卡数量
#pragma comment(lib,"Winmm.lib")//播放音乐

typedef struct Map {

	char map[100][100];
	int level;
	int h;

	int x;
	int y;

	int box_count;
	int boxx[50];
	int boxy[50];

	int aim_count;
	int aimx[50];
	int aimy[50];

	int boxlocated_x[50][1000], boxlocated_y[50][1000];
	int Xlocated_x[1000], Xlocated_y[1000];

}Map;

struct MYPOINTS
{
	int x;
	int y;
};




//函数前置声明

/*
简介：
初始化程序
参数：
返回值：
*/


/*
简介：
主界面循环
参数：
返回值：
*/
void mainloop();

/*
简介：
游戏循环
参数：
level:当前游戏进行的关卡
返回值：
reValue:主循环的场景
*/
int gameloop(int level);

/*
简介：
读取游戏地图
参数：
level:要读取的关卡
返回值：
*/
Map* LoadMap(int level);
