#include "uievent.h"
INIT_STATIC_JAVASCRIPTATTRI_NAME(UIEvent,view)
INIT_STATIC_JAVASCRIPTATTRI_NAME(UIEvent,detail)

INIT_STATIC_JAVASCRIPTFUNCTION_NAME(UIEvent,initUIEvent)


hash_map<string,string> UIEvent::_type;

UIEvent::UIEvent(){

   embed();
}

UIEvent::~UIEvent(){

}

void  UIEvent::initUIEvent(string& typeArg,bool canBubbleArg,bool cancelableArg,void* viewArg,long detailArg){
     this->initEvent(typeArg,canBubbleArg,cancelableArg);
     this->view = viewArg;
     this->detail = detailArg;
}

v8::Handle<v8::ObjectTemplate> UIEvent::embed(){

   if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
   }   
   
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(UIEvent,view).c_str()), UIEvent::GetProperty, UIEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(UIEvent,detail).c_str()), UIEvent::GetProperty, UIEvent::SetProperty);
  

   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(UIEvent,initUIEvent).c_str()), v8::FunctionTemplate::New(UIEvent::initUIEvent));


   return _templ;

}

Handle<Value> UIEvent::GetProperty(Local<String> property,const AccessorInfo &info){
   UIEventPtr cur_event =(UIEventPtr) embedObject::UnWrap(info);
   char* property_name = (char*)embedObject::ToCString(property).c_str();

   
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(UIEvent,detail).c_str())==0 ){
        return v8::Integer::New(cur_event->detail);
   }
   
}

void UIEvent::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

}

v8::Handle<v8::Value> UIEvent::initUIEvent(const v8::Arguments& args){

   if(args.Length()>=5){

       UIEventPtr cur_event =(UIEventPtr) embedObject::UnWrap(args);
       Local<v8::Value> type_value = args[0];
       Local<v8::Value> bubbles_value= args[1];
       Local<v8::Value> cancelable_value = args[2];
       Local<v8::Value> view_value = args[3];
       Local<v8::Value> detail_value = args[4];
       

       if(type_value->IsString() && bubbles_value->IsBoolean() && cancelable_value->IsBoolean()){
           string type = embedObject::ToCString(type_value);
           bool bubbles = bubbles_value->BooleanValue();
           bool cancelable = cancelable_value->BooleanValue();
           long detail = detail_value->IntegerValue();
           cur_event->initUIEvent(type,bubbles,cancelable,NULL,detail);
       }

   }
}




hash_map<string,string>& UIEvent::listEventType(){

   if(UIEvent::_type.size()==0){
        UIEvent::initEventType();
   }   
   
   return UIEvent::_type;

}

void UIEvent::initEventType(){

}
