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

class ofxCurlFileDownload {
public:
	ofxCurlFileDownload(std::string sURL, std::string sLocalFile);
	~ofxCurlFileDownload();

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
	 
private:
	CURL* curl_handle;
	CURLM* multi_curl_handle;
	std::ofstream file_stream;
	std::string remote_url;
	std::string file_path;
};
#endif
