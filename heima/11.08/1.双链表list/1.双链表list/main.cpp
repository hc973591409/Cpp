#include <list>
#include <iostream>

using namespace std;

void main1()
{
	list<int>my{ 1, 2, 3, 4 };					// �½����ҳ�ʼ��һ������
	for (auto i : my) { cout << i << "  "; };	// auto ����
	cout << endl;
	my.push_back(5);							// TODO β��
	my.push_front(0);							// TODO ǰ��
	for (auto i : my) { cout << i << "  "; };
	cout << endl;

	for (auto ib = my.begin(), ie = my.end(); ib != ie; ib++)		//����������  �ɶ���д����������ָ��
	{
		cout << *ib << "  ";
	}
	cout << endl;

	for (auto rb = my.rbegin(), re = my.rend(); rb != re; rb++)		//�������������  �ɶ���д����������ָ��
	{
		cout << *rb << "  ";
	}
	cout << endl;


	for (auto cb = my.cbegin(), ce = my.cend(); cb != ce; cb++)		//const ����������  �ɶ�����������ָ��
	{
		cout << *cb << "  ";
	}
	cout << endl;

	for (auto crb = my.crbegin(), cre = my.crend(); crb != cre; crb++)		//���� const ����������  �ɶ���������
	{
		cout << *crb << "  ";
	}
	cout << endl;
	
	// �����д  ����ֻ��������

	my.assign(3, 5);							// ���³�ʼ��  ��3��5
	for (auto i : my) { cout << i << " "; }			
	cout << endl;

	int a[5]{11, 22, 33, 44, 55};
	my.assign(a, a + 4);						// ���³�ʼ����a,a+1,a+2
	for (auto i : my) { cout << i << " "; }
	cout << endl;

	my.pop_back();                                   // ɾ��β��
	my.pop_front();									// ɾ��ͷ

	cout << my.front() << endl;
	cout << my.back() << endl;

	cout << my.size() << endl;						// ��������
	my.clear();										// �������

	cin.get();
}

void main2()
{
	list<int>my{ 1, 2, 3, 4, 5 };
	for (auto ib = my.begin(), ie = my.end(); ib != ie; ib++){
		if (*ib == 3)					// ָ��λ���޸�
		{
			*ib *= 2;
			break;
		}
	}
	for (auto i : my) { cout << i << " "; }
	cout << endl;

	for (auto ib = my.begin(), ie = my.end(); ib != ie; ib++){
		if (*ib == 1)					// ָ��λ��ɾ��
		{
			my.erase(ib);				// ����һ������������ָ��			
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
	my1.sort();									// ����	
	for (auto i : my1) { cout << i << " "; }
	cout << endl;

	my1.reverse();								// �����򣬲���ʵ����������
	for (auto i : my1) { cout << i << " "; }
	cout << endl;

	list<int>my2{ 11, 22, 33, 6, 7 };
	my1.sort();
	my2.sort();
	my1.merge(my2);							// �ϲ����������������Һϲ��Ժ�Ҳ�������
	for (auto i : my1) { cout << i << " "; }
	cout << endl;

	cin.get();
}

void main()
{
	list<int>my1{ 1, 9, 2, 8, 3, 7 };
	list<int>my2{ 11, 22, 33, 6, 7 };
	list<int>my3{ 0, 2, 33, 6, 7 };

	// �����ÿ��Ԫ�ض�������
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