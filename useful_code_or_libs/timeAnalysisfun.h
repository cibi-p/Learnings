#ifndef __TIMEANALYSISFUN
#define __TIMEANALYSISFUN

#include <sys/time.h> // For gettimeofday

struct tmAnalysis{
    struct timeval start;
    struct timeval end;
    long usedTm;
};

#define SEC_TO_MICRO_MULTIPLIER 1000000
typedef struct tmAnalysis TManalysis;

#define TM_SUCCESS 1
#define TM_FAIL    0
static int tm_startTimeAnalysis(TManalysis* time);
static int tm_calculateUsedTime(TManalysis* time);

static inline int tm_startTimeAnalysis(TManalysis* time) {
    if(time == NULL)
        return TM_FAIL;

    gettimeofday(&time->start, NULL);      
    return TM_SUCCESS;
}

static inline int tm_calculateUsedTime(TManalysis* time) {
    if(time == NULL)
        return TM_FAIL;

    gettimeofday(&time->end, NULL);
    long seconds = time->end.tv_sec - time->start.tv_sec;
    long microseconds = time->end.tv_usec - time->start.tv_usec;
    time->usedTm = (seconds * SEC_TO_MICRO_MULTIPLIER) + microseconds;
    return TM_SUCCESS;
}
#endif