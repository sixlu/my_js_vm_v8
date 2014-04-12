#ifndef UIEVENT_H
#define UIEVENT_H

#include "commonType.h"
#include "event.h"

class UIEvent;

typedef UIEvent* UIEventPtr;

class UIEvent:public Event{

public:
  UIEvent();
  virtual ~UIEvent();

  v8::Handle<v8::ObjectTemplate> embed();

public:
  void*  view;
  long  detail;

public:
  void  initUIEvent(string& typeArg,bool canBubbleArg,bool cancelableArg,void* viewArg,long detailArg);


public:
   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
  static hash_map<string,string> _type;
  static hash_map<string,string>& listEventType();
private:
  static void initEventType();

public:
  static v8::Handle<v8::Value> initUIEvent(const v8::Arguments& args);

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(view)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(detail)

DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(initUIEvent)

};


#endif
