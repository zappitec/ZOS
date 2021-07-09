#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "zos.h"
#include "tasks.h"

extern volatile int sw1;
extern volatile int sw2;
extern volatile int sw3;

ZOS_TASK_START(task_1)
    //declare local variables:
    static unsigned int counter;    
    //printf("Start from Task 1 -");
    //end local variables, Task initialization:
    ZOS_TASKINIT
    //initialize local variables if needed:
    counter = 0;
    
    while (counter++ < 10000000) {
        ZOS_YIELD;
    }
    printf("Task1 Block 0 executing\n");
    //block0           
   
    ZOS_WAITFOR(sw1)
   
    printf("Task1 cond 1 satisfied -");         
    printf("Task1 Block 1 executing\n");
    //block1

    ZOS_WAITFOR(sw2)
    
    printf("Task1 cond 2 satisfied -");    
    printf("Task1 Block 2 executing\n");
    //block2
    
    //printf("Returning from task 1 -");
    //ZOS_TASK_RETURN;  

ZOS_TASK_END


