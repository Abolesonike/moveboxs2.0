
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

// 图形化初始函数
err_code_e  initgraph(ver_e _ege_ver, int32 width, int32 height);
err_code_e  initgraphex(ver_e _ege_ver, int32 width, int32 height, uint32 mode);
void        closegraph();
// 判断UI是否退出
BOOL is_run();
//设置标题
void setcaption(pcchar str);
//获取版本号
pcchar getver();
//err_code_e run();

// 输入函数
int32       kbmsg();
key_msg     getkey();
uint32      getkeypress();
int32       mousehit();
mouse_msg   getmouse();
int32       waitmsg(uint32 waittime); // 使用 ege_infinite 来无限等待
BOOL        keystate(int32 key);
#define     getch getkeypress
#define     kbhit kbmsg

// 时间函数
void    delay_ms(uint32 ms);
void    delay_fps(uint32 fps);
double  fclock();
float32 getfps();
#define delay delay_ms

// 绘图目标
image   gettarget();
int32   settarget(image pbuf); // 用 NULL 设置窗口为绘图目标

// 绘图属性
void    setcolor(col_t color);
void    setfillcolor(col_t color);
void    setclearcolor(col_t color);

rect_t  getviewport();
void    setviewport(int32 x, int32 y, int32 w, int32 h); // 不会改变原点坐标，改变绘图目标后，可能需要重新setviewport（如果不是需要整个图绘画）

void    enable_antialias(BOOL val);
void    enable_bilinear (BOOL val);

// 绘图函数
void    cleardevice();
void    clearcolor (col_t color);

col_t   getpixel(int32 x, int32 y);
void    putpixel(int32 x, int32 y, col_t color);

void    setlinewidth(int32 w);
void    line(int32 x1, int32 y1, int32 x2, int32 y2);
void    linef(float32 x1, float32 y1, float32 x2, float32 y2);
void    linef_f(float32 x1, float32 y1, float32 x2, float32 y2); // no alphablend, just alpha value set, no width, no antialias

int32   lines_begin(); // 以下四个函数要匹配使用，一个begin必须对应一个end，中间就是画线控制
void    lines_moveto(float32 x, float32 y);
void    lines_lineto(float32 x, float32 y);
void    lines_end();

void    drawpoly (uint32 numpoint, const point_t * polypoints);
void    drawpolyf(uint32 numpoint, const pointf_t * polypoints);
void    drawpoly_f(uint32 numpoint, const point_t * polypoints); // no alphablend, just alpha value set, no width, no antialias
void    fillpoly (uint32 numpoint, const point_t * polypoints);
void    fillpolyf(uint32 numpoint, const pointf_t * polypoints);

void    rectangle(int32 left, int32 top, int32 right, int32 bottom); // 画矩形
void    bar      (int32 left, int32 top, int32 right, int32 bottom); // 画实心矩形

void    ellipse     (float32 x, float32 y, float32 rx, float32 ry); // 画椭圆边框
void    fillellipse (float32 x, float32 y, float32 rx, float32 ry); // 画实心椭圆

/* arc圆弧函数待补充 */

// 文字函数
void    outtextxy (int32 x, int32 y, pcchar str);
int32   textwidth (pcchar str);
int32   textheight(pcchar str);

// 图片函数
image   newimage(int32 width, int32 height); // 新建图片
void    release  (image img); // 删除图片
int32   getwidth (image img); // 用 NULL 获取窗口尺寸
int32   getheight(image img); // 用 NULL 获取窗口尺寸
#define getmaxx getwidth
#define getmaxy getheight

void        getimage(image imgdest, int32 x, int32 y, int32 w, int32 h);
void        getimage_fromimg(image imgdest, image img, int32 x, int32 y, int32 w, int32 h);
err_code_e  getimage_frombmp(image img, pcchar filename);
err_code_e  getimage_frompng(image img, pcchar filename); // 现阶段会有问题，待测试
void        putimage(image img, int32 x, int32 y); // 凡以下putimage开头的函数，参数img不得为NULL
void        putimage_f(image img, int32 x, int32 y); // no alphablend
void        putimage_blt(image img, int32 x, int32 y, int32 srcx, int32 srcy, int32 srcw, int32 srch);
void        putimage_blt_f(image img, int32 x, int32 y, int32 srcx, int32 srcy, int32 srcw, int32 srch); // no alphablend
void        putimage_scale(image img, int32 x, int32 y, int32 w, int32 h, int32 srcx, int32 srcy, int32 srcw, int32 srch);
void        putimage_rotate(image img, float32 x, float32 y,float32 srccenterx, float32 srccentery, float32 radian); // center x/y in range [0.0, 1.0]
void        putimage_rotatescale(image img, float32 x, float32 y, float32 srccenterx, float32 srccentery, float32 radian, float32 scalex, float32 scaley);
void        putimage_rotatescaleex(image img, float32 x, float32 y, float32 srccenterx, float32 srccentery, float32 radian,
                                   int32 srcx, int32 srcy, int32 srcw, int32 srch, float32 scalex, float32 scaley);
err_code_e  saveimage_bmp(image img, pcchar filename);
err_code_e  saveimage_png(image img, pcchar filename, int bAlpha); // bAlpha: 保存 alpha 通道信息，现阶段会有问题

// 图片高级变换
void    putimage_bilinear(image img, const pointf_t* pt);
void    putimage_perspective(image img, const pointf_t* pt);  // pt 指向一个包含四个点的数组，y向上时逆时针描述，否则顺时针，这个pt所描述的必须为凸四边形

err_code_e  imagefilter_blur_simple(int32 x, int32 y, int32 w, int32 h, int32 intensity, int32 alpha); // 速度最快的模糊
void        imagefilter_blur_stack (int32 x, int32 y, int32 w, int32 h, uint32 r); // 速度慢一些的模糊，r是模糊半径
void        imagefilter_blur_gauss (int32 x, int32 y, int32 w, int32 h, float32 r); // 速度最慢的高斯模糊，质量最好，r是模糊半径

//随机函数
void    ege_randomize();
uint32  ege_random(uint32 n);
double  ege_randomf();

#define randomize   ege_randomize
#define random      ege_random
#define randomf     ege_randomf

// 颜色模型转换函数
col_t   RGBtoGRAY(col_t rgb);
void    RGBtoHSL(col_t rgb, float32 *H, float32 *S, float32 *L);
void    RGBtoHSV(col_t rgb, float32 *H, float32 *S, float32 *V);
col_t   HSLtoRGB(float32 H, float32 S, float32 L);
col_t   HSVtoRGB(float32 H, float32 S, float32 V);

// 数据压缩函数
int             ege_compress(void *dest, unsigned long *destLen, const void *source, unsigned long sourceLen);
int             ege_compress2(void *dest, unsigned long *destLen, const void *source, unsigned long sourceLen, int level);
int             ege_uncompress(void *dest, unsigned long *destLen, const void *source, unsigned long sourceLen);
unsigned long   ege_uncompress_size(const void *source, unsigned long sourceLen); /* 返回0表示错误，其它表示大小 */

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
