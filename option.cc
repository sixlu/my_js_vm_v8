#include "option.h"

INIT_STATIC_JAVASCRIPTATTRI_NAME(Option,defaultSelected)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Option,form)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Option,text)


INIT_STATIC_ATTRNAME(Option,disabled,disabled)
INIT_STATIC_ATTRNAME(Option,index,index)
INIT_STATIC_ATTRNAME(Option,selected,selected)
INIT_STATIC_ATTRNAME(Option,value,value)


Option::Option(xmlNodePtr node,FormPtr form,bool isdefaultSelected)
:HTMLElement(node),_form(form),_isdefaultSelected(isdefaultSelected){

javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Option,disabled)]=XML_ATTRNAME(Option,disabled);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Option,index)]=XML_ATTRNAME(Option,index);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Option,selected)]=XML_ATTRNAME(Option,selected);
javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(Option,value)]=XML_ATTRNAME(Option,value);
   embed();
}

Option::~Option(){

}

v8::Handle<v8::ObjectTemplate> Option::embed(){
    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register self attribute
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Option,disabled).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Option,index).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Option,selected).c_str()), Node::GetAttribute, Node::SetAttribute);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Option,value).c_str()), Node::GetAttribute, Node::SetAttribute);


    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Option,defaultSelected).c_str()), Option::GetProperty, Option::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Option,form).c_str()), Option::GetProperty, Option::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Option,text).c_str()), Option::GetProperty, Option::SetProperty);
    


    
    return _templ;

}


Handle<Value> Option::GetProperty(Local<String> property,const AccessorInfo &info){

    OptionPtr cur_node =(OptionPtr) embedObject::UnWrap(info);
    char* property_name = (char*)embedObject::ToCString(property).c_str();

    
    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Option,defaultSelected).c_str())==0){
         return v8::Boolean::New(cur_node->isDefaultSelected());
    }

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Option,form).c_str())==0){
         FormPtr form = cur_node->getForm();
         return form->newInstance<FormPtr>();
    }

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Option,text).c_str())==0){
         string str= cur_node->getNodeValue();
         return v8::String::New(str.c_str());
    }

 
}


void Option::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

    NodePtr cur_node =(NodePtr) embedObject::UnWrap(info);
    char* property_name = (char*)embedObject::ToCString(property).c_str();
    char *value_ptr = (char*)embedObject::ToCString(value).c_str();



    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Option,text).c_str())==0){
        cur_node->setNodeValue(value_ptr);

    }


}


bool Option::isDefaultSelected(){

    return _isdefaultSelected;
}


void Option::setDefaultSelected(){
    _isdefaultSelected=true;
 
}


FormPtr Option::getForm(){
    return _form;

}



