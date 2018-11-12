#include <iostream>
#include <thread>
#include <cstdlib>

using namespace std;

// �̳��ڶ��߳�
class HuThread : public thread
{
public:
	// �޲�����ʱ��������ø���Ĺ��캯��
	HuThread() :thread()
	{

	}
	template <typename T, typename ...Args>				// ���εĹ��캯��
	HuThread(T &&fun, Args&&...args) : thread(std::forward<T>(fun), forward<Args>(args)...)
	{

	}


	int num;
	void run(string s)						// �����Լ��Ĺ���
	{
		system(s.c_str());
	}
};

void main()
{
	HuThread t1([](){cout << "hello" << endl; });
	t1.run("notepad");
	
	HuThread t2([](int num){cout << "hello   "<< num << endl; }, 100);
	t2.run("calc");

	cin.get();
}