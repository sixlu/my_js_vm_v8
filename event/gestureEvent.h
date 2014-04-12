#ifndef GESTURE_EVENT_H
#define GESTURE_EVENT_H

#include "uievent.h"
#include "eventTarget.h"
#include "touchList.h"

class GestureEvent;

typedef GestureEvent* GestureEventPtr;

class GestureEvent:public UIEvent{

public:
  GestureEvent();
  virtual ~GestureEvent();

public: 
  v8::Handle<v8::ObjectTemplate> embed();
public:
  void initGestureEvent(string& type,
                      bool canBubble,
                      bool cancelable,
                      void* view, 
                      long detail, 
                      long screenX, 
                      long screenY,
                      long clientX, 
                      long clientY,
                      bool ctrlKey,
                      bool altKey,
                      bool shiftKey,
                      bool metaKey,
                      EventTargetPtr target,
                      float scale, 
                      float rotation);

public:
   bool altKey;
   bool ctrlKey;
   bool metaKey;
   bool shiftKey;
   TouchListPtr changedTouches;
   TouchListPtr targetTouches;
   TouchListPtr touches;
   float rotation;
   float scale;

public:
  static hash_map<string,string> _type;
  static hash_map<string,string>& listEventType();
private:
  static void initEventType();

public:
   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);
public:
   static  v8::Handle<v8::Value> initGestureEvent(const v8::Arguments& args);

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(altKey)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(ctrlKey)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(metaKey)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(shiftKey)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(target)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(rotation)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(scale)

DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(initGestureEvent)


};


#endif
