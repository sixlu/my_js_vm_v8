#include "common.h"
#include "httpUtil.h"
#include "window.h"
#include "config.h"

//int main(int argc,char** argv){
//
//    map<string,string> request_headers;    
//
//    request_headers["User-Agent"]="Mozilla/5.0 (iPhone; CPU iPhone OS 6_0 like Mac OS X) AppleWebKit/536.26 (KHTML, like Gecko) Mobile/10A403";
//    request_headers["Accept"]="*/*";
//    request_headers["Accept-Language"]="zh-cn";
//    request_headers["Accept-Encoding"]="gzip, deflate";
//    
////    string url = "http://googleads.g.doubleclick.net/mads/gma?u_audio=1&hl=zh-CN&preqs=1801&app_name=2.3.4.iphone.com.wali2020.na1&prl=1121&u_h=480&u_so=p&net=ed&u_w=320&ptime=45641546&js=afma-sdk-i-v5.0.5&session_id=1186857567329139253&platform=iPhone&submodel=iPhone4,1&u_sd=2&format=320x50_mb&output=html&region=mobile_app&u_tz=480&client_sdk=1&ex=1&slotname=a1516191c116a95&askip=1&caps=interactiveVideo_inlineVideo_th_autoplay_mediation_sdkAdmobApiForAds&jsv=46&ms=BbtUJIXW-hI2VlmWHE3L_Z5tWnI70i_iM6Yd0heL_KMaPSylkZI--mmQsCjxGIHPVVaFELbKJlpNfgZ6xfGe4-4hjqo3sj9YaLYTE9w6WzJ23J_wudV3RuQz9y6T5Y9Vhvhn6xr41VMGp8ag1Ut6spTHeT8Z0Cb58658OpL4Jt1J26zYRnU104C5QdvgohhAgQ3AJ-Nvf9HsMx-QNDPz-fBGITI7uQiEeXVRvByveK51aJP_W-M4jkTCubdNPbwxbUjtvBz7FqBfHPyJjG83H9VPjcVtRipmw3QDh7WTBwYGTyZolBE_luhnc1U3zI6lDEct0HfM_BbUnojTarvRqQ";
//
//    //string url ="http://localhost/mitvcms/admin/index.php?tab=custom";
//    string url =argv[1];//"http://172.16.12.132:82/view/mixcontent.htm";
//    printf("%s\n",url.c_str());
//
//    map<string,string> response_headers;
//    HttpUtil::BODY *response_body = HttpUtil::newBody();
//
//    HttpUtil::httpGet(request_headers,url,&response_headers,response_body);
//
//    //printf("%s",response_body->buf);
//   
//    string response_body_str = response_body->buf;
//    
//    printf("%s",response_body_str.c_str());
//
//    Window * window = new Window(request_headers,url,response_headers,response_body_str);
//   
//    window->render();
//
//}

int main(int argc,char** argv){

    Config::load();

    map<string,string> request_headers;    

    Config::fillRequestHeader(request_headers);

    string url =argv[1];//"http://172.16.12.132:82/view/mixcontent.htm";
    printf("%s\n",url.c_str());

    map<string,string> response_headers;
    HttpUtil::BODY *response_body = HttpUtil::newBody();

    HttpUtil::httpGet(request_headers,url,&response_headers,response_body);

    //printf("%s",response_body->buf);
   
    string response_body_str = response_body->buf;
    
    printf("%s",response_body_str.c_str());

    Window * window = new Window(request_headers,url,response_headers,response_body_str);
   
    window->render();

}
