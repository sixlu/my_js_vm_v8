#ifndef  V8_OBJECT_H
#define  V8_OBJECT_H



#include "htmlElement.h"





class HtmlObject:public HTMLElement{
public:
   HtmlObject(xmlNodePtr node);
   virtual ~HtmlObject();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);
public:
DECLARE_STATIC_ATTRNAME(align,align)//Sets or returns the alignment of the object according to the surrounding text 	Yes
DECLARE_STATIC_ATTRNAME(archive,archive)//Sets or returns a string that can be used to implement your own archive functionality for the object 	Yes
DECLARE_STATIC_ATTRNAME(border,border)//Sets or returns the border around the object 	Yes
DECLARE_STATIC_ATTRNAME(code,code)//Sets or returns the URL of the file that contains the compiled Java class 	Yes
DECLARE_STATIC_ATTRNAME(codeBase,codeBase)//Sets or returns the URL of the component 	Yes
DECLARE_STATIC_ATTRNAME(codeType,codeType)//  	Yes
DECLARE_STATIC_ATTRNAME(data,data)//  	Yes
DECLARE_STATIC_ATTRNAME(declare,declare)//  	Yes
DECLARE_STATIC_ATTRNAME(form,form)//Returns a reference to the object's parent form 	Yes
DECLARE_STATIC_ATTRNAME(height,height)//Sets or returns the height of the object 	Yes
DECLARE_STATIC_ATTRNAME(hspace,hspace)//Sets or returns the horizontal margin of the object 	Yes
DECLARE_STATIC_ATTRNAME(name,name)//Sets or returns the name of the object 	Yes
DECLARE_STATIC_ATTRNAME(standby,standby)//Sets or returns a message when loading the object 	Yes
DECLARE_STATIC_ATTRNAME(type,type)//Sets or returns the content type for data downloaded via the data attribute 	Yes
DECLARE_STATIC_ATTRNAME(useMap,useMap)//  	Yes
DECLARE_STATIC_ATTRNAME(vspace,vspace)//Sets or returns the vertical margin of the object 	Yes
DECLARE_STATIC_ATTRNAME(width,width)//Sets or returns the width of the object 	Yes
};
#endif
