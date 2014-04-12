#include "mutationevent.h"

INIT_STATIC_JAVASCRIPTATTRI_NAME(MutationEvent,relatedNode)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MutationEvent,prevValue)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MutationEvent,newValue)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MutationEvent,attrName)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MutationEvent,attrChange)

INIT_STATIC_JAVASCRIPTFUNCTION_NAME(MutationEvent,initMutationEvent)


const unsigned short      MutationEvent::MODIFICATION=1;
const unsigned short      MutationEvent::ADDITION=2;
const unsigned short      MutationEvent::REMOVAL=3;

hash_map<string,string> MutationEvent::_type;


MutationEvent::MutationEvent(){

  embed();
   
}

MutationEvent::~MutationEvent(){

}

v8::Handle<v8::ObjectTemplate> MutationEvent::embed(){

   if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
   }   
   
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MutationEvent,relatedNode).c_str()), MutationEvent::GetProperty, MutationEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MutationEvent,prevValue).c_str()), MutationEvent::GetProperty, MutationEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MutationEvent,newValue).c_str()), MutationEvent::GetProperty, MutationEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MutationEvent,attrName).c_str()), MutationEvent::GetProperty, MutationEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MutationEvent,attrChange).c_str()), MutationEvent::GetProperty, MutationEvent::SetProperty);
  

   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(MutationEvent,initMutationEvent).c_str()), v8::FunctionTemplate::New(MutationEvent::initMutationEvent));


   return _templ;

}

Handle<Value> MutationEvent::GetProperty(Local<String> property,const AccessorInfo &info){
   MutationEventPtr cur_event =(MutationEventPtr) embedObject::UnWrap(info);
   char* property_name = (char*)embedObject::ToCString(property).c_str();

   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MutationEvent,relatedNode).c_str())==0 ){
        return cur_event->relatedNode->newInstance<NodePtr>();
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MutationEvent,prevValue).c_str())==0 ){
        return v8::String::New(cur_event->prevValue.c_str());
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MutationEvent,newValue).c_str())==0 ){
        return v8::String::New(cur_event->newValue.c_str());
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MutationEvent,attrName).c_str())==0 ){
        return v8::String::New(cur_event->attrName.c_str());
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MutationEvent,attrChange).c_str())==0 ){
        return v8::Uint32::New(cur_event->attrChange);
   }

}

void MutationEvent::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

}

void  MutationEvent::initMutationEvent(string &typeArg, 
                         bool canBubbleArg, 
                         bool cancelableArg, 
                         NodePtr relatedNodeArg, 
                         string &prevValueArg, 
                         string &newValueArg, 
                         string &attrNameArg, 
                         unsigned short attrChangeArg){
 
   this->initEvent(typeArg,canBubbleArg,cancelableArg);
   this->relatedNode = relatedNodeArg;
   this->prevValue = prevValueArg;
   this->newValue = newValueArg;
   this->attrName  = attrNameArg;
   this->attrChange = attrChangeArg;

}

v8::Handle<v8::Value> MutationEvent::initMutationEvent(const v8::Arguments& args){

   if(args.Length()>=8){

       MutationEventPtr cur_event =(MutationEventPtr) embedObject::UnWrap(args);
       Local<v8::Value> type_value = args[0];
       Local<v8::Value> bubbles_value= args[1];
       Local<v8::Value> cancelable_value = args[2];
       Local<v8::Value> relatedNode_value = args[3];
       Local<v8::Value> prevValue_value = args[4];
       Local<v8::Value> newValue_value = args[5];
       Local<v8::Value> attrName_value = args[6];
       Local<v8::Value> attrChange_value = args[7];


       if(type_value->IsString() && bubbles_value->IsBoolean() && cancelable_value->IsBoolean()){
           string type = embedObject::ToCString(type_value);
           bool bubbles = bubbles_value->BooleanValue();
           bool cancelable = cancelable_value->BooleanValue();
           NodePtr relatedNode  = (NodePtr)embedObject::UnWrap(relatedNode_value);
           string prevValue = embedObject::ToCString(prevValue_value);
           string newValue = embedObject::ToCString(newValue_value);
           string attrName = embedObject::ToCString(attrName_value);
           unsigned short attrChange = attrChange_value->Uint32Value();

           cur_event->initMutationEvent(type,bubbles,cancelable,relatedNode,prevValue,newValue,attrName,attrChange);
       }

   }
}



hash_map<string,string>& MutationEvent::listEventType(){

   if(MutationEvent::_type.size()==0){
        MutationEvent::initEventType();
   }   
   
   return MutationEvent::_type;

}

void MutationEvent::initEventType(){


}

