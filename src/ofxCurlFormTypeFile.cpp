#include "ofxCurlFormTypeFile.h"
#include "ofxCurlForm.h"
#include "ofxLog.h"
#include <iostream>

ofxCurlFormTypeFile::ofxCurlFormTypeFile(
	 std::string sName
	,std::string sFilePath
)
	:ofxCurlFormType(sName)
	,file_path(sFilePath)
{
}

ofxCurlFormTypeFile::~ofxCurlFormTypeFile() {
    OFXLOG("~~~~ ofxCurlFormTypeFile()");
}

void ofxCurlFormTypeFile::setFile(std::string sFilePath) {
	file_path = sFilePath;
}

std::string ofxCurlFormTypeFile::getFile() {
	return file_path;
}

void ofxCurlFormTypeFile::addToForm(
			ofxCurlForm* pForm
			,curl_httppost** pCurr
			,curl_httppost** pLast
)
{
	OFXLOG("ofxCurlFormTypeFile: " << name << " = " << file_path);
	curl_formadd(
		 pCurr
		,pLast
		,CURLFORM_COPYNAME
		,name.c_str()
		,CURLFORM_FILE
		,file_path.c_str()
		,CURLFORM_END
	);
}

