#include "Process.h"



Process::Process(string mainClass,ClassFile *main,string class_path)
{
	this->class_path = class_path;
	threads.push_back(new Thread(main,mainClass,"Main"));
	this->mainClass = mainClass;
	classFiles.insert(pair<string,ClassFile*>(mainClass,main));
	arrays = new Arrays();
}

ClassFile* Process::getClassFile(string name) 
{
	if (classFiles.find(name) == classFiles.end())//在此处实现类的加载
	{
		classFiles.insert(pair<string, ClassFile*>(name, new ClassFile(name,class_path)));
	}
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

u4 Process::newInstance(string class_name,ClassFile* class_file)
{
	if (!unused_instances.empty()) {
		u4 index = unused_instances.top();
		unused_instances.pop();
		instances.at(index) = new Instance(class_name,class_file);
		return index;
	}
	instances.push_back(new Instance(class_name,class_file));
	return instances.size()-1;
}

void Process::printProcess()
{
	printClassFiles();
	printInstances();
	printArrays();
	printThreads();
}

void Process::printClassFiles() {
	cout << "ClassFiles: " << endl;
	cout << "ClassFile_count: " << classFiles.size() << endl;
	map<string, ClassFile*>::iterator iter;
	for (iter = classFiles.begin(); iter != classFiles.end(); iter++) {
		cout << iter->first << endl;
		iter->second->printClassFile();
	}
}
void Process::printInstances() {
	cout<<"instances: " << endl;
	cout << "isntance_count: " << instances.size() << endl;
	for (int i = 0; i < instances.size(); i++) {

		instances.at(i)->printInstance();
	}
	cout << "unused: " << unused_instances.size()<<endl;
	stack<u4> unused;
	while (!unused_instances.empty()) {
		unused.push(unused_instances.top());
		unused_instances.pop();
	}
	while (!unused.empty()) {
		cout << unused.top() << endl;
		unused_instances.push(unused.top());
		unused.pop();
	}
	
}

void Process::printArrays() {
	cout << "Arrays: " << endl;
	arrays->printArrays();
}

void Process::printThreads() {
	cout << "Threads: " << endl;
	cout << "thread_count: " << threads.size() << endl;
	for (int i = 0; i < threads.size(); i++)
		threads.at(i)->printThread();
}

Process::~Process()
{
}
