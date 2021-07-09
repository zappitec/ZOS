#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "zos.h"
#include "tasks.h"

volatile int sw1=1;
volatile int sw2=1;
volatile int sw3=0;

volatile zos_task_control_t zos_tasklist[] = ZOS_TASK_CONTROL_INIT;

int main ( void ) {
    int taskn;
    printf("Main Start\n");
    printf("Number of Tasks:%d\n",ZOS_NBR_TASKS);
    while (1) {
        for (taskn=0;taskn<ZOS_NBR_TASKS;taskn++) {
            //if (ZOS_TASK_ON(taskn)) {
                ZOS_TASK(taskn);
            //}
        }
    }
}
