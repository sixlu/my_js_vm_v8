
#include "node.h"
//#include "document.h"
#include "attr.h"

string Node::_try="try";

INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,tagName)

INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,attributes)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,baseURI)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,childNodes)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,firstChild)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,lastChild)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,localName)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,namespaceURI)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,nextSibling)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,nodeName)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,nodeType)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,nodeValue)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,ownerDocument)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,parentNode)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,prefix)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,previousSibling)
INIT_STATIC_JAVASCRIPTATTRI_NAME(Node,textContent)


INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,appendChild)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,cloneNode)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,compareDocumentPosition)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,getFeature)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,getUserData)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,hasAttributes)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,hasChildNodes)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,insertBefore)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,isDefaultNamespace)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,isEqualNode)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,isSameNode)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,isSupported)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,lookupNamespaceURI)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,lookupPrefix)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,normalize)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,removeChild)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,replaceChild)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(Node,setUserData)

Node::Node(void* node,xmlElementType nodetype)
:_node(node),_nodetype(nodetype),EventTarget(EventTarget::_supportAllEvent){

   embed();    
}

Node::Node(void* node,xmlElementType nodetype,unsigned short int supportEventType)
:_node(node),_nodetype(nodetype),EventTarget(supportEventType){

   embed();    
}

Node::~Node(){

}


v8::Handle<v8::ObjectTemplate> Node::embed(){
    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }
    //register property accessor
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,tagName).c_str()), Node::GetProperty, Node::SetProperty);
    
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,attributes).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,baseURI).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,childNodes).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,firstChild).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,lastChild).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,localName).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,namespaceURI).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,nextSibling).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,nodeName).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,nodeType).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,nodeValue).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,ownerDocument).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,parentNode).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,prefix).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,previousSibling).c_str()), Node::GetProperty, Node::SetProperty);
    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(Node,textContent).c_str()), Node::GetProperty, Node::SetProperty);                 
    //register function 
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,appendChild).c_str()), v8::FunctionTemplate::New(Node::appendChild));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,cloneNode).c_str()), v8::FunctionTemplate::New(Node::cloneNode));
//    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,compareDocumentPosition).c_str()), v8::FunctionTemplate::New(Node::compareDocumentPosition));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,getFeature).c_str()), v8::FunctionTemplate::New(Node::getFeature));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,getUserData).c_str()), v8::FunctionTemplate::New(Node::getUserData));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,hasAttributes).c_str()), v8::FunctionTemplate::New(Node::hasAttributes));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,hasChildNodes).c_str()), v8::FunctionTemplate::New(Node::hasChildNodes));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,insertBefore).c_str()), v8::FunctionTemplate::New(Node::insertBefore));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,isDefaultNamespace).c_str()), v8::FunctionTemplate::New(Node::isDefaultNamespace));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,isEqualNode).c_str()), v8::FunctionTemplate::New(Node::isEqualNode));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,isSameNode).c_str()), v8::FunctionTemplate::New(Node::isSameNode));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,isSupported).c_str()), v8::FunctionTemplate::New(Node::isSupported));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,lookupNamespaceURI).c_str()), v8::FunctionTemplate::New(Node::lookupNamespaceURI));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,lookupPrefix).c_str()), v8::FunctionTemplate::New(Node::lookupPrefix));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,normalize).c_str()), v8::FunctionTemplate::New(Node::normalize));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,removeChild).c_str()), v8::FunctionTemplate::New(Node::removeChild));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,replaceChild).c_str()), v8::FunctionTemplate::New(Node::replaceChild));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(Node,setUserData).c_str()), v8::FunctionTemplate::New(Node::setUserData));



      

    return _templ;

}


