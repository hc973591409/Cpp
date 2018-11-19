#include <iostream>

using namespace std;

// 基本静态数据类型转换用static_cast<type>(data)
void main1()
{
	char ch = 'A';
	double num = 1.11;
	cout << static_cast<int>(ch) << endl;
	cout << static_cast<int>(num) << endl;

	cin.get();
}

// 指针类型转换用reinterpret_cast<type *>(ptr)
void main3()
{
	int num = 78;
	int *p = &num;
	cout << reinterpret_cast<char *>(p) << endl;

	cin.get();
}

// const指针类型转换用const_cast<type *>(ptr),一般用于取出const属性
void main4()
{
	const int num = 78;
	const int *pnum = &num;
	int *pp = const_cast<int *>(pnum);
	cout << *pp << endl;

	cin.get();
}

class dog
{
public:
	dog(){};
	~dog(){};
	virtual void fun(){
		cout << "wangwang...." << endl;
	}
};
class xiaohuang : public dog
{
public:
	xiaohuang(){};
	~xiaohuang(){};
	virtual void fun(){
		cout << "wangwang.... and gogogo" << endl;
	}
};

void main()
{
	dog *pdog = new dog;
	xiaohuang *phuang = new xiaohuang;
	pdog->fun();
	pdog = dynamic_cast<dog *> (phuang);		
	if (pdog != nullptr)
	{
		pdog->fun();
	}
	/*phuang->fun();
	phuang = dynamic_cast<xiaohuang *>(pdog);		//父类指针转换为子类指针，不过内存问题 一般不能这么转
	phuang->fun();*/

	cin.get();
}