#include <iostream>

using namespace std;

int obj = 0;
void *g_p = nullptr;

class myclass
{
public:
	myclass(){
		cout << "���캯�� " << endl;
	}
	~myclass(){
		cout << "�������� " << endl;
	}

	// ����new
	static void * operator new(size_t size)
	{
		if (g_p == nullptr)
		{
			obj++;
			// ::new myclass����ȫ�ֵĹ��캯��
			myclass *p = ::new myclass;
			g_p = p;
			return p;
		}
		else
		{
			cout << "ֻ�ܹ���һ��" << endl;
			return g_p;
		}
	}

	// ����delete ��ֻ������������࣬����Ӱ���������ⲿʹ��

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
			cout << "���ܷ���delete" << endl;
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