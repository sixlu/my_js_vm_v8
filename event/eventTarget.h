#ifndef EVENTTARGET_H
#define EVENTTARGET_H


#include "commonType.h"
#include "eventException.h"
#include "../embedObject.h"


class EventTarget;

typedef EventTarget* EventTargetPtr;

class EventTarget: public embedObject{

public:
  EventTarget(unsigned short int supportEventType);
  v8::Handle<v8::ObjectTemplate> embed(); 

public:
  static unsigned short int _supportMouseEvent;
  static unsigned short int _supportKeyboardEvent;
  static unsigned short int _supportMutationEvent;
  static unsigned short int _supportHtmlFormEvent;
  static unsigned short int _supportHtmlFrameOrObjectEvent;
  static unsigned short int _supportUIEvent;
  static unsigned short int _supportAllEvent;
  

private:
  hash_map<string,deque<Handle<v8::Function> > > _eventListeners;//监听队列
  unsigned short int _supportEventType; 

protected:
  virtual bool dispatchEventToParent(void * eptr)=0;
  virtual void defaultAction();
private:
  void dealEvent(void * eptr);

public:
  void addEventListener(string &type,Handle<v8::Function> listener,bool useCapture);
  void removeEventListener(string &type,Handle<v8::Function> listener,bool useCapture);
  bool dispatchEvent(void * evt) throw(EventException);

DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(addEventListener)
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(removeEventListener)
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(dispatchEvent)

public:

  static  v8::Handle<v8::Value> addEventListener(const v8::Arguments& args);
  static  v8::Handle<v8::Value> removeEventListener(const v8::Arguments& args);
  static  v8::Handle<v8::Value> dispatchEvent(const v8::Arguments& args);

public:
  static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
  static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);


};
#endif
