#include <iostream>
using namespace std;

struct Info
{
	int num;
	int data;
	// �ṹ��Ĺ��캯�����޷���ֵ
	//Info(int a, int b) :num(a), data(b){}

	// ���ֹ��캯����һ��������ʹ��
	Info(int a, int b){
		num = a;
		data = b;
	}
};

void main()
{
	// ����
	Info *p{new Info[4]{{ 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 9 }}};
	Info *(rp)(p);

	Info a[4]{{ 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 9 }};
	Info(&ra)[4](a);
	for (auto i : ra)
	{
		cout << i.num << "     " << i.data << endl;
	}


	cin.get();
}