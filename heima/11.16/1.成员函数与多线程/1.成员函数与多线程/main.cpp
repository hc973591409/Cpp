#include <iostream>
#include <string>
#include <windows.h>
#include <thread>

using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();
	void run();
	void runit(string str);

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

void MyClass::run()
{
	MessageBoxA(0, "成员函数", "多线程", 0);
}

void MyClass::runit(string str)
{
	MessageBoxA(0, str.c_str(), str.c_str(), 1);
}

void main1()
{
	MyClass *my = new MyClass;				//实例化一个类
	thread th1(&MyClass::run, my);				// 要指明谁调用的
	thread th2(&MyClass::run, my);
	// 传参模式
	thread th3(&MyClass::runit, my, "要指明谁调用的");
	thread th4(&MyClass::runit, my, "要指明谁调用的");
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	delete my;								// 释放对象
}

void main()
{
	main1();
}