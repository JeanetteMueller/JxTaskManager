
#ifndef WaitTask_h
#define WaitTask_h

#include "Arduino.h"
#include "Task.h"

class WaitTask: public Task {
	public:
		WaitTask(double minSeconds, double maxSeconds, const bool debug = false);
		WaitTask(double seconds, const bool debug = false);
		void loop();
	private:
		uint16_t _duration;
		bool _debug;
};

#endif
