#include "body.h"

INIT_STATIC_ATTRNAME(Body,aLink,aLink)
INIT_STATIC_ATTRNAME(Body,background,background)
INIT_STATIC_ATTRNAME(Body,bgColor,bgColor)
INIT_STATIC_ATTRNAME(Body,link,link)
INIT_STATIC_ATTRNAME(Body,text,text)
INIT_STATIC_ATTRNAME(Body,vLink,vLink)

Body::Body(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Body,aLink)]=XML_ATTRNAME(Body,aLink);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Body,background)]=XML_ATTRNAME(Body,background);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Body,bgColor)]=XML_ATTRNAME(Body,bgColor);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Body,link)]=XML_ATTRNAME(Body,link);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Body,text)]=XML_ATTRNAME(Body,text);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Body,vLink)]=XML_ATTRNAME(Body,vLink);

   embed();
}


Body::~Body(){


}


v8::Handle<v8::ObjectTemplate> Body::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register property accessor
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Body,aLink).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Body,background).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Body,bgColor).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Body,link).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Body,text).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Body,vLink).c_str()), Node::GetAttribute, Node::SetAttribute);


    
    return _templ;



}




