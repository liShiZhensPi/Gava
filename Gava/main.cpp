#include "ClassFile.h"
#include "Process.h"
#include"ExecuteEngine.h"

int main(int argc,char* argv[]) {

	if (argc < 2) {
		cout << "Please input Gava class file" << endl;
		return 0;
	}

	ClassFile *file = new ClassFile(argv[1]);
	Process *process = new Process("Test/Test", file);
	ExecuteEngine *engine = new ExecuteEngine(process);
	engine->execute(true);


}
