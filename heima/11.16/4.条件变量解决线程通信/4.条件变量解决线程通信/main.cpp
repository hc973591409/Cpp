#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;
mutex m;						// 线程互斥
condition_variable cv;			// 线程通信

// 创建多个线程，一个用于通知其他线程
void main()
{
	vector<thread>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(thread([](int index){ 
			unique_lock<mutex>lck(m);			//锁定
			cv.wait_for(lck, chrono::hours(1));						// 等待解锁
			cout << index << "  "; 
			this_thread::sleep_for(chrono::milliseconds(10));
		}, i));
		
	}

	for (size_t i = 0; i < 10; i++)
	{
		lock_guard<mutex>lckg(m);		//解锁一个
	}
	cv.notify_all();					//一次性通知全部

	for (size_t i = 0; i < 10; i++)
	{
		v[i].join();
	}

	cin.get();
}

void main1()
{
	thread **pp = new thread *[10];
	for (size_t i = 0; i < 10; i++)
	{
		pp[i] = new thread([](int index){ 
			unique_lock<mutex>lck(m);			//锁定
			cv.wait_for(lck, chrono::hours(1));						// 等待解锁
			cout << index << "  "; 
			this_thread::sleep_for(chrono::milliseconds(10)); 
		}, i);
	}

	for (size_t i = 0; i < 10; i++)
	{
		lock_guard<mutex>lckg(m);		//解锁一个，通知一个
		cv.notify_one();
	}


	for (size_t i = 0; i < 10; i++)
	{
		pp[i]->join();
	}

	cin.get();
}