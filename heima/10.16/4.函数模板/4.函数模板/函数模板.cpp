#include <iostream>

using namespace std;

//调用顺序，原声函数大于模板函数

int add(int a, int b){
	cout << "int" << endl;
	return a + b;
}

// 函数模板可以模拟任何数据类型，无法模板的时候就报错
template <class T>
T add(T a, T b){
	cout << 'T' << endl;
	return a + b;
}

void main1(){
	cout << add(1, 2) << endl;
	// 这里函数模板会把字符1，2的字体aciis码相加，形成新的字符
	cout << add('1', '2') << endl;

	//可以强行指定类型
	cout << add<int>(20.0, 20.9) << endl;

	cin.get();
}
