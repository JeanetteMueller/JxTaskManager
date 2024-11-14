
#ifndef FuncTask_h
#define FuncTask_h

#include "Arduino.h"
#include "Task.h"
#include <functional>

class FuncTask : public Task
{
public:
	FuncTask(const std::function<Task::State(FuncTask *)> &function);
	void loop();
	uint16_t count = 0;
private:
	std::function<Task::State(FuncTask *)> _function;
};

using Func = std::function<Task::State(FuncTask *)>;

#endif
