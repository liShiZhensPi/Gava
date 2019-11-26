#pragma once
#include"Process.h"
#include"Thread.h"
#include"StackFrame.h"
#include"Opcodes.h"
#include"error_exit.h"
class ExecuteEngine
{
private:
	Process *currentProcess;
	Thread *currentThread;
	StackFrame *currentFrame;
	//ClassFile *currentClass;
	Arrays* arrays;

public:
	ExecuteEngine(Process *process);

	void execute(bool  isVisualized);
	~ExecuteEngine();
};

