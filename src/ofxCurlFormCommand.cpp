#ifdef OFXCURL_WITH_OFXCOMMANDPATTERN
#include "ofxCurlFormCommand.h"
#include "ofxCurlForm.h"
#include "ofMain.h"
#include <iostream>
ofxCurlFormCommand::ofxCurlFormCommand(std::string sName, ofxCurlForm* pForm)
	:ofxCommand(sName)
	,form(pForm)
{
}

ofxCurlFormCommand::~ofxCurlFormCommand() {
	std::cout << "~~~~ ofxCurlFormCommand()" << std::endl;
	form->cleanup();
	delete form;
}

bool ofxCurlFormCommand::execute() {
    std::cout << "ofxCurlFormCommand: execute()" <<std::endl;
	form->post();
	return true;
}
#endif
