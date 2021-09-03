//
// Created by WDS on 2021/8/22.
//

#ifndef QTOPENGL_GLSHADER_H
#define QTOPENGL_GLSHADER_H
#include <iostream>
#include "glm/glm.hpp"
#include <Gl/glew.h>
#include "GlTexture2D.h"

#define  MAX_TEXTURE_UNIT 32

class GlShader {
public:
    GlShader(std::string& vertShaderPaht, std::string& fragShaderPaht);
    ~GlShader();

public:
    static char*  loadShader(const char* shaderPaht);
    void shaderUse();
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value);
    void setMat4(const std::string &name, const glm::mat4 &mat) const;
    GLuint  mShaderId;
private:
    GLuint createShader();
    GLuint CompileShader(GLenum shaderType, const char* filePath);
    const char* mVertShaderFilePath;
    const char* mFragmentShaderFilepath;

    bool textureUnit[MAX_TEXTURE_UNIT];
    GLuint program;
};


#endif //QTOPENGL_GLSHADER_H
