
#include "document.h"
#include "utils.h"


INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,anchors)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,applets)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,body)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,cookie)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,documentMode)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,domain)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,forms)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,images)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,lastModified)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,links)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,readyState)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,referrer)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,title)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Document,URL)




INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Document,close)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Document,getElementsByName)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Document,open)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Document,write)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Document,writeln)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Document,createAttribute)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Document,createComment)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Document,createElement)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Document,createTextNode)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Document,getElementById)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Document,getElementsByTagName)


Document::Document(string &html_str,string &referrer,string &url,string& lastmodified,string &encoding,string &cookie)
:_referrer(referrer),_URL(url),_lastModified(lastmodified),_cookie(cookie){

   _doc = htmlReadMemory(html_str.c_str(),html_str.size(),url.c_str(),encoding.c_str(),HTML_PARSE_NOBLANKS|HTML_PARSE_NONET);    
   _referrer = referrer;
   _lastModified = lastmodified;
   _cookie  = cookie; 

   _xpathCtx = xmlXPathNewContext(_doc);
   
   embed();
}

Document::~Document(){

   if (_doc)
      xmlFreeDoc(_doc); 
}

DocumentPtr Document::New(string &html_str,string &referrer,string &url,string & lastmodified,string &encoding,string &cookie){
   
    DocumentPtr document = new Document(html_str,referrer,url,lastmodified,encoding,cookie);
    return document;  
}


vector<xmlNodePtr> Document::getElementsByXPathExpr(string &xpath_expr){

    vector<xmlNodePtr> result;
    if (xpath_expr.empty() || _xpathCtx==NULL)
       return result;


    /* Evaluate xpath expression */
    xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression((xmlChar*)xpath_expr.c_str(), _xpathCtx);
    if(xpathObj == NULL) {
        fprintf(stderr,"Error: unable to evaluate xpath expression \"%s\"\n", xpath_expr.c_str());
        return result;
    }    

    xmlNodeSetPtr nodes = xpathObj->nodesetval;
    int i=0;
    for(i=0;i<nodes->nodeNr;i++){
	    xmlNodePtr node =  nodes->nodeTab[i];
            result.push_back(node);	    
    }
   
    return result;
}

Document::PARSERESULT Document::parseHtml(){
    
    /* Create xpath evaluation context */
    if(_xpathCtx==NULL&&_doc)
    {
	    _xpathCtx = xmlXPathNewContext(_doc);
	    if(_xpathCtx == NULL) {
		fprintf(stderr,"Error: unable to create new XPath context\n");
		xmlFreeDoc(_doc);
		return PARSE_FAILURE;
	    }
    }

    string tagname = "a";
    _anchors = Document::Case<Anchor,AnchorPtr>(getElementsByTagName(tagname));
    tagname = "body";
    _body = Document::Case<Body,BodyPtr>(getElementsByTagName(tagname)[0]);
    string domain_regx="http://([^/]*)";
    vector<string> matchs;
    if(IChrome::Utils::str_regx_match(_URL,domain_regx,matchs)==0){
       _domain = matchs[1];
    }
    
    tagname = "form";
    _forms = Document::Case<Form,FormPtr>(getElementsByTagName(tagname));
    tagname = "img";
    _images = Document::Case<Image,ImagePtr>(getElementsByTagName(tagname));
    tagname = "link";
    _links = Document::Case<Link,LinkPtr>(getElementsByTagName(tagname));
    tagname = "title";
    vector<xmlNodePtr> titles = getElementsByTagName(tagname);
    if(titles.size()>0){
        xmlNodePtr title_node = titles[0];
        if(title_node!=NULL && title_node->children!=NULL){
          
           _title = (char*)title_node->children->content;
        } 
    }
    _readyState = COMPLETE;

    return PARSE_SUCCESS;
}

