#include "jstimer.h"



JsTimer::JsTimer(long long int timeout,bool isInterval,Local<v8::Function> &func):Timer(timeout,isInterval){

    _func=Local<v8::Function>::Cast(func->Clone());
    //_func=func;
}


void JsTimer::deal(){
   printf("JsTimer::deal\n");    
   _func=Local<v8::Function>::Cast(_func->Clone());
   Local<Context> context= v8::Context::GetCurrent();
   _func->Call(context->Global(), 0, NULL);

}




JsTimerPtr JsTimer::New(long long int timeout,bool isInterval,Local<v8::Function> &func){

    JsTimerPtr jstimer= new JsTimer(timeout,isInterval,func);
    Timer::addTimer(jstimer);
    //Timer::_timers.push_back(jstimer);
    //jstimer.setIndex(Timer::_timers.size()-1);
    return jstimer;

}



