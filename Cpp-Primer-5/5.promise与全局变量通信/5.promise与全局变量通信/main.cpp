#include <iostream>
#include <thread>
#include <string>
#include <future>

using namespace std;

promise<string> val;

void main()
{
	thread t1([](){
		future<string>fu = val.get_future();			// �ȴ���ȡ
		cout << "�ȴ���" << endl;
		cout << fu.get() << endl;					 // ��ȡֵ
	});

	thread t2([](){
		system("pause");	
		val.set_value("hello world");			// ����ֵ
	});
	t1.join();
	t2.join();

	cin.get();
}