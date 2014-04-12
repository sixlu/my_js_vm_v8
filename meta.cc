#include "meta.h"

INIT_STATIC_ATTRNAME(Meta,content,content)
INIT_STATIC_ATTRNAME(Meta,httpEquiv,httpEquiv)
INIT_STATIC_ATTRNAME(Meta,name,name)
INIT_STATIC_ATTRNAME(Meta,scheme,scheme)


Meta::Meta(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Meta,content)]=XML_ATTRNAME(Meta,content);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Meta,httpEquiv)]=XML_ATTRNAME(Meta,httpEquiv);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Meta,name)]=XML_ATTRNAME(Meta,name);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Meta,scheme)]=XML_ATTRNAME(Meta,scheme);

   embed();
}


Meta::~Meta(){


}


v8::Handle<v8::ObjectTemplate> Meta::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);

    }
    //register property accessor

    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Meta,content).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Meta,httpEquiv).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Meta,name).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Meta,scheme).c_str()), Node::GetAttribute, Node::SetAttribute);

    return _templ;

}