Handle<Value> Node::GetAttribute(Local<String> property,
                          const AccessorInfo &info) {
    
    NodePtr cur_node =(NodePtr) embedObject::UnWrap(info);

    string  property_name=embedObject::ToCString(property);
    string xmlattrname = cur_node->getXmlAttrNameByJsAttrName(property_name);
    
    xmlNodePtr xmlnodeptr=(xmlNodePtr) cur_node->getXmlNodePtr();
    xmlAttrPtr xml_property=xmlHasProp(xmlnodeptr,(xmlChar*)xmlattrname.c_str());

    if (xml_property!=NULL){

       return v8::String::New((char*)xml_property->children->content);
    }else{
       return v8::String::New("");
    }   

}


void Node::SetAttribute(Local<String> property, Local<Value> value,
                 const AccessorInfo& info) {

    NodePtr cur_node =(NodePtr) embedObject::UnWrap(info);   
    xmlNodePtr xmlnodeptr=(xmlNodePtr) cur_node->getXmlNodePtr(); 
    string  property_name=embedObject::ToCString(property);
    string xmlattrname = cur_node->getXmlAttrNameByJsAttrName(property_name);
    char *value_ptr =(char*) embedObject::ToCString(value).c_str();


    xmlAttrPtr xml_property=xmlHasProp(xmlnodeptr,(xmlChar*)xmlattrname.c_str());
    if (xml_property!=NULL){
       //xmlFreeProp(property);
       xmlSetProp(xmlnodeptr,(xmlChar*)xmlattrname.c_str(),(xmlChar*)value_ptr);
    }else{
       xmlNewProp(xmlnodeptr,(xmlChar*)xmlattrname.c_str(),(xmlChar*)value_ptr);
    }
}



Handle<Value> Node::GetProperty(Local<String> property,const AccessorInfo &info){
    
    NodePtr cur_node =(NodePtr) embedObject::UnWrap(info);
    char* property_name = (char*)embedObject::ToCString(property).c_str();

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,tagName).c_str())==0){

         xmlNodePtr xmnode = (xmlNodePtr)cur_node->getXmlNodePtr();
         const char* str= (const char*)xmnode->name;
         return v8::String::New(str);
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,attributes).c_str())==0 && cur_node->getNodetype()==XML_ELEMENT_NODE){

        NameNodeMapPtr namenodemap = cur_node->getAttributes();
        return namenodemap->newInstance<NameNodeMapPtr>();
        
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,baseURI).c_str())==0){

        return v8::Undefined();
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,childNodes).c_str())==0 && cur_node->getNodetype()==XML_ELEMENT_NODE){

        vector<NodePtr> childs = cur_node->getChildNodes();
        return embedObject::toJsArray<NodePtr>(childs);
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,firstChild).c_str())==0 && cur_node->getNodetype()==XML_ELEMENT_NODE){

        NodePtr node = cur_node->getFirstChild();
        return node->newInstance<NodePtr>(); 
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,lastChild).c_str())==0  && cur_node->getNodetype()==XML_ELEMENT_NODE){

        NodePtr node = cur_node->getLastChild();
        return node->newInstance<NodePtr>(); 
        
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,localName).c_str())==0){

         string str= cur_node->getLocalName();
         return v8::String::New(str.c_str());
    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,namespaceURI).c_str())==0){

         string str= cur_node->getNamespaceURI();
         return v8::String::New(str.c_str());

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,nextSibling).c_str())==0){

        NodePtr node = cur_node->getNextSibling();
        return node->newInstance<NodePtr>(); 

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,nodeName).c_str())==0){

         string str= cur_node->getNodeName();
         return v8::String::New(str.c_str());

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,nodeType).c_str())==0){
         
         return v8::Integer::New(cur_node->getNodeType());

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,nodeValue).c_str())==0){

         string str= cur_node->getNodeValue();
         return v8::String::New(str.c_str());

    }


/*
    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,ownerDocument).c_str())==0){
         DocumentPtr document=(DocumentPtr)cur_node->getOwnerDocument();
         return document->newInstance();

    }
*/

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,parentNode).c_str())==0){

        NodePtr node = cur_node->getParentNode();
        return node->newInstance<NodePtr>(); 

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,prefix).c_str())==0){

         string str= cur_node->getPrefix();
         return v8::String::New(str.c_str());

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,previousSibling).c_str())==0){

        NodePtr node = cur_node->getPreviousSibling();
        return node->newInstance<NodePtr>(); 

    }


    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,textContent).c_str())==0){

         string str= cur_node->getTextContent();
         return v8::String::New(str.c_str());

    }



}


