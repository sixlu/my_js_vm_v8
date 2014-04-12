#ifndef  V8_JSTIMER_H
#define  V8_JSTIMER_H

#include "timer.h"

using namespace v8;
using namespace std;

class JsTimer;

typedef JsTimer* JsTimerPtr;

class JsTimer:public Timer{

private:
   JsTimer(){};
   JsTimer(long long int timeout,bool isInterval,Local<v8::Function> &func);
public:
   
   virtual  void deal();
public:
   static JsTimerPtr New(long long int timeout,bool isInterval,Local<v8::Function> &func);
private:
  
   Local<v8::Function> _func;
};

#endif
