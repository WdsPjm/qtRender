//
// Created by WDS on 2021/8/22.
//
#include <GL/glew.h>
#include "MyOpenGl.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "../stbImage/stb_image.h"
MyOpenGl::MyOpenGl() {

}

MyOpenGl::~MyOpenGl() {

}

bool MyOpenGl::OpenGlInit() {
    setOpenglVersion(4,6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);


    if (glewInit() != GLEW_OK)
    {
        std::cout<< "glewInit failed!";
        throw;
        return false;
    }

    //Set all the required options for GLFW
    if (glfwInit() != GL_TRUE)
    {
        std::cout << "GlfwInit error" << std::endl;
        return false;
    };

    return true;
}

void MyOpenGl::OpenGlRender() {

}

void MyOpenGl::OpenGlGeneData() {

}

void MyOpenGl::setOpenglVersion(int major, int minor) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
}

void MyOpenGl::clearOpengl(const float &red, const float &green, const float &blue, const float &alpha) {
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void MyOpenGl::RenderInit() {

}

void MyOpenGl::createVaO( GLuint& locationVao) {
    glGenVertexArrays(1, &locationVao);
    glBindVertexArray(locationVao);

}


void MyOpenGl::createVbo(GLuint& locationVbo, vector<float>& allVertex ) {
    glGenBuffers(1,&locationVbo);
    glBindBuffer(GL_ARRAY_BUFFER,locationVbo);
    glBufferData(GL_ARRAY_BUFFER, allVertex.size() * sizeof(float), allVertex.data(),GL_STATIC_DRAW);

}

void MyOpenGl::createEbo(GLuint& locationEbo, vector<GLuint>& indexVertex) {
    glGenBuffers(1, &locationEbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, locationEbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexVertex), indexVertex.data(),GL_STATIC_DRAW);
}




