#include "eventTarget.h"
#include "event.h"
#include "mouseEvent.h"
#include "keyboardEvent.h"
#include "mutationevent.h"
#include "htmlFormEvent.h"
#include "htmlFrameOrObjectEvent.h"
#include "uievent.h"

unsigned short int EventTarget::_supportMouseEvent=0x01;
unsigned short int EventTarget::_supportKeyboardEvent=0x02;
unsigned short int EventTarget::_supportMutationEvent=0x04;
unsigned short int EventTarget::_supportHtmlFormEvent=0x08;
unsigned short int EventTarget::_supportHtmlFrameOrObjectEvent=0x10;
unsigned short int EventTarget::_supportUIEvent=0x20;
unsigned short int EventTarget::_supportAllEvent=0xff;




INIT_STATIC_JAVASCRIPTFUNCTION_NAME(EventTarget,addEventListener)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(EventTarget,removeEventListener)
INIT_STATIC_JAVASCRIPTFUNCTION_NAME(EventTarget,dispatchEvent)


EventTarget::EventTarget(unsigned short int supportEventType){

   _supportEventType = supportEventType;
   embed();
}

v8::Handle<v8::ObjectTemplate> EventTarget::embed(){

   if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
   }

   hash_map<string,string> eventType;
   hash_map<string,string>::iterator eventType_itr;
   //register event listener attribute
   if(_supportEventType & EventTarget::_supportMouseEvent){//支持mouse event

       eventType = MouseEvent::_type;//MouseEvent::listEventType();
       eventType_itr = eventType.begin();
       while(eventType_itr!= eventType.end()){
          _templ->SetAccessor(String::New(eventType_itr->second.c_str()), EventTarget::GetProperty, EventTarget::SetProperty);
          eventType_itr++;
       }

   }
   
   if(_supportEventType & EventTarget::_supportKeyboardEvent){//支持keyboard event

       eventType = KeyboardEvent::listEventType();
       eventType_itr = eventType.begin();
       while(eventType_itr!= eventType.end()){
          _templ->SetAccessor(String::New(eventType_itr->second.c_str()), EventTarget::GetProperty, EventTarget::SetProperty);
          eventType_itr++;
       }

   }
  
   if(_supportEventType & EventTarget::_supportMutationEvent){//支持Mutation event

       eventType = MutationEvent::listEventType();
       eventType_itr = eventType.begin();
       while(eventType_itr!= eventType.end()){
          _templ->SetAccessor(String::New(eventType_itr->second.c_str()), EventTarget::GetProperty, EventTarget::SetProperty);
          eventType_itr++;
       }

   }

   if(_supportEventType & EventTarget::_supportHtmlFormEvent){//支持HtmlForm event

       eventType = HtmlFormEvent::listEventType();
       eventType_itr = eventType.begin();
       while(eventType_itr!= eventType.end()){
          _templ->SetAccessor(String::New(eventType_itr->second.c_str()), EventTarget::GetProperty, EventTarget::SetProperty);
          eventType_itr++;
       }

   }

   if(_supportEventType & EventTarget::_supportHtmlFrameOrObjectEvent){//支持HtmlFrameOrObject event

       eventType = HtmlFrameOrObjectEvent::listEventType();
       eventType_itr = eventType.begin();
       while(eventType_itr!= eventType.end()){
          _templ->SetAccessor(String::New(eventType_itr->second.c_str()), EventTarget::GetProperty, EventTarget::SetProperty);
          eventType_itr++;
       }

   }

   if(_supportEventType & EventTarget::_supportUIEvent){//支持UI event

       eventType = UIEvent::listEventType();
       eventType_itr = eventType.begin();
       while(eventType_itr!= eventType.end()){
          _templ->SetAccessor(String::New(eventType_itr->second.c_str()), EventTarget::GetProperty, EventTarget::SetProperty);
          eventType_itr++;
       }

   }

   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(EventTarget,addEventListener).c_str()), v8::FunctionTemplate::New(EventTarget::addEventListener));
   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(EventTarget,removeEventListener).c_str()), v8::FunctionTemplate::New(EventTarget::removeEventListener));
   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(EventTarget,dispatchEvent).c_str()), v8::FunctionTemplate::New(EventTarget::dispatchEvent));


   return _templ;

  

}

void EventTarget::addEventListener(string &type,Handle<v8::Function> listener,bool useCapture){


       _eventListeners[type].push_back(listener);

}

void EventTarget::removeEventListener(string &type,Handle<v8::Function> listener,bool useCapture){

      
      if(_eventListeners[type].size()){
          deque<Handle<Function> >::iterator itr = _eventListeners[type].begin();
          while(itr!=_eventListeners[type].end()){
               Handle<v8::Function> cur_listener =(*itr);
               if(cur_listener->Equals(listener)){
                   _eventListeners[type].erase(itr);
                   break;
               }

               itr++;
          }
      }
}

bool EventTarget::dispatchEvent(void *evt) throw(EventException){
     EventPtr evt_ptr = (EventPtr)evt;
     this->dealEvent(evt_ptr);
     if(!evt_ptr->isStopPropagation()){
        this->dispatchEventToParent(evt_ptr); 
     }
     if(evt_ptr->isPreventDefault()){
        return false;
     }else{
        return true;
     }
     
}

