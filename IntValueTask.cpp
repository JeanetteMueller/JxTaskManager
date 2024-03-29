
#include "Arduino.h"
#include "IntValueTask.h"

IntValueTask::IntValueTask(int16_t *value, int16_t reactMinValue, int16_t reactMaxValue, const bool debug)
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

void IntValueTask::loop()
{
	Task::loop();

	int16_t currentValue = *_value;

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