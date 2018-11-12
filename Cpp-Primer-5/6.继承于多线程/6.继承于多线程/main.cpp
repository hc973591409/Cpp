#include <iostream>
#include <thread>
#include <cstdlib>

using namespace std;

// 继承于多线程
class HuThread : public thread
{
public:
	// 无参数的时候，子类调用父类的构造函数
	HuThread() :thread()
	{

	}
	template <typename T, typename ...Args>				// 传参的构造函数
	HuThread(T &&fun, Args&&...args) : thread(std::forward<T>(fun), forward<Args>(args)...)
	{

	}


	int num;
	void run(string s)						// 新增自己的功能
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