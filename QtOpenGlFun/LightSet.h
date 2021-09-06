//
// Created by WDS on 2021/9/7.
//

#ifndef QTOPENGL_LIGHTSET_H
#define QTOPENGL_LIGHTSET_H
#include "glm/glm.hpp"

class LightSet {
public:
    LightSet(glm::vec3 lightPos);
    ~LightSet();

public:
    glm::vec3 mLightPos;

};


#endif //QTOPENGL_LIGHTSET_H
