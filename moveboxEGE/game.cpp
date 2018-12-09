
#include"function.h"


int setsound = 1;//声音开关
int level_knock[1];//关卡锁

Map* setmap();

void mainloop() {


	int level = 1;

	char key = 0;

	int isEnd = 0;

	int scenes = 1;

	int face = 1;

	int level_knock[1];



	PIMAGE strat = newimage();
	getimage(strat, "data\\image\\1开始.jpg", 0, 0);

	PIMAGE setting = newimage();
	getimage(setting, "data\\image\\1设置.jpg", 0, 0);

	PIMAGE pser = newimage();
	getimage(pser, "data\\image\\1开发者.jpg", 0, 0);

	PIMAGE exit = newimage();
	getimage(exit, "data\\image\\1退出.jpg", 0, 0);

	PIMAGE newstrat = newimage();
	getimage(newstrat, "data\\image\\2从头开始.jpg", 0, 0);

	PIMAGE ruturn = newimage();
	getimage(ruturn, "data\\image\\2返回主菜单.jpg", 0, 0);

	PIMAGE shouming = newimage();
	getimage(shouming, "data\\image\\2说明.jpg", 0, 0);

	PIMAGE xuanguan = newimage();
	getimage(xuanguan, "data\\image\\2选关.jpg", 0, 0);

	PIMAGE inxuanguan = newimage();
	getimage(inxuanguan, "data\\image\\3选关确定.jpg", 0, 0);

	PIMAGE inxuanguan1 = newimage();
	getimage(inxuanguan1, "data\\image\\3选关返回.jpg", 0, 0);

	PIMAGE inkaifazhe = newimage();
	getimage(inkaifazhe, "data\\image\\4开发者.jpg", 0, 0);

	PIMAGE inshouming = newimage();
	getimage(inshouming, "data\\image\\5说明.jpg", 0, 0);

	PIMAGE yinxiaokai = newimage();
	getimage(yinxiaokai, "data\\image\\音效开.jpg", 0, 0);

	PIMAGE yinxiaoguan = newimage();
	getimage(yinxiaoguan, "data\\image\\音效关.jpg", 0, 0);

	PIMAGE yinxiaofanhui = newimage();
	getimage(yinxiaofanhui, "data\\image\\音效返回.jpg", 0, 0);


	cleardevice();


	while (1) {
		FILE *fpRead = fopen("data//level_knock//knock.txt", "r");  //其中"r"是表示 读
		if (fpRead == NULL)
		{
			return;
		}
		fscanf(fpRead, "%d ", &level_knock[0]);
		fclose(fpRead);

		switch (face) {
		case 1:
			switch (scenes) {
			case 1:
				putimage(0, 0, strat);
				break;
			case 2:
				putimage(0, 0, setting);
				break;
			case 3:
				putimage(0, 0, pser);
				break;
			case 4:
				putimage(0, 0, exit);
				break;
			}
			char str[20];
			setcolor(EGERGB(0xF0, 0xF0, 0xF0));
			setbkmode(TRANSPARENT);
			setfont(100, 0, "楷体");
			sprintf(str, "推箱子");
			outtextxy(50, 10, str);
			break;
		case 2:
			switch (scenes) {
			case 1:
				putimage(0, 0, newstrat);
				break;
			case 2:
				putimage(0, 0, xuanguan);
				break;
			case 3:
				putimage(0, 0, shouming);
				break;
			case 4:
				putimage(0, 0, ruturn);
				break;
			}
			break;
		case 3:
			putimage(0, 0, inkaifazhe);
			break;
		case 4:
			switch (scenes) {
			case 1:
				putimage(0, 0, yinxiaokai);
				break;
			case 2:
				putimage(0, 0, yinxiaoguan);
				break;
			case 3:
				putimage(0, 0, yinxiaofanhui);
				break;
			}
			break;
		case 5:
			switch (scenes) {
			case 1:
				putimage(0, 0, inxuanguan);
				char str[20];
				char str1[20];
				setcolor(EGERGB(0xF0, 0xF0, 0xF0));
				setbkmode(TRANSPARENT);
				setfont(100, 0, "楷体");
				sprintf(str, "%d", level);
				outtextxy(805, 270, str);
				setbkmode(TRANSPARENT);
				setfont(30, 0, "楷体");
				sprintf(str1, "%d", level_knock[0]);
				outtextxy(905, 385, str1);
				break;
			case 2:
				putimage(0, 0, inxuanguan1);
				setcolor(EGERGB(0xF0, 0xF0, 0xF0));
				setbkmode(TRANSPARENT);
				setfont(100, 0, "楷体");
				sprintf(str, "%d", level);
				outtextxy(805, 270, str);
				setbkmode(TRANSPARENT);
				setfont(30, 0, "楷体");
				sprintf(str1, "%d", level_knock[0]);
				outtextxy(905, 385, str1);
				break;
			}
			break;
		case 6:
			putimage(0, 0, inshouming);
			break;
		}

		key = getch();
		switch (key) {
		case'w':
			if (setsound == 1)
				PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if ((face == 1 || face == 2) && scenes > 1) {
				scenes--;
				break;
			}
			if (face == 4 && scenes > 1) {
				scenes--;
				break;
			}
			if (face == 5 && scenes > 1) {
				scenes--;
				break;
			}
			else
				break;
		case's':
			if (setsound == 1)
				PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if ((face == 1 || face == 2) && scenes < 4) {
				scenes++;
				break;
			}
			if (face == 4 && scenes < 3) {
				scenes++;
				break;
			}
			if (face == 5 && scenes < 2) {
				scenes++;
				break;
			}
			else
				break;
		case'a':
			if (setsound == 1)
				PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (face == 5 && level > 0) {
				level--;
				break;
			}
			else
				break;
		case'd':
			if (setsound == 1)
				PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (face == 5 && level < level_knock[0]) {
				level++;
				break;
			}
			else
				break;
		case'j':
			if (setsound == 1)
				PlaySound(TEXT("data\\sound\\question.wav"), NULL, SND_FILENAME | SND_ASYNC);
			if (face == 1 && scenes == 1) {
				face = 2;
				scenes = 1;
				break;
			}
			if (face == 1 && scenes == 2) {
				face = 4;
				scenes = 1;
				break;
			}
			if (face == 2 && scenes == 1) {
				gameloop(1);
				break;
			}
			if (face == 2 && scenes == 3) {
				scenes = 1;
				face = 6;
				break;
			}
			if (face == 1 && scenes == 3) {
				face = 3;
				scenes = 1;
				break;
			}
			if (face == 1 && scenes == 4) {
				isEnd = 1;
				break;
			}
			if (face == 3 && scenes == 1) {
				face = 1;
				scenes = 1;
				break;
			}
			if (face == 4 && scenes == 3) {
				face = 1;
				scenes = 1;
				break;
			}
			if (face == 4 && scenes == 1) {
				setsound = 1;
				break;
			}
			if (face == 4 && scenes == 2) {
				setsound = 0;
				break;
			}
			if (face == 2 && scenes == 4) {
				face = 1;
				scenes = 1;
				break;
			}
			if (face == 2 && scenes == 2) {
				face = 5;
				scenes = 1;
				break;
			}
			if (face == 5 && scenes == 1) {
				gameloop(level);
				break;
			}
			if (face == 5 && scenes == 2) {
				face = 2;
				scenes = 1;
				break;
			}
			if (face == 6 && scenes == 1) {
				face = 2;
				break;
			}
			else
				break;
		default:
			break;
		}
		if (isEnd == 1)
			break;
	}

}




