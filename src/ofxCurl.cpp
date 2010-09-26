#include "ofxCurl.h"
ofxCurl::ofxCurl() {
}

ofxCurlForm ofxCurl::createForm(std::string sPostURL) {
	ofxCurlForm form(sPostURL);
	return form;
}
