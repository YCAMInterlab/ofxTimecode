/**
 * ofxTimecode
 * James George 2012
 *
 * Created as part of the Duration + ofxTimeline project
 * Supported by YCAM InterLab Guest Research Project ( http://interlab.ycam.jp/en/ )
 *
 */

#pragma once

#include "ofMain.h"

class ofxTimecode {
  public:
    ofxTimecode();
    
    void setFPS(float fps); //default is 30;
    float getFPS();
    
    //these functions expect format HH:MM:SS:FR
    //and negative value if improperly formatted
	long millisForTimecode(string timecode);
    float secondsForTimecode(string timecode);
    int frameForTimecode(string timecode);
    
    int frameForSeconds(float timeInSeconds);
    int frameForMillis(long timeInMillis);
    
    float secondsForFrame(int frame);
    long millisForFrame(int frame);
    
    //returns format HH:MM:SS:FR
    string timecodeForMillis(long millis);
    string timecodeForSeconds(float seconds);
    string timecodeForFrame(int frame);
    
  protected:
    float fps;
    bool decodeString(string time, int* times);
};
