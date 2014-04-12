#include "navigator.h"

NavigatorPtr Navigator::_single=NULL;

INIT_STATIC_JAVASCRIPTATTRI_NAME(Navigator,appCodeName)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Navigator,appName)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Navigator,appVersion)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Navigator,cookieEnabled)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Navigator,onLine)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Navigator,platform)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Navigator,userAgent)

Navigator::Navigator(){


}


Navigator::Navigator(string &appcodename,string& appname,string& appversion,string& platform,string &useragent,bool cookieEnabled,bool isOnline){
    _appCodeName=appcodename;
    _appName=appname;
    _appVersion=appversion; 
    _cookieEnabled=cookieEnabled;
    _isOnline=isOnline;
    _platform=platform;
    _userAgent=useragent;

    embed();    
 
}


NavigatorPtr Navigator::New(string &appcodename,string& appname,string& appversion,string& platform,string &useragent,bool cookieEnabled,bool online){

    if(Navigator::_single==NULL){
       Navigator::_single =new Navigator(appcodename,appname,appversion,platform,useragent,cookieEnabled,online);
    }
    return Navigator::_single;

}


v8::Handle<v8::ObjectTemplate> Navigator::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
            //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Navigator,appCodeName).c_str()), Navigator::GetProperty, Navigator::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Navigator,appName).c_str()), Navigator::GetProperty, Navigator::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Navigator,appVersion).c_str()), Navigator::GetProperty, Navigator::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Navigator,cookieEnabled).c_str()), Navigator::GetProperty, Navigator::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Navigator,onLine).c_str()), Navigator::GetProperty, Navigator::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Navigator,platform).c_str()), Navigator::GetProperty, Navigator::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Navigator,userAgent).c_str()), Navigator::GetProperty, Navigator::SetProperty);




       
    return _templ;

}

Handle<Value> Navigator::GetProperty(Local<String> property,const AccessorInfo &info){

    NavigatorPtr nv =(NavigatorPtr) embedObject::UnWrap(info);
    char* property_name = (char*)embedObject::ToCString(property).c_str();

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Navigator,appCodeName).c_str())==0){
         string str= nv->getAppCodeName();
         return v8::String::New(str.c_str());

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Navigator,appName).c_str())==0){

         string str= nv->getAppName();
         return v8::String::New(str.c_str());

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Navigator,appVersion).c_str())==0){


         string str= nv->getAppVersion();
         return v8::String::New(str.c_str());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Navigator,cookieEnabled).c_str())==0){
         return v8::Boolean::New(nv->isCookieEnabled());

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Navigator,onLine).c_str())==0){

         return v8::Boolean::New(nv->isOnline());

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Navigator,platform).c_str())==0){

         string str= nv->getPlatform();
         return v8::String::New(str.c_str());

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Navigator,userAgent).c_str())==0){

         string str= nv->getUserAgent();
         return v8::String::New(str.c_str());

    }




    

}

void Navigator::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){


}



