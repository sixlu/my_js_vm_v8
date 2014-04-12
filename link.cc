#include "link.h"

INIT_STATIC_ATTRNAME(Link,charset,charset)
INIT_STATIC_ATTRNAME(Link,href,href)
INIT_STATIC_ATTRNAME(Link,hreflang,hreflang)
INIT_STATIC_ATTRNAME(Link,media,media)
INIT_STATIC_ATTRNAME(Link,rel,rel)
INIT_STATIC_ATTRNAME(Link,rev,rev)
INIT_STATIC_ATTRNAME(Link,type,type)

Link::Link(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Link,charset)]=XML_ATTRNAME(Link,charset);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Link,href)]=XML_ATTRNAME(Link,href);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Link,hreflang)]=XML_ATTRNAME(Link,hreflang);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Link,media)]=XML_ATTRNAME(Link,media);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Link,rel)]=XML_ATTRNAME(Link,rel);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Link,rev)]=XML_ATTRNAME(Link,rev);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Link,type)]=XML_ATTRNAME(Link,type);

   embed();
}


Link::~Link(){


}


v8::Handle<v8::ObjectTemplate> Link::embed(){

    if((*_templ)==NULL){
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Link,charset).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Link,href).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Link,hreflang).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Link,media).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Link,rel).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Link,rev).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Link,type).c_str()), Node::GetAttribute, Node::SetAttribute);



    
    return _templ;

}


