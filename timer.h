#ifndef  V8_TIMER_H
#define  V8_TIMER_H

#include "common.h"
#include <string>
#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <vector>
#include <unistd.h>
#include <pthread.h>

using namespace v8;
using namespace std;


class Timer;

typedef Timer* TimerPtr;



class Timer{


public:
   Timer(){};
   Timer(long long int timeout,bool isInterval);


   bool isTimeout();
   bool isInterval(){return _isInterval;};

   virtual  void deal()=0;
   int getIndex();
   void setIndex(int index);

public:
   static void handle(long long int min_interval);
   static long long int getCurrentMilliSecond();
  
private:
   long long int _beginTime;
   long long int _timeout;
   bool _isInterval;
   int _index;

public:
   static void addTimer(TimerPtr timer);
   static void delTimer(int index);
private:
   static vector<TimerPtr> _timers;
   static pthread_mutex_t _timers_metux;
};


 

#endif
