#include <iostream>
#include <vector>
#include <array>

using namespace std;

void main1()
{
	// ��ʼ���ļ��ַ�ʽ
	vector<int>v1;				//
	vector<int>v2(v1);
	vector<int>v3(5, 10);		// ��ʼ��Ϊ5��10
	for (auto i : v3){ cout << i << endl; };
	vector<int>v4(5);			// ��ʼ��Ϊ5��ֵ ��ָ������0
	for (auto i : v4){ cout << i << endl; };
	vector<int>v5{ 1, 2, 3, 4, 5 };		//�����ų�ʼ��
	for (auto i : v5){ cout << i << endl; };
	// �жϷ�ʽ  Բ�����ǹ��죬  {}�Ǵ����ų�ʼ��

	cin.get();
}


void main2()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);         // ���
	}
	for (auto i : v1){ cout << i << endl; };

	//����
	v1.empty();				//�յķ���1
	v1.size();				//���ظ���
	v1.push_back(2);			//���
	v1[10];						// ȡ����10������
	vector<int>v2;
	v2 = v1; v1.push_back(10000);	//v2�Ǹ���
	for (auto i : v2){ cout << i << endl; };
	v1 == v2;					// Ԫ�ظ�����ͬ��ʱ������ж�
	//< <= > >=    
	// vector�������±�ķ�ʽ ����Ԫ��
	v1[1] = 500;		//��������������
	for (auto i : v2){ cout << i << endl; };

	cin.get();
}
/*
1. v.push_back(t)    ��������������һ��ֵΪt�����ݣ�������size���
����list��push_front()��������ǰ�˲��룬�����Ԫ���±���������
2. v.size()        �������������ݵĸ�����size���ض�Ӧvector�ඨ���size_type��ֵ��
v.resize(2*v.size)��v.resize(2*v.size, 99) ��v����������(������Ԫ�ص�ֵ��ʼ��Ϊ99)

*/

// ����������ʼ��vector
void main3()
{
	int a[5]{1, 2, 3, 4, 5};
	vector<int>v1(begin(a), end(a));				// begin ���ص�������ʼ
	for (auto i : v1){ cout << i << endl; };
	
	// ֻ�ǳ�ʼ������
	vector<int>v2(a, a+3);				// begin ���ص�������ʼ
	for (auto i : v2){ cout << i << endl; };


	cin.get();
}

// ��ά����vector

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

// λ����
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
	int data = 3.9;			// ��ʽת�� ����С��
	cout << data << endl;

	auto t = 8.9 + data;     // data��ת��double �ɵ;�����߾���ת��
	cout << t << endl;

	auto num = 3 + 'A';		// char ---> int ����  С����-->������   ������ת��Ϊ�޷���
	cout << num << endl;

	cin.get();
}

void main7()
{
	vector<int>myint{ 1, 2, 3, 4, 5, 6, 7, 8 };
	for (auto &i : myint){ cout << i << "   "; };
	cout << endl;

	myint.resize(6);			//��̬���������С
	for (auto &i : myint){ cout << i << "   "; };
	cout << endl;

	myint.resize(5, 90);		// ��ǰ������5�������Ǹ�����90�Ļ�����
	for (auto &i : myint){ cout << i << "   "; };
	cout << endl;

	auto it = myint.begin() + 3;
	myint.insert(it, 400);						// ָ��λ�ò���
	for (auto &i : myint){ cout << i << "   "; };
	cout << endl;

	array<int, 5>myarr = { 11, 22, 33, 44, 55 };		//������������
	myint.insert(it, myarr.begin(), myarr.end());
	for (auto &i : myint){ cout << i << "   "; };
	cout << endl;

	// ɾ��
	for (auto ib = myint.begin(); ib != myint.end(); ib++){
		if ((*ib == 3) || (*ib % 5 == 0))
		{
			auto it = ib - 1;
			myint.erase(ib);	// ÿ��ɾ����ʱ��ib���ǿգ������ٴ�����ib���ʣ�������it��������һ��ֵ������ɾ����һ��ֵ
			ib = it;
		}
	}

	for (auto &i : myint){ cout << i << "   "; };
	cout << endl;

	cin.get();
}

void main8()
{
	// vector���ڶ��ϵģ����Զ������ڴ棬�Ҳ���ջ���
	vector<int>myint;							//�յ�vector
	int *p = myint.get_allocator().allocate(5);			// �����ڴ�
	for (int i = 0; i < 5; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << p[i] << endl;
	}
	myint.get_allocator().deallocate(p, 5);               //�ͷ��ڴ�


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