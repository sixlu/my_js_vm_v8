#ifndef MUTATION_EVENT_H
#define MUTATION_EVENT_H

#include "commonType.h"
#include "event.h"
#include "../node.h"

class MutationEvent;

typedef MutationEvent* MutationEventPtr;

class MutationEvent:public Event{


public:
  MutationEvent();
  virtual ~MutationEvent();
  v8::Handle<v8::ObjectTemplate> embed();

public:
  static const unsigned short      MODIFICATION;
  static const unsigned short      ADDITION;
  static const unsigned short      REMOVAL;

public:
  NodePtr       relatedNode;
  string        prevValue;
  string        newValue;
  string        attrName;
  unsigned short   attrChange;
  void   initMutationEvent(string &typeArg, 
                                       bool canBubbleArg, 
                                       bool cancelableArg, 
                                       NodePtr relatedNodeArg, 
                                       string &prevValueArg, 
                                       string &newValueArg, 
                                       string &attrNameArg, 
                                       unsigned short attrChangeArg);
public:
   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
  static hash_map<string,string> _type;
  static hash_map<string,string>& listEventType();
private:
  static void initEventType();

public:
  static v8::Handle<v8::Value> initMutationEvent(const v8::Arguments& args);

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(relatedNode)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(prevValue)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(newValue)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(attrName)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(attrChange)

DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(initMutationEvent)


};

#endif
