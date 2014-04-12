#ifndef TOUCH_H
#define TOUCH_H

#include "commonType.h"
#include "../embedObject.h"
#include "eventTarget.h"

class Touch;

typedef Touch* TouchPtr;

class Touch:public embedObject{

public:
   Touch();
   virtual ~Touch();
public:
   v8::Handle<v8::ObjectTemplate> embed();
   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
  long clientX;
  long clientY;
  unsigned long identifier;
  long pageX;
  long pageY;
  long screenX;
  long screenY;
  EventTargetPtr target;
public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(clientX)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(clientY)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(identifier)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(pageX)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(pageY)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(screenX)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(screenY)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(target)

};

#endif
