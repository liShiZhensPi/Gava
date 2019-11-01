#include "Thread.h"



Thread::Thread(string name,Code_attribute *code)
{
	this->name = name;
	VMStack.push(new StackFrame(code->code_length, code->codes, code->max_stack, code->max_locals));
}

StackFrame* Thread::getStackFrame() {
	StackFrame* stack_frame = VMStack.top();
	VMStack.pop();
	return stack_frame;
}

Thread::~Thread()
{
}
