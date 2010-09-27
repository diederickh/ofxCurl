#ifndef OFXCURLFORMTYPEINPUTH
#define OFXCURLFORMTYPEINPUTH
#include <string>
#include "ofxCurlFormType.h"
#include "curl.h"
class ofxCurlFormTypeInput : public ofxCurlFormType {
public:
	ofxCurlFormTypeInput(std::string sName);
	void setValue(std::string sValue);
	virtual void addToForm(
			ofxCurlForm* pForm
			,curl_httppost** pCurr
			,curl_httppost** pLast
	);
	
protected:
	std::string val;
};
#endif