vector<xmlNodePtr>  Document::getElementsByName(string &name){

    vector<xmlNodePtr> result;
    if (name.empty() || _xpathCtx==NULL)
       return result;

    char pathexpr[PATHEXPRT_LEN];
    memset(pathexpr,0,PATHEXPRT_LEN);
    sprintf(pathexpr,"//*[@name='%s']",name.c_str());
    string xpathExpr = pathexpr;

    result = getElementsByXPathExpr(xpathExpr);   
   
    return result;



}
xmlNodePtr  Document::getElementById(string &id){
   
    vector<xmlNodePtr> result;
    if (id.empty() || _xpathCtx==NULL)
       return NULL;

    char pathexpr[PATHEXPRT_LEN];
    memset(pathexpr,0,PATHEXPRT_LEN);
    sprintf(pathexpr,"//*[@id='%s'][1]",id.c_str());
    string  xpathExpr = pathexpr;
   
    result = getElementsByXPathExpr(xpathExpr);
    if (result.size()>0)
      return result[0];
    else
      return NULL;
}
vector<xmlNodePtr>  Document::getElementsByTagName(string &tagname){
    
    vector<xmlNodePtr> result;
    if (tagname.empty() || _xpathCtx==NULL)
       return result;

    char pathexpr[PATHEXPRT_LEN];
    memset(pathexpr,0,PATHEXPRT_LEN);
    sprintf(pathexpr,"//%s",tagname.c_str());
    string  xpathExpr = pathexpr;
   
    result = getElementsByXPathExpr(xpathExpr);
 
    return result;
}

v8::Handle<v8::ObjectTemplate> Document::embed(){

    if((*_templ)==NULL){
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);

    }


    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,anchors).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,applets).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,body).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,cookie).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,documentMode).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,domain).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,forms).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,images).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,lastModified).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,links).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,readyState).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,referrer).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,title).c_str()), Document::GetProperty, Document::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Document,URL).c_str()), Document::GetProperty, Document::SetProperty);




    _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Document,close).c_str()),v8::FunctionTemplate::New(Document::close));
    _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Document,getElementsByName).c_str()),v8::FunctionTemplate::New(Document::getElementsByName));
    _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Document,open).c_str()),v8::FunctionTemplate::New(Document::open));
    _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Document,write).c_str()),v8::FunctionTemplate::New(Document::write));
    _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Document,writeln).c_str()),v8::FunctionTemplate::New(Document::writeln));
    _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Document,createAttribute).c_str()),v8::FunctionTemplate::New(Document::createAttribute));
    _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Document,createComment).c_str()),v8::FunctionTemplate::New(Document::createComment));
    _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Document,createElement).c_str()),v8::FunctionTemplate::New(Document::createElement));
    _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Document,createTextNode).c_str()),v8::FunctionTemplate::New(Document::createTextNode));
    _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Document,getElementById).c_str()),v8::FunctionTemplate::New(Document::getElementById));
    _templ->Set(String::New(JAVASCRIPT_FUNCNAME(Document,getElementsByTagName).c_str()),v8::FunctionTemplate::New(Document::getElementsByTagName));


    
    return _templ;

}


vector<AnchorPtr> Document::getanchors(){

    return _anchors;

}



BodyPtr Document::getbody(){
    
    return _body;

}



string Document::getcookie(){

    return _cookie;
}



string Document::getdomain(){

    return _domain;
}



vector<FormPtr> Document::getforms(){

    return _forms;
}



vector<ImagePtr> Document::getimages(){

    return _images;
}



string Document::getlastModified(){

    return _lastModified;
}



vector<LinkPtr> Document::getlinks(){

    return _links;
}



Document::READYSTATE Document::getreadyState(){

    return _readyState;
}



string Document::getreferrer(){

    return _referrer;
}



string Document::gettitle(){

    return _title;
}



void Document::settitle(string &title){

   string tagname="title";
   vector<xmlNodePtr> xml_nodes = getElementsByTagName(tagname);
   xmlNodePtr title_node =NULL;
   if(xml_nodes.size()>0){
     title_node = xml_nodes[0];
     //title_node->setNodeValue(title);
      if( title_node->content){
         free(title_node->content);
      }   
      title_node->content=(xmlChar *)title.c_str();
   }else{
     xmlNodePtr root = xmlDocGetRootElement(_doc);
     HTMLElementPtr html = new HTMLElement("title");
     html->setNodeValue(title.c_str());
     appendChild(html);
   }

}



string Document::getURL(){

    return _URL;
}







