#ifndef  V8_HTTPUTIL_H
#define  V8_HTTPUTIL_H

#include <curl/curl.h>
#include <stdio.h>
#include <string>
#include <map>
#include <string.h>

#include "utils.h"

using namespace std;



class HttpUtil{

public:
typedef struct{
   char * buf;
   size_t hadReceiveSize;
   size_t size;

} BODY;

public:

   static int httpGet(map<string,string> &request_headers,string &url,
                     map<string,string> * response_headers,HttpUtil::BODY *response_body);
   
   static int httpPost(map<string,string> &request_headers,string &url,const char *request_body,size_t request_body_size,
                     map<string,string> *response_headers,HttpUtil::BODY *response_body);

   static size_t receiveBody(char *ptr, size_t size,size_t nmemb, void *userdata);
   static size_t receiveHeader( void *ptr, size_t size,size_t nmemb, void *userdata);


   static HttpUtil::BODY *newBody();
private:

   static struct curl_slist * setHeaderForRequest(map<string,string> &request_headers);

};

#endif