int gameloop(int level) {

	int x = 0;
	int y = 0;
	int a = 0;
	int b = 0;
	int step_num = 0;
	int eat = 1;
	int eat_count = 3;
	int box_count;
	int boxx[50];
	int boxy[50];
	int Xlocated_x[1000], Xlocated_y[1000];
	int boxlocated_x[1000][50];
	int boxlocated_y[1000][50];
	int level_knock[1];
	int count = 0;
	int face = 1;
	int level1 = 0;
	int manchange = 1;


	char key = 0;

	int isEnd = 0;

	int scenes = 0;

	FILE *fpRead = fopen("data//level_knock//knock.txt", "r");  //其中"r"是表示读
	fscanf(fpRead, "%d ", &level_knock[0]);
	fclose(fpRead);/********************************************/



	Map *map;
	map = LoadMap(level);
	x = map->x;
	y = map->y;
	box_count = map->box_count;
	for (int i = 0; i < map->box_count; i++)
	{
		boxx[i] = map->boxx[i];
		boxy[i] = map->boxy[i];
	}

	for (int i = 0; i < box_count; i++) {
		boxlocated_x[0][i] = boxx[i];
		boxlocated_y[0][i] = boxy[i];
	}


	PIMAGE ren = newimage();
	getimage(ren, "data\\image\\人.jpg", 0, 0);

	PIMAGE xiangzi = newimage();
	getimage(xiangzi, "data\\image\\箱子.jpg", 0, 0);

	PIMAGE mubiao = newimage();
	getimage(mubiao, "data\\image\\目标.jpg", 0, 0);

	PIMAGE dimian = newimage();
	getimage(dimian, "data\\image\\地.jpg", 0, 0);

	PIMAGE qiang1 = newimage();
	getimage(qiang1, "data\\image\\墙1.jpg", 0, 0);

	PIMAGE qiang2 = newimage();
	getimage(qiang2, "data\\image\\墙2.jpg", 0, 0);

	PIMAGE mubiaoxiangzi = newimage();
	getimage(mubiaoxiangzi, "data\\image\\目标+箱子.jpg", 0, 0);

	PIMAGE bg = newimage();
	getimage(bg, "data\\image\\bg.jpg", 0, 0);

	PIMAGE xyg = newimage();
	getimage(xyg, "data\\image\\过关-下一关.jpg", 0, 0);

	PIMAGE cw = newimage();
	getimage(cw, "data\\image\\过关-重玩.jpg", 0, 0);

	PIMAGE xg = newimage();
	getimage(xg, "data\\image\\过关-选关.jpg", 0, 0);

	PIMAGE zcd = newimage();
	getimage(zcd, "data\\image\\过关-返回主菜单.jpg", 0, 0);

	PIMAGE inxuanguan = newimage();
	getimage(inxuanguan, "data\\image\\3选关确定.jpg", 0, 0);

	PIMAGE inxuanguan1 = newimage();
	getimage(inxuanguan1, "data\\image\\3选关返回.jpg", 0, 0);

	PIMAGE ren2 = newimage();
	getimage(ren2, "data\\image\\人2.jpg", 0, 0);

	PIMAGE mei1 = newimage();
	getimage(mei1, "data\\image\\妹1.jpg", 0, 0);

	PIMAGE mei2 = newimage();
	getimage(mei2, "data\\image\\妹2.jpg");

	PIMAGE a1 = newimage();
	getimage(a1, "data\\image\\1.jpg");
	PIMAGE a2 = newimage();
	getimage(a2, "data\\image\\2.jpg");
	PIMAGE a3 = newimage();
	getimage(a3, "data\\image\\3.jpg");
	PIMAGE a4 = newimage();
	getimage(a4, "data\\image\\4.jpg");
	PIMAGE a5 = newimage();
	getimage(a5, "data\\image\\5.jpg");
	PIMAGE a6 = newimage();
	getimage(a6, "data\\image\\6.jpg");
	PIMAGE a7 = newimage();
	getimage(a7, "data\\image\\7.jpg");
	PIMAGE a8 = newimage();
	getimage(a8, "data\\image\\8.jpg");
	PIMAGE a9 = newimage();
	getimage(a9, "data\\image\\9.jpg");
	PIMAGE a10 = newimage();
	getimage(a10, "data\\image\\10.jpg");

	PIMAGE b1 = newimage();
	getimage(b1, "data\\image\\1\\1.jpg");
	PIMAGE b2 = newimage();
	getimage(b2, "data\\image\\1\\2.jpg");
	PIMAGE b3 = newimage();
	getimage(b3, "data\\image\\1\\3.jpg");
	PIMAGE b4 = newimage();
	getimage(b4, "data\\image\\1\\4.jpg");
	PIMAGE b5 = newimage();
	getimage(b5, "data\\image\\1\\5.jpg");
	PIMAGE b6 = newimage();
	getimage(b6, "data\\image\\1\\6.jpg");





	for (; is_run(); delay_fps(60))
	{
		if (count > 60)
			count = 0;
		count += 2;

		switch (scenes)
		{
		case 0:
			cleardevice();
			putimage(0, 0, bg);
			char str1[40];
			setcolor(EGERGB(0x00, 0xF0, 0x00));
			setbkmode(TRANSPARENT);
			setfont(80, 0, "楷体");
			sprintf(str1, "第:%d关", level);
			outtextxy(750, 10, str1);
			setfont(50, 0, "楷体");
			sprintf(str1, "步数:%d", step_num);
			outtextxy(800, 100, str1);
			setfont(30, 0, "楷体");
			sprintf(str1, "剩余吃的次数:%d", eat_count);
			outtextxy(780, 200, str1);
			setfont(30, 0, "楷体");
			sprintf(str1, "U:撤销 R:重新开始");
			outtextxy(750, 300, str1);
			setfont(30, 0, "楷体");
			sprintf(str1, "Q:选择人物");
			outtextxy(780, 400, str1);
			setfont(30, 0, "楷体");
			sprintf(str1, "ESC:返回");
			outtextxy(800, 500, str1);
			setfont(30, 0, "楷体");
			sprintf(str1, "E:自定义地图");
			outtextxy(800, 450, str1);
			for (int i = 0; i <= 17; i++)
			{
				for (int t = 0; t < strlen(map->map[0]); t++)
				{
					if (map->map[i][t] == '|' || map->map[i][t] == '=')
						putimage(t * 50, i * 50, qiang1);
					if (map->map[i][t] == ' ')
						putimage(t * 50, i * 50, dimian);
					if (map->map[i][t] == 'O')
						putimage(t * 50, i * 50, xiangzi);
					if (map->map[i][t] == 'Q')
						putimage(t * 50, i * 50, mubiaoxiangzi);
					if (map->map[i][t] == '#')
						putimage(t * 50, i * 50, qiang2);
					if (map->map[i][t] == 'X')
						putimage(t * 50, i * 50, mubiao);
					if (map->map[i][t] == '@') {
						if (manchange == 1) {
							if (count > 30)
								putimage(t * 50, i * 50, mei1);
							else
								putimage(t * 50, i * 50, mei2);
						}
						else if (manchange == 2) {
							if (count > 30)
								putimage(t * 50, i * 50, ren);
							else
								putimage(t * 50, i * 50, ren2);
						}
						else if (manchange == 3) {
							if (count < 6)
								putimage(t * 50, i * 50, a1);
							else if (count < 12 && count >= 6)
								putimage(t * 50, i * 50, a2);
							else if (count < 18 && count >= 12)
								putimage(t * 50, i * 50, a3);
							else if (count < 24 && count >= 18)
								putimage(t * 50, i * 50, a4);
							else if (count < 30 && count >= 24)
								putimage(t * 50, i * 50, a5);
							else if (count < 42 && count >= 30)
								putimage(t * 50, i * 50, a7);
							else if (count < 48 && count >= 42)
								putimage(t * 50, i * 50, a8);
							else if (count < 54 && count >= 48)
								putimage(t * 50, i * 50, a9);
							else
								putimage(t * 50, i * 50, a10);
						}
						else if (manchange == 4) {
							if (count < 10)
								putimage(t * 50, i * 50, b1);
							else if (count < 20 && count >= 10)
								putimage(t * 50, i * 50, b2);
							else if (count < 30 && count >= 20)
								putimage(t * 50, i * 50, b3);
							else if (count < 40 && count >= 30)
								putimage(t * 50, i * 50, b4);
							else if (count < 50 && count >= 40)
								putimage(t * 50, i * 50, b5);
							else
								putimage(t * 50, i * 50, b6);
						}
					}

				}
				if (map->map[i][1] == '|')
					break;
			}
			break;
		case 1:
			if (face == 1) {
				putimage(0, 0, xyg);
				break;
			}
			if (face == 2) {
				putimage(0, 0, cw);
				break;
			}
			if (face == 3) {
				putimage(0, 0, xg);
				break;
			}
			if (face == 4) {
				putimage(0, 0, zcd);
				break;
			}
			break;
		case 2:
			switch (face) {
			case 1:
				putimage(0, 0, inxuanguan);
				char str[20];
				char str1[20];
				setcolor(EGERGB(0xF0, 0xF0, 0xF0));
				setbkmode(TRANSPARENT);
				setfont(100, 0, "楷体");
				sprintf(str, "%d", level);
				outtextxy(805, 270, str);
				setbkmode(TRANSPARENT);
				setfont(30, 0, "楷体");
				sprintf(str1, "%d", level_knock[0]);
				outtextxy(905, 385, str1);
				break;
			case 2:
				putimage(0, 0, inxuanguan1);
				setcolor(EGERGB(0xF0, 0xF0, 0xF0));
				setbkmode(TRANSPARENT);
				setfont(100, 0, "楷体");
				sprintf(str, "%d", level);
				outtextxy(805, 270, str);
				setbkmode(TRANSPARENT);
				setfont(30, 0, "楷体");
				sprintf(str1, "%d", level_knock[0]);
				outtextxy(905, 385, str1);
				break;
			}

		default:
			break;
		}

		if (kbhit()) {
			key = getch();//获取按键输入


			switch (scenes)
			{
			case 0:
				switch (key)
				{
				case 'q':
				case'Q':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
					switch (manchange) {
					case 1:
						manchange = 2;
						break;
					case 2:
						manchange = 3;
						break;
					case 3:
						manchange = 4;
						break;
					case 4:
						manchange = 1;
						break;
					}
					break;
				case 'W':
				case 'w':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
					switch (map->map[y - 1][x])
					{
					case ' ':
					case 'X':
						for (int i = 0; i < box_count; i++)//纪录箱子坐标
						{
							if (map->map[boxy[i]][boxx[i]] == '@')
							{
								boxy[i] = boxy[i] - 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////
						Xlocated_x[step_num] = x;//每移动一次就把坐标存入数字中，实现撤销
						Xlocated_y[step_num] = y;
						map->map[y - 1][x] = '@';
						map->map[y][x] = ' ';
						y = y - 1;
						step_num++;
						break;
					case 'O':
					case 'Q':
						if (map->map[y - 2][x] != '#'&&map->map[y - 2][x] != 'O'&&map->map[y - 2][x] != 'Q'&&eat == 1) {
							for (int i = 0; i < box_count; i++)
							{
								if (map->map[boxy[i] + 1][boxx[i]] == '@')
								{
									boxy[i] = boxy[i] - 1;
								}
							}
							for (int i = 0; i < box_count; i++)
							{
								boxlocated_y[step_num + 1][i] = boxy[i];
								boxlocated_x[step_num + 1][i] = boxx[i];
							}////////////////////////
							if (map->map[y - 2][x] == 'X') {
								map->map[y - 2][x] = 'Q';
							}
							else {
								map->map[y - 2][x] = 'O';
							}

							map->map[y - 1][x] = '@';
							map->map[y][x] = ' ';
							Xlocated_x[step_num] = x;
							Xlocated_y[step_num] = y;
							y = y - 1;
							step_num++;
						}
						break;
					default:
						break;
					}

					break;
				case 'S':
				case 's':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
					switch (map->map[y + 1][x])
					{
					case ' ':
					case 'X':
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i]] == '@')
							{
								boxy[i] = boxy[i] + 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////
						map->map[y + 1][x] = '@';
						map->map[y][x] = ' ';
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						y = y + 1;
						step_num++;
						break;
					case 'O':
					case 'Q':
						if (map->map[y + 2][x] != '#'&&map->map[y + 2][x] != 'O'&&map->map[y + 2][x] != 'Q'&&eat == 1) {
							for (int i = 0; i < box_count; i++)
							{
								if (map->map[boxy[i] - 1][boxx[i]] == '@')
								{
									boxy[i] = boxy[i] + 1;
								}
							}
							for (int i = 0; i < box_count; i++)
							{
								boxlocated_y[step_num + 1][i] = boxy[i];
								boxlocated_x[step_num + 1][i] = boxx[i];
							}////////////////////////
							if (map->map[y + 2][x] == 'X') {
								map->map[y + 2][x] = 'Q';
							}
							else {
								map->map[y + 2][x] = 'O';
							}

							map->map[y + 1][x] = '@';
							map->map[y][x] = ' ';
							Xlocated_x[step_num] = x;
							Xlocated_y[step_num] = y;
							y = y + 1;
							step_num++;
						}
						break;
					default:
						break;
					}

					break;
				case 'A':
				case 'a':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
					switch (map->map[y][x - 1])
					{
					case ' ':
					case 'X':
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i]] == '@')
							{
								boxx[i] = boxx[i] - 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////
						map->map[y][x - 1] = '@';
						map->map[y][x] = ' ';
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						x = x - 1;
						step_num++;
						break;
					case 'O':
					case 'Q':
						if (map->map[y][x - 2] != '#'&&map->map[y][x - 2] != 'O'&&map->map[y][x - 2] != 'Q'&&eat == 1) {
							for (int i = 0; i < box_count; i++)
							{
								if (map->map[boxy[i]][boxx[i] + 1] == '@')
								{
									boxx[i] = boxx[i] - 1;
									boxlocated_x[step_num + 1][i] = boxx[i];
									boxlocated_y[step_num + 1][i] = boxy[i];
								}
							}
							for (int i = 0; i < box_count; i++)
							{
								boxlocated_y[step_num + 1][i] = boxy[i];
								boxlocated_x[step_num + 1][i] = boxx[i];
							}////////////////////////
							if (map->map[y][x - 2] == 'X') {
								map->map[y][x - 2] = 'Q';
							}
							else {
								map->map[y][x - 2] = 'O';
							}
							map->map[y][x - 1] = '@';
							map->map[y][x] = ' ';
							Xlocated_x[step_num] = x;
							Xlocated_y[step_num] = y;
							x = x - 1;
							step_num++;
						}
						break;
					default:
						break;
					}

					break;
				case 'D':
				case 'd':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
					switch (map->map[y][x + 1])
					{
					case ' ':
					case 'X':
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i]] == '@')
							{
								boxx[i] = boxx[i] + 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////
						map->map[y][x + 1] = '@';
						map->map[y][x] = ' ';
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						x = x + 1;
						step_num++;
						break;
					case 'O':
					case 'Q':
						if (map->map[y][x + 2] != '#'&&map->map[y][x + 2] != 'O'&&map->map[y][x + 2] != 'Q'&&eat == 1) {
							for (int i = 0; i < box_count; i++)
							{
								if (map->map[boxy[i]][boxx[i] - 1] == '@')
								{
									boxx[i] = boxx[i] + 1;
								}
							}
							for (int i = 0; i < box_count; i++)
							{
								boxlocated_y[step_num + 1][i] = boxy[i];
								boxlocated_x[step_num + 1][i] = boxx[i];
							}////////////
							if (map->map[y][x + 2] == 'X') {
								map->map[y][x + 2] = 'Q';
							}
							else {
								map->map[y][x + 2] = 'O';
							}
							map->map[y][x + 1] = '@';
							map->map[y][x] = ' ';
							Xlocated_x[step_num] = x;
							Xlocated_y[step_num] = y;
							x = x + 1;
							step_num++;
						}
						break;

					default:
						break;
					}
					break;
				case 'R':
				case'r':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\specialsummon.wav"), NULL, SND_FILENAME | SND_ASYNC);
					scenes = 0;
					map = LoadMap(map->level);
					x = map->x;
					y = map->y;
					for (int i = 0; i < box_count; i++)
					{
						boxx[i] = map->boxx[i];
						boxy[i] = map->boxy[i];
					}
					eat = 1;
					step_num = 0;
					eat_count = 3;
					break;
				case 27:
					isEnd = 1;
					face = 2;
					break;
				case 'U':
				case'u':
					if (step_num > 0) {
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\info.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map->map[y][x] = ' ';
						x = (Xlocated_x[step_num - 1]);//取出最后一次人的坐标
						y = (Xlocated_y[step_num - 1]);
						map->map[Xlocated_y[step_num - 1]][Xlocated_x[step_num - 1]] = '@';//打印人
						for (int i = 0; i < box_count; i++) {//还吃的步数
							if (map->map[boxlocated_y[step_num][i]][boxlocated_x[step_num][i]] == '@' && map->map[boxlocated_y[step_num - 1][i]][boxlocated_x[step_num - 1][i]] != '@')
								eat_count++;
						}
						for (int i = 0; i < box_count; i++)//撤销箱子
						{
							map->map[boxy[i]][boxx[i]] = ' ';
						}
						for (int i = 0; i < box_count; i++)
						{
							boxx[i] = boxlocated_x[step_num - 1][i];
							boxy[i] = boxlocated_y[step_num - 1][i];
						}
						for (int i = 0; i < box_count; i++)
						{
							map->map[boxy[i]][boxx[i]] = 'O';
						}
						map->map[Xlocated_y[step_num - 1]][Xlocated_x[step_num - 1]] = '@';
						step_num--;
						break;
					}
					break;
				case'g':
				case'G':
					if (((map->map[y + 1][x] == 'O' || map->map[y + 1][x] == 'Q'&&eat == 1)) && eat_count > 0)//降低游戏难度，你可以吃箱子，按键后可以吃掉对应位置的箱子
					{
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\token.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map->map[y + 1][x] = ' ';
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i] - 1][boxx[i]] == '@')
							{
								boxy[i] = boxy[i] - 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////////////////
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						eat = 0;//改变eat，只能吃一个箱子
						eat_count--;//吃箱子的次数减一
						step_num++;
						break;
					}
					else if (map->map[y + 1][x] == ' ' && eat == 0)//吐箱子
					{
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\damage.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i]] == '@')
							{
								boxy[i] = boxy[i] + 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////////////////
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						map->map[y + 1][x] = 'O';
						eat = 1;//你又可以吃了
						step_num++;
						break;
					}
					else if (map->map[y + 1][x] == 'X' && eat == 0)
					{
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\damage.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i]] == '@')
							{
								boxy[i] = boxy[i] + 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////////////////
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						map->map[y + 1][x] = 'Q';
						eat = 1;
						step_num++;
						break;
					}
					break;
				case't':
				case'T':
					if (((map->map[y - 1][x] == 'O' || map->map[y - 1][x] == 'Q') && eat == 1) && eat_count > 0)
					{
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\token.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i] + 1][boxx[i]] == '@')
							{
								boxy[i] = boxy[i] + 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////////////////
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						map->map[y - 1][x] = ' ';
						eat = 0;
						eat_count--;
						step_num++;
						break;
					}
					else if (map->map[y - 1][x] == ' ' && eat == 0)
					{
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\damage.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i]] == '@')
							{
								boxy[i] = boxy[i] - 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////////////////
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						map->map[y - 1][x] = 'O';
						eat = 1;
						step_num++;
						break;
					}
					else if (map->map[y - 1][x] == 'X' && eat == 0)
					{
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\damage.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i]] == '@')
							{
								boxy[i] = boxy[i] - 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////////////////
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						map->map[y - 1][x] = 'Q';
						eat = 1;
						step_num++;
						break;
					}
					break;
				case'f':
				case'F':
					if (((map->map[y][x - 1] == 'O' || map->map[y][x - 1] == 'Q') && eat == 1) && eat_count > 0)
					{
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\token.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map->map[y][x - 1] = ' ';
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i] + 1] == '@')
							{
								boxx[i] = boxx[i] + 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////////////////
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						eat = 0;
						eat_count--;
						step_num++;
						break;
					}
					else if (map->map[y][x - 1] == ' ' && eat == 0)
					{
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\damage.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i]] == '@')
							{
								boxx[i] = boxx[i] - 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////////////////
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						map->map[y][x - 1] = 'O';
						eat = 1;
						step_num++;
						break;
					}
					else if (map->map[y][x - 1] == 'X' && eat == 0)
					{
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\damage.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i]] == '@')
							{
								boxx[i] = boxx[i] - 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////////////////
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						map->map[y][x - 1] = 'Q';
						eat = 1;
						step_num++;
						break;
					}
					break;
				case'h':
				case'H':
					if (((map->map[y][x + 1] == 'O' || map->map[y][x + 1] == 'Q') && eat == 1) && eat_count > 0)
					{
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\token.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map->map[y][x + 1] = ' ';
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i] - 1] == '@')
							{
								boxx[i] = boxx[i] - 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						eat = 0;
						eat_count--;
						step_num++;
						break;
					}
					else if (map->map[y][x + 1] == ' '&& eat == 0)
					{
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\damage.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i]] == '@')
							{
								boxx[i] = boxx[i] + 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						map->map[y][x + 1] = 'O';
						eat = 1;
						step_num++;
						break;
					}
					else if (map->map[y][x + 1] == 'X' && eat == 0)
					{
						if (setsound == 1)
							PlaySound(TEXT("data\\sound\\damage.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (int i = 0; i < box_count; i++)
						{
							if (map->map[boxy[i]][boxx[i]] == '@')
							{
								boxx[i] = boxx[i] + 1;
							}
						}
						for (int i = 0; i < box_count; i++)
						{
							boxlocated_y[step_num + 1][i] = boxy[i];
							boxlocated_x[step_num + 1][i] = boxx[i];
						}////////////
						Xlocated_x[step_num] = x;
						Xlocated_y[step_num] = y;
						map->map[y][x + 1] = 'Q';
						eat = 1;
						step_num++;
						break;
					}
					break;
				case'e':
				case'E':
					setmap();
					break;
				default:
					break;
				}
				break;
			}

			int isOver = 1;
			switch (scenes)
			{
			case 0:
				for (int i = 0; i < map->aim_count; i++) {
					if (map->map[map->aimy[i]][map->aimx[i]] != 'Q')
						isOver = 0;
				}
				if (isOver) {
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\nextturn.wav"), NULL, SND_FILENAME | SND_ASYNC);
					eat_count = 3;
					scenes = 1;
					if (level == level_knock[0]) {//关卡锁，记录到一个文件里
						FILE *fp = fopen("data//level_knock//knock.txt", "w");
						fprintf(fp, "%d", level_knock[0] + 1);
						fclose(fp);
						FILE *fpRead = fopen("data//level_knock//knock.txt", "r");  //其中"r"是表示读
						fscanf(fpRead, "%d ", &level_knock[0]);
						fclose(fpRead);/********************************************/
					}
				}

				for (int i = 0; i < map->aim_count; i++) {//消除一些bug
					if (map->map[map->aimy[i]][map->aimx[i]] == ' ')
						map->map[map->aimy[i]][map->aimx[i]] = 'X';
					if (map->map[map->aimy[i]][map->aimx[i]] == map->map[boxy[i]][boxx[i]])
						map->map[map->aimy[i]][map->aimx[i]] = 'Q';
					if ((map->map[map->aimy[i]][map->aimx[i]] == map->map[boxy[i]][boxx[i]]) && (map->map[map->aimy[i]][map->aimx[i]] == map->map[y][x]))
						map->map[map->aimy[i]][map->aimx[i]] = '@';
				}
				break;

			case 1:
				switch (key)
				{
				case's':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (face < 4) {
						face++;
						break;
					}
					if (scenes == 2 && face < 2) {
						face++;
						break;
					}
					else
						break;
				case'w':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (face > 1) {
						face--;
						break;
					}
					if (scenes == 2 && face > 1) {
						face--;
						break;
					}

					else
						break;
				case'j':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\question.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (face == 1) {
						scenes = 0;
						level++;
						map = LoadMap(map->level + 1);
						x = map->x;
						y = map->y;//
						box_count = map->box_count;
						for (int i = 0; i < map->box_count; i++)
						{
							boxx[i] = map->boxx[i];
							boxy[i] = map->boxy[i];
						}

						for (int i = 0; i < box_count; i++) {
							boxlocated_x[0][i] = boxx[i];
							boxlocated_y[0][i] = boxy[i];
						}
						step_num = 0;
						break;
					}
					if (face == 2) {
						gameloop(map->level);
						break;
					}
					if (face == 3) {
						scenes = 2;
						face = 1;
						break;
					}
					if (face == 4) {
						isEnd = 1;
						break;
					}
					else
						break;
				default:
					break;
				}

				break;
			case 2:
				switch (key) {
				case's':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (scenes == 2 && face < 2) {
						face++;
						break;
					}
					else
						break;
				case'w':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (scenes == 2 && face > 1) {
						face--;
						break;
					}
					else
						break;
				case'a':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (scenes == 2 && level > 0) {
						level--;
						level1--;
						break;
					}
					else
						break;
				case'd':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\phase.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (scenes == 2 && level < level_knock[0]) {
						level++;
						level1++;
						break;
					}
					else
						break;
				case'j':
					if (setsound == 1)
						PlaySound(TEXT("data\\sound\\question.wav"), NULL, SND_FILENAME | SND_ASYNC);
					if (scenes == 2 && face == 1) {
						scenes = 0;
						map = LoadMap(map->level + level1);
						x = map->x;
						y = map->y;//
						box_count = map->box_count;
						for (int i = 0; i < map->box_count; i++)
						{
							boxx[i] = map->boxx[i];
							boxy[i] = map->boxy[i];
						}

						for (int i = 0; i < box_count; i++) {
							boxlocated_x[0][i] = boxx[i];
							boxlocated_y[0][i] = boxy[i];
						}
						step_num = 0;
						break;
						break;
					}
					if (scenes == 2 && face == 2) {
						scenes = 1;
						break;
					}
					else
						break;
				default:
					break;
				}
			default:
				break;
			}

			if (isEnd)
				break;
		}
	}
	return 0;
}

