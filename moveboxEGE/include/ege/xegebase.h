
#ifndef _XEGEBASE_H_
#define _XEGEBASE_H_

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif

#ifndef _CRT_NON_CONFORMING_SWPRINTFS
#define _CRT_NON_CONFORMING_SWPRINTFS
#endif

#ifdef _MSC_VER
#pragma warning(disable: 4996)
#endif

#ifdef RGB
#undef RGB
#endif

#define RGB(r, g, b) (0xFF000000|((r)<<16)|((g)<<8)|(b))
#define RGBA(r, g, b, a) (((a)<<24)|((r)<<16)|((g)<<8)|(b))
#define RGBGetR(col) (0xFF & ((col)>>16))
#define RGBGetG(col) (0xFF & ((col)>> 8))
#define RGBGetB(col) (0xFF & ((col)))
#define RGBGetA(col) (0xFF & ((col)>>24))

#if !defined(FALSE) && !defined(TRUE)
typedef int     BOOL;
#define TRUE    1
#define FALSE   0
#endif

#define NAMESPACE_DEF
#include "xegehead.h"
#undef  NAMESPACE_DEF

#include <math.h>

NAMESPACE_BEG

enum {
    ege_infinite    = 0xFFFFFFFF,
};

#ifndef PI
#define PI  3.1415926535897932384
#endif

typedef enum err_code_e {
    err_failure     = -1,
    err_success     = 0,
    err_mallocfail  = 1,
    err_initfail    = 2,
    err_overflow    = 3,
    err_paramerr    = 4,
    err_fileio      = 5,
    err_libver      = 0x10,
}err_code_e;

typedef enum init_mode_e {
    init_flip_y = 1,
}init_mode_e;

typedef unsigned char   ubyte;
typedef unsigned short  ushort;
typedef unsigned int    uint32;
typedef signed int      int32;
typedef unsigned int    col_t;
typedef float           float32;
typedef char*           pchar;
typedef const char*     pcchar;
typedef FILE*           PFILE;

typedef struct point_t {
    int32 x;
    int32 y;
}point_t;

typedef struct pointf_t {
    float32 x;
    float32 y;
}pointf_t;

typedef struct rect_t {
    int32 x1;
    int32 y1;
    int32 x2;
    int32 y2;
}rect_t;

typedef struct rectf_t {
    float32 x1;
    float32 y1;
    float32 x2;
    float32 y2;
}rectf_t;

typedef struct key_msg {
    uint32 msg;
    uint32 key;
    uint32 flags;
}key_msg;

typedef struct mouse_msg {
    uint32 msg;
    int32 x;
    int32 y;
    uint32 flags;
}mouse_msg;

struct image_buf;
typedef image_buf* image;

typedef enum key_msgflag_e {
    key_msg_down    = 1,
    key_msg_up      = 2,
    key_flag_shift  = 0x100,
    key_flag_ctrl   = 0x200,
}key_msgflag_e;

typedef enum mouse_msgflag_e {
    mouse_msg_down      = 0x10,
    mouse_msg_up        = 0x20,
    mouse_msg_move      = 0x40,

    mouse_flag_left     = 1,
    mouse_flag_right    = 2,
    mouse_flag_shift    = 0x100,
    mouse_flag_ctrl     = 0x200,
}mouse_msgflag_e;

// color enum value
typedef enum colors_e {
    col_black           = 0xff000000,
    col_blue            = 0xff0000a8,
    col_green           = 0xff00a800,
    col_cyan            = 0xff00a8a8,
    col_red             = 0xffa80000,
    col_magenta         = 0xffa800a8,
    col_brown           = 0xffa85400,
    col_lightgray       = 0xffa8a8a8,
    col_darkgray        = 0xff545454,
    col_lightblue       = 0xff5454fc,
    col_lightgreen      = 0xff54fc54,
    col_lightcyan       = 0xff54fcfc,
    col_lightred        = 0xfffc5454,
    col_lightmagenta    = 0xfffc54fc,
    col_yellow          = 0xfffcfc54,
    col_white           = 0xfffcfcfc,
}colors_e;

