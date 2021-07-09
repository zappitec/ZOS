# ZOS
A very simple, portable, non-preemptive, minimalist task scheduler for resource-constrained embedded systems 

a Task is defined as follows:

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
    

//task ends with the following statement:

ZOS_TASK_END


