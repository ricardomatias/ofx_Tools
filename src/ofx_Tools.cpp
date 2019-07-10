#include "ofx_Tools.h"



glm::vec3 Tools::getMouseCoords(bool inNDC)
{
    int width = ofGetWindowWidth();
    int height = ofGetWindowHeight();
    
    float x = ofClamp(ofGetMouseX(), 0.f, width);
    float y = ofClamp(ofGetMouseY(), 0.f, height);

    if (inNDC)
    {
        y = ofMap(y, 0.f, height, height, 0.f);
        
        x /= width;
        y /= height;
        
        x = 2.f * x - 1.f;
        y = 2.f * y - 1.f;
    }
    
    return glm::vec3{x, y, 0.f};
}

void Tools::Axis::setup()
{
    fbo.allocate(70.f, 70.f, GL_RGBA);
}

void Tools::Axis::draw(glm::mat4 modelView)
{
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    /****** CAPTURE AXIS *******/
    fbo.begin();
    
    ofPushStyle();
        ofBackground(ofColor(150, 100));
    
    ofPushMatrix();
        ofSetOrientation(OF_ORIENTATION_DEFAULT,false);
    
        glm::mat4 proj = glm::ortho(-50.f, 50.f, -50.f, 50.f, -100000.0f, 100000.f);
    
        ofSetMatrixMode(OF_MATRIX_PROJECTION);
        ofLoadMatrix(proj);
    
        ofSetMatrixMode(OF_MATRIX_MODELVIEW);
        ofLoadMatrix(modelView);
    
        ofSetLineWidth(2.f);
    
        ofSetColor(ofColor::red);
        ofDrawArrow(glm::vec3(0.f, 0.f, 0.f), glm::vec3(50.f, 0.f, 0.f), 3.f);
        ofSetColor(ofColor::green);
        ofDrawArrow(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 50.f, 0.f), 3.f);
        ofSetColor(ofColor::blue);
        ofDrawArrow(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 0.f, 50.f), 3.f);
    
    ofPopMatrix();
    
    ofPopStyle();
    
    ofSetOrientation(OF_ORIENTATION_DEFAULT, true);
    fbo.end();

    ofDisableLighting();
    ofDisableDepthTest();
    
    fbo.draw(10.f, 10.f);
    
    ofEnableLighting();
    ofEnableDepthTest();
}
