#ifndef  V8_FORM_H
#define  V8_FORM_H



#include "htmlElement.h"


class Form;

typedef Form* FormPtr;



class Form:public HTMLElement{
public:
   Form(xmlNodePtr node);
   virtual ~Form();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
//Collection 	Description 	W3C
//elements[] 	Returns an array of all elements in a form

DECLARE_STATIC_ATTRNAME(acceptCharset,acceptCharset)//Sets or returns the value of the accept-charset attribute in a form 	Yes
DECLARE_STATIC_ATTRNAME(action,action)//Sets or returns the value of the action attribute in a form 	Yes
DECLARE_STATIC_ATTRNAME(enctype,enctype)//Sets or returns the value of the enctype attribute in a form 	Yes
DECLARE_STATIC_ATTRNAME(length,length)//Returns the number of elements in a form 	Yes
DECLARE_STATIC_ATTRNAME(method,method)//Sets or returns the value of the method attribute in a form 	Yes
DECLARE_STATIC_ATTRNAME(name,name)//Sets or returns the value of the name attribute in a form 	Yes
DECLARE_STATIC_ATTRNAME(target,target)//Sets or returns the value of the target attribute in a form 	Yes
};
#endif
