#include<iostream>
#include<locale>
//本地化

using namespace std;

void main()
{
	// 设置本地化字符集
	setlocale(LC_ALL, "zh-CN");

	wchar_t *p(L"胡超12");
	wcout << p << endl;

	cin.get();
}