
#include "Arduino.h"
#include "FuncTask.h"

FuncTask::FuncTask(const Func& function) {
	_function = function;

};

void FuncTask::loop() {

	Task::loop();

	_state = _function(this);

};

