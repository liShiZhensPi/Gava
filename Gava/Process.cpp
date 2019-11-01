#include "Process.h"



Process::Process(string mainClass,ClassFile *main)
{
	threads.push_back(new Thread("Main",main->getMethodByNameAndType("main", "([Ljava/lang/String;)V")));
	this->mainClass = mainClass;
	classFiles.insert(pair<string,ClassFile*>(mainClass,main));
}

Thread* Process::getMainThread() {
	return threads.back();
}

ClassFile* Process::getMainClass() {
	return classFiles.at(mainClass);
}

Process::~Process()
{
}
