#include "OpStack.h"

OpStack::OpStack(u2 length)
{
	this->length = length;
	stack = new u4[length];
	index = 0;
}

void OpStack::push(u4 value) 
{
	if (index >= length) {
		cerr << "stack full" << endl;
		exit(-1);
	}
	stack[index++] = value;
}

void OpStack::print()
{
	cout << "OpstackLength: " <<index<< endl;
	for (int i = index - 1; i >= 0; i--)
		cout << stack[i] << endl;
}

u4 OpStack::pop() 
{
	if (index == 0) {
		cerr << "stack empty" << endl;
		exit(-1);
	}
	return stack[--index];
}

OpStack::~OpStack()
{
}
