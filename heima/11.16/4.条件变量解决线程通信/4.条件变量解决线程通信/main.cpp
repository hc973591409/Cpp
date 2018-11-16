#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;
mutex m;						// �̻߳���
condition_variable cv;			// �߳�ͨ��

// ��������̣߳�һ������֪ͨ�����߳�
void main()
{
	vector<thread>v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(thread([](int index){ 
			unique_lock<mutex>lck(m);			//����
			cv.wait_for(lck, chrono::hours(1));						// �ȴ�����
			cout << index << "  "; 
			this_thread::sleep_for(chrono::milliseconds(10));
		}, i));
		
	}

	for (size_t i = 0; i < 10; i++)
	{
		lock_guard<mutex>lckg(m);		//����һ��
	}
	cv.notify_all();					//һ����֪ͨȫ��

	for (size_t i = 0; i < 10; i++)
	{
		v[i].join();
	}

	cin.get();
}

void main1()
{
	thread **pp = new thread *[10];
	for (size_t i = 0; i < 10; i++)
	{
		pp[i] = new thread([](int index){ 
			unique_lock<mutex>lck(m);			//����
			cv.wait_for(lck, chrono::hours(1));						// �ȴ�����
			cout << index << "  "; 
			this_thread::sleep_for(chrono::milliseconds(10)); 
		}, i);
	}

	for (size_t i = 0; i < 10; i++)
	{
		lock_guard<mutex>lckg(m);		//����һ����֪ͨһ��
		cv.notify_one();
	}


	for (size_t i = 0; i < 10; i++)
	{
		pp[i]->join();
	}

	cin.get();
}