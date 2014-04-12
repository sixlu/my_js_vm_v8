#ifndef TOUCH_EVENT_H
#define TOUCH_EVENT_H

#include "uievent.h"
#include "touchList.h"

class TouchEvent;

typedef TouchEvent* TouchEventPtr;

class TouchEvent:public UIEvent{

public:
  TouchEvent();
  virtual ~TouchEvent();

public: 
  v8::Handle<v8::ObjectTemplate> embed();
public:
  void initTouchEvent(string& type,
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
                      TouchListPtr touches, 
                      TouchListPtr targetTouches, 
                      TouchListPtr changedTouches, 
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
   static  v8::Handle<v8::Value> initTouchEvent(const v8::Arguments& args);

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(altKey)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(ctrlKey)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(metaKey)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(shiftKey)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(changedTouches)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(targetTouches)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(touches)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(rotation)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(scale)

DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(initTouchEvent)


};


#endif
