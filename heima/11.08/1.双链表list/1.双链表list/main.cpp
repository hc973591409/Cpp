#include <list>
#include <iostream>

using namespace std;

void main1()
{
	list<int>my{ 1, 2, 3, 4 };					// 新建并且初始化一个链表
	for (auto i : my) { cout << i << "  "; };	// auto 遍历
	cout << endl;
	my.push_back(5);							// TODO 尾插
	my.push_front(0);							// TODO 前插
	for (auto i : my) { cout << i << "  "; };
	cout << endl;

	for (auto ib = my.begin(), ie = my.end(); ib != ie; ib++)		//迭代器遍历  可读可写迭代器，是指针
	{
		cout << *ib << "  ";
	}
	cout << endl;

	for (auto rb = my.rbegin(), re = my.rend(); rb != re; rb++)		//反向迭代器遍历  可读可写迭代器，是指针
	{
		cout << *rb << "  ";
	}
	cout << endl;


	for (auto cb = my.cbegin(), ce = my.cend(); cb != ce; cb++)		//const 迭代器遍历  可读迭代器，是指针
	{
		cout << *cb << "  ";
	}
	cout << endl;

	for (auto crb = my.crbegin(), cre = my.crend(); crb != cre; crb++)		//反向 const 迭代器遍历  可读迭代器，
	{
		cout << *crb << "  ";
	}
	cout << endl;
	
	// 如果不写  请用只读迭代器

	my.assign(3, 5);							// 重新初始化  用3个5
	for (auto i : my) { cout << i << " "; }			
	cout << endl;

	int a[5]{11, 22, 33, 44, 55};
	my.assign(a, a + 4);						// 重新初始化，a,a+1,a+2
	for (auto i : my) { cout << i << " "; }
	cout << endl;

	my.pop_back();                                   // 删除尾巴
	my.pop_front();									// 删除头

	cout << my.front() << endl;
	cout << my.back() << endl;

	cout << my.size() << endl;						// 求链表长度
	my.clear();										// 清空链表

	cin.get();
}

void main2()
{
	list<int>my{ 1, 2, 3, 4, 5 };
	for (auto ib = my.begin(), ie = my.end(); ib != ie; ib++){
		if (*ib == 3)					// 指定位置修改
		{
			*ib *= 2;
			break;
		}
	}
	for (auto i : my) { cout << i << " "; }
	cout << endl;

	for (auto ib = my.begin(), ie = my.end(); ib != ie; ib++){
		if (*ib == 1)					// 指定位置删除
		{
			my.erase(ib);				// 接受一个迭代器参数指针			
			break;
		}
	}
	for (auto i : my) { cout << i << " "; }
	cout << endl;

	cin.get();
}


void main11()
{
	list<int>my1{ 1, 9, 2, 8, 3, 7 };
	my1.sort();									// 排序	
	for (auto i : my1) { cout << i << " "; }
	cout << endl;

	my1.reverse();								// 链表反向，不就实现逆序了嘛
	for (auto i : my1) { cout << i << " "; }
	cout << endl;

	list<int>my2{ 11, 22, 33, 6, 7 };
	my1.sort();
	my2.sort();
	my1.merge(my2);							// 合并链表，必须先排序，且合并以后也是有序的
	for (auto i : my1) { cout << i << " "; }
	cout << endl;

	cin.get();
}

void main()
{
	list<int>my1{ 1, 9, 2, 8, 3, 7 };
	list<int>my2{ 11, 22, 33, 6, 7 };
	list<int>my3{ 0, 2, 33, 6, 7 };

	// 链表的每个元素都是链表
	list <list <int >> myint{ my1, my2, my3 };
	for (auto i : myint)
	{
		for (auto j : i)
		{
			cout << j << " \t ";
		}
		cout << endl;
	}

	cin.get();
}