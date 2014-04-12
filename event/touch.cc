#include "touch.h"

INIT_STATIC_JAVASCRIPTATTRI_NAME(Touch,clientX)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Touch,clientY)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Touch,identifier)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Touch,pageX)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Touch,pageY)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Touch,screenX)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Touch,screenY)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Touch,target)

Touch::Touch(){

  embed();
}

Touch::~Touch(){

}

v8::Handle<v8::ObjectTemplate> Touch::embed(){

   if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
   }   
   
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Touch,clientX).c_str()), Touch::GetProperty, Touch::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Touch,clientY).c_str()), Touch::GetProperty, Touch::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Touch,identifier).c_str()), Touch::GetProperty, Touch::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Touch,pageX).c_str()), Touch::GetProperty, Touch::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Touch,pageY).c_str()), Touch::GetProperty, Touch::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Touch,screenX).c_str()), Touch::GetProperty, Touch::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Touch,screenY).c_str()), Touch::GetProperty, Touch::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Touch,target).c_str()), Touch::GetProperty, Touch::SetProperty);




   return _templ;

}

Handle<Value> Touch::GetProperty(Local<String> property,const AccessorInfo &info){
   TouchPtr cur_touch =(TouchPtr) embedObject::UnWrap(info);
   char* property_name = (char*)embedObject::ToCString(property).c_str();

   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Touch,clientX).c_str())==0 ){
        return v8::Integer::New(cur_touch->clientX);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Touch,clientY).c_str())==0 ){
        return v8::Integer::New(cur_touch->clientY);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Touch,identifier).c_str())==0 ){
        return v8::Integer::New(cur_touch->identifier);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Touch,pageX).c_str())==0 ){
        return v8::Integer::New(cur_touch->pageX);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Touch,pageY).c_str())==0 ){
        return v8::Integer::New(cur_touch->pageY);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Touch,screenX).c_str())==0 ){
        return v8::Integer::New(cur_touch->screenX);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Touch,screenY).c_str())==0 ){
        return v8::Integer::New(cur_touch->screenY);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Touch,target).c_str())==0 ){
        return cur_touch->target->newInstance<EventTargetPtr>();
   }
}

void Touch::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

}

