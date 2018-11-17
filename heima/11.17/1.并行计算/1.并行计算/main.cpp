#include <iostream>
#include <future>			// ��ȡ�߳̽����Ľ��
#include <thread>
#include <mutex>
#include <chrono>			// ʱ��

using namespace std;

void main()
{
	auto fun = [](int index){
		cout << this_thread::get_id() << "   " << index << endl;
		this_thread::sleep_for(chrono::seconds(2));
		return index * 1024;
	};

	packaged_task<int(int)>pt1(fun);					// ����һ����������������ķ���ֵ
	packaged_task<int(int)>pt2(fun);

	thread t1([&](){pt1(2); });							// �����߳�
	thread t2([&](){pt2(3); });

	// ��һֱ�ȴ���ֱ�������з���ֵ

	int num = pt1.get_future().get() + pt2.get_future().get();
	cout << num << endl;
	cout << "cppppppppppp" << endl;

	t1.join();
	t2.join();

	cin.get();
}