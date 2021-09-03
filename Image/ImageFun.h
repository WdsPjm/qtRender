//
// Created by WDS on 2021/8/29.
//

#ifndef QTOPENGL_IMAGEFUN_H
#define QTOPENGL_IMAGEFUN_H
#include "windows.h"

enum IMAGETYPE{
    IF_JEGP,
    IF_PNG,
    IF_BNP,
};

class ImageFun {
public:
    ImageFun();
    ~ImageFun();

static bool WriteBitmapFile(char * filename, int wid, int hei, unsigned char * bitmapData);
static void snap_shot(int img_w, int img_h);

IMAGETYPE getFormat();

private:
    IMAGETYPE mformat;

};


#endif //QTOPENGL_IMAGEFUN_H
