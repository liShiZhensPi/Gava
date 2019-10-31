#pragma once
#include<string>
#include<stack>
#include"StackFrame.h"
#include"ClassFile.h"
using namespace std;
class Thread
{
public:
	Thread(string name,u1 *codes);
	~Thread();
private:
	string name;
	stack<StackFrame> VMStack;
};

