#ifndef  V8_FRAMESET_H
#define  V8_FRAMESET_H



#include "htmlElement.h"





class Frameset:public HTMLElement{

public:
   Frameset(xmlNodePtr node);
   virtual ~Frameset();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

   //static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   //static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);
public:
DECLARE_STATIC_ATTRNAME(cols,cols)//Sets or returns the value of the cols attribute in a frameset 	Yes
DECLARE_STATIC_ATTRNAME(rows,rows)//Sets or returns the value of the rows attribute in a frameset 	Yes
};
#endif