void Node::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){
    NodePtr cur_node =(NodePtr) embedObject::UnWrap(info);
    char* property_name = (char*)embedObject::ToCString(property).c_str();
    char *value_ptr = (char*)embedObject::ToCString(value).c_str();



    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,nodeValue).c_str())==0){
        cur_node->setNodeValue(value_ptr);

    }


    //html not support this attribute
    
    //if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,prefix).c_str())==0){


    //}
    

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(Node,textContent).c_str())==0){

        cur_node->setTextContent(value_ptr);
    }
}




NameNodeMapPtr Node::getAttributes(){
  
     if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
       xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
       xmlAttrPtr cur_attr = xmlnodeptr->properties;
       NameNodeMapPtr namenodemap=NULL;
       while(cur_attr!=NULL){
         if(namenodemap==NULL){
           namenodemap =new NameNodeMap();
         }
         AttrPtr attr = NULL;
         if(cur_attr->_private!=NULL){
            attr = (AttrPtr)cur_attr->_private;
         }else{
            attr = new Attr(cur_attr);
            cur_attr->_private = attr;

         }
         namenodemap->addItem(attr);
         cur_attr = cur_attr->next;
       }
  
       return namenodemap;
     }else
       return NULL;

}


vector<NodePtr> Node::getChildNodes(){
    vector<NodePtr> childnodes;
    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      xmlNodePtr cur_child =  xmlnodeptr->children;
      while(cur_child!=NULL){
         if(cur_child->type!=XML_TEXT_NODE){ 
            NodePtr node = NULL;
            if(cur_child->_private !=NULL){
               node = (NodePtr)cur_child->_private;
            }else{
               node = new Node(cur_child,cur_child->type);
               cur_child->_private = node;
            }
            childnodes.push_back(node);
         }
         cur_child=cur_child->next;
      }

    }
    return childnodes;

}


NodePtr Node::getFirstChild(){
     
    NodePtr node =NULL;
    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      xmlNodePtr cur_child =  xmlnodeptr->children;
      if (cur_child){
         if(cur_child->_private!=NULL){
            node = (NodePtr)cur_child->_private;
         }else{
            node =new Node(cur_child,cur_child->type);
            cur_child->_private =node;
         }
      }
    } 

    return node;

}


NodePtr Node::getLastChild(){

    NodePtr node =NULL;
    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      xmlNodePtr cur_child =  xmlnodeptr->last;
      if (cur_child)
         if(cur_child->_private!=NULL){
            node = (NodePtr)cur_child->_private;
         }else{
            node =new Node(cur_child,cur_child->type);
            cur_child->_private =node;
         }
    } 

    return node;


}


string   Node::getLocalName(){
    
    string localname;
    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      localname = (char*)xmlnodeptr->name;

    }else if (_node!=NULL && _nodetype==XML_ATTRIBUTE_NODE){
      xmlAttrPtr xmlattrptr=(xmlAttrPtr) _node;
      localname = (char*)xmlattrptr->name;
    }
    return localname;

}


string   Node::getNamespaceURI(){

    string namespaceuri;
    xmlNs *ns=NULL;
    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      ns = xmlnodeptr->nsDef;
      

    }else if (_node!=NULL && _nodetype==XML_ATTRIBUTE_NODE){
      xmlAttrPtr xmlattrptr=(xmlAttrPtr) _node;
      ns = xmlattrptr->ns;
    }
    
    if(ns!=NULL)
      namespaceuri = (char*)ns->href;
    return namespaceuri;
}


