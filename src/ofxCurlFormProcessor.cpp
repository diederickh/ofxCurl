#ifdef OFXCURL_WITH_OFXCOMMANDPATTERN
#include "ofxCurlForm.h"
#include "ofxCurlFormProcessor.h"
#include "ofxCurlFormCommand.h"
#include "ofxLog.h"

ofxCurlFormProcessor::ofxCurlFormProcessor() {

}

ofxCurlFormProcessor::~ofxCurlFormProcessor() {
	OFXLOG("~~~~ ofxCurlFormProcessor()");
}

void ofxCurlFormProcessor::start() {
	OFXLOG("ofxCurlFormProcessor.start()");
	processor.start();
}

void ofxCurlFormProcessor::addForm(ofxCurlForm* pForm) {
	OFXLOG("ofxCurlFormProcessor.addForm()");
	processor.enqueue(boost::shared_ptr<ofxCommand>(new ofxCurlFormCommand("ofxcurlform", pForm)));
	//ofxCurlFormCommand* cmd = new ofxCurlFormCommand("ofxcurlform", pForm);
	//processor.enqueue(cmd);
}

#endif
