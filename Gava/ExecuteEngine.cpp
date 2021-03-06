#include "ExecuteEngine.h"



ExecuteEngine::ExecuteEngine(Process *process)
{
	this->currentProcess = process;
	this->currentThread = process->getMainThread();
	//this->currentClass = process->getMainClass();
	this->currentFrame = currentThread->getStackFrame();
	this->arrays = process->getArrays();
	process->printProcess();
}

void ExecuteEngine::execute(bool isVisualized) {
	short opcode_length[] = JVM_OPCODE_LENGTH_INITIALIZER;
	u4 null = 0;
	while (currentFrame->hasCode()) {
	

		if (isVisualized) {
			string instruct;

			cin >> instruct;
			if (instruct.compare("end") == 0)//结束指令
				break;
		}
		u1 code = currentFrame->getCode();
		switch (code)
		{
		case nop: //0x00 	什么都不做
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aconst_null: //0x01 	将null推送至栈顶
			currentFrame->pusha(null);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_m1: //0x02 	将int型-1推送至栈顶
			currentFrame->pushi(-1);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_0: //0x03 	将int型0推送至栈顶
			currentFrame->pushi(0);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_1: //0x04 	将int型1推送至栈顶
			currentFrame->pushi(1);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_2: //0x05 	将int型2推送至栈顶
			currentFrame->pushi(2);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_3: //0x06 	将int型3推送至栈顶
			currentFrame->pushi(3);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_4: //0x07 	将int型4推送至栈顶
			currentFrame->pushi(4);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_5: //0x08 	将int型5推送至栈顶
			currentFrame->pushi(5);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lconst_0: //0x09 	将long型0推送至栈顶
			currentFrame->pushl(0);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lconst_1: //0x0a 	将long型1推送至栈顶
			currentFrame->pushl(1);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fconst_0: //0x0b 	将float型0推送至栈顶
			currentFrame->pushf(0);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;


		case fconst_1: //0x0c 	将float型1推送至栈顶
			currentFrame->pushf(1);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fconst_2: //0x0d 	将float型2推送至栈顶
			currentFrame->pushf(2);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dconst_0: //0x0e 	将do le型0推送至栈顶
			currentFrame->pushd(0);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dconst_1: //0x0f 	将do le型1推送至栈顶
			currentFrame->pushd(1);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case bipush: //0x10 	将单字节的常量值(-128~127)推送至栈顶
			currentFrame->pushb(currentFrame->getU1());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case sipush: //0x11 	将一个短整型常量值(-32768~32767)推送至栈顶
			currentFrame->pushs(currentFrame->getU2());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ldc: //0x12 	将int, float或String型常量值从常量池中推送至栈顶
		{
			int index = currentFrame->getU1()&0x000000ff;
			switch (currentFrame->classFile->constant_pools[index].tag)
			{
			case Tags::JVM_CONSTANT_Integer:
				currentFrame->pusha(currentFrame->classFile->constant_pools[index].integer_info.bytes);
				break;
			case Tags::JVM_CONSTANT_Float:
				currentFrame->pusha(currentFrame->classFile->constant_pools[index].float_info.bytes);
				break;
			case Tags::JVM_CONSTANT_String:
				currentFrame->pushc(currentFrame->classFile->constant_pools[index].string_info.string_index);
				break;
			default:
				break;
			}
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case ldc_w: //0x13 	将int, float或String型常量值从常量池中推送至栈顶（宽索引）
		{
			int index = currentFrame->getU2() & 0x0000ffff;
			switch (currentFrame->classFile->constant_pools[index].tag)
			{
			case Tags::JVM_CONSTANT_Integer:
				currentFrame->pusha(currentFrame->classFile->constant_pools[index].integer_info.bytes);
				break;
			case Tags::JVM_CONSTANT_Float:
				currentFrame->pusha(currentFrame->classFile->constant_pools[index].float_info.bytes);
				break;
			case Tags::JVM_CONSTANT_String:
				currentFrame->pushc(currentFrame->classFile->constant_pools[index].string_info.string_index);
				break;
			default:
				break;
			}
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case ldc2_w: //0x14 	将long或do le型常量值从常量池中推送至栈顶（宽索引）
		{
			int index = currentFrame->getU2() & 0x0000ffff;
			switch (currentFrame->classFile->constant_pools[index].tag)
			{
			case Tags::JVM_CONSTANT_Long:
				currentFrame->pusha(currentFrame->classFile->constant_pools[index].long_info.low_bytes);
				currentFrame->pusha(currentFrame->classFile->constant_pools[index].long_info.high_bytes);
				break;
			case Tags::JVM_CONSTANT_Double:
				currentFrame->pusha(currentFrame->classFile->constant_pools[index].double_info.low_bytes);
				currentFrame->pusha(currentFrame->classFile->constant_pools[index].double_info.high_bytes);
				break;		
			default:
				break;
			}
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case iload: //0x15 	将指定的int型本地变量
			currentFrame->pushi(currentFrame->loadi(currentFrame->getU1()));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload: //0x16 	将指定的long型本地变量
			currentFrame->pushl(currentFrame->loadl(currentFrame->getU1()));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload: //0x17 	将指定的float型本地变量
			currentFrame->pushf(currentFrame->loadf(currentFrame->getU1()));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload: //0x18 	将指定的do le型本地变量
			currentFrame->pushd(currentFrame->loadd(currentFrame->getU1()));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload: //0x19 	将指定的引用类型本地变量
			currentFrame->pusha(currentFrame->loada(currentFrame->getU1()));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload_0: //0x1a 	将第一个int型本地变量
			currentFrame->pushi(currentFrame->loadi(0));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload_1: //0x1b 	将第二个int型本地变量
			currentFrame->pushi(currentFrame->loadi(1));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload_2: //0x1c 	将第三个int型本地变量
			currentFrame->pushi(currentFrame->loadi(2));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload_3: //0x1d 	将第四个int型本地变量
			currentFrame->pushi(currentFrame->loadi(3));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload_0: //0x1e 	将第一个long型本地变量
			currentFrame->pushl(currentFrame->loadl(0));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload_1: //0x1f 	将第二个long型本地变量
			currentFrame->pushl(currentFrame->loadl(1));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload_2: //0x20 	将第三个long型本地变量
			currentFrame->pushl(currentFrame->loadl(2));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload_3: //0x21 	将第四个long型本地变量
			currentFrame->pushl(currentFrame->loadl(3));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload_0: //0x22 	将第一个float型本地变量
			currentFrame->pushf(currentFrame->loadf(0));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload_1: //0x23 	将第二个float型本地变量
			currentFrame->pushf(currentFrame->loadf(1));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload_2: //0x24 	将第三个float型本地变量
			currentFrame->pushf(currentFrame->loadf(2));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload_3: //0x25 	将第四个float型本地变量
			currentFrame->pushf(currentFrame->loadf(3));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload_0: //0x26 	将第一个do le型本地变量
			currentFrame->pushd(currentFrame->loadd(0));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload_1: //0x27 	将第二个do le型本地变量
			currentFrame->pushd(currentFrame->loadd(1));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload_2: //0x28 	将第三个do le型本地变量
			currentFrame->pushd(currentFrame->loadd(2));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload_3: //0x29 	将第四个do le型本地变量
			currentFrame->pushd(currentFrame->loadd(3));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload_0: //0x2a 	将第一个引用类型本地变量
			currentFrame->pusha(currentFrame->loada(0));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload_1: //0x2b 	将第二个引用类型本地变量
			currentFrame->pusha(currentFrame->loada(1));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload_2: //0x2c 	将第三个引用类型本地变量
			currentFrame->pusha(currentFrame->loada(2));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload_3: //0x2d 	将第四个引用类型本地变量
			currentFrame->pusha(currentFrame->loada(3));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iaload: //0x2e 	将int型数组指定索引的值推送至栈顶
		{
			int shift = currentFrame->popi();
			u4 index = currentFrame->popa();
			currentFrame->pushi(arrays->getArray(index)->array_date->int_array[shift]);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case laload: //0x2f 	将long型数组指定索引的值推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case faload: //0x30 	将float型数组指定索引的值推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case daload: //0x31 	将do le型数组指定索引的值推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aaload: //0x32 	将引用型数组指定索引的值推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case baload: //0x33 	将boolean或byte型数组指定索引的值推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case caload: //0x34 	将char型数组指定索引的值推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case saload: //0x35 	将short型数组指定索引的值推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore: //0x36 	将栈顶int型数值存入指定本地变量
			currentFrame->storei(currentFrame->getU1(), currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore: //0x37 	将栈顶long型数值存入指定本地变量
			currentFrame->storel(currentFrame->getU1(), currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore: //0x38 	将栈顶float型数值存入指定本地变量
			currentFrame->storef(currentFrame->getU1(), currentFrame->popf());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore: //0x39 	将栈顶do le型数值存入指定本地变量
			currentFrame->stored(currentFrame->getU1(), currentFrame->popd());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore: //0x3a 	将栈顶引用型数值存入指定本地变量
			currentFrame->storea(currentFrame->getU1(), currentFrame->popa());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore_0: //0x3b 	将栈顶int型数值存入第一个本地变量
			currentFrame->storei(0, currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore_1: //0x3c 	将栈顶int型数值存入第二个本地变量
			currentFrame->storei(1, currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore_2: //0x3d 	将栈顶int型数值存入第三个本地变量
			currentFrame->storei(2, currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore_3: //0x3e 	将栈顶int型数值存入第四个本地变量
			currentFrame->storei(3, currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore_0: //0x3f 	将栈顶long型数值存入第一个本地变量
			currentFrame->storel(0, currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore_1: //0x40 	将栈顶long型数值存入第二个本地变量
			currentFrame->storel(1, currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore_2: //0x41 	将栈顶long型数值存入第三个本地变量
			currentFrame->storel(2, currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore_3: //0x42 	将栈顶long型数值存入第四个本地变量
			currentFrame->storel(3, currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore_0: //0x43 	将栈顶float型数值存入第一个本地变量
			currentFrame->storef(0, currentFrame->popf());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore_1: //0x44 	将栈顶float型数值存入第二个本地变量
			currentFrame->storef(1, currentFrame->popf());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore_2: //0x45 	将栈顶float型数值存入第三个本地变量
			currentFrame->storef(2, currentFrame->popf());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore_3: //0x46 	将栈顶float型数值存入第四个本地变量
			currentFrame->storef(3, currentFrame->popf());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore_0: //0x47 	将栈顶do le型数值存入第一个本地变量
			currentFrame->stored(0, currentFrame->popd());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore_1: //0x48 	将栈顶do le型数值存入第二个本地变量
			currentFrame->stored(1, currentFrame->popd());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore_2: //0x49 	将栈顶do le型数值存入第三个本地变量
			currentFrame->stored(2, currentFrame->popd());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore_3: //0x4a 	将栈顶do le型数值存入第四个本地变量
			currentFrame->stored(3, currentFrame->popd());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore_0: //0x4b 	将栈顶引用型数值存入第一个本地变量
			currentFrame->storea(0, currentFrame->popa());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore_1: //0x4c 	将栈顶引用型数值存入第二个本地变量
			currentFrame->storea(1, currentFrame->popa());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore_2: //0x4d 	将栈顶引用型数值存入第三个本地变量
			currentFrame->storea(2, currentFrame->popa());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore_3: //0x4e 	将栈顶引用型数值存入第四个本地变量
			currentFrame->storea(3, currentFrame->popa());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iastore: //0x4f 	将栈顶int型数值存入指定数组的指定索引位置
		{
			int value = currentFrame->popi();
			int shift = currentFrame->popi();
			u4 index = currentFrame->popa();
			arrays->getArray(index)->array_date->int_array[shift] = value;
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case lastore: //0x50 	将栈顶long型数值存入指定数组的指定索引位置
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fastore: //0x51 	将栈顶float型数值存入指定数组的指定索引位置
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dastore: //0x52 	将栈顶do le型数值存入指定数组的指定索引位置
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aastore: //0x53 	将栈顶引用型数值存入指定数组的指定索引位置
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case bastore: //0x54 	将栈顶boolean或byte型数值存入指定数组的指定索引位置
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case castore: //0x55 	将栈顶char型数值存入指定数组的指定索引位置
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case sastore: //0x56 	将栈顶short型数值存入指定数组的指定索引位置
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case pop: //0x57 	将栈顶数值弹出 (数值不能是long或do le类型的)
			currentFrame->popa();
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case pop2: //0x58 	将栈顶的一个（long或do le类型的)或两个数值弹出（其它）
			currentFrame->popl();
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup: //0x59 	复制栈顶数值并将复制值压入栈顶
		{	
			u4 a = currentFrame->popa();
			currentFrame->pusha(a);
			currentFrame->pusha(a);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case dup_x1: //0x5a 	复制栈顶数值并将两个复制值压入栈顶
		{
			u4 a = currentFrame->popa();
			currentFrame->pusha(a);
			currentFrame->pusha(a);
			currentFrame->pusha(a);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case dup_x2: //0x5b 	复制栈顶数值并将三个（或两个）复制值压入栈顶
		{
			u4 a = currentFrame->popa();
			currentFrame->pusha(a);
			currentFrame->pusha(a);
			currentFrame->pusha(a);
			currentFrame->pusha(a);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case dup2: //0x5c 	复制栈顶一个（long或do le类型的)或两个（其它）数值并将复制值压入栈顶
		{
			long long a = currentFrame->popl();
			currentFrame->pushl(a);
			currentFrame->pushl(a);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case dup2_x1: //0x5d 	dup_x1 指令的双倍版本
		{
			long long a = currentFrame->popl();
			currentFrame->pushl(a);
			currentFrame->pushl(a);
			currentFrame->pushl(a);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case dup2_x2: //0x5e 	dup_x2 指令的双倍版本
		{
			long long a = currentFrame->popl();
			currentFrame->pushl(a);
			currentFrame->pushl(a);
			currentFrame->pushl(a);
			currentFrame->pushl(a);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case swap_: //0x5f 	将栈最顶端的两个数值互换(数值不能是long或do le类型的)
		{
			u4 a = currentFrame->popa();
			u4 b = currentFrame->popa();
			currentFrame->pusha(b);
			currentFrame->pusha(a);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case iadd: //0x60 	将栈顶两int型数值相加并将结果压入栈顶
			currentFrame->pushi(currentFrame->popi() + currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ladd: //0x61 	将栈顶两long型数值相加并将结果压入栈顶
			currentFrame->pushl(currentFrame->popl() + currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fadd: //0x62 	将栈顶两float型数值相加并将结果压入栈顶
			currentFrame->pushf(currentFrame->popf() + currentFrame->popf());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dadd: //0x63 	将栈顶两do le型数值相加并将结果压入栈顶
			currentFrame->pushd(currentFrame->popd() + currentFrame->popd());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case is: //0x64 	将栈顶两int型数值相减并将结果压入栈顶
		{
			int b = currentFrame->popi();
			int a = currentFrame->popi();
			currentFrame->pushi(a - b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case ls: //0x65 	将栈顶两long型数值相减并将结果压入栈顶
		{
			long long b = currentFrame->popl();
			long long a = currentFrame->popl();
			currentFrame->pushl(a - b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case fs: //0x66 	将栈顶两float型数值相减并将结果压入栈顶
		{
			float b = currentFrame->popf();
			float a = currentFrame->popf();
			currentFrame->pushf(a - b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case ds: //0x67 	将栈顶两do le型数值相减并将结果压入栈顶
		{
			double b = currentFrame->popd();
			double a = currentFrame->popd();
			currentFrame->pushd(a - b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case imul: //0x68 	将栈顶两int型数值相乘并将结果压入栈顶
			currentFrame->pushi(currentFrame->popi()*currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lmul: //0x69 	将栈顶两long型数值相乘并将结果压入栈顶
			currentFrame->pushl(currentFrame->popl()*currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fmul: //0x6a 	将栈顶两float型数值相乘并将结果压入栈顶
			currentFrame->pushf(currentFrame->popf()*currentFrame->popf());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dmul: //0x6b 	将栈顶两do le型数值相乘并将结果压入栈顶
			currentFrame->pushd(currentFrame->popd()*currentFrame->popd());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case idiv: //0x6c 	将栈顶两int型数值相除并将结果压入栈顶
		{
			int b = currentFrame->popi();
			int a = currentFrame->popi();
			currentFrame->pushi(a / b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case ldiv_: //0x6d 	将栈顶两long型数值相除并将结果压入栈顶
		{
			long long b = currentFrame->popl();
			long long a = currentFrame->popl();
			currentFrame->pushl(a / b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case fdiv: //0x6e 	将栈顶两float型数值相除并将结果压入栈顶
		{
			float b = currentFrame->popf();
			float a = currentFrame->popf();
			currentFrame->pushf(a / b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case ddiv: //0x6f 	将栈顶两do le型数值相除并将结果压入栈顶
		{
			double b = currentFrame->popd();
			double a = currentFrame->popd();
			currentFrame->pushd(a / b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case irem: //0x70 	将栈顶两int型数值作取模运算并将结果压入栈顶
		{
			int b = currentFrame->popi();
			int a = currentFrame->popi();
			currentFrame->pushi(a % b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case lrem: //0x71 	将栈顶两long型数值作取模运算并将结果压入栈顶
		{
			long long b = currentFrame->popl();
			long long a = currentFrame->popl();
			currentFrame->pushl(a % b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case frem: //0x72 	将栈顶两float型数值作取模运算并将结果压入栈顶
		{
			/*float b = currentFrame->popf();
			float a = currentFrame->popf();
			currentFrame->pushf((int)a % (int)b);*/
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case drem: //0x73 	将栈顶两do le型数值作取模运算并将结果压入栈顶
		{
			/*double b = currentFrame->popd();
			double a = currentFrame->popd();
			currentFrame->pushd(a % b);*/
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case ineg: //0x74 	将栈顶int型数值取负并将结果压入栈顶
			currentFrame->pushi(-currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lneg: //0x75 	将栈顶long型数值取负并将结果压入栈顶
			currentFrame->pushl(-currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fneg: //0x76 	将栈顶float型数值取负并将结果压入栈顶
			currentFrame->pushf(-currentFrame->popf());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dneg: //0x77 	将栈顶do le型数值取负并将结果压入栈顶
			currentFrame->pushd(-currentFrame->popd());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ishl: //0x78 	将int型数值左移位指定位数并将结果压入栈顶
		{
			int b = currentFrame->popi();
			int a = currentFrame->popi();
			currentFrame->pushi(a << b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case lshl: //0x79 	将long型数值左移位指定位数并将结果压入栈顶
		{
			int b = currentFrame->popi();//b一定是int，若为long会转型为int
			long long a = currentFrame->popl();
			currentFrame->pushl(a << b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case ishr: //0x7a 	将int型数值右（符号）移位指定位数并将结果压入栈顶
		{
			int b = currentFrame->popi();
			int a = currentFrame->popi();
			currentFrame->pushi(a >> b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case lshr: //0x7b 	将long型数值右（符号）移位指定位数并将结果压入栈顶
		{
			int b = currentFrame->popi();//b一定是int，若为long会转型为int
			long long a = currentFrame->popl();
			currentFrame->pushi(a >> b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case iushr: //0x7c 	将int型数值右（无符号）移位指定位数并将结果压入栈顶
		{
			int b = currentFrame->popi();
			int a = currentFrame->popi();
			currentFrame->pushi((u4)a >> b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case lushr: //0x7d 	将long型数值右（无符号）移位指定位数并将结果压入栈顶
		{
			int b = currentFrame->popi();//b一定是int，若为long会转型为int
			long long a = currentFrame->popl();
			currentFrame->pushi((u4)a >> b);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case iand: //0x7e 	将栈顶两int型数值作“按位与”并将结果压入栈顶
			currentFrame->pushi(currentFrame->popi()&currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case land: //0x7f 	将栈顶两long型数值作“按位与”并将结果压入栈顶
			currentFrame->pushl(currentFrame->popl()&currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ior: //0x80 	将栈顶两int型数值作“按位或”并将结果压入栈顶
			currentFrame->pushi(currentFrame->popi()|currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lor: //0x81 	将栈顶两long型数值作“按位或”并将结果压入栈顶
			currentFrame->pushl(currentFrame->popl() | currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ixor: //0x82 	将栈顶两int型数值作“按位异或”并将结果压入栈顶
			currentFrame->pushi(currentFrame->popi()^currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lxor: //0x83 	将栈顶两long型数值作“按位异或”并将结果压入栈顶
			currentFrame->pushl(currentFrame->popl() ^ currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iinc: //0x84 	将指定int型变量增加指定值（i++, i–, i+=2）
		{
			u2 a = currentFrame->getU2();
			u1 index = a >> 8;
			char inc = a & 0x00ff;
			currentFrame->storei(index, currentFrame->loadi(index)+inc);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case i2l: //0x85 	将栈顶int型数值强制转换成long型数值并将结果压入栈顶
			currentFrame->pushl(currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2f: //0x86 	将栈顶int型数值强制转换成float型数值并将结果压入栈顶
			currentFrame->pushf(currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2d: //0x87 	将栈顶int型数值强制转换成doule型数值并将结果压入栈顶
			currentFrame->pushd(currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case l2i: //0x88 	将栈顶long型数值强制转换成int型数值并将结果压入栈顶
			currentFrame->pushi(currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case l2f: //0x89 	将栈顶long型数值强制转换成float型数值并将结果压入栈顶
			currentFrame->pushf(currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case l2d: //0x8a 	将栈顶long型数值强制转换成doule型数值并将结果压入栈顶
			currentFrame->pushd(currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case f2i: //0x8b 	将栈顶float型数值强制转换成int型数值并将结果压入栈顶
			currentFrame->pushi(currentFrame->popf());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case f2l: //0x8c 	将栈顶float型数值强制转换成long型数值并将结果压入栈顶
			currentFrame->pushl(currentFrame->popf());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case f2d: //0x8d 	将栈顶float型数值强制转换成doule型数值并将结果压入栈顶
			currentFrame->pushd(currentFrame->popf());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case d2i: //0x8e 	将栈顶do le型数值强制转换成int型数值并将结果压入栈顶
			currentFrame->pushi(currentFrame->popd());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case d2l: //0x8f 	将栈顶do le型数值强制转换成long型数值并将结果压入栈顶
			currentFrame->pushl(currentFrame->popd());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case d2f: //0x90 	将栈顶do le型数值强制转换成float型数值并将结果压入栈顶
			currentFrame->pushf(currentFrame->popd());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2b: //0x91 	将栈顶int型数值强制转换成byte型数值并将结果压入栈顶
			currentFrame->pushb(currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2c: //0x92 	将栈顶int型数值强制转换成char型数值并将结果压入栈顶
			currentFrame->pushc(currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2s: //0x93 	将栈顶int型数值强制转换成short型数值并将结果压入栈顶
			currentFrame->pushs(currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lcmp: //0x94 	比较栈顶两long型数值大小，并将结果（1，0，-1）压入栈顶
		{
			long long b = currentFrame->popl();
			long long a = currentFrame->popl();
			if (a > b)
				currentFrame->pushi(1);
			else if (a == b)
				currentFrame->pushi(0);
			else
				currentFrame->pushi(-1);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case fcmpl: //0x95 	比较栈顶两float型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将-1压入栈顶
		{
			float b = currentFrame->popl();
			float a = currentFrame->popl();
			if (a > b)
				currentFrame->pushi(1);
			else if (a == b)
				currentFrame->pushi(0);
			else
				currentFrame->pushi(-1);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case fcmpg: //0x96 	比较栈顶两float型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将1压入栈顶
		{
			float b = currentFrame->popl();
			float a = currentFrame->popl();
			if (a > b)
				currentFrame->pushi(1);
			else if (a == b)
				currentFrame->pushi(0);
			else
				currentFrame->pushi(-1);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case dcmpl: //0x97 	比较栈顶两do le型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将-1压入栈顶
		{
			double b = currentFrame->popl();
			double a = currentFrame->popl();
			if (a > b)
				currentFrame->pushi(1);
			else if (a == b)
				currentFrame->pushi(0);
			else
				currentFrame->pushi(-1);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case dcmpg: //0x98 	比较栈顶两do le型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将1压入栈顶
		{
			double b = currentFrame->popl();
			double a = currentFrame->popl();
			if (a > b)
				currentFrame->pushi(1);
			else if (a == b)
				currentFrame->pushi(0);
			else
				currentFrame->pushi(-1);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case ifeq: //0x99 	当栈顶int型数值等于0时跳转
			if (currentFrame->popi() == 0)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifne: //0x9a 	当栈顶int型数值不等于0时跳转
			if (currentFrame->popi() != 0)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iflt: //0x9b 	当栈顶int型数值小于0时跳转
			if (currentFrame->popi() < 0)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifge: //0x9c 	当栈顶int型数值大于等于0时跳转
			if (currentFrame->popi() >= 0)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifgt: //0x9d 	当栈顶int型数值大于0时跳转
			if (currentFrame->popi() > 0)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifle: //0x9e 	当栈顶int型数值小于等于0时跳转
			if (currentFrame->popi() <= 0)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmpeq: //0x9f 	比较栈顶两int型数值大小，当结果等于0时跳转
		{
			int b = currentFrame->popi();
			int a = currentFrame->popi();
			if(a-b==0)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case if_icmpne: //0xa0 	比较栈顶两int型数值大小，当结果不等于0时跳转
		{
			int b = currentFrame->popi();
			int a = currentFrame->popi();
			if (a - b != 0)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case if_icmplt: //0xa1 	比较栈顶两int型数值大小，当结果小于0时跳转
		{
			int b = currentFrame->popi();
			int a = currentFrame->popi();
			if (a - b < 0)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case if_icmpge: //0xa2 	比较栈顶两int型数值大小，当结果大于等于0时跳转
		{
			int b = currentFrame->popi();
			int a = currentFrame->popi();
			if (a - b >= 0)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case if_icmpgt: //0xa3 	比较栈顶两int型数值大小，当结果大于0时跳转
		{
			int b = currentFrame->popi();
			int a = currentFrame->popi();
			if (a - b > 0)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case if_icmple: //0xa4 	比较栈顶两int型数值大小，当结果小于等于0时跳转
		{
			int b = currentFrame->popi();
			int a = currentFrame->popi();
			if (a - b <= 0)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case if_acmpeq: //0xa5 	比较栈顶两引用型数值，当结果相等时跳转
			if (currentFrame->popa() == currentFrame->popa())
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_acmpne: //0xa6 	比较栈顶两引用型数值，当结果不相等时跳转
			if (currentFrame->popa() != currentFrame->popa())
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case goto_: //0xa7 	无条件跳转
			currentFrame->goto_(currentFrame->getU2());
			break;
		case jsr: //0xa8 	跳转至指定16位offset位置，并将jsr下一条指令地址压入栈顶    这条指令现在可能不用了
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ret: //0xa9 	返回至本地变量  这条指令现在可能不用了
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case tableswitch: //0xaa 	用于switch条件跳转，case值连续（可变长度指令）
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lookupswitch: //0xab 	用于switch条件跳转，case值不连续（可变长度指令）
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ireturn: //0xac 	从当前方法返回int
		{
			currentThread->VMStack.pop();
			if (currentThread->VMStack.empty())
				exit(currentFrame->popi());
			StackFrame* back_frame = currentThread->VMStack.top();
			
			back_frame->pushi(currentFrame->popi());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);//似乎这是一条没用的语句
			currentFrame = back_frame;
			break;
		}
		case lreturn: //0xad 	从当前方法返回long
		{
			currentThread->VMStack.pop();
			if (currentThread->VMStack.empty())
				exit(currentFrame->popl());
			StackFrame* back_frame = currentThread->VMStack.top();
			
			back_frame->pushl(currentFrame->popl());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);//似乎这是一条没用的语句
			currentFrame = back_frame;
			break;
		}
		case freturn: //0xae 	从当前方法返回float
		{
			currentThread->VMStack.pop();
			if (currentThread->VMStack.empty())
				exit(currentFrame->popf());
			StackFrame* back_frame = currentThread->VMStack.top();
			
			back_frame->pushf(currentFrame->popf());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);//似乎这是一条没用的语句
			currentFrame = back_frame;
			break;
		}
		case dreturn: //0xaf 	从当前方法返回do le
		{
			currentThread->VMStack.pop();
			if (currentThread->VMStack.empty())
				exit(currentFrame->popd());
			StackFrame* back_frame = currentThread->VMStack.top();
			
			back_frame->pushd(currentFrame->popd());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);//似乎这是一条没用的语句
			currentFrame = back_frame;
			break;
		}
		case areturn: //0xb0 	从当前方法返回对象引用
		{
			currentThread->VMStack.pop();
			if (currentThread->VMStack.empty())
				exit(currentFrame->popa());
			StackFrame* back_frame = currentThread->VMStack.top();
			
			back_frame->pusha(currentFrame->popa());
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);//似乎这是一条没用的语句
			currentFrame = back_frame;
			break;
		}
		case return_: //0xb1 	从当前方法返回void
		{
			currentThread->VMStack.pop();
			if (currentThread->VMStack.empty())
				exit(0);
			StackFrame* back_frame = currentThread->VMStack.top();
			
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);//似乎这是一条没用的语句
			currentFrame = back_frame;
			break;
		}
		case getstatic: //0xb2 	获取指定类的静态域，并将其值压入栈顶
		{
			u2 field_index = currentFrame->getU2();
			u2 class_index = currentFrame->classFile->constant_pools[field_index].fieldref_info.class_index;
			u2 name_type_index = currentFrame->classFile->constant_pools[field_index].fieldref_info.name_and_type_index;
			u2 class_name_index = currentFrame->classFile->constant_pools[class_index].class_info.name_index;
			u2 field_name_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.name_index;
			u2 field_type_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.descriptor_index;

			string class_name(currentFrame->classFile->constant_pools[class_name_index].utf8_info.bytes, currentFrame->classFile->constant_pools[class_name_index].utf8_info.length);
			string field_name(currentFrame->classFile->constant_pools[field_name_index].utf8_info.bytes, currentFrame->classFile->constant_pools[field_name_index].utf8_info.length);
			string field_type(currentFrame->classFile->constant_pools[field_type_index].utf8_info.bytes, currentFrame->classFile->constant_pools[field_type_index].utf8_info.length);

			switch (field_type.data()[0]) {
			case Descriptor::JVM_SIGNATURE_ARRAY:
			case Descriptor::JVM_SIGNATURE_CLASS:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				currentFrame->pusha(class_file->getField(field_name).a);
				break;
			}
			case Descriptor::JVM_SIGNATURE_BOOLEAN:
			case Descriptor::JVM_SIGNATURE_BYTE:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				currentFrame->pushb(class_file->getField(field_name).b);
				break;
			}
			case Descriptor::JVM_SIGNATURE_CHAR:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				currentFrame->pushc(class_file->getField(field_name).c);
				break;
			}
			case Descriptor::JVM_SIGNATURE_DOUBLE:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				currentFrame->pushd(class_file->getField(field_name).d);
				break;
			}
			case Descriptor::JVM_SIGNATURE_FLOAT:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				currentFrame->pushf(class_file->getField(field_name).f);
				break;
			}
			case Descriptor::JVM_SIGNATURE_INT:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				currentFrame->pushi(class_file->getField(field_name).i);
				break;

			}
			case Descriptor::JVM_SIGNATURE_LONG:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				currentFrame->pushl(class_file->getField(field_name).l);
				break;
			}
			case Descriptor::JVM_SIGNATURE_SHORT:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				currentFrame->pushs(class_file->getField(field_name).s);
				break;
			}
			default:
				exit_with_massage("unkonw field type: " + field_type.data()[0]);
			}
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case putstatic: //0xb3 	为指定的类的静态域赋值
		{
			u2 field_index = currentFrame->getU2();
			u2 class_index = currentFrame->classFile->constant_pools[field_index].fieldref_info.class_index;
			u2 name_type_index = currentFrame->classFile->constant_pools[field_index].fieldref_info.name_and_type_index;
			u2 class_name_index = currentFrame->classFile->constant_pools[class_index].class_info.name_index;
			u2 field_name_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.name_index;
			u2 field_type_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.descriptor_index;

			string class_name(currentFrame->classFile->constant_pools[class_name_index].utf8_info.bytes, currentFrame->classFile->constant_pools[class_name_index].utf8_info.length);
			string field_name(currentFrame->classFile->constant_pools[field_name_index].utf8_info.bytes, currentFrame->classFile->constant_pools[field_name_index].utf8_info.length);
			string field_type(currentFrame->classFile->constant_pools[field_type_index].utf8_info.bytes, currentFrame->classFile->constant_pools[field_type_index].utf8_info.length);
			
			switch (field_type.data()[0]) {
			case Descriptor::JVM_SIGNATURE_ARRAY:
			case Descriptor::JVM_SIGNATURE_CLASS:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				fieldType field_value;
				field_value.a = currentFrame->popa();
				class_file->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_BOOLEAN:
			case Descriptor::JVM_SIGNATURE_BYTE:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				fieldType field_value;
				field_value.b = currentFrame->popb();
				class_file->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_CHAR:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				fieldType field_value;
				field_value.c = currentFrame->popc();
				class_file->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_DOUBLE:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				fieldType field_value;
				field_value.d = currentFrame->popd();
				class_file->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_FLOAT:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				fieldType field_value;
				field_value.f = currentFrame->popf();
				class_file->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_INT:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				fieldType field_value;
				field_value.i = currentFrame->popi();
				class_file->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_LONG:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				fieldType field_value;
				field_value.l = currentFrame->popl();
				class_file->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_SHORT:
			{
				ClassFile* class_file = currentProcess->getClassFile(class_name);
				fieldType field_value;
				field_value.s = currentFrame->pops();
				class_file->setField(field_name, field_value);
				break;
			}
			default:
				exit_with_massage("unkonw field type: " + field_type.data()[0]);
			}
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case getfield: //0xb4 	获取指定类的实例域，并将其值压入栈顶
		{
			u2 field_index = currentFrame->getU2();
			u2 class_index = currentFrame->classFile->constant_pools[field_index].fieldref_info.class_index;
			u2 name_type_index = currentFrame->classFile->constant_pools[field_index].fieldref_info.name_and_type_index;
			u2 class_name_index = currentFrame->classFile->constant_pools[class_index].class_info.name_index;
			u2 field_name_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.name_index;
			u2 field_type_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.descriptor_index;

			string class_name(currentFrame->classFile->constant_pools[class_name_index].utf8_info.bytes, currentFrame->classFile->constant_pools[class_name_index].utf8_info.length);
			string field_name(currentFrame->classFile->constant_pools[field_name_index].utf8_info.bytes, currentFrame->classFile->constant_pools[field_name_index].utf8_info.length);
			string field_type(currentFrame->classFile->constant_pools[field_type_index].utf8_info.bytes, currentFrame->classFile->constant_pools[field_type_index].utf8_info.length);
			switch (field_type.data()[0]) {
			case Descriptor::JVM_SIGNATURE_ARRAY:
			case Descriptor::JVM_SIGNATURE_CLASS:
			{
				u4 instance_index = currentFrame->popa();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage(instance_index + " 实例 : 不是指定类型。");
				currentFrame->pusha(instance->getField(field_name).a);
				break;
			}
			case Descriptor::JVM_SIGNATURE_BOOLEAN:
			case Descriptor::JVM_SIGNATURE_BYTE:
			{
				char instance_index = currentFrame->popb();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage(instance_index + " 实例 : 不是指定类型。");
				currentFrame->pushb(instance->getField(field_name).b);
				break;
			}
			case Descriptor::JVM_SIGNATURE_CHAR:
			{
				u2 instance_index = currentFrame->popc();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage(instance_index + " 实例 : 不是指定类型。");
				currentFrame->pushc(instance->getField(field_name).c);
				break;
			}
			case Descriptor::JVM_SIGNATURE_DOUBLE:
			{
				double instance_index = currentFrame->popd();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage("实例不是指定类型");
				currentFrame->pushd(instance->getField(field_name).d);
				break;
			}
			case Descriptor::JVM_SIGNATURE_FLOAT:
			{
				float instance_index = currentFrame->popf();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage("实例不是指定类型");
				currentFrame->pushf(instance->getField(field_name).f);
				break;
			}
			case Descriptor::JVM_SIGNATURE_INT:
			{
				int instance_index = currentFrame->popi();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage("实例不是指定类型");
				currentFrame->pushi(instance->getField(field_name).i);
				break;
			}
			case Descriptor::JVM_SIGNATURE_LONG:
			{
				long long instance_index = currentFrame->popl();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage("实例不是指定类型");
				currentFrame->pushl(instance->getField(field_name).l);
				break;
			}
			case Descriptor::JVM_SIGNATURE_SHORT:
			{
				short instance_index = currentFrame->pops();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage("实例不是指定类型");
				currentFrame->pushs(instance->getField(field_name).s);
				break;
			}
			default:
				exit_with_massage("unkonw field type: " + field_type.data()[0]);
			}
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case putfield: //0xb5 	为指定的类的实例域赋值
		{
			u2 field_index = currentFrame->getU2();
			u2 class_index = currentFrame->classFile->constant_pools[field_index].fieldref_info.class_index;
			u2 name_type_index = currentFrame->classFile->constant_pools[field_index].fieldref_info.name_and_type_index;
			u2 class_name_index = currentFrame->classFile->constant_pools[class_index].class_info.name_index;
			u2 field_name_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.name_index;
			u2 field_type_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.descriptor_index;

			string class_name(currentFrame->classFile->constant_pools[class_name_index].utf8_info.bytes, currentFrame->classFile->constant_pools[class_name_index].utf8_info.length);
			string field_name(currentFrame->classFile->constant_pools[field_name_index].utf8_info.bytes, currentFrame->classFile->constant_pools[field_name_index].utf8_info.length);
			string field_type(currentFrame->classFile->constant_pools[field_type_index].utf8_info.bytes, currentFrame->classFile->constant_pools[field_type_index].utf8_info.length);
			switch (field_type.data()[0]) {
			case Descriptor::JVM_SIGNATURE_ARRAY:
			case Descriptor::JVM_SIGNATURE_CLASS:
			{
				u4 value = currentFrame->popa();
				u4 instance_index = currentFrame->popa();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage(instance_index+" 实例 : 不是指定类型。");
				fieldType field_value;
				field_value.a = value;
				instance->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_BOOLEAN:
			case Descriptor::JVM_SIGNATURE_BYTE:
			{
				char value = currentFrame->popb();
				u4 instance_index = currentFrame->popa();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage(instance_index + " 实例 : 不是指定类型。");
				fieldType field_value;
				field_value.b = value;
				instance->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_CHAR:
			{
				u2 value = currentFrame->popc();
				u4 instance_index = currentFrame->popa();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage(instance_index + " 实例 : 不是指定类型。");
				fieldType field_value;
				field_value.c = value;
				instance->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_DOUBLE:
			{
				double value = currentFrame->popd();
				u4 instance_index = currentFrame->popa();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage(instance_index + " 实例 : 不是指定类型。");
				fieldType field_value;
				field_value.d = value;
				instance->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_FLOAT:
			{
				float value = currentFrame->popf();
				u4 instance_index = currentFrame->popa();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage(instance_index + " 实例 : 不是指定类型。");
				fieldType field_value;
				field_value.f = value;
				instance->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_INT:
			{
				int value = currentFrame->popi();
				u4 instance_index = currentFrame->popa();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage(instance_index + " 实例 : 不是指定类型。");
				fieldType field_value;
				field_value.i = value;
				instance->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_LONG:
			{
				long long  value = currentFrame->popl();
				u4 instance_index = currentFrame->popa();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage(instance_index + " 实例 : 不是指定类型。");
				fieldType field_value;
				field_value.l = value;
				instance->setField(field_name, field_value);
				break;
			}
			case Descriptor::JVM_SIGNATURE_SHORT:
			{
				short  value = currentFrame->pops();
				u4 instance_index = currentFrame->popa();
				Instance* instance = currentProcess->getInstance(instance_index);
				if (instance->class_name.compare(class_name) != 0)
					exit_with_massage(instance_index + " 实例 : 不是指定类型。");
				fieldType field_value;
				field_value.s = value;
				instance->setField(field_name, field_value);
				break;
			}
			default:
				exit_with_massage("unkonw field type: " + field_type.data()[0]);
			}
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case invokevirtual: //0xb6 	调用实例方法
		{
			u2 index = currentFrame->getU2();

			u2 class_index = currentFrame->classFile->constant_pools[index].methodref_info.class_index;
			u2 name_type_index = currentFrame->classFile->constant_pools[index].methodref_info.name_and_type_index;

			u2 utf8_class_index = currentFrame->classFile->constant_pools[class_index].class_info.name_index;
			u2 utf8_name_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.name_index;
			u2 utf8_type_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.descriptor_index;

			string class_name(currentFrame->classFile->constant_pools[utf8_class_index].utf8_info.bytes, currentFrame->classFile->constant_pools[utf8_class_index].utf8_info.length);
			string method_name(currentFrame->classFile->constant_pools[utf8_name_index].utf8_info.bytes, currentFrame->classFile->constant_pools[utf8_name_index].utf8_info.length);
			string method_descriptor(currentFrame->classFile->constant_pools[utf8_type_index].utf8_info.bytes, currentFrame->classFile->constant_pools[utf8_type_index].utf8_info.length);
			StackFrame* new_frame = new StackFrame(currentProcess->getClassFile(class_name), class_name,method_name, method_descriptor);
			stack<char> args;
			for (int i = 0; i < method_descriptor.length(); i++) {//解析参数列表
				if (method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_FUNC)
					continue;
				else if (method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_ARRAY || method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_CLASS) {
					args.push(method_descriptor.data()[i]);
					do {
						i++;
					} while (method_descriptor.data()[i] != Descriptor::JVM_SIGNATURE_ENDCLASS);
				}
				else if (method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_DOUBLE || method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_LONG) {
					args.push(method_descriptor.data()[i]);
					args.push(method_descriptor.data()[i]);
				}
				else if (method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_ENDFUNC)
					break;
				else
					args.push(method_descriptor.data()[i]);
			}
			while (!args.empty()) {
				switch (args.top())
				{
				case Descriptor::JVM_SIGNATURE_ARRAY:
					new_frame->storea(args.size(), currentFrame->popa());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_BOOLEAN:
					new_frame->storeb(args.size(), currentFrame->popb());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_BYTE:
					new_frame->storeb(args.size(), currentFrame->popb());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_CHAR:
					new_frame->storec(args.size(), currentFrame->popc());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_DOUBLE:
					new_frame->stored(args.size() - 1, currentFrame->popd());
					args.pop();
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_FLOAT:
					new_frame->storef(args.size(), currentFrame->popf());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_INT:
					new_frame->storei(args.size(), currentFrame->popi());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_LONG:
					new_frame->storel(args.size() - 1, currentFrame->popl());
					args.pop();
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_SHORT:
					new_frame->stores(args.size(), currentFrame->pops());
					args.pop();
					break;
				default:
					exit_with_massage("未知的参数类型 : " + args.top());
				}
			}

			new_frame->storea(0, currentFrame->popa());//存入实例的引用
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			currentThread->VMStack.push(new_frame);
			currentFrame = new_frame;
			break;
		}
		case invokespecial: //0xb7 	调用超类构造方法，实例初始化方法，私有方法
		{
			u2 index = currentFrame->getU2();

			u2 class_index = currentFrame->classFile->constant_pools[index].methodref_info.class_index;
			u2 name_type_index = currentFrame->classFile->constant_pools[index].methodref_info.name_and_type_index;

			u2 utf8_class_index = currentFrame->classFile->constant_pools[class_index].class_info.name_index;
			u2 utf8_name_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.name_index;
			u2 utf8_type_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.descriptor_index;

			string class_name(currentFrame->classFile->constant_pools[utf8_class_index].utf8_info.bytes, currentFrame->classFile->constant_pools[utf8_class_index].utf8_info.length);
			string method_name(currentFrame->classFile->constant_pools[utf8_name_index].utf8_info.bytes, currentFrame->classFile->constant_pools[utf8_name_index].utf8_info.length);
			string method_descriptor(currentFrame->classFile->constant_pools[utf8_type_index].utf8_info.bytes, currentFrame->classFile->constant_pools[utf8_type_index].utf8_info.length);
			StackFrame* new_frame = new StackFrame(currentProcess->getClassFile(class_name),class_name, method_name, method_descriptor);
			stack<char> args;
			for (int i = 0; i < method_descriptor.length(); i++) {//解析参数列表
				if (method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_FUNC)
					continue;
				else if (method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_ARRAY || method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_CLASS) {
					args.push(method_descriptor.data()[i]);
					do {
						i++;
					} while (method_descriptor.data()[i] != Descriptor::JVM_SIGNATURE_ENDCLASS);
				}
				else if (method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_DOUBLE || method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_LONG) {
					args.push(method_descriptor.data()[i]);
					args.push(method_descriptor.data()[i]);
				}
				else if (method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_ENDFUNC)
					break;
				else
					args.push(method_descriptor.data()[i]);
			}
			while (!args.empty()) {
				switch (args.top())
				{
				case Descriptor::JVM_SIGNATURE_ARRAY:
					new_frame->storea(args.size(), currentFrame->popa());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_BOOLEAN:
					new_frame->storeb(args.size(), currentFrame->popb());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_BYTE:
					new_frame->storeb(args.size() , currentFrame->popb());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_CHAR:
					new_frame->storec(args.size() , currentFrame->popc());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_DOUBLE:
					new_frame->stored(args.size() - 1, currentFrame->popd());
					args.pop();
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_FLOAT:
					new_frame->storef(args.size() , currentFrame->popf());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_INT:
					new_frame->storei(args.size() , currentFrame->popi());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_LONG:
					new_frame->storel(args.size() - 1, currentFrame->popl());
					args.pop();
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_SHORT:
					new_frame->stores(args.size() , currentFrame->pops());
					args.pop();
					break;
				default:
					exit_with_massage("未知的参数类型 : " + args.top());
				}
			}

			new_frame->storea(0, currentFrame->popa());//存入实例的引用
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			currentThread->VMStack.push(new_frame);
			currentFrame = new_frame;
			break;
		}
		case invokestatic: //0xb8 	调用静态方法
		{
			u2 index = currentFrame->getU2();

			u2 class_index = currentFrame->classFile->constant_pools[index].methodref_info.class_index;
			u2 name_type_index = currentFrame->classFile->constant_pools[index].methodref_info.name_and_type_index;

			u2 utf8_class_index = currentFrame->classFile->constant_pools[class_index].class_info.name_index;
			u2 utf8_name_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.name_index;
			u2 utf8_type_index = currentFrame->classFile->constant_pools[name_type_index].nameAndType_info.descriptor_index;

			string class_name(currentFrame->classFile->constant_pools[utf8_class_index].utf8_info.bytes, currentFrame->classFile->constant_pools[utf8_class_index].utf8_info.length);
			string method_name(currentFrame->classFile->constant_pools[utf8_name_index].utf8_info.bytes, currentFrame->classFile->constant_pools[utf8_name_index].utf8_info.length);
			string method_descriptor(currentFrame->classFile->constant_pools[utf8_type_index].utf8_info.bytes, currentFrame->classFile->constant_pools[utf8_type_index].utf8_info.length);
			StackFrame* new_frame = new StackFrame(currentProcess->getClassFile(class_name),class_name, method_name, method_descriptor);
			stack<char> args;
			for (int i = 0; i < method_descriptor.length(); i++) {//解析参数列表
				if (method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_FUNC)
					continue;
				else if (method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_ARRAY || method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_CLASS) {
					args.push(method_descriptor.data()[i]);
					do {
						i++;
					} while (method_descriptor.data()[i] != Descriptor::JVM_SIGNATURE_ENDCLASS);
				}
				else if (method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_DOUBLE || method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_LONG) {
					args.push(method_descriptor.data()[i]);
					args.push(method_descriptor.data()[i]);
				}
				else if (method_descriptor.data()[i] == Descriptor::JVM_SIGNATURE_ENDFUNC)
					break;
				else
					args.push(method_descriptor.data()[i]);
			}
			while (!args.empty()) {
				switch (args.top())
				{
				case Descriptor::JVM_SIGNATURE_ARRAY:
					new_frame->storea(args.size()-1,currentFrame->popa());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_BOOLEAN:
					new_frame->storeb(args.size() - 1, currentFrame->popb());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_BYTE:
					new_frame->storeb(args.size() - 1, currentFrame->popb());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_CHAR:
					new_frame->storec(args.size() - 1, currentFrame->popc());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_DOUBLE:
					new_frame->stored(args.size() - 2, currentFrame->popd());
					args.pop();
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_FLOAT:
					new_frame->storef(args.size() - 1, currentFrame->popf());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_INT:
					new_frame->storei(args.size() - 1, currentFrame->popi());
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_LONG:
					new_frame->storel(args.size() - 2, currentFrame->popl());
					args.pop();
					args.pop();
					break;
				case Descriptor::JVM_SIGNATURE_SHORT:
					new_frame->stores(args.size() - 1, currentFrame->pops());
					args.pop();
					break;
				default:
					exit_with_massage("未知的参数类型 : " + args.top());
				}
			}

			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			currentThread->VMStack.push(new_frame);
			currentFrame = new_frame;
			break;
		}
		case invokeinterface: //0xb9 	调用接口方法
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case invokedynamic: //0xba 	调用动态方法
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case new_: //0xbb 	创建一个对象，并将其引用值压入栈顶
		{
			u2 class_index = currentFrame->getU2();
			u2 class_name_index = currentFrame->classFile->constant_pools[class_index].class_info.name_index;
			string class_name(currentFrame->classFile->constant_pools[class_name_index].utf8_info.bytes, currentFrame->classFile->constant_pools[class_name_index].utf8_info.length);
			ClassFile* class_file = currentProcess->getClassFile(class_name);
			currentFrame->pusha( currentProcess->newInstance(class_name,class_file));
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case newarray: //0xbc 	创建一个指定原始类型（如int, float, char…）的数组，并将其引用值压入栈顶
		{
			u4 index = arrays->newArray();
			gava_array* a = arrays->getArray(index);
			char type = currentFrame->getU1();
			u4 length = currentFrame->popa();
			a->array_length = length;
			switch (type) 
			{
			case ArrayType::JVM_T_BOOLEAN:
				a->array_date->boolean_array = new char[length]();
				a->array_type = ArrayType::JVM_T_BOOLEAN;
				break;
			case ArrayType::JVM_T_BYTE:
				a->array_date->byte_array = new char[length]();
				a->array_type = ArrayType::JVM_T_BYTE;
				break;
			case ArrayType::JVM_T_CHAR:
				a->array_date->char_array = new u2[length]();
				a->array_type = ArrayType::JVM_T_CHAR;
				break;
			case ArrayType::JVM_T_DOUBLE:
				a->array_date->double_array = new double[length]();
				a->array_type = ArrayType::JVM_T_DOUBLE;
				break;
			case ArrayType::JVM_T_FLOAT:
				a->array_date->float_array = new float[length]();
				a->array_type = ArrayType::JVM_T_FLOAT;
				break;
			case ArrayType::JVM_T_INT:
				a->array_date->int_array = new int[length]();
				a->array_type = ArrayType::JVM_T_INT;
				break;
			case ArrayType::JVM_T_LONG:
				a->array_date->long_array = new long long[length]();
				a->array_type = ArrayType::JVM_T_LONG;
				break;
			case ArrayType::JVM_T_SHORT:
				a->array_date->short_array = new short[length]();
				a->array_type = ArrayType::JVM_T_SHORT;
				break;
			default:
				//释放数组
				a->array_date = NULL;
				a->array_length = 0;
				arrays->deleteArray(index);
				break;
			}
			currentFrame->pusha(index);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		}
		case anewarray: //0xbd 	创建一个引用型（如类，接口，数组）的数组，并将其引用值压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case arraylength: //0xbe 	获得数组的长度值并压入栈顶
			currentFrame->pushi(arrays->getArray(currentFrame->popa())->array_length);
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case athrow: //0xbf 	将栈顶的异常抛出
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case checkcast: //0xc0 	检验类型转换，检验未通过将抛出ClassCastException
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case instanceof: //0xc1 	检验对象是否是指定的类的实例，如果是将1压入栈顶，否则将0压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case monitorenter: //0xc2 	获得对象的锁，用于同步方法或同步块
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case monitorexit: //0xc3 	释放对象的锁，用于同步方法或同步块
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case wide: //0xc4 	<待补充>
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case multianewarray: //0xc5 	创建指定类型和指定维度的多维数组（执行该指令时，操作栈中必须包含各维度的长度值），并将其引用值压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifnull: //0xc6 	为null时跳转
			if (currentFrame->popa() == null)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifnonnull: //0xc7 	不为null时跳转
			if (currentFrame->popa() != null)
				currentFrame->goto_(currentFrame->getU2());
			else
				currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case goto_w: //0xc8 	无条件跳转（宽索引）
			currentFrame->goto_(currentFrame->getU4());
			break;
		case jsr_w: //0xc9    jsr_w	跳转至指定32位offset位置，并将jsr_w下一条指令地址压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		default:
			cerr << "UnKnow opcode" << endl;
			exit(-1);
			break;
		}

		if (isVisualized) {
			currentProcess->printProcess();
		}
	}
}

ExecuteEngine::~ExecuteEngine()
{
}
