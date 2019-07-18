#pragma once

#include <ofMain.h>
#include <ofx_Palettes.hpp>
#include <ofx_Random.hpp>

inline ofColor ofHSB(int hue, int saturation, int brightness) { return ofColor::fromHsb(hue, saturation, brightness); };

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

