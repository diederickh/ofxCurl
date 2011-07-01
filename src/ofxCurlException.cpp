#include "ofxCurlException.h"
ofxCurlException::ofxCurlException(string sMessage, int nCode) 
:msg(sMessage)
,code(nCode)
{

}

ofxCurlException::~ofxCurlException() {
}

int ofxCurlException::getCode() {
	return code;
}

string ofxCurlException::getMessage() {
	return msg;
}
