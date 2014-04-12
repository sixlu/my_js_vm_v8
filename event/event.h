#ifndef EVENT_H
#define EVENT_H

#include "commonType.h"
#include "eventTarget.h"
#include "../embedObject.h"

class Event;

typedef Event* EventPtr;


class Event:public embedObject{

public:
  Event();
  virtual ~Event();

  // PhaseType
public:
  static const unsigned short      CAPTURING_PHASE;//=1;
  static const unsigned short      AT_TARGET;//=2;
  static const unsigned short      BUBBLING_PHASE;//=3;

public:
  string type;
  EventTargetPtr      target;
  EventTargetPtr      currentTarget;
  unsigned short   eventPhase;
  bool          bubbles;
  bool          cancelable;
  DOMTimeStamp     timeStamp;

private:
  bool _isPreventDefault;
  bool _isStopPropagation;

public:
   v8::Handle<v8::ObjectTemplate> embed();


public:
  void  stopPropagation();
  void  preventDefault();
  bool  isPreventDefault();
  bool  isStopPropagation();
  void  initEvent(string &eventTypeArg,bool canBubbleArg,bool cancelableArg);

public:
   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
  static  v8::Handle<v8::Value> stopPropagation(const v8::Arguments& args);
  static  v8::Handle<v8::Value> preventDefault(const v8::Arguments& args);
  static  v8::Handle<v8::Value> initEvent(const v8::Arguments& args);

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(type)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(target)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(currentTarget)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(eventPhase)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(bubbles)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(cancelable)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(timeStamp)

DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(stopPropagation)
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(preventDefault)
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(initEvent)

public:
   static hash_map<string,string> _eventAttributeToType;

};

#endif
