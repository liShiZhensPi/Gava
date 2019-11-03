#pragma once
#include"classfile_typedef.h"
#include<stack>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef union {
	char* boolean_array;
	u2* char_array;
	float* float_array;
	double* double_array;
	char* byte_array;
	short* short_array;
	int* int_array;
	long long* long_array;
}arrayType;

typedef struct {
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
	~Arrays();

};

