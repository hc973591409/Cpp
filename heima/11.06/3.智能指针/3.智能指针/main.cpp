#include <iostream>
#include <windows.h>
#include <memory>


using namespace std;

void auto_cppptr()
{
	while (true)
	{
		Sleep(6000);   // 智能指针。禁止拷贝构造，自动释放，防止内存泄漏
		unique_ptr<double> p(new double[1024 * 1024 * 10]);
		Sleep(6000);
	}
}

void main()
{
	auto_cppptr();



	cin.get();
}