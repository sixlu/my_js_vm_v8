#include "gestureEvent.h"

INIT_STATIC_JAVASCRIPTATTRI_NAME(GestureEvent,altKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(GestureEvent,ctrlKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(GestureEvent,metaKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(GestureEvent,shiftKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(GestureEvent,target)
INIT_STATIC_JAVASCRIPTATTRI_NAME(GestureEvent,rotation)
INIT_STATIC_JAVASCRIPTATTRI_NAME(GestureEvent,scale)

INIT_STATIC_JAVASCRIPTFUNCTION_NAME(GestureEvent,initGestureEvent)


hash_map<string,string> GestureEvent::_type;


GestureEvent::GestureEvent(){

  embed();
}

GestureEvent::~GestureEvent(){

}

void GestureEvent::initGestureEvent(string& type,
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
                      EventTargetPtr target,
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
   this->target= target;
   this->scale = scale;
   this->rotation = rotation;


}

v8::Handle<v8::ObjectTemplate> GestureEvent::embed(){

   if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
   }   
   
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(GestureEvent,altKey).c_str()), GestureEvent::GetProperty, GestureEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(GestureEvent,ctrlKey).c_str()), GestureEvent::GetProperty, GestureEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(GestureEvent,metaKey).c_str()), GestureEvent::GetProperty, GestureEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(GestureEvent,shiftKey).c_str()), GestureEvent::GetProperty, GestureEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(GestureEvent,target).c_str()), GestureEvent::GetProperty, GestureEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(GestureEvent,rotation).c_str()), GestureEvent::GetProperty, GestureEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(GestureEvent,scale).c_str()), GestureEvent::GetProperty, GestureEvent::SetProperty);



   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(GestureEvent,initGestureEvent).c_str()), v8::FunctionTemplate::New(GestureEvent::initGestureEvent));


   return _templ;

}

Handle<Value> GestureEvent::GetProperty(Local<String> property,const AccessorInfo &info){
   GestureEventPtr cur_gestureevent =(GestureEventPtr) embedObject::UnWrap(info);
   char* property_name = (char*)embedObject::ToCString(property).c_str();


   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(GestureEvent,altKey).c_str())==0 ){
        return v8::Boolean::New(cur_gestureevent->altKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(GestureEvent,ctrlKey).c_str())==0 ){
        return v8::Boolean::New(cur_gestureevent->ctrlKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(GestureEvent,metaKey).c_str())==0 ){
        return v8::Boolean::New(cur_gestureevent->metaKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(GestureEvent,shiftKey).c_str())==0 ){
        return v8::Boolean::New(cur_gestureevent->shiftKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(GestureEvent,target).c_str())==0 ){
        return cur_gestureevent->target->newInstance<EventTargetPtr>();
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(GestureEvent,rotation).c_str())==0 ){
        return v8::Number::New(cur_gestureevent->rotation);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(GestureEvent,scale).c_str())==0 ){
        return v8::Number::New(cur_gestureevent->scale);
   }
  
}

void GestureEvent::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

}

v8::Handle<v8::Value> GestureEvent::initGestureEvent(const v8::Arguments& args){

     if(args.Length()>=18){

       GestureEventPtr cur_event =(GestureEventPtr) embedObject::UnWrap(args);
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
       Local<v8::Value> target_value = args[offset++];
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
          && target_value->IsObject()
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
           EventTargetPtr target  = (EventTargetPtr)embedObject::UnWrap(target_value);
           float scale = (float)scale_value->NumberValue(); 
           float rotation = (float)rotation_value->NumberValue(); 
           cur_event->initGestureEvent(type,bubbles,cancelable,view,detail,screenX,screenY,clientX,clientY,
                                     ctrlKey,altKey,shiftKey,metaKey,target,
                                     scale,rotation);

       }   

    }

}



hash_map<string,string>& GestureEvent::listEventType(){

   if(GestureEvent::_type.size()==0){
        GestureEvent::initEventType();
   }   
   
   return GestureEvent::_type;

}

void GestureEvent::initEventType(){

   GestureEvent::_type["gesturestart"]="ongesturestart";
   GestureEvent::_type["gesturechange"]="ongesturechange";
   GestureEvent::_type["gestureend"]="ongestureend";
   

   Event::_eventAttributeToType["ongesturestart"]="gesturestart";
   Event::_eventAttributeToType["ongesturechange"]="gesturechange";
   Event::_eventAttributeToType["ongestureend"]="gestureend";
}
