#include<thread>
#include<iostream>
#include<windows.h>


using namespace std;

void run()
{
	MessageBoxA(0, "hellohuahhua", "fangfang", 0);
}
void main1()
{
	// ջ�ϵ��߳����飬�첽������
	thread t[5]{thread(run), thread(run), thread(run), thread(run), thread(run)};
	cin.get();
}

void main3()
{
	// ���ú�����ʼ���߳�
	thread t1(run);
	thread t3(run);
	thread t4(run);
	cin.get();
}

void main()
{
	// TODO ��������Ȼ������ؼ���vs2017��һ��
	thread  *pthread1(new thread[5]{ thread(run), thread(run), thread(run), thread(run), thread(run) });
	cout << "hello";
	cin.get();
}