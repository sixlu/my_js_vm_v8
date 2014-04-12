#ifndef V8_HTMLElEMENT_H
#define V8_HTMLElEMENT_H

#include "common.h"
/*
#include <libxml/HTMLparser.h>
#include <libxml/HTMLtree.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <string>
*/
#include "element.h"

//using namespace v8;
//using namespace std;




class HTMLElement : public Element{


public:
  HTMLElement(xmlNodePtr node);
  HTMLElement(const char* node_name);
  virtual ~HTMLElement();
public:
   v8::Handle<v8::ObjectTemplate> embed();

public:
//  static Handle<Value> GetAttribute(Local<String> property,const AccessorInfo &info);
//  static void SetAttribute(Local<String> property, Local<Value> value,const AccessorInfo& info); 
   static Handle<Value> GetAttribute(Local<String> property,const AccessorInfo &info);
   static void SetAttribute(Local<String> property, Local<Value> value,const AccessorInfo& info);
 
public:

  //accessKey 	Sets or returns an accesskey for an element 	Yes
  DECLARE_STATIC_ATTRNAME(accessKey,accessKey)
  //className 	Sets or returns the class attribute of an element 	Yes
  DECLARE_STATIC_ATTRNAME(className,class)
  //clientHeight 	Returns the viewable height of the content on a page (not including borders, margins, or scrollbars) 	No
  DECLARE_STATIC_ATTRNAME(clientHeight,clientHeight)
  //clientWidth 	Returns the viewable width of the content on a page (not including borders, margins, or scrollbars) 	No
  DECLARE_STATIC_ATTRNAME(clientWidth,clientWidth)
  //dir 	Sets or returns the text direction of an element 	Yes
  DECLARE_STATIC_ATTRNAME(dir,dir)
  //id 	Sets or returns the id of an element 	Yes
  DECLARE_STATIC_ATTRNAME(id,id)
  //innerHTML 	Sets or returns the HTML contents (+text) of an element 	Yes
  DECLARE_STATIC_ATTRNAME(innerHTML,innerHTML)
  //lang 	Sets or returns the language code for an element 	Yes
  DECLARE_STATIC_ATTRNAME(lang,lang)
  //offsetHeight 	Returns the height of an element, including borders and padding if any, but not margins 	No
  DECLARE_STATIC_ATTRNAME(offsetHeight,offsetHeight)
  //offsetLeft 	Returns the horizontal offset position of the current element relative to its offset container 	No
  DECLARE_STATIC_ATTRNAME(offsetLeft,offsetLeft)
  //offsetParent 	Returns the offset container of an element 	No
  DECLARE_STATIC_ATTRNAME(offsetParent,offsetParent)
  //offsetTop 	Returns the vertical offset position of the current element relative to its offset container 	No
  DECLARE_STATIC_ATTRNAME(offsetTop,offsetTop)
  //offsetWidth 	Returns the width of an element, including borders and padding if any, but not margins 	No
  DECLARE_STATIC_ATTRNAME(offsetWidth,offsetWidth)
  //scrollHeight 	Returns the entire height of an element (including areas hidden with scrollbars) 	No
  DECLARE_STATIC_ATTRNAME(scrollHeight,scrollHeight)
  //scrollLeft 	Returns the distance between the actual left edge of an element and its left edge currently in view 	No
  DECLARE_STATIC_ATTRNAME(scrollLeft,scrollLeft)
  //scrollTop 	Returns the distance between the actual top edge of an element and its top edge currently in view 	No
  DECLARE_STATIC_ATTRNAME(scrollTop,scrollTop)
  //scrollWidth 	Returns the entire width of an element (including areas hidden with scrollbars) 	No
  DECLARE_STATIC_ATTRNAME(scrollWidth,scrollWidth)
  //style 	Sets or returns the style attribute of an element 	Yes
  DECLARE_STATIC_ATTRNAME(style,style)
  //tabIndex 	Sets or returns the tab order of an element 	Yes
  DECLARE_STATIC_ATTRNAME(tabIndex,tabIndex)
  //title 	Sets or returns the title attribute of an element 	Yes
  DECLARE_STATIC_ATTRNAME(title,title)



};


typedef HTMLElement* HTMLElementPtr; 

#endif
