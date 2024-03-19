
#ifndef TaskManager_h
#define TaskManager_h

#include "Arduino.h"
#include "Task.h"

#include "WaitTask.h"
#include "InputTask.h"
#include "PrintTask.h"
#include "MoveServoTask.h"
#include "FuncTask.h"

class TaskManager {
  public:
    TaskManager();
	void loop();
    void addTask(Task *newTask);
  private:
    Task * _tasks[50];
	uint8_t _taskCount;
	uint8_t _runningTask;
};

#endif

