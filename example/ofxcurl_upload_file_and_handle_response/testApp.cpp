#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(33);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key == 't') {
		// Create a form.
		ofxCurl curl;
		ofxCurlForm* form = curl.createForm("http://ofxcurl_upload_test.localhost/upload.php");
		
		// Add some form entries.
		form->addInput("name", "Diederick Huijbers");
		form->addInput("email","diederick_AT_apollomedia.nl");
		form->addInput("secret", "call me roxlu");
		form->addFile("photo",ofToDataPath("image_to_upload.png",true));
		
		// Perform the post.
		try {
			form->post();	
		}
		catch(...) {
			cout << "OOPS.. something went wrong while posting" << endl;
		}
		
		// Do something with the response from the post.
		vector<char> response_buf = form->getPostResponseAsBuffer();
		string response_str = form->getPostResponseAsString();
		cout << "Size of response buffer: " << response_buf.size() << endl << endl;
		cout << "Response string:" << endl;
		cout << "-----------------" << endl;
		cout << response_str <<endl;
		
		// Cleanup
		delete form;
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}