NodePtr Node::getNextSibling(){
   
    NodePtr node =NULL;
    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      xmlNodePtr nextnode = xmlnodeptr->next;
      if(nextnode){
        if(nextnode->_private!=NULL){
           node =(NodePtr)nextnode->_private;
        }else{
           node =new Node(nextnode,nextnode->type);
           nextnode->_private = node;
        }
      }

    }else if (_node!=NULL && _nodetype==XML_ATTRIBUTE_NODE){
      xmlAttrPtr xmlattrptr=(xmlAttrPtr) _node;
      xmlAttrPtr nextattr = xmlattrptr->next;
      if (nextattr){
        if(nextattr->_private!=NULL){
           node = (NodePtr)nextattr->_private;
        }else{
           node =new Node(nextattr,nextattr->type);
           nextattr->_private = node;
        }
      }
    } 
 
    return node;

}


string   Node::getNodeName(){

    string nodename;
    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      nodename = (char*)xmlnodeptr->name;

    }else if (_node!=NULL && _nodetype==XML_ATTRIBUTE_NODE){
      xmlAttrPtr xmlattrptr=(xmlAttrPtr) _node;
      nodename = (char*)xmlattrptr->name;
    }
    return nodename;

}


xmlElementType Node::getNodeType(){
    
    xmlElementType type;
    void *type_addr = _node+4;
    memcpy(&type,type_addr,4);
    return type;    

}


string   Node::getNodeValue(){

    string value;
    if (_node!=NULL && _nodetype==XML_TEXT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      value = (char*)xmlnodeptr->content;

    }else if (_node!=NULL && _nodetype==XML_ATTRIBUTE_NODE){
      xmlAttrPtr xmlattr = (xmlAttrPtr) _node;
      xmlNodePtr value_node=xmlattr->children;
      value = (char*)value_node->content;

    }else if(_node!=NULL  ){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      if(xmlnodeptr->children->type==XML_TEXT_NODE){
        value = (char*)xmlnodeptr->children->content;
      }

    }
    return value;


}

void Node::addNextSibling(NodePtr node){

    if (_node!=NULL && _nodetype==XML_ATTRIBUTE_NODE && node->getNodetype()==XML_ATTRIBUTE_NODE){
      xmlAttrPtr xmlattr = (xmlAttrPtr) _node;
      xmlAttrPtr newattr = (xmlAttrPtr)node->getXmlNodePtr();
      xmlattr->next = (xmlAttrPtr)node->getXmlNodePtr();
      newattr->next = NULL;
      
    }else{
       
       xmlAddNextSibling((xmlNodePtr)_node,(xmlNodePtr)node->getXmlNodePtr());

    }



}

void   Node::setNodeValue(const char* value){
    if (_node!=NULL && _nodetype==XML_TEXT_NODE){
       
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      if( xmlnodeptr->content){
         free(xmlnodeptr->content);
      }
      xmlnodeptr->content=(xmlChar *)value;

    }else if (_node!=NULL && _nodetype==XML_ATTRIBUTE_NODE){
      xmlAttrPtr xmlattr = (xmlAttrPtr) _node;
      xmlNodePtr value_node=xmlattr->children;
      value_node->content = (xmlChar *)value;

    }

}

/*
DocumentPtr Node::getOwnerDocument(){

    DocumentPtr document =NULL;
    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      document =new Document(xmlnodeptr->doc);

    }else if (_node!=NULL && _nodetype==XML_ATTRIBUTE_NODE){
      xmlAttrPtr xmlattrptr=(xmlAttrPtr) _node;
      document =new Document(xmlattrptr->doc);
    }
    return document;
}
*/


NodePtr  Node::getParentNode(){

    NodePtr node =NULL;
    xmlNodePtr parentnode =NULL;
    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      parentnode = xmlnodeptr->parent;
      
    }else if (_node!=NULL && _nodetype==XML_ATTRIBUTE_NODE){
      xmlAttrPtr xmlattrptr=(xmlAttrPtr) _node;
      parentnode = xmlattrptr->parent;
    } 
    if(parentnode){
        if(parentnode->_private!=NULL){
           node = (NodePtr)parentnode->_private;
        }else{
           node =new Node(parentnode,parentnode->type);
           parentnode->_private = node;
        }
    }

    return node;

}


