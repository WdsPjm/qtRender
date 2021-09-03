//
// Created by WDS on 2021/8/22.
//

#include "GlContext.h"
#include <Gl/glew.h>
#include <Gl/wglew.h>
#include <stdio.h>
GlContext::GlContext(HWND hwnd) {
    this->mhwnd = hwnd;
}

GlContext::~GlContext() {

}

bool GlContext::CreateGLContex() {

    mdc = GetDC(mhwnd);
    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    //struct version
    pfd.nVersion = 1;
    pfd.cColorBits = 32;
    //depth
    pfd.cDepthBits = 24;
    //model
    pfd.cStencilBits = 8;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;

    int format = 0;
    format = ChoosePixelFormat(mdc, &pfd);
    if (!format)
    {
        throw;
    }
    SetPixelFormat(mdc, format, &pfd);

    int nPixelFormat = -1;
    int nPixCount = 0;
    float fPixAttribs[] = { 0,0 };
    int iPixAttribs[] = {
            WGL_SUPPORT_OPENGL_ARB, 1, /// Must support OGL rendering
            WGL_DRAW_TO_WINDOW_ARB, 1, /// pf that can run a window
            WGL_ACCELERATION_ARB,   WGL_FULL_ACCELERATION_ARB, /// must be HW accelerated
            WGL_COLOR_BITS_ARB,     32, /// 8 bits of each R, G and B
            WGL_DEPTH_BITS_ARB,     24, /// 24 bits of depth precision for window,
            WGL_DOUBLE_BUFFER_ARB,GL_TRUE, /// Double buffered context
            WGL_PIXEL_TYPE_ARB,      WGL_TYPE_RGBA_ARB, /// pf should be RGBA type
            WGL_STENCIL_BITS_ARB, 8,
            WGL_SAMPLE_BUFFERS_ARB, GL_TRUE, /// MSAA on
            WGL_SAMPLES_ARB,        4, /// 4x MSAA
            0 }; /// NULL termination

    auto tempDcTest = mdc;
    HGLRC temphRC = wglCreateContext(tempDcTest);
    wglMakeCurrent(tempDcTest, temphRC);
    GLenum err = glewInit();
    if (GLEW_OK != err)
        return NULL;
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(temphRC);


    //pix of fun
    wglChoosePixelFormatARB(mdc, iPixAttribs, fPixAttribs, 1, &nPixelFormat, (UINT*)&nPixCount);
    GLint attribs[] = { WGL_CONTEXT_MAJOR_VERSION_ARB,  4,
                        WGL_CONTEXT_MINOR_VERSION_ARB,  6,
                        WGL_CONTEXT_PROFILE_MASK_ARB,WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
                        0 };
    mrc = wglCreateContextAttribsARB(mdc, 0, attribs);
    wglMakeCurrent(mdc, mrc);
    //rc = wglCreateContext(dc);
    return true;
}

