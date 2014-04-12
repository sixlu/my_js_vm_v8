#include "window.h"

INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,closed)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,defaultStatus)
//INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,document)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,frames)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,history)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,innerHeight)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,innerWidth)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,length)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,location)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,name)
//INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,navigator)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,opener)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,outerHeight)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,outerWidth)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,pageXOffset)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,pageYOffset)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,parent)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,screen)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,screenLeft)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,screenTop)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,screenX)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,screenY)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,self)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,status)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Window,top)


INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Window,alert)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Window,clearInterval)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Window,clearTimeout)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Window,setInterval)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Window,setTimeout)


Window::Window(map<string,string> &request_headers,string &url,map<string,string> &response_headers, string &response_body_str){

     //_isolate = Isolate::New();
     //_handleScope = HandleScope::CreateHandle(_isolate,NULL);
     //_handleScope = new HandleScope(_isolate);
     //HandleScope handle_scope;


     string appCodeName="Mozilla";
     string appName="Netscape";
     string appVersion="5.0 (iPhone; CPU iPhone OS 5_1_1 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Mobile/9B208";
     bool cookieEnabled = true;
     bool onLine=true;
     string platform="iPhone";
     string userAgent="Mozilla/5.0 (iPhone; CPU iPhone OS 5_1_1 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Mobile/9B208";

     string referrer = request_headers["Referer"];
     string lastModified = response_headers["Last-Modified"];
     vector<string> matchs;
     string match_regx = "charset=(.*)";
     IChrome::Utils::str_regx_match(response_headers["Content-Type"],match_regx,matchs);
     string encoding = ""; 
     if (matchs.size()>0)
        encoding = matchs[0];
     else  
        encoding = "utf8";
     string cookie = response_headers["Cookie"];

     _closed = false;  
     _defaultStatus = "luyang debug...";   
     _document = Document::New(response_body_str,referrer,url,lastModified,encoding,cookie);   
     _innerHeight = 50;    
     _innerWidth =320;    
     _name="";    
     _navigator =Navigator::New(appCodeName,appName,appVersion,platform,userAgent,cookieEnabled,onLine);
     _outerHeight=50;    
     _outerWidth=320;    
     _pageXOffset=0;   
     _pageYOffset=0;    
     _parent = NULL;
     _self  = this;


     embed();

     _defalutHeaders["User-Agent"]=userAgent;
     _defalutHeaders["Accept"]="*/*";
     _defalutHeaders["Accept-Language"]="zh-cn";
     //_defalutHeaders["Accept-Encoding"]="gzip, deflate";
     _defalutHeaders["Connection"]="keep-alive";
     

    
}

Window::~Window(){
}

bool Window::getclosed(){
  return _closed;
}
void Window::setclosed(bool closed){
  _closed=closed;
}
  
string Window::getdefaultStatus(){
  return _defaultStatus;
}
void Window::setdefaultStatus(string &defaultStatus){
  _defaultStatus=defaultStatus;
}
   
DocumentPtr Window::getdocument(){
  return _document;
}
void Window::setdocument(DocumentPtr document){
  _document=document;
}
           
int Window::getinnerHeight(){
  return _innerHeight;
}
void Window::setinnerHeight(int innerHeight){
  _innerHeight=innerHeight;
}
         
int Window::getinnerWidth(){
  return _innerWidth;
}
void Window::setinnerWidth(int innerWidth){
  _innerWidth=innerWidth;
}
    
string Window::getname(){
  return _name;
}
void Window::setname(string &name){
  _name=name;
}
    
NavigatorPtr Window::getnavigator(){
  return _navigator;
}
void Window::setnavigator(NavigatorPtr navigator){
  _navigator=navigator;
}
    
int Window::getouterHeight(){
  return _outerHeight;
}
void Window::setouterHeight(int outerHeight){
  _outerHeight=outerHeight;
}
    
int Window::getouterWidth(){
  return _outerWidth;
}
void Window::setouterWidth(int outerWidth){
  _outerWidth=outerWidth;
}
    
int Window::getpageXOffset(){
  return _pageXOffset;
}
void Window::setpageXOffset(int pageXOffset){
  _pageXOffset=pageXOffset;
}
   