string   Node::getPrefix(){

    string prefix;
    xmlNs *ns=NULL;
    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      ns = xmlnodeptr->nsDef;
      

    }else if (_node!=NULL && _nodetype==XML_ATTRIBUTE_NODE){
      xmlAttrPtr xmlattrptr=(xmlAttrPtr) _node;
      ns = xmlattrptr->ns;
    }
    
    if(ns!=NULL)
      prefix = (char*)ns->prefix;
    return prefix;

}


NodePtr  Node::getPreviousSibling(){

    NodePtr node =NULL;
    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      xmlNodePtr prevnode = xmlnodeptr->prev;
      if(prevnode){
        if(prevnode->_private!=NULL){
           node = (NodePtr)prevnode->_private;
        }else{
           node =new Node(prevnode,prevnode->type);
           prevnode->_private = node;
        }
      }

    }else if (_node!=NULL && _nodetype==XML_ATTRIBUTE_NODE){
      xmlAttrPtr xmlattrptr=(xmlAttrPtr) _node;
      xmlAttrPtr prevattr = xmlattrptr->prev;
      if (prevattr){
        if(prevattr->_private!=NULL){
           node = (NodePtr)prevattr->_private;
        }else{
           node =new Node(prevattr,prevattr->type);
           prevattr->_private =node;
        }
      }
    } 
 
    return node;

}


string   Node::getTextContent(){
 
    string textcontent = getNodeValue();
    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
      xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
      xmlNodePtr cur_child =  xmlnodeptr->children;
      while(cur_child!=NULL){
         string cur_child_content = (char*)cur_child->content; 
         textcontent += cur_child_content;  
         cur_child=cur_child->next;
      }

    }
    return textcontent;
}

void   Node::setTextContent(const char *value){

    if (_node!=NULL && _nodetype==XML_ELEMENT_NODE){
       xmlNodePtr xmlnodeptr=(xmlNodePtr) _node;
       xmlFreeNodeList(xmlnodeptr->children);
       xmlNewTextChild(xmlnodeptr,NULL,NULL, (xmlChar*)value);
    }

}


v8::Handle<v8::Value> Node::appendChild(const v8::Arguments& args){
    if(args.Length()>=1  ){
       NodePtr cur_node =(NodePtr) embedObject::UnWrap(args); 
       if(cur_node){
          NodePtr child_node = (NodePtr)embedObject::UnWrap(args[0]);       
          cur_node->appendChild(child_node);  
       }
    }

}


v8::Handle<v8::Value> Node::cloneNode(const v8::Arguments& args){

    if(args.Length()>=1 ){
       NodePtr cur_node =(NodePtr) embedObject::UnWrap(args); 
       if(cur_node){
   
         NodePtr clonenode= cur_node->cloneNode(args[0]->ToBoolean()->Value());  
         return clonenode->newInstance<NodePtr>();         
       }
    }

}


v8::Handle<v8::Value> Node::compareDocumentPosition(const v8::Arguments& args){
    /*
    if(args.Length()>=1  ){
       NodePtr cur_node =(NodePtr) embedObject::UnWrap(args); 
       if(cur_node){
          NodePtr second_node = (NodePtr)embedObject::UnWrap(args[0]);       
          return v8::Integer::New(cur_node->compareDocumentPosition(second_node));  
       }
    }
    */

}


v8::Handle<v8::Value> Node::getFeature(const v8::Arguments& args){


}


v8::Handle<v8::Value> Node::getUserData(const v8::Arguments& args){


}


v8::Handle<v8::Value> Node::hasAttributes(const v8::Arguments& args){
    NodePtr cur_node =(NodePtr) embedObject::UnWrap(args); 
    if(cur_node){
        return v8::Boolean::New(cur_node->hasAttributes());  
    }

}


