#ifndef  V8_OPTION_H
#define  V8_OPTION_H



#include "htmlElement.h"
#include "form.h"


class Option;

typedef Option* OptionPtr;


class Option:public HTMLElement{

public:
   Option(xmlNodePtr node,FormPtr form,bool isdefaultSelected);
   virtual ~Option();
public:
   v8::Handle<v8::ObjectTemplate> embed();

public:
   bool isDefaultSelected();
   void setDefaultSelected();
   FormPtr getForm();

private:
   bool _isdefaultSelected;
   FormPtr _form;

public:

   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);
public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(defaultSelected)//Returns the default value of the selected attribute 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(form)//Returns a reference to the form that contains the option 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(text)//Sets or returns the text of an option element 	Yes


DECLARE_STATIC_ATTRNAME(disabled,disabled)//Sets or returns whether an option is disabled, or not 	Yes
DECLARE_STATIC_ATTRNAME(index,index)//Sets or returns the index position of an option in a dropdown list 	Yes
DECLARE_STATIC_ATTRNAME(selected,selected)//Sets or returns the value of the selected attribute 	Yes
DECLARE_STATIC_ATTRNAME(value,value)//Sets or returns the value to be sent to the server 	Yes
};
#endif
