#ifndef  V8_BODY_H
#define  V8_BODY_H



#include "htmlElement.h"


class Body;

typedef Body* BodyPtr;



class Body:public HTMLElement{

public:
   Body(xmlNodePtr node);
   virtual ~Body();

public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
DECLARE_STATIC_ATTRNAME(aLink,aLink)//Sets or returns the value of the alink attribute of the body element 	Yes
DECLARE_STATIC_ATTRNAME(background,background)//Sets or returns the value of the background attribute of the body element 	Yes
DECLARE_STATIC_ATTRNAME(bgColor,bgColor)//Sets or returns the value of the bgcolor attribute of the body element 	Yes
DECLARE_STATIC_ATTRNAME(link,link)//Sets or returns the value of the link attribute of the body element 	Yes
DECLARE_STATIC_ATTRNAME(text,text)//Sets or returns the value of the text attribute of the body element 	Yes
DECLARE_STATIC_ATTRNAME(vLink,vLink)//Sets or returns the value of the vlink attribute of the body element 	Yes

};
#endif
