#ifndef OFXCURLFORMH
#define OFXCURLFORMH
#include <string>
class ofxCurlForm {
public:
    ofxCurlForm(std::string sPostURL);
private:
    std::string action;
};
#endif
