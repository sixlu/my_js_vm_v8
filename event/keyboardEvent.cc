#include "keyboardEvent.h"

INIT_STATIC_JAVASCRIPTATTRI_NAME(KeyboardEvent,screenX)
INIT_STATIC_JAVASCRIPTATTRI_NAME(KeyboardEvent,screenY)
INIT_STATIC_JAVASCRIPTATTRI_NAME(KeyboardEvent,clientX)
INIT_STATIC_JAVASCRIPTATTRI_NAME(KeyboardEvent,clientY)
INIT_STATIC_JAVASCRIPTATTRI_NAME(KeyboardEvent,ctrlKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(KeyboardEvent,shiftKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(KeyboardEvent,altKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(KeyboardEvent,metaKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(KeyboardEvent,button)
INIT_STATIC_JAVASCRIPTATTRI_NAME(KeyboardEvent,relatedTarget)

INIT_STATIC_JAVASCRIPTFUNCTION_NAME(KeyboardEvent,initKeyboardEvent)



hash_map<string,string> KeyboardEvent::_type;

KeyboardEvent::KeyboardEvent(){

   embed();
}

KeyboardEvent::~KeyboardEvent(){


}

v8::Handle<v8::ObjectTemplate> KeyboardEvent::embed(){

   if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
   }   
   
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(KeyboardEvent,screenX).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(KeyboardEvent,screenY).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(KeyboardEvent,clientX).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(KeyboardEvent,clientY).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(KeyboardEvent,ctrlKey).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(KeyboardEvent,shiftKey).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(KeyboardEvent,altKey).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(KeyboardEvent,metaKey).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(KeyboardEvent,button).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(KeyboardEvent,relatedTarget).c_str()), Event::GetProperty, Event::SetProperty);


   //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(KeyboardEvent,initKeyboardEvent).c_str()), v8::FunctionTemplate::New(KeyboardEvent::initKeyboardEvent));

 
   return _templ;

}

Handle<Value> KeyboardEvent::GetProperty(Local<String> property,const AccessorInfo &info){
   
   KeyboardEventPtr cur_event =(KeyboardEventPtr) embedObject::UnWrap(info);
   char* property_name = (char*)embedObject::ToCString(property).c_str();

   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(KeyboardEvent,screenX).c_str())==0 ){
        return v8::Integer::New(cur_event->screenX);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(KeyboardEvent,screenY).c_str())==0 ){
        return v8::Integer::New(cur_event->screenY);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(KeyboardEvent,clientX).c_str())==0 ){
        return v8::Integer::New(cur_event->clientX);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(KeyboardEvent,clientY).c_str())==0 ){
        return v8::Integer::New(cur_event->clientY);
   }

   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(KeyboardEvent,ctrlKey).c_str())==0 ){
        return v8::Boolean::New(cur_event->ctrlKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(KeyboardEvent,shiftKey).c_str())==0 ){
        return v8::Boolean::New(cur_event->shiftKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(KeyboardEvent,altKey).c_str())==0 ){
        return v8::Boolean::New(cur_event->altKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(KeyboardEvent,metaKey).c_str())==0 ){
        return v8::Boolean::New(cur_event->metaKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(KeyboardEvent,button).c_str())==0 ){
        return v8::Integer::New(cur_event->button);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(KeyboardEvent,relatedTarget).c_str())==0 ){
        return cur_event->relatedTarget->newInstance<EventTargetPtr>();
   }



   
}

void KeyboardEvent::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

}

void KeyboardEvent::initKeyboardEvent(string &typeArg, 
                                    bool canBubbleArg, 
                                    bool cancelableArg, 
                                    void* viewArg, 
                                    long detailArg, 
                                    long screenXArg, 
                                    long screenYArg, 
                                    long clientXArg, 
                                    long clientYArg, 
                                    bool ctrlKeyArg, 
                                    bool altKeyArg, 
                                    bool shiftKeyArg, 
                                    bool metaKeyArg, 
                                    unsigned short buttonArg, 
                                    EventTargetPtr relatedTargetArg){


   this->initUIEvent(typeArg,canBubbleArg,cancelableArg,viewArg,detailArg);

   this->screenX=screenXArg;
   this->screenY=screenYArg;
   this->clientX=clientXArg;
   this->clientY=clientYArg;
   this->ctrlKey=ctrlKeyArg;
   this->shiftKey=shiftKeyArg;
   this->altKey=altKeyArg;
   this->metaKey=metaKeyArg;
   this->button=buttonArg;
   this->relatedTarget=relatedTargetArg;

}


hash_map<string,string>& KeyboardEvent::listEventType(){

   if(KeyboardEvent::_type.size()==0){
        KeyboardEvent::initEventType();
   }
   
   return KeyboardEvent::_type;

}

void KeyboardEvent::initEventType(){

   KeyboardEvent::_type["keydown"]="onkeydown";
   KeyboardEvent::_type["keypress"]="onkeypress";
   KeyboardEvent::_type["keyup"]="onkeyup";
   
   Event::_eventAttributeToType["onkeydown"]="keydown";
   Event::_eventAttributeToType["onkeypress"]="keypress";
   Event::_eventAttributeToType["onkeyup"]="keyup";
}
