#include "touchEvent.h"

INIT_STATIC_JAVASCRIPTATTRI_NAME(TouchEvent,altKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(TouchEvent,ctrlKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(TouchEvent,metaKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(TouchEvent,shiftKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(TouchEvent,changedTouches)
INIT_STATIC_JAVASCRIPTATTRI_NAME(TouchEvent,targetTouches)
INIT_STATIC_JAVASCRIPTATTRI_NAME(TouchEvent,touches)
INIT_STATIC_JAVASCRIPTATTRI_NAME(TouchEvent,rotation)
INIT_STATIC_JAVASCRIPTATTRI_NAME(TouchEvent,scale)

INIT_STATIC_JAVASCRIPTFUNCTION_NAME(TouchEvent,initTouchEvent)


hash_map<string,string> TouchEvent::_type;


TouchEvent::TouchEvent(){

  embed();
}

TouchEvent::~TouchEvent(){

}

void TouchEvent::initTouchEvent(string& type,
                      bool canBubble,
                      bool cancelable,
                      void* view, 
                      long detail, 
                      long screenX, 
                      long screenY,
                      long clientX, 
                      long clientY,
                      bool ctrlKey,
                      bool altKey,
                      bool shiftKey,
                      bool metaKey,
                      TouchListPtr touches, 
                      TouchListPtr targetTouches, 
                      TouchListPtr changedTouches, 
                      float scale, 
                      float rotation){

   this->type =type;
   this->bubbles = canBubble;
   this->cancelable = cancelable;
   this->view = view;
   this->detail = detail;
   this->ctrlKey = ctrlKey;
   this->altKey = altKey;
   this->shiftKey = shiftKey;
   this->metaKey = metaKey;
   this->touches = touches;
   this->targetTouches = targetTouches;
   this->changedTouches = changedTouches;
   this->scale = scale;
   this->rotation = rotation;


}

v8::Handle<v8::ObjectTemplate> TouchEvent::embed(){

   if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
   }   
   
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(TouchEvent,altKey).c_str()), TouchEvent::GetProperty, TouchEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(TouchEvent,ctrlKey).c_str()), TouchEvent::GetProperty, TouchEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(TouchEvent,metaKey).c_str()), TouchEvent::GetProperty, TouchEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(TouchEvent,shiftKey).c_str()), TouchEvent::GetProperty, TouchEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(TouchEvent,changedTouches).c_str()), TouchEvent::GetProperty, TouchEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(TouchEvent,targetTouches).c_str()), TouchEvent::GetProperty, TouchEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(TouchEvent,touches).c_str()), TouchEvent::GetProperty, TouchEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(TouchEvent,rotation).c_str()), TouchEvent::GetProperty, TouchEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(TouchEvent,scale).c_str()), TouchEvent::GetProperty, TouchEvent::SetProperty);



   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(TouchEvent,initTouchEvent).c_str()), v8::FunctionTemplate::New(TouchEvent::initTouchEvent));


   return _templ;

}

Handle<Value> TouchEvent::GetProperty(Local<String> property,const AccessorInfo &info){
   TouchEventPtr cur_touchevent =(TouchEventPtr) embedObject::UnWrap(info);
   char* property_name = (char*)embedObject::ToCString(property).c_str();


   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(TouchEvent,altKey).c_str())==0 ){
        return v8::Boolean::New(cur_touchevent->altKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(TouchEvent,ctrlKey).c_str())==0 ){
        return v8::Boolean::New(cur_touchevent->ctrlKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(TouchEvent,metaKey).c_str())==0 ){
        return v8::Boolean::New(cur_touchevent->metaKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(TouchEvent,shiftKey).c_str())==0 ){
        return v8::Boolean::New(cur_touchevent->shiftKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(TouchEvent,changedTouches).c_str())==0 ){
        return cur_touchevent->changedTouches->newInstance<TouchListPtr>();
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(TouchEvent,targetTouches).c_str())==0 ){
        return cur_touchevent->targetTouches->newInstance<TouchListPtr>();
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(TouchEvent,touches).c_str())==0 ){
        return cur_touchevent->touches->newInstance<TouchListPtr>();
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(TouchEvent,rotation).c_str())==0 ){
        return v8::Number::New(cur_touchevent->rotation);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(TouchEvent,scale).c_str())==0 ){
        return v8::Number::New(cur_touchevent->scale);
   }
  
}

