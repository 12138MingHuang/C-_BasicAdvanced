//�޶����ʷ�Χ

//source1.cpp
extern void sayHello();
const char* msg = "Hello World!\n";

int main() {
	sayHello();
	return 0;
}

//g++�����������������ļ��ǿ����������벢�Ҵ�ӡHello World!��
//�������source1.cpp�е�msg����static����ᵼ��undefined reference to 'msg'�ı������