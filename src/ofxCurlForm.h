#ifndef OFXCURLFORMH
#define OFXCURLFORMH

#include <string>
#include <vector>
#include "curl.h"

class ofxCurlFormType;

class ofxCurlForm {
public:
    ofxCurlForm(std::string sPostURL);
	~ofxCurlForm();
	void addElement(ofxCurlFormType* pElement);
	ofxCurlForm& addInput(std::string sName, std::string sValue);
	ofxCurlForm& addFile(std::string sName, std::string sFilePath);
	ofxCurlForm& post();
	void cleanup(); // removes all elements and frees memory.
private:
	void parseForm();
    std::string action;
	std::vector<ofxCurlFormType*> elements;
	
	struct curl_httppost* post_curr;
	struct curl_httppost* post_last;
};
#endif
