#include"function.h"

int main()
{
#define Win_L 1024
#define Win_H 620

	
	ege::setinitmode(ege::INIT_ANIMATION);
	// ͼ�γ�ʼ��
	ege::initgraph(Win_L, Win_H);
	setcaption("������"); //�޸Ĵ�������
	// �������ʼ���������Ҫʹ��������Ļ�
	ege::randomize();
	// ������ѭ��
	mainloop();
	// �رջ�ͼ�豸
	ege::closegraph();
	return 0;
}