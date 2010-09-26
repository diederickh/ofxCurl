#ifndef OFXCURLH
#define OFXCURLH

#include <string>

class ofxCurl {
public:
    ofxCurl();
    ofxCurlForm createForm(std::string sPostURL);

private:
};
#endif
