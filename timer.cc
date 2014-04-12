
#include "timer.h"

vector<TimerPtr> Timer::_timers;
pthread_mutex_t Timer::_timers_metux;


Timer::Timer(long long int timeout,bool isInterval){
    _beginTime=Timer::getCurrentMilliSecond();
    _timeout=timeout;
    _isInterval=isInterval;

}




bool Timer::isTimeout(){
   long long int cur_millisecond = Timer::getCurrentMilliSecond();
   //printf("cur_millisecond[%lld],_beginTime[%lld],_timeout[%lld]\n",cur_millisecond,_beginTime,_timeout);
   if (cur_millisecond-_beginTime>=_timeout){
      _beginTime = cur_millisecond;
      return true;
   }else
      return false;

}

long long int Timer::getCurrentMilliSecond(){

   struct timeval cur_tv;
   struct timezone timezone;


   gettimeofday(&cur_tv,NULL);
   long long int cur_millisecond= cur_tv.tv_sec*1000+ cur_tv.tv_usec/1000;
   return cur_millisecond;
}


int Timer::getIndex(){
  return _index;
}
void Timer::setIndex(int index){
  _index=index;
}


void Timer::handle(long long int min_interval){

   pthread_mutex_init(&Timer::_timers_metux,NULL);
 
   fd_set rfds;
   struct timeval tv; 
   int retval;
  
   FD_ZERO(&rfds);
   FD_SET(0, &rfds);

   while(1 ){

     tv.tv_sec = 0;
     tv.tv_usec = min_interval*1000;
     retval = select(0, NULL, NULL, NULL, &tv);
     long long int cur_millisecond= Timer::getCurrentMilliSecond();
     //printf("beating [%lld],Timer::_timers.size()=%ld\n",cur_millisecond,Timer::_timers.size());

     pthread_mutex_lock(&Timer::_timers_metux);     

     vector<TimerPtr>::iterator itr = Timer::_timers.begin();
     while(itr!=Timer::_timers.end()){
       if((*itr)->isTimeout()){
          (*itr)->deal();
          if (!(*itr)->isInterval()){
              itr=Timer::_timers.erase(itr);
              continue;
          }
       }
       itr++;   
     }

     pthread_mutex_unlock(&Timer::_timers_metux);
   } 



}

void Timer::addTimer(TimerPtr timer){
   if(timer){
     pthread_mutex_lock(&Timer::_timers_metux);
     Timer::_timers.push_back(timer);
     pthread_mutex_unlock(&Timer::_timers_metux);
     timer->setIndex(Timer::_timers.size()-1);
   }
}
void Timer::delTimer(int index){
   pthread_mutex_lock(&Timer::_timers_metux);
   if(index < Timer::_timers.size()){

	   int i=0;
	   TimerPtr timer= Timer::_timers[index];
	   vector<TimerPtr>::iterator itr= Timer::_timers.begin();
	   while(itr!=Timer::_timers.end()){
	      if(i==timer->getIndex()){
		 itr=Timer::_timers.erase(itr);
                 delete timer;
		 return;
	      }
	      i++;
	      itr++;
	   }
   }
   pthread_mutex_unlock(&Timer::_timers_metux);
}

