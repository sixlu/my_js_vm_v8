#include "select.h"

INIT_STATIC_ATTRNAME(Select,disabled,disabled)
INIT_STATIC_ATTRNAME(Select,form,form)
INIT_STATIC_ATTRNAME(Select,length,length)
INIT_STATIC_ATTRNAME(Select,multiple,multiple)
INIT_STATIC_ATTRNAME(Select,selectedIndex,selectedIndex)
INIT_STATIC_ATTRNAME(Select,size,size)


INIT_STATIC_ATTRNAME(Select,name,name)
INIT_STATIC_ATTRNAME(Select,type,type)

Select::Select(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Select,disabled)]=XML_ATTRNAME(Select,disabled);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Select,form)]=XML_ATTRNAME(Select,form);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Select,length)]=XML_ATTRNAME(Select,length);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Select,multiple)]=XML_ATTRNAME(Select,multiple);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Select,selectedIndex)]=XML_ATTRNAME(Select,selectedIndex);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Select,size)]=XML_ATTRNAME(Select,size);


javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Select,name)]=XML_ATTRNAME(Select,name);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Select,type)]=XML_ATTRNAME(Select,type);


    embed();
}


Select::~Select(){


}


v8::Handle<v8::ObjectTemplate> Select::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Select,disabled).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Select,form).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Select,length).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Select,multiple).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Select,selectedIndex).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Select,size).c_str()), Node::GetAttribute, Node::SetAttribute);


    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Select,name).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Select,type).c_str()), Node::GetAttribute, Node::SetAttribute);




    
    return _templ;


}



