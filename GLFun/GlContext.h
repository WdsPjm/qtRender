//
// Created by WDS on 2021/8/22.
//

#ifndef QTOPENGL_GLCONTEXT_H
#define QTOPENGL_GLCONTEXT_H
#include <windows.h>

class GlContext {
public:
    GlContext(HWND hwnd);
    ~GlContext();

public:
    bool  CreateGLContex();
    HDC mdc = nullptr;
    HGLRC mrc = nullptr;
    HWND mhwnd = nullptr;

};


#endif //QTOPENGL_GLCONTEXT_H
