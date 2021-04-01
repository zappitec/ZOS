# ZOS
A very simple, portable, non-preemptive, minimalist task scheduler for resource-constrained embedded systems 

a Task is defined as follows:

#define SELF TASK_0

ZOS_TASK_START(task_0)

//declare local variables always as static variables:
    static float start;
    static float end;
    static int i;
    
    ZOS_TASKINIT
    
    // do something;
    // something else;

    //The following yields to the scheduler if condition is not met. It is like a conditional yield() instruction.    
    ZOS_WAITFOR(condition)
    
    //You can also call another task (no recursion). As soon as the other task returns with ZOS_TASK_RETURN it will 
    //come back to the   next instruction:
    ZOS_TASK_CALL(TASK_1);

//task ends with the following two statements:

ZOS_TASK_END

#undef SELF


