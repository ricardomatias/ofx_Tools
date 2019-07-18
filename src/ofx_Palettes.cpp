//
//  ofx_Palettes.cpp
//  triangle-subdivision
//
//  Created by Ricardo Matias on 17.07.19.
//

#include "ofx_Palettes.hpp"

namespace Tools {
    void Palettes::load(string baseOFPath)
    {
        string path = "/addons/ofx_Tools/bin/data/top-100.json";
        
        ofFile file(baseOFPath + path);
        
        if (file.exists()){
            file >> json;
        }
        
        ofLogNotice() << "[Palettes] Loaded " << json.size() << " palettes.";
    }
    
    Palette Palettes::operator[](int i) {
        vector<string> palette = json[i];
        
        if (!index) index = i;
        
        return Palette{palette};
    };
    
    Palette Palettes::next() {
        if (index >= json.size())
        {
            index = 0;
        }
        
        ++index;
        
        vector<string> palette = json[index];
        
        return Palette{palette};
    };
}

