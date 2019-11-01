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
		case nop: //0x00 	ʲô������
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aconst_null: //0x01 	��null������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_m1: //0x02 	��int��-1������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_0: //0x03 	��int��0������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_1: //0x04 	��int��1������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_2: //0x05 	��int��2������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_3: //0x06 	��int��3������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_4: //0x07 	��int��4������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iconst_5: //0x08 	��int��5������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lconst_0: //0x09 	��long��0������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lconst_1: //0x0a 	��long��1������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fconst_0: //0x0b 	��float��0������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fconst_1: //0x0c 	��float��1������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fconst_2: //0x0d 	��float��2������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dconst_0: //0x0e 	��do le��0������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dconst_1: //0x0f 	��do le��1������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case bipush: //0x10 	�����ֽڵĳ���ֵ(-128~127)������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case sipush: //0x11 	��һ�������ͳ���ֵ(-32768~32767)������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ldc: //0x12 	��int, float��String�ͳ���ֵ�ӳ�������������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ldc_w: //0x13 	��int, float��String�ͳ���ֵ�ӳ�������������ջ������������
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ldc2_w: //0x14 	��long��do le�ͳ���ֵ�ӳ�������������ջ������������
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload: //0x15 	��ָ����int�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload: //0x16 	��ָ����long�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload: //0x17 	��ָ����float�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload: //0x18 	��ָ����do le�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload: //0x19 	��ָ�����������ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload_0: //0x1a 	����һ��int�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload_1: //0x1b 	���ڶ���int�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload_2: //0x1c 	��������int�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iload_3: //0x1d 	�����ĸ�int�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload_0: //0x1e 	����һ��long�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload_1: //0x1f 	���ڶ���long�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload_2: //0x20 	��������long�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lload_3: //0x21 	�����ĸ�long�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload_0: //0x22 	����һ��float�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload_1: //0x23 	���ڶ���float�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload_2: //0x24 	��������float�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fload_3: //0x25 	�����ĸ�float�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload_0: //0x26 	����һ��do le�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload_1: //0x27 	���ڶ���do le�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload_2: //0x28 	��������do le�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dload_3: //0x29 	�����ĸ�do le�ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload_0: //0x2a 	����һ���������ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload_1: //0x2b 	���ڶ����������ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload_2: //0x2c 	���������������ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aload_3: //0x2d 	�����ĸ��������ͱ��ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iaload: //0x2e 	��int������ָ��������ֵ������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case laload: //0x2f 	��long������ָ��������ֵ������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case faload: //0x30 	��float������ָ��������ֵ������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case daload: //0x31 	��do le������ָ��������ֵ������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aaload: //0x32 	������������ָ��������ֵ������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case baload: //0x33 	��boolean��byte������ָ��������ֵ������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case caload: //0x34 	��char������ָ��������ֵ������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case saload: //0x35 	��short������ָ��������ֵ������ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore: //0x36 	��ջ��int����ֵ����ָ�����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore: //0x37 	��ջ��long����ֵ����ָ�����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore: //0x38 	��ջ��float����ֵ����ָ�����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore: //0x39 	��ջ��do le����ֵ����ָ�����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore: //0x3a 	��ջ����������ֵ����ָ�����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore_0: //0x3b 	��ջ��int����ֵ�����һ�����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore_1: //0x3c 	��ջ��int����ֵ����ڶ������ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore_2: //0x3d 	��ջ��int����ֵ������������ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case istore_3: //0x3e 	��ջ��int����ֵ������ĸ����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore_0: //0x3f 	��ջ��long����ֵ�����һ�����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore_1: //0x40 	��ջ��long����ֵ����ڶ������ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore_2: //0x41 	��ջ��long����ֵ������������ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lstore_3: //0x42 	��ջ��long����ֵ������ĸ����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore_0: //0x43 	��ջ��float����ֵ�����һ�����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore_1: //0x44 	��ջ��float����ֵ����ڶ������ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore_2: //0x45 	��ջ��float����ֵ������������ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fstore_3: //0x46 	��ջ��float����ֵ������ĸ����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore_0: //0x47 	��ջ��do le����ֵ�����һ�����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore_1: //0x48 	��ջ��do le����ֵ����ڶ������ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore_2: //0x49 	��ջ��do le����ֵ������������ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dstore_3: //0x4a 	��ջ��do le����ֵ������ĸ����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore_0: //0x4b 	��ջ����������ֵ�����һ�����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore_1: //0x4c 	��ջ����������ֵ����ڶ������ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore_2: //0x4d 	��ջ����������ֵ������������ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case astore_3: //0x4e 	��ջ����������ֵ������ĸ����ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iastore: //0x4f 	��ջ��int����ֵ����ָ�������ָ������λ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lastore: //0x50 	��ջ��long����ֵ����ָ�������ָ������λ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fastore: //0x51 	��ջ��float����ֵ����ָ�������ָ������λ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dastore: //0x52 	��ջ��do le����ֵ����ָ�������ָ������λ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case aastore: //0x53 	��ջ����������ֵ����ָ�������ָ������λ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case bastore: //0x54 	��ջ��boolean��byte����ֵ����ָ�������ָ������λ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case castore: //0x55 	��ջ��char����ֵ����ָ�������ָ������λ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case sastore: //0x56 	��ջ��short����ֵ����ָ�������ָ������λ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case pop: //0x57 	��ջ����ֵ���� (��ֵ������long��do le���͵�)
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case pop2: //0x58 	��ջ����һ����long��do le���͵�)��������ֵ������������
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup: //0x59 	����ջ����ֵ��������ֵѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup_x1: //0x5a 	����ջ����ֵ������������ֵѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup_x2: //0x5b 	����ջ����ֵ����������������������ֵѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup2: //0x5c 	����ջ��һ����long��do le���͵�)����������������ֵ��������ֵѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup2_x1: //0x5d 	dup_x1 ָ���˫���汾
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dup2_x2: //0x5e 	dup_x2 ָ���˫���汾
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case swap_: //0x5f 	��ջ��˵�������ֵ����(��ֵ������long��do le���͵�)
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iadd: //0x60 	��ջ����int����ֵ��Ӳ������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ladd: //0x61 	��ջ����long����ֵ��Ӳ������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fadd: //0x62 	��ջ����float����ֵ��Ӳ������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dadd: //0x63 	��ջ����do le����ֵ��Ӳ������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case is: //0x64 	��ջ����int����ֵ����������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ls: //0x65 	��ջ����long����ֵ����������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fs: //0x66 	��ջ����float����ֵ����������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ds: //0x67 	��ջ����do le����ֵ����������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case imul: //0x68 	��ջ����int����ֵ��˲������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lmul: //0x69 	��ջ����long����ֵ��˲������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fmul: //0x6a 	��ջ����float����ֵ��˲������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dmul: //0x6b 	��ջ����do le����ֵ��˲������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case idiv: //0x6c 	��ջ����int����ֵ����������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ldiv_: //0x6d 	��ջ����long����ֵ����������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fdiv: //0x6e 	��ջ����float����ֵ����������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ddiv: //0x6f 	��ջ����do le����ֵ����������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case irem: //0x70 	��ջ����int����ֵ��ȡģ���㲢�����ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lrem: //0x71 	��ջ����long����ֵ��ȡģ���㲢�����ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case frem: //0x72 	��ջ����float����ֵ��ȡģ���㲢�����ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case drem: //0x73 	��ջ����do le����ֵ��ȡģ���㲢�����ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ineg: //0x74 	��ջ��int����ֵȡ���������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lneg: //0x75 	��ջ��long����ֵȡ���������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fneg: //0x76 	��ջ��float����ֵȡ���������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dneg: //0x77 	��ջ��do le����ֵȡ���������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ishl: //0x78 	��int����ֵ����λָ��λ���������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lshl: //0x79 	��long����ֵ����λָ��λ���������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ishr: //0x7a 	��int����ֵ�ң����ţ���λָ��λ���������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lshr: //0x7b 	��long����ֵ�ң����ţ���λָ��λ���������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iushr: //0x7c 	��int����ֵ�ң��޷��ţ���λָ��λ���������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lushr: //0x7d 	��long����ֵ�ң��޷��ţ���λָ��λ���������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iand: //0x7e 	��ջ����int����ֵ������λ�롱�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case land: //0x7f 	��ջ����long����ֵ������λ�롱�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ior: //0x80 	��ջ����int����ֵ������λ�򡱲������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lor: //0x81 	��ջ����long����ֵ������λ�򡱲������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ixor: //0x82 	��ջ����int����ֵ������λ��򡱲������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lxor: //0x83 	��ջ����long����ֵ������λ��򡱲������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iinc: //0x84 	��ָ��int�ͱ�������ָ��ֵ��i++, i�C, i+=2��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2l: //0x85 	��ջ��int����ֵǿ��ת����long����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2f: //0x86 	��ջ��int����ֵǿ��ת����float����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2d: //0x87 	��ջ��int����ֵǿ��ת����doule����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case l2i: //0x88 	��ջ��long����ֵǿ��ת����int����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case l2f: //0x89 	��ջ��long����ֵǿ��ת����float����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case l2d: //0x8a 	��ջ��long����ֵǿ��ת����doule����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case f2i: //0x8b 	��ջ��float����ֵǿ��ת����int����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case f2l: //0x8c 	��ջ��float����ֵǿ��ת����long����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case f2d: //0x8d 	��ջ��float����ֵǿ��ת����doule����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case d2i: //0x8e 	��ջ��do le����ֵǿ��ת����int����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case d2l: //0x8f 	��ջ��do le����ֵǿ��ת����long����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case d2f: //0x90 	��ջ��do le����ֵǿ��ת����float����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2b: //0x91 	��ջ��int����ֵǿ��ת����byte����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2c: //0x92 	��ջ��int����ֵǿ��ת����char����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case i2s: //0x93 	��ջ��int����ֵǿ��ת����short����ֵ�������ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lcmp: //0x94 	�Ƚ�ջ����long����ֵ��С�����������1��0��-1��ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fcmpl: //0x95 	�Ƚ�ջ����float����ֵ��С�����������1��0��-1��ѹ��ջ����������һ����ֵΪNaNʱ����-1ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case fcmpg: //0x96 	�Ƚ�ջ����float����ֵ��С�����������1��0��-1��ѹ��ջ����������һ����ֵΪNaNʱ����1ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dcmpl: //0x97 	�Ƚ�ջ����do le����ֵ��С�����������1��0��-1��ѹ��ջ����������һ����ֵΪNaNʱ����-1ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dcmpg: //0x98 	�Ƚ�ջ����do le����ֵ��С�����������1��0��-1��ѹ��ջ����������һ����ֵΪNaNʱ����1ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifeq: //0x99 	��ջ��int����ֵ����0ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifne: //0x9a 	��ջ��int����ֵ������0ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case iflt: //0x9b 	��ջ��int����ֵС��0ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifge: //0x9c 	��ջ��int����ֵ���ڵ���0ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifgt: //0x9d 	��ջ��int����ֵ����0ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifle: //0x9e 	��ջ��int����ֵС�ڵ���0ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmpeq: //0x9f 	�Ƚ�ջ����int����ֵ��С�����������0ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmpne: //0xa0 	�Ƚ�ջ����int����ֵ��С�������������0ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmplt: //0xa1 	�Ƚ�ջ����int����ֵ��С�������С��0ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmpge: //0xa2 	�Ƚ�ջ����int����ֵ��С����������ڵ���0ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmpgt: //0xa3 	�Ƚ�ջ����int����ֵ��С�����������0ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_icmple: //0xa4 	�Ƚ�ջ����int����ֵ��С�������С�ڵ���0ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_acmpeq: //0xa5 	�Ƚ�ջ������������ֵ����������ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case if_acmpne: //0xa6 	�Ƚ�ջ������������ֵ������������ʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case goto_: //0xa7 	��������ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case jsr: //0xa8 	��ת��ָ��16λoffsetλ�ã�����jsr��һ��ָ���ַѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ret: //0xa9 	���������ر���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case tableswitch: //0xaa 	����switch������ת��caseֵ�������ɱ䳤��ָ�
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lookupswitch: //0xab 	����switch������ת��caseֵ���������ɱ䳤��ָ�
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ireturn: //0xac 	�ӵ�ǰ��������int
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case lreturn: //0xad 	�ӵ�ǰ��������long
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case freturn: //0xae 	�ӵ�ǰ��������float
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case dreturn: //0xaf 	�ӵ�ǰ��������do le
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case areturn: //0xb0 	�ӵ�ǰ�������ض�������
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case return_: //0xb1 	�ӵ�ǰ��������void
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case getstatic: //0xb2 	��ȡָ����ľ�̬�򣬲�����ֵѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case putstatic: //0xb3 	Ϊָ������ľ�̬��ֵ
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case getfield: //0xb4 	��ȡָ�����ʵ���򣬲�����ֵѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case putfield: //0xb5 	Ϊָ�������ʵ����ֵ
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case invokevirtual: //0xb6 	����ʵ������
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case invokespecial: //0xb7 	���ó��๹�췽����ʵ����ʼ��������˽�з���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case invokestatic: //0xb8 	���þ�̬����
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case invokeinterface: //0xb9 	���ýӿڷ���
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case invokedynamic: //0xba 	���ö�̬����
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case new_: //0xbb 	����һ�����󣬲���������ֵѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case newarray: //0xbc 	����һ��ָ��ԭʼ���ͣ���int, float, char���������飬����������ֵѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case anewarray: //0xbd 	����һ�������ͣ����࣬�ӿڣ����飩�����飬����������ֵѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case arraylength: //0xbe 	�������ĳ���ֵ��ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case athrow: //0xbf 	��ջ�����쳣�׳�
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case checkcast: //0xc0 	��������ת��������δͨ�����׳�ClassCastException
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case instanceof: //0xc1 	��������Ƿ���ָ�������ʵ��������ǽ�1ѹ��ջ��������0ѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case monitorenter: //0xc2 	��ö������������ͬ��������ͬ����
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case monitorexit: //0xc3 	�ͷŶ������������ͬ��������ͬ����
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case wide: //0xc4 	<������>
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case multianewarray: //0xc5 	����ָ�����ͺ�ָ��ά�ȵĶ�ά���飨ִ�и�ָ��ʱ������ջ�б��������ά�ȵĳ���ֵ��������������ֵѹ��ջ��
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifnull: //0xc6 	Ϊnullʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case ifnonnull: //0xc7 	��Ϊnullʱ��ת
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case goto_w: //0xc8 	��������ת����������
			currentFrame->goto_(opcode_length[(u4)code & 0x000000ff]);
			break;
		case jsr_w: //0xc9    jsr_w	��ת��ָ��32λoffsetλ�ã�����jsr_w��һ��ָ���ַѹ��ջ��
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
