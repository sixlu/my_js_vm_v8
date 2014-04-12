#include "config.h"

map<string,string> Config::_request_headers_defaults;

void Config::load(){

    Config::_request_headers_defaults["User-Agent"]="Mozilla/5.0 (iPhone; CPU iPhone OS 6_0 like Mac OS X) AppleWebKit/536.26 (KHTML, like Gecko) Mobile/10A403";
    Config::_request_headers_defaults["Accept"]="*/*";
    Config::_request_headers_defaults["Accept-Language"]="zh-cn";
    Config::_request_headers_defaults["Accept-Encoding"]="gzip, deflate";

}

void Config::fillRequestHeader(map<string,string> &request_headers){
    
    map<string,string>::iterator itr = Config::_request_headers_defaults.begin();
    while(itr!=Config::_request_headers_defaults.end()){
        request_headers[itr->first]=itr->second;
        itr++;
    }

}
