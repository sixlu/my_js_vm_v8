#include "event.h"

const unsigned short Event::CAPTURING_PHASE=1;
const unsigned short Event::AT_TARGET=2;
const unsigned short Event::BUBBLING_PHASE=3;

hash_map<string,string> Event::_eventAttributeToType;

INIT_STATIC_JAVASCRIPTATTRI_NAME(Event,type)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Event,target)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Event,currentTarget)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Event,eventPhase)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Event,bubbles)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Event,cancelable)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Event,timeStamp)


INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Event,stopPropagation)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Event,preventDefault)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Event,initEvent)


Event::Event():_isPreventDefault(false),_isStopPropagation(false){
 
    embed();
}
Event::~Event(){

}

v8::Handle<v8::ObjectTemplate> Event::embed(){

   if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
   }   
   
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Event,type).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Event,target).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Event,currentTarget).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Event,eventPhase).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Event,bubbles).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Event,cancelable).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Event,timeStamp).c_str()), Event::GetProperty, Event::SetProperty);
  

   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Event,stopPropagation).c_str()), v8::FunctionTemplate::New(Event::stopPropagation));
   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Event,preventDefault).c_str()), v8::FunctionTemplate::New(Event::preventDefault));
   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Event,initEvent).c_str()), v8::FunctionTemplate::New(Event::initEvent));


   return _templ;

}

Handle<Value> Event::GetProperty(Local<String> property,const AccessorInfo &info){
   EventPtr cur_event =(EventPtr) embedObject::UnWrap(info);
   char* property_name = (char*)embedObject::ToCString(property).c_str();
  
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Event,type).c_str())==0 ){
        return v8::String::New(cur_event->type.c_str());
   } 

   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Event,target).c_str())==0 ){
        return cur_event->target->newInstance<EventTargetPtr>();
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Event,currentTarget).c_str())==0 ){
        return cur_event->currentTarget->newInstance<EventTargetPtr>();
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Event,eventPhase).c_str())==0 ){
        return v8::Integer::New(cur_event->eventPhase);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Event,bubbles).c_str())==0 ){
        return v8::Boolean::New(cur_event->bubbles);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Event,cancelable).c_str())==0 ){
        return v8::Boolean::New(cur_event->cancelable);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Event,timeStamp).c_str())==0 ){
        return v8::Integer::New(cur_event->timeStamp);
   }
}

void Event::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

}



void  Event::stopPropagation(){
   
   _isStopPropagation=true;
}

void  Event::preventDefault(){
   _isPreventDefault=true;
}

bool  Event::isPreventDefault(){
    return _isPreventDefault;
}

bool  Event::isStopPropagation(){
    return _isStopPropagation;
}

void  Event::initEvent(string &eventTypeArg,bool canBubbleArg,bool cancelableArg){
      type = eventTypeArg;
      bubbles = canBubbleArg;
      cancelable = cancelableArg;
      
}

v8::Handle<v8::Value> Event::stopPropagation(const v8::Arguments& args){
     EventPtr cur_event =(EventPtr) embedObject::UnWrap(args);
     cur_event->stopPropagation();
}

v8::Handle<v8::Value> Event::preventDefault(const v8::Arguments& args){
    
     EventPtr cur_event =(EventPtr) embedObject::UnWrap(args);
     cur_event->preventDefault();
}

v8::Handle<v8::Value> Event::initEvent(const v8::Arguments& args){
    if(args.Length()>=3){

       EventPtr cur_event =(EventPtr) embedObject::UnWrap(args);
       Local<v8::Value> type_value = args[0];
       Local<v8::Value> bubbles_value= args[1];
       Local<v8::Value> cancelable_value = args[2];

       if(type_value->IsString() && bubbles_value->IsBoolean() && cancelable_value->IsBoolean()){
           string type = embedObject::ToCString(type_value);
           bool bubbles = bubbles_value->BooleanValue();
           bool cancelable = cancelable_value->BooleanValue();
           cur_event->initEvent(type,bubbles,cancelable);
       }

    }
}

