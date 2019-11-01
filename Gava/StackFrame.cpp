#include "StackFrame.h"



StackFrame::StackFrame(u4 code_length,u1 *codes,u2 max_stack,u2 max_locals)
{
	pc = 0;
	this->code_length = code_length;
	this->codes = codes;
	this->opstack = new OpStack(max_stack);
	this->local_table = new LocalTable(max_locals);
}

u1 StackFrame::getCode() {
	return codes[pc];
}

bool StackFrame::hasCode() {
	if (pc >= code_length)
		return false;
	return true;
}

void StackFrame::goto_(short shift) {
	pc += shift;
}
StackFrame::~StackFrame()
{
}
