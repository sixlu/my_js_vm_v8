#ifndef   V8_ANCHOR_H
#define   V8_ANCHOR_H

#include "common.h"
#include "htmlElement.h"
#include "attr.h"

class Anchor;

typedef Anchor* AnchorPtr;


class Anchor:public HTMLElement{
public:
   Anchor(xmlNodePtr node);
   virtual ~Anchor();
public:
   v8::Handle<v8::ObjectTemplate> embed();

protected:
   void defaultAction();

// static  Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
// static  void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);


DECLARE_STATIC_ATTRNAME(charset,charset)//Sets or returns the value of the charset attribute of a link 	Yes
DECLARE_STATIC_ATTRNAME(href,href)//Sets or returns the value of the href attribute of a link 	Yes
DECLARE_STATIC_ATTRNAME(hreflang,hreflang)//Sets or returns the value of the hreflang attribute of a link 	Yes
DECLARE_STATIC_ATTRNAME(name,name)//Sets or returns the value of the name attribute of a link 	Yes
DECLARE_STATIC_ATTRNAME(rel,rel)//Sets or returns the value of the rel attribute of a link 	Yes
DECLARE_STATIC_ATTRNAME(rev,rev)//Sets or returns the value of the rev attribute of a link 	Yes
DECLARE_STATIC_ATTRNAME(target,target)//Sets or returns the value of the target attribute of a link 	Yes
DECLARE_STATIC_ATTRNAME(type,type)//Sets or returns the value of the type attribute of a link 	Yes

};


#endif
