#include "ofxCurlForm.h"
#include "ofxCurlFormType.h"
#include "ofxCurlFormTypeInput.h"
#include <iostream>
ofxCurlForm::ofxCurlForm(std::string sPostURL)
	:action(sPostURL)
	,post_curr(NULL)
	,post_last(NULL)
{
	curl_global_init(CURL_GLOBAL_ALL);
}

ofxCurlForm& ofxCurlForm::addInput(std::string sName, std::string sValue) {
	ofxCurlFormTypeInput* input = new ofxCurlFormTypeInput(sName);
	input->setValue(sValue);
	elements.push_back(input);
	return *this;
}

ofxCurlForm& ofxCurlForm::post() {
	// let all elements add themself to the form.
	CURL* easy_handle;
	
	parseForm();	
	curl_global_init(CURL_GLOBAL_ALL);
	// TODO: add some error handling; see this: http://curl.haxx.se/libcurl/c/postit2.html
	easy_handle = curl_easy_init();
	curl_easy_setopt(easy_handle, CURLOPT_URL, action.c_str());
	curl_easy_setopt(easy_handle, CURLOPT_HTTPPOST, post_curr);
	curl_easy_perform(easy_handle);
	curl_formfree(post_curr);
	
	return *this;
}

void ofxCurlForm::parseForm() {
	std::vector<ofxCurlFormType*>::iterator it = elements.begin();
	while(it != elements.end()) {
		std::cout << &post_curr << std::endl;
		(*it)->addToForm(this, &post_curr, &post_last);
		++it;
	}
	
}