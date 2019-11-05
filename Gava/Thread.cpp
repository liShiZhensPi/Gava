#include "Thread.h"



Thread::Thread(ClassFile* classFile,string name)
{
	this->name = name;

	VMStack.push(new StackFrame(classFile, "main", "([Ljava/lang/String;)V"));
}

StackFrame* Thread::getStackFrame() {
	StackFrame* stack_frame = VMStack.top();
	VMStack.pop();
	return stack_frame;
}

Thread::~Thread()
{
}
