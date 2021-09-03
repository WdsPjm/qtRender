//
// Created by WDS on 2021/8/22.
//

#include "QtOpenglFun.h"
#include "../GLFun/MyOpenGl.h"
#include "../GLFun/GlShader.h"
#include "../GLFun/GlContext.h"
#include <windows.h>
#include "../stbImage/stb_image.h"
#include <tuple>
#include <QTime>

uint32_t width = 1920;
uint32_t height = 1080;

//#include <thread>
QtOpenglFun::QtOpenglFun() {
    mCamera = std::make_shared<Camera>();
    std::cout << "firstmCamera" << &mCamera << std::endl;
    IniCamearMat();

}

QtOpenglFun::~QtOpenglFun() {

}

void QtOpenglFun::QtGLinit(HWND hwnd) {
    mGlContex = std::make_shared<GlContext>(hwnd);
    mMyOpengl = std::make_shared<MyOpenGl>();
    mGlContex->CreateGLContex();
    mMyOpengl->OpenGlInit();

}

void QtOpenglFun::QtRender() {

    if (!mRenderTypes.size())
    {
        defaultRender();
    }
    else {
        startRender();
    }

}

void QtOpenglFun::QtInitRender() {
    std::string vertPaht;
    std::string fragPaht;
    if (!mRenderTypes.size())
    {
        return;
    }

    for (auto tempRenderType : mRenderTypes)
    {
        if (tempRenderType == RENDERTYPE::TRIANGLERENDER)
        {

        }
        else if (tempRenderType == RENDERTYPE::SQUARERENDER)
        {
            GeneData();
        }
    }

    buildShader(vertPaht, fragPaht);
    mVAO.resize(VAONUMBERS);
    mMyOpengl->createVaO(mVAO[TRIANGLEVAO]);
    mVBO.resize(VBONUMBERS);
    mMyOpengl->createVbo(mVBO[TRIANGLEVBO], mvertices);
    bindVertex();
    //EBO
    mEBO.resize(EBONUMBERS);
    mMyOpengl->createEbo(mEBO[TRIANGLEEBO], mVerticesIndex);
    unBindBuffer();
    assert(!glGetError());

}

void QtOpenglFun::QtClearColor(const float& red, const float& green, const float& blue, const float& alpha) {
    mMyOpengl->clearOpengl(red, green, blue, alpha);
}

void QtOpenglFun::GeneData() {
    mvertices = {    //color           uv
            0.5f,-0.5f,0.0f,  0.9,0.3,0.5,  1.0f,0.0f,
            0.5f,0.5f,0.0f,   0.2,0.5,0.1,  1.0f,1.0f,
            -0.5f,0.5f,0.0f,  1.0,0.6,0.2,  0.0f,1.0f,
            -0.5f,-0.5f,0.0f, 0.4,0.7,0.9,  0.0f,0.0f
    };

    mVerticesIndex =
    {
            0,1,2,
            2,3,0
    };

}

void QtOpenglFun::bindVertex() {
    glEnableVertexAttribArray(0);//Genable Position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)offsetof(VertexSt, position));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)offsetof(VertexSt, color));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)offsetof(VertexSt, uv));

    for (auto tempShader : mShaderTypes)
    {
        if (tempShader == SHADERTYPE::PICTUREFIX)
        {
            std::string imagePath1 = "H:\\c++train\\QtOpengl\\x64\\resources\\textures\\container2.png"; //container
            std::string imagePath2 = "H:\\c++train\\QtOpengl\\x64\\resources\\textures\\bricks2_disp.jpg";
            loadTexture(imagePath1, mTexture1);
            loadTexture(imagePath2, mTexture2);
            mShader->shaderUse();
            mShader->setInt("samp1", 0);
            mShader->setInt("samp2", 1);
        }
        else if (tempShader == SHADERTYPE::DISCARD)
        {
            std::string imagePath1 = "H:\\c++train\\QtOpengl\\x64\\resources\\textures\\grass.png";
            loadTexture(imagePath1, mTexture1);
            mShader->shaderUse();
            mShader->setInt("samp1", 0);
        }
    }

}

void QtOpenglFun::unBindBuffer() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void QtOpenglFun::loadTexture(const std::string& texturePath, std::shared_ptr<GlTexture2D>& textureId) {
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    //// The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    std::string imagePath = texturePath;
    unsigned char* data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        if (imagePath.find(".png") != std::string::npos)
        {
            textureId = std::make_shared<GlTexture2D>(width, height, GL_RGBA, GL_RGBA, data);
            std::cout << "load sampRGBA" << textureId->texID << std::endl;
        }
        else {
            textureId = std::make_shared<GlTexture2D>(width, height, GL_RGB, GL_RGB, data);
            std::cout << "load sampRGB" << textureId->texID << std::endl;
        }

    }
    else {
        std::cout << "error loadImage" << std::endl;
    }

    stbi_image_free(data);
}

void QtOpenglFun::startRender() {
    setFrames();
    QtClearColor(0.3f, 0.5f, 0.4f, 1.0f);
    for (auto tempShader : mShaderTypes)
    {
        if (tempShader == SHADERTYPE::PICTUREFIX)
        {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, mTexture1->texID);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, mTexture2->texID);
        }
        else if (tempShader == SHADERTYPE::DISCARD)
        {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, mTexture1->texID);
        }
    }

    mShader->setFloat("mixValue", mMixValue);
    mShader->setFloat("discardValue", mDiscardValue);
    mShader->shaderUse();

    setMat();
    glBindVertexArray(mVAO[TRIANGLEVAO]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO[TRIANGLEEBO]);
    glDrawElements(GL_TRIANGLES, mVerticesIndex.size(), GL_UNSIGNED_INT, nullptr);
    SwapBuffers(mGlContex->mdc);

}


