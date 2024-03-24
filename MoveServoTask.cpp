
#include "Arduino.h"
#include "MoveServoTask.h"
#include <Adafruit_PWMServoDriver.h>

MoveServoTask::MoveServoTask(Adafruit_PWMServoDriver pwm, uint8_t pin, double startDegree, double targetDegree, double duration, uint16_t wait)
{
	_pwm = pwm;
	_pin = pin;
	_startDegree = startDegree;
	_currentDegree = startDegree;
	_targetDegree = targetDegree;

	if (duration == 0)
	{
		if (startDegree < targetDegree)
		{
			duration = (targetDegree - startDegree) * 10;
		}
		else 
		{
			duration = (startDegree - targetDegree) * 10;
		}
		
	}

	_duration = duration;
	_doneAnimation = 0;
	_wait = wait;
}
void MoveServoTask::reset() {
	Task::reset();
	
	_doneAnimation = 0;
}

void MoveServoTask::loop()
{
	Task::loop();
	
	if (_doneAnimation == 0) {
		if (_duration > 0) {
			double percentage = _runningDuration / _duration;
			
			_currentDegree = easeInAndOut(_startDegree, _currentDegree, _targetDegree, percentage);
			
			uint16_t pulselength = map(_currentDegree, 0, 180, 150, 595);
			_pwm.setPWM(_pin, 0, pulselength);
			
			if (percentage >= 1.0) {
				_doneAnimation = _runningDuration;
			}
		}else{
			uint16_t pulselength = map(_targetDegree, 0, 180, 150, 595);
			_pwm.setPWM(_pin, 0, pulselength);
			
			_doneAnimation = _runningDuration;
		}
	} else if (_runningDuration - _doneAnimation >= _wait) {
		_state = done;
	}
}

double MoveServoTask::easeInOutQuad(double t)
{
	return t < 0.5 ? 2 * t * t : t * (4 - 2 * t) - 1;
}

double MoveServoTask::easeInAndOut(double start, double current, double target, double percentage)
{
	double result = target;

	if (current != target)
	{
		double easeInOut = easeInOutQuad(percentage);

		if (start < target)
		{
			double subTarget = (target - start);

			result = start + (subTarget * easeInOut);

			if (result > target)
			{
				result = target;
			}
		}
		else if (start > target)
		{
			double subTarget = (start - target);

			result = start - (subTarget * easeInOut);

			if (result < target)
			{
				result = target;
			}
		}
	}

	return result;
}