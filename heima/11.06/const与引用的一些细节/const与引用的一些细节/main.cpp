#include <iostream>

using namespace std;

void main1()
{
	const int a = 10;
	int b[a] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	// 在cpp中 const引用右值得时候，会自动优化替换
	for (auto i : b){
		cout << i << "   ";
	}

	int data = 5;
	const int num = data;
	//int arr[data];


	cin.get();
}

//constexpr标志返回值或者其他表达式是常量  c11貌似不能用
//constexpr   int get()
//{
//	return 5;
//}


void main2()
{
	//int a[5 + get()];
	int * const p(new int(5));
	int * const rp(p);
	cout << *rp << endl;

	cin.get();
}

void change(int & num)
{
	num -= 5;  //改变一个数需要一个引用，在cpp中能用引用不要用指针
}

void changeite(int &&num)
{
	num += 4;
}

void main()
{
	int data = 9;
	change(data);
	cout << data << endl;

	changeite(move(data));			// 用移动语义可以把左值变成右值，有内存实体和左值引用一样，没有就直接引用
	cout << data << endl;

	cin.get();
}