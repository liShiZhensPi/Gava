#include "ClassFile.h"
#include <cstdlib>
#include<cstdio>

int main() {
	ClassFile *classfile = new ClassFile("Test.class");

	cout << classfile->methods[1].attributes[0].attribute_length << endl;

	getchar();
}
