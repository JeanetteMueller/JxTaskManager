
#ifndef InputTask_h
#define InputTask_h

#include "Arduino.h"
#include <IBusBM.h>
#include "Task.h"

class InputTask : public Task
{
public:
	InputTask(IBusBM *iBus, uint8_t channelNumber, int16_t reactMinValue, int16_t reactMaxValue = -1, const bool debug = false);
	void loop();

private:
	IBusBM *_iBus;
	uint8_t _channelNumber = 0;
	uint16_t _reactMinValue = 0;
	uint16_t _reactMaxValue = 0;
	bool _debug = false;
};

#endif
