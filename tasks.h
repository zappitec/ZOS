#ifndef TASKS_H
#define TASKS_H

#include "task_0.h"
#include "task_1.h"
#include "task_2.h"

typedef void (*menuFuncP_t)(void);
typedef struct {
    menuFuncP_t task;
    int active;
    //int calling;
} zos_task_control_t;

#define TASK_0 0
#define TASK_1 1
#define TASK_2 2

#define ZOS_TASK_CONTROL_INIT \
{\
    [TASK_0].task = task_0, [TASK_0].active = true,\
\
    [TASK_1].task = task_1, [TASK_1].active = true,\
\
    [TASK_2].task = task_2, [TASK_2].active = true,\
}

extern volatile zos_task_control_t zos_tasklist[];

#endif
