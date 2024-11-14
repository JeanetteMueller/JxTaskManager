
#ifndef IntValueTask_h
#define IntValueTask_h

#include "Arduino.h"
#include "Task.h"

class IntValueTask : public Task
{
public:
	IntValueTask(int16_t *value, int16_t reactMinValue, int16_t reactMaxValue = -1, const bool debug = false);
	void loop();

private:
	int16_t *_value = 0;
	int16_t _reactMinValue = 0;
	int16_t _reactMaxValue = 0;
	bool _debug = false;
};

#endif
