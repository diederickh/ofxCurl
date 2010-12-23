#include "ofxCurlFileDownload.h"

ofxCurlFileDownload::ofxCurlFileDownload(
		 std::string sURL 
		,std::string sLocalFile
		,ofxCurlFileDownloadListener* pListener
)
:remote_url(sURL)
,file_path(sLocalFile)
,listener(pListener)
,initialized(false)
{
	
}

void ofxCurlFileDownload::setURL(std::string sURL) {
	remote_url = sURL;
}

std::string ofxCurlFileDownload::getURL() {
	return remote_url;
}

void ofxCurlFileDownload::setDestination(std::string sFile) {
	file_path = sFile;
}
	

void ofxCurlFileDownload::startDownloading() {
	file_stream.open(file_path.c_str(), std::ios::binary);
	if(!file_stream.is_open()) {
		printf("Could not open the file!");
	}
	
	curl_handle = curl_easy_init();
	if(curl_handle) {
		initialized = true;
		// set the url to download
		curl_easy_setopt(
			curl_handle
			,CURLOPT_URL
			,remote_url.c_str()
		);
		
		// set the write function which store the file
		curl_easy_setopt(
			curl_handle
			,CURLOPT_WRITEFUNCTION
			,&ofxCurlFileDownload::writeData
		);
		
		// the userpointer (this object)
		curl_easy_setopt(
			curl_handle
			,CURLOPT_WRITEDATA
			,this
		);
		
		// we use the multi handles because of async-io
		multi_curl_handle = curl_multi_init();
		assert(multi_curl_handle!=NULL);
		curl_multi_add_handle(multi_curl_handle, curl_handle);
		
		// We we an update listener to continue downloading the data.
		ofAddListener(ofEvents.update, this, &ofxCurlFileDownload::update);
	}
	else {
		printf("Error initializing curl.\n");
	}
}

void ofxCurlFileDownload::update(ofEventArgs& rArgs) {
	int still_running = 0;
	int r = curl_multi_perform(multi_curl_handle, &still_running);
	
	if(still_running == 0) {
		if (initialized) {
			cleanup();
		}
		ofRemoveListener(ofEvents.update,this,&ofxCurlFileDownload::update);
		if(listener != NULL) {
			file_stream.close();
			listener->onReady(this);
		}
	}
}

void ofxCurlFileDownload::cleanup() {
	if(initialized) {
		curl_easy_cleanup(curl_handle);
		initialized = false;
	}
}

void ofxCurlFileDownload::setListener(ofxCurlFileDownloadListener* pListener) {
	listener = pListener;
}

ofxCurlFileDownload::~ofxCurlFileDownload() {
	cleanup();
}