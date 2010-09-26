#include "ofxCurlFormType.h"
#include "ofxCurlForm.h" 
ofxCurlFormType::ofxCurlFormType(std::string sName)
    :name(sName)
{

}

void ofxCurlFormType::setName(std::string sName) {
	name = sName;
}

std::string ofxCurlFormType::getName() {
	return name;
}