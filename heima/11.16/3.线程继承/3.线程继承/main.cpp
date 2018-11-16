#include <iostream>
#include <thread>
#include <string>
#include <cstdlib>

using namespace std;

class my_thread :public thread
{
public:
	my_thread() : thread()		// ������ø���Ĺ��캯��
	{

	}
	template <typename T, typename ...Args>
	my_thread(T && fun, Args && ...args) : \
		thread(std::forward<T>(fun), std::forward<Args>(args)...)
	{

	}

	// ��չ�Լ��߳���Ĺ���
	void run(string str)
	{
		system(str.c_str());
	}
};

void main()
{
	my_thread t1([](){cout << "my thread"; });
	my_thread t2([](){cout << "my thread2"; });
	t1.run("calc");
	t2.run("notepad");
	t1.join();
	t2.join();
	cin.get();
}
