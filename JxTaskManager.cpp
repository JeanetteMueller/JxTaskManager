
#include "Arduino.h"
#include "JxTaskManager.h"
#include "Task.h"

JxTaskManager::JxTaskManager()
{
	_runningTask = 0;
};

void JxTaskManager::loop()
{
	if (_tasks[_runningTask]->getState() == Task::State::done)
	{

		_runningTask++;
	}

	if (_runningTask > _taskCount - 1)
	{
		Serial.println(F("TaskManager::loop reset all"));

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
	_tasks[_taskCount] = newTask;
	_taskCount++;
};