// key code
typedef enum key_code_e {
    // ASCII set. Should be supported everywhere
    key_mouse_l        = 1,
    key_mouse_r        = 2,
    key_backspace      = 8,
    key_tab            = 9,
    key_clear          = 12,
    key_return         = 13,
    key_pause          = 19,
    key_escape         = 27,
    key_space          = 32,

    // Keypad 
    key_delete         = 127,
    key_kp0            = 256,
    key_kp1            = 257,
    key_kp2            = 258,
    key_kp3            = 259,
    key_kp4            = 260,
    key_kp5            = 261,
    key_kp6            = 262,
    key_kp7            = 263,
    key_kp8            = 264,
    key_kp9            = 265,
    key_kp_period      = 266,
    key_kp_divide      = 267,
    key_kp_multiply    = 268,
    key_kp_minus       = 269,
    key_kp_plus        = 270,
    key_kp_enter       = 271,
    key_kp_equals      = 272,

    // Arrow-keys and stuff
    key_up             = 273,
    key_down           = 274,
    key_right          = 275,
    key_left           = 276,
    key_insert         = 277,
    key_home           = 278,
    key_end            = 279,
    key_page_up        = 280,
    key_page_down      = 281,

    // Functional keys. You'd better avoid using
    // f11...f15 in your applications if you want 
    // the applications to be portable
    key_f1             = 282,
    key_f2             = 283,
    key_f3             = 284,
    key_f4             = 285,
    key_f5             = 286,
    key_f6             = 287,
    key_f7             = 288,
    key_f8             = 289,
    key_f9             = 290,
    key_f10            = 291,
    key_f11            = 292,
    key_f12            = 293,
    key_f13            = 294,
    key_f14            = 295,
    key_f15            = 296,

    // The possibility of using these keys is 
    // very restricted. Actually it's guaranteed 
    // only in win32_api and win32_sdl implementations
    key_numlock        = 300,
    key_capslock       = 301,
    key_scrollock      = 302,

    // Phew!
    end_of_key_codes
}key_code_e;

#ifdef __cplusplus

struct VECTOR3D {
    float x, y, z;
    VECTOR3D() {
        x = 0; y = 0; z = 0;
    }
    VECTOR3D(float _x, float _y) {
        x = _x; y = _y; z = 0;
    }
    VECTOR3D(float _x, float _y, float _z) {
        x = _x; y = _y; z = _z;
    }
    VECTOR3D& operator = (const VECTOR3D& _fp)  {
        x = _fp.x; y = _fp.y; z = _fp.z;
        return *this;
    }
    VECTOR3D& operator += (const VECTOR3D& _fp);
    VECTOR3D& operator -= (const VECTOR3D& _fp);
    VECTOR3D operator + (const VECTOR3D& _fp) const;
    VECTOR3D operator - (const VECTOR3D& _fp) const;
    VECTOR3D& operator *= (float f);
    VECTOR3D operator * (float f) const;
    float operator * (const VECTOR3D& _fp) const;
    VECTOR3D operator & (const VECTOR3D& _fp) const;
    VECTOR3D& operator &= (const VECTOR3D& _fp);
    float GetModule() const {
        return (float)sqrt(x*x + y*y + z*z);
    }
    float GetSqrModule() const {
        return float(x*x + y*y + z*z);
    }
    VECTOR3D& SetModule(float m) {
        float t = m / GetModule();
        *this *= t;
        return *this;
    }
    VECTOR3D& Rotate(float rad, const VECTOR3D& v);
    VECTOR3D& Rotate(float rad, float x, float y, float z) {
        VECTOR3D v(x, y, z);
        return Rotate(rad, v);
    }
    VECTOR3D& Rotate(const VECTOR3D& e, const VECTOR3D& s = VECTOR3D(0.0f, 0.0f, 1.0f)); //between s to e
    static float GetAngel(const VECTOR3D& e, const VECTOR3D& s = VECTOR3D(0.0f, 0.0f, 1.0f));
};

// 3d rotate function
void rotate_point3d_x(VECTOR3D  * pt, float r); //right-hand
void rotate_point3d_y(VECTOR3D  * pt, float r);
void rotate_point3d_z(VECTOR3D  * pt, float r);

#endif

NAMESPACE_END


extern "C" int ege_main(int argc, char* argv[]);


#endif

