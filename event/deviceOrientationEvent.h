#ifndef DEVICE_ORIENTATION_EVENT_H
#define DEVICE_ORIENTATION_EVENT_H

#include "event.h"

class DeviceOrientationEvent;

typedef DeviceOrientationEvent* DeviceOrientationEventPtr;

class DeviceOrientationEvent:public Event{

public:
  DeviceOrientationEvent();
  virtual ~DeviceOrientationEvent();

public: 
  v8::Handle<v8::ObjectTemplate> embed();
public:
  void initDeviceOrientationEvent(string& type,
                      bool canBubble,
                      bool cancelable,
                      double alpha, 
                      double beta,
                      double gamma,
                      double compassHeading,
                      double compassAccuracy);

public:
  double alpha;
  double beta;
  double gamma;
  double webkitCompassAccuracy;
  double webkitCompassHeading;
 

public:
  static hash_map<string,string> _type;
  static hash_map<string,string>& listEventType();
private:
  static void initEventType();

public:
   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);
public:
   static  v8::Handle<v8::Value> initDeviceOrientationEvent(const v8::Arguments& args);

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(alpha)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(beta)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(gamma)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(webkitCompassAccuracy)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(webkitCompassHeading)
 

DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(initDeviceOrientationEvent)


};


#endif
