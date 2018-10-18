#include <iostream>
#include <functional>

using namespace std;        //使用命名空间
using std::function;        // 命名空间的一部分
using MYFUN = std::ios::fmtflags;         //可以命名空间内的函数起别名

typedef double DB;
using MYINT = int;         // 原则上给类型起别用都用usiing，typdef处理不了类、模板等
using CPPARRY = int[10];     // 给数组其别名， 起别名的时候，按正常定义，然后去掉变量名即可
using PPFUN = void(*[10])(int, int); // 函数指针数组
typedef int a[10];                   // a 其实是给int[10] 这种类型去别名

void main1()
{
	cout << sizeof(a) << endl;
	cout << sizeof(CPPARRY) << endl;

	cin.get();
}

namespace china{
	template <typename T>
	T add(T t)
	{
		return t * 2;
	}
}

void main(){
	cout << china::add(3) << endl;

	cin.get();
}