#include <stdio.h>
#include "timeAnalysisfun.h"
#include <unistd.h> 


void tm_startTimeAnalysis(TManalysis* time)
{
    gettimeofday(&time->start, NULL);      
    return;
}

void tm_calculateUsedTime(TManalysis* time)
{
    gettimeofday(&time->end, NULL);
    long seconds = time->end.tv_sec - time->start.tv_sec;
    long microseconds = time->end.tv_usec - time->start.tv_usec;
    time->usedTm = (seconds * 1000000) + microseconds;
    return;
}


