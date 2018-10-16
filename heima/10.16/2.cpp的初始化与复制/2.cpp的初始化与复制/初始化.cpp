#include<iostream>
using namespace std;

void main()
{
	// 变量初始化
	int num(5);
	cout << num << endl;

	// 指针初始化
	char *p("calc");
	cout << p << endl;

	// 宽字符指针的初始化
	wchar_t *wp(L"锄禾日当午");

	// 数组的初始化
	int a[5]{1, 2, 3, 4, 5};
	// for each 遍历数组
	for each(int i in a){
		cout << i <<' ';
	}


	cin.get();
}