v8::Handle<v8::Value> Node::hasChildNodes(const v8::Arguments& args){
    NodePtr cur_node =(NodePtr) embedObject::UnWrap(args); 
    if(cur_node){
        return v8::Boolean::New(cur_node->hasChildNodes());  
    }



}


v8::Handle<v8::Value> Node::insertBefore(const v8::Arguments& args){
    if(args.Length()>=2  ){
       NodePtr cur_node =(NodePtr) embedObject::UnWrap(args); 
       if(cur_node){
          NodePtr new_node = (NodePtr)embedObject::UnWrap(args[0]);       
          NodePtr child_node = (NodePtr)embedObject::UnWrap(args[1]);       
          NodePtr inserted_node =cur_node->insertBefore(new_node,child_node);  
          return inserted_node->newInstance<NodePtr>();
       }
    }

}


v8::Handle<v8::Value> Node::isDefaultNamespace(const v8::Arguments& args){
    if(args.Length()>=1  ){
       NodePtr cur_node =(NodePtr) embedObject::UnWrap(args); 
       if(cur_node){
          Local< Value > t = args[0];
          char *namespaceuri= (char*)embedObject::ToCString(t).c_str();       
          return v8::Boolean::New(cur_node->isDefaultNamespace(namespaceuri));  
       }
    }



}


v8::Handle<v8::Value> Node::isEqualNode(const v8::Arguments& args){
    if(args.Length()>=1  ){
       NodePtr cur_node =(NodePtr) embedObject::UnWrap(args); 
       if(cur_node){
          NodePtr other_node = (NodePtr)embedObject::UnWrap(args[0]);       
          return v8::Boolean::New( cur_node->isEqualNode(other_node));  
       }
    }



}


v8::Handle<v8::Value> Node::isSameNode(const v8::Arguments& args){
    if(args.Length()>=1  ){
       NodePtr cur_node =(NodePtr) embedObject::UnWrap(args); 
       if(cur_node){
          NodePtr other_node = (NodePtr)embedObject::UnWrap(args[0]);       
          return v8::Boolean::New( cur_node->isSameNode(other_node));  
       }
    }



}


v8::Handle<v8::Value> Node::isSupported(const v8::Arguments& args){


}


v8::Handle<v8::Value> Node::lookupNamespaceURI(const v8::Arguments& args){


}


v8::Handle<v8::Value> Node::lookupPrefix(const v8::Arguments& args){


}


v8::Handle<v8::Value> Node::normalize(const v8::Arguments& args){


}


v8::Handle<v8::Value> Node::removeChild(const v8::Arguments& args){
    if(args.Length()>=1  ){
       NodePtr cur_node =(NodePtr) embedObject::UnWrap(args); 
       if(cur_node){
          NodePtr other_node = (NodePtr)embedObject::UnWrap(args[0]);       
          NodePtr removed_node = cur_node->removeChild(other_node);
          return removed_node->newInstance<NodePtr>();  
       }
    }

}


v8::Handle<v8::Value> Node::replaceChild(const v8::Arguments& args){
    if(args.Length()>=1  ){
       NodePtr cur_node =(NodePtr) embedObject::UnWrap(args); 
       if(cur_node){
          NodePtr new_node = (NodePtr)embedObject::UnWrap(args[0]);       
          NodePtr old_node = (NodePtr)embedObject::UnWrap(args[1]);       
          NodePtr replaced_node = cur_node->replaceChild(new_node,old_node);
          return replaced_node->newInstance<NodePtr>();  
       }
    }

}


v8::Handle<v8::Value> Node::setUserData(const v8::Arguments& args){


}


void Node::appendChild(NodePtr child){
    if (child){
       xmlNodePtr parent_xml =(xmlNodePtr)this->_node;
       xmlNodePtr child_xml = (xmlNodePtr) child->getXmlNodePtr();
       xmlAddChild(parent_xml,child_xml);
       //return child->newInstance(); 
    }
}


