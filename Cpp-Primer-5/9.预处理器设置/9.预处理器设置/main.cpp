#include <iostream>

using namespace std;


void f()
{
#ifdef _DEBUG										// 在C++的预处理器中定义_DEBUG，这叫条件编译，利于调试
	cout << "debug" << endl; 
#else 
	cout << "release" << endl;
#endif
} 

void main1()
{
	f();
	cout << __cplusplus << endl;					// 魔法宏，定义当前编写的是CPP代码
	

	cin.get();
}
// 常规---> 输出目录，决定生成的最终产品放于什么目录，存放可执行文件，库，和DLL
// 常规---> 中间目录，中间文件主要为log文件和obj文件。发布产品不需要这些