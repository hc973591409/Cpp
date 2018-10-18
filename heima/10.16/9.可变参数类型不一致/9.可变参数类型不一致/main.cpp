#include <iostream>
#include <cstdarg>
using namespace std;

// 提前定义一个空的函数，作为递归的出口
void show1(){
	return;
}

// 用于处理参数个数确定， 类型也不确定的时候
template <typename T, typename...Args>
void show1(T t, Args...args){
	cout << t << " ";
	show1(args...);            // 参数传递 递归调用
}

void main1()
{
	show1(1, 'A', "hello world", 12.9);

	cin.get();
}