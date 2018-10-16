#include <iostream>

using namespace std;

void show(int num){
	cout << num << endl;
}

// 这里实现一个通用函数结构，传递任意函数，都可以执行
template <class T, class F>
void run(T t, F f){
	f(t);
}

void main()
{
	run(1, show);

	cin.get();
}