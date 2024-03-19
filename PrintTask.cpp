
#include "Arduino.h"
#include "PrintTask.h"

PrintTask::PrintTask(char *text) {
	_text = text;
	
};

void PrintTask::loop() {
	
	Task::loop();
	Serial.print(F("PrintTask::loop - "));
	Serial.println(_text);
	
	_state = done;

};

