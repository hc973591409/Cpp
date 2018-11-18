#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

#define LOOP 10

using namespace std;
int flag = 0;

void fun(char id)
{
	static condition_variable cv;
	static mutex g_m;
	for (size_t i = 0; i < LOOP; i++)
	{
		unique_lock<mutex>lk(g_m);
		while ((flag + 'A') != id)
		{
			cv.wait(lk);
		}
		flag = (flag + 1) % 4;
		cout << id;
		cv.notify_all();

		if (id == 'D')
		{
			cout << endl;
		}
	}
	
}

void main1()
{
	thread t1(fun, 'A');
	thread t2(fun, 'B');
	thread t3(fun, 'C');
	thread t4(fun, 'D');



	t1.join();
	t2.join();
	t3.join();
	t4.join();

	t2.swap(t3);					// 线程交换句柄
	thread t5 = move(t2);			// 把t2的所有权移交给t4 t2完全消亡为不可用


	cin.get();
}