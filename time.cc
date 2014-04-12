
#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>


int main(int argc,char** argv){
 
   fd_set rfds;
   struct timeval tv;
   int retval;
  
   struct timeval cur_tv;
   struct timezone timezone;


   /* Watch stdin (fd 0) to see when it has input. */
   FD_ZERO(&rfds);
   FD_SET(0, &rfds);

   /* Wait up to five seconds. */
   while(1 ){

     tv.tv_sec = 0;
     tv.tv_usec = 50*1000;
     retval = select(0, NULL, NULL, NULL, &tv);
     gettimeofday(&cur_tv,NULL);
     long long int cur_millisecond= cur_tv.tv_sec*1000+ cur_tv.tv_usec/1000;
     printf("beating [%lld]\n",cur_millisecond);
     printf("beating tv_sec[%ld] tv_msec[%ld]\n",cur_tv.tv_sec,cur_tv.tv_usec/1000);
     /* Don't rely on the value of tv now! */
   }




  return 0;

}
