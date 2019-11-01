#include "LocalTable.h"



LocalTable::LocalTable(u2 length)
{
	this->length = length;
	locals = new u4[length];
}

void LocalTable::store(u2 index, u4 value)
{
	if (index >= length) {
		cerr << "lcoal index out" << endl;
		exit(-1);
	}
	locals[index] = value;
}

u4 LocalTable::load(u2 index)
{
	if (index >= length) {
		cerr << "lcoal index out" << endl;
		exit(-1);
	}
	return locals[index];
}

LocalTable::~LocalTable()
{
}
