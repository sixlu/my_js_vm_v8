#include "mouseEvent.h"

INIT_STATIC_JAVASCRIPTATTRI_NAME(MouseEvent,screenX)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MouseEvent,screenY)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MouseEvent,clientX)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MouseEvent,clientY)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MouseEvent,ctrlKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MouseEvent,shiftKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MouseEvent,altKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MouseEvent,metaKey)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MouseEvent,button)
INIT_STATIC_JAVASCRIPTATTRI_NAME(MouseEvent,relatedTarget)

INIT_STATIC_JAVASCRIPTFUNCTION_NAME(MouseEvent,initMouseEvent)



hash_map<string,string> MouseEvent::_type;

MouseEvent::MouseEvent(){

   embed();
}

MouseEvent::~MouseEvent(){


}

v8::Handle<v8::ObjectTemplate> MouseEvent::embed(){

   if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
   }   
   
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MouseEvent,screenX).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MouseEvent,screenY).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MouseEvent,clientX).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MouseEvent,clientY).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MouseEvent,ctrlKey).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MouseEvent,shiftKey).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MouseEvent,altKey).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MouseEvent,metaKey).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MouseEvent,button).c_str()), Event::GetProperty, Event::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(MouseEvent,relatedTarget).c_str()), Event::GetProperty, Event::SetProperty);


   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(MouseEvent,initMouseEvent).c_str()), v8::FunctionTemplate::New(MouseEvent::initMouseEvent));

 
   return _templ;

}

Handle<Value> MouseEvent::GetProperty(Local<String> property,const AccessorInfo &info){
   
   MouseEventPtr cur_event =(MouseEventPtr) embedObject::UnWrap(info);
   char* property_name = (char*)embedObject::ToCString(property).c_str();

   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MouseEvent,screenX).c_str())==0 ){
        return v8::Integer::New(cur_event->screenX);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MouseEvent,screenY).c_str())==0 ){
        return v8::Integer::New(cur_event->screenY);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MouseEvent,clientX).c_str())==0 ){
        return v8::Integer::New(cur_event->clientX);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MouseEvent,clientY).c_str())==0 ){
        return v8::Integer::New(cur_event->clientY);
   }

   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MouseEvent,ctrlKey).c_str())==0 ){
        return v8::Boolean::New(cur_event->ctrlKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MouseEvent,shiftKey).c_str())==0 ){
        return v8::Boolean::New(cur_event->shiftKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MouseEvent,altKey).c_str())==0 ){
        return v8::Boolean::New(cur_event->altKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MouseEvent,metaKey).c_str())==0 ){
        return v8::Boolean::New(cur_event->metaKey);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MouseEvent,button).c_str())==0 ){
        return v8::Integer::New(cur_event->button);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(MouseEvent,relatedTarget).c_str())==0 ){
        return cur_event->relatedTarget->newInstance<EventTargetPtr>();
   }



   
}

void MouseEvent::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

}

void MouseEvent::initMouseEvent(string &typeArg,
                           bool canBubbleArg,    
                           bool cancelableArg,    
                           void* viewArg,               
                           long detailArg, 
                           long screenXArg, 
                           long screenYArg, 
                           long clientXArg, 
                           long clientYArg, 
                           bool ctrlKeyArg,    
                           bool altKeyArg,    
                           bool shiftKeyArg,    
                           bool metaKeyArg,    
                           unsigned short buttonArg,
                           EventTargetPtr relatedTargetArg){
  
   this->initUIEvent(typeArg,canBubbleArg,cancelableArg,viewArg,detailArg);

   this->screenX=screenXArg;
   this->screenY=screenYArg;
   this->clientX=clientXArg;
   this->clientY=clientYArg;
   this->ctrlKey=ctrlKeyArg;
   this->shiftKey=shiftKeyArg;
   this->altKey=altKeyArg;
   this->metaKey=metaKeyArg;
   this->button=buttonArg;
   this->relatedTarget=relatedTargetArg;

}

