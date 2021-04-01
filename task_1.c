#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "zos.h"
#include "tasks.h"

extern volatile int sw1;
extern volatile int sw2;
extern volatile int sw3;

ZOS_TASK_START(task_1)
    #define SELF TASK_1
    
    printf("Start from Task 1 -");
    ZOS_TASKINIT
    
    printf("Block 0 executing\n");
    //block0           
   
    ZOS_WAITFOR(sw1)
   
    printf("tsk1 cond 1 satisfied -");         
    printf("Block 1 executing\n");
    //block1

    ZOS_WAITFOR(sw2)
    
    printf("tsk1 cond 2 satisfied -");    
    printf("Block 2 executing\n");
    //block2
    
    printf("Returning from task 1 -");
    ZOS_TASK_RETURN;  

ZOS_TASK_END
#undef SELF

