#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct timespec
{
 time_t tv_sec;
 long int tv_nsec;
};
int main(void)
{
   struct timespec time_start={0, 0},time_end={0, 0};
   clock_gettime(CLOCK_REALTIME, &time_start);
   printf("start time %llus,%llu ns\n", time_start.tv_sec, time_start.tv_nsec);
   clock_gettime(CLOCK_REALTIME, &time_end);
   printf("end   time %llus,%llu ns\n", time_end.tv_sec, time_end.tv_nsec);
   printf("duration:%llus %lluns\n", time_end.tv_sec-time_start.tv_sec, time_end.tv_nsec-time_start.tv_nsec);
   return 0;
}