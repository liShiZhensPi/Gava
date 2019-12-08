#include "Arrays.h"

Arrays::Arrays()
{
	for (u4 i = length; i < length + change; i++)
		unused.push(i);
	length += change;
	/*arrays = (gava_array*)calloc(length ,sizeof(gava_array));
	if (arrays == NULL) {
		cout << "calloc error" << endl;
		exit(-1);
	}*/

	arrays = new gava_array[length]();
}

gava_array* Arrays::getArray(u4 index)
{
	if (arrays[index].array_date == NULL)
	{
		cout << "array is not init" << endl;
		exit(-1);
	}
	return &arrays[index];
}

u4 Arrays::newArray()
{
	if (unused.empty()) {//如果可用数组空间满了，进行扩展
		if (length + change > max_arrays) {
			cout << "to many arrays" << endl;
			exit(-1);
		}

		for (u4 i = length; i < length + change; i++)
			unused.push(i);

		//gava_array* new_arrays = (gava_array*)calloc((length + change), sizeof(gava_array));
		gava_array* new_arrays = new gava_array[length + change]();

		for (u4 i = 0; i < length; i++)
			new_arrays[i] = arrays[i];
		length += change;
		arrays = new_arrays;
	}
	u4 index = unused.top();
	unused.pop();
	arrays[index].array_date = new arrayType();
	return index;
}

void Arrays::deleteArray(u4 index)
{
	delete[] arrays[index].array_date;
	arrays[index].array_date = NULL;
	arrays[index].array_length = 0;
	unused.push(index);
}

void Arrays::printArrays()
{
	cout << "array_count: " << length << endl;
	for (int i = 0; i < length; i++) {
		cout << "array_length: " << arrays[i].array_length << endl;
		if(arrays[i].array_length!=0)//若数组已初始化
			for (int j = 0; j < arrays[i].array_length; j++) {
				switch (arrays[i].array_type)
				{
				case ArrayType::JVM_T_BOOLEAN:
					cout << j << " : " << arrays[i].array_date->boolean_array[j] << endl;
					break;
				case ArrayType::JVM_T_BYTE:
					cout << j << " : " << arrays[i].array_date->byte_array[j] << endl;
					break;
				case ArrayType::JVM_T_CHAR:
					cout << j << " : " << arrays[i].array_date->char_array[j] << endl;
					break;
				case ArrayType::JVM_T_DOUBLE:
					cout << j << " : " << arrays[i].array_date->double_array[j] << endl;
					break;
				case ArrayType::JVM_T_FLOAT:
					cout << j << " : " << arrays[i].array_date->float_array[j] << endl;
					break;
				case ArrayType::JVM_T_INT:
					cout << j << " : " << arrays[i].array_date->int_array[j] << endl;
					break;
				case ArrayType::JVM_T_LONG:
					cout << j << " : " << arrays[i].array_date->long_array[j] << endl;
					break;
				case ArrayType::JVM_T_SHORT:
					cout << j << " : " << arrays[i].array_date->short_array[j] << endl;
					break;
				default:
					cout << "未知的数组类型，可能出现了什么错误:(" << endl;
					break;
				}
			}
	}
	cout << "unused: " << unused.size() << endl;
	stack<u4> unused2;
	while (!unused.empty()) {
		unused2.push(unused.top());
		unused.pop();
	}
	while (!unused2.empty()) {
		cout << unused2.top() << endl;
		unused.push(unused2.top());
		unused2.pop();
	}
}

Arrays::~Arrays()
{
}
