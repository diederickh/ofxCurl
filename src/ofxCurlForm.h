#ifndef OFXCURLFORMH
#define OFXCURLFORMH

#include <string>
#include <vector>
#include "curl.h"

class ofxCurlFormType;

class ofxCurlForm {
public:
    ofxCurlForm(std::string sPostURL);
	void addElement(ofxCurlFormType* pElement);
	ofxCurlForm& addInput(std::string sName, std::string sValue);
	ofxCurlForm& post();
private:
	void parseForm();
    std::string action;
	std::vector<ofxCurlFormType*> elements;
	
	struct curl_httppost* post_curr;
	struct curl_httppost* post_last;
};
#endif
