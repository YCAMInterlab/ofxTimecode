#ofxTimecode

ofxTimecode is a simple class for converting between frames, seconds, milliseconds, and SMPTE representation (HH:MM:SS:FRAME) for time.

It stores a frame rate internally. Useful for displaying times as strings, or saving/pulling human readable times from xml

Easily combined with ofGetElapsedTimef(), ofGetElapsedMillis(), and ofGetFrameNum() as well as ofxMSATimer.

Developed by James George at YCAM InterLab as part of the ofxTimeline project

History:
v. 00 July 22nd 2012
first version, fairly untested but functional
example-smpte shows very simple use case, and shows how ofGetElapsedTimef() always differs from ofGetFrameNum()

