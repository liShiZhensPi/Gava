#include "ExecuteEngine.h"



ExecuteEngine::ExecuteEngine(Process *process)
{
	this->currentProcess = process;
	this->currentThread = process->getMainThread();
	this->currentClass = process->getMainClass();
	this->currentFrame = currentThread->getStackFrame();
}

void ExecuteEngine::execute() {
	short opcode_length[] = JVM_OPCODE_LENGTH_INITIALIZER;
	int flag = 0;
	while (currentFrame->hasCode()) {
		u1 code = currentFrame->getCode();
		switch (code)
		{
		case nop: //0x00 	什么都不做
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aconst_null: //0x01 	将null推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_m1: //0x02 	将int型-1推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_0: //0x03 	将int型0推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_1: //0x04 	将int型1推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_2: //0x05 	将int型2推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_3: //0x06 	将int型3推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_4: //0x07 	将int型4推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_5: //0x08 	将int型5推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lconst_0: //0x09 	将long型0推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lconst_1: //0x0a 	将long型1推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fconst_0: //0x0b 	将float型0推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fconst_1: //0x0c 	将float型1推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fconst_2: //0x0d 	将float型2推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dconst_0: //0x0e 	将do le型0推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dconst_1: //0x0f 	将do le型1推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case bipush: //0x10 	将单字节的常量值(-128~127)推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case sipush: //0x11 	将一个短整型常量值(-32768~32767)推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ldc: //0x12 	将int, float或String型常量值从常量池中推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ldc_w: //0x13 	将int, float或String型常量值从常量池中推送至栈顶（宽索引）
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ldc2_w: //0x14 	将long或do le型常量值从常量池中推送至栈顶（宽索引）
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload: //0x15 	将指定的int型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload: //0x16 	将指定的long型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload: //0x17 	将指定的float型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload: //0x18 	将指定的do le型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload: //0x19 	将指定的引用类型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload_0: //0x1a 	将第一个int型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload_1: //0x1b 	将第二个int型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload_2: //0x1c 	将第三个int型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload_3: //0x1d 	将第四个int型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload_0: //0x1e 	将第一个long型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload_1: //0x1f 	将第二个long型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload_2: //0x20 	将第三个long型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload_3: //0x21 	将第四个long型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload_0: //0x22 	将第一个float型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload_1: //0x23 	将第二个float型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload_2: //0x24 	将第三个float型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload_3: //0x25 	将第四个float型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload_0: //0x26 	将第一个do le型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload_1: //0x27 	将第二个do le型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload_2: //0x28 	将第三个do le型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload_3: //0x29 	将第四个do le型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload_0: //0x2a 	将第一个引用类型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload_1: //0x2b 	将第二个引用类型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload_2: //0x2c 	将第三个引用类型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload_3: //0x2d 	将第四个引用类型本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iaload: //0x2e 	将int型数组指定索引的值推送至栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
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
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore: //0x37 	将栈顶long型数值存入指定本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore: //0x38 	将栈顶float型数值存入指定本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore: //0x39 	将栈顶do le型数值存入指定本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore: //0x3a 	将栈顶引用型数值存入指定本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore_0: //0x3b 	将栈顶int型数值存入第一个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore_1: //0x3c 	将栈顶int型数值存入第二个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore_2: //0x3d 	将栈顶int型数值存入第三个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore_3: //0x3e 	将栈顶int型数值存入第四个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore_0: //0x3f 	将栈顶long型数值存入第一个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore_1: //0x40 	将栈顶long型数值存入第二个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore_2: //0x41 	将栈顶long型数值存入第三个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore_3: //0x42 	将栈顶long型数值存入第四个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore_0: //0x43 	将栈顶float型数值存入第一个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore_1: //0x44 	将栈顶float型数值存入第二个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore_2: //0x45 	将栈顶float型数值存入第三个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore_3: //0x46 	将栈顶float型数值存入第四个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore_0: //0x47 	将栈顶do le型数值存入第一个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore_1: //0x48 	将栈顶do le型数值存入第二个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore_2: //0x49 	将栈顶do le型数值存入第三个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore_3: //0x4a 	将栈顶do le型数值存入第四个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore_0: //0x4b 	将栈顶引用型数值存入第一个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore_1: //0x4c 	将栈顶引用型数值存入第二个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore_2: //0x4d 	将栈顶引用型数值存入第三个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore_3: //0x4e 	将栈顶引用型数值存入第四个本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iastore: //0x4f 	将栈顶int型数值存入指定数组的指定索引位置
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
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
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case pop2: //0x58 	将栈顶的一个（long或do le类型的)或两个数值弹出（其它）
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup: //0x59 	复制栈顶数值并将复制值压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup_x1: //0x5a 	复制栈顶数值并将两个复制值压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup_x2: //0x5b 	复制栈顶数值并将三个（或两个）复制值压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup2: //0x5c 	复制栈顶一个（long或do le类型的)或两个（其它）数值并将复制值压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup2_x1: //0x5d 	dup_x1 指令的双倍版本
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup2_x2: //0x5e 	dup_x2 指令的双倍版本
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case swap_: //0x5f 	将栈最顶端的两个数值互换(数值不能是long或do le类型的)
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iadd: //0x60 	将栈顶两int型数值相加并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ladd: //0x61 	将栈顶两long型数值相加并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fadd: //0x62 	将栈顶两float型数值相加并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dadd: //0x63 	将栈顶两do le型数值相加并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case is: //0x64 	将栈顶两int型数值相减并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ls: //0x65 	将栈顶两long型数值相减并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fs: //0x66 	将栈顶两float型数值相减并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ds: //0x67 	将栈顶两do le型数值相减并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case imul: //0x68 	将栈顶两int型数值相乘并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lmul: //0x69 	将栈顶两long型数值相乘并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fmul: //0x6a 	将栈顶两float型数值相乘并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dmul: //0x6b 	将栈顶两do le型数值相乘并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case idiv: //0x6c 	将栈顶两int型数值相除并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ldiv_: //0x6d 	将栈顶两long型数值相除并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fdiv: //0x6e 	将栈顶两float型数值相除并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ddiv: //0x6f 	将栈顶两do le型数值相除并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case irem: //0x70 	将栈顶两int型数值作取模运算并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lrem: //0x71 	将栈顶两long型数值作取模运算并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case frem: //0x72 	将栈顶两float型数值作取模运算并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case drem: //0x73 	将栈顶两do le型数值作取模运算并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ineg: //0x74 	将栈顶int型数值取负并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lneg: //0x75 	将栈顶long型数值取负并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fneg: //0x76 	将栈顶float型数值取负并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dneg: //0x77 	将栈顶do le型数值取负并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ishl: //0x78 	将int型数值左移位指定位数并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lshl: //0x79 	将long型数值左移位指定位数并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ishr: //0x7a 	将int型数值右（符号）移位指定位数并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lshr: //0x7b 	将long型数值右（符号）移位指定位数并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iushr: //0x7c 	将int型数值右（无符号）移位指定位数并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lushr: //0x7d 	将long型数值右（无符号）移位指定位数并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iand: //0x7e 	将栈顶两int型数值作“按位与”并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case land: //0x7f 	将栈顶两long型数值作“按位与”并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ior: //0x80 	将栈顶两int型数值作“按位或”并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lor: //0x81 	将栈顶两long型数值作“按位或”并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ixor: //0x82 	将栈顶两int型数值作“按位异或”并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lxor: //0x83 	将栈顶两long型数值作“按位异或”并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iinc: //0x84 	将指定int型变量增加指定值（i++, i–, i+=2）
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2l: //0x85 	将栈顶int型数值强制转换成long型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2f: //0x86 	将栈顶int型数值强制转换成float型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2d: //0x87 	将栈顶int型数值强制转换成doule型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case l2i: //0x88 	将栈顶long型数值强制转换成int型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case l2f: //0x89 	将栈顶long型数值强制转换成float型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case l2d: //0x8a 	将栈顶long型数值强制转换成doule型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case f2i: //0x8b 	将栈顶float型数值强制转换成int型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case f2l: //0x8c 	将栈顶float型数值强制转换成long型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case f2d: //0x8d 	将栈顶float型数值强制转换成doule型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case d2i: //0x8e 	将栈顶do le型数值强制转换成int型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case d2l: //0x8f 	将栈顶do le型数值强制转换成long型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case d2f: //0x90 	将栈顶do le型数值强制转换成float型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2b: //0x91 	将栈顶int型数值强制转换成byte型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2c: //0x92 	将栈顶int型数值强制转换成char型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2s: //0x93 	将栈顶int型数值强制转换成short型数值并将结果压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lcmp: //0x94 	比较栈顶两long型数值大小，并将结果（1，0，-1）压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fcmpl: //0x95 	比较栈顶两float型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将-1压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fcmpg: //0x96 	比较栈顶两float型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将1压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dcmpl: //0x97 	比较栈顶两do le型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将-1压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dcmpg: //0x98 	比较栈顶两do le型数值大小，并将结果（1，0，-1）压入栈顶；当其中一个数值为NaN时，将1压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifeq: //0x99 	当栈顶int型数值等于0时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifne: //0x9a 	当栈顶int型数值不等于0时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iflt: //0x9b 	当栈顶int型数值小于0时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifge: //0x9c 	当栈顶int型数值大于等于0时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifgt: //0x9d 	当栈顶int型数值大于0时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifle: //0x9e 	当栈顶int型数值小于等于0时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmpeq: //0x9f 	比较栈顶两int型数值大小，当结果等于0时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmpne: //0xa0 	比较栈顶两int型数值大小，当结果不等于0时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmplt: //0xa1 	比较栈顶两int型数值大小，当结果小于0时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmpge: //0xa2 	比较栈顶两int型数值大小，当结果大于等于0时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmpgt: //0xa3 	比较栈顶两int型数值大小，当结果大于0时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmple: //0xa4 	比较栈顶两int型数值大小，当结果小于等于0时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_acmpeq: //0xa5 	比较栈顶两引用型数值，当结果相等时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_acmpne: //0xa6 	比较栈顶两引用型数值，当结果不相等时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case goto_: //0xa7 	无条件跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case jsr: //0xa8 	跳转至指定16位offset位置，并将jsr下一条指令地址压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ret: //0xa9 	返回至本地变量
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case tableswitch: //0xaa 	用于switch条件跳转，case值连续（可变长度指令）
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lookupswitch: //0xab 	用于switch条件跳转，case值不连续（可变长度指令）
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ireturn: //0xac 	从当前方法返回int
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lreturn: //0xad 	从当前方法返回long
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case freturn: //0xae 	从当前方法返回float
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dreturn: //0xaf 	从当前方法返回do le
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case areturn: //0xb0 	从当前方法返回对象引用
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case return_: //0xb1 	从当前方法返回void
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case getstatic: //0xb2 	获取指定类的静态域，并将其值压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case putstatic: //0xb3 	为指定的类的静态域赋值
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case getfield: //0xb4 	获取指定类的实例域，并将其值压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case putfield: //0xb5 	为指定的类的实例域赋值
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case invokevirtual: //0xb6 	调用实例方法
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case invokespecial: //0xb7 	调用超类构造方法，实例初始化方法，私有方法
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case invokestatic: //0xb8 	调用静态方法
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case invokeinterface: //0xb9 	调用接口方法
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case invokedynamic: //0xba 	调用动态方法
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case new_: //0xbb 	创建一个对象，并将其引用值压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case newarray: //0xbc 	创建一个指定原始类型（如int, float, char…）的数组，并将其引用值压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case anewarray: //0xbd 	创建一个引用型（如类，接口，数组）的数组，并将其引用值压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case arraylength: //0xbe 	获得数组的长度值并压入栈顶
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
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifnonnull: //0xc7 	不为null时跳转
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case goto_w: //0xc8 	无条件跳转（宽索引）
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case jsr_w: //0xc9    jsr_w	跳转至指定32位offset位置，并将jsr_w下一条指令地址压入栈顶
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		default:
			cerr << "UnKnow opcode" << endl;
			exit(-1);
			break;
		}
	}
}

ExecuteEngine::~ExecuteEngine()
{
}
