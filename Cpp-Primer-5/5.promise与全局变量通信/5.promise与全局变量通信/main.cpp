#include <iostream>
#include <thread>
#include <string>
#include <future>

using namespace std;

promise<string> val;

void main()
{
	thread t1([](){
		future<string>fu = val.get_future();			// 等待获取
		cout << "等待中" << endl;
		cout << fu.get() << endl;					 // 获取值
	});

	thread t2([](){
		system("pause");	
		val.set_value("hello world");			// 设置值
	});
	t1.join();
	t2.join();

	cin.get();
}