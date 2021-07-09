#ifndef ZOS_H
#define ZOS_H
//#include <stdio.h>
//#include <stdbool.h>

//Approach - goto (Labels as Values)

//Global, only used during startup to enumerate tasks:
int zos_TaskCount;

#define ZOSI_CONCAT(s1, s2) s1##s2
#define ZOSI_LABEL_(a) ZOSI_CONCAT(ZOS_LABEL_, a)
#define ZOSI_LABEL ZOSI_LABEL_(__LINE__)
#define ZOSI_PLACE_RETURN_POINT \
ZOSI_LABEL: \
zos_taskReturn = &&ZOSI_LABEL; \

#define ZOS_TASK_START(a) \
void a( void ) {\
static void * zos_taskReturn = NULL; \
static int zos_yielded = false;\
static int zos_self = -1;\
if (zos_self == -1) {\
zos_self = zos_TaskCount++;\
printf("(I am task %d)\n",zos_self);\
}\
if (!ZOS_TASK_ON(zos_self))\
return;

#define ZOS_TASKINIT \
if (zos_taskReturn != NULL) \
goto *zos_taskReturn;

#define ZOS_TASK_END \
zos_taskReturn = NULL; \
return;}

#define ZOS_YIELD \
ZOSI_PLACE_RETURN_POINT \
if (! zos_yielded) {\
    zos_yielded = true; \
    return; \
} else { \
    zos_yielded = false; \
}

#define ZOS_WAITFOR(condition) \
do { \
    ZOSI_PLACE_RETURN_POINT \
    if(!(condition)) \
    return; \
} while(0);

//printf("Waiting Condition=( "#condition" )\n");\

//END #defines for BLOCK tasks
//used in task_3



#define ZOS_NBR_TASKS \
sizeof(zos_tasklist)/sizeof(zos_task_control_t)
#define ZOS_TASK(n) zos_tasklist[n].task()
#define ZOS_TASK_ON(n) zos_tasklist[n].active

#endif
