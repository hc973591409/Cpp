#include<thread>
#include<iostream>
#include<array>
#include<windows.h>
//join�õ�ǰ���̵߳ȴ��������߳�ִ����ɲ����˳�
//deatch �������̵߳İ󶨣����߳��˳���ʱ�򣬲�Ӱ�����߳��˳�����
//thread::hardware_concurrency();//��ȡCPU���ĸ���  
//cout << th.joinable() << endl;�ж��Ƿ���Լ���ȴ�

using namespace std;

void show()
{
	MessageBoxA(0, "1", "1", 0);
}

void main��()
{
	auto n = thread::hardware_concurrency();//��ȡCPU���ĸ���
	cout << n << endl;

	cin.get();
}

void main3()
{
	array<thread, 3>  threads = { thread(show), thread(show), thread(show) };
	for (int i = 0; i < 3; i++)
	{
		cout << threads[i].joinable() << endl;//�Ƿ����join�ж�
		threads[i].join();//���̵߳ȴ���ǰ�߳�ִ��������˳�
	}
	//cin.get();
}
void main()
{
	thread th(show);
	//th.join();
	th.detach();//�������̣߳����̹߳��ˣ��������Զ��˳�
	//detach�Ժ��߳��޷�ͨ��
	cout << th.joinable() << endl;
	cin.get();
}