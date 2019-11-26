#include "Thread.h"



Thread::Thread(ClassFile* classFile,string class_name,string name)
{
	this->name = name;

	VMStack.push(new StackFrame(classFile,class_name, "main", "([Ljava/lang/String;)V"));
}

StackFrame* Thread::getStackFrame() {
	StackFrame* stack_frame = VMStack.top();
	//VMStack.pop();
	return stack_frame;
}

void Thread::printThread()
{
	cout << "thread_name: " << name << endl;
	cout << "VMStack: " << VMStack.size() << endl;
	stack<StackFrame*> vm;
	while (!VMStack.empty()) {
		VMStack.top()->printStackFrame();
		vm.push(VMStack.top());
		VMStack.pop();
	}

	while (!vm.empty()) {
		VMStack.push(vm.top());
		vm.pop();
	}
	
}

Thread::~Thread()
{
}
