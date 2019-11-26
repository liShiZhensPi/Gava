#pragma once
#include<string>
#include<stack>
#include"StackFrame.h"
#include"ClassFile.h"
using namespace std;
class Thread
{
public:
	stack<StackFrame*> VMStack;
	Thread(ClassFile *classFile,string class_name,string name);
	StackFrame* getStackFrame();
	void printThread();
	~Thread();
private:
	string name;
	
};

