#include "ClassFile.h"



ClassFile::ClassFile(string filename)
{
	f.open(filename, ios::in | ios::binary);
	if (!f)
	{
		cout << "Can't open file " << endl;
		exit(-1);
		return;
	}
	parseFile();
}

void ClassFile::parseFile(){
	magic = getU4();
	minor_version = getU2();
	major_version = getU2();
	parseConstantPools();
	access_flags = getU2();
	this_class = getU2();
	super_class = getU2();
	parseInterfaces();
	parseFields();
	parseMethods();
	parseAttributes();
}

void ClassFile::parseConstantPools() {
	constant_pool_count = getU2();
	constant_pools = new CpInfo[constant_pool_count];
	for (int i = 1; i < constant_pool_count; i++) {
		constant_pools[i].tag = getU1();
		switch (constant_pools[i].tag)
		{
		case Tags::JVM_CONSTANT_Class:
			constant_pools[i].class_info.name_index = getU2();
			break;
		case Tags::JVM_CONSTANT_Fieldref:
			constant_pools[i].fieldref_info.class_index = getU2();
			constant_pools[i].fieldref_info.name_and_type_index = getU2();
			break;
		case Tags::JVM_CONSTANT_Methodref:
			constant_pools[i].methodref_info.class_index = getU2();
			constant_pools[i].methodref_info.name_and_type_index = getU2();
			break;
		case Tags::JVM_CONSTANT_InterfaceMethodref:
			constant_pools[i].interfaceMethodref_info.class_index = getU2();
			constant_pools[i].interfaceMethodref_info.name_and_type_index = getU2();
			break;
		case Tags::JVM_CONSTANT_String:
			constant_pools[i].string_info.string_index = getU2();
			break;
		case Tags::JVM_CONSTANT_Integer:
			constant_pools[i].integer_info.bytes = getU4();
			break;
		case Tags::JVM_CONSTANT_Float:
			constant_pools[i].float_info.bytes = getU4();
			break;
		case Tags::JVM_CONSTANT_Long:
			constant_pools[i].long_info.high_bytes = getU4();
			constant_pools[i].long_info.low_bytes = getU4();
			i++;
			break;
		case Tags::JVM_CONSTANT_Double:
			constant_pools[i].double_info.high_bytes = getU4();
			constant_pools[i].double_info.low_bytes = getU4();
			i++;
			break;
		case JVM_CONSTANT_NameAndType:
			constant_pools[i].nameAndType_info.name_index = getU2();
			constant_pools[i].nameAndType_info.descriptor_index = getU2();
			break;
		case Tags::JVM_CONSTANT_Utf8:
			constant_pools[i].utf8_info.length = getU2();
			constant_pools[i].utf8_info.bytes = new char[constant_pools[i].utf8_info.length];
			f.read(constant_pools[i].utf8_info.bytes, constant_pools[i].utf8_info.length*sizeof(u1));
			/*for (int j = 0; j < constant_pools[i].utf8_info.length; j++)
				constant_pools[i].utf8_info.bytes[j] = getU1();*/
			break;
		case Tags::JVM_CONSTANT_MethodHandle:
			constant_pools[i].methodHandle_info.reference_kind = getU1();
			constant_pools[i].methodHandle_info.reference_index = getU2();
			break;
		case Tags::JVM_CONSTANT_MethodType:
			constant_pools[i].methodType_info.descriptor_index = getU2();
			break;
		case Tags::JVM_CONSTANT_InvokeDynamic:
			constant_pools[i].invokeDynamic_info.bootstrap_method_attr_index = getU2();
			constant_pools[i].invokeDynamic_info.name_and_type_index = getU2();
			break;
		default:
			cout << "UnKnow tag:" << constant_pools[i].tag<< endl;
			exit(0);
		}
	}
}

void ClassFile::parseInterfaces() {
	interfaces_count = getU2();
	interfaces = new InterfacesInfo[interfaces_count];
	for (int i = 0; i < interfaces_count; i++)
		interfaces[i] = getU2();
}

void ClassFile::parseFields() {
	fields_count = getU2();
	fields = new FieldInfo[fields_count];
	for(int i = 0;i<fields_count;i++){
		fields[i].access_flags = getU2();
		fields[i].name_index = getU2();
		fields[i].descriptor_index = getU2();
		fields[i].attributes_count = getU2();
		fields[i].attributes = new AttributeInfo[fields[i].attributes_count];
		for (int j = 0; j < fields[i].attributes_count; j++) {
			fields[i].attributes[j].attribute_name_index = getU2();
			fields[i].attributes[j].attribute_length = getU4();
			fields[i].attributes[j].info = new char[fields[i].attributes[j].attribute_length];
			f.read(fields[i].attributes[j].info, fields[i].attributes[j].attribute_length * sizeof(u1));
			/*for (int k = 0; k < fields[i].attributes[j].attribute_length; k++)
				fields[i].attributes[j].info[k] = getU1();*/
		}
	}

}

