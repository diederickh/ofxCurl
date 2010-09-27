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
			,curl_httppost** pCurr
			,curl_httppost** pLast
	) = 0;

protected:
    std::string name;
};
#endif
