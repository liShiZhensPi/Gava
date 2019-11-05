#pragma once
#include <vector>
#include <string>
#include"Thread.h"
#include<map>
#include"ClassFile.h"
#include"Instance.h"
#include"Arrays.h"
#include"error_exit.h"
using namespace std;


class Process
{
public:

	Process(string mainClass,ClassFile *main);
	ClassFile* getClassFile(string name);
	void putClassFile(string name, ClassFile* classFile);
	Thread* getMainThread();
	ClassFile* getMainClass();
	Arrays* getArrays();
	Instance* getInstance(u4 index);
	u4 newInstance(ClassFile *class_file);
	~Process();
private:
	vector<Thread*> threads;
	string mainClass;
	map<string, ClassFile*> classFiles;
	vector<Instance*> instances;
	stack<u4> unused_instances;
	Arrays *arrays;

};

