#include <iostream>
#include <thread>
#include <mutex>	// 互斥量
#include <atomic>	// 原子变量

using namespace std;

atomic_int num{ 0 };       // 原子变量用大括号初始化
//int num = 0;
mutex m;

void gogog()
{
	//m.lock();
	for (int i = 1; i <= 1000000; i++)
	{
		
		num++;
		
	}
	//m.unlock();
}

void main()
{
	clock_t start = clock();			// 获取当前时间
	cout << start << endl;
	thread t1(gogog);
	thread t2(gogog);
	thread t3(gogog);
	t1.join();
	t2.join();
	
	t3.join();
	cout << num << endl;

	clock_t end = clock();
	cout << "程序耗时：" << end - start << "ms" << endl;
	// 互斥需要12s       atomic_int num 需要100ms

	cin.get();
}