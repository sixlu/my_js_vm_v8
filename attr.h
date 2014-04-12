#ifndef   V8_ATTR_H
#define   V8_ATTR_H

#include "common.h"

#include "node.h"


class Attr;

typedef Attr* AttrPtr;


class Attr:public Node{

public:
   Attr(xmlAttrPtr attr);
   Attr(string &attr_name);
   virtual ~Attr(); 
public:
   bool isId;
   string name;
   NodePtr ownerElement;
   bool specified;
   string value; 
public:

   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);


public:
   v8::Handle<v8::ObjectTemplate> embed();

DECLARE_STATIC_ATTRNAME(isId,isId)//Returns true if the attribute is of type ID, otherwise it returns false 	3
DECLARE_STATIC_ATTRNAME(name,name)//Returns the name of the attribute 	1
DECLARE_STATIC_ATTRNAME(ownerElement,ownerElement)//Returns the element this attribute belongs to 	2
//DECLARE_STATIC_ATTRNAME(schemaTypeInfo,schemaTypeInfo)//Returns the type information of the attribute 	3
DECLARE_STATIC_ATTRNAME(specified,specified)//Returns true if the attribute has been specified, otherwise it returns false 	1
DECLARE_STATIC_ATTRNAME(value,value)//Sets or returns the value of the attribute
};

#endif
