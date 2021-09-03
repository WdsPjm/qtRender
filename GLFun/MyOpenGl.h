//
// Created by WDS on 2021/8/22.
//

#ifndef QTOPENGL_MYOPENGL_H
#define QTOPENGL_MYOPENGL_H

#include <iostream>
#include <vector>
#include "GlTexture2D.h"

using std::vector;

class MyOpenGl {
public:
    MyOpenGl();
    ~MyOpenGl();

    bool  OpenGlInit();
    void  createVaO( GLuint& locationVao);
    void  createVbo( GLuint& locationVbo, vector<float>& allVertex );
    void  createEbo( GLuint& locationEbo, vector<GLuint>& indexVertex );
    void  OpenGlRender();
    void  OpenGlGeneData();
    void  RenderInit();

    void  setOpenglVersion(int major,int minor);
    void  clearOpengl(const float &red,const float &green, const float &blue, const float &alpha);

};


#endif //QTOPENGL_MYOPENGL_H
