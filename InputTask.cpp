
#include "Arduino.h"
#include <IBusBM.h>
#include "InputTask.h"

InputTask::InputTask(IBusBM *iBus, uint8_t channelNumber, int16_t reactMinValue, int16_t reactMaxValue, const bool debug)
{
	_iBus = iBus;
	_channelNumber = channelNumber;
	_reactMinValue = reactMinValue;
	_reactMaxValue = reactMaxValue;

	if (reactMaxValue == -1)
	{
		_reactMaxValue = _reactMinValue;
	}

	_debug = debug;
};

void InputTask::loop()
{
	Task::loop();
	uint16_t value = _iBus->readChannel(_channelNumber);

	if (_debug == true)
	{
		Serial.print(F("Channel Nr. "));
		Serial.print(_channelNumber);
		Serial.print(F(" with Value "));
		Serial.print(value);
		Serial.print(F(" == ("));
		Serial.print(_reactMinValue);
		Serial.print(F("-"));
		Serial.print(_reactMaxValue);
		Serial.println(F(")"));
	}

	if (value >= _reactMinValue && value <= _reactMaxValue)
	{
		_state = done;
	}
};