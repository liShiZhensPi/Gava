#pragma once
#include"classfile_typedef.h"
typedef union {
	u4 a;
	int i;
	short s;
	u2 c;
	char b;
	float f;
}stackType;

typedef union {
	u4 U4[2];
	long long l;
	double d;
}stackType2;

typedef union {
	u2 U2;
	u1 U1[2];
}translate_U2;

typedef union {
	u4 U4;
	u1 U1[4];
}translate_U4;