#include "anchor.h"
#include "config.h"
#include "window.h"


INIT_STATIC_ATTRNAME(Anchor,charset,charset)
INIT_STATIC_ATTRNAME(Anchor,href,href)
INIT_STATIC_ATTRNAME(Anchor,hreflang,hreflang)
INIT_STATIC_ATTRNAME(Anchor,name,name)
INIT_STATIC_ATTRNAME(Anchor,rel,rel)
INIT_STATIC_ATTRNAME(Anchor,rev,rev)
INIT_STATIC_ATTRNAME(Anchor,target,target)
INIT_STATIC_ATTRNAME(Anchor,type,type)

Anchor::Anchor(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Anchor,charset)]=XML_ATTRNAME(Anchor,charset);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Anchor,href)]=XML_ATTRNAME(Anchor,href);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Anchor,hreflang)]=XML_ATTRNAME(Anchor,hreflang);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Anchor,name)]=XML_ATTRNAME(Anchor,name);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Anchor,rel)]=XML_ATTRNAME(Anchor,rel);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Anchor,rev)]=XML_ATTRNAME(Anchor,rev);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Anchor,target)]=XML_ATTRNAME(Anchor,target);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Anchor,type)]=XML_ATTRNAME(Anchor,type);

   embed();
}


Anchor::~Anchor(){


}


v8::Handle<v8::ObjectTemplate> Anchor::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register property accessor
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Anchor,charset).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Anchor,href).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Anchor,hreflang).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Anchor,name).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Anchor,rel).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Anchor,rev).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Anchor,target).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Anchor,type).c_str()), Node::GetAttribute, Node::SetAttribute);


    
    return _templ;

}

void Anchor::defaultAction(){
    NameNodeMapPtr namenodemap =  this->getAttributes();
    string attr_name = "href";
    AttrPtr href_attr =(AttrPtr)namenodemap->getNameItem(attr_name);

    map<string,string> request_headers;    
    
    Config::fillRequestHeader(request_headers);

    string url = href_attr->value;
    printf("%s\n",url.c_str());

    map<string,string> response_headers;
    HttpUtil::BODY *response_body = HttpUtil::newBody();

    HttpUtil::httpGet(request_headers,url,&response_headers,response_body);

    //printf("%s",response_body->buf);
   
    string response_body_str = response_body->buf;
    
    printf("%s",response_body_str.c_str());

    Window * window = new Window(request_headers,url,response_headers,response_body_str);
   
    window->render();
}



