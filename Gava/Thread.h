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
	Thread(ClassFile *classFile,string name);
	StackFrame* getStackFrame();
	~Thread();
private:
	string name;
	
};

