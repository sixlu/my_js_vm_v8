#ifndef  V8_STYLE_H
#define  V8_STYLE_H



#include "attr.h"





class Style:public Attr{

public:
   Style(xmlAttrPtr attr);
   virtual ~Style();
public:
   v8::Handle<v8::ObjectTemplate> embed();
public:

//   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
//   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
DECLARE_STATIC_ATTRNAME(background,background)//Sets or returns all the background properties in one declaration 	Yes
DECLARE_STATIC_ATTRNAME(backgroundAttachment,backgroundAttachment)//Sets or returns whether a background-image is fixed or scrolls with the page 	Yes
DECLARE_STATIC_ATTRNAME(backgroundColor,backgroundColor)//Sets or returns the background-color of an element 	Yes
DECLARE_STATIC_ATTRNAME(backgroundImage,backgroundImage)//Sets or returns the background-image for an element 	Yes
DECLARE_STATIC_ATTRNAME(backgroundPosition,backgroundPosition)//Sets or returns the starting position of a background-image 	Yes
DECLARE_STATIC_ATTRNAME(backgroundRepeat,backgroundRepeat)//Sets or returns how to repeat (tile) a background-image 	Yes
DECLARE_STATIC_ATTRNAME(border,border)//Sets or returns border-width, border-style, and border-color in one declaration 	Yes
DECLARE_STATIC_ATTRNAME(borderBottom,borderBottom)//Sets or returns all the borderBottom* properties in one declaration 	Yes
DECLARE_STATIC_ATTRNAME(borderBottomColor,borderBottomColor)//Sets or returns the color of the bottom border 	Yes
DECLARE_STATIC_ATTRNAME(borderBottomStyle,borderBottomStyle)//Sets or returns the style of the bottom border 	Yes
DECLARE_STATIC_ATTRNAME(borderBottomWidth,borderBottomWidth)//Sets or returns the width of the bottom border 	Yes
DECLARE_STATIC_ATTRNAME(borderColor,borderColor)//Sets or returns the color of an element's border (can have up to four values) 	Yes
DECLARE_STATIC_ATTRNAME(borderLeft,borderLeft)//Sets or returns all the borderLeft* properties in one declaration 	Yes
DECLARE_STATIC_ATTRNAME(borderLeftColor,borderLeftColor)//Sets or returns the color of the left border 	Yes
DECLARE_STATIC_ATTRNAME(borderLeftStyle,borderLeftStyle)//Sets or returns the style of the left border 	Yes
DECLARE_STATIC_ATTRNAME(borderLeftWidth,borderLeftWidth)//Sets or returns the width of the left border 	Yes
DECLARE_STATIC_ATTRNAME(borderRight,borderRight)//Sets or returns all the borderRight* properties in one declaration 	Yes
DECLARE_STATIC_ATTRNAME(borderRightColor,borderRightColor)//Sets or returns the color of the right border 	Yes
DECLARE_STATIC_ATTRNAME(borderRightStyle,borderRightStyle)//Sets or returns the style of the right border 	Yes
DECLARE_STATIC_ATTRNAME(borderRightWidth,borderRightWidth)//Sets or returns the width of the right border 	Yes
DECLARE_STATIC_ATTRNAME(borderStyle,borderStyle)//Sets or returns the style of an element's border (can have up to four values) 	Yes
DECLARE_STATIC_ATTRNAME(borderTop,borderTop)//Sets or returns all the borderTop* properties in one declaration 	Yes
DECLARE_STATIC_ATTRNAME(borderTopColor,borderTopColor)//Sets or returns the color of the top border 	Yes
DECLARE_STATIC_ATTRNAME(borderTopStyle,borderTopStyle)//Sets or returns the style of the top border 	Yes
DECLARE_STATIC_ATTRNAME(borderTopWidth,borderTopWidth)//Sets or returns the width of the top border 	Yes
DECLARE_STATIC_ATTRNAME(borderWidth,borderWidth)//Sets or returns the width of an element's border (can have up to four values) 	Yes
DECLARE_STATIC_ATTRNAME(outline,outline)//Sets or returns all the outline properties in one declaration 	Yes
DECLARE_STATIC_ATTRNAME(outlineColor,outlineColor)//Sets or returns the color of the outline around a element 	Yes
DECLARE_STATIC_ATTRNAME(outlineStyle,outlineStyle)//Sets or returns the style of the outline around an element 	Yes
DECLARE_STATIC_ATTRNAME(outlineWidth,outlineWidth)//Sets or returns the width of the outline around an element 	Yes
DECLARE_STATIC_ATTRNAME(content,content)//Sets or returns the generated content before or after the element 	Yes
DECLARE_STATIC_ATTRNAME(counterIncrement,counterIncrement)//Sets or returns the list of counters and increment values 	Yes
DECLARE_STATIC_ATTRNAME(counterReset,counterReset)//Sets or returns the list of counters and their initial values 	Yes
DECLARE_STATIC_ATTRNAME(listStyle,listStyle)//Sets or returns list-style-image, list-style-position, and list-style-type in one declaration 	Yes
DECLARE_STATIC_ATTRNAME(listStyleImage,listStyleImage)//Sets or returns an image as the list-item marker 	Yes
DECLARE_STATIC_ATTRNAME(listStylePosition,listStylePosition)//Sets or returns the position of the list-item marker 	Yes
DECLARE_STATIC_ATTRNAME(listStyleType,listStyleType)//Sets or returns the list-item marker type 	Yes
DECLARE_STATIC_ATTRNAME(margin,margin)//Sets or returns the margins of an element (can have up to four values) 	Yes
DECLARE_STATIC_ATTRNAME(marginBottom,marginBottom)//Sets or returns the bottom margin of an element 	Yes
DECLARE_STATIC_ATTRNAME(marginLeft,marginLeft)//Sets or returns the left margin of an element 	Yes
DECLARE_STATIC_ATTRNAME(marginRight,marginRight)//Sets or returns the right margin of an element 	Yes
DECLARE_STATIC_ATTRNAME(marginTop,marginTop)//Sets or returns the top margin of an element 	Yes
DECLARE_STATIC_ATTRNAME(padding,padding)//Sets or returns the padding of an element (can have up to four values) 	Yes
DECLARE_STATIC_ATTRNAME(paddingBottom,paddingBottom)//Sets or returns the bottom padding of an element 	Yes
DECLARE_STATIC_ATTRNAME(paddingLeft,paddingLeft)//Sets or returns the left padding of an element 	Yes
DECLARE_STATIC_ATTRNAME(paddingRight,paddingRight)//Sets or returns the right padding of an element 	Yes
DECLARE_STATIC_ATTRNAME(paddingTop,paddingTop)//Sets or returns the top padding of an element 	Yes
DECLARE_STATIC_ATTRNAME(cssText,cssText)//Sets or returns the contents of a style declaration as a string 	Yes
DECLARE_STATIC_ATTRNAME(bottom,bottom)//Sets or returns the bottom position of a positioned element 	Yes
DECLARE_STATIC_ATTRNAME(clear,clear)//Sets or returns the position of the element relative to floating objects 	Yes
DECLARE_STATIC_ATTRNAME(clip,clip)//Sets or returns which part of a positioned element is visible 	Yes
DECLARE_STATIC_ATTRNAME(cssFloat,cssFloat)//Sets or returns the horizontal alignment of an object 	Yes
DECLARE_STATIC_ATTRNAME(cursor,cursor)//Sets or returns the type of cursor to display for the mouse pointer 	Yes
DECLARE_STATIC_ATTRNAME(display,display)//Sets or returns an element's display type 	Yes
DECLARE_STATIC_ATTRNAME(height,height)//Sets or returns the height of an element 	Yes
DECLARE_STATIC_ATTRNAME(left,left)//Sets or returns the left position of a positioned element 	Yes
DECLARE_STATIC_ATTRNAME(maxHeight,maxHeight)//Sets or returns the maximum height of an element 	Yes
DECLARE_STATIC_ATTRNAME(maxWidth,maxWidth)//Sets or returns the maximum width of an element 	Yes
DECLARE_STATIC_ATTRNAME(minHeight,minHeight)//Sets or returns the minimum height of an element 	Yes
DECLARE_STATIC_ATTRNAME(minWidth,minWidth)//Sets or returns the minimum width of an element 	Yes
DECLARE_STATIC_ATTRNAME(overflow,overflow)//Sets or returns what to do with content that renders outside the element box 	Yes
DECLARE_STATIC_ATTRNAME(position,position)//Sets or returns the type of positioning method used for an element (static, relative, absolute or fixed) 	Yes
DECLARE_STATIC_ATTRNAME(right,right)//Sets or returns the right position of a positioned element 	Yes
DECLARE_STATIC_ATTRNAME(top,top)//Sets or returns the top position of a positioned element 	Yes
DECLARE_STATIC_ATTRNAME(verticalAlign,verticalAlign)//Sets or returns the vertical alignment of the content in an element 	Yes
DECLARE_STATIC_ATTRNAME(visibility,visibility)//Sets or returns whether an element should be visible 	Yes
DECLARE_STATIC_ATTRNAME(width,width)//Sets or returns the width of an element 	Yes
DECLARE_STATIC_ATTRNAME(zIndex,zIndex)//Sets or returns the stack order of a positioned element 	Yes
DECLARE_STATIC_ATTRNAME(orphans,orphans)//Sets or returns the minimum number of lines for an element that must be visible at the bottom of a page 	Yes
DECLARE_STATIC_ATTRNAME(pageBreakAfter,pageBreakAfter)//Sets or returns the page-break behavior after an element 	Yes
DECLARE_STATIC_ATTRNAME(pageBreakBefore,pageBreakBefore)//Sets or returns the page-break behavior before an element 	Yes
DECLARE_STATIC_ATTRNAME(pageBreakInside,pageBreakInside)//Sets or returns the page-break behavior inside an element 	Yes
DECLARE_STATIC_ATTRNAME(widows,widows)//Sets or returns the minimum number of lines for an element that must be visible at the top of a page 	Yes
DECLARE_STATIC_ATTRNAME(borderCollapse,borderCollapse)//Sets or returns whether the table border should be collapsed into a single border, or not 	Yes
DECLARE_STATIC_ATTRNAME(borderSpacing,borderSpacing)//Sets or returns the space between cells in a table 	Yes
DECLARE_STATIC_ATTRNAME(captionSide,captionSide)//Sets or returns the position of the table caption 	Yes
DECLARE_STATIC_ATTRNAME(emptyCells,emptyCells)//Sets or returns whether to show the border and background of empty cells, or not 	Yes
DECLARE_STATIC_ATTRNAME(tableLayout,tableLayout)//Sets or returns the way to lay out table cells, rows, and columns 	Yes
DECLARE_STATIC_ATTRNAME(color,color)//Sets or returns the color of the text 	Yes
DECLARE_STATIC_ATTRNAME(direction,direction)//Sets or returns the text direction 	Yes
DECLARE_STATIC_ATTRNAME(font,font)//Sets or returns font-style, font-variant, font-weight, font-size, line-height, and font-family in one declaration 	Yes
DECLARE_STATIC_ATTRNAME(fontFamily,fontFamily)//Sets or returns the font face for text 	Yes
DECLARE_STATIC_ATTRNAME(fontSize,fontSize)//Sets or returns the font size of the text 	Yes
DECLARE_STATIC_ATTRNAME(fontSizeAdjust,fontSizeAdjust)//Sets or returns the font aspect value 	Yes
DECLARE_STATIC_ATTRNAME(fontStyle,fontStyle)//Sets or returns whether the style of the font is normal, italic or oblique 	Yes
DECLARE_STATIC_ATTRNAME(fontVariant,fontVariant)//Sets or returns whether the font should be displayed in small capital letters 	Yes
DECLARE_STATIC_ATTRNAME(fontWeight,fontWeight)//Sets or returns the boldness of the font 	Yes
DECLARE_STATIC_ATTRNAME(letterSpacing,letterSpacing)//Sets or returns the space between characters in a text 	Yes
DECLARE_STATIC_ATTRNAME(lineHeight,lineHeight)//Sets or returns the distance between lines in a text 	Yes
DECLARE_STATIC_ATTRNAME(quotes,quotes)//Sets or returns the type of quotation marks for embedded quotations 	Yes
DECLARE_STATIC_ATTRNAME(textAlign,textAlign)//Sets or returns the horizontal alignment of text 	Yes
DECLARE_STATIC_ATTRNAME(textDecoration,textDecoration)//Sets or returns the decoration of a text 	Yes
DECLARE_STATIC_ATTRNAME(textIndent,textIndent)//Sets or returns the indentation of the first line of text 	Yes
DECLARE_STATIC_ATTRNAME(textShadow,textShadow)//Sets or returns the shadow effect of a text 	Yes
DECLARE_STATIC_ATTRNAME(textTransform,textTransform)//Sets or returns the case of a text 	Yes
DECLARE_STATIC_ATTRNAME(unicodeBidi,unicodeBidi)//Sets or returns whether the text should be overridden to support multiple languages in the same document 	Yes
DECLARE_STATIC_ATTRNAME(whiteSpace,whiteSpace)//Sets or returns how to handle tabs, line breaks and whitespace in a text 	Yes
DECLARE_STATIC_ATTRNAME(wordSpacing,wordSpacing)//Sets or returns the spacing between words in a text 	Yes

};
#endif
