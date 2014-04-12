#ifndef  V8_BASE_H
#define  V8_BASE_H



#include "htmlElement.h"





class Base:public HTMLElement{

public:
   Base();
   virtual ~Base();

public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
DECLARE_STATIC_ATTRNAME(href,href)//Sets or returns the value of the href attribute in a base element 	Yes
DECLARE_STATIC_ATTRNAME(target,target)//Sets or returns the value of the target attribute in a base element 	Yes
};
#endif