void QtOpenglFun::setFrames() {
    long long stopTime1 = QDateTime::currentMSecsSinceEpoch();
    long long resultTime = stopTime1 - mStartTime;
    mframes += 1;
    if (resultTime / 1000 > 1)
    {
        //qDebug() <<"framesTest="<< mframes;
        mframes = 0;
        mStartTime = QDateTime::currentMSecsSinceEpoch();
    }
}

void QtOpenglFun::setmixValue(const float& mixValue) {
    mMixValue = mixValue;
}

void QtOpenglFun::defaultRender() {
    QtClearColor(0.3f, 0.5f, 0.4f, 1.0f);
    SwapBuffers(mGlContex->mdc);

}

void QtOpenglFun::buildShader(std::string& vertShaderPath, std::string& framShaderPath) {
    std::string vertPaht;
    std::string fragPaht;

    for (auto temp : mShaderTypes)
    {
        if (temp == SHADERTYPE::PICTUREFIX)
        {
            vertPaht = "..\\data\\shader\\vertexShader.vert";
            fragPaht = "..\\data\\shader\\fragmentShader.frag";
            std::cout << "load PICTUREFIX SHADER" << std::endl;

        }
        else if (temp == SHADERTYPE::DISCARD)
        {
            vertPaht = "..\\data\\shader\\DiscardVertShader.vert";
            fragPaht = "..\\data\\shader\\DiscardfragmentShader.frag";
            std::cout << "load DISCARD SHADER" << std::endl;
        }
        else
        {
            vertPaht = "..\\data\\shader\\DefaultvertexShader.vert";
            fragPaht = "..\\data\\shader\\DefaultfragmentShader.frag";
        }
    }

    mShader.reset(new GlShader(vertPaht, fragPaht));
}

void QtOpenglFun::setRenderType(RENDERTYPE renderType) {
    mRenderTypes.emplace_back(renderType);
}

void QtOpenglFun::setShaderType(SHADERTYPE shaderType) {
    mShaderTypes.emplace_back(shaderType);
}

void QtOpenglFun::rEstartRender() {
    QtInitRender();
    QtRender();
}

void QtOpenglFun::setmDiscardValue(const float& DiscardValue) {
    mDiscardValue = DiscardValue;
}

std::vector<SHADERTYPE>& QtOpenglFun::getShaderValues() {
    return mShaderTypes;
}

void QtOpenglFun::setWidthHeigth(int width, int height) {
    mWidth = width;
    mHeight = height;
}
uint32_t frameCounter = 0;
float frameTimer = 1.0f;

void QtOpenglFun::setMat() {

    auto tStart = std::chrono::high_resolution_clock::now();

    glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
  //  if (viewUpdated)
    {
        //	viewUpdated = false;
        projection = mCamera->matrices.perspective;
        view = mCamera->matrices.view;
    }


    model = glm::mat4(1.0f);
    mShader->setMat4("model", model);
    mShader->setMat4("view", view);
    mShader->setMat4("projection", projection);


    frameCounter++;
    auto tEnd = std::chrono::high_resolution_clock::now();
    auto tDiff = std::chrono::duration<double, std::milli>(tEnd - tStart).count();
    frameTimer = (float)tDiff / 1000.0f;
    mCamera->update(frameTimer);
    // if (mCamera->moving())
    {
        // viewUpdated = true;
    }


}

void QtOpenglFun::IniCamearMat() {
    mCamera->type = Camera::CameraType::lookat;
    mCamera->setPosition(glm::vec3(0.0f, 0.0f, -2.5f));
    mCamera->setRotation(glm::vec3(0.0f));
    mCamera->setPerspective(60.0f, (float)mWidth / (float)mHeight, 1.0f, 256.0f);


}

void QtOpenglFun::handleMouseMove(int32_t x, int32_t y) {
    int32_t dx = (int32_t)mousePos.x - x;
    int32_t dy = (int32_t)mousePos.y - y;
    // 	int32_t dx = x;
    // 	int32_t dy = y;

    bool handled = false;

    /*if (settings.overlay) {
        ImGuiIO& io = ImGui::GetIO();
        handled = io.WantCaptureMouse;
    }*/
    ///////mouseMoved((float)x, (float)y, handled);

    /*if (handled) {
        mousePos = glm::vec2((float)x, (float)y);
        return;
    }*/

    if (mouseButtons.left) {
        mCamera->rotate(glm::vec3(dy * mCamera->rotationSpeed, -dx * mCamera->rotationSpeed, 0.0f));
        std::cout << "camera:" << &mCamera << std::endl;
        viewUpdated = true;
        std::cout << "mouseButtonsLeft" << "dy" << dy * mCamera->rotationSpeed << "dx" << dx << std::endl;
        std::cout << "secondmCamera" << &mCamera << std::endl;
    }
    if (mouseButtons.right) {
        mCamera->translate(glm::vec3(-0.0f, 0.0f, dy * .005f));
        viewUpdated = true;
    }
    if (mouseButtons.middle) {
        mCamera->translate(glm::vec3(-dx * 0.01f, -dy * 0.01f, 0.0f));
        viewUpdated = true;
    }

    mousePos = glm::vec2((float)x, (float)y);

}

void QtOpenglFun::MouseWheelScal(short delta) {
    if (mouseButtons.middleScal)
    {
        mCamera->translate(glm::vec3(0.0f, 0.0f, (float)delta * 0.005f));
        viewUpdated = true;
    }
}

std::shared_ptr<Camera>& QtOpenglFun::getCameraType() {
    return  mCamera;
}

