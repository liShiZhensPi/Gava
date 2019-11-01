#pragma once
#include"Process.h"
#include"Thread.h"
#include"StackFrame.h"
#include"Opcodes.h"
class ExecuteEngine
{
private:
	Process *currentProcess;
	Thread *currentThread;
	StackFrame *currentFrame;
	ClassFile *currentClass;


public:
	ExecuteEngine(Process *process);

	void execute();
	~ExecuteEngine();
};

