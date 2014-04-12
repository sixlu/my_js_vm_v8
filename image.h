#ifndef  V8_IMAGE_H
#define  V8_IMAGE_H



#include "htmlElement.h"


class Image;

typedef Image* ImagePtr;


class Image:public HTMLElement{

public:
   Image(xmlNodePtr node);
   virtual ~Image();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);
public:
DECLARE_STATIC_ATTRNAME(complete,complete)//Returns whether or not the browser is finished loading an image 	No


DECLARE_STATIC_ATTRNAME(align,align)//Sets or returns the value of the align attribute of an image 	Yes
DECLARE_STATIC_ATTRNAME(alt,alt)//Sets or returns the value of the alt attribute of an image 	Yes
DECLARE_STATIC_ATTRNAME(border,border)//Sets or returns the value of the border attribute of an image 	Yes
DECLARE_STATIC_ATTRNAME(height,height)//Sets or returns the value of the height attribute of an image 	Yes
DECLARE_STATIC_ATTRNAME(hspace,hspace)//Sets or returns the value of the hspace attribute of an image 	Yes
DECLARE_STATIC_ATTRNAME(longDesc,longDesc)//Sets or returns the value of the longdesc attribute of an image 	Yes
DECLARE_STATIC_ATTRNAME(lowsrc,lowsrc)//Sets or returns a URL to a low-resolution version of an image 	No
DECLARE_STATIC_ATTRNAME(name,name)//Sets or returns the name of an image 	Yes
DECLARE_STATIC_ATTRNAME(src,src)//Sets or returns the value of the src attribute of an image 	Yes
DECLARE_STATIC_ATTRNAME(useMap,useMap)//Sets or returns the value of the usemap attribute of an image 	Yes
DECLARE_STATIC_ATTRNAME(vspace,vspace)//Sets or returns the value of the vspace attribute of an image 	Yes
DECLARE_STATIC_ATTRNAME(width,width)//Sets or returns the value of the width attribute of an image 	Yes
};
#endif
