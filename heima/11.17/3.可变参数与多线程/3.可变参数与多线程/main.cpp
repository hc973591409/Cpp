#include <iostream>
#include <vector>
#include <cstdarg>		// 可变参数
#include <thread>

using namespace std;

void Go(const char *fmt,...)
{
	va_list ap;				// 创建可变参数指针
	va_start(ap,fmt);
	vprintf(fmt, ap);
	va_end(ap);
}

// 可变参数模板的递归出口, 可变参数实现像Python一样的打印函数
void print()
{
	cout << endl;
	return;
}

template <typename T, typename ...Args>
void print(T head, Args ...args)
{
	cout << head << " ";
	print(args...);
}

void main1()
{
	thread t(Go, "%d---%s---%c----%x", 123, "abc", 'W', 0xA);
	t.join();

	cin.get();
}

void main2()
{
	print();
	print(1);
	print(1, 'c');
	print(1, 2, "hello");
	print(1, 2, "\n", 4, 5);

	cin.get();
}

// 可变参数实现任意类型的加法函数

template <typename T>
T addit(T t)
{
	return t;
}

template <typename T, typename ...Args>
T addit(T first, Args ...args)
{
	return first + addit<T>(args...);
}
//上面的可变模版参数的定义当中，省略号的作用有两个：
//1.声明一个参数包T... args，这个参数包中可以包含0到任意个模板参数； 租包
//2.在模板定义的右边，可以将参数包展开成一个一个独立的参数。； 解包
void main()
{
	print( addit(1, 2.2) );
	print(addit(1, 2.2, 4));

	cin.get();
}