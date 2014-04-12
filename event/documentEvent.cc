#include "documentEvent.h"
//#include "uievent.h"
//#include "mouseEvent.h"
//#include "mutationevent.h"
//#include "touchEvent.h"
//#include "gestureEvent.h"
//#include "deviceOrientationEvent.h"

INIT_STATIC_JAVASCRIPTFUNCTION_NAME(DocumentEvent,createEvent)

hash_map<string,int> DocumentEvent::_supportEventModule;

DocumentEvent::DocumentEvent(){

   embed();
}

DocumentEvent::~DocumentEvent(){

}

v8::Handle<v8::ObjectTemplate> DocumentEvent::embed(){

   if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
   }   
   
   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(DocumentEvent,createEvent).c_str()), v8::FunctionTemplate::New(DocumentEvent::createEvent));


   return _templ;

}

void DocumentEvent::initSupportEventModule(){
   
    DocumentEvent::_supportEventModule["UIEvents"]=1;
    DocumentEvent::_supportEventModule["MouseEvents"]=1;
    DocumentEvent::_supportEventModule["MutationEvents"]=1;
    DocumentEvent::_supportEventModule["HTMLEvents"]=1;//event.initEvent
    DocumentEvent::_supportEventModule["TouchEvent"]=1;
    DocumentEvent::_supportEventModule["GestureEvent"]=1;
    DocumentEvent::_supportEventModule["DeviceOrientationEvent"]=1;

}

v8::Handle<v8::Value> DocumentEvent::createEvent(const v8::Arguments& args){
    if(args.Length()>=1){
        Local<Value> t= args[0];
        string type = embedObject::ToCString(t);
        EventPtr event;
        if(DocumentEvent::_supportEventModule[type]==1){
           if(strcasecmp(type.c_str(),"UIEvents")==0){
              event = new UIEvent();
              return event->newInstance<UIEventPtr>();
           }else if(strcasecmp(type.c_str(),"MouseEvents")==0){
              event = new MouseEvent();
              return event->newInstance<MouseEventPtr>();
           }else if(strcasecmp(type.c_str(),"MutationEvents")==0){
              event = new MutationEvent();
              return event->newInstance<MutationEventPtr>();
           }else if(strcasecmp(type.c_str(),"HTMLEvents")==0){
              event = new Event();
              return event->newInstance<EventPtr>();
           }else if(strcasecmp(type.c_str(),"TouchEvent")==0){
              event = new TouchEvent();
              return event->newInstance<TouchEventPtr>();
           }else if(strcasecmp(type.c_str(),"GestureEvent")==0){
              event = new GestureEvent();
              return event->newInstance<GestureEventPtr>();
           }else if(strcasecmp(type.c_str(),"DeviceOrientationEvent")==0){
              event = new DeviceOrientationEvent();
              return event->newInstance<DeviceOrientationEventPtr>();
           } 
        }else{
           return v8::ThrowException(v8::Exception::TypeError(v8::String::New("NOT_SUPPORTED_ERR")));
        }

    }

}

