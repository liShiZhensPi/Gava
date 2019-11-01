#pragma once
#include"ClassFile.h"
#include"OpStack.h"
#include"LocalTable.h"
class StackFrame
{
private:
	u4 pc;
	u4 code_length;
	u1 *codes;
	OpStack *opstack;
	LocalTable *local_table;
public:
	StackFrame(u4 code_length,u1 *codes,u2 max_stack,u2 max_locals);
	u1 getCode();
	bool hasCode();
	void goto_(short shift);
	~StackFrame();
};

