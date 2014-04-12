#ifndef TOUCH_LIST_H
#define TOUCH_LIST_H

#include "commonType.h"
#include "../embedObject.h"
#include "touch.h"

class TouchList;

typedef TouchList* TouchListPtr;

class TouchList:public embedObject{

public:
   TouchList();
   virtual ~TouchList();

public:
   long length;
private:
   vector<TouchPtr> _items;
   
public:
   void add(TouchPtr touch);
   TouchPtr item(unsigned long index);

public:
   v8::Handle<v8::ObjectTemplate> embed();

   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);
public:
   static  v8::Handle<v8::Value> item(const v8::Arguments& args);

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(length)

DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(item)

};

#endif
