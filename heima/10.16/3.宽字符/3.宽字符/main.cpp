#include<iostream>
#include<locale>
//���ػ�

using namespace std;

void main()
{
	// ���ñ��ػ��ַ���
	setlocale(LC_ALL, "zh-CN");

	wchar_t *p(L"����12");
	wcout << p << endl;

	cin.get();
}