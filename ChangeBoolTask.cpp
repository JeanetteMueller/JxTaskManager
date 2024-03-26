
#include "Arduino.h"
#include "ChangeBoolTask.h"

ChangeBoolTask::ChangeBoolTask(bool *variable, const bool newValue, const bool debug) : _variable(variable)
{
	_newValue = newValue;
	_debug = debug;
};

void ChangeBoolTask::loop()
{
	Task::loop();

	if (_debug == true)
	{
		Serial.print(" - set new Value to: ");
		Serial.println(_newValue ? "new is true" : "new is false");
	}

	*_variable = _newValue;

	_state = done;
};
