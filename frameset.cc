#include "frameset.h"

INIT_STATIC_ATTRNAME(Frameset,cols,cols)
INIT_STATIC_ATTRNAME(Frameset,rows,rows)

Frameset::Frameset(xmlNodePtr node):HTMLElement(node){


javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frameset,cols)]=XML_ATTRNAME(Frameset,cols);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frameset,rows)]=XML_ATTRNAME(Frameset,rows);

   embed();
}


Frameset::~Frameset(){

}


v8::Handle<v8::ObjectTemplate> Frameset::embed(){

    if((*_templ)==NULL){ 
         _templ = ObjectTemplate::New();
         _templ->SetInternalFieldCount(1);
    }
    //register property accessor
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frameset,cols).c_str()), Node::GetAttribute, Node::SetAttribute);

    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frameset,rows).c_str()), Node::GetAttribute, Node::SetAttribute);

    
    return _templ;

}



