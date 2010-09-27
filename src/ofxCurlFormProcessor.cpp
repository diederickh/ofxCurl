#ifdef OFXCURL_WITH_OFXCOMMANDPATTERN
#include "ofxCurlForm.h"
#include "ofxCurlFormProcessor.h"
#include "ofxCurlFormCommand.h"

ofxCurlFormProcessor::ofxCurlFormProcessor() {

}

ofxCurlFormProcessor::~ofxCurlFormProcessor() {
	std::cout << "~~~~ ofxCurlFormProcessor()" << std::endl;
}

void ofxCurlFormProcessor::start() {
	std::cout << "ofxCurlFormProcessor.start()" << std::endl;
	processor.start();
}

void ofxCurlFormProcessor::addForm(ofxCurlForm* pForm) {
	std::cout << "ofxCurlFormProcessor.addForm()" << std::endl;
	ofxCurlFormCommand* cmd = new ofxCurlFormCommand("ofxcurlform", pForm);
	processor.enqueue(cmd);
}

#endif
