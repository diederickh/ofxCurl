#include "ofxCurl.h"
ofxCurl::ofxCurl() {
/*
#ifdef OFXCURL_WITH_OFXCOMMANDPATTERN
	processor.start();
#endif
*/
}

ofxCurlForm* ofxCurl::createForm(std::string sPostURL) {
	ofxCurlForm* form = new ofxCurlForm(sPostURL);
	return form;
}

/*

#ifdef OFXCURL_WITH_OFXCOMMANDPATTERN
void ofxCurl::enqueueForm(ofxCurlForm* pForm) {
	processor.addForm(pForm);
}
#endif
*/