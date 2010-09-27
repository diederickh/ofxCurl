#include "ofxCurlForm.h"
#include "ofxCurlFormType.h"
#include "ofxCurlFormTypeInput.h"
#include "ofxCurlFormTypeFile.h"

#include <iostream>
ofxCurlForm::ofxCurlForm(std::string sPostURL)
	:action(sPostURL)
	,post_curr(NULL)
	,post_last(NULL)
{
	curl_global_init(CURL_GLOBAL_ALL);
}

ofxCurlForm::~ofxCurlForm() {
	std::cout << "~~~~ ofxCurlForm()" << std::endl;
}

ofxCurlForm& ofxCurlForm::addInput(std::string sName, std::string sValue) {
	ofxCurlFormTypeInput* input = new ofxCurlFormTypeInput(sName);
	input->setValue(sValue);
	elements.push_back(input);
	return *this;
}

ofxCurlForm& ofxCurlForm::addFile(std::string sName, std::string sFilePath) {
	ofxCurlFormTypeFile* file = new ofxCurlFormTypeFile(sName, sFilePath);
	elements.push_back(file);
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

	// free list..
	curl_easy_cleanup(easy_handle);
	curl_formfree(post_curr);
	std::cout << "ofxCurlForm: posting to: " << action << std::endl;
	return *this;
}

void ofxCurlForm::parseForm() {
	std::vector<ofxCurlFormType*>::iterator it = elements.begin();
	while(it != elements.end()) {
		(*it)->addToForm(this, &post_curr, &post_last);
		++it;
	}
}

void ofxCurlForm::cleanup() {
	std::cout << "cleanup!" << std::endl;
	std::vector<ofxCurlFormType*>::iterator it = elements.begin();
	while(it != elements.end()) {
		delete (*it);
		it = elements.erase(it);
	};
}
