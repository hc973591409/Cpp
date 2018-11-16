#include <iostream>

using namespace std;

#define ASSERTIONS_ENABLED 1              // 定义断言
#if ASSERTIONS_ENABLED
// 定义内联汇编让调试器暂停程序
#define debugBreak() asm {int 3;}
#define ASSERT(expr)\
if (expr){}\
	else\
{\
	reportAssertionFailure(#expr, __FILE__, __LINE__); \
	debugBreak();\
}
//#expr #是预处理操作符， 把表达式转成1个字符串
#else
#define ASSERT(expr)	// 不处理
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