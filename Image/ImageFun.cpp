//
// Created by WDS on 2021/8/29.
//

#include "ImageFun.h"
#include "stdio.h"
#include "gl/glew.h"
#include <QString>
#include <string>
ImageFun::ImageFun() {

}

ImageFun::~ImageFun() {

}

bool ImageFun::WriteBitmapFile(char *filename, int wid, int hei, unsigned char *bitmapData) {

    int width = wid;
    int height = hei;

    BITMAPFILEHEADER bitmapFileHeader;
    memset(&bitmapFileHeader, 0, sizeof(BITMAPFILEHEADER));
    bitmapFileHeader.bfSize = sizeof(BITMAPFILEHEADER);
    bitmapFileHeader.bfType = 0x4d42;	//BM
    bitmapFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    //填充BITMAPINFOHEADER
    BITMAPINFOHEADER bitmapInfoHeader;
    memset(&bitmapInfoHeader, 0, sizeof(BITMAPINFOHEADER));
    bitmapInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
    bitmapInfoHeader.biWidth = width;
    bitmapInfoHeader.biHeight = height;
    bitmapInfoHeader.biPlanes = 1;
    bitmapInfoHeader.biBitCount = 24;
    bitmapInfoHeader.biCompression = BI_RGB;
    bitmapInfoHeader.biSizeImage = width * abs(height) * 3;

    //
    FILE * filePtr;
    unsigned char tempRGB;
    int imageIdx;

    //swap R B
    for (imageIdx = 0; imageIdx < bitmapInfoHeader.biSizeImage; imageIdx += 3)
    {
        tempRGB = bitmapData[imageIdx];
        bitmapData[imageIdx] = bitmapData[imageIdx + 2];
        bitmapData[imageIdx + 2] = tempRGB;
    }

    filePtr = fopen(filename, "wb");
    if (NULL == filePtr)
    {
        return FALSE;
    }

    fwrite(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);

    fwrite(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);

    fwrite(bitmapData, bitmapInfoHeader.biSizeImage, 1, filePtr);

    fclose(filePtr);
    return TRUE;

}
static int numbe =0;
void ImageFun::snap_shot(int img_w, int img_h) {
    GLubyte* pPixelData;
    GLint line_width;
    GLint PixelDataLength;

    line_width = img_w * 3; // 得到每一行的像素数据长度
    line_width = (line_width + 3) / 4 * 4;

    PixelDataLength = line_width * img_h;

    // 分配内存和打开文件
    pPixelData = (GLubyte*)malloc(PixelDataLength);
    if (pPixelData == 0)
        exit(0);


    // 读取像素
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

    //glReadPixels(0, 0, img_w, img_h, GL_BGR_EXT, GL_UNSIGNED_BYTE, pPixelData);
    glReadPixels(0, 0, img_w, img_h, GL_RGB, GL_UNSIGNED_BYTE, pPixelData);
	char buf[250] = { 0 };
   
    _snprintf_s(buf, 255, "%03d.jpg", numbe++);//1_00000
    
    char temp[] ="./images/snapshot.jpg";
    std::string tempPaht = "./images/";
    std::string resultPaht = tempPaht + buf;
    WriteBitmapFile((char*)resultPaht.c_str(), img_w, img_h, pPixelData);
    free(pPixelData);

}

IMAGETYPE ImageFun::getFormat() {
    return mformat;
}
