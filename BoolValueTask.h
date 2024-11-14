
#ifndef BoolValueTask_h
#define BoolValueTask_h

#include "Arduino.h"
#include "Task.h"

class BoolValueTask : public Task
{
public:
	BoolValueTask(bool *value, bool reactValue, const bool debug = false);
	void loop();

private:
	bool *_value;
	bool _reactValue = false;
	bool _debug = false;
};

#endif
