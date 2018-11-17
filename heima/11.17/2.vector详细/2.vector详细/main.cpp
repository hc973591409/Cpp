#include <iostream>
#include <vector>

using namespace std;

void main1()
{
	vector<int>myint{ 1, 2, 3, 4, 5 };
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;

	for (int i = 10; i < 20; i++){
		myint.push_back(i);      // 尾部插入
	}

	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;

	cout << myint.size() << endl;				// 求元素个数

	cout << myint.at(5) << endl;						// 等价于 myint[5]

	// 迭代器		可读可写迭代器
	for (auto ib = myint.begin(); ib != myint.end(); ib++)
	{
		cout << *ib << "  ";
		if (*ib==15)
		{
			*ib = 65;
			break;
		}
	}
	cout << endl;

	// 迭代器		只读迭代器
	for (auto ib = myint.cbegin(); ib != myint.cend(); ib++)
	{
		cout << *ib << "  ";
	}
	cout << endl;

	// 迭代器		可读写反向迭代器
	for (auto ib = myint.rbegin(); ib != myint.rend(); ib++)
	{
		cout << *ib << "  ";
		if (*ib==17)
		{
			*ib = 77;
		}
	}
	cout << endl;

	// 迭代器		只读反向迭代器
	for (auto ib = myint.crbegin(); ib != myint.crend(); ib++)
	{
		cout << *ib << "  ";
	}
	cout << endl;



	cin.get();
}


void main3()
{
	vector<int>myint{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << myint.front() << endl;   // 获取第一个
	cout << myint.back() << endl;	// 获取最后一个
	myint.resize(5);					// 重新分配大小
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;

	myint.resize(4, 90);				// 设置元素为4个缓冲区为90
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;

	//cout << myint.max_size();			//求最大尺寸
	myint.assign(7, 100);				// 重新分配，7个100
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;

	auto it = myint.begin() + 3;
	myint.insert(it, 400);				// 指定迭代器位置插入
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;

	int a[5]{1, 2, 3, 4, 5};
	myint.insert(it, a, a + 5);
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;
	vector<int>myint2{ 5, 4, 3, 2, 1 };

	auto ib = myint.begin() + 3;
	myint.insert(ib, myint2.begin(), myint2.end());
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;

	auto itb = myint.begin() + 3;
	/*
	myint.erase(itb);					// 根据迭代器删除
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;*/

	myint.erase(itb,itb+5);					// 根据迭代器删除, 批量删除
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;


	cin.get();
}

void main4()
{
	// vector 实现锯齿数组
	vector<int>my1{ 1, 2, 3, 4, 5 };
	vector<int>my2{ 11,22};
	vector<int>my3{ 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<vector<int>>my{ my1, my2, my3 };
	for (auto i : my)
	{
		for (auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}
	cout << "\n\n\n";
	my1.swap(my2);						// 交换两个vector
	vector<vector<int>>myX{ my1, my2, my3 };
	for (auto i : myX)
	{
		for (auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}


	cin.get();
}
#include<ctime>
#define random(x) (rand()%(x))

void main()
{
	srand((unsigned int)time(0));						// 设定随机数种子
	vector<int>my;
	int *p = my.get_allocator().allocate(5);			// 分配内存
	for (size_t i = 0; i < 5; i++)
	{
		p[i] = random(100);
	}

	for (size_t i = 0; i < 5; i++)
	{
		cout << p[i] << endl;
	}

	// 释放内存 这里只是利用vector的分配器实现内存分配，和本身的my没有关系
	my.get_allocator().deallocate(p, 5);


	cin.get();
}
