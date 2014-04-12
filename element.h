#ifndef   V8_ELEMENT_H
#define   V8_ELEMENT_H

#include "common.h"

#include "node.h"


class Element;

typedef Element * ElementPtr;


class Element : public Node{
public:

   Element();
   Element(xmlNodePtr node);
   virtual ~Element();
public:
   v8::Handle<v8::ObjectTemplate> embed();

public:
   const char* getTagName();


public:
  //static   v8::Handle<v8::Value> getAttribute(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> getAttributeNS(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> getAttributeNode(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> getAttributeNodeNS(const v8::Arguments& args);
  static   v8::Handle<v8::Value> getElementsByTagName(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> getElementsByTagNameNS(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> hasAttribute(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> hasAttributeNS(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> removeAttribute(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> removeAttributeNS(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> removeAttributeNode(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> setAttribute(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> setAttributeNS(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> setAttributeNode(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> setAttributeNodeNS(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> setIdAttribute(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> setIdAttributeNS(const v8::Arguments& args);
  //static   v8::Handle<v8::Value> setIdAttributeNode(const v8::Arguments& args);

public:
  static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
  static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
//DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(schemaTypeInfo)//Returns the type information of the element. 	3
//DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(tagName)//Returns the tag name of the element 	1



//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getAttribute)//) 	Returns the specified attribute value 	1
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getAttributeNS)//) 	Returns the specified attribute value, with the specified namespace. For XML DOM only 	2
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getAttributeNode)//) 	Returns the specified attribute node 	1
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getAttributeNodeNS)//) 	Returns the specified attribute node, with the specified namespace. For XML DOM only 	3
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getElementsByTagName)//) 	Returns a collection of all child elements with the specified tagname 	1
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getElementsByTagNameNS)//) 	Returns a collection of all child elements with the specified tagname and namespace. For XML DOM only 	2
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(hasAttribute)//) 	Returns true if the element has the specified attribute, otherwise it returns false 	2
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(hasAttributeNS)//) 	Returns true if the element has the specified attribute, with the specified namespace, otherwise it returns false. For XML DOM only 	2
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(removeAttribute)//) 	Removes the specified attribute 	1
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(removeAttributeNS)//) 	Removes the attribute with the specified name and namespace. For XML DOM only 	2
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(removeAttributeNode)//) 	Removes the specified attribute node, and returns the removed node 	1
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(setAttribute)//) 	Sets or changes the specified attribute, to the specified value 	1
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(setAttributeNS)//) 	Sets or changes the specified attribute, with the specified namespace, to the specified value. For XML DOM only 	2
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(setAttributeNode)//) 	Sets or changes the specified attribute node 	1
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(setAttributeNodeNS)//) 	Sets or changes the specified attribute node 	2
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(setIdAttribute)//) 		3
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(setIdAttributeNS)//) 		3
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(setIdAttributeNode)//) 		3


};

#endif

