#include "object.h"

INIT_STATIC_ATTRNAME(HtmlObject,align,align)
INIT_STATIC_ATTRNAME(HtmlObject,archive,archive)
INIT_STATIC_ATTRNAME(HtmlObject,border,border)
INIT_STATIC_ATTRNAME(HtmlObject,code,code)
INIT_STATIC_ATTRNAME(HtmlObject,codeBase,codeBase)
INIT_STATIC_ATTRNAME(HtmlObject,codeType,codeType)
INIT_STATIC_ATTRNAME(HtmlObject,data,data)
INIT_STATIC_ATTRNAME(HtmlObject,declare,declare)
INIT_STATIC_ATTRNAME(HtmlObject,form,form)
INIT_STATIC_ATTRNAME(HtmlObject,height,height)
INIT_STATIC_ATTRNAME(HtmlObject,hspace,hspace)
INIT_STATIC_ATTRNAME(HtmlObject,name,name)
INIT_STATIC_ATTRNAME(HtmlObject,standby,standby)
INIT_STATIC_ATTRNAME(HtmlObject,type,type)
INIT_STATIC_ATTRNAME(HtmlObject,useMap,useMap)
INIT_STATIC_ATTRNAME(HtmlObject,vspace,vspace)
INIT_STATIC_ATTRNAME(HtmlObject,width,width)


HtmlObject::HtmlObject(xmlNodePtr node):HTMLElement(node){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,align)]=XML_ATTRNAME(HtmlObject,align);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,archive)]=XML_ATTRNAME(HtmlObject,archive);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,border)]=XML_ATTRNAME(HtmlObject,border);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,code)]=XML_ATTRNAME(HtmlObject,code);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,codeBase)]=XML_ATTRNAME(HtmlObject,codeBase);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,codeType)]=XML_ATTRNAME(HtmlObject,codeType);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,data)]=XML_ATTRNAME(HtmlObject,data);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,declare)]=XML_ATTRNAME(HtmlObject,declare);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,form)]=XML_ATTRNAME(HtmlObject,form);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,height)]=XML_ATTRNAME(HtmlObject,height);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,hspace)]=XML_ATTRNAME(HtmlObject,hspace);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,name)]=XML_ATTRNAME(HtmlObject,name);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,standby)]=XML_ATTRNAME(HtmlObject,standby);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,type)]=XML_ATTRNAME(HtmlObject,type);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,useMap)]=XML_ATTRNAME(HtmlObject,useMap);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,vspace)]=XML_ATTRNAME(HtmlObject,vspace);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HtmlObject,width)]=XML_ATTRNAME(HtmlObject,width);

   embed();
}


HtmlObject::~HtmlObject(){


}


v8::Handle<v8::ObjectTemplate> HtmlObject::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register property accessor
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,align).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,archive).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,border).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,code).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,codeBase).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,codeType).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,data).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,declare).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,form).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,height).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,hspace).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,name).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,standby).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,type).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,useMap).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,vspace).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(HtmlObject,width).c_str()), Node::GetAttribute, Node::SetAttribute);



    
    return _templ;

}



