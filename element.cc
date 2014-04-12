#include "element.h"

//INIT_STATIC_JAVASCRIPTATTRI_NAME(Element,schemaTypeInfo)
//INIT_STATIC_JAVASCRIPTATTRI_NAME(Element,tagName)


//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,getAttribute)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,getAttributeNS)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,getAttributeNode)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,getAttributeNodeNS)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,getElementsByTagName)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,getElementsByTagNameNS)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,hasAttribute)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,hasAttributeNS)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,removeAttribute)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,removeAttributeNS)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,removeAttributeNode)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,setAttribute)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,setAttributeNS)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,setAttributeNode)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,setAttributeNodeNS)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,setIdAttribute)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,setIdAttributeNS)
//INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Element,setIdAttributeNode)

Element::Element(){
   embed();
}

Element::Element(xmlNodePtr node):Node(node,XML_ELEMENT_NODE){
   embed();
}


Element::~Element(){

}

v8::Handle<v8::ObjectTemplate> Element::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }   
    //register property accessor
    //_templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Element,schemaTypeInfo).c_str()), Element::GetProperty, Element::SetProperty);
    //_templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Element,tagName).c_str()), Element::GetProperty, Element::SetProperty);



    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,getAttribute).c_str()), v8::FunctionTemplate::New(Element::getAttribute));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,getAttributeNS).c_str()), v8::FunctionTemplate::New(Element::getAttributeNS));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,getAttributeNode).c_str()), v8::FunctionTemplate::New(Element::getAttributeNode));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,getAttributeNodeNS).c_str()), v8::FunctionTemplate::New(Element::getAttributeNodeNS));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,getElementsByTagName).c_str()), v8::FunctionTemplate::New(Element::getElementsByTagName));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,getElementsByTagNameNS).c_str()), v8::FunctionTemplate::New(Element::getElementsByTagNameNS));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,hasAttribute).c_str()), v8::FunctionTemplate::New(Element::hasAttribute));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,hasAttributeNS).c_str()), v8::FunctionTemplate::New(Element::hasAttributeNS));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,removeAttribute).c_str()), v8::FunctionTemplate::New(Element::removeAttribute));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,removeAttributeNS).c_str()), v8::FunctionTemplate::New(Element::removeAttributeNS));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,removeAttributeNode).c_str()), v8::FunctionTemplate::New(Element::removeAttributeNode));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,setAttribute).c_str()), v8::FunctionTemplate::New(Element::setAttribute));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,setAttributeNS).c_str()), v8::FunctionTemplate::New(Element::setAttributeNS));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,setAttributeNode).c_str()), v8::FunctionTemplate::New(Element::setAttributeNode));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,setAttributeNodeNS).c_str()), v8::FunctionTemplate::New(Element::setAttributeNodeNS));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,setIdAttribute).c_str()), v8::FunctionTemplate::New(Element::setIdAttribute));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,setIdAttributeNS).c_str()), v8::FunctionTemplate::New(Element::setIdAttributeNS));
    //_templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Element,setIdAttributeNode).c_str()), v8::FunctionTemplate::New(Element::setIdAttributeNode));

   return _templ;

}

const char* Element::getTagName(){
    xmlNodePtr xmnode = (xmlNodePtr)this->getXmlNodePtr();
    return (const char*)xmnode->name;

}

Handle<Value> Element::GetProperty(Local<String> property,const AccessorInfo &info){
   /*
   ElementPtr cur_element =(ElementPtr) embedObject::UnWrap(info);
   char* property_name = (char*)embedObject::ToCString(property).c_str();

   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Element,tagName).c_str())==0){

         const char* str= cur_element->getTagName();
         return v8::String::New(str);
   }
   */
}

void Element::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

}

v8::Handle<v8::Value> Element::getElementsByTagName(const v8::Arguments& args){

}
