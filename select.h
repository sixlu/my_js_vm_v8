#ifndef  V8_SELECT_H
#define  V8_SELECT_H



#include "htmlElement.h"

class Select;

typedef Select * SelectPtr;

class Select:public HTMLElement{

public:
   Select(xmlNodePtr node);
   virtual ~Select();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
//options 	Returns a collection of all the options in a dropdown list 	Yes
//Select Object Properties
DECLARE_STATIC_ATTRNAME(disabled,disabled)//Sets or returns whether the dropdown list is disabled, or not 	Yes
DECLARE_STATIC_ATTRNAME(form,form)//Returns a reference to the form that contains the dropdown list 	Yes
DECLARE_STATIC_ATTRNAME(length,length)//Returns the number of options in a dropdown list 	Yes
DECLARE_STATIC_ATTRNAME(multiple,multiple)//Sets or returns whether more than one item can be selected from the dropdown list 	Yes
DECLARE_STATIC_ATTRNAME(selectedIndex,selectedIndex)//Sets or returns the index of the selected option in a dropdown list 	Yes
DECLARE_STATIC_ATTRNAME(size,size)//Sets or returns the number of visible options in a dropdown list 	Yes


DECLARE_STATIC_ATTRNAME(name,name)//Sets or returns the name of a dropdown list 	Yes
DECLARE_STATIC_ATTRNAME(type,type)//Returns which type of form element a dropdown list is 	Yes
};
#endif
