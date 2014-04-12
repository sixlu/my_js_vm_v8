#include "httpUtil.h"

int HttpUtil::httpGet(map<string,string> &request_headers,string &url,
                     map<string,string> *response_headers,HttpUtil::BODY *response_body){

    CURL *curl = curl_easy_init();

    curl_easy_setopt(curl,CURLOPT_VERBOSE,1);
    //curl_easy_setopt(curl,CURLOPT_HEADER,1);
    struct curl_slist *slist = HttpUtil::setHeaderForRequest(request_headers);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "gzip, deflate");
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    
    if (response_body){
      curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,HttpUtil::receiveBody);
      curl_easy_setopt(curl,CURLOPT_WRITEDATA,response_body);
    }

    if (response_headers){

      curl_easy_setopt(curl,CURLOPT_HEADERFUNCTION,HttpUtil::receiveHeader);
      curl_easy_setopt(curl,CURLOPT_WRITEHEADER,response_headers);
    }
   
    CURLcode recode = curl_easy_perform(curl);
     

    curl_easy_cleanup(curl);

    return recode;

}
   
int HttpUtil::httpPost(map<string,string> &request_headers,string &url,const char *request_body,size_t request_body_size,
                     map<string,string> *response_headers,HttpUtil::BODY *response_body){


}


size_t HttpUtil::receiveBody(char *ptr, size_t size,size_t nmemb, void *userdata){
      if (userdata && size >0){
         
         HttpUtil::BODY *body=(HttpUtil::BODY*)userdata;
         /*
         body->size = size*nmemb;
         body->buf = (char*)malloc(body->size+1);
         memcpy(body->buf,ptr,body->size);
         *(body->buf+body->size+1)=0;
         return body->size;
         */
         int receive_size = size*nmemb;
         if((body->hadReceiveSize+receive_size)> body->size)
               return -1;

         memcpy(body->buf+body->hadReceiveSize,ptr,receive_size);
         body->hadReceiveSize += receive_size;
         return receive_size; 
      }else
         return -1;
}

size_t HttpUtil::receiveHeader( void *ptr, size_t size,size_t nmemb, void *userdata){
      if (userdata && size >0){
        char header[CURL_MAX_HTTP_HEADER];
        memset(header,0,CURL_MAX_HTTP_HEADER);
        map<string,string> *headers= (map<string,string> *)userdata;
        memcpy(header,ptr,size*nmemb);
        
        string header_str= header;
        string delimiter =":";
        vector<string> tokens;

        if(header_str.find("HTTP",0)!=0){

		//IChrome::Utils::split(header_str,delimiter,tokens);
                int colon_index = header_str.find(":",0);
                if(colon_index>0){
		   string header_key = header_str.substr(0,colon_index);
                   int first_not_blank_index = header_str.find_first_not_of(' ',colon_index+1);
	    	   string header_value = header_str.substr(first_not_blank_index,header_str.size()-first_not_blank_index);
		   (*headers)[header_key]=header_value;
                }
        }
        return size*nmemb; 
 
      }else
        return -1;
}


struct curl_slist * HttpUtil::setHeaderForRequest(map<string,string> &request_headers){

     struct curl_slist *slist=NULL;
     char header[1000];
     memset(header,0,1000);
     map<string,string>::iterator itr= request_headers.begin();
     while(itr!=request_headers.end()){
        string name = itr->first;
        string value= itr->second;
        sprintf(header,"%s: %s",name.c_str(),value.c_str());
        slist = curl_slist_append(slist, header);
        memset(header,0,1000);
        itr++;
     }
     return slist;

}

HttpUtil::BODY * HttpUtil::newBody(){

     HttpUtil::BODY* body = new HttpUtil::BODY();
     body->size = CURL_MAX_WRITE_SIZE * 4;
     body->buf = (char*)malloc(body->size);
     memset(body->buf,0,body->size);
     body->hadReceiveSize = 0;

     return body;
}
