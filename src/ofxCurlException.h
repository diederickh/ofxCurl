#pragma once
#include <string>
using namespace std;

enum OFXCURL_EXCEPTIONS {
 	 OFXCURL_TIMEOUT
	,OFXCURL_CANT_RESOLVE_HOST
};

class ofxCurlException {
public:
	ofxCurlException(string sMessage, int nCode);
	~ofxCurlException();
	int getCode();
	string getMessage();
private:
	int code;
	string msg;
};