Map* LoadMap(int level) {

	Map *temp = (Map*)malloc(sizeof(Map));
	char buffer[256];

	FILE *fp;
	sprintf(buffer, "data/Map/%d.txt", level);
	fp = fopen(buffer, "r");

	temp->level = level;
	temp->aim_count = 0;
	temp->box_count = 0;

	for (int i = 0;; i++) {//循环读取文件内容，直到达到退出条件
		fgets(temp->map[i], 256, fp);//读取一行字符串

		temp->map[i][strlen(temp->map[i]) - 1] = '\0';//在字符串末尾手动加上结束符'\0'

		for (int j = 0; temp->map[i][j] != '\0'; j++) {
			switch (temp->map[i][j]) {
			case '@':
				temp->x = j;
				temp->y = i;
				break;
			case 'X':
				temp->aimx[temp->aim_count] = j;
				temp->aimy[temp->aim_count] = i;
				temp->aim_count++;
				break;
			case'O':
				temp->boxx[temp->box_count] = j;
				temp->boxy[temp->box_count] = i;
				temp->box_count++;
				break;
			case 'Q':
				temp->aimx[temp->aim_count] = j;
				temp->aimy[temp->aim_count] = i;
				temp->aim_count++;
				temp->boxx[temp->box_count] = j;
				temp->boxy[temp->box_count] = i;
				temp->box_count++;
				break;
			}
		}

		if (temp->map[i][1] == '|') {//当字符串第二位出现'|'时表示该行为最后一行，文件读取结束
			temp->map[i][1] = '=';//将该位字符设置为'='
			temp->h = i + 1;
			break;//跳出循环
		}
	}

	fclose(fp);
	return temp;
}




