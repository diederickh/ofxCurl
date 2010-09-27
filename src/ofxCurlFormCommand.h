#ifndef OFXCURLFORMCOMMANDH
#define OFXCURLFORMCOMMANDH

#ifdef OFXCURL_WITH_OFXCOMMANDPATTERN
#include <string>
#include "ofxCommand.h"
class ofxCurlForm;

class ofxCurlFormCommand : public ofxCommand {
public:
	ofxCurlFormCommand(std::string sName, ofxCurlForm* pForm);
	~ofxCurlFormCommand();
	virtual bool execute();
	
private:
	ofxCurlForm* form;
};
#endif // OFXCURL_WITH_OFXCOMMANDPATTERN

#endif