//
// Created by WDS on 2021/8/22.
//

#ifndef QTOPENGL_QTOPENGLFUN_H
#define QTOPENGL_QTOPENGLFUN_H
#include <memory>
#include "QWidget"
#include <GL/glew.h>
#include <../glm/glm.hpp>
#include "../GLFun/GlTexture2D.h"
#include "CommonGlobal.h"
#include "../GLFun/camera.hpp"

class MyOpenGl;
class GlShader;
class GlContext;

enum VAOTYPE{
    TRIANGLEVAO,
    VAONUMBERS

};
enum VBOTYPE{
    TRIANGLEVBO,
    VBONUMBERS
};
enum EBOTYPE{
    TRIANGLEEBO,
    EBONUMBERS
};


struct VertexSt{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 uv;
};

class QtOpenglFun {
public:
    QtOpenglFun();
    ~QtOpenglFun();

public:
    void QtGLinit(HWND hwnd);
    void QtInitRender();
    void QtClearColor(const float &red,const float &green, const float &blue, const float &alpha);
    void QtRender();
    void GeneData();
    void bindVertex();
    void unBindBuffer();
    void loadTexture(const std::string& texturePath, std::shared_ptr<GlTexture2D>&);
    void setmixValue(const float& mixValue);
    void setmDiscardValue(const float& mDiscardValue);
    std::vector<SHADERTYPE>& getShaderValues();
    void buildShader(std::string &vertShaderPath, std::string &framShaderPath);
    void setRenderType(RENDERTYPE renderType);
    void setShaderType(SHADERTYPE shaderType);
    void rEstartRender();
    void setWidthHeigth(int width, int height);
    void setMat();
    void handleMouseMove(int32_t x, int32_t y);
    void MouseWheelScal(short delta /*= 1*/);
   std::shared_ptr<Camera>& getCameraType();
    struct {
        bool left = false;
        bool right = false;
        bool middle = false;
        bool middleScal = false;
    } mouseButtons;
private:
    std::shared_ptr<GlShader> mShader;
    std::shared_ptr<GlContext> mGlContex;
    std::shared_ptr<MyOpenGl>mMyOpengl;
    std::vector<float> mvertices;
    std::vector<GLuint>mVerticesIndex;
    std::vector<GLuint>mVBO;
    std::vector<GLuint>mVAO;
    std::vector<GLuint>mEBO;
    std::shared_ptr<GlTexture2D>mTexture1;
    std::shared_ptr<GlTexture2D>mTexture2;
    std::vector<RENDERTYPE> mRenderTypes;
    std::vector<SHADERTYPE>mShaderTypes;
    uint64_t mframes =0;
    uint64_t mWidth;
    uint64_t mHeight;
    long long  mStartTime =0;
    void startRender();
    void defaultRender();
    void setFrames();
    void IniCamearMat();
    float mMixValue;
    float mDiscardValue;
    std::shared_ptr<Camera> mCamera;
    glm::vec2 mousePos;
    bool viewUpdated = false;

};


#endif //QTOPENGL_QTOPENGLFUN_H
