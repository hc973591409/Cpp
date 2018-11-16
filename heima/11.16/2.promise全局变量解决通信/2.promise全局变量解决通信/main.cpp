#include <iostream>
#include <thread>
#include <string>
#include <cstdlib>
#include <future>			// 提供全局的promise和futrue

using namespace std;

promise<string> val;

void main()
{
	thread th([](){
		future<string>fu = val.get_future();            // 获取将来的参数
		cout << "wait somthing " << endl;
		cout << fu.get() << endl;						// 打印获取到的参数
	});
	thread th1([](){
		system("pause");
		val.set_value("i am coming");
	});
	th.join();
	th1.join();
	cin.get();
}