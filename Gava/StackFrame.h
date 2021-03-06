#pragma once
#include"ClassFile.h"
#include"OpStack.h"
#include"LocalTable.h"
#include"typeTranslate.h"
class StackFrame
{
private:
	u4 pc;
	u4 code_length;
	char *codes;
	OpStack *opstack;
	LocalTable *local_table;

	string classFile_name;
	string method_name;
	string method_descriptor;
public:
	ClassFile* classFile;
	StackFrame(ClassFile *classFile,string classFile_name,string method_name,string method_descriptor);

	void printStackFrame();

	void printOpStack();
	void printLocals();
	u1 getCode();
	u1 getU1();
	u2 getU2();
	u4 getU4();
	bool hasCode();
	void goto_(short shift);



	//8种数据类型  其中short 和 byte 在虚拟机中会转化为int存储；而 char（u2）会转化为引用类型（u4）存储
	void pushb(char value);
	void pushs(short value);
	void pushc(u2 value);
	void pusha(u4 value);
	void pushi(int value);
	void pushl(long long value);
	void pushf(float value);
	void pushd(double value);

	char popb();
	short pops();
	u2 popc();
	u4 popa();
	int popi();
	long long popl();
	float popf();
	double popd();

	void storeb(u2 index, char value);
	void storec(u2 index, u2 value);
	void stores(u2 index, short value);
	void storea(u2 index, u4 value);
	void storei(u2 index, int value);
	void storel(u2 index, long long value);
	void storef(u2 index, float value);
	void stored(u2 index, double value);


	char loadb(u2 index);
	short loads(u2 index);
	u2 loadc(u2 index);
	u4 loada(u2 index);
	int loadi(u2 index);
	long long loadl(u2 index);
	float loadf(u2 index);
	double loadd(u2 index);

	~StackFrame();
};

