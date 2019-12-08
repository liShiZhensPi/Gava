#include "ClassFile.h"
#include "Process.h"
#include"ExecuteEngine.h"

int main(int argc,char* argv[]) {

	if (argc < 2) {
		cout << "Please input Gava class file" << endl;
		return 0;
	}

	string class_file;
	string class_path;

	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-')
			switch (argv[i][1]) {
			case 'p':
				class_path = argv[++i];
				break;
			}
		else
			class_file = argv[i];
	}
	if (class_file.empty()) {
		cout << "Please input Gava class file" << endl;
		return 0;
	}


	ClassFile *file = new ClassFile(class_file,class_path);
	Process *process = new Process(class_file, file,class_path);
	ExecuteEngine *engine = new ExecuteEngine(process);
	engine->execute(true);


}
