#include "Instance.h"



Instance::Instance(ClassFile* class_file)
{
	this->class_file = class_file;
	for (int i = 0; i < class_file->fields_count; i++) {
		if ((class_file->fields[i].access_flags & Flags::JVM_ACC_STATIC) == 0) {
			string name = class_file->constant_pools[class_file->fields[i].name_index].utf8_info.bytes;//获取属性的name
			fieldType a;
			a.l = 0;//初始化为0   float和double暂不考虑
			fields.insert(pair<string,fieldType>(name,a));
		}
	}
}

void Instance::setField(string field, fieldType value)
{
	if (fields.find(field) == fields.end())
	{
		cout << "can't find field" << endl;
		exit(-1);
	}
	fields[field] = value;
}

fieldType Instance::getField(string field)
{
	if (fields.find(field) == fields.end())
	{
		cout << "can't find field" << endl;
		exit(-1);
	}
	return fields[field];
}

Instance::~Instance()
{
}
