#ifndef  V8_LINK_H
#define  V8_LINK_H



#include "htmlElement.h"


class Link;

typedef Link* LinkPtr;


class Link:public HTMLElement{
public:
   Link(xmlNodePtr node);
   virtual ~Link();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);
public:
DECLARE_STATIC_ATTRNAME(charset,charset)//Sets or returns the character encoding of a linked document 	Yes
DECLARE_STATIC_ATTRNAME(href,href)//Sets or returns the URL of a linked document 	Yes
DECLARE_STATIC_ATTRNAME(hreflang,hreflang)//Sets or returns the language code of the linked document 	Yes
DECLARE_STATIC_ATTRNAME(media,media)//Sets or returns the media type for the link element 	Yes
DECLARE_STATIC_ATTRNAME(rel,rel)//Sets or returns the relationship between the current document and the linked document 	Yes
DECLARE_STATIC_ATTRNAME(rev,rev)//Sets or returns the reverse relationship from the linked document to the current document 	Yes
DECLARE_STATIC_ATTRNAME(type,type)//Sets or returns the content type of the linked document 	Yes
};
#endif
