/**
 * ofxTimecode
 * James George 2012
 *
 * Created as part of the Duration + ofxTimeline project
 * Supported by YCAM InterLab Guest Research Project ( http://interlab.ycam.jp/en/ )
 *
 */

#include "ofxTimecode.h"

ofxTimecode::ofxTimecode(){
    fps = 30;
}
    
void ofxTimecode::setFPS(int _fps){
    if(fps < 1){
        ofLogError("ofxTimecode::setFPS invalid FPS set");
        return;
    }
	fps = _fps;
}

int ofxTimecode::getFPS(){
    return fps;
}

//------------------------------------------------------------------------------------------
//                        Conversions involving frame-based timecodes
//------------------------------------------------------------------------------------------

//expects format HH:MM:SS:FR
int ofxTimecode::frameForTimecode(string timecode){
    int times[4];
    if(decodeString(timecode, times)){
        //hours					  //minutes				//seconds		 //frames
        return times[0] * fps * 60 * 60 + times[1] * fps * 60 + times[2] * fps + times[3];
    }
    return -1;
}

//expects format HH:MM:SS:FR
long ofxTimecode::millisForTimecode(string timecode){
    return millisForFrame(frameForTimecode(timecode));
}

//expects format HH:MM:SS:FR
float ofxTimecode::secondsForTimecode(string timecode){
    return secondsForFrame(frameForTimecode(timecode));
}

//Returns a timecode in the format HH:MM:SS:FR
string ofxTimecode::timecodeForMillis(long millis){
    return timecodeForFrame(millis * fps / 1000 );
}

//Returns a timecode in the format HH:MM:SS:FR
string ofxTimecode::timecodeForSeconds(float seconds){
    return timecodeForFrame(seconds * fps);
}

//Returns a timecode in the format HH:MM:SS:FR
string ofxTimecode::timecodeForFrame(int frame){
	char buf[512];
    sprintf(buf, "%02d:%02d:%02d:%d", frame / (60 * 60 * fps), (frame / (60 * fps)) % 60, (frame / fps) % 60, frame % fps );
    return string(buf);
}

//------------------------------------------------------------------------------------------
//                      Conversions involving millisecond-based timecodes
//------------------------------------------------------------------------------------------

//expects format HH:MM:SS:MS (last field is 3 digits)
int ofxTimecode::frameForMSTimecode(string timecode){
    return frameForMillis(millisforMSTimecode(timecode));
}

//expects format HH:MM:SS:MS (last field is 3 digits)
float ofxTimecode::secondsforMSTimecode(string timecode){
    return float((millisForMSTimecode(timecode))/1000);
}

//expects format HH:MM:SS:MS (last field is 3 digits)
long ofxTimecode::millisForMSTimecode(string timecode){
    int times[4];
    if(decodeString(timecode, times)){
        //hours                             //minutes             //seconds         //millis
        return times[0] * 1000 * 60 * 60 + times[1] * 1000 * 60 + times[2] * 1000 + times[3];
    }
    return -1;
}

//Returns a timecode in the format HH:MM:SS:MS
string ofxTimecode::MSTimecodeForFrame(int frame){
    return MSTimecodeForMillis(millisForFrame(frame));
}

//Returns a timecode in the format HH:MM:SS:MS
string ofxTimecode::MSTimecodeForSeconds(float seconds){
    return MSTimecodeForMillis(seconds * 1000);
}

//Returns a timecode in the format HH:MM:SS:FR
string ofxTimecode::MSTimecodeForMillis(int millis){
	char buf[512];
    sprintf(buf, "%02d:%02d:%02d:%d", millis / (60 * 60 * 1000), (millis / (60 * 1000)) % 60, (millis / 1000) % 60, millis % 1000 );
    return string(buf);
}

//------------------------------------------------------------------------------------------
//                            Conversions not involving timecodes
//------------------------------------------------------------------------------------------

int ofxTimecode::frameForSeconds(float timeInSeconds){
    return timeInSeconds * fps;
}

int ofxTimecode::frameForMillis(long timeInMillis){
    return timeInMillis * fps / 1000;
}

float ofxTimecode::secondsForFrame(int frame){
	return frame / float(fps);
}

long ofxTimecode::millisForFrame(int frame){
	return frame * 1000 / fps;    
}


//Decodes a timecode string into its four components: HH, MM, SS, and FR/MS
bool ofxTimecode::decodeString(string time, int* times){
    vector<string> split = ofSplitString(time, ":,");
    if(split.size() != 4){
        ofLogError("ofxTimecode::decodeString -- incorrect timecode");
        return false;
    }
    for(int i = 0; i < split.size(); i++){
    	times[i] = ofToInt(split[i]);
    }
    return true;
}
