#include"main.h"
#include <iostream>
using namespace std;

int num = 10;
// 匿名命名空间等价于全局变量
namespace{
	int a = 9;
}

void main()
{
	cout << num << endl;
	//输出全局
	cout << data::num << endl;
	cin.get();
}