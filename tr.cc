#include "tr.h"

INIT_STATIC_ATTRNAME(Tr,align,align)
INIT_STATIC_ATTRNAME(Tr,bgColor,bgColor)
INIT_STATIC_ATTRNAME(Tr,ch,ch)
INIT_STATIC_ATTRNAME(Tr,chOff,chOff)
INIT_STATIC_ATTRNAME(Tr,height,height)
INIT_STATIC_ATTRNAME(Tr,rowIndex,rowIndex)
INIT_STATIC_ATTRNAME(Tr,sectionRowIndex,sectionRowIndex)
INIT_STATIC_ATTRNAME(Tr,vAlign,vAlign)

Tr::Tr(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Tr,align)]=XML_ATTRNAME(Tr,align);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Tr,bgColor)]=XML_ATTRNAME(Tr,bgColor);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Tr,ch)]=XML_ATTRNAME(Tr,ch);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Tr,chOff)]=XML_ATTRNAME(Tr,chOff);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Tr,height)]=XML_ATTRNAME(Tr,height);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Tr,rowIndex)]=XML_ATTRNAME(Tr,rowIndex);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Tr,sectionRowIndex)]=XML_ATTRNAME(Tr,sectionRowIndex);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Tr,vAlign)]=XML_ATTRNAME(Tr,vAlign);
   
   embed();

}


Tr::~Tr(){


}


v8::Handle<v8::ObjectTemplate> Tr::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register property accessor
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Tr,align).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Tr,bgColor).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Tr,ch).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Tr,chOff).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Tr,height).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Tr,rowIndex).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Tr,sectionRowIndex).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Tr,vAlign).c_str()), Node::GetAttribute, Node::SetAttribute);



    
    return _templ;

}



