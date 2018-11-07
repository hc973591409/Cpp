#include<iostream>
#include<Windows.h>
#include<cstdlib>
using namespace std;

void main1()
{
	//基本数据类型,int double char

	int *p = new int(5);
	cout << (void*)p << "   p=" << p << endl;
	delete(p);
	cout << "   p=" << p << endl;
	p = nullptr;//delete不会改变指针的值，为了避免迷途指针，指针设定为nullptr
	delete p;

	//delete free对于基本数据类型，释放，释放两次都会出错
	//free不改变指针的值，delete会改变


	cin.get();
}

void main2()
{
	int *p = (int*)malloc(4);
	*p = 4;

	free(p);//基本数据类型，free malloc new delete效果一致

	cin.get();
}

class mydata
{
public:
	void *p;
	mydata()//构造函数
	{
		p = malloc(1024 * 1024 * 1024);//分配
		cout << "mydata create" << endl;
	}
	~mydata()//析构函数
	{
		free(p);//释放
		cout << "mydata delete" << endl;
	}


};

//mydata d1;//创建对象，自动调用构造函数
void test()
{
	mydata d1;//栈上，创建调用构造，销毁调用析构函数
}

void main()
{
	//mydata *p = new mydata;

	//delete p;//自动调用 构造，析构
	//test(); malloc 不会调用构造函数，所以在用类的时候都用new delete
	mydata *p = (mydata *)malloc(sizeof(mydata));

	//delete p; 
	//free(p);//free不会调用析构函数

	cin.get();
}