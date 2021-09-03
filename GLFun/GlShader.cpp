//
// Created by WDS on 2021/8/22.
//

#include "GlShader.h"

GlShader::GlShader(std::string& vertShaderPaht, std::string& fragShaderPaht) {

    mVertShaderFilePath = vertShaderPaht.c_str();
    mFragmentShaderFilepath = fragShaderPaht.c_str();
    mShaderId = createShader();
}

GlShader::~GlShader() {

}

char *GlShader::loadShader(const char* shaderPaht) {

    char* fileContex = nullptr;
    FILE* fp = fopen(shaderPaht, "rb");
    if (fp)
    {
        fseek(fp, 0, SEEK_END);
        auto lenFile = ftell(fp);
        if (lenFile >0 )
        {
            rewind(fp);
            fileContex = new char[lenFile + 1];
            fread(fileContex, 1, lenFile, fp);
            fileContex[lenFile] = 0;
        }
        fclose(fp);
    }
    return fileContex;
}

GLuint GlShader::createShader() {
    GLuint vShader =  CompileShader(GL_VERTEX_SHADER,mVertShaderFilePath);
    GLuint fShader =  CompileShader(GL_FRAGMENT_SHADER, mFragmentShaderFilepath);
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vShader);
    glAttachShader(shaderProgram, fShader);
    glLinkProgram(shaderProgram);

    GLint success = GL_TRUE;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infolog[1024];
        GLsizei logLen = 0;
        glGetShaderInfoLog(shaderProgram, sizeof(infolog), &logLen, infolog);
        printf("[ERROR] Link error error: %s \n", infolog);
        glDeleteProgram(shaderProgram);
        throw;
    }
    printf("Link shader Program success\n");
    //着色器编译成功  删除着色器 只留下着色器程序就行
    glDetachShader(shaderProgram, vShader);
    glDetachShader(shaderProgram, fShader);
    glDeleteShader(vShader);
    glDeleteShader(fShader);

    return shaderProgram;

}

GLuint GlShader::CompileShader(GLenum shaderType, const char *filePath) {
    //GlShader glsd;
    char* shaderCode =  loadShader(filePath);
    const char* shaderTypeStr = "Vertex Shader";
    if (shaderType == GL_FRAGMENT_SHADER)
    {
        shaderTypeStr = "Fragment Shader";
    }
    GLuint shader = glCreateShader(shaderType);
    if (!shader)
        throw;
    glShaderSource(shader, 1, &shaderCode, NULL);
    glCompileShader(shader);
    GLint success = GL_TRUE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infolog[1024];
        GLsizei logLen = 0;
        glGetShaderInfoLog(shader, sizeof(infolog), &logLen, infolog);
        printf("[ERROR] Compile %s error: %s\n", shaderTypeStr, infolog);
        glDeleteShader(shader);
        throw;
    }
    printf("%s Compile Success\n",shaderTypeStr);
    delete shaderCode;
    return shader;
}

void GlShader::shaderUse() {
    glUseProgram(mShaderId);
}

void GlShader::setInt(const std::string &name, int value) const {

    glUniform1i(glGetUniformLocation(mShaderId, name.c_str()), value);

}

void GlShader::setFloat(const std::string &name, float value) {

    glUniform1f(glGetUniformLocation(mShaderId, name.c_str()), value);

}

void GlShader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(mShaderId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
