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
	Arrays* getArrays();//Arrays 的层次有点不协调，待改进
	Instance* getInstance(u4 index);
	u4 newInstance(string class_name,ClassFile *class_file);

	void printProcess();
	~Process();
private:
	vector<Thread*> threads;
	string mainClass;
	map<string, ClassFile*> classFiles;
	vector<Instance*> instances;
	stack<u4> unused_instances;
	Arrays *arrays;

	void printClassFiles();
	void printInstances();
	void printArrays();
	void printThreads();

};

