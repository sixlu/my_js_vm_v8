
#ifndef   V8_NAVIGATOR_H
#define  V8_NAVIGATOR_H 

#include "common.h"
#include <string>
#include "embedObject.h"
#include "node.h"



class Navigator;

typedef Navigator* NavigatorPtr;


class Navigator: public embedObject{


private:
	Navigator();
	Navigator(string &appcodename,string& appname,string& appversion,string& platform,string &useragent,bool cookieEnabled,bool online);

public:
	static NavigatorPtr New(string &appcodename,string& appname,string& appversion,string& platform,string &useragent
			  ,bool cookieEnabled,bool online);
	v8::Handle<v8::ObjectTemplate> embed();

public:
	string getAppCodeName(){return _appCodeName;};
	string getAppName(){return _appName;};
	string getAppVersion(){return _appVersion;};
	bool   isCookieEnabled(){return _cookieEnabled;};
	bool   isOnline(){return _isOnline;};
	string getPlatform(){return _platform;};
	string getUserAgent(){return _userAgent;};

private:
	string _appCodeName;
	string _appName;
	string _appVersion;
	bool   _cookieEnabled;
	bool   _isOnline;
	string _platform;
	string _userAgent;

public:
	static  NavigatorPtr _single;


public:

	static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
	static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(appCodeName)//Returns the code name of the browser
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(appName)//Returns the name of the browser
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(appVersion)//Returns the version information of the browser
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(cookieEnabled)//Determines whether cookies are enabled in the browser
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(onLine)//Boolean, returns true if the browser is on line, otherwise false.
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(platform)//Returns for which platform the browser is compiled
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(userAgent)//Returns the user-agent header sent by the browser to the server


};

#endif

