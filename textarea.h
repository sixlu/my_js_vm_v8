#ifndef  V8_TEXTAREA_H
#define  V8_TEXTAREA_H



#include "htmlElement.h"





class Textarea:public HTMLElement{
public:
   Textarea(xmlNodePtr node);
   virtual ~Textarea();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);
public:
DECLARE_STATIC_ATTRNAME(cols,cols)//Sets or returns the width of a text area 	Yes
DECLARE_STATIC_ATTRNAME(defaultValue,defaultValue)//Sets or returns the default value of a text area 	Yes
DECLARE_STATIC_ATTRNAME(disabled,disabled)//Sets or returns whether the text area is disabled, or not 	Yes
DECLARE_STATIC_ATTRNAME(form,form)//Returns a reference to the form that contains the text area 	Yes
DECLARE_STATIC_ATTRNAME(name,name)//Sets or returns the name of a text area 	Yes
DECLARE_STATIC_ATTRNAME(readOnly,readOnly)//Sets or returns whether the contents of a text area is read-only 	Yes
DECLARE_STATIC_ATTRNAME(rows,rows)//Sets or returns the height (in rows) of a text area 	Yes
DECLARE_STATIC_ATTRNAME(type,type)//Returns the type of the form element the text area is 	Yes
DECLARE_STATIC_ATTRNAME(value,value)//Sets or returns the contents of a text area 	Yes

public:
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(select)//) 	Selects the entire contents of a text area 	Yes
};
#endif
