#include <iostream>
#include <windows.h>
#include <thread>
#include <string>

using namespace std;

struct MyStruct
{
	int i;
	void run()
	{
		MessageBoxA(0, "1234", "adcd", 1);
	}

	void runit(string s1,string s2)
	{
		MessageBoxA(0, s1.c_str(), s2.c_str(), 1);
	}

};

void main()
{
	MyStruct St;
	// 无参数模式
	thread t1(&MyStruct::run, St);
	thread t2(&MyStruct::run, St);

	// 带参数的传递方式，指定成员函数，调用对象，参数
	thread t3(&MyStruct::runit, St,"hello","huchao");
	thread t4(&MyStruct::runit, St, "hellocpp", "huchaocpp");

	cin.get();
}