#pragma once
#include <vector>
#include <string>
#include"Thread.h"
#include<map>
#include"ClassFile.h"
#include"Instance.h"
using namespace std;
class Process
{
public:

	Process(string mainClass,ClassFile *main);
	Thread* getMainThread();
	ClassFile* getMainClass();
	~Process();
private:
	vector<Thread*> threads;
	string mainClass;
	map<string, ClassFile*> classFiles;
	vector<Instance*> instances;
};

