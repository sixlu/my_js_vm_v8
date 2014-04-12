#ifndef  V8_TABLE_H
#define  V8_TABLE_H



#include "htmlElement.h"





class Table:public HTMLElement{
public:
   Table(xmlNodePtr node);
   virtual ~Table();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
DECLARE_STATIC_ATTRNAME(cells,cells)//Returns a collection of all <td> or <th> elements in a table 	No
DECLARE_STATIC_ATTRNAME(rows,rows)//Returns a collection of all <tr> elements in a table 	Yes
DECLARE_STATIC_ATTRNAME(tBodies,tBodies)//Returns a collection of all <tbody> elements in a table 	Yes
DECLARE_STATIC_ATTRNAME(align,align)//Deprecated. Sets or returns the alignment of a table according to surrounding text. Use style.textAlign instead 	D
DECLARE_STATIC_ATTRNAME(background,background)//Deprecated. Sets or returns the background image of a table. Use style.background instead 	D
DECLARE_STATIC_ATTRNAME(bgColor,bgColor)//Deprecated. Sets or returns the background color of a table. Use style.backgroundColor instead 	D
DECLARE_STATIC_ATTRNAME(border,border)//Deprecated. Sets or returns the width of the table border. Use style.border instead 	D
DECLARE_STATIC_ATTRNAME(caption,caption)//Returns the caption of a table 	Yes
DECLARE_STATIC_ATTRNAME(cellPadding,cellPadding)//Sets or returns the amount of space between the cell border and cell content 	Yes
DECLARE_STATIC_ATTRNAME(cellSpacing,cellSpacing)//Sets or returns the amount of space between the cells in a table 	Yes
DECLARE_STATIC_ATTRNAME(frame,frame)//Sets or returns which outer-borders (of a table) that should be displayed 	Yes
DECLARE_STATIC_ATTRNAME(height,height)//Deprecated. Sets or returns the height of a table. Use style.height instead 	D
DECLARE_STATIC_ATTRNAME(rules,rules)//Sets or returns which inner-borders (between the cells) that should be displayed in a table 	Yes
DECLARE_STATIC_ATTRNAME(summary,summary)//Sets or returns a description of the data in a table 	Yes
DECLARE_STATIC_ATTRNAME(tFoot,tFoot)//Returns a reference to the tfoot element of a table 	Yes
DECLARE_STATIC_ATTRNAME(tHead,tHead)//Returns a reference to the thead element of a table 	Yes
DECLARE_STATIC_ATTRNAME(width,width)//Deprecated. Sets or returns the width of the table. Use style.width instead 	D

public:
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(createCaption)//) 	Creates an empty caption element and adds it to the table 	Yes
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(createTFoot)//) 	Creates an empty tfoot element and adds it to the table 	Yes
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(createTHead)//) 	Creates an empty thead element and adds it to the table 	Yes
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(deleteCaption)//) 	Removes the first caption element from the table 	Yes
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(deleteRow)//) 	Removes a row from the table 	Yes
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(deleteTFoot)//) 	Removes the tfoot element from the table 	Yes
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(deleteTHead)//) 	Removes the thead element from the table 	Yes
//DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(insertRow)//) 	Creates an empty tr element and adds it to the table 	Yes
};
#endif