Map* setmap()//地图编辑器
{
	struct MYPOINTS
	{
		int x;
		int y;
	};
	Map *temp1 = (Map*)malloc(sizeof(Map));
	char buffer1[256] = { 0 };

	int isend = 0;
	int nowTile = 6;
	setinitmode(INIT_ANIMATION);//这个函数用于设置初始化图形的选项和模式。
	PIMAGE b1 = newimage();
	getimage(b1, "data\\image\\地.jpg");
	PIMAGE b2 = newimage();
	getimage(b2, "data\\image\\墙1.jpg");
	PIMAGE b3 = newimage();
	getimage(b3, "data\\image\\墙2.jpg");
	PIMAGE b4 = newimage();
	getimage(b4, "data\\image\\箱子.jpg");
	PIMAGE b5 = newimage();
	getimage(b5, "data\\image\\目标.jpg");
	PIMAGE b6 = newimage();
	getimage(b6, "data\\image\\人.jpg");

	PIMAGE b7 = newimage();
	getimage(b7, "data\\image\\智障地图编辑器.jpg");


	putimage(0,0, b7);

	FILE* f;//初始化地图
	sprintf(buffer1, "data//Map//0.txt");
	f = fopen(buffer1, "w");		for (int x = 0; x < 10; x++)
	{
		for (int y = 1; y < 9; y++)
		{
			for (int x = 1; x < 9; x++)
			temp1->map[y][x] = ' ';
		}
	}
	fclose(f);

	for (; is_run(); delay_fps(30))
	{
		int x, y;
		if (GetAsyncKeyState(VK_LBUTTON) == 0x8001I16)	//如果鼠标左键按下了
		{
			mousepos(&x, &y);		//把鼠标坐标位置赋值给xy
			if (x > 0 && x < 500 && y>50 && y < 450)
			{
				temp1->map[x / 50][y / 50] = nowTile;
			}
			else if (x > 500 && x < 550 && y>0 && y < 50)
				isend = 1;
			else if (x > 0 && x < 300 && y>550 && y < 600)
			{
				if (x / 50 == 0)
					nowTile = ' ';
				else if (x / 50 == 1)//
					nowTile = '=';
				else if (x / 50 == 2)//
					nowTile = '#';
				else if (x / 50 == 3)
					nowTile = 'O';
				else if (x / 50 == 4)
					nowTile = 'X';
				else if (x / 50 == 5)
					nowTile = '@';
			}
			FILE* f;
			sprintf(buffer1, "data//Map//0.txt");
			f = fopen(buffer1, "w");
			for (int y = 0; y < 10; y++)
			{
				temp1->map[y][strlen(temp1->map[y]) - 1] = '\0';
				for (int x = 0; x < 10; x++)
				{
					if (x == 0 && y != 9)
						fprintf(f, "|", temp1->map[y][x]);//强行统一地图格式
					else if (x == 0 && y == 9)
						fprintf(f, "||", temp1->map[y][x]);
					else if (x == 9)
						fprintf(f, "|\n", temp1->map[y][x]);
					else
						fprintf(f, "%c", temp1->map[y][x]);
				}
			}
			fclose(f);
		}

		//专门贴地板
		for (int x = 1; x < 9; x++)
		{
			for (int y = 1; y < 9; y++)
			{
				putimage(y * 50, x * 50, b1);
			}
		}

		for (int y = 0; y < 10; y++)
		{
			for (int x = 1; x < 9; x++)
			{
				switch (temp1->map[y][x])
				{
				case '=':	
					putimage(y * 50, x * 50, b2);
					break;
				case '#':
					putimage(y * 50, x * 50, b3);
					break;
				case 'X':
					putimage(y * 50, x * 50, b5);
					break;
				case '@':
					putimage(y * 50, x * 50, b6);
					break;
				case 'O':
					putimage(y * 50, x * 50, b4);
					break;
				default:
					break;
				}

			}
		}

		putimage(0 * 50, 550, b1);

		putimage(1 * 50, 550, b2);

		putimage(2 * 50, 550, b3);

		putimage(3 * 50, 550, b4);

		putimage(4 * 50, 550, b5);

		putimage(5 * 50, 550, b6);
		if (isend)
			return temp1;
	}
	

}