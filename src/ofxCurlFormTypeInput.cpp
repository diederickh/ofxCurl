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
			,struct curl_httppost** pCurr
			,struct curl_httppost** pLast
)
{
	std::cout << "ofxCurlFormTypeInput: " << name << " = " << val << std::endl;
	struct curl_httppost* tmp;
	//struct curl_httppost* tmp2= NULL;
	curl_formadd(
			&tmp
			,&tmp
			,CURLFORM_COPYNAME
			,name
			,CURLFORM_COPYCONTENTS
			,val
			,CURLFORM_END
	);
}

