//
//  ofx_Palette.cpp
//  triangle-subdivision
//
//  Created by Ricardo Matias on 17.07.19.
//

#include "ofx_Palette.hpp"

namespace Tools {
    void Palette::create(const std::vector<string> &_colors)
    {
        colors.clear();
        colors.reserve(_colors.size());
        
        for (string color : _colors) {
            color.erase(0, 1);
            
            colors.emplace_back(toHex(color));
        }
    }
    
    Palette &Palette::operator=(const std::vector<string> &_colors)
    {
        create(_colors);
        
        return *this;
    }
    
    ofColor Palette::toHex(string color)
    {
        return ofColor::fromHex(std::stoul("0x" + color, nullptr, 16));
    }
    
    ofColor &Palette::random(mt19937 gen)
    {
        return colors[rnd(gen)];
    }
}

