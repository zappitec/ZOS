#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "zos.h"
#include "tasks.h"

extern volatile int sw1;
extern volatile int sw2;
extern volatile int sw3;

float time_from(float start) {
    return ((float)clock()-start)/CLOCKS_PER_SEC;
}

ZOS_TASK_START(task_0)
    //declare local variables:
    static float start;
    static float end;
    static int i;
    //end local variables, Task initialization:
    ZOS_TASKINIT
    //initialize local variables if needed:
    start = (float)clock();       
    //end initialization
    
    printf("Task0 - BLK0\n");
    //block0
    
    ZOS_WAITFOR(sw1)

    //printf("tsk0 cond 1 satisfied -");         
    printf("Task0 - BLK1\n");
    //block1              

    ZOS_WAITFOR(sw2)
 
    //printf("tsk0 cond 2 satisfied -");    
    printf("Task0 - BLK2\n");
    //block2

    start = (float)clock();    
    ZOS_WAITFOR(time_from(start)>1)
        
    printf("Task0: After wait\n");
    
    printf("Task0: Clock: %f\n",time_from(start)); 
    //printf("tsk0 cond 3 satisfied -");    
    printf("Task0 - BLK3\n");
    //block3


ZOS_TASK_END


