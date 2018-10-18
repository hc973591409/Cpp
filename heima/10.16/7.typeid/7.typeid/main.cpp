#include <iostream>
#include <cstring>

using namespace std;

void main()
{
	// 可以用typid求数据类型
	int a = 10;
	cout << typeid(a).name() << endl;
	cout << typeid(10).name() << endl;
	cout << typeid(11.1 + 9).name() << endl;
	cout << typeid("hsdafds").name() << endl;

	int *px;
	int *py; 
	cout << typeid(px).name() << endl;
	cout << typeid(*py).name() << endl;


	cin.get();
}
