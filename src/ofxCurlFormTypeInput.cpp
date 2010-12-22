#include "ofxCurlFormTypeInput.h"
#include "curl.h"
#include <iostream>
ofxCurlFormTypeInput::ofxCurlFormTypeInput(std::string sName)
	:ofxCurlFormType(sName)
{
}

ofxCurlFormTypeInput::~ofxCurlFormTypeInput() {
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

