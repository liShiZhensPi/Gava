#pragma once
#include<cstring>
#include<iostream>
#include<fstream>
#include<map>
#include"classfile_typedef.h"
#include"classfile_constants.h"

using namespace std;


class ClassFile
{
public:
	u4 magic;
	u2 minor_version;
	u2 major_version;
	u2 constant_pool_count;
	CpInfo* constant_pools;
	u2 access_flags;
	u2 this_class;
	u2 super_class;
	u2 interfaces_count;
	InterfacesInfo* interfaces;
	u2 fields_count;
	FieldInfo* fields;
	u2 methods_count;
	MethodInfo* methods;
	u2 attributes_count;
	AttributeInfo* attributes;

	ClassFile(string filename);
	/*int constant_utf8_equal(char* s, u2 length, string str);*/
	Code_attribute* getMethodByNameAndType(string name,string type);
	fieldType getField(string name);
	void setField(string name, fieldType value);
	~ClassFile();
private:
	map<string, fieldType> static_fields;
	void init_static_fields();
	fstream f;
	u1 getU1();
	u2 getU2();
	u4 getU4();
	
	
	void parseFile();
	void parseConstantPools();
	void parseInterfaces();
	void parseFields();
	void parseMethods();
	void parseAttributes();
};

