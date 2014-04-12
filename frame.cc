#include "frame.h"

INIT_STATIC_ATTRNAME(Frame,align,align)
INIT_STATIC_ATTRNAME(Frame,contentDocument,contentDocument)
INIT_STATIC_ATTRNAME(Frame,contentWindow,contentWindow)
INIT_STATIC_ATTRNAME(Frame,frameBorder,frameBorder)
INIT_STATIC_ATTRNAME(Frame,height,height)
INIT_STATIC_ATTRNAME(Frame,longDesc,longDesc)
INIT_STATIC_ATTRNAME(Frame,marginHeight,marginHeight)
INIT_STATIC_ATTRNAME(Frame,marginWidth,marginWidth)
INIT_STATIC_ATTRNAME(Frame,name,name)
INIT_STATIC_ATTRNAME(Frame,noResize,noResize)
INIT_STATIC_ATTRNAME(Frame,scrolling,scrolling)
INIT_STATIC_ATTRNAME(Frame,src,src)
INIT_STATIC_ATTRNAME(Frame,width,width)

Frame::Frame(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,align)]=XML_ATTRNAME(Frame,align);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,contentDocument)]=XML_ATTRNAME(Frame,contentDocument);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,contentWindow)]=XML_ATTRNAME(Frame,contentWindow);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,frameBorder)]=XML_ATTRNAME(Frame,frameBorder);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,height)]=XML_ATTRNAME(Frame,height);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,longDesc)]=XML_ATTRNAME(Frame,longDesc);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,marginHeight)]=XML_ATTRNAME(Frame,marginHeight);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,marginWidth)]=XML_ATTRNAME(Frame,marginWidth);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,name)]=XML_ATTRNAME(Frame,name);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,noResize)]=XML_ATTRNAME(Frame,noResize);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,scrolling)]=XML_ATTRNAME(Frame,scrolling);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,src)]=XML_ATTRNAME(Frame,src);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Frame,width)]=XML_ATTRNAME(Frame,width);

   embed();
}


Frame::~Frame(){


}


v8::Handle<v8::ObjectTemplate> Frame::embed(){

    if((*_templ)==NULL){
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,align).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,contentDocument).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,contentWindow).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,frameBorder).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,height).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,longDesc).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,marginHeight).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,marginWidth).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,name).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,noResize).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,scrolling).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,src).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Frame,width).c_str()), Node::GetAttribute, Node::SetAttribute);




    
    return _templ;


}



