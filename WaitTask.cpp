
#include "Arduino.h"
#include "WaitTask.h"

WaitTask::WaitTask(double minSeconds, double maxSeconds, const bool debug) {
	_duration = random(minSeconds * 10, maxSeconds * 10) * 100;
	_debug = debug;
};

WaitTask::WaitTask(double seconds, const bool debug) {
	_duration = seconds * 1000;
	_debug = debug;
};

void WaitTask::loop() {
	Task::loop();
	// Serial.println(F("WaitTask::loop"));
	if (_runningDuration >= _duration)
	{
		if (_debug == true)
		{
			Serial.print(F("WaitTask waited "));
			Serial.println(_duration);
		}
		
		_state = done;
	}
};