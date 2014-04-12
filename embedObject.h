
#ifndef  V8_EMBED_H
#define V8_EMBED_H

#include "common.h"

class embedObject;

typedef embedObject * embedObjectPtr;

class embedObject {



public:
    embedObject():_templ(NULL){

//      _obj=NULL;
    }

#define JAVASCRIPT_ATTRNAME(CLASS_NAME,JAVASCRIPT_ATTRI_NAME)  CLASS_NAME::_javascript_##JAVASCRIPT_ATTRI_NAME 

#define XML_ATTRNAME(CLASS_NAME,XML_ATTRI_NAME)  CLASS_NAME::_xml_##XML_ATTRI_NAME

#define JAVASCRIPT_FUNCNAME(CLASS_NAME,JAVASCRIPT_FUNC_NAME) CLASS_NAME::_javascript_function_##JAVASCRIPT_FUNC_NAME    

#define DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(NAME)  \
   static string _javascript_##NAME;

 
#define DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(NAME)  \
   static string _javascript_function_##NAME; 

#define DECLARE_STATIC_ATTRNAME(JAVASCRIPT_ATTRI_NAME,XML_ATTRI_NAME)  \
   static string _javascript_##JAVASCRIPT_ATTRI_NAME;                               \
   static string _xml_##XML_ATTRI_NAME;


#define INIT_STATIC_JAVASCRIPTATTRI_NAME(CLASS_NAME,NAME)  \
   string CLASS_NAME::_javascript_##NAME = #NAME; 


#define INIT_STATIC_JAVASCRIPTFUNCTION_NAME(CLASS_NAME,NAME)  \
   string CLASS_NAME::_javascript_function_##NAME = #NAME; 



#define INIT_STATIC_ATTRNAME(CLASS_NAME,JAVASCRIPT_ATTRI_NAME,XML_ATTRI_NAME)  \
   string CLASS_NAME::_javascript_##JAVASCRIPT_ATTRI_NAME = #JAVASCRIPT_ATTRI_NAME;           \
   string CLASS_NAME::_xml_##XML_ATTRI_NAME = #XML_ATTRI_NAME;


public:
   
   string getXmlAttrNameByJsAttrName(string &js_attr_nam){

        return javascriptAttrName_map_xmlAttrName[js_attr_nam];

   }   

//   v8::Handle<v8::ObjectTemplate> embed()=0;

public:
   /*
   v8::Local<v8::Object> newInstance(){
     if ((*_obj)==NULL){
        _obj = _templ->NewInstance();
        _obj->SetInternalField(0, External::New(this));
     }
     return _obj;
   }
   */
   template<class T>
   v8::Local<v8::Object> newInstance(){
     if ((*_obj)==NULL ){
        _obj = _templ->NewInstance();
        _obj->SetInternalField(0, External::New((T)this));
     }
     return _obj;
   }
public:
   /*
   static char * ToCString(Local<v8::Value> &value){
       v8::String::Utf8Value value_str(value);
       return  *value_str ? *value_str : NULL;
   }

   static char * ToCString(Local<v8::String> &value){
       v8::String::Utf8Value value_str(value);
       return  *value_str ? *value_str : NULL;
   }
   */
   static string ToCString(Local<v8::Value> &value){
       String::Utf8Value utf8_value(value);
       return string(*utf8_value);
   }
   static string ToCString(Local<v8::String> &value){
       String::Utf8Value utf8_value(value);
       return string(*utf8_value);
   }
   
   template<class T>
   static v8::Handle<v8::Value> toJsArray(vector<T> &vt){

       Local<Array> array = v8::Array::New(vt.size());
       int i=0;
       while(i<vt.size()){
         Local<v8::Object> obj = vt[i]->newInstance<T>();
         array->Set(i, obj);
         i++;
       }   
       return array;

   }

   inline static void* UnWrap(const Local<Value>& value){
       
       Local<Object> self = value->ToObject();
       Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
       return wrap->Value();
   }

   static void* UnWrap(const AccessorInfo& info){
       Local<Object> self = info.Holder();
       //printf("self->InternalFieldCount()=%d\n",self->InternalFieldCount());
       Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
       return  wrap->Value();

   }

   static void* UnWrap(const v8::Arguments& args){
       Local<Object> self = args.Holder(); 
       Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
       return  wrap->Value();
   }

protected:
   map<string,string> javascriptAttrName_map_xmlAttrName;

protected:
  Handle<ObjectTemplate> _templ;
  v8::Local<v8::Object>  _obj;
};

#endif
