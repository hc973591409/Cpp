#include <iostream>
#include <cstdarg>
using namespace std;

//可变参数模板。类型一致
template <typename T>
T run(int n, T t...)
{
	va_list ptr;               //定义开头指针
	va_start(ptr, n);          // 从指定地址读取n个参数
	T res(0);					//保存结果
	for (int i = 0; i < n; i++){
		res += va_arg(ptr, T);	//根据类型每次读取指定的数据
		cout << res << " ";
	}
	va_end(ptr);					// 结束读取

	return res;
}

void main()
{
	cout << run(3, 1, 2, 3) << endl;
	cout << run(3, 1.1, 2.2, 3.3) << endl;

	cin.get();
}