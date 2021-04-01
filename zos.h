#ifndef ZOS_H
#define ZOS_H
//#include <stdio.h>
//#include <stdbool.h>

//Approach - goto (Labels as Values)

#define ZOSI_CONCAT(s1, s2) s1##s2
#define ZOSI_LABEL_(a) ZOSI_CONCAT(ZOS_LABEL_, a)
#define ZOSI_LABEL ZOSI_LABEL_(__LINE__)
#define ZOSI_PLACE_RETURN_POINT \
ZOSI_LABEL: \
zos_taskReturn = &&ZOSI_LABEL; \

#define ZOS_TASK_START(a) \
void a( void ) {\
static void * zos_taskReturn = NULL; \
static int zos_yielded = false;

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

typedef void (*menuFuncP_t)(void);
typedef struct {
    menuFuncP_t task;
    int active;
    int calling;
} zos_task_control_t;

#define ZOS_NBR_TASKS \
sizeof(zos_tasklist)/sizeof(zos_task_control_t)
#define ZOS_TASK(n) zos_tasklist[n].task()
#define ZOS_TASK_ON(n) zos_tasklist[n].active
#define ZOS_TASK_CALLING(n) zos_tasklist[n].calling    
#define ZOS_TASK_CALL(n) \
do { \
    ZOS_TASK_ON(SELF)=false;\
    ZOS_TASK_ON(n)=true;\
    ZOS_TASK_CALLING(n)=SELF; \
    ZOS_YIELD; \
} while(0);


#define ZOS_TASK_RETURN \
ZOS_TASK_ON(SELF)=false;\
if (zos_tasklist[SELF].calling >= 0) {\
ZOS_TASK_ON(zos_tasklist[SELF].calling)=true;\
}\
return;


#endif
