//
// Created by WDS on 2021/8/22.
//
#include <GL/glew.h>
#ifndef QTOPENGL_GLTEXTURE2D_H
#define QTOPENGL_GLTEXTURE2D_H


class GlTexture2D {
public:
    GlTexture2D(int width, int height, GLint internalFormat, GLint format, const void *data);
    ~GlTexture2D();

public:
    void UpdateTexture2D(int width, int height, int linesize, const void* data);
    GLuint CreateGLTexture(GLenum target, int width, int height, GLint internalformat, GLint format, const void* data);

public:
    int width;
    int height;
    GLint internalFormat;
    GLint format;
    GLuint texID;

};


#endif //QTOPENGL_GLTEXTURE2D_H
