#include<iostream>
using namespace std;

void main()
{
	// ������ʼ��
	int num(5);
	cout << num << endl;

	// ָ���ʼ��
	char *p("calc");
	cout << p << endl;

	// ���ַ�ָ��ĳ�ʼ��
	wchar_t *wp(L"�����յ���");

	// ����ĳ�ʼ��
	int a[5]{1, 2, 3, 4, 5};
	// for each ��������
	for each(int i in a){
		cout << i <<' ';
	}


	cin.get();
}