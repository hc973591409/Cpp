#include <iostream>
#include <vector>

using namespace std;

void main1()
{
	// 初始化的几种方式
	vector<int>v1;				//
	vector<int>v2(v1);
	vector<int>v3(5, 10);		// 初始化为5个10
	for (auto i : v3){ cout << i << endl; };
	vector<int>v4(5);			// 初始化为5个值 不指定都是0
	for (auto i : v4){ cout << i << endl; };
	vector<int>v5{ 1, 2, 3, 4, 5 };		//大括号初始化
	for (auto i : v5){ cout << i << endl; };
	// 判断方式  圆括号是构造，  {}是大括号初始化

	cin.get();
}


void main2()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);         // 后插
	}
	for (auto i : v1){ cout << i << endl; };

	//方法
	v1.empty();				//空的返回1
	v1.size();				//返回个数
	v1.push_back(2);			//后插
	v1[10];						// 取出第10个数据
	vector<int>v2;
	v2 = v1; v1.push_back(10000);	//v2是副本
	for (auto i : v2){ cout << i << endl; };
	v1 == v2;					// 元素个数相同的时候才能判定
	//< <= > >=    
	// vector不能用下标的方式 插入元素
	v1[1] = 500;		//并不能正常更改
	for (auto i : v2){ cout << i << endl; };

	cin.get();
}
/*
1. v.push_back(t)    在容器的最后加入一个值为t的数据，容器的size变大。
另外list有push_front()函数，在前端插入，后面的元素下标依次增大。
2. v.size()        返回容器中数据的个数，size返回对应vector类定义的size_type的值。
v.resize(2*v.size)或v.resize(2*v.size, 99) 将v的容量翻倍(并把新元素的值初始化为99)

*/

// 用数组来初始化vector
void main3()
{
	int a[5]{1, 2, 3, 4, 5};
	vector<int>v1(begin(a), end(a));				// begin 返回迭代器开始
	for (auto i : v1){ cout << i << endl; };
	
	// 只是初始化部分
	vector<int>v2(a, a+3);				// begin 返回迭代器开始
	for (auto i : v2){ cout << i << endl; };


	cin.get();
}

// 二维数组vector

void main4()
{
	vector<vector<int>>v{
		{ 1, 2, 3, 4 },
		{ 2, 3, 4, 5 },
		{ 3, 4, 5, 6 },
	};
	for (auto row : v){
		for (auto clomn : row)
		{
			cout << clomn << "  ";
		}
		cout << endl;
	}

	cin.get();
}

// 位运算
void main5()
{
	unsigned int a = 9;
	cout << ~a << endl;

	// << >> & ^ |

	int num = 1 << 27;
	cout << num << endl;


	cin.get();
}

void main()
{
	int data = 3.9;			// 隐式转换 舍弃小数
	cout << data << endl;

	auto t = 8.9 + data;     // data会转成double 由低精度向高精度转换
	cout << t << endl;

	auto num = 3 + 'A';		// char ---> int 类型  小类型-->大类型   带符号转换为无符号
	cout << num << endl;

	cin.get();
}