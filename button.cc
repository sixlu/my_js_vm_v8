#include "button.h"

INIT_STATIC_JAVASCRIPTATTRI_NAME(Button,form)


INIT_STATIC_ATTRNAME(Button,disabled,disabled)
INIT_STATIC_ATTRNAME(Button,name,name)
INIT_STATIC_ATTRNAME(Button,type,type)
INIT_STATIC_ATTRNAME(Button,value,value)

Button::Button(xmlNodePtr node,FormPtr form)
:HTMLElement(node),_form(form){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Button,disabled)]=XML_ATTRNAME(Button,disabled);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Button,name)]=XML_ATTRNAME(Button,name);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Button,type)]=XML_ATTRNAME(Button,type);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Button,value)]=XML_ATTRNAME(Button,value);


   embed();
}


Button::~Button(){


}


v8::Handle<v8::ObjectTemplate> Button::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Button,form).c_str()), Button::GetProperty, Button::SetProperty);


    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Button,disabled).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Button,name).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Button,type).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Button,value).c_str()), Node::GetAttribute, Node::SetAttribute);

   


       
    return _templ;

}


FormPtr Button::getForm(){
   return _form;     

}


Handle<Value> Button::GetProperty(Local<String> property,const AccessorInfo &info){

    ButtonPtr cur_node =(ButtonPtr) embedObject::UnWrap(info);
    char* property_name =(char*) embedObject::ToCString(property).c_str();



    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Button,form).c_str())==0){
         FormPtr form = cur_node->getForm();
         return form->newInstance<FormPtr>();
    }
     

}


void Button::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){


}




