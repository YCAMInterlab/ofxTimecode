#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(30);
    ofSetVerticalSync(true);
    ofBackground(0);
    
    timecode.setFPS(30);
    

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);

	ofDrawBitmapString("Elapsed Frames: " + timecode.timecodeForFrame(ofGetFrameNum()), mouseX, mouseY);
	ofDrawBitmapString("Elapsed Time:   " + timecode.timecodeForSeconds(ofGetElapsedTimef()), mouseX, mouseY-30);
	ofDrawBitmapString("Elapsed Millis: " + timecode.timecodeForMillis(ofGetElapsedTimeMillis()), mouseX, mouseY-60);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}