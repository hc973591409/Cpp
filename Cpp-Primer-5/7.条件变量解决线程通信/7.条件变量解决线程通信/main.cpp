#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <windows.h>

using namespace std;

mutex m;		// ����������
condition_variable cv;   // �����߳�ͨ����������


void main1()
{
	//vector<thread>v;
	thread **pp = new thread *[10];
	for (int i = 0; i < 10; i++)
	{
		//Sleep(10);                      // ���̣߳������ӡ����
		pp[i] = new thread([](int index){
			unique_lock<mutex> lock(m);                            // �����߳�
			cv.wait_for(lock, chrono::hours(10000));				// ���޵ȴ���ֱ��lock����
			cout << "print" << index << endl; 
		}, i);
		this_thread::sleep_for(chrono::milliseconds(10));
	}

	for (int i = 0; i < 10; i++)
	{
		lock_guard<mutex>lockg(m);                 //����������
		cv.notify_one();
	}

	for (int i = 0; i < 10; i++)
	{
		pp[i]->join();
	}
	
	
	//cv.notify_all();

	cin.get();
}

//����һ����־λ
bool ready = false;

void run()
{
	unique_lock<mutex>lck(m);
	while (!ready)						// readyλtrue��һֱ�ȴ�
	{
		cv.wait(lck);					//������ǰ�̣߳�ֱ������
	}
	cout << "hello world" << endl;
}

void go()
{
	unique_lock<mutex>lck(m);  // TODO
	ready = true;
	cv.notify_all();
}

void main()
{
	thread th[10];
	for (int i = 0; i < 10; i++)
	{
		th[i] = thread(run);
	}

	go();						// ����go 

	for (auto &t:th)
	{
		t.join();
	}

	cin.get();
}