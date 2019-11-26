#pragma once
#include"classfile_typedef.h"
#include"classfile_constants.h"
#include<stack>
#include<cstdlib>
#include<iostream>
using namespace std;

typedef struct {
	char array_type;
	arrayType* array_date = NULL;
	u4 array_length = 0;
}gava_array;

class Arrays
{
private:
	u4 max_arrays = 255;
	u4 change = 10;
	u4 length = 0;
	gava_array* arrays;
	stack<u4> unused;
public :
	
	Arrays();
	gava_array* getArray(u4 index);
	u4 newArray();
	void deleteArray(u4 index);

	void printArrays();
	~Arrays();

};