int Window::getpageYOffset(){
  return _pageYOffset;
}
void Window::setpageYOffset(int pageYOffset){
  _pageYOffset=pageYOffset;
}
    
WindowPtr Window::getparent(){
  return _parent;
}
void Window::setparent(WindowPtr parent){
  _parent=parent;
}
  
WindowPtr Window::getself(){
  return _self;
}
void Window::setself(WindowPtr self){
  _self=self;
}

int Window::getContentFromUrl(const char* url,map<string,string> *response_headers,HttpUtil::BODY *response_body){
    if (url){
 
      map<string,string> request_headers=_defalutHeaders;
      
      request_headers["Referer"] = _document->getURL();
      string aurl=url;

      return HttpUtil::httpGet(request_headers,aurl,response_headers,response_body);

    }
    else
      return -1;
}

string Window::getScriptFromUrl(const char * url){
    
   if(url){
     map<string,string> response_headers;
     //HttpUtil::BODY response_body;
     HttpUtil::BODY *response_body = HttpUtil::newBody();

     if(getContentFromUrl(url,&response_headers,response_body)==0){

         string content_type= response_headers["Content-Type"];

         if(content_type.find("text/javascript")!=string::npos){
           string content = response_body->buf;
           return content;
         }
     }else
       return "";

   }else
     return "";
}

string Window::fetchScript(){
   
   string script="";
   string tagname="script";
   vector<xmlNodePtr> script_xml_nodes = _document->getElementsByTagName(tagname);
   vector<xmlNodePtr>::iterator itr = script_xml_nodes.begin();
   while(itr!= script_xml_nodes.end()){
      xmlNodePtr script_xml_node = (*itr);
      xmlAttrPtr attr = xmlHasProp(script_xml_node,(xmlChar*)"src");
      string content;
      if(attr){
         content = getScriptFromUrl((const char*)attr->children->content);
      }else{
         content=(char*) xmlNodeGetContent(script_xml_node);
      }
      
      script.append(content);
      itr++;
   }

   return script;

}
v8::Handle<v8::Value> Window::init_windowJSObject(const v8::Arguments& args){
     Local<Context> context= v8::Context::GetCurrent();
     WindowPtr window = (WindowPtr)context->GetAlignedPointerFromEmbedderData(1);//wrap->Value();
    
     //string tmp_value = window->getdefaultStatus();
     //printf("Window::init_windowJSObject %s\n",tmp_value.c_str());
     //printf("innerWidth=%d\n",window->getinnerWidth());

     //Local<Context> context= v8::Context::GetCurrent();
     ////Local<External> wrap = Local<External>::Cast(context->GetData());
     //WindowPtr window = (WindowPtr)context->GetAlignedPointerFromEmbedderData(1);//wrap->Value();
     
     return window->newInstance<WindowPtr>();
    

}

v8::Handle<v8::Value> Window::init_documentJSObject(const v8::Arguments& args){
     Local<Context> context= v8::Context::GetCurrent();
     WindowPtr window = (WindowPtr)context->GetAlignedPointerFromEmbedderData(1);//wrap->Value();
     DocumentPtr document = window->getdocument();
     return document->newInstance<DocumentPtr>();
    

}

v8::Handle<v8::Value> Window::init_navigatorJSObject(const v8::Arguments& args){
     Local<Context> context= v8::Context::GetCurrent();
     WindowPtr window = (WindowPtr)context->GetAlignedPointerFromEmbedderData(1);//wrap->Value();
     NavigatorPtr navigator = window->getnavigator();
     return navigator->newInstance<NavigatorPtr>();
    

}

void Window::createContext(){

  Handle<ObjectTemplate> global_templ = this->embed();//ObjectTemplate::New();
  
  //Handle<ObjectTemplate> global_templ = this->embed();
  Handle<ObjectTemplate> navigator_templ = _navigator->embed();
  Handle<ObjectTemplate> document_templ = _document->embed();
  //Handle<ObjectTemplate> window_templ = this->embed();
  
  //global_templ->Set(v8::String::New("navigator"), navigator_templ);
  //global_templ->Set(v8::String::New("document"), document_templ);


  global_templ->Set(v8::String::New("init_windowJSObject"), v8::FunctionTemplate::New(Window::init_windowJSObject));
  global_templ->Set(v8::String::New("init_documentJSObject"), v8::FunctionTemplate::New(Window::init_documentJSObject));
  global_templ->Set(v8::String::New("init_navigatorJSObject"), v8::FunctionTemplate::New(Window::init_navigatorJSObject));

  _context = Context::New(NULL, global_templ);
  _context->SetAlignedPointerInEmbedderData(1,this);

}

