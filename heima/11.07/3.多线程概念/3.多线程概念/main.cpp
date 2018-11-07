#include<thread>
#include<iostream>
#include<windows.h>


using namespace std;

void run()
{
	MessageBoxA(0, "hellohuahhua", "fangfang", 0);
}
void main1()
{
	// 栈上的线程数组，异步非阻塞
	thread t[5]{thread(run), thread(run), thread(run), thread(run), thread(run)};
	cin.get();
}

void main3()
{
	// 利用函数初始化线程
	thread t1(run);
	thread t3(run);
	thread t4(run);
	cin.get();
}

void main()
{
	// TODO 编译器居然会出错，回家用vs2017试一下
	thread  *pthread1(new thread[5]{ thread(run), thread(run), thread(run), thread(run), thread(run) });
	cout << "hello";
	cin.get();
}