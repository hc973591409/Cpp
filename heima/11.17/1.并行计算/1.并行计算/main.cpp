#include <iostream>
#include <future>			// 获取线程将来的结果
#include <thread>
#include <mutex>
#include <chrono>			// 时间

using namespace std;

void main()
{
	auto fun = [](int index){
		cout << this_thread::get_id() << "   " << index << endl;
		this_thread::sleep_for(chrono::seconds(2));
		return index * 1024;
	};

	packaged_task<int(int)>pt1(fun);					// 传入一个函数，打包函数的返回值
	packaged_task<int(int)>pt2(fun);

	thread t1([&](){pt1(2); });							// 开启线程
	thread t2([&](){pt2(3); });

	// 会一直等待。直到函数有返回值

	int num = pt1.get_future().get() + pt2.get_future().get();
	cout << num << endl;
	cout << "cppppppppppp" << endl;

	t1.join();
	t2.join();

	cin.get();
}