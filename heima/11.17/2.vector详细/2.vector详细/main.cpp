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
		myint.push_back(i);      // β������
	}

	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;

	cout << myint.size() << endl;				// ��Ԫ�ظ���

	cout << myint.at(5) << endl;						// �ȼ��� myint[5]

	// ������		�ɶ���д������
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

	// ������		ֻ��������
	for (auto ib = myint.cbegin(); ib != myint.cend(); ib++)
	{
		cout << *ib << "  ";
	}
	cout << endl;

	// ������		�ɶ�д���������
	for (auto ib = myint.rbegin(); ib != myint.rend(); ib++)
	{
		cout << *ib << "  ";
		if (*ib==17)
		{
			*ib = 77;
		}
	}
	cout << endl;

	// ������		ֻ�����������
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
	cout << myint.front() << endl;   // ��ȡ��һ��
	cout << myint.back() << endl;	// ��ȡ���һ��
	myint.resize(5);					// ���·����С
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;

	myint.resize(4, 90);				// ����Ԫ��Ϊ4��������Ϊ90
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;

	//cout << myint.max_size();			//�����ߴ�
	myint.assign(7, 100);				// ���·��䣬7��100
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;

	auto it = myint.begin() + 3;
	myint.insert(it, 400);				// ָ��������λ�ò���
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
	myint.erase(itb);					// ���ݵ�����ɾ��
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;*/

	myint.erase(itb,itb+5);					// ���ݵ�����ɾ��, ����ɾ��
	for (auto i : myint)
	{
		cout << i << "   ";
	}
	cout << endl;


	cin.get();
}

void main4()
{
	// vector ʵ�־������
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
	my1.swap(my2);						// ��������vector
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
	srand((unsigned int)time(0));						// �趨���������
	vector<int>my;
	int *p = my.get_allocator().allocate(5);			// �����ڴ�
	for (size_t i = 0; i < 5; i++)
	{
		p[i] = random(100);
	}

	for (size_t i = 0; i < 5; i++)
	{
		cout << p[i] << endl;
	}

	// �ͷ��ڴ� ����ֻ������vector�ķ�����ʵ���ڴ���䣬�ͱ����myû�й�ϵ
	my.get_allocator().deallocate(p, 5);


	cin.get();
}
