
#include "Arduino.h"
#include "BoolValueTask.h"

BoolValueTask::BoolValueTask(bool *value, bool reactValue, const bool debug)
{
	_value = value;
	_reactValue = reactValue;
	_debug = debug;
};

void BoolValueTask::loop()
{
	Task::loop();

	bool currentValue = *_value;

	if (_debug == true)
	{
		Serial.print(F("Value "));
		Serial.print(currentValue == true ? "true" : "false");
		Serial.print(F(" == "));
		Serial.println(_reactValue == true ? "true" : "false");
	}

	if (currentValue == _reactValue)
	{
		_state = done;
	}
};