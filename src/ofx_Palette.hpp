//
//  ofx_Palette.hpp
//  triangle-subdivision
//
//  Created by Ricardo Matias on 17.07.19.
//

#pragma once

#include <ofMain.h>
#include <random>

namespace Tools {
    class Palette {
        vector<ofColor> colors;
        
        void create(const vector<string> &_colors);
        
        ofColor toHex(string color);
        uniform_int_distribution<int> rnd;
    public:
        Palette() :
            colors(vector<ofColor>()), rnd(uniform_int_distribution<int>(0, 4)) {};
        Palette(const vector<string> &_colors) {
            rnd = uniform_int_distribution<int>(0, _colors.size() - 1);
            create(_colors);
        };
        
        Palette &operator=(const vector<string> &_colors);
        
        inline ofColor operator[] (int i) const { return colors[i]; };
        inline ofColor &operator[] (int i) { return colors[i]; };
        
        int size() const { return colors.size(); };
        
        vector<ofColor> &container() { return colors; };
        
        ofColor &random(mt19937 gen);
    };
}

