#include <iostream>

using namespace std;

void main1()
{
	int data = 3.9;			// 隐式转换 舍弃小数
	cout << data << endl;

	auto t = 8.9 + data;     // data会转成double 由低精度向高精度转换
	cout << t << endl;

	auto num = 3 + 'A';		// char ---> int 类型  小类型-->大类型   带符号转换为无符号
	cout << num << endl;

	cin.get();
}

// CPP的几种显示转换
// 命名规则   cast-name<type>(expression)
void main()
{
	// 基本数据类型转换static_cast  不带const都能用
	int j = 9;
	double slope = static_cast<double>(j) / 10;
	cout << slope << endl;

	void *p = nullptr;
	double *pd = static_cast<double *>(p);

	// 只能改变带const的
	const char *pc;
	char *p = const_cast<char *>(pc); // 一般用于去掉const属性

	// 一般用于改变指针的时候用, 一般不推荐用
	int *ip;		// 一般用于从高精度指针转换到低精度指针 
	char *pc = reinterpret_cast<char *>(ip);

	cin.get();
}