void ClassFile::parseMethods() {
	methods_count = getU2();
	methods = new MethodInfo[methods_count];
	for (int i = 0; i < methods_count; i++) {
		methods[i].access_flags = getU2();
		methods[i].name_index = getU2();
		methods[i].descriptor_index = getU2();
		methods[i].attributes_count = getU2();
		methods[i].attributes = new AttributeInfo[methods[i].attributes_count];
		for (int j = 0; j < methods[i].attributes_count; j++) {
			methods[i].attributes[j].attribute_name_index = getU2();
			methods[i].attributes[j].attribute_length = getU4();
			methods[i].attributes[j].info = new char[methods[i].attributes[j].attribute_length];
			f.read(methods[i].attributes[j].info, methods[i].attributes[j].attribute_length * sizeof(u1));
			/*for (int k = 0; k < methods[i].attributes[j].attribute_length; k++)
				methods[i].attributes[j].info[k] = getU1();*/
		}
	}

}

void ClassFile::parseAttributes() {
	attributes_count = getU2();
	attributes = new AttributeInfo[attributes_count];
	for (int i = 0; i < attributes_count; i++) {
		attributes[i].attribute_name_index = getU2();
		attributes[i].attribute_length = getU4();
		attributes[i].info = new char[attributes[i].attribute_length];
		f.read(attributes[i].info, attributes[i].attribute_length * sizeof(u1));
		/*for (int j = 0; j < attributes[i].attribute_length; j++)
			attributes[i].info[j] = getU1();*/
	}
}

u1 ClassFile::getU1() {
	char b1;
	f.read(&b1, sizeof(char));
	return b1;
}

u2 ClassFile::getU2() {
	char b1;
	char b2;
	f.read(&b1, sizeof(char));
	f.read(&b2, sizeof(char));
	return (u2)b1 << 8 | ((u2)b2 & 0x00ff);
}

u4 ClassFile::getU4() {
	char b1;
	char b2;
	char b3;
	char b4;
	f.read(&b1, sizeof(char));
	f.read(&b2, sizeof(char));
	f.read(&b3, sizeof(char));
	f.read(&b4, sizeof(char));
	return ((u4)b1 << 24 & 0xff000000) | ((u4)b2 << 16 & 0x00ff0000) | ((u4)b3 << 8 & 0x0000ff00) | ((u4)b4 & 0x000000ff);
}

ClassFile::~ClassFile()
{
	f.close();
}


Code_attribute* ClassFile::getMethodByNameAndType(string main_name, string main_type)
{
	MethodInfo* method = NULL;
	for (int i = 0; i < methods_count; i++) {
		//class文件规范的检查在类文件加载时进行
		char *name = constant_pools[methods[i].name_index].utf8_info.bytes;
		u2 name_length = constant_pools[methods[i].name_index].utf8_info.length;
		char *type = constant_pools[methods[i].descriptor_index].utf8_info.bytes;
		u2 type_length = constant_pools[methods[i].descriptor_index].utf8_info.length;
		if (constant_utf8_equal(name,name_length,main_name) == 0 && constant_utf8_equal(type,type_length,main_type) == 0) {
			method = &methods[i];
			break;
		}
	}
	if (method == NULL) {
		cerr << "Can't find main method" << endl;
		exit(-1);
	}
	
	char *info = NULL;
	for (int i = 0; i < method->attributes_count; i++) {
		char *name = constant_pools[method->attributes[i].attribute_name_index].utf8_info.bytes;
		u2 name_length = constant_pools[method->attributes[i].attribute_name_index].utf8_info.length;
		if ( constant_utf8_equal(name,name_length,"Code")== 0) {
			info = method->attributes[i].info;
			break;
		}
	}
	if (info == NULL) {
		cerr << "Can't find code" << endl;
		exit(-1);
	}

	Code_attribute *code = new Code_attribute();
	code->max_stack = (((u2)info[0]<<8)&0xff00) | ((u2)info[1]&0x00ff);
	code->max_locals = (((u2)info[2] << 8) & 0xff00) | ((u2)info[3] & 0x00ff);
	code->code_length = (((u2)info[4] << 24) & 0xff000000) | (((u2)info[5] << 16) & 0x00ff0000) | (((u2)info[6] << 8) & 0x0000ff00) | (((u2)info[7]) & 0x000000ff);
	code->codes = &info[8];//info[8~8+code_length]为代码
	return code;
}

int ClassFile::constant_utf8_equal(char *s, u2 length,string str) {
	if (length != str.length())
		return -1;
	for (int i = 0; i < length; i++)
		if (s[i] != str.data()[i])
			return -1;
	return 0;
}
