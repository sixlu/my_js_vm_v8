#include "form.h"

INIT_STATIC_ATTRNAME(Form,acceptCharset,acceptCharset)
INIT_STATIC_ATTRNAME(Form,action,action)
INIT_STATIC_ATTRNAME(Form,enctype,enctype)
INIT_STATIC_ATTRNAME(Form,length,length)
INIT_STATIC_ATTRNAME(Form,method,method)
INIT_STATIC_ATTRNAME(Form,name,name)
INIT_STATIC_ATTRNAME(Form,target,target)

Form::Form(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Form,acceptCharset)]=XML_ATTRNAME(Form,acceptCharset);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Form,action)]=XML_ATTRNAME(Form,action);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Form,enctype)]=XML_ATTRNAME(Form,enctype);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Form,length)]=XML_ATTRNAME(Form,length);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Form,method)]=XML_ATTRNAME(Form,method);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Form,name)]=XML_ATTRNAME(Form,name);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Form,target)]=XML_ATTRNAME(Form,target);

  embed();
}


Form::~Form(){


}


v8::Handle<v8::ObjectTemplate> Form::embed(){


    if((*_templ)==NULL){
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Form,acceptCharset).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Form,action).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Form,enctype).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Form,length).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Form,method).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Form,name).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Form,target).c_str()), Node::GetAttribute, Node::SetAttribute);




    
    return _templ;

}




