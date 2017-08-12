#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
    ofSetVerticalSync(true);
    ofBackground(0);
    
    timecode.setFPS(30);
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);

	ofDrawBitmapString("Elapsed Frames: " + timecode.timecodeForFrame(ofGetFrameNum()), mouseX, mouseY);
	ofDrawBitmapString("Elapsed Time:   " + timecode.timecodeForSeconds(ofGetElapsedTimef()), mouseX, mouseY-30);
	ofDrawBitmapString("Elapsed Millis: " + timecode.timecodeForMillis(ofGetElapsedTimeMillis()), mouseX, mouseY-60);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}