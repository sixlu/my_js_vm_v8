#ifndef  V8_BUTTON_H
#define  V8_BUTTON_H



#include "htmlElement.h"
#include "form.h"


class Button;

typedef Button* ButtonPtr;


class Button:public HTMLElement{
public:
   Button(xmlNodePtr node,FormPtr form);
   virtual ~Button();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:
   FormPtr getForm();

private:
   FormPtr _form;
public:

   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(form)//Returns a reference to the form that contains a button 	Yes


DECLARE_STATIC_ATTRNAME(disabled,disabled)//Sets or returns whether a button is disabled, or not 	Yes
DECLARE_STATIC_ATTRNAME(name,name)//Sets or returns the value of the name attribute of a button 	Yes
DECLARE_STATIC_ATTRNAME(type,type)//Sets or returns the type of a button 	Yes
DECLARE_STATIC_ATTRNAME(value,value)//Sets or returns the value of the value attribute of a button 	Yes
};
#endif
