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

Arrays::~Arrays()
{
}
