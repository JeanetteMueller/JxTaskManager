
#ifndef Task_h
#define Task_h

#include "Arduino.h"

class Task {
	public:
		enum State { none, running, done };
		
		Task();
		State getState();
		virtual void start();
		virtual void loop();
		virtual void reset();
	protected:	
		State _state;
		long _startTimeStamp;
		long _runningDuration;
	private:
};

#endif

