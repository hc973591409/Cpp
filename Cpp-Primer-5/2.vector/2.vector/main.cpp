#include <iostream>
#include <vector>

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

void main()
{
	int data = 3.9;			// ��ʽת�� ����С��
	cout << data << endl;

	auto t = 8.9 + data;     // data��ת��double �ɵ;�����߾���ת��
	cout << t << endl;

	auto num = 3 + 'A';		// char ---> int ����  С����-->������   ������ת��Ϊ�޷���
	cout << num << endl;

	cin.get();
}