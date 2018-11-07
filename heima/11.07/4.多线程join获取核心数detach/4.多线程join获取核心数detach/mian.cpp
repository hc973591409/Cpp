#include<thread>
#include<iostream>
#include<array>
#include<windows.h>
//join让当前主线程等待所有子线程执行完成才能退出
//deatch 脱离主线程的绑定，主线程退出的时候，不影响子线程退出出错。
//thread::hardware_concurrency();//获取CPU核心个数  
//cout << th.joinable() << endl;判断是否可以加入等待

using namespace std;

void show()
{
	MessageBoxA(0, "1", "1", 0);
}

void main２()
{
	auto n = thread::hardware_concurrency();//获取CPU核心个数
	cout << n << endl;

	cin.get();
}

void main3()
{
	array<thread, 3>  threads = { thread(show), thread(show), thread(show) };
	for (int i = 0; i < 3; i++)
	{
		cout << threads[i].joinable() << endl;//是否可以join判断
		threads[i].join();//主线程等待当前线程执行完成再退出
	}
	//cin.get();
}
void main()
{
	thread th(show);
	//th.join();
	th.detach();//脱离主线程，主线程挂了，不报错，自动退出
	//detach以后线程无法通信
	cout << th.joinable() << endl;
	cin.get();
}