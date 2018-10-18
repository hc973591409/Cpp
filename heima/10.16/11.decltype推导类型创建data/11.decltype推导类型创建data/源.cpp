#include <iostream>
using namespace std;

template <typename T>
void show(T *t){
	cout << *t << endl;
	decltype(*t)num(*t);           //指针备份
	cout << num << endl;
	return;
}

void main()
{
	int num = 10;      //decltype(num) 根据参数创建一个类型，可以创建指针，数组等
	decltype(num) a[10]{0};
	for (auto i : a){
		cout << i << endl;
	}
	double db = 10;
	show(&db);
	cin.get();
}