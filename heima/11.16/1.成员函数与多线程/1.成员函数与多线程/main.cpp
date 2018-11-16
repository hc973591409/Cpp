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
	MessageBoxA(0, "��Ա����", "���߳�", 0);
}

void MyClass::runit(string str)
{
	MessageBoxA(0, str.c_str(), str.c_str(), 1);
}

void main1()
{
	MyClass *my = new MyClass;				//ʵ����һ����
	thread th1(&MyClass::run, my);				// Ҫָ��˭���õ�
	thread th2(&MyClass::run, my);
	// ����ģʽ
	thread th3(&MyClass::runit, my, "Ҫָ��˭���õ�");
	thread th4(&MyClass::runit, my, "Ҫָ��˭���õ�");
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	delete my;								// �ͷŶ���
}

void main()
{
	main1();
}