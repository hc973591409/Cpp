#include <iostream>

using namespace std;

extern int x;                  //���ļ�ʹ��ȫ�ֱ�����ʱ�� Ӧ����extern����
extern int y;

void main()
{
	cout << x << endl;

	int show();                   // �����ⲿ�ĺ��� ����������
	cout << show() << endl;

	cin.get();
}