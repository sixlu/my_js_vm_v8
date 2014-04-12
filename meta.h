#ifndef  V8_META_H
#define  V8_META_H



#include "htmlElement.h"





class Meta:public HTMLElement{

public:
   Meta(xmlNodePtr node);
   virtual ~Meta();

public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);
public:
DECLARE_STATIC_ATTRNAME(content,content)//Sets or returns the value of the content attribute of a meta element 	Yes
DECLARE_STATIC_ATTRNAME(httpEquiv,httpEquiv)//Sets or returns an HTTP header for the information in the content attribute 	Yes
DECLARE_STATIC_ATTRNAME(name,name)//Sets or returns a name for the information in the content attribute 	Yes
DECLARE_STATIC_ATTRNAME(scheme,scheme)//Sets or returns how the value of content should be interpreted 	Yes
};
#endif
