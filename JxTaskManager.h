
#ifndef JxTaskManager_h
#define JxTaskManager_h

#include "Arduino.h"
#include "Task.h"

#include "WaitTask.h"
#include "InputTask.h"
#include "PrintTask.h"
#include "MoveServoTask.h"
#include "FuncTask.h"
#include "ChangeBoolTask.h"
#include "IntValueTask.h"
#include "BoolValueTask.h"

class JxTaskManager
{
public:
    JxTaskManager();
    void loop();
    void addTask(Task *newTask);

private:
    Task *_tasks[50];
    uint8_t _taskCount;
    uint8_t _runningTask;
};

#endif
