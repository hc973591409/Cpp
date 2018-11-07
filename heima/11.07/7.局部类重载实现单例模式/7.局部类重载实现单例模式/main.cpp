#include <iostream>

using namespace std;

int obj = 0;
void *g_p = nullptr;

class myclass
{
public:
	myclass(){
		cout << "构造函数 " << endl;
	}
	~myclass(){
		cout << "析构函数 " << endl;
	}

	// 重载new
	static void * operator new(size_t size)
	{
		if (g_p == nullptr)
		{
			obj++;
			// ::new myclass调用全局的构造函数
			myclass *p = ::new myclass;
			g_p = p;
			return p;
		}
		else
		{
			cout << "只能构造一次" << endl;
			return g_p;
		}
	}

	// 重载delete 都只是适用于这个类，不会影响我们在外部使用

	static void operator delete(void *p)
	{
		if (g_p != nullptr)
		{
			obj--;
			cout << "delete  call" << endl;
			::delete p;
			return;
		}
		else
		{
			cout << "不能反复delete" << endl;
		}
	}

};

void main()
{
	myclass *p = new myclass;
	myclass *p1 = new myclass;
	myclass *p2 = new myclass;

	cin.get();
}