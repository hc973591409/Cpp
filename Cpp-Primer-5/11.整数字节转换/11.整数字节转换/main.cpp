#include <iostream>

using namespace std;

#define ASSERTIONS_ENABLED 1              // �������
#if ASSERTIONS_ENABLED
// ������������õ�������ͣ����
#define debugBreak() asm {int 3;}
#define ASSERT(expr)\
if (expr){}\
	else\
{\
	reportAssertionFailure(#expr, __FILE__, __LINE__); \
	debugBreak();\
}
//#expr #��Ԥ����������� �ѱ��ʽת��1���ַ���
#else
#define ASSERT(expr)	// ������
#endif
//void main()
//{
//	int a = 0;
//	if (a < 5){
//		ASSERT(a>5);
//	}
//	else
//	{
//		cout << "doing something ";
//	}
//	
//
//
//	cin.get();
//}