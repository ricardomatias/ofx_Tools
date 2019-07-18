//
//  ofx_Random.cpp
//  triangle-subdivision
//
//  Created by Ricardo Matias on 17.07.19.
//

#include "ofx_Random.hpp"


namespace Tools {
    template <typename T>
    T random(vector<T> &c) {
        float size = c.size();
        
        int index = glm::floor(ofRandom(size));
        
        return c[index];
    }
}
