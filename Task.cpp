
#include "Arduino.h"
#include "Task.h"

Task::Task() {
  _state = none;
}


Task::State Task::getState() {
  return _state;
}

void Task::start() {
	_state = running;
	_runningDuration = 0;
	_startTimeStamp = millis();
}

void Task::loop() {
	// Serial.println(F("Task::loop"));
	_runningDuration = millis() - _startTimeStamp;
}

void Task::reset(){
	_state = none;
	_startTimeStamp = 0;
	_runningDuration = 0;
}
