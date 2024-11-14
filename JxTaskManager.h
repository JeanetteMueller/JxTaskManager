
#ifndef JxTaskManager_h
#define JxTaskManager_h

#include "Arduino.h"

#include <functional>

#include "Task.h"

#include "WaitTask.h"
#include "InputTask.h"
#include "PrintTask.h"
#include "MoveServoTask.h"
#include "FuncTask.h"
#include "ChangeBoolTask.h"
#include "IntValueTask.h"
#include "DoubleValueTask.h"
#include "BoolValueTask.h"

class JxTaskManager {
public:
  JxTaskManager(char *name, const bool debug = false);
  void loop();
  void addTask(Task *newTask);

private:
  bool _debug = false;
  char *_identifier = "DEFAULT";
  Task *_tasks[50];
  uint8_t _taskCount = 0;
  uint8_t _runningTask = 0;
};

#endif
