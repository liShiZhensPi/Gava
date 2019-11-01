#pragma once
#include"ClassFile.h"
class LocalTable
{
private:
	u2 length;
	u4 *locals;
public:
	LocalTable(u2 length);
	u4 load(u2 index);
	void store(u2 index, u4 value);
	~LocalTable();
};

