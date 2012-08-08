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
    
    void setFPS(int fps); //default is 30;
    int getFPS();
    
    //these functions expect format HH:MM:SS:FR
    //and negative value if improperly formatted
    int frameForTimecode(string timecode);
    long millisForTimecode(string timecode);
    float secondsForTimecode(string timecode);
    
    //returns format HH:MM:SS:FR
    string timecodeForMillis(long millis);
    string timecodeForSeconds(float seconds);
    string timecodeForFrame(int frame);    
    
    //these functions expect format HH:MM:SS:MS
    //and negative value if improperly formatted
    int frameForMSTimecode(string timecode);
    long millisForMSTimecode(string timecode);
    float secondsForMSTimecode(string timecode);
    
    //returns format HH:MM:SS:MS
    string MSTimecodeForMillis(long millis);
    string MSTimecodeForSeconds(float seconds);
    string MSTimecodeForFrame(int frame);
    
    //These functions can be used outside the context
    //of specific timecodes for various conversions
    int frameForSeconds(float timeInSeconds);
    int frameForMillis(long timeInMillis);
    float secondsForFrame(int frame);
    long millisForFrame(int frame);
    
    
  protected:
    int fps;
    bool decodeString(string time, int* times);
};
