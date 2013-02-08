#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    ofVideoPlayer fingerMovie;
    float           w, h;
    int             frame, totalFrames;
    ofFbo renderTexture;
    int frameNumber;
};
