
#include "namenodemap.h"
#include "node.h"

INIT_STATIC_JAVASCRIPTATTRI_NAME(NameNodeMap,length)

INIT_STATIC_JAVASCRIPTFUNCTION_NAME(NameNodeMap,getNamedItem)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(NameNodeMap,getNamedItemNS)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(NameNodeMap,item)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(NameNodeMap,removeNamedItem)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(NameNodeMap,removeNamedItemNS)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(NameNodeMap,setNamedItem)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(NameNodeMap,setNamedItemNS)


NameNodeMap::NameNodeMap(){


}


NameNodeMap::~NameNodeMap(){


}


v8::Handle<v8::ObjectTemplate> NameNodeMap::embed(){

    if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
    }

    _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(NameNodeMap,length).c_str()), NameNodeMap::GetProperty, NameNodeMap::SetProperty);

    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(NameNodeMap,getNamedItem).c_str()), v8::FunctionTemplate::New(NameNodeMap::getNamedItem));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(NameNodeMap,getNamedItemNS).c_str()), v8::FunctionTemplate::New(NameNodeMap::getNamedItemNS));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(NameNodeMap,item).c_str()), v8::FunctionTemplate::New(NameNodeMap::item));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(NameNodeMap,removeNamedItem).c_str()), v8::FunctionTemplate::New(NameNodeMap::removeNamedItem));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(NameNodeMap,removeNamedItemNS).c_str()), v8::FunctionTemplate::New(NameNodeMap::removeNamedItemNS));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(NameNodeMap,setNamedItem).c_str()), v8::FunctionTemplate::New(NameNodeMap::setNamedItem));
    _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(NameNodeMap,setNamedItemNS).c_str()), v8::FunctionTemplate::New(NameNodeMap::setNamedItemNS));



    return _templ;


}

Handle<Value> NameNodeMap::GetProperty(Local<String> property,const AccessorInfo &info){
    NameNodeMapPtr collection =(NameNodeMapPtr) embedObject::UnWrap(info);
    char* property_name = (char*)embedObject::ToCString(property).c_str();

    if (strcmp(property_name,JAVASCRIPT_ATTRNAME(NameNodeMap,length).c_str())==0){
         return v8::Integer::New(collection->count());
    }



}


void NameNodeMap::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){


}




v8::Handle<v8::Value> NameNodeMap::getNamedItem(const v8::Arguments& args){
     if(args.Length()>=1  ){
        NameNodeMapPtr collection =(NameNodeMapPtr) embedObject::UnWrap(args);
        Local< Value > param1 = args[0];
        string name = embedObject::ToCString(param1);
        NodePtr node = (NodePtr)collection->getNameItem(name);
        if(node)
          return node->newInstance<NodePtr>();
     }

}

 
v8::Handle<v8::Value> NameNodeMap::getNamedItemNS(const v8::Arguments& args){


}

 
v8::Handle<v8::Value> NameNodeMap::item(const v8::Arguments& args){
     if(args.Length()>=1  ){
        NameNodeMapPtr collection =(NameNodeMapPtr) embedObject::UnWrap(args);
        int index = args[0]->Int32Value();;
        NodePtr node = (NodePtr)collection->getItemByIndex(index);
        if(node)
          return node->newInstance<NodePtr>();
     }



}

 
v8::Handle<v8::Value> NameNodeMap::removeNamedItem(const v8::Arguments& args){


}


v8::Handle<v8::Value> NameNodeMap::removeNamedItemNS(const v8::Arguments& args){


}


v8::Handle<v8::Value> NameNodeMap::setNamedItem(const v8::Arguments& args){
     if(args.Length()>=1  ){
        NameNodeMapPtr collection =(NameNodeMapPtr) embedObject::UnWrap(args);
        NodePtr other_node = (NodePtr)embedObject::UnWrap(args[0]);
        collection->setItem(other_node);
     }


}


v8::Handle<v8::Value> NameNodeMap::setNamedItemNS(const v8::Arguments& args){


}


void NameNodeMap::addItem(void *node){
   if(node)
     _nodes.push_back(node);
}



void* NameNodeMap::getNameItem(string &name){
   vector<void*>::iterator itr = _nodes.begin();
   while(itr!=_nodes.end()){
      NodePtr node  = (NodePtr)(*itr);
      string nodename = node->getNodeName();
      if(strcmp(name.c_str(),nodename.c_str())==0){
         return (void*)node;
      }
      itr++;
   }

}


void* NameNodeMap::getItemByIndex(int index){

   if (index<_nodes.size()){
      NodePtr node  = (NodePtr)_nodes[index];
      return (void*)node;
   }
}


void NameNodeMap::setItem(void *node){

   if (node){
       NodePtr lastnode =(NodePtr) _nodes[_nodes.size()-1];
       if(lastnode->getNodetype()==XML_ATTRIBUTE_NODE && ((NodePtr)node)->getNodetype()==XML_ATTRIBUTE_NODE){
         
          lastnode->addNextSibling((NodePtr)node);
       
       }
       addItem((void*)node);
       
   }
}




