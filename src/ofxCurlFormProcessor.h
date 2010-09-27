#ifndef OFXCURLFORMPROCESSORH
#define OFXCURLFORMPROCESSORH



// define this in  you preprocessor settings when you want to use the 
// form processor which processes form in a separate thread.
#ifdef OFXCURL_WITH_OFXCOMMANDPATTERN

// Include correct command processor file.
#if defined( __WIN32__ ) || defined( _WIN32 )
	#include "ofxCommandProcessorThreadWin.h"
#elif defined(__APPLE__)	
	#include "ofxCommandProcessorThreadMac.h"
#endif

#include "ofxCommand.h"	
	
class ofxCurlForm;	
class ofxCurlFormProcessor {
	public: 
		ofxCurlFormProcessor();
		~ofxCurlFormProcessor();
		void start();
		void addForm(ofxCurlForm* pForm);
	private:
		#if defined( __WIN32__ ) || defined( _WIN32 )
			ofxCommandProcessorThreadWin processor;
		#elif defined(__APPLE__)	
			ofxCommandProcessorThreadMac processor;
		#endif	
};

#endif // OFXCURL_WITH_OFXCOMMANDPATTERN

#endif