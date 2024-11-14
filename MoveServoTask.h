
#ifndef MoveServoTask_h
#define MoveServoTask_h

#include "Arduino.h"
#include <Adafruit_PWMServoDriver.h>
#include "Task.h"

class MoveServoTask : public Task
{
public:
	MoveServoTask(Adafruit_PWMServoDriver *pwm, uint8_t pin, double startDegree, double targetDegree, double duration = 0, uint16_t wait = 0, const bool debug = false);
	void loop();
	void reset();

private:
	Adafruit_PWMServoDriver *_pwm;
	uint8_t _pin = 0;
	double _startDegree = 0;
	double _targetDegree = 0;
	double _currentDegree = 0;
	double _duration = 0;
	long _doneAnimation = 0;
	uint16_t _wait = 0;

	double easeInOutQuad(double t);
	double easeInAndOut(double start, double current, double target, double percentage);
};

#endif
