#include "touchList.h"


INIT_STATIC_JAVASCRIPTATTRI_NAME(TouchList,length)

INIT_STATIC_JAVASCRIPTFUNCTION_NAME(TouchList,item)


TouchList::TouchList(){

  embed();
}

TouchList::~TouchList(){

}

TouchPtr TouchList::item(unsigned long index){
   
    if(index< _items.size()){
       return _items[index];
    }else{
       return NULL;
    }
  
}

void TouchList::add(TouchPtr touch){
   _items.push_back(touch);
}

v8::Handle<v8::ObjectTemplate> TouchList::embed(){

   if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
   }   
   
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(TouchList,length).c_str()), TouchList::GetProperty, TouchList::SetProperty);

   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(TouchList,item).c_str()), v8::FunctionTemplate::New(TouchList::item));



   return _templ;

}

Handle<Value> TouchList::GetProperty(Local<String> property,const AccessorInfo &info){
   TouchListPtr cur_touchlist =(TouchListPtr) embedObject::UnWrap(info);
   char* property_name = (char*)embedObject::ToCString(property).c_str();

   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(TouchList,length).c_str())==0 ){
        return v8::Integer::New(cur_touchlist->length);
   }
}

void TouchList::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

}

v8::Handle<v8::Value> TouchList::item(const v8::Arguments& args){
   if(args.Length()>=1  ){
       TouchListPtr cur_touchlist =(TouchListPtr) embedObject::UnWrap(args);
       int index = args[0]->Int32Value();;
       TouchPtr touch = (TouchPtr)cur_touchlist->item(index);
       if(touch)
          return touch->newInstance<TouchPtr>();
   }
}



