#include <iostream>
using namespace std;

struct Info
{
	int num;
	int data;
	// 结构体的构造函数，无返回值
	//Info(int a, int b) :num(a), data(b){}

	// 两种构造函数都一样，都能使用
	Info(int a, int b){
		num = a;
		data = b;
	}
};

void main()
{
	// 堆上
	Info *p{new Info[4]{{ 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 9 }}};
	Info *(rp)(p);

	Info a[4]{{ 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 9 }};
	Info(&ra)[4](a);
	for (auto i : ra)
	{
		cout << i.num << "     " << i.data << endl;
	}


	cin.get();
}