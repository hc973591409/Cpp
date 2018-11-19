#include <iostream>
#include <initializer_list>					// 大括号头文件
using namespace std;

void show(initializer_list<int>list1)
{
	for (auto i : list1)
	{
		cout << i << endl;
	}
}

int * getmem(initializer_list<int>list1)
{
	int len = list1.size();
	int *p = new int[len];
	int i = 0;
	for (auto ib = list1.begin(); ib != list1.end(); ib++){
		p[i++] = *ib;
	}
	return p;
}

void main()
{
	show({ 1, 2, 3, 4, 5, 6, 19 });

	// 大括号给指针分配
	int *p = getmem({ 77, 88, 99, 100 });
	for (int i = 0; i < 4;i++)
	{
		cout << p[i] << endl;
	}
	cin.get();
}