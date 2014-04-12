#ifndef V8_WINDOW_H
#define V8_WINDOW_H

#include "common.h"
#include <string>
#include "embedObject.h"
#include "navigator.h"
#include "document.h"
#include "jstimer.h"
#include "httpUtil.h"


using namespace std;


class Window;

typedef Window* WindowPtr;


class Window:public embedObject {

public:
	Window(map<string,string> &request_headers,string &url,map<string,string> &response_headers, string &response_body_str);
	virtual ~Window();

        void render();

private:
        void createContext();
        string fetchScript();
        int getContentFromUrl(const char* url,map<string,string> *response_headers,HttpUtil::BODY *response_body);
        string getScriptFromUrl(const char * url);
public:
        v8::Handle<v8::ObjectTemplate> embed();
        bool getclosed();
        void setclosed(bool closed);  
	string getdefaultStatus();
        void setdefaultStatus(string &defaultStatus);   
	DocumentPtr getdocument();
        void setdocument(DocumentPtr document);       
	int getinnerHeight();
        void setinnerHeight(int innerHeight);     
	int getinnerWidth();
        void setinnerWidth(int innerWidth);      
	string getname();
        void setname(string &name);    
	NavigatorPtr getnavigator();
        void setnavigator(NavigatorPtr navigator);       
	int getouterHeight();
        void setouterHeight(int outerHeight);    
	int getouterWidth();
        void setouterWidth(int outerWidth);     
	int getpageXOffset();
        void setpageXOffset(int pageXOffset);   
	int getpageYOffset();
        void setpageYOffset(int pageYOffset);    
	WindowPtr getparent();
        void setparent(WindowPtr parent);  
        WindowPtr getself();
        void setself(WindowPtr self); 


private:
	bool _closed;  
	string _defaultStatus;   
	DocumentPtr _document;       
	int _innerHeight;     
	int _innerWidth;      
	string _name;    
	NavigatorPtr _navigator;       
	int _outerHeight;    
	int _outerWidth;     
	int _pageXOffset;   
	int _pageYOffset;    
	WindowPtr _parent;  
        WindowPtr _self;   

private:
        //Isolate * _isolate;
        //HandleScope *_handleScope;
        HandleScope _handle_scope;
        Persistent<Context> _context;
        map<string,string>  _defalutHeaders;

public:
	static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
	static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public: 
        //初始化一个window javascript object
	static v8::Handle<v8::Value> init_windowJSObject(const v8::Arguments& args); 	
        //初始化一个document javascript object
	static v8::Handle<v8::Value> init_documentJSObject(const v8::Arguments& args); 	
        //初始化一个navigator javascript object
	static v8::Handle<v8::Value> init_navigatorJSObject(const v8::Arguments& args); 	
public:
	static v8::Handle<v8::Value> alert(const v8::Arguments& args); 	
	static v8::Handle<v8::Value> clearInterval(const v8::Arguments& args); 	
	static v8::Handle<v8::Value> clearTimeout(const v8::Arguments& args); 	
	static v8::Handle<v8::Value> setInterval(const v8::Arguments& args);
	static v8::Handle<v8::Value> setTimeout(const v8::Arguments& args); 	

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(closed)//Returns a Boolean value indicating whether a window has been closed or not
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(defaultStatus)//Sets or returns the default text in the statusbar of a window
//DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(document)//Returns the Document object for the window (See Document object)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(frames)//Returns an array of all the frames (including iframes) in the current window
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(history)//Returns the History object for the window (See History object)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(innerHeight)//Sets or returns the inner height of a window's content area
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(innerWidth)//Sets or returns the inner width of a window's content area
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(length)//Returns the number of frames (including iframes) in a window
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(location)//Returns the Location object for the window (See Location object)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(name)//Sets or returns the name of a window
//DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(navigator)//Returns the Navigator object for the window (See Navigator object)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(opener)//Returns a reference to the window that created the window
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(outerHeight)//Sets or returns the outer height of a window, including toolbars/scrollbars
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(outerWidth)//Sets or returns the outer width of a window, including toolbars/scrollbars
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(pageXOffset)//Returns the pixels the current document has been scrolled (horizontally) from the upper left corner of the window
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(pageYOffset)//Returns the pixels the current document has been scrolled (vertically) from the upper left corner of the window
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(parent)//Returns the parent window of the current window
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(screen)//Returns the Screen object for the window (See Screen object)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(screenLeft)//Returns the x coordinate of the window relative to the screen
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(screenTop)//Returns the y coordinate of the window relative to the screen
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(screenX)//Returns the x coordinate of the window relative to the screen
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(screenY)//Returns the y coordinate of the window relative to the screen
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(self)//Returns the current window
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(status)//Sets the text in the statusbar of a window
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(top)//Returns the topmost browser window


DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(alert)// Displays an alert box with a message and an OK button	
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(clearInterval)// 	Clears a timer set with setInterval()
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(clearTimeout)// 	Clears a timer set with setTimeout()
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(setInterval)// 	Calls a function or evaluates an expression at specified intervals (in milliseconds)
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(setTimeout)// 	Calls a function or evaluates an expression after a specified number of milliseconds


};
#endif
