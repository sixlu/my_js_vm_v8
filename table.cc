#include "table.h"

INIT_STATIC_ATTRNAME(Table,cells,cells)
INIT_STATIC_ATTRNAME(Table,rows,rows)
INIT_STATIC_ATTRNAME(Table,tBodies,tBodies)
INIT_STATIC_ATTRNAME(Table,align,align)
INIT_STATIC_ATTRNAME(Table,background,background)
INIT_STATIC_ATTRNAME(Table,bgColor,bgColor)
INIT_STATIC_ATTRNAME(Table,border,border)
INIT_STATIC_ATTRNAME(Table,caption,caption)
INIT_STATIC_ATTRNAME(Table,cellPadding,cellPadding)
INIT_STATIC_ATTRNAME(Table,cellSpacing,cellSpacing)
INIT_STATIC_ATTRNAME(Table,frame,frame)
INIT_STATIC_ATTRNAME(Table,height,height)
INIT_STATIC_ATTRNAME(Table,rules,rules)
INIT_STATIC_ATTRNAME(Table,summary,summary)
INIT_STATIC_ATTRNAME(Table,tFoot,tFoot)
INIT_STATIC_ATTRNAME(Table,tHead,tHead)
INIT_STATIC_ATTRNAME(Table,width,width)

Table::Table(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,cells)]=XML_ATTRNAME(Table,cells);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,rows)]=XML_ATTRNAME(Table,rows);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,tBodies)]=XML_ATTRNAME(Table,tBodies);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,align)]=XML_ATTRNAME(Table,align);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,background)]=XML_ATTRNAME(Table,background);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,bgColor)]=XML_ATTRNAME(Table,bgColor);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,border)]=XML_ATTRNAME(Table,border);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,caption)]=XML_ATTRNAME(Table,caption);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,cellPadding)]=XML_ATTRNAME(Table,cellPadding);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,cellSpacing)]=XML_ATTRNAME(Table,cellSpacing);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,frame)]=XML_ATTRNAME(Table,frame);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,height)]=XML_ATTRNAME(Table,height);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,rules)]=XML_ATTRNAME(Table,rules);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,summary)]=XML_ATTRNAME(Table,summary);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,tFoot)]=XML_ATTRNAME(Table,tFoot);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,tHead)]=XML_ATTRNAME(Table,tHead);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Table,width)]=XML_ATTRNAME(Table,width);

   embed();

}


Table::~Table(){


}


v8::Handle<v8::ObjectTemplate> Table::embed(){

    if((*_templ)==NULL){
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,cells).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,rows).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,tBodies).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,align).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,background).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,bgColor).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,border).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,caption).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,cellPadding).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,cellSpacing).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,frame).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,height).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,rules).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,summary).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,tFoot).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,tHead).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Table,width).c_str()), Node::GetAttribute, Node::SetAttribute);




    
    return _templ;

}



