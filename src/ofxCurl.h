#ifndef OFXCURLH
#define OFXCURLH

#include <string>
#include "ofxCurlForm.h"
class ofxCurl {
public:
    ofxCurl();
    ofxCurlForm createForm(std::string sPostURL);

private:
};
#endif
