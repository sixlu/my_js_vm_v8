#include "base.h"

INIT_STATIC_ATTRNAME(Base,href,href)
INIT_STATIC_ATTRNAME(Base,target,target)


Base::Base():HTMLElement("Base"){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Base,href)]=XML_ATTRNAME(Base,href);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Base,target)]=XML_ATTRNAME(Base,target);


embed();

}

Base::~Base(){

}


v8::Handle<v8::ObjectTemplate> Base::embed(){
    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);

    }
    //register property accessor
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Base,href).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Base,target).c_str()), Node::GetAttribute, Node::SetAttribute);

    
    return _templ;

}

/*
Handle<Value> Base::GetProperty(Local<String> property,const AccessorInfo &info){


}


void Base::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){


}

*/