NodePtr Node::cloneNode(bool clone_descendants){
    int extended=2;
    if (clone_descendants)
       extended=1;
    xmlNodePtr cur_xml = (xmlNodePtr)this->_node;
    xmlNodePtr new_xml= xmlCopyNode(cur_xml,extended);
    if (new_xml){
       NodePtr new_node = NULL;
       if(new_xml->_private!=NULL){
          new_node = (NodePtr)new_xml->_private;
       }else{
          new_node = new Node(new_xml,new_xml->type);
          new_xml->_private = new_node;
       }
       return new_node;
    }
}

/*
DOCUMENTPOSITION Node::compareDocumentPosition(NodePtr seconeNode){
   if (this->getOwnerDocument()== seconeNode->getOwnerDocument()){

      xmlNodePtr first_node=(xmlNodePtr)this;
      xmlNodePtr second_node  = (xmlNodePtr) seconeNode->getXmlNodePtr();
      if (first_node->parent==second_node)
          return FIRST_INSIDE_POSITION;
      else if (second_node->parent== first_node)
          return SECOND_INSIDE_POSITION;
      else if (first_node->parent==second_node->parent){
          xmlNodePtr parent = first_node->parent;
          xmlNodePtr brother = parent->children;
          int first_node_index=0;
          int second_node_index=0;
          int index=0;
          while (brother!=NULL){
            if (brother==first_node)
               first_node_index=index;
            if (brother==second_node)
               second_node_index=index;
            index++;
            brother= brother->next;
          }

          if (first_node_index<= second_node_index)
             return BEFORE_POSITION;
          else
             return AFTER_POSITION;
      }else
          return NO_RELATION_SHIP_OR_TOWATTR_ON_SAME_ELEMENT;
   }else
      return NOT_SAME_DOCUMENT;
}
*/

bool Node::hasAttributes(){
   xmlNodePtr node=(xmlNodePtr)this;
   if (node->properties!=NULL)
      return true;
   else
      return false;
}


bool Node::hasChildNodes(){
   xmlNodePtr node=(xmlNodePtr)this;
   if (node->children!=NULL)
      return true;
   else
      return false;

}


NodePtr Node::insertBefore(NodePtr newnode,NodePtr childnode){
    xmlNodePtr newnode_xml =(xmlNodePtr) newnode->getXmlNodePtr();
    xmlNodePtr childnode_xml=(xmlNodePtr) childnode->getXmlNodePtr();
    if( xmlAddPrevSibling(childnode_xml,newnode_xml)!=NULL)
       return newnode;
    
}


bool Node::isDefaultNamespace(const char *namespaceuri){
    
   xmlNodePtr node_xml=(xmlNodePtr)this;
   if (node_xml->nsDef){
      char *href=(char*)node_xml->nsDef->href;
      if (strcasecmp(href,namespaceuri)==0)
        return true;
      else 
        return false;
   }
}


bool Node::isEqualNode(NodePtr node){

}


bool Node::isSameNode(NodePtr node){
    xmlNodePtr cur_node_xml=(xmlNodePtr)this;
    xmlNodePtr node_xml= (xmlNodePtr)node->getXmlNodePtr();
    if (cur_node_xml==node_xml)
       return true;
    else
       return false;
}


NodePtr Node::removeChild(NodePtr node){
    xmlNodePtr node_xml= (xmlNodePtr)node->getXmlNodePtr();
    xmlUnlinkNode(node_xml);
    xmlFreeNode(node_xml);
    return node;
}


NodePtr Node::replaceChild(NodePtr newnode,NodePtr oldnode){
    xmlNodePtr new_xml =(xmlNodePtr)newnode->getXmlNodePtr();
    xmlNodePtr old_xml =(xmlNodePtr)oldnode->getXmlNodePtr();
    xmlReplaceNode(old_xml,new_xml);
    return newnode;
}

bool Node::dispatchEventToParent(void* eptr){
    NodePtr parentNode = getParentNode();
    return parentNode->dispatchEvent((EventPtr)eptr);
}
void Node::defaultAction(){

}



