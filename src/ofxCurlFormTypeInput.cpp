#include "ofxCurlFormTypeInput.h"
#include "curl.h"
#include <iostream>
ofxCurlFormTypeInput::ofxCurlFormTypeInput(std::string sName)	
	:ofxCurlFormType(sName)
{
}

void ofxCurlFormTypeInput::setValue(std::string sValue) {
	val = sValue;
}

void ofxCurlFormTypeInput::addToForm(
			ofxCurlForm* pForm
			,curl_httppost** pCurr
			,curl_httppost** pLast
)
{
	std::cout << "ofxCurlFormTypeInput: " << name << " = " << val << std::endl;
	curl_formadd(
			pCurr
			,pLast
			,CURLFORM_COPYNAME
			,name.c_str()
			,CURLFORM_COPYCONTENTS
			,val.c_str()
			,CURLFORM_END
	);
}

