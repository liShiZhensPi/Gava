#include "Process.h"



Process::Process(string mainClass,ClassFile *main)
{
	threads.push_back(new Thread(main,"Main"));
	this->mainClass = mainClass;
	classFiles.insert(pair<string,ClassFile*>(mainClass,main));
	arrays = new Arrays();
}

ClassFile* Process::getClassFile(string name) 
{
	if (classFiles.find(name) == classFiles.end())//在此处实现类的加载
		exit_with_massage("找不到指定类: "+name);
	return classFiles.at(name);
}

void Process::putClassFile(string name, ClassFile* classFile)
{
	if (classFiles.find(name) == classFiles.end())
		classFiles.insert(pair<string, ClassFile*>(name, classFile));
}

Thread* Process::getMainThread() {
	return threads.back();
}

ClassFile* Process::getMainClass() {
	return classFiles.at(mainClass);
}

Arrays* Process::getArrays()
{
	return arrays;
}

Instance* Process::getInstance(u4 index)
{
	if (instances.at(index) == NULL) {
		cout << "instance not init" << endl;
		exit(-1);
	}
	return instances.at(index);
}

u4 Process::newInstance(ClassFile* class_file)
{
	if (!unused_instances.empty()) {
		u4 index = unused_instances.top();
		unused_instances.pop();
		instances.at(index) = new Instance(class_file);
		return index;
	}
	instances.push_back(new Instance(class_file));
	return instances.size()-1;
}

Process::~Process()
{
}
