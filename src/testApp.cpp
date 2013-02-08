#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
    frameNumber = 0;
    
    
    fingerMovie.loadMovie("movies/fingers.mov");
    fingerMovie.play();
    //fingerMovie.setPaused(true);
    
    //set the bounds for the 'for' loop
    h = fingerMovie.getHeight();
    w = fingerMovie.getWidth();
    
    //null out the frame variable
    frame = 0;
    
    //and then set the bounds for the loop of the film
    totalFrames = fingerMovie.getTotalNumFrames();
    
    renderTexture.allocate(fingerMovie.getWidth(), fingerMovie.getHeight(), GL_RGB);
    renderTexture.begin();
    ofClear(0,0,0);
    renderTexture.end();
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    //I don't know that I need this anymore.
    fingerMovie.update();
    if (fingerMovie.isFrameNew()) {
        renderTexture.begin();
        int index = frameNumber++;
        int x = index % int(fingerMovie.getWidth()/10);
        int screenY = index / int(fingerMovie.getWidth()/10);
        int y = screenY % int(fingerMovie.getHeight()/10);
        
        x*=10;
        y*=10;
        //        for (int y=0; y<h; y+=10) {
        //            for (int x=0; x<w; x+=10) {
        
        //get pixel color
        int i = (y*w+x)*3;
        int r = fingerMovie.getPixels()[i+0];
        int g = fingerMovie.getPixels()[i+1];
        int b = fingerMovie.getPixels()[i+2];
        
        ofPushStyle();
        
        //set drawing color to the pixel values
        ofSetColor(r, g, b);
        
        //draw a rectangle with that pixel color
        ofRect(x, y, 10, 10);
        ofPopStyle();
        
        //this sets the loop of the video so that
        //we can get a pixel from each frame
        
        //            }
        //      }
        renderTexture.end();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    renderTexture.getTextureReference().draw(0,0);
    
    
    
}