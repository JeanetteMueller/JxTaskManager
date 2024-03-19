
#ifndef WaitTask_h
#define WaitTask_h

#include "Arduino.h"
#include "Task.h"

class WaitTask: public Task {
	public:
		WaitTask(double minSeconds, double maxSeconds);
		WaitTask(double seconds);
		void loop();
	private:
		uint16_t _duration;
};

#endif
