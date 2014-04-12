#include "attr.h"

INIT_STATIC_ATTRNAME(Attr,isId,isId)
INIT_STATIC_ATTRNAME(Attr,name,name)
INIT_STATIC_ATTRNAME(Attr,ownerElement,ownerElement)
//INIT_STATIC_ATTRNAME(Attr,schemaTypeInfo,schemaTypeInfo)
INIT_STATIC_ATTRNAME(Attr,specified,specified)
INIT_STATIC_ATTRNAME(Attr,value,value)

Attr::Attr(xmlAttrPtr attr):Node(attr,XML_ATTRIBUTE_NODE){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Attr,isId)]=XML_ATTRNAME(Attr,isId);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Attr,name)]=XML_ATTRNAME(Attr,name);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Attr,ownerElement)]=XML_ATTRNAME(Attr,ownerElement);
//javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Attr,schemaTypeInfo)]=XML_ATTRNAME(Attr,schemaTypeInfo);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Attr,specified)]=XML_ATTRNAME(Attr,specified);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Attr,value)]=XML_ATTRNAME(Attr,value);

   embed();
   this->name = this->getNodeName();
   if(strcasecmp(this->name.c_str(),"id")==0){
      this->isId=true;
   }else{
      this->isId=false;
   }
   this->ownerElement=this->getParentNode();
   this->specified =true;   
   this->value = this->getNodeValue();
}

Attr::Attr(string &attr_name){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Attr,isId)]=XML_ATTRNAME(Attr,isId);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Attr,name)]=XML_ATTRNAME(Attr,name);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Attr,ownerElement)]=XML_ATTRNAME(Attr,ownerElement);
//javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Attr,schemaTypeInfo)]=XML_ATTRNAME(Attr,schemaTypeInfo);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Attr,specified)]=XML_ATTRNAME(Attr,specified);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Attr,value)]=XML_ATTRNAME(Attr,value);

   embed();

   xmlAttrPtr xmlattr = new xmlAttr;
   memset(xmlattr,0,sizeof(xmlAttr));
   this->name = attr_name;
   xmlattr->_private = this;
   
   xmlattr->name =(xmlChar*) this->name.c_str();
   xmlattr->atype = XML_ATTRIBUTE_CDATA;


   _node = xmlattr;
   _nodetype = XML_ATTRIBUTE_NODE;

}


Attr::~Attr(){


}

 
v8::Handle<v8::ObjectTemplate> Attr::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Attr,isId).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Attr,name).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Attr,ownerElement).c_str()), Node::GetProperty, Node::SetProperty);
//    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Attr,schemaTypeInfo).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Attr,specified).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Attr,value).c_str()), Node::GetProperty, Node::SetProperty);

   


       
    return _templ;

}

Handle<Value> Attr::GetProperty(Local<String> property,const AccessorInfo &info){

    AttrPtr cur_attr =(AttrPtr) embedObject::UnWrap(info);
    char* property_name = (char*)embedObject::ToCString(property).c_str();

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Attr,isId).c_str())==0){

         return v8::Boolean::New(cur_attr->isId);

    }
    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Attr,name).c_str())==0){

         return v8::String::New(cur_attr->name.c_str());

    }

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Attr,ownerElement).c_str())==0 ){

        return cur_attr->ownerElement->newInstance<NodePtr>();
    
    }
    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Attr,specified).c_str())==0){

         return v8::Boolean::New(cur_attr->specified);

    }
    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Attr,value).c_str())==0){

         return v8::String::New(cur_attr->value.c_str());

    }

}

void Attr::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

}


