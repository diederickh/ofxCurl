ofxCurl
================================================================================
This addon was created using curl-7.21.1 downloaded from:
http://curl.haxx.se/download/curl-7.21.1.tar.gz

Compiling libcurl from source on windows
================================================================================
- Download source
- Extract and open a 'cmd' window, go to the directory
- I used a recent (2010.09.26) version of mingw and typed:

mingw32-make mingw32

  to create a basic libcurl library. Then I used the static
  libcurl.a from the created "lib" directory to link against 
  in my project (code::blocks, windows).

- These are the directories you get when you download libcurl
include - use this for libcurl
lib 	- use this for libcurl
src	- this is the curl application.


Compiling libcurl from source on Mac (for the addon)
================================================================================
Download libcurl form here: 
http://www.hmug.org/pub/MacOS_X/BSD/Applications/Internet/curl/

./configure --disable-ldab --without-ssl --prefix=/Downloads/curl-7.21.1/stage CFLAGS="-arch i386" 

make
make install

Then I'm compiling a 10.6, i386 architecture project in XCode.

Install (both WIN / MAC)
================================================================================
Use these preprocessor defines:	
	OFXCURL_WITH_OFXCOMMANDPATTERN
	CURL_STATIC
		
Install MAC (both WIN / MAC)
================================================================================
Add this search path:
	../../../addons_diederick/ofxCurl/lib/mac/

		

IMPORTANT:
================================================================================
In Code::Blocks I had to define these two defines to make it 
link:

CURL_STATICLIB
CURL_DISABLE_LDAP

I also changed the curl-7.21.1\lib\config-win32.h file and added this define
at the top:
#define CURL_DISABLE_LDAP
