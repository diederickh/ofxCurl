#ifndef OFXCURLFORMTYPEH
#define OFXCURLFORMTYPEH
#include <string>
#include "curl.h"
class ofxCurlForm;
class ofxCurlFormType {
public:
    ofxCurlFormType(std::string sName);
	virtual ~ofxCurlFormType(){};
	std::string getName();
	void setName(std::string sName);

	// This method is called when the type needs to add itself to the form
	//--------------------------------------------------------------------------
	virtual void addToForm(
			ofxCurlForm* pForm
			,curl_httppost** pCurr // used to  keep track of order of added elements
			,curl_httppost** pLast // used to  keep track of order of added elements
	) = 0;

protected:
    std::string name;
};
#endif
