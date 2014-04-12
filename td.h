#ifndef  V8_TD_H
#define  V8_TD_H



#include "htmlElement.h"





class Td:public HTMLElement{

public:
   Td(xmlNodePtr node);
   virtual ~Td();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);
public:
DECLARE_STATIC_ATTRNAME(abbr,abbr)//Sets or returns an abbreviated version of the content in a data cell 	Yes
DECLARE_STATIC_ATTRNAME(align,align)//Deprecated. Sets or returns the horizontal alignment of the content in a data cell. Use style.textAlign instead 	D
DECLARE_STATIC_ATTRNAME(axis,axis)//Sets or returns a comma-separated list of related data cells 	Yes
DECLARE_STATIC_ATTRNAME(background,background)//Deprecated. Sets or returns the background image of a data cell. Use style.background instead 	D
DECLARE_STATIC_ATTRNAME(bgColor,bgColor)//Deprecated. Sets or returns the background color of a table. Use style.backgroundColor instead 	D
DECLARE_STATIC_ATTRNAME(cellIndex,cellIndex)//Returns the position of a cell in the cells collection of a table row 	Yes
DECLARE_STATIC_ATTRNAME(ch,ch)//Sets or returns an alignment character for a data cell 	Yes
DECLARE_STATIC_ATTRNAME(chOff,chOff)//Sets or returns the horizontal offset of the ch property 	Yes
DECLARE_STATIC_ATTRNAME(colSpan,colSpan)//Sets or returns the number of columns a cell should span 	Yes
DECLARE_STATIC_ATTRNAME(headers,headers)//Sets or returns a list of header cell ids for the current data cell 	Yes
DECLARE_STATIC_ATTRNAME(height,height)//Deprecated. Sets or returns the height of a data cell. Use style.height instead 	D
DECLARE_STATIC_ATTRNAME(noWrap,noWrap)//Deprecated. Sets or returns whether the content in a cell can be wrapped. Use style.whiteSpace instead 	D
DECLARE_STATIC_ATTRNAME(rowSpan,rowSpan)//Sets or returns the number of rows a cell should span 	Yes
DECLARE_STATIC_ATTRNAME(vAlign,vAlign)//Sets or returns the vertical alignment of the content within a cell 	Yes
DECLARE_STATIC_ATTRNAME(width,width)//Deprecated. Sets or returns the width of a data cell. Use style.width instead 	D
};
#endif
