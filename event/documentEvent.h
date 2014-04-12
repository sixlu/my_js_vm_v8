#ifndef DOCUMENT_EVENT_H
#define DOCUMENT_EVENT_H

#include "commonType.h"
//#include "eventException.h"
#include "uievent.h"
#include "mouseEvent.h"
#include "mutationevent.h"
#include "touchEvent.h"
#include "gestureEvent.h"
#include "deviceOrientationEvent.h"
#include "../embedObject.h"

class DocumentEvent:public embedObject{

public:
   static hash_map<string,int> _supportEventModule;
   static void initSupportEventModule();
    

public:
   DocumentEvent();
   virtual ~DocumentEvent();
public:
   v8::Handle<v8::ObjectTemplate> embed();
//public:
//   EventPtr createEvent(string &eventType) throw(DOMException);
public:
  static  v8::Handle<v8::Value> createEvent(const v8::Arguments& args);
public:
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(createEvent)
};

#endif



