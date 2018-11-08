#include <iostream>
#include <thread>
#include <windows.h>

using namespace std;

struct MyStruct
{
	void operator ()()					// 重载() 运算符，可以把对象名当做函数用
	{
		MessageBoxA(0, "hello", "world", 1);
	}
	void operator ()(int i)					// 重载() 运算符，可以把对象名当做函数用
	{
		MessageBoxA(0, "hello", "cppp", 1);
	}
};

void main()
{
	MyStruct my1;		//
	MyStruct my2;
	thread t1(my1);
	thread t2(my2,1);

	cin.get();
}