#pragma once
#include<map>
#include<string>
#include"ClassFile.h"
using namespace std;

class Instance
{
public:	
	ClassFile* class_file;
	Instance(ClassFile* class_file);
	void setField(string field, fieldType value);
	fieldType getField(string field);
	~Instance();
private:
	map<string, fieldType> fields;
};

