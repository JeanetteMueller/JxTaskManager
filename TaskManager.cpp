
#include "Arduino.h"
#include "TaskManager.h"
#include "Task.h"



TaskManager::TaskManager() {
	_runningTask = 0;
};

void TaskManager::loop() {
	
	// Serial.println(F("TaskManager::loop"));
	
	if (_tasks[_runningTask]->getState() == Task::State::done){
	
		_runningTask++;
	}
	
	if (_runningTask > _taskCount - 1) {
		Serial.println(F("TaskManager::loop reset all"));
		
		for (uint8_t index = 0; index < _taskCount; index++){
			_tasks[index]->reset();
		}
		
		_runningTask = 0;
	}
	
	
	if (_tasks[_runningTask]->getState() == Task::State::none){
		// Serial.println(F("TaskManager::loop start new Task"));
		_tasks[_runningTask]->start();
	}
	if (_tasks[_runningTask]->getState() == Task::State::running){
		// Serial.println(F("TaskManager::loop loop current Task"));
		_tasks[_runningTask]->loop();
		
	} 
};

void TaskManager::addTask(Task *newTask) {

	_tasks[_taskCount] = newTask;
	_taskCount++;
};