#pragma once

#include <ofMain.h>

namespace Tools {
    glm::vec3 getMouseCoords(bool inNDC = false);
    
    class Axis
    {
        ofFbo fbo;
    public:
        void setup();
        void draw(glm::mat4 modelView);
    };
};