void Window::render(){

  _document->parseHtml();

     // Create a stack-allocated handle scope.
  //HandleScope handle_scope;

  createContext();

  
  Context::Scope context_scope(_context);

  string init_script_content = "window=init_windowJSObject();\r\ndocument=init_documentJSObject()\r\nnavigator=init_navigatorJSObject()\r\n";
  string script_content = init_script_content+ fetchScript();

  printf("===========begin script_content============\n");
  printf("%s\n",script_content.c_str());
  printf("===========end script_content============\n");


  //Handle<String> source = script_content.c_str();//ReadFile(argv[1]);//String::New(argv[1]);
  Handle<String> source = String::New(script_content.c_str());//ReadFile(argv[1]);//String::New(argv[1]);

  // Compile the source code.
  Handle<Script> script = Script::Compile(source);

  // Run the script to get the result.
  Handle<Value> result = script->Run();


  //Timer::handle(50);
  
  // Dispose the persistent context.
  _context.Dispose();


}


v8::Handle<v8::ObjectTemplate> Window::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
            //register self attribute
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,closed).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,defaultStatus).c_str()), Window::GetProperty, Window::SetProperty);
            //_templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,document).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,frames).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,history).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,innerHeight).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,innerWidth).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,length).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,location).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,name).c_str()), Window::GetProperty, Window::SetProperty);
            //_templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,navigator).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,opener).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,outerHeight).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,outerWidth).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,pageXOffset).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,pageYOffset).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,parent).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,screen).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,screenLeft).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,screenTop).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,screenX).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,screenY).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,self).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,status).c_str()), Window::GetProperty, Window::SetProperty);
            _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Window,top).c_str()), Window::GetProperty, Window::SetProperty);


            _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Window,alert).c_str()),v8::FunctionTemplate::New(Window::alert));
            _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Window,clearInterval).c_str()),v8::FunctionTemplate::New(Window::clearInterval));
            _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Window,clearTimeout).c_str()),v8::FunctionTemplate::New(Window::clearTimeout));
            _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Window,setInterval).c_str()),v8::FunctionTemplate::New(Window::setInterval));
            _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Window,setTimeout).c_str()),v8::FunctionTemplate::New(Window::setTimeout));



    }   
    return _templ;

}


Handle<Value> Window::GetProperty(Local<String> property,const AccessorInfo &info){
    WindowPtr window =NULL;
    //if(info.Holder()->InternalFieldCount()==0){
    //   Local<Context> context= v8::Context::GetCurrent();
    //   window = (WindowPtr)context->GetAlignedPointerFromEmbedderData(1);//wrap->Value();
    //}else{
    //   window =(WindowPtr) embedObject::UnWrap(info);
    //}
    window =(WindowPtr) embedObject::UnWrap(info);
    //printf("property->Length()=%d\n",property->Length());
    string tmp_property_name = embedObject::ToCString(property);
    const char *property_name = tmp_property_name.c_str();

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,closed).c_str())==0){
         return v8::Boolean::New(window->getclosed());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,defaultStatus).c_str())==0){
         string str= window->getdefaultStatus();
         return v8::String::New(str.c_str());
    }


    //if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,document).c_str())==0){
    //     DocumentPtr document = window->getdocument();
    //     return document->newInstance<DocumentPtr>();
    //}


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,frames).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,history).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,innerHeight).c_str())==0){
         return v8::Integer::New(window->getinnerHeight());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,innerWidth).c_str())==0){

         return v8::Integer::New(window->getinnerWidth());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,length).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,location).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,name).c_str())==0){

         string str= window->getname();
         return v8::String::New(str.c_str());
    }


    //if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,navigator).c_str())==0){

    //     NavigatorPtr navigator = window->getnavigator();
    //     return navigator->newInstance<NavigatorPtr>();
    //}


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,opener).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,outerHeight).c_str())==0){

         return v8::Integer::New(window->getouterHeight());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,outerWidth).c_str())==0){

         return v8::Integer::New(window->getouterWidth());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,pageXOffset).c_str())==0){

         return v8::Integer::New(window->getpageXOffset());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,pageYOffset).c_str())==0){

         return v8::Integer::New(window->getpageYOffset());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,parent).c_str())==0){

         WindowPtr parent = window->getparent();
         return parent->newInstance<WindowPtr>();
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,screen).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,screenLeft).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,screenTop).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,screenX).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,screenY).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,self).c_str())==0){

         WindowPtr self = window->getself();
         return self->newInstance<WindowPtr>();
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,status).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,top).c_str())==0){

    }




}


