
#include "Arduino.h"
#include "WaitTask.h"

WaitTask::WaitTask(double minSeconds, double maxSeconds) {
	_duration = random(minSeconds * 10, maxSeconds * 10) * 100;
	
};
WaitTask::WaitTask(double seconds) {
	_duration = seconds * 1000;
	
};

void WaitTask::loop() {
	Task::loop();
	// Serial.println(F("WaitTask::loop"));
	if (_runningDuration >= _duration) {
		
		Serial.print(F("WaitTask waited "));
		Serial.println(_duration);
		
		_state = done;
	}

};