#ifndef TIMEANALYSISFUN
#define TIMEANALYSISFUN

#include <sys/time.h> // For gettimeofday

struct tmAnalysis{
    struct timeval start;
    struct timeval end;
    long usedTm;
};

typedef struct tmAnalysis TManalysis;


void tm_startTimeAnalysis(TManalysis* time);
void tm_calculateUsedTime(TManalysis* time);

#endif