void Window::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

    WindowPtr window =(WindowPtr) embedObject::UnWrap(info);
    char* property_name =(char*) embedObject::ToCString(property).c_str();

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,defaultStatus).c_str())==0){

         string value_ptr = embedObject::ToCString(value);
         window->setdefaultStatus(value_ptr);
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,innerHeight).c_str())==0){
         window->setinnerHeight(value->Int32Value());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,innerWidth).c_str())==0){

         window->setinnerWidth(value->Int32Value());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,name).c_str())==0){

         string value_ptr = embedObject::ToCString(value);
         window->setname(value_ptr);
    }

    

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,outerHeight).c_str())==0){

         window->setouterHeight(value->Int32Value());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Window,outerWidth).c_str())==0){

         window->setouterWidth(value->Int32Value());
    }





}

v8::Handle<v8::Value> Window::alert(const v8::Arguments& args){

  if(args.Holder()->InternalFieldCount()==0){
     /*
     Local<Context> context= v8::Context::GetCurrent();
     WindowPtr window = (WindowPtr)context->GetAlignedPointerFromEmbedderData(1);//wrap->Value();
     string tmp_value = window->getdefaultStatus();
     printf("%s\n",tmp_value.c_str());
     */
     int count = args.Length();
     for (int i = 0; i < count; i++) {

       v8::String::Utf8Value str(args[i]); 
       if(*str){
          printf("%s\n", *str);
       }else{
          printf("%s\n","<string conversion failed>");
       }
     }
     return v8::Undefined();

  }else{
     int count = args.Length();
     for (int i = 0; i < count; i++) {

       v8::String::Utf8Value str(args[i]); 
       if(*str){
          printf("%s\n", *str);
       }else{
          printf("%s\n","<string conversion failed>");
       }
     }
     return v8::Undefined();
  }

}

v8::Handle<v8::Value> Window::clearInterval(const v8::Arguments& args){
       
       Local<Object> self = args.Holder();
       Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
       WindowPtr p =(WindowPtr) wrap->Value();
       if(p&& args.Length()>=1){
           int index = args[0]->Int32Value();
           Timer::delTimer(index);
       }

}


v8::Handle<v8::Value> Window::clearTimeout(const v8::Arguments& args){

       Local<Object> self = args.Holder();
       Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
       WindowPtr p =(WindowPtr) wrap->Value();
       if(p&& args.Length()>=1){
           int index = args[0]->Int32Value();
           Timer::delTimer(index);
       }
}


v8::Handle<v8::Value> Window::setInterval(const v8::Arguments& args){

       Local<Object> self = args.Holder();
       Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
       WindowPtr p =(WindowPtr) wrap->Value();
       if(p&& args.Length()>=2){
    
           Local<Function> jscallbackfunc = Local<v8::Function>::Cast(args[0]);
           int timeout= args[1]->Int32Value();    
           JsTimer* jstimer=JsTimer::New(timeout,true,jscallbackfunc);
           return v8::Integer::New(jstimer->getIndex());
    
       }

}


v8::Handle<v8::Value> Window::setTimeout(const v8::Arguments& args){

       Local<Object> self = args.Holder();
       Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
       WindowPtr p =(WindowPtr) wrap->Value();
       if(p&& args.Length()>=2){
    
           Local<Function> jscallbackfunc = Local<v8::Function>::Cast(args[0]);
           int timeout= args[1]->Int32Value();    
           JsTimer* jstimer=JsTimer::New(timeout,false,jscallbackfunc);
           return v8::Integer::New(jstimer->getIndex());
    
       }


}




