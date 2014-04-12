
#include "htmlElement.h"

INIT_STATIC_ATTRNAME(HTMLElement,accessKey,accessKey)
INIT_STATIC_ATTRNAME(HTMLElement,className,class)
INIT_STATIC_ATTRNAME(HTMLElement,clientHeight,clientHeight)
INIT_STATIC_ATTRNAME(HTMLElement,clientWidth,clientWidth)
INIT_STATIC_ATTRNAME(HTMLElement,dir,dir)
INIT_STATIC_ATTRNAME(HTMLElement,id,id)
INIT_STATIC_ATTRNAME(HTMLElement,innerHTML,innerHTML)
INIT_STATIC_ATTRNAME(HTMLElement,lang,lang)
INIT_STATIC_ATTRNAME(HTMLElement,offsetHeight,offsetHeight)
INIT_STATIC_ATTRNAME(HTMLElement,offsetLeft,offsetLeft)
INIT_STATIC_ATTRNAME(HTMLElement,offsetParent,offsetParent)
INIT_STATIC_ATTRNAME(HTMLElement,offsetTop,offsetTop)
INIT_STATIC_ATTRNAME(HTMLElement,offsetWidth,offsetWidth)
INIT_STATIC_ATTRNAME(HTMLElement,scrollHeight,scrollHeight)
INIT_STATIC_ATTRNAME(HTMLElement,scrollLeft,scrollLeft)
INIT_STATIC_ATTRNAME(HTMLElement,scrollTop,scrollTop)
INIT_STATIC_ATTRNAME(HTMLElement,scrollWidth,scrollWidth)
INIT_STATIC_ATTRNAME(HTMLElement,style,style)
INIT_STATIC_ATTRNAME(HTMLElement,tabIndex,tabIndex)
INIT_STATIC_ATTRNAME(HTMLElement,title,title)

HTMLElement::HTMLElement(xmlNodePtr node)
:Element(node){

   
   embed();
}

HTMLElement::HTMLElement(const char *node_name){

   xmlNodePtr _node  = xmlNewNode(NULL,(xmlChar*)node_name);
   _node->_private = this;
   _nodetype = XML_ELEMENT_NODE;

    embed();

}


HTMLElement::~HTMLElement(){
 
}



v8::Handle<v8::ObjectTemplate> HTMLElement::embed(){

   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,accessKey)]=XML_ATTRNAME(HTMLElement,accessKey);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,className)]=XML_ATTRNAME(HTMLElement,class);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,clientHeight)]=XML_ATTRNAME(HTMLElement,clientHeight);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,clientWidth)]=XML_ATTRNAME(HTMLElement,clientWidth);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,dir)]=XML_ATTRNAME(HTMLElement,dir);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,id)]=XML_ATTRNAME(HTMLElement,id);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,innerHTML)]=XML_ATTRNAME(HTMLElement,innerHTML);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,lang)]=XML_ATTRNAME(HTMLElement,lang);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,offsetHeight)]=XML_ATTRNAME(HTMLElement,offsetHeight);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,offsetLeft)]=XML_ATTRNAME(HTMLElement,offsetLeft);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,offsetParent)]=XML_ATTRNAME(HTMLElement,offsetParent);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,offsetTop)]=XML_ATTRNAME(HTMLElement,offsetTop);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,offsetWidth)]=XML_ATTRNAME(HTMLElement,offsetWidth);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,scrollHeight)]=XML_ATTRNAME(HTMLElement,scrollHeight);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,scrollLeft)]=XML_ATTRNAME(HTMLElement,scrollLeft);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,scrollTop)]=XML_ATTRNAME(HTMLElement,scrollTop);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,scrollWidth)]=XML_ATTRNAME(HTMLElement,scrollWidth);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,style)]=XML_ATTRNAME(HTMLElement,style);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,tabIndex)]=XML_ATTRNAME(HTMLElement,tabIndex);
   javascriptAttrName_map_xmlAttrName[JAVASCRIPT_ATTRNAME(HTMLElement,title)]=XML_ATTRNAME(HTMLElement,title);

 
    if((*_templ)==NULL){ 
	    _templ = ObjectTemplate::New();
	    _templ->SetInternalFieldCount(1);
    }
    map<string,string>::iterator itr = javascriptAttrName_map_xmlAttrName.begin();
    while(itr!=javascriptAttrName_map_xmlAttrName.end()){
       string javascript_attrname = itr->first;
       _templ->SetAccessor(String::New(javascript_attrname.c_str()), HTMLElement::GetAttribute, HTMLElement::SetAttribute);
       itr++;
    }
    

    return _templ;
    
    
}




//Handle<Value> HTMLElement::GetAttribute(Local<String> property,
//                          const AccessorInfo &info) {
Handle<Value> HTMLElement::GetAttribute(Local<String> property,
                          const AccessorInfo &info) {

    //Local<Object> self = info.Holder();
    //Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    //void* ptr = wrap->Value();
    HTMLElementPtr cur_html =(HTMLElementPtr) embedObject::UnWrap(info);

    string  property_name=embedObject::ToCString(property);
    xmlNodePtr cur_node = (xmlNodePtr)cur_html->getXmlNodePtr();

    if (strcmp(property_name.c_str(),JAVASCRIPT_ATTRNAME(HTMLElement,innerHTML).c_str())!=0){
        
	    //string xmlattrname = javascriptAttrName_map_xmlAttrName[property_name];
            string xmlattrname = cur_html->getXmlAttrNameByJsAttrName(property_name);
	    xmlAttrPtr property=xmlHasProp(cur_node,(xmlChar*)xmlattrname.c_str());

	    if (property!=NULL){
		      
	       return v8::String::New((char*)property->children->content);
	    }else{
	       return v8::String::New("");
	    }
    }else{

        xmlBufferPtr xml_buf = NULL;
        xml_buf = xmlBufferCreate();
        xmlNodeDump(xml_buf, NULL, cur_node, 0, 0);
        const xmlChar *xml = xmlBufferContent(xml_buf);
        //printf("hahahaha\n%s\nooooo\n",(const char *)xml);
        Local<v8::String> result = v8::String::New((const char *)xml);
        xmlBufferFree(xml_buf);
        
        return result;
    }

}

//void HTMLElement::SetAttribute(Local<String> property, Local<Value> value,
//                 const AccessorInfo& info) {
void HTMLElement::SetAttribute(Local<String> property, Local<Value> value,
                 const AccessorInfo& info) {


    //Local<Object> self = info.Holder();
    //Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    //void* ptr = wrap->Value();
    HTMLElementPtr cur_html =(HTMLElementPtr) embedObject::UnWrap(info);
    xmlNodePtr cur_node = (xmlNodePtr)cur_html->getXmlNodePtr();
    
    char* property_name = (char*)embedObject::ToCString(property).c_str();
    char *value_ptr = (char*)embedObject::ToCString(value).c_str();

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(HTMLElement,innerHTML).c_str())!=0){

	    xmlAttrPtr property=xmlHasProp(cur_node,(xmlChar*)property_name);
	    if (property!=NULL){
	       xmlFreeProp(property);
	    }
	       
	    xmlNewProp(cur_node,(xmlChar*)property_name,(xmlChar*)value_ptr);
    }else{
          //xmlDocPtr	xmlParseMemory		(const char * buffer, 
	//				 int size)
            xmlNodeSetContent(cur_node,(xmlChar*)value_ptr);
    }
}







