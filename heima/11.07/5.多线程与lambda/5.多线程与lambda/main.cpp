#include <iostream>
#include <thread>
#include <chrono>			//时间
#include <windows.h>

using namespace std;

void show_msg()
{
	MessageBoxA(0, "hello", "world", 1);
}

void main2()
{
	auto fun = [](){MessageBoxA(0, "hello", "world", 1); };
	thread t1(fun);
	thread t2(fun);
	thread t3(fun);

	cin.get();
}

void main3()
{
	thread t1 ( [](){MessageBoxA(0, "hello", "world", 1); });
	thread t2([](){MessageBoxA(0, "hello", "world", 1); });
	thread t3([](){MessageBoxA(0, "hello", "world", 1); });

	cin.get();
}

void main()
{
	thread t1([](){
		this_thread::sleep_for(chrono::seconds(3));				// 睡眠3s
		this_thread::yield();									// 线程挂起 让CPU执行其他
		cout << this_thread::get_id() << endl;					// 获取线程id
	});

	thread t2([](){
		this_thread::sleep_for(chrono::seconds(10));				// 睡眠3s
		cout << this_thread::get_id() << endl;					// 获取线程id
	});

	cin.get();
}