void TouchEvent::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

}

v8::Handle<v8::Value> TouchEvent::initTouchEvent(const v8::Arguments& args){

     if(args.Length()>=18){

       TouchEventPtr cur_event =(TouchEventPtr) embedObject::UnWrap(args);
       int offset=0;
       Local<v8::Value> type_value = args[offset++];
       Local<v8::Value> bubbles_value= args[offset++];
       Local<v8::Value> cancelable_value = args[offset++];
       Local<v8::Value> view_value = args[offset++];
       Local<v8::Value> detail_value = args[offset++];
       Local<v8::Value> screenX_value = args[offset++];
       Local<v8::Value> screenY_value = args[offset++];
       Local<v8::Value> clientX_value = args[offset++];
       Local<v8::Value> clientY_value = args[offset++];
       Local<v8::Value> ctrlKey_value = args[offset++];
       Local<v8::Value> altKey_value = args[offset++];
       Local<v8::Value> shiftKey_value = args[offset++];
       Local<v8::Value> metaKey_value = args[offset++];
       Local<v8::Value> touches_value = args[offset++];
       Local<v8::Value> targetTouches_value = args[offset++];
       Local<v8::Value> changedTouches_value = args[offset++];
       Local<v8::Value> scale_value = args[offset++];
       Local<v8::Value> rotation_value = args[offset++];

       if(type_value->IsString() 
          && bubbles_value->IsBoolean() 
          && cancelable_value->IsBoolean()

          && detail_value->IsInt32()
          && screenX_value->IsInt32()
          && screenY_value->IsInt32()
          && clientX_value->IsInt32()
          && clientY_value->IsInt32()
          && ctrlKey_value->IsBoolean()
          && altKey_value->IsBoolean()
          && shiftKey_value->IsBoolean()
          && metaKey_value->IsBoolean()
          && touches_value->IsObject()
          && targetTouches_value->IsObject()
          && changedTouches_value->IsObject()
          && scale_value->IsNumber()
          && rotation_value->IsNumber()
          ){

           string type = embedObject::ToCString(type_value);
           bool bubbles = bubbles_value->BooleanValue();
           bool cancelable = cancelable_value->BooleanValue();
           void * view = NULL;
           long detail = detail_value->Int32Value();
           long screenX = screenX_value->Int32Value(); 
           long screenY = screenY_value->Int32Value(); 
           long clientX = clientX_value->Int32Value(); 
           long clientY = clientY_value->Int32Value();
           bool ctrlKey = ctrlKey_value->BooleanValue();
           bool altKey  = altKey_value->BooleanValue();
           bool shiftKey= shiftKey_value->BooleanValue();
           bool metaKey = metaKey_value->BooleanValue();
           TouchListPtr touches  = (TouchListPtr)embedObject::UnWrap(touches_value); 
           TouchListPtr targetTouches= (TouchListPtr)embedObject::UnWrap(targetTouches_value); 
           TouchListPtr changedTouches  = (TouchListPtr)embedObject::UnWrap(changedTouches_value); 
           float scale = (float)scale_value->NumberValue(); 
           float rotation = (float)rotation_value->NumberValue(); 
           cur_event->initTouchEvent(type,bubbles,cancelable,view,detail,screenX,screenY,clientX,clientY,
                                     ctrlKey,altKey,shiftKey,metaKey,touches,targetTouches,changedTouches,
                                     scale,rotation);

       }   

    }

}



hash_map<string,string>& TouchEvent::listEventType(){

   if(TouchEvent::_type.size()==0){
        TouchEvent::initEventType();
   }   
   
   return TouchEvent::_type;

}

void TouchEvent::initEventType(){

   TouchEvent::_type["touchcancel"]="ontouchcancel";
   TouchEvent::_type["touchend"]="ontouchend";
   TouchEvent::_type["touchmove"]="ontouchmove";
   TouchEvent::_type["touchstart"]="ontouchstart";


   Event::_eventAttributeToType["ontouchcancel"]="touchcancel";
   Event::_eventAttributeToType["ontouchend"]="touchend";
   Event::_eventAttributeToType["ontouchmove"]="touchmove";
   Event::_eventAttributeToType["ontouchstart"]="touchstart";
}
