#pragma once
#include"ClassFile.h"
class OpStack
{
private:
	u4 *stack;
	u2 length;
	u2 index;
public:
	OpStack(u2 length);
	u4 pop();
	void push(u4 value);
	void print();
	~OpStack();
};

