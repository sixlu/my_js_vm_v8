#include "area.h"

INIT_STATIC_JAVASCRIPTATTRI_NAME(Area,protocol)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Area,search)

INIT_STATIC_ATTRNAME(Area,alt,alt)
INIT_STATIC_ATTRNAME(Area,coords,coords)
INIT_STATIC_ATTRNAME(Area,hash,hash)
INIT_STATIC_ATTRNAME(Area,host,host)
INIT_STATIC_ATTRNAME(Area,hostname,hostname)
INIT_STATIC_ATTRNAME(Area,href,href)
INIT_STATIC_ATTRNAME(Area,noHref,noHref)
INIT_STATIC_ATTRNAME(Area,pathname,pathname)
INIT_STATIC_ATTRNAME(Area,port,port)
INIT_STATIC_ATTRNAME(Area,shape,shape)
INIT_STATIC_ATTRNAME(Area,target,target)


Area::Area(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Area,alt)]=XML_ATTRNAME(Area,alt);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Area,coords)]=XML_ATTRNAME(Area,coords);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Area,hash)]=XML_ATTRNAME(Area,hash);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Area,host)]=XML_ATTRNAME(Area,host);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Area,hostname)]=XML_ATTRNAME(Area,hostname);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Area,href)]=XML_ATTRNAME(Area,href);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Area,noHref)]=XML_ATTRNAME(Area,noHref);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Area,pathname)]=XML_ATTRNAME(Area,pathname);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Area,port)]=XML_ATTRNAME(Area,port);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Area,shape)]=XML_ATTRNAME(Area,shape);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Area,target)]=XML_ATTRNAME(Area,target);

   embed();
}


Area::~Area(){


}


v8::Handle<v8::ObjectTemplate> Area::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);

    }
    //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,protocol).c_str()), Area::GetProperty, Area::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,search).c_str()), Area::GetProperty, Area::SetProperty);

    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,alt).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,coords).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,hash).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,host).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,hostname).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,href).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,noHref).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,pathname).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,port).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,shape).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Area,target).c_str()), Node::GetAttribute, Node::SetAttribute);




       
    return _templ;

}


Handle<Value> Area::GetProperty(Local<String> property,const AccessorInfo &info){



}


void Area::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){


}




