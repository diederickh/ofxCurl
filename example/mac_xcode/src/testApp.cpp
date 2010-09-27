#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofDrawBitmapString(ofToString(ofGetFrameRate(),2),10,10);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == 'p' || key == 'P') {
		cout << "Post form." << std::endl;
		ofxCurlForm* form = curl.createForm("URL_TO_POST_TO_PLEASE_CHANGE_THIS");
		form->addInput("rfid","rfid_code")
			.addFile("file", ofToDataPath("test.jpg"));
		curl.enqueueForm(form);
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

