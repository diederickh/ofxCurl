#ifndef OFXCURLFILEDOWNLOADH
#define OFXCURLFILEDOWNLOADH

#include "ofMain.h"
#include "curl.h"

#include <string>
#include <fstream>

/* Example code:
for(int i = 0; i < 10; ++i) {
		ostringstream oss;
		oss << "stored_" << i << ".png";
		std::string fname= oss.str();
		ofxCurlFileDownload* d = new ofxCurlFileDownload(
			"http://b.tile.cloudmade.com/BC9A493B41014CAABB98F0471D759707/1/256/15/17599/10746.png"
			,ofToDataPath(fname,true)

		);
	}
*/
class ofxCurlFileDownload;
class ofxCurlFileDownloadListener {
public:
	virtual void onReady(ofxCurlFileDownload* pDownloaded) = 0;
};

class ofxCurlFileDownload {
public:
	ofxCurlFileDownload(
		 std::string sURL = ""
		,std::string sLocalFile = ""
		,ofxCurlFileDownloadListener* pListener = NULL
	);
	~ofxCurlFileDownload();
	
	void setURL(std::string sURL);
	void setDestination(std::string sLocalFile);
	std::string getURL();
	
	void startDownloading();
	
	static size_t writeData(
		void *ptr
		,size_t size
		,size_t nmemb
		,void* pCurlFileDownload)
     {
	   size_t bytes_to_write = size * nmemb;
	   ofxCurlFileDownload* downloader = static_cast<ofxCurlFileDownload*>(pCurlFileDownload);
	   char* data_ptr = static_cast<char*>(ptr);
	   downloader->file_stream.write(data_ptr, bytes_to_write);
	   return bytes_to_write;
     }
	
	 void update(ofEventArgs& rArgs); 
	 void setListener(ofxCurlFileDownloadListener* pListener);
	 
private:
	void cleanup();
	CURL* curl_handle;
	CURLM* multi_curl_handle;
	ofxCurlFileDownloadListener* listener;
	std::ofstream file_stream;
	std::string remote_url;
	std::string file_path;
	bool initialized;
};
#endif
