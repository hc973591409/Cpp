#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <windows.h>

using namespace std;

mutex m;		// 创建互斥量
condition_variable cv;   // 创建线程通信条件变量


void main1()
{
	//vector<thread>v;
	thread **pp = new thread *[10];
	for (int i = 0; i < 10; i++)
	{
		//Sleep(10);                      // 错开线程，避免打印乱序
		pp[i] = new thread([](int index){
			unique_lock<mutex> lock(m);                            // 锁定线程
			cv.wait_for(lock, chrono::hours(10000));				// 无限等待，直到lock解锁
			cout << "print" << index << endl; 
		}, i);
		this_thread::sleep_for(chrono::milliseconds(10));
	}

	for (int i = 0; i < 10; i++)
	{
		lock_guard<mutex>lockg(m);                 //创建解锁向导
		cv.notify_one();
	}

	for (int i = 0; i < 10; i++)
	{
		pp[i]->join();
	}
	
	
	//cv.notify_all();

	cin.get();
}

//增加一个标志位
bool ready = false;

void run()
{
	unique_lock<mutex>lck(m);
	while (!ready)						// ready位true则一直等待
	{
		cv.wait(lck);					//阻塞当前线程，直到解锁
	}
	cout << "hello world" << endl;
}

void go()
{
	unique_lock<mutex>lck(m);  // TODO
	ready = true;
	cv.notify_all();
}

void main()
{
	thread th[10];
	for (int i = 0; i < 10; i++)
	{
		th[i] = thread(run);
	}

	go();						// 调用go 

	for (auto &t:th)
	{
		t.join();
	}

	cin.get();
}