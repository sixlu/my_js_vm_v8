#ifndef  V8_INPUT_H
#define  V8_INPUT_H



#include "htmlElement.h"





class Input:public HTMLElement{
public:
   Input(xmlNodePtr node);
   virtual ~Input();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:

DECLARE_STATIC_ATTRNAME(disabled,disabled)//Sets or returns whether a button is disabled, or not 	Yes
DECLARE_STATIC_ATTRNAME(form,form)//Returns a reference to the form that contains the input button 	Yes
DECLARE_STATIC_ATTRNAME(name,name)//Sets or returns the value of the name attribute of an input button 	Yes
DECLARE_STATIC_ATTRNAME(type,type)//Returns which type of form element the button is 	Yes
DECLARE_STATIC_ATTRNAME(value,value)//Sets or returns the value of the value attribute of a button 	Yes
DECLARE_STATIC_ATTRNAME(checked,checked)//Sets or returns the checked state of a checkbox 	Yes
DECLARE_STATIC_ATTRNAME(defaultChecked,defaultChecked)//Returns the default value of the checked attribute 	Yes
DECLARE_STATIC_ATTRNAME(accept,accept)//Sets or returns a comma-separated list of accepted content types 	Yes
DECLARE_STATIC_ATTRNAME(defaultValue,defaultValue)//Sets or returns the default value of a password field 	Yes
DECLARE_STATIC_ATTRNAME(maxLength,maxLength)//Sets or returns the maximum number of characters allowed in a password field 	Yes
DECLARE_STATIC_ATTRNAME(readOnly,readOnly)//Sets or returns whether a password field is read-only, or not 	Yes
DECLARE_STATIC_ATTRNAME(size,size)//Sets or returns the width of a password field (in number of characters) 	Yes

};
#endif
