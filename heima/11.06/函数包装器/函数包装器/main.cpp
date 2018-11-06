#include <iostream>
#include <functional>               // ������װ��ͷ�ļ�

using namespace std;
using std::function;            

void go()
{
	cout << "gogogo" << endl;
}

int add(int a, int b)
{
	return a + b;
}

void main()
{
	auto f = go;
	f();
	function<void(void)> ff = go;
	ff();

	auto fadd = add;
	cout << fadd(10, 9) << endl;

	function<int(int, int)> ffadd = add;
	cout << ffadd(100, 9) << endl;

	auto ladd = [](int a, int b){ cout << a + b << endl; };
	ladd(90, 90);

	// ������װ������ʵ��������c���Եĺ���ָ������ã���ʵautoҲ���ð�
	function<void(int, int)> lladd = [](int a, int b){ cout << a + b << endl; };
	lladd(987, 789);

	cin.get();
}