v8::Handle<v8::Value> MouseEvent::initMouseEvent(const v8::Arguments& args){

   if(args.Length()>=3){

       MouseEventPtr cur_event =(MouseEventPtr) embedObject::UnWrap(args);
       Local<v8::Value> type_value = args[0];
       Local<v8::Value> bubbles_value= args[1];
       Local<v8::Value> cancelable_value = args[2];
       Local<v8::Value> view_value = args[3];
       Local<v8::Value> detail_value = args[4];
       Local<v8::Value> screenX_value=args[5];
       Local<v8::Value> screenY_value=args[6];
       Local<v8::Value> clientX_value=args[7];
       Local<v8::Value> clientY_value=args[8];
       Local<v8::Value> ctrlKey_value=args[9];
       Local<v8::Value> shiftKey_value=args[10];
       Local<v8::Value> altKey_value=args[11];
       Local<v8::Value> metaKey_value=args[12];
       Local<v8::Value> button_value=args[13];
       Local<v8::Value> relatedTarget_value=args[14];

       if(type_value->IsString() && bubbles_value->IsBoolean() && cancelable_value->IsBoolean()){
           string type = embedObject::ToCString(type_value);
           bool bubbles = bubbles_value->BooleanValue();
           bool cancelable = cancelable_value->BooleanValue();
           void * view = NULL;
           long detail = detail_value->IntegerValue();
           long screenX= screenX_value->IntegerValue();
           long screenY = screenY_value->IntegerValue();
           long clientX = clientX_value->IntegerValue();
           long clientY = clientY_value->IntegerValue();
           bool ctrlKey= ctrlKey_value->BooleanValue();
           bool shiftKey= shiftKey_value->BooleanValue();
           bool altKey= altKey_value->BooleanValue();
           bool metaKey= metaKey_value->BooleanValue();
           unsigned short button = button_value->Uint32Value();
           EventTargetPtr relatedTarget  = (EventTargetPtr)embedObject::UnWrap(relatedTarget_value);
 
           cur_event->initMouseEvent(type,bubbles,cancelable,view,detail,screenX,screenY,clientX,clientY,ctrlKey,shiftKey,altKey,metaKey,button,relatedTarget);

 
           


       }   

   }
}


hash_map<string,string>& MouseEvent::listEventType(){

   if(MouseEvent::_type.size()==0){
        MouseEvent::initEventType();
   }
   
   return MouseEvent::_type;

}

void MouseEvent::initEventType(){

   MouseEvent::_type["click"]="onclick";
   MouseEvent::_type["dblclick"]="ondblclick";
   MouseEvent::_type["mousedown"]="onmousedown";
   MouseEvent::_type["mouseup"]="onmouseup";
   MouseEvent::_type["mouseover"]="onmouseover";
   MouseEvent::_type["mousemove"]="onmousemove";
   MouseEvent::_type["mouseout"]="onmouseout";
   MouseEvent::_type["dragstart"]="ondragstart";
   MouseEvent::_type["drag"]="ondrag";
   MouseEvent::_type["dragenter"]="ondragenter";
   MouseEvent::_type["dragleave"]="ondragleave";
   MouseEvent::_type["dragover"]="ondragover";
   MouseEvent::_type["drop"]="ondrop";
   MouseEvent::_type["dragend"]="ondragend"; 


   Event::_eventAttributeToType["onclick"]="click";
   Event::_eventAttributeToType["ondblclick"]="dblclick";
   Event::_eventAttributeToType["onmousedown"]="mousedown";
   Event::_eventAttributeToType["onmouseup"]="mouseup";
   Event::_eventAttributeToType["onmouseover"]="mouseover";
   Event::_eventAttributeToType["onmousemove"]="mousemove";
   Event::_eventAttributeToType["onmouseout"]="mouseout";
   Event::_eventAttributeToType["ondragstart"]="dragstart";
   Event::_eventAttributeToType["ondrag"]="drag";
   Event::_eventAttributeToType["ondragenter"]="dragenter";
   Event::_eventAttributeToType["ondragleave"]="dragleave";
   Event::_eventAttributeToType["ondragover"]="dragover";
   Event::_eventAttributeToType["ondrop"]="drop";
   Event::_eventAttributeToType["ondragend"]="dragend"; 


}
