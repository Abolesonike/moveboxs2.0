#include"graphics.h"
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<string.h>

#define maps_num 35//�ܹ��Ĺؿ�����
#pragma comment(lib,"Winmm.lib")//��������

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




//����ǰ������

/*
��飺
��ʼ������
������
����ֵ��
*/


/*
��飺
������ѭ��
������
����ֵ��
*/
void mainloop();

/*
��飺
��Ϸѭ��
������
level:��ǰ��Ϸ���еĹؿ�
����ֵ��
reValue:��ѭ���ĳ���
*/
int gameloop(int level);

/*
��飺
��ȡ��Ϸ��ͼ
������
level:Ҫ��ȡ�Ĺؿ�
����ֵ��
*/
Map* LoadMap(int level);
