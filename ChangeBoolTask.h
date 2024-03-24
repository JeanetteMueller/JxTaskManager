
#ifndef ChangeBoolTask_h
#define ChangeBoolTask_h

#include "Arduino.h"
#include "Task.h"

class ChangeBoolTask: public Task {
	public:
		ChangeBoolTask(bool *variable, const bool newValue, const bool debug = false);
		void loop();
	private:
		bool* _variable;
		bool _newValue;
		bool _debug;
};

#endif
