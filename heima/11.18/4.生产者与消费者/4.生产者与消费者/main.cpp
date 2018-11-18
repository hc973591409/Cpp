#include<iostream>
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

private:
	vector<int>factory;
	mutex m;
	condition_variable isfull, isempty;
};
void MyClass::put(int num)
{
	int i = 0;
	while (1) {
		unique_lock<mutex> lk(m);
		while (this->factory.size() >= 100)
		{
			this->isempty.wait(lk);
		}
		this->factory.push_back(++i);
		cout << "生产者： " << i << "   ID" << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
		this->isfull.notify_all();							// 通知消费者消费
	}


}
void MyClass::take()
{
	while (1)
	{
		unique_lock<mutex> lk(m);
		this->isfull.wait(lk);					// 等待通知
		cout << "消费： " << this->factory.back() << "    ID:" << this_thread::get_id() << endl;
		if (this->factory.size() > 0)
		{
			this->factory.pop_back();
		}
		if (this->factory.size() == 0) {
			this->isempty.notify_all();										// 通知生产者
			//flag = false;
		}
	}
}


void main()
{
	MyClass *my = new MyClass;				//实例化一个类
	thread t1(&MyClass::put, my, 20);
	thread t2(&MyClass::put, my, 20);

	thread t3(&MyClass::take, my);
	thread t4(&MyClass::take, my);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	cin.get();
}