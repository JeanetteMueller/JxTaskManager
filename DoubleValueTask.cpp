
#include "Arduino.h"
#include "DoubleValueTask.h"

DoubleValueTask::DoubleValueTask(double *value, double reactMinValue, double reactMaxValue, const bool debug)
{
	_value = value;
	_reactMinValue = reactMinValue;
	_reactMaxValue = reactMaxValue;

	if (reactMaxValue == -1)
	{
		_reactMaxValue = _reactMinValue;
	}

	_debug = debug;
};

void DoubleValueTask::loop()
{
	Task::loop();

	double currentValue = *_value;

	if (_debug == true)
	{
		Serial.print(F("Value "));
		Serial.print(currentValue);
		Serial.print(F(" == ("));
		Serial.print(_reactMinValue);
		Serial.print(F("-"));
		Serial.print(_reactMaxValue);
		Serial.println(F(")"));
	}

	if (currentValue >= _reactMinValue && currentValue <= _reactMaxValue)
	{
		_state = done;
	}
};