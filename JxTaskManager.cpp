
#include "Arduino.h"
#include "JxTaskManager.h"
#include "Task.h"

JxTaskManager::JxTaskManager(char *name, const bool debug)
{
  _debug = debug;
  _identifier = name;
  _runningTask = 0;
};

void JxTaskManager::loop()
{
  if (_debug)
  {
    Serial.print(F("TaskManager::loop \""));
    Serial.print(F(_identifier));
    Serial.println(F("\" "));
  }

  if (_tasks[_runningTask]->getState() == Task::State::done)
  {
    _runningTask++;
  }

  if (_runningTask > _taskCount - 1)
  {
    if (_debug)
    {
      Serial.print(F("TaskManager::loop \""));
      Serial.print(F(_identifier));
      Serial.println(F("\" reset all"));
    }
    for (uint8_t index = 0; index < _taskCount; index++)
    {
      _tasks[index]->reset();
    }

    _runningTask = 0;
  }

  if (_tasks[_runningTask]->getState() == Task::State::none)
  {
    _tasks[_runningTask]->start();
  }

  if (_tasks[_runningTask]->getState() == Task::State::running)
  {
    _tasks[_runningTask]->loop();
  }
};

void JxTaskManager::addTask(Task *newTask)
{
  if (_debug)
  {
    Serial.print("JxTaskManager::addTask \"");
    Serial.print(F(_identifier));
    Serial.print(F("\" "));
  }
  if (_taskCount < 50 - 1)
  {
    _tasks[_taskCount] = newTask;
    _taskCount++;

    if (_debug)
    {
      Serial.print(_taskCount);
      Serial.println(" Tasks saved");
    }
  }
  else
  {
    Serial.println("WARNING - Try to save more Tasks than possible");
  }
};