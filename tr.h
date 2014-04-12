#ifndef  V8_TR_H
#define  V8_TR_H



#include "htmlElement.h"





class Tr:public HTMLElement{
public:
   Tr(xmlNodePtr node);
   virtual ~Tr();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);
public:
DECLARE_STATIC_ATTRNAME(align,align)//Deprecated. Sets or returns the horizontal alignment of the content within a table row. Use style.textAlign instead 	D
DECLARE_STATIC_ATTRNAME(bgColor,bgColor)//Deprecated. Sets or returns the background color of a table row. Use style.backgroundColor instead 	D
DECLARE_STATIC_ATTRNAME(ch,ch)//Sets or returns an alignment character for cells in a table row 	Yes
DECLARE_STATIC_ATTRNAME(chOff,chOff)//Sets or returns the horizontal offset of the ch property 	Yes
DECLARE_STATIC_ATTRNAME(height,height)//Deprecated. Sets or returns the height of a table row. Use style.height instead 	D
DECLARE_STATIC_ATTRNAME(rowIndex,rowIndex)//Returns the position of a row in the rows collection of a table 	Yes
DECLARE_STATIC_ATTRNAME(sectionRowIndex,sectionRowIndex)//Returns the position of a row in the rows collection of a tbody, thead, or tfoot 	Yes
DECLARE_STATIC_ATTRNAME(vAlign,vAlign)//Sets or returns the vertical alignment of the content within a table row 	Yes


public:
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(deleteCell)//) 	Deletes a cell from the current table row 	Yes
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(insertCell)//) 	Inserts a cell into the current table row 	Yes
};
#endif