Handle<Value> Document::GetProperty(Local<String> property,const AccessorInfo &info){

    DocumentPtr doc =(DocumentPtr) embedObject::UnWrap(info);
    char* property_name = (char*)embedObject::ToCString(property).c_str();

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,anchors).c_str())==0){
         vector<AnchorPtr> objs= doc->getanchors();
         return Document::Case<Anchor,AnchorPtr>(objs);       
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,applets).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,body).c_str())==0){
         BodyPtr body = doc->getbody();
         return body->newInstance<BodyPtr>();
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,cookie).c_str())==0){
         return v8::String::New(doc->getcookie().c_str());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,documentMode).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,domain).c_str())==0){

         return v8::String::New(doc->getdomain().c_str());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,forms).c_str())==0){

         vector<FormPtr> objs= doc->getforms();
         return Document::Case<Form,FormPtr>(objs);       
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,images).c_str())==0){

         vector<ImagePtr> objs= doc->getimages();
         return Document::Case<Image,ImagePtr>(objs);       
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,lastModified).c_str())==0){

         return v8::String::New(doc->getlastModified().c_str());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,links).c_str())==0){

         vector<LinkPtr> objs= doc->getlinks();
         return Document::Case<Link,LinkPtr>(objs);       
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,readyState).c_str())==0){

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,referrer).c_str())==0){

         return v8::String::New(doc->getreferrer().c_str());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,title).c_str())==0){

         return v8::String::New(doc->gettitle().c_str());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,URL).c_str())==0){

         return v8::String::New(doc->getURL().c_str());
    }




}



void Document::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

    DocumentPtr doc =(DocumentPtr) embedObject::UnWrap(info);
    char* property_name =(char*) embedObject::ToCString(property).c_str();

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Document,title).c_str())==0){

         string value_ptr = embedObject::ToCString(value);
         doc->settitle(value_ptr);
    }

}



v8::Handle<v8::Value> Document::close(const v8::Arguments& args){


}



v8::Handle<v8::Value> Document::getElementsByName(const v8::Arguments& args){
 
     if(args.Length()>=1  ){
        Local< Value > param1 = args[0];
        string name = embedObject::ToCString(param1);
        DocumentPtr doc =(DocumentPtr) embedObject::UnWrap(args);
        vector<HTMLElementPtr> html_nodes=  Document::Case<HTMLElement,HTMLElementPtr>(doc->getElementsByName(name));
        return Document::Case<HTMLElement,HTMLElementPtr>(html_nodes);   
     }
}



v8::Handle<v8::Value> Document::open(const v8::Arguments& args){


}



v8::Handle<v8::Value> Document::write(const v8::Arguments& args){

    printf("Document::write\n");
}



v8::Handle<v8::Value> Document::writeln(const v8::Arguments& args){


    printf("Document::writeln\n");
}



v8::Handle<v8::Value> Document::createAttribute(const v8::Arguments& args){
    
   if(args.Length()>=1  ){
       Local< Value > param1 = args[0];
       string attr_name = embedObject::ToCString(param1);
       AttrPtr attr= new Attr(attr_name);
       return attr->newInstance<AttrPtr>();
   }
}



v8::Handle<v8::Value> Document::createComment(const v8::Arguments& args){

    printf("Document::createComment\n");
}



v8::Handle<v8::Value> Document::createElement(const v8::Arguments& args){
    
   if(args.Length()>=1  ){
       Local< Value > param1 = args[0];
       string ele_name = embedObject::ToCString(param1);
       HTMLElementPtr htmlelement= new HTMLElement(ele_name.c_str());
       return htmlelement->newInstance<HTMLElementPtr>();
   }

}



v8::Handle<v8::Value> Document::createTextNode(const v8::Arguments& args){

   if(args.Length()>=1  ){
       Local< Value > param1 = args[0];
       string text = embedObject::ToCString(param1);
       xmlNodePtr text_node= xmlNewText((xmlChar*)text.c_str());
       NodePtr node= new Node(text_node,text_node->type);
       text_node->_private = node;
       return node->newInstance<NodePtr>();
   }



}



v8::Handle<v8::Value> Document::getElementById(const v8::Arguments& args){

     if(args.Length()>=1  ){
        Local< Value > param1 = args[0];
        string id = embedObject::ToCString(param1);
        DocumentPtr doc =(DocumentPtr) embedObject::UnWrap(args);
        HTMLElementPtr html_node = Document::Case<HTMLElement,HTMLElementPtr>(doc->getElementById(id));
        return html_node->newInstance<HTMLElementPtr>();
     }
}



v8::Handle<v8::Value> Document::getElementsByTagName(const v8::Arguments& args){

     if(args.Length()>=1  ){
        Local< Value > param1 = args[0];
        string name = embedObject::ToCString(param1);
        DocumentPtr doc =(DocumentPtr) embedObject::UnWrap(args);
        vector<HTMLElementPtr> html_nodes=  Document::Case<HTMLElement,HTMLElementPtr>(doc->getElementsByTagName(name));
        return Document::Case<HTMLElement,HTMLElementPtr>(html_nodes);   
     }

}



