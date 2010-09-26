#include "ofxCurlForm.h"
#include "ofxCurlFormType.h"
#include "ofxCurlFormTypeInput.h"
#include <iostream>
ofxCurlForm::ofxCurlForm(std::string sPostURL)
	:action(sPostURL)
	,post_curr(NULL)
	,post_last(NULL)
{
	curl_global_init(CURL_GLOBAL_ALL);
}

ofxCurlForm& ofxCurlForm::addInput(std::string sName, std::string sValue) {
	ofxCurlFormTypeInput* input = new ofxCurlFormTypeInput(sName);
	input->setValue(sValue);
	elements.push_back(input);
	return *this;
}

ofxCurlForm& ofxCurlForm::post() {

		  CURL *curl;
		  CURLcode res;
		 
//		  struct curl_httppost *formpost=NULL;
//		  struct curl_httppost *lastptr=NULL;
		  struct curl_slist *headerlist=NULL;
		 // static const char buf[] = "Expect:";
		 
		  curl_global_init(CURL_GLOBAL_ALL);
		parseForm();
		 
		  /* Fill in the filename field */ 
		  /*
		  curl_formadd(&post_curr,
					   &post_last,
					   CURLFORM_COPYNAME, "filename",
					   CURLFORM_COPYCONTENTS, "postit2.c",
					   CURLFORM_END);
		 
		 
		  // Fill in the submit field too, even if this is rarely needed 
		  curl_formadd(&post_curr,
					   &post_last,
					   CURLFORM_COPYNAME, "submit",
					   CURLFORM_COPYCONTENTS, "send",
					   CURLFORM_END);
			*/
		 
		  curl = curl_easy_init();
		  /* initalize custom header list (stating that Expect: 100-continue is not
			 wanted */ 
		 // headerlist = curl_slist_append(headerlist, buf);
		  if(curl) {
			/* what URL that receives this POST */ 
			curl_easy_setopt(curl, CURLOPT_URL, "http://ahm.demo.apollomedia.nl/control/ahm/site/test");
			curl_easy_setopt(curl, CURLOPT_HTTPPOST, post_curr);
			res = curl_easy_perform(curl);
			std::cout << "result " << res << std::endl;
			/* always cleanup */ 
			//curl_easy_cleanup(curl);

			/* then cleanup the formpost chain */ 
			//curl_formfree(post_curr);
			/* free slist */ 
			//curl_slist_free_all (headerlist);
		  }



	
	/*
	// let all elements add themself to the form.
	// set the form info.
	CURL* easy_handle = NULL;
	
	//parseForm();	
	curl_global_init(CURL_GLOBAL_ALL);

	
	easy_handle = curl_easy_init();
	curl_easy_setopt(easy_handle, CURLOPT_URL, action);
	curl_easy_setopt(easy_handle, CURLOPT_HTTPPOST, post_curr);
	curl_easy_perform(easy_handle);
	curl_formfree(post_curr);
	*/
	return *this;
}

void ofxCurlForm::parseForm() {
	std::vector<ofxCurlFormType*>::iterator it = elements.begin();
	while(it != elements.end()) {
	//	std::cout << &post_curr << std::endl;
		(*it)->addToForm(this, &post_curr, &post_last);
		++it;
	}
	
}