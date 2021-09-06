//
// Created by WDS on 2021/9/6.
//

#ifndef QTOPENGL_SHADERSET_H
#define QTOPENGL_SHADERSET_H
#include <iostream>
#include "Gl/glew.h"
#include "glm/glm.hpp"
#include "../GLFun/GlShader.h"
class ShaderSet {
public:
    ShaderSet(std::shared_ptr<GlShader>Shader,glm::mat4 model, glm::mat4 view,glm::mat4 project);
    ~ShaderSet();
public:
    std::shared_ptr<GlShader> mShader;
    glm::mat4 mModel;
    glm::mat4 mView;
    glm::mat4 mProjection;
    void setLightPos(const glm::vec3& lightPos);
    glm::vec3& getLightPos();
private:
    glm::vec3 mLightPos;
public:
    void  setShader();
    void  setLightObjColor(const std::string &name, float x, float y, float z);
};


#endif //QTOPENGL_SHADERSET_H
