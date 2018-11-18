#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

using namespace std;

class MyClass
{
public:
	MyClass() {};
	~MyClass() {};

	void put(int num);
	void take();
	void show()
	{
		unique_lock<mutex> lk(m);
		for (auto i : this->factory)
		{
			cout << i << " ";
		}
		cout << endl;
	}

private:
	vector<int>factory;
	mutex m;
	condition_variable isfull, isempty;
	int index;
};
void MyClass::put(int num)
{
	while (1){
		unique_lock<mutex> lk(m);
		if (this->factory.size() >= 20)
		{
			this->isfull.notify_all();							// ֪ͨ����������
			this->isempty.wait(lk);
		}
		this->factory.push_back(++index);
		cout << "�����ߣ� " << index << "   ID" << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
		this->isfull.notify_all();							// ֪ͨ����������
	}


}
void MyClass::take()
{
	while (1)
	{
		unique_lock<mutex> lk(m);
		this->isfull.wait(lk);					// �ȴ�֪ͨ
		cout << "���ѣ� " << this->factory.back() << "    ID:" << this_thread::get_id() << endl;
		if (this->factory.size() > 0)
		{
			cout << "size: " << this->factory.size()  << endl;
			this->factory.pop_back();
		}
		if (this->factory.size() <= 10) {
			this->isempty.notify_all();										// ֪ͨ������
			//flag = false;
		}
		this_thread::sleep_for(chrono::milliseconds(1));
	}
}


void main()
{
	MyClass *my = new MyClass;				//ʵ����һ����
	thread t1(&MyClass::put, my, 20);
	thread t2(&MyClass::put, my, 20);

	thread t3(&MyClass::take, my);
	thread t4(&MyClass::take, my);
	thread t5(&MyClass::take, my);
	thread t6(&MyClass::take, my);

	while (1)
	{
		this_thread::sleep_for(chrono::seconds(1));
		my->show();
	}

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	

	cin.get();
}