void EventTarget::defaultAction(){

}

void EventTarget::dealEvent(void *eptr){
     EventPtr evt_ptr = (EventPtr)eptr;
     string type = evt_ptr->type;
     if(_eventListeners[type].size()){
          deque<Handle<Function> >::iterator itr = _eventListeners[type].begin();
          while(itr!=_eventListeners[type].end()){
               Handle<v8::Function> cur_listener =(*itr);
               Local<Context> context= v8::Context::GetCurrent();
               context->Global()->Set(v8::String::New("event"), evt_ptr->newInstance<EventPtr>());//把event的javascript object传到这个function的上下文
               Handle<Value> argv[1];
               argv[0]=evt_ptr->newInstance<EventPtr>();//把event的javascript object通过这个function的参数传进function里面
               cur_listener->Call(context->Global(), 0, argv);//执行javascript function
               itr++;
          }
     }
     if(!evt_ptr->isPreventDefault()){//执行默认动作，比如<a>请求链接地址页面
         this->defaultAction();
     }

}


v8::Handle<v8::Value> EventTarget::addEventListener(const v8::Arguments& args){
    if(args.Length()>=2){

        EventTargetPtr cur_eventTarget =(EventTargetPtr) embedObject::UnWrap(args);
        Local< Value > t = args[0];
        string type = embedObject::ToCString(t);
        Handle<v8::Value> callback = args[1];
        Handle<Value> handleEvent_function;
        if(callback->IsFunction()){//是javascript function

             handleEvent_function = callback;

        }else if(callback->IsObject()){//是带有handleEvent函数的javascript object

            //寻找这个对象的handleEven函数
            Handle<String> handleEvent_name = String::New("handleEvent");
            handleEvent_function = callback->ToObject()->Get(handleEvent_name);
            if(!handleEvent_function->IsFunction()){
               handleEvent_name = String::New("handleevent");
               handleEvent_function = callback->ToObject()->Get(handleEvent_name);

            }

        }

        if(handleEvent_function->IsFunction()){
            cur_eventTarget->addEventListener(type,Handle<Function>::Cast(handleEvent_function),false);
        }

    }

}

v8::Handle<v8::Value> EventTarget::removeEventListener(const v8::Arguments& args){
    if(args.Length()>=1){

        EventTargetPtr cur_eventTarget =(EventTargetPtr) embedObject::UnWrap(args);

        Local< Value > t = args[0];
        string type = embedObject::ToCString(t);
        Handle<v8::Value> callback = args[1];
        Handle<Value> handleEvent_function;
        if(callback->IsFunction()){//是javascript function

             handleEvent_function = callback;

        }else if(callback->IsObject()){//是带有handleEvent函数的javascript object

            //寻找这个对象的handleEven函数
            Handle<String> handleEvent_name = String::New("handleEvent");
            handleEvent_function = callback->ToObject()->Get(handleEvent_name);
            if(!handleEvent_function->IsFunction()){
               handleEvent_name = String::New("handleevent");
               handleEvent_function = callback->ToObject()->Get(handleEvent_name);

            }

        }

        if(handleEvent_function->IsFunction()){
            cur_eventTarget->removeEventListener(type,Handle<Function>::Cast(handleEvent_function),false);
        }

    }


    

}

v8::Handle<v8::Value> EventTarget::dispatchEvent(const v8::Arguments& args){
    if(args.Length()>=1){

        EventTargetPtr cur_eventTarget =(EventTargetPtr) embedObject::UnWrap(args);

        Local<Value> event= args[0];
        if(event->IsObject()){
            Handle<String> name = String::New("stopPropagation");
            Handle<Value> function = event->ToObject()->Get(name);
            if(!function->IsFunction()){
               name = String::New("stoppropagation");
               function = event->ToObject()->Get(name);

            }

            if(!function->IsFunction()){
                 EventPtr event_p = (EventPtr)embedObject::UnWrap(event);
                  cur_eventTarget->dispatchEvent(event_p);
            }
        }
    }
}




Handle<Value> EventTarget::GetProperty(Local<String> property,const AccessorInfo &info){
        
        
}

void EventTarget::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){
     
        EventTargetPtr cur_eventTarget =(EventTargetPtr) embedObject::UnWrap(info);

        string event_attribute = embedObject::ToCString(property);
        string type = Event::_eventAttributeToType[event_attribute];
        if(type.size()>0){
        
            Handle<v8::Value> callback = value;
            Handle<Value> handleEvent_function;
            if(callback->IsFunction()){//是javascript function

                 handleEvent_function = callback;

            }else if(callback->IsObject()){//是带有handleEvent函数的javascript object

                //寻找这个对象的handleEven函数
                Handle<String> handleEvent_name = String::New("handleEvent");
                handleEvent_function = callback->ToObject()->Get(handleEvent_name);
                if(!handleEvent_function->IsFunction()){
                   handleEvent_name = String::New("handleevent");
                   handleEvent_function = callback->ToObject()->Get(handleEvent_name);

                }

            }

            if(handleEvent_function->IsFunction()){
                cur_eventTarget->addEventListener(type,Handle<Function>::Cast(handleEvent_function),false);
            }

        }
}
