#include <iostream>

using namespace std;

void main1()
{
	const int a = 10;
	int b[a] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	// ��cpp�� const������ֵ��ʱ�򣬻��Զ��Ż��滻
	for (auto i : b){
		cout << i << "   ";
	}

	int data = 5;
	const int num = data;
	//int arr[data];


	cin.get();
}

//constexpr��־����ֵ�����������ʽ�ǳ���  c11ò�Ʋ�����
//constexpr   int get()
//{
//	return 5;
//}


void main2()
{
	//int a[5 + get()];
	int * const p(new int(5));
	int * const rp(p);
	cout << *rp << endl;

	cin.get();
}

void change(int & num)
{
	num -= 5;  //�ı�һ������Ҫһ�����ã���cpp���������ò�Ҫ��ָ��
}

void changeite(int &&num)
{
	num += 4;
}

void main()
{
	int data = 9;
	change(data);
	cout << data << endl;

	changeite(move(data));			// ���ƶ�������԰���ֵ�����ֵ�����ڴ�ʵ�����ֵ����һ����û�о�ֱ������
	cout << data << endl;

	cin.get();
}