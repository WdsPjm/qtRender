//
// Created by WDS on 2021/9/6.
//

#include "ShaderSet.h"


ShaderSet::~ShaderSet() {

}

void ShaderSet::setShader() {
mShader->shaderUse();
mShader->setMat4("model",mModel);
mShader->setMat4("view",mView);
mShader->setMat4("projection", mProjection);
}

ShaderSet::ShaderSet(std::shared_ptr<GlShader> shader, glm::mat4 model, glm::mat4 view, glm::mat4 project) {
    mShader= shader;
    mModel = model;
    mView = view;
    mProjection = project;
}

void ShaderSet::setLightObjColor(const std::string &name, float x, float y, float z) {

    mShader->setVec3(name, x, y, z);

}

void ShaderSet::setLightPos(const glm::vec3 &lightPos) {
  mLightPos = lightPos;
}

glm::vec3 &ShaderSet::getLightPos() {
    return mLightPos;
}
