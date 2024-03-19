
#ifndef PrintTask_h
#define PrintTask_h

#include "Arduino.h"
#include "Task.h"

class PrintTask: public Task {
	public:
		PrintTask(char *text);
		void loop();
	private:
		char *_text;
};

#endif
