#ifdef OFXCURL_WITH_OFXCOMMANDPATTERN
#include "ofxCurlFormCommand.h"
#include "ofxCurlForm.h"
#include "ofMain.h"
#include "ofxLog.h"

#include <iostream>
ofxCurlFormCommand::ofxCurlFormCommand(std::string sName, ofxCurlForm* pForm)
	:ofxCommand(sName)
	,form(pForm)
{
}

ofxCurlFormCommand::~ofxCurlFormCommand() {
	OFXLOG("~~~~ ofxCurlFormCommand() - delete form");
	form->cleanup();
	delete form;
}

bool ofxCurlFormCommand::execute() {
    OFXLOG("ofxCurlFormCommand: execute()");
	form->post();
	return true;
}
#endif
