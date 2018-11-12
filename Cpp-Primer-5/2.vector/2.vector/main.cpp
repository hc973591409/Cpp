#include <iostream>
#include <vector>
#include <array>

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

void main6()
{
	int data = 3.9;			// 隐式转换 舍弃小数
	cout << data << endl;

	auto t = 8.9 + data;     // data会转成double 由低精度向高精度转换
	cout << t << endl;

	auto num = 3 + 'A';		// char ---> int 类型  小类型-->大类型   带符号转换为无符号
	cout << num << endl;

	cin.get();
}

void main7()
{
	vector<int>myint{ 1, 2, 3, 4, 5, 6, 7, 8 };
	for (auto &i : myint){ cout << i << "   "; };
	cout << endl;

	myint.resize(6);			//动态调整数组大小
	for (auto &i : myint){ cout << i << "   "; };
	cout << endl;

	myint.resize(5, 90);		// 当前数组有5个，但是给分配90的缓冲区
	for (auto &i : myint){ cout << i << "   "; };
	cout << endl;

	auto it = myint.begin() + 3;
	myint.insert(it, 400);						// 指定位置插入
	for (auto &i : myint){ cout << i << "   "; };
	cout << endl;

	array<int, 5>myarr = { 11, 22, 33, 44, 55 };		//批量插入数据
	myint.insert(it, myarr.begin(), myarr.end());
	for (auto &i : myint){ cout << i << "   "; };
	cout << endl;

	// 删除
	for (auto ib = myint.begin(); ib != myint.end(); ib++){
		if ((*ib == 3) || (*ib % 5 == 0))
		{
			auto it = ib - 1;
			myint.erase(ib);	// 每次删除的时候，ib都是空，不能再次利用ib访问，所以用it来保存上一个值，不能删除第一个值
			ib = it;
		}
	}

	for (auto &i : myint){ cout << i << "   "; };
	cout << endl;

	cin.get();
}

void main8()
{
	// vector是在堆上的，会自动管理内存，且不会栈溢出
	vector<int>myint;							//空的vector
	int *p = myint.get_allocator().allocate(5);			// 分配内存
	for (int i = 0; i < 5; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << p[i] << endl;
	}
	myint.get_allocator().deallocate(p, 5);               //释放内存


	cin.get();
}

void main()
{
	vector<int>my1{ 1, 2, 3, 4, 5 };
	vector<int>my2{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 22, 2 };
	vector<int>my3{ 3, 5, 8, 9, 6, 4, 7 };
	vector<vector<int>>my{ my1, my2, my3 };
	for (auto &i : my){
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}


	cin.get();
}