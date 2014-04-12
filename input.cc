#include "input.h"

INIT_STATIC_ATTRNAME(Input,disabled,disabled)
INIT_STATIC_ATTRNAME(Input,form,form)
INIT_STATIC_ATTRNAME(Input,name,name)
INIT_STATIC_ATTRNAME(Input,type,type)
INIT_STATIC_ATTRNAME(Input,value,value)
INIT_STATIC_ATTRNAME(Input,checked,checked)
INIT_STATIC_ATTRNAME(Input,defaultChecked,defaultChecked)
INIT_STATIC_ATTRNAME(Input,accept,accept)
INIT_STATIC_ATTRNAME(Input,defaultValue,defaultValue)
INIT_STATIC_ATTRNAME(Input,maxLength,maxLength)
INIT_STATIC_ATTRNAME(Input,readOnly,readOnly)
INIT_STATIC_ATTRNAME(Input,size,size)

Input::Input(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Input,disabled)]=XML_ATTRNAME(Input,disabled);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Input,form)]=XML_ATTRNAME(Input,form);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Input,name)]=XML_ATTRNAME(Input,name);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Input,type)]=XML_ATTRNAME(Input,type);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Input,value)]=XML_ATTRNAME(Input,value);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Input,checked)]=XML_ATTRNAME(Input,checked);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Input,defaultChecked)]=XML_ATTRNAME(Input,defaultChecked);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Input,accept)]=XML_ATTRNAME(Input,accept);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Input,defaultValue)]=XML_ATTRNAME(Input,defaultValue);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Input,maxLength)]=XML_ATTRNAME(Input,maxLength);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Input,readOnly)]=XML_ATTRNAME(Input,readOnly);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Input,size)]=XML_ATTRNAME(Input,size);

   embed();
}


Input::~Input(){


}


v8::Handle<v8::ObjectTemplate> Input::embed(){

    if((*_templ)==NULL){
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Input,disabled).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Input,form).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Input,name).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Input,type).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Input,value).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Input,checked).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Input,defaultChecked).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Input,accept).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Input,defaultValue).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Input,maxLength).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Input,readOnly).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Input,size).c_str()), Node::GetAttribute, Node::SetAttribute);



    
    return _templ;

}




