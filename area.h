#ifndef  V8_AREA_H
#define  V8_AREA_H

#include "htmlElement.h"





class Area :public HTMLElement{
public:
   Area(xmlNodePtr node);
   virtual ~Area();

public:
   v8::Handle<v8::ObjectTemplate> embed();

public:

   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(protocol)//Sets or returns the protocol part of the href attribute value 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(search)//Sets or returns the querystring part of the href attribute value 	Yes

DECLARE_STATIC_ATTRNAME(alt,alt)//Sets or returns the value of the alt attribute of an area 	Yes
DECLARE_STATIC_ATTRNAME(coords,coords)//Sets or returns the value of the coords attribute of an area 	Yes
DECLARE_STATIC_ATTRNAME(hash,hash)//Sets or returns the anchor part of the href attribute value 	Yes
DECLARE_STATIC_ATTRNAME(host,host)//Sets or returns the hostname:port part of the href attribute value 	Yes
DECLARE_STATIC_ATTRNAME(hostname,hostname)//Sets or returns the hostname part of the href attribute value 	Yes
DECLARE_STATIC_ATTRNAME(href,href)//Sets or returns the value of the href attribute of an area 	Yes
DECLARE_STATIC_ATTRNAME(noHref,noHref)//Sets or returns the value of the nohref attribute of an area 	Yes
DECLARE_STATIC_ATTRNAME(pathname,pathname)//Sets or returns the pathname part of the href attribute value 	Yes
DECLARE_STATIC_ATTRNAME(port,port)//Sets or returns the port part of the href attribute value 	Yes
DECLARE_STATIC_ATTRNAME(shape,shape)//Sets or returns the value of the shape attribute of an area 	Yes
DECLARE_STATIC_ATTRNAME(target,target)//Sets or returns the value of the target attribute of an area 	Yes




};


#endif
