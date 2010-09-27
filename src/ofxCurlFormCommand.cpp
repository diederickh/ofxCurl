#include "ofxCurlFormCommand.h"
#include "ofxCurlForm.h"
#include <iostream>
ofxCurlFormCommand::ofxCurlFormCommand(std::string sName, ofxCurlForm* pForm)
	:ofxCommand(sName)
	,form(pForm)
{
}

ofxCurlFormCommand::~ofxCurlFormCommand() {
	std::cout << "~~~~ ofxCurlFormCommand() SHOULD CLEANUP!" << std::endl;
	form->cleanup();
	delete form;
}

bool ofxCurlFormCommand::execute() {
	form->post();
	return true;
}
