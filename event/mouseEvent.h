#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

#include "commonType.h"
#include "eventTarget.h"
#include "uievent.h"

class MouseEvent;

typedef MouseEvent* MouseEventPtr;

class MouseEvent:public UIEvent{

public:
   MouseEvent();
   virtual ~MouseEvent();

public:
   long             screenX;
   long             screenY;
   long             clientX;
   long             clientY;
   bool          ctrlKey;
   bool          shiftKey;
   bool          altKey;
   bool          metaKey;
   unsigned short   button;
   EventTargetPtr      relatedTarget;

public:
   
  v8::Handle<v8::ObjectTemplate> embed();
  void   initMouseEvent(string &typeArg, 
                                    bool canBubbleArg, 
                                    bool cancelableArg, 
                                    void* viewArg, 
                                    long detailArg, 
                                    long screenXArg, 
                                    long screenYArg, 
                                    long clientXArg, 
                                    long clientYArg, 
                                    bool ctrlKeyArg, 
                                    bool altKeyArg, 
                                    bool shiftKeyArg, 
                                    bool metaKeyArg, 
                                    unsigned short buttonArg, 
                                    EventTargetPtr relatedTargetArg);
public:
   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
  static hash_map<string,string> _type;
  static hash_map<string,string>&  listEventType();
private:
  static void initEventType();
public:
  static  v8::Handle<v8::Value> initMouseEvent(const v8::Arguments& args);
public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(screenX)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(screenY)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(clientX)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(clientY)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(ctrlKey)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(shiftKey)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(altKey)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(metaKey)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(button)
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(relatedTarget)

DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(initMouseEvent)


};




#endif
