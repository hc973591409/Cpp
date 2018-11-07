#include <iostream>

using namespace std;

auto add(int a, int b)->decltype(a + b)
{
	return a + b;
}

auto sub(int a, int b)->decltype(a - b)
{
	return a - b;
}

auto mul (int a, int b)->decltype(a - b)
{
	return a * b;
}


auto divv(int a, int b)->decltype(a / b)
{
	return a / b;
}

void main()
{
	// 新建函数指针数组
	int(*p[4])(int a, int b){add,sub,mul,divv};
	for (int i = 0; i < 4; i++)
	{
		cout << p[i](19,8) << endl;
	}

	// 堆上开辟二级函数指针 存放函数指针数组
	int(**pp)(int a, int b) = new (int(*[4])(int, int)){ add, sub, mul, divv };
	for (int i = 0; i < 4; i++)
	{
		cout << pp[i](19, 8) << endl;
	}

	// 引用函数指针数组和二级函数指针
	int(* (&rp) [4])(int a, int b)(p);
	for (int i = 0; i < 4; i++)
	{
		cout << rp[i](19, 8) << endl;
	}

	int(**(&rpp))(int a, int b)(pp);
	for (int i = 0; i < 4; i++)
	{
		cout << rpp[i](19, 8) << endl;
	}

	// 指针法遍历
	for (auto *ip = p; ip < p + 3; ip++)
	{
		cout << (*ip)(19, 8) << endl;
	}

	// 引用二级函数指针 指针法遍历
	for (auto *ip = rpp; ip < rpp + 3; ip++)
	{
		cout << (*ip)(19, 8) << endl;
	}

	cin.get();
}