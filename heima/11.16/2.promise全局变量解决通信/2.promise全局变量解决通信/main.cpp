#include <iostream>
#include <thread>
#include <string>
#include <cstdlib>
#include <future>			// �ṩȫ�ֵ�promise��futrue

using namespace std;

promise<string> val;

void main()
{
	thread th([](){
		future<string>fu = val.get_future();            // ��ȡ�����Ĳ���
		cout << "wait somthing " << endl;
		cout << fu.get() << endl;						// ��ӡ��ȡ���Ĳ���
	});
	thread th1([](){
		system("pause");
		val.set_value("i am coming");
	});
	th.join();
	th1.join();
	cin.get();
}