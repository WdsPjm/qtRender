//
// Created by WDS on 2021/8/22.
//

#include "GlTexture2D.h"

GlTexture2D::GlTexture2D(int width, int height, GLint internalFormat, GLint format, const void *data) {
    this->width = width;
    this->height = height;
    this->internalFormat = internalFormat;
    this->format = format;
    texID = CreateGLTexture(GL_TEXTURE_2D, width, height, internalFormat, format, data);

}

GlTexture2D::~GlTexture2D() {
    glDeleteTextures(1, &texID);
}
void GlTexture2D::UpdateTexture2D(int width, int height, int linesize, const void *data) {
    glBindTexture(GL_TEXTURE_2D, texID);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, linesize);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, format, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);

}

GLuint GlTexture2D::CreateGLTexture(GLenum target, int width, int height, GLint internalformat, GLint format,const void *data) {
    GLuint texID;
    glGenTextures(1, &texID);
    glBindTexture(target, texID);
    //设置环绕方式
    glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //设置过滤方式
    glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT); // for this tutorial: use GL_CLAMP_TO_EDGE to prevent semi-transparent borders. Due to interpolation it takes texels from next repeat
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    glTexImage2D(
            target, //纹理类型
            0, //多级渐远纹理级别
            internalformat, //纹理的格式
            width,
            height,
            0,
            format, //数据的格式
            GL_UNSIGNED_BYTE,
            data
    );
    glGenerateMipmap(target);
    glBindTexture(target, 0);
    return texID;
}
