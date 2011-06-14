#ifndef OFXCURLH
#define OFXCURLH

#include <string>
#include "ofxCurlForm.h"

/*
#ifdef OFXCURL_WITH_OFXCOMMANDPATTERN
	#include "ofxCurlFormProcessor.h"
	#include "ofxCurlFormCommand.h"
#endif
*/

class ofxCurl {
public:
    ofxCurl();
    ofxCurlForm* createForm(std::string sPostURL);
/*
	#ifdef OFXCURL_WITH_OFXCOMMANDPATTERN
		void enqueueForm(ofxCurlForm* pForm);
	#endif
*/
private:
/*
	#ifdef OFXCURL_WITH_OFXCOMMANDPATTERN
	ofxCurlFormProcessor processor;
	#endif
*/
};
#endif
