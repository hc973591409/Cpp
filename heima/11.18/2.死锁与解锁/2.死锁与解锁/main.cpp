#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex ma;
mutex mb;

void add1(int *ra,int *rb)
{
	for (size_t i = 0; i < 10; i++)
	{
		//ma.lock();						//���������������������ٽ��������������ͻ�����
		//mb.lock();
		//ra++;
		//rb++;
		//mb.unlock();
		//ma.unlock();
		ma.lock();							//�ڶ��߳������ָ�룬���ò�����
		(*ra)++;
		ma.unlock();
		mb.lock();
		(*rb)++;
		mb.unlock();
	}
}
void add2(int *ra, int *rb)
{
	for (size_t i = 0; i < 10; i++)
	{
		/*mb.lock();
		ma.lock();
		ra++;
		rb++;
		mb.unlock();
		ma.unlock();*/
	
		mb.lock();
		(*rb)++;
		mb.unlock();
		ma.lock();
		(*ra)++;
		ma.unlock();
	}
}

void main()
{
	int a = 0;
	int b = 0;
	thread t1(add1, &a, &b);
	thread t2(add2, &a, &b);
	t1.join();
	t2.join();
	while (1)
	{
		cout << a << endl;
		cout << b << endl;
		this_thread::sleep_for(chrono::seconds(3));
	}

	cin.get();
}