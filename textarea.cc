#include "textarea.h"

INIT_STATIC_ATTRNAME(Textarea,cols,cols)
INIT_STATIC_ATTRNAME(Textarea,defaultValue,defaultValue)
INIT_STATIC_ATTRNAME(Textarea,disabled,disabled)
INIT_STATIC_ATTRNAME(Textarea,form,form)
INIT_STATIC_ATTRNAME(Textarea,name,name)
INIT_STATIC_ATTRNAME(Textarea,readOnly,readOnly)
INIT_STATIC_ATTRNAME(Textarea,rows,rows)
INIT_STATIC_ATTRNAME(Textarea,type,type)
INIT_STATIC_ATTRNAME(Textarea,value,value)

Textarea::Textarea(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Textarea,cols)]=XML_ATTRNAME(Textarea,cols);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Textarea,defaultValue)]=XML_ATTRNAME(Textarea,defaultValue);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Textarea,disabled)]=XML_ATTRNAME(Textarea,disabled);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Textarea,form)]=XML_ATTRNAME(Textarea,form);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Textarea,name)]=XML_ATTRNAME(Textarea,name);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Textarea,readOnly)]=XML_ATTRNAME(Textarea,readOnly);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Textarea,rows)]=XML_ATTRNAME(Textarea,rows);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Textarea,type)]=XML_ATTRNAME(Textarea,type);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Textarea,value)]=XML_ATTRNAME(Textarea,value);


   embed();
}


Textarea::~Textarea(){


}


v8::Handle<v8::ObjectTemplate> Textarea::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Textarea,cols).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Textarea,defaultValue).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Textarea,disabled).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Textarea,form).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Textarea,name).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Textarea,readOnly).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Textarea,rows).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Textarea,type).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Textarea,value).c_str()), Node::GetAttribute, Node::SetAttribute);




    
    return _templ;

}



