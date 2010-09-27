#ifndef OFXCULRFORMTYPEFILEH
#define OFXCULRFORMTYPEFILEH
#include <string>


#include "ofxCurlFormType.h"
class ofxCurlForm;

class ofxCurlFormTypeFile : public ofxCurlFormType {
public:
	ofxCurlFormTypeFile(std::string sName, std::string sFilePath = NULL);
	virtual ~ofxCurlFormTypeFile();
	void setFile(std::string sFilePath);
	std::string getFile();
	virtual void addToForm(
			ofxCurlForm* pForm
			,curl_httppost** pCurr
			,curl_httppost** pLast
	);

protected:
	std::string file_path;
};

#endif