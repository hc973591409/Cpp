#include <iostream>
#include <thread>
#include <mutex>	// ������
#include <atomic>	// ԭ�ӱ���

using namespace std;

atomic_int num{ 0 };       // ԭ�ӱ����ô����ų�ʼ��
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
	clock_t start = clock();			// ��ȡ��ǰʱ��
	cout << start << endl;
	thread t1(gogog);
	thread t2(gogog);
	thread t3(gogog);
	t1.join();
	t2.join();
	
	t3.join();
	cout << num << endl;

	clock_t end = clock();
	cout << "�����ʱ��" << end - start << "ms" << endl;
	// ������Ҫ12s       atomic_int num ��Ҫ100ms

	cin.get();
}