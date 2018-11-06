#include <iostream>
#include <functional>               // 函数包装器头文件

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

	// 函数包装器可以实现类似于c语言的函数指针的作用，其实auto也能用啊
	function<void(int, int)> lladd = [](int a, int b){ cout << a + b << endl; };
	lladd(987, 789);

	cin.get();
}