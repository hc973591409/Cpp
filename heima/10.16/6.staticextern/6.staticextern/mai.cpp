#include <iostream>

using namespace std;

extern int x;                  //跨文件使用全局变量的时候 应该用extern声明
extern int y;

void main()
{
	cout << x << endl;

	int show();                   // 访问外部的函数 必须先声明
	cout << show() << endl;

	cin.get();
}