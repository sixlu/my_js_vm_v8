#include "td.h"

INIT_STATIC_ATTRNAME(Td,abbr,abbr)
INIT_STATIC_ATTRNAME(Td,align,align)
INIT_STATIC_ATTRNAME(Td,axis,axis)
INIT_STATIC_ATTRNAME(Td,background,background)
INIT_STATIC_ATTRNAME(Td,bgColor,bgColor)
INIT_STATIC_ATTRNAME(Td,cellIndex,cellIndex)
INIT_STATIC_ATTRNAME(Td,ch,ch)
INIT_STATIC_ATTRNAME(Td,chOff,chOff)
INIT_STATIC_ATTRNAME(Td,colSpan,colSpan)
INIT_STATIC_ATTRNAME(Td,headers,headers)
INIT_STATIC_ATTRNAME(Td,height,height)
INIT_STATIC_ATTRNAME(Td,noWrap,noWrap)
INIT_STATIC_ATTRNAME(Td,rowSpan,rowSpan)
INIT_STATIC_ATTRNAME(Td,vAlign,vAlign)
INIT_STATIC_ATTRNAME(Td,width,width)


Td::Td(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,abbr)]=XML_ATTRNAME(Td,abbr);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,align)]=XML_ATTRNAME(Td,align);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,axis)]=XML_ATTRNAME(Td,axis);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,background)]=XML_ATTRNAME(Td,background);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,bgColor)]=XML_ATTRNAME(Td,bgColor);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,cellIndex)]=XML_ATTRNAME(Td,cellIndex);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,ch)]=XML_ATTRNAME(Td,ch);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,chOff)]=XML_ATTRNAME(Td,chOff);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,colSpan)]=XML_ATTRNAME(Td,colSpan);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,headers)]=XML_ATTRNAME(Td,headers);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,height)]=XML_ATTRNAME(Td,height);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,noWrap)]=XML_ATTRNAME(Td,noWrap);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,rowSpan)]=XML_ATTRNAME(Td,rowSpan);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,vAlign)]=XML_ATTRNAME(Td,vAlign);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Td,width)]=XML_ATTRNAME(Td,width);

   embed();

}


Td::~Td(){


}


v8::Handle<v8::ObjectTemplate> Td::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register property accessor
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,abbr).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,align).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,axis).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,background).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,bgColor).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,cellIndex).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,ch).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,chOff).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,colSpan).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,headers).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,height).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,noWrap).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,rowSpan).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,vAlign).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Td,width).c_str()), Node::GetAttribute, Node::SetAttribute);



    
    return _templ;


}


