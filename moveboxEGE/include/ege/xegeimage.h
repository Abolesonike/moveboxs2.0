#ifndef _XEGEIMAGE_H_
#define _XEGEIMAGE_H_

#ifndef __cplusplus
#error "With include xegeimage.h, You must use C++ compiler. Please confirm that your filename's suffix is '.cpp'"
#endif

#ifndef _XEGE_H_
#error "You must include 'xege.h' before include 'xegeimage.h'"
#endif

#include "xegebase.h"

NAMESPACE_BEG

class IMAGE
{
public:
    IMAGE()
    {
        m_img = newimage(0, 0);
    }
    IMAGE(int32 w, int32 h)
    {
        m_img = newimage(w, h);
    }
    IMAGE(const image img)
    {
        m_img = newimage(0, 0);
        getimage_fromimg(m_img, img, 0, 0, getwidth(img), getheight(img));
    }
    IMAGE& operator = (const image img)
    {
        getimage_fromimg(m_img, img, 0, 0, getwidth(img), getheight(img));
        return *this;
    }
    operator image ()
    {
        return m_img;
    }
    image operator &()
    {
        return m_img;
    }
    int32 width()
    {
        return getwidth(m_img);
    }
    int32 height()
    {
        return getheight(m_img);
    }
    ~IMAGE()
    {
        release(m_img);
        m_img = NULL;
    }
private:
    image m_img;
};

NAMESPACE_END

#endif
