#include "StackFrame.h"



StackFrame::StackFrame(ClassFile *classFile,string classFile_name,string method_name,string method_descriptor)
{

	pc = 0;
	Code_attribute*  code = classFile->getMethodByNameAndType(method_name, method_descriptor);
	this->classFile = classFile;
	this->method_name = method_name;
	this->method_descriptor = method_descriptor;
	this->classFile_name = classFile_name;
	this->code_length = code->code_length;
	this->codes = code->codes;
	this->opstack = new OpStack(code->max_stack);
	this->local_table = new LocalTable(code->max_locals);
}

void StackFrame::printStackFrame()
{
	cout << "class_name: " << classFile_name << endl;
	cout << "method_name: " << method_name << endl;
	cout << "method_descriptor: " << method_descriptor << endl;
	cout << "pc: " << pc << endl;
	cout << "code_length: " << code_length << endl;
	for (int i = 0; i < code_length; i++)
		printf("%02hhx\n", codes[i]);
	printOpStack();
	printLocals();
}

u1 StackFrame::getCode() {
	return codes[pc];
}

u1 StackFrame::getU1() {
	return codes[pc + 1];
}

u2 StackFrame::getU2() {
	translate_U2 u_2;
	u_2.U1[1] = codes[pc + 1];
	u_2.U1[0] = codes[pc + 2];
	return u_2.U2;
}

u4 StackFrame::getU4() {
	translate_U4 u_4;
	u_4.U1[3] = codes[pc + 1];
	u_4.U1[2] = codes[pc + 2];
	u_4.U1[1] = codes[pc + 3];
	u_4.U1[0] = codes[pc + 4];
	return u_4.U4;
}

bool StackFrame::hasCode() {
	if (pc >= code_length)
		return false;
	return true;
}

void StackFrame::goto_(short shift) {
	pc += shift;
}

void StackFrame::pushb(char value)
{
	stackType stack;
	stack.i = value;
	opstack->push(stack.a);
}
void StackFrame::pushs(short value)
{
	stackType stack;
	stack.i = value;
	opstack->push(stack.a);
}
void StackFrame::pushc(u2 value)
{
	stackType stack;
	stack.a = value;
	opstack->push(stack.a);
}
void StackFrame::pusha(u4 value)
{
	stackType stack;
	stack.a = value;
	opstack->push(stack.a);
}
void StackFrame::pushi(int value)
{
	stackType stack;
	stack.i = value;
	opstack->push(stack.a);
}
void StackFrame::pushl(long long value)
{
	stackType2 stack;
	stack.l = value;
	opstack->push(stack.U4[0]);
	opstack->push(stack.U4[1]);//注意顺序，在pop操作时相反
}
void StackFrame::pushf(float value)
{
	stackType stack;
	stack.f = value;
	opstack->push(stack.a);
}
void StackFrame::pushd(double value)
{
	stackType2 stack;
	stack.d = value;
	opstack->push(stack.U4[0]);
	opstack->push(stack.U4[1]);
}
char StackFrame::popb()
{
	stackType stack;
	stack.a = opstack->pop();
	return stack.i;
}
short StackFrame::pops()
{
	stackType stack;
	stack.a = opstack->pop();
	return stack.i;
}
u2 StackFrame::popc()
{
	stackType stack;
	stack.a = opstack->pop();
	return stack.a;
}
u4 StackFrame::popa()
{
	stackType stack;
	stack.a = opstack->pop();
	return stack.a;
}
int StackFrame::popi()
{
	stackType stack;
	stack.a = opstack->pop();
	return stack.i;
}
long long StackFrame::popl()
{
	stackType2 stack;
	stack.U4[1] = opstack->pop();
	stack.U4[0] = opstack->pop();
	return stack.l;
}
float StackFrame::popf()
{
	stackType stack;
	stack.a = opstack->pop();
	return stack.f;
}
double StackFrame::popd()
{
	stackType2 stack;
	stack.U4[1] = opstack->pop();
	stack.U4[0] = opstack->pop();
	return stack.d;
}
void StackFrame::storeb(u2 index, char value)
{
	stackType stack;
	stack.i = value;
	local_table->store(index, stack.a);
}
void StackFrame::storec(u2 index, u2 value)
{
	stackType stack;
	stack.a = value;
	local_table->store(index, stack.a);
}
void StackFrame::stores(u2 index, short value)
{
	stackType stack;
	stack.i = value;
	local_table->store(index, stack.a);
}
void StackFrame::storea(u2 index, u4 value)
{
	stackType stack;
	stack.a = value;
	local_table->store(index, stack.a);
}
void StackFrame::storei(u2 index, int value)
{
	stackType stack;
	stack.i = value;
	local_table->store(index, stack.a);
}
void StackFrame::storel(u2 index, long long value)
{
	stackType2 stack;
	stack.l = value;
	local_table->store(index, stack.U4[0]);
	local_table->store(index + 1, stack.U4[1]);
}
void StackFrame::storef(u2 index, float value)
{
	stackType stack;
	stack.f = value;
	local_table->store(index, stack.a);
}
void StackFrame::stored(u2 index, double value)
{
	stackType2 stack;
	stack.d = value;
	local_table->store(index, stack.U4[0]);
	local_table->store(index + 1, stack.U4[1]);
}
char StackFrame::loadb(u2 index)
{
	stackType stack;
	stack.a = local_table->load(index);
	return stack.i;
}
short StackFrame::loads(u2 index)
{
	stackType stack;
	stack.a = local_table->load(index);
	return stack.i;
}
u2 StackFrame::loadc(u2 index)
{
	stackType stack;
	stack.a = local_table->load(index);
	return stack.a;
}
u4 StackFrame::loada(u2 index)
{
	stackType stack;
	stack.a = local_table->load(index);
	return stack.a;
}
int StackFrame::loadi(u2 index)
{
	stackType stack;
	stack.a = local_table->load(index);
	return stack.i;
}
long long StackFrame::loadl(u2 index)
{
	stackType2 stack;
	stack.U4[0] = local_table->load(index);
	stack.U4[1] = local_table->load(index + 1);
	return stack.l;
}
float StackFrame::loadf(u2 index)
{
	stackType stack;
	stack.a = local_table->load(index);
	return stack.f;
}
double StackFrame::loadd(u2 index)
{
	stackType2 stack;
	stack.U4[0] = local_table->load(index);
	stack.U4[1] = local_table->load(index + 1);
	return stack.d;
}

void StackFrame::printOpStack() {
	opstack->print();
}
void StackFrame::printLocals()
{
	local_table->print();
}

StackFrame::~StackFrame()
{
}
