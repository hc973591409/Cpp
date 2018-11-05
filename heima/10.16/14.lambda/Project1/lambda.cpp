#include <iostream>
#include <array>

using namespace std;

void main1()
{
	// 匿名lambda
	[] {cout << "hello world" << endl; }();
	// 
	auto fun = [] { cout << "我是函数指针，指向匿名函数lambda" << endl; };
	fun();                    // 调用

	[](const char * str) {cout << str << endl; }("第一个小括号参数，第二个是传递的参数");

	auto add = [](auto a, auto b = 0) {cout << a + b << endl; };
	add(10.9,19.9);                    // auto a, auto b = 0 默认参数是无效的

	// lambda的本质为类，不能完全当作函数指针，所以不能给lambda取地址

	cin.get();
}


void main3()
{
	auto fun = [](auto a, auto b)->decltype(a + b) {return a + b; };
	cout << fun(10, 25.1) << endl;
	int num = 10;
	// [] {cout << num << endl; }(); lambda不能引用外部变量
	[=] {cout << num << endl; }();		// =可以引用外部变量，只读不写
	[&] {num = 20; cout << num << endl; }(); // [&] 可以引用外部变量，无副本机制
	cout << num << endl;

	int a = 10, b = 20, c = 30;
	[&a,b,c] {a= 10; cout << a << " "<< c << " "<<  b << endl; }(); // 参数列表

	int m = 20, n = 25;
	// mutable 修饰lambda  可以引用外部变量，但是是副本
	[=]()mutable {m += 20; cout << m << " " << n << endl; }();
	cout << m << endl;

	cin.get();
}

void main()
{
	array <int, 10> myint{ 1,2,3,4,5,6,7,8,9,0 };
	// lambda与迭代器   副本
	for_each(myint.begin(), myint.end(), [] (auto num){
		cout << num <<  "   "; });
	cout << endl;

	// [&] 是原本
	for_each(myint.begin(), myint.end(), [](int &num) {
		num += 1;
		cout << num << "   "; });
	cout << endl;

	// lambda与迭代器   副本
	for_each(myint.begin(), myint.end(), [](int num) {
		cout << num << "   "; });
	cout << endl;

	cin.get();
}