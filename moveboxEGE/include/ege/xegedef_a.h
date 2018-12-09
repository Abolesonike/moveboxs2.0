
#ifndef _XEGEDEF_H_
#define _XEGEDEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xegebase.h"

#if !defined(_GRAPH_LIB_BUILD_) && !defined(_GRAPH_NO_LIB_)
    #ifdef _MSC_VER
        #if (_MSC_VER >= 1600)
            #if defined(_DLL)
                #pragma comment(lib,"xegelib10d.lib")
            #else
                #pragma comment(lib,"xegelib.lib")
            #endif
        #elif (_MSC_VER >= 1500)
            #if defined(_DLL)
                #pragma comment(lib,"xegelibd.lib")
            #else
                #pragma comment(lib,"xegelib.lib")
            #endif
        #elif (_MSC_VER > 1200)
            #pragma comment(lib,"xegelib06.lib")
        #else
            #pragma comment(lib,"xegelib06.lib")
        #endif
        #if _MSC_VER >= 1600
            #ifdef _DEBUG
                //#pragma comment(linker, "/NODEFAULTLIB:libcmtd.lib")
                //#pragma comment(linker, "/NODEFAULTLIB:libcmt.lib")
                //#pragma comment(linker, "/NODEFAULTLIB:libcpmt.lib")
                //#pragma comment(linker, "/NODEFAULTLIB:libc.lib")
            #else
            #endif
        #elif _MSC_VER > 1200
            #ifdef _DEBUG
                #pragma comment(linker, "/NODEFAULTLIB:libcmtd.lib")
                //#pragma comment(linker, "/NODEFAULTLIB:libcmt.lib")
                //#pragma comment(linker, "/NODEFAULTLIB:libcpmt.lib")
                #pragma comment(linker, "/NODEFAULTLIB:libc.lib")
            #else
            #endif
        #else
            #pragma comment(linker, "/NODEFAULTLIB:MSVCRT.lib")
            #pragma comment(linker, "/NODEFAULTLIB:MSVCRTD.lib")
            #ifdef _DEBUG
                #pragma comment(linker, "/NODEFAULTLIB:libcd.lib")
                #pragma comment(linker, "/NODEFAULTLIB:libcmt.lib")
                #pragma comment(linker, "/NODEFAULTLIB:libcpmt.lib")
            #else
            #endif
        #endif
    #endif
#endif

NAMESPACE_BEG

enum ver_e {
    ege_ver = 20110710,
};

EGEEXTERNC

// ͼ�λ���ʼ����
err_code_e  initgraph(ver_e _ege_ver, int32 width, int32 height);
err_code_e  initgraphex(ver_e _ege_ver, int32 width, int32 height, uint32 mode);
void        closegraph();
// �ж�UI�Ƿ��˳�
BOOL is_run();
//���ñ���
void setcaption(pcchar str);
//��ȡ�汾��
pcchar getver();
//err_code_e run();

// ���뺯��
int32       kbmsg();
key_msg     getkey();
uint32      getkeypress();
int32       mousehit();
mouse_msg   getmouse();
int32       waitmsg(uint32 waittime); // ʹ�� ege_infinite �����޵ȴ�
BOOL        keystate(int32 key);
#define     getch getkeypress
#define     kbhit kbmsg

// ʱ�亯��
void    delay_ms(uint32 ms);
void    delay_fps(uint32 fps);
double  fclock();
float32 getfps();
#define delay delay_ms

// ��ͼĿ��
image   gettarget();
int32   settarget(image pbuf); // �� NULL ���ô���Ϊ��ͼĿ��

// ��ͼ����
void    setcolor(col_t color);
void    setfillcolor(col_t color);
void    setclearcolor(col_t color);

rect_t  getviewport();
void    setviewport(int32 x, int32 y, int32 w, int32 h); // ����ı�ԭ�����꣬�ı��ͼĿ��󣬿�����Ҫ����setviewport�����������Ҫ����ͼ�滭��

void    enable_antialias(BOOL val);
void    enable_bilinear (BOOL val);

// ��ͼ����
void    cleardevice();
void    clearcolor (col_t color);

col_t   getpixel(int32 x, int32 y);
void    putpixel(int32 x, int32 y, col_t color);

void    setlinewidth(int32 w);
void    line(int32 x1, int32 y1, int32 x2, int32 y2);
void    linef(float32 x1, float32 y1, float32 x2, float32 y2);
void    linef_f(float32 x1, float32 y1, float32 x2, float32 y2); // no alphablend, just alpha value set, no width, no antialias

int32   lines_begin(); // �����ĸ�����Ҫƥ��ʹ�ã�һ��begin�����Ӧһ��end���м���ǻ��߿���
void    lines_moveto(float32 x, float32 y);
void    lines_lineto(float32 x, float32 y);
void    lines_end();

void    drawpoly (uint32 numpoint, const point_t * polypoints);
void    drawpolyf(uint32 numpoint, const pointf_t * polypoints);
void    drawpoly_f(uint32 numpoint, const point_t * polypoints); // no alphablend, just alpha value set, no width, no antialias
void    fillpoly (uint32 numpoint, const point_t * polypoints);
void    fillpolyf(uint32 numpoint, const pointf_t * polypoints);

void    rectangle(int32 left, int32 top, int32 right, int32 bottom); // ������
void    bar      (int32 left, int32 top, int32 right, int32 bottom); // ��ʵ�ľ���

void    ellipse     (float32 x, float32 y, float32 rx, float32 ry); // ����Բ�߿�
void    fillellipse (float32 x, float32 y, float32 rx, float32 ry); // ��ʵ����Բ

/* arcԲ������������ */

// ���ֺ���
void    outtextxy (int32 x, int32 y, pcchar str);
int32   textwidth (pcchar str);
int32   textheight(pcchar str);

// ͼƬ����
image   newimage(int32 width, int32 height); // �½�ͼƬ
void    release  (image img); // ɾ��ͼƬ
int32   getwidth (image img); // �� NULL ��ȡ���ڳߴ�
int32   getheight(image img); // �� NULL ��ȡ���ڳߴ�
#define getmaxx getwidth
#define getmaxy getheight

void        getimage(image imgdest, int32 x, int32 y, int32 w, int32 h);
void        getimage_fromimg(image imgdest, image img, int32 x, int32 y, int32 w, int32 h);
err_code_e  getimage_frombmp(image img, pcchar filename);
err_code_e  getimage_frompng(image img, pcchar filename); // �ֽ׶λ������⣬������
void        putimage(image img, int32 x, int32 y); // ������putimage��ͷ�ĺ���������img����ΪNULL
void        putimage_f(image img, int32 x, int32 y); // no alphablend
void        putimage_blt(image img, int32 x, int32 y, int32 srcx, int32 srcy, int32 srcw, int32 srch);
void        putimage_blt_f(image img, int32 x, int32 y, int32 srcx, int32 srcy, int32 srcw, int32 srch); // no alphablend
void        putimage_scale(image img, int32 x, int32 y, int32 w, int32 h, int32 srcx, int32 srcy, int32 srcw, int32 srch);
void        putimage_rotate(image img, float32 x, float32 y,float32 srccenterx, float32 srccentery, float32 radian); // center x/y in range [0.0, 1.0]
void        putimage_rotatescale(image img, float32 x, float32 y, float32 srccenterx, float32 srccentery, float32 radian, float32 scalex, float32 scaley);
void        putimage_rotatescaleex(image img, float32 x, float32 y, float32 srccenterx, float32 srccentery, float32 radian,
                                   int32 srcx, int32 srcy, int32 srcw, int32 srch, float32 scalex, float32 scaley);
err_code_e  saveimage_bmp(image img, pcchar filename);
err_code_e  saveimage_png(image img, pcchar filename, int bAlpha); // bAlpha: ���� alpha ͨ����Ϣ���ֽ׶λ�������

// ͼƬ�߼��任
void    putimage_bilinear(image img, const pointf_t* pt);
void    putimage_perspective(image img, const pointf_t* pt);  // pt ָ��һ�������ĸ�������飬y����ʱ��ʱ������������˳ʱ�룬���pt�������ı���Ϊ͹�ı���

err_code_e  imagefilter_blur_simple(int32 x, int32 y, int32 w, int32 h, int32 intensity, int32 alpha); // �ٶ�����ģ��
void        imagefilter_blur_stack (int32 x, int32 y, int32 w, int32 h, uint32 r); // �ٶ���һЩ��ģ����r��ģ���뾶
void        imagefilter_blur_gauss (int32 x, int32 y, int32 w, int32 h, float32 r); // �ٶ������ĸ�˹ģ����������ã�r��ģ���뾶

//�������
void    ege_randomize();
uint32  ege_random(uint32 n);
double  ege_randomf();

#define randomize   ege_randomize
#define random      ege_random
#define randomf     ege_randomf

// ��ɫģ��ת������
col_t   RGBtoGRAY(col_t rgb);
void    RGBtoHSL(col_t rgb, float32 *H, float32 *S, float32 *L);
void    RGBtoHSV(col_t rgb, float32 *H, float32 *S, float32 *V);
col_t   HSLtoRGB(float32 H, float32 S, float32 L);
col_t   HSVtoRGB(float32 H, float32 S, float32 V);

// ����ѹ������
int             ege_compress(void *dest, unsigned long *destLen, const void *source, unsigned long sourceLen);
int             ege_compress2(void *dest, unsigned long *destLen, const void *source, unsigned long sourceLen, int level);
int             ege_uncompress(void *dest, unsigned long *destLen, const void *source, unsigned long sourceLen);
unsigned long   ege_uncompress_size(const void *source, unsigned long sourceLen); /* ����0��ʾ����������ʾ��С */

EGEEXTERNED

NAMESPACE_END

#if defined(_MSC_VER) && (defined(HIDE_CONSOLE) || !defined(SHOW_CONSOLE))
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"WinMainCRTStartup\"" )
#endif

#if !defined(_GRAPH_LIB_BUILD_)
    #if !defined(_MSC_VER)
        #define WinMain(...) ege_main(int argc, char* argv[])
    #elif (_MSC_VER > 1200)
        #define WinMain(...) ege_main(int argc, char* argv[])
    #else
        #define WinMain() ege_main(int argc, char* argv[])
    #endif
#endif

#endif
