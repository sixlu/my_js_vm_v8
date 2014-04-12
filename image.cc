#include "image.h"

INIT_STATIC_ATTRNAME(Image,complete,complete)


INIT_STATIC_ATTRNAME(Image,align,align)
INIT_STATIC_ATTRNAME(Image,alt,alt)
INIT_STATIC_ATTRNAME(Image,border,border)
INIT_STATIC_ATTRNAME(Image,height,height)
INIT_STATIC_ATTRNAME(Image,hspace,hspace)
INIT_STATIC_ATTRNAME(Image,longDesc,longDesc)
INIT_STATIC_ATTRNAME(Image,lowsrc,lowsrc)
INIT_STATIC_ATTRNAME(Image,name,name)
INIT_STATIC_ATTRNAME(Image,src,src)
INIT_STATIC_ATTRNAME(Image,useMap,useMap)
INIT_STATIC_ATTRNAME(Image,vspace,vspace)
INIT_STATIC_ATTRNAME(Image,width,width)

Image::Image(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Image,align)]=XML_ATTRNAME(Image,align);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Image,alt)]=XML_ATTRNAME(Image,alt);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Image,border)]=XML_ATTRNAME(Image,border);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Image,height)]=XML_ATTRNAME(Image,height);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Image,hspace)]=XML_ATTRNAME(Image,hspace);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Image,longDesc)]=XML_ATTRNAME(Image,longDesc);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Image,lowsrc)]=XML_ATTRNAME(Image,lowsrc);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Image,name)]=XML_ATTRNAME(Image,name);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Image,src)]=XML_ATTRNAME(Image,src);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Image,useMap)]=XML_ATTRNAME(Image,useMap);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Image,vspace)]=XML_ATTRNAME(Image,vspace);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Image,width)]=XML_ATTRNAME(Image,width);

    embed();

}


Image::~Image(){


}


v8::Handle<v8::ObjectTemplate> Image::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Image,align).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Image,alt).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Image,border).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Image,height).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Image,hspace).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Image,longDesc).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Image,lowsrc).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Image,name).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Image,src).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Image,useMap).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Image,vspace).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Image,width).c_str()), Node::GetAttribute, Node::SetAttribute);




       
    return _templ;


}


