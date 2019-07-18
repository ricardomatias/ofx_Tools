//
//  ofx_Palettes.hpp
//  triangle-subdivision
//
//  Created by Ricardo Matias on 17.07.19.
//

#pragma once

#include <ofMain.h>
#include "ofx_Palette.hpp"

namespace Tools {
    class Palettes
    {
        int index;
        vector<Palette> palettes;
        ofJson json;
    public:
        void load(string baseOFPath);
        
        Palette operator[](int i);
        
        int size() const { return json.size(); };
        
        Palette next();
    };
}
