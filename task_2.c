#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "zos.h"
#include "tasks.h"

extern volatile int sw1;
extern volatile int sw2;
extern volatile int sw3;

ZOS_TASK_START(task_2)

    static float start;
    static float end;
    //start = clock();
    //printf("Start from Task 2 -");
    ZOS_TASKINIT
        
    printf("Task2 BLK0 executing\n");
    //block0
    start = (float)clock(); 
    ZOS_WAITFOR(sw1)
    
    //printf("tsk2 cond 1 satisfied -");         
    printf("Task2 BLK1 executing\n");
    //block1

    ZOS_WAITFOR(sw2)
    
    //printf("tsk2 cond 2 satisfied -");    
    printf("Task2 BLK2 executing\n");
    //block2        

    ZOS_WAITFOR(time_from(start)>0.9)

    printf("Clock: task2 %f\n",time_from(start));    
    //printf("tsk2 cond 3 satisfied -");    
    //printf("Clock:%f\n",clock());
    //block3

ZOS_TASK_END


