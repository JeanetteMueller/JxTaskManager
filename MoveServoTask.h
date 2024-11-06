
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
	uint8_t _pin;
	double _startDegree;
	double _targetDegree;
	double _currentDegree;
	double _duration;
	long _doneAnimation;
	uint16_t _wait;

	double easeInOutQuad(double t);
	double easeInAndOut(double start, double current, double target, double percentage);
};

#endif
