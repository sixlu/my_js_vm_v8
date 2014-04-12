#include "deviceOrientationEvent.h"

INIT_STATIC_JAVASCRIPTATTRI_NAME(DeviceOrientationEvent,alpha)
INIT_STATIC_JAVASCRIPTATTRI_NAME(DeviceOrientationEvent,beta)
INIT_STATIC_JAVASCRIPTATTRI_NAME(DeviceOrientationEvent,gamma)
INIT_STATIC_JAVASCRIPTATTRI_NAME(DeviceOrientationEvent,webkitCompassAccuracy)
INIT_STATIC_JAVASCRIPTATTRI_NAME(DeviceOrientationEvent,webkitCompassHeading)

INIT_STATIC_JAVASCRIPTFUNCTION_NAME(DeviceOrientationEvent,initDeviceOrientationEvent)


hash_map<string,string> DeviceOrientationEvent::_type;


DeviceOrientationEvent::DeviceOrientationEvent(){

  embed();
}

DeviceOrientationEvent::~DeviceOrientationEvent(){

}

void DeviceOrientationEvent::initDeviceOrientationEvent(string& type,
                      bool canBubble,
                      bool cancelable,
                      double alpha,
                      double beta,
                      double gamma,
                      double compassHeading,
                      double compassAccuracy
                      ){

   this->type =type;
   this->bubbles = canBubble;
   this->cancelable = cancelable;
   this->alpha = alpha;
   this->beta = beta;
   this->gamma = gamma;
   this->webkitCompassAccuracy = compassHeading;
   this->webkitCompassHeading = compassAccuracy; 

}

v8::Handle<v8::ObjectTemplate> DeviceOrientationEvent::embed(){

   if((*_templ)==NULL){ 
            _templ = ObjectTemplate::New();
            _templ->SetInternalFieldCount(1);
   }   
   
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(DeviceOrientationEvent,alpha).c_str()), DeviceOrientationEvent::GetProperty, DeviceOrientationEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(DeviceOrientationEvent,beta).c_str()), DeviceOrientationEvent::GetProperty, DeviceOrientationEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(DeviceOrientationEvent,gamma).c_str()), DeviceOrientationEvent::GetProperty, DeviceOrientationEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(DeviceOrientationEvent,webkitCompassAccuracy).c_str()), DeviceOrientationEvent::GetProperty, DeviceOrientationEvent::SetProperty);
   _templ->SetAccessor(String::New(JAVASCRIPT_ATTRNAME(DeviceOrientationEvent,webkitCompassHeading).c_str()), DeviceOrientationEvent::GetProperty, DeviceOrientationEvent::SetProperty);



   _templ->Set(v8::String::New(JAVASCRIPT_FUNCNAME(DeviceOrientationEvent,initDeviceOrientationEvent).c_str()), v8::FunctionTemplate::New(DeviceOrientationEvent::initDeviceOrientationEvent));


   return _templ;

}

Handle<Value> DeviceOrientationEvent::GetProperty(Local<String> property,const AccessorInfo &info){
   DeviceOrientationEventPtr cur_deviceorientationevent =(DeviceOrientationEventPtr) embedObject::UnWrap(info);
   char* property_name = (char*)embedObject::ToCString(property).c_str();

   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(DeviceOrientationEvent,alpha).c_str())==0 ){
        return v8::Number::New(cur_deviceorientationevent->alpha);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(DeviceOrientationEvent,beta).c_str())==0 ){
        return v8::Number::New(cur_deviceorientationevent->beta);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(DeviceOrientationEvent,gamma).c_str())==0 ){
        return v8::Number::New(cur_deviceorientationevent->gamma);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(DeviceOrientationEvent,webkitCompassAccuracy).c_str())==0 ){
        return v8::Number::New(cur_deviceorientationevent->webkitCompassAccuracy);
   }
   if (strcmp(property_name,JAVASCRIPT_ATTRNAME(DeviceOrientationEvent,webkitCompassHeading).c_str())==0 ){
        return v8::Number::New(cur_deviceorientationevent->webkitCompassHeading);
   }
  
}

void DeviceOrientationEvent::SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info){

}

v8::Handle<v8::Value> DeviceOrientationEvent::initDeviceOrientationEvent(const v8::Arguments& args){

     if(args.Length()>=18){

       DeviceOrientationEventPtr cur_event =(DeviceOrientationEventPtr) embedObject::UnWrap(args);
       int offset=0;
       Local<v8::Value> type_value = args[offset++];
       Local<v8::Value> bubbles_value= args[offset++];
       Local<v8::Value> cancelable_value = args[offset++];
       Local<v8::Value> alpha_value = args[offset++];
       Local<v8::Value> beta_value = args[offset++];
       Local<v8::Value> gamma_value = args[offset++];
       Local<v8::Value> webkitCompassAccuracy_value = args[offset++];
       Local<v8::Value> webkitCompassHeading_value = args[offset++];
       
       if(type_value->IsString() 
          && bubbles_value->IsBoolean() 
          && cancelable_value->IsBoolean()

          && alpha_value->IsNumber()
          && beta_value->IsNumber()
          && gamma_value->IsNumber()
          && webkitCompassAccuracy_value->IsNumber()
          && webkitCompassHeading_value->IsNumber()
          ){

           string type = embedObject::ToCString(type_value);
           bool bubbles = bubbles_value->BooleanValue();
           bool cancelable = cancelable_value->BooleanValue();
           void * view = NULL;
           double alpha = alpha_value->NumberValue(); 
           double beta = beta_value->NumberValue(); 
           double gamma = gamma_value->NumberValue(); 
           double webkitCompassAccuracy = webkitCompassAccuracy_value->NumberValue(); 
           double webkitCompassHeading = webkitCompassHeading_value->NumberValue(); 
           cur_event->initDeviceOrientationEvent(type,bubbles,cancelable,alpha,beta,gamma,webkitCompassAccuracy,webkitCompassHeading);

       }   

    }

}



hash_map<string,string>& DeviceOrientationEvent::listEventType(){

   if(DeviceOrientationEvent::_type.size()==0){
        DeviceOrientationEvent::initEventType();
   }   
   
   return DeviceOrientationEvent::_type;

}

void DeviceOrientationEvent::initEventType(){

   DeviceOrientationEvent::_type["orientationchange"]="onorientationchange";
   
   Event::_eventAttributeToType["onorientationchange"]="orientationchange";

}
