
#ifndef DoubleValueTask_h
#define DoubleValueTask_h

#include "Arduino.h"
#include "Task.h"

class DoubleValueTask : public Task
{
public:
	DoubleValueTask(double *value, double reactMinValue, double reactMaxValue = -1, const bool debug = false);
	void loop();

private:
	double *_value;
	double _reactMinValue;
	double _reactMaxValue;
	bool _debug;
};

#endif
