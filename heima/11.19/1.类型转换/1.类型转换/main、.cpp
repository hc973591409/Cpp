#include <iostream>

using namespace std;

// ������̬��������ת����static_cast<type>(data)
void main1()
{
	char ch = 'A';
	double num = 1.11;
	cout << static_cast<int>(ch) << endl;
	cout << static_cast<int>(num) << endl;

	cin.get();
}

// ָ������ת����reinterpret_cast<type *>(ptr)
void main3()
{
	int num = 78;
	int *p = &num;
	cout << reinterpret_cast<char *>(p) << endl;

	cin.get();
}

// constָ������ת����const_cast<type *>(ptr),һ������ȡ��const����
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
	phuang = dynamic_cast<xiaohuang *>(pdog);		//����ָ��ת��Ϊ����ָ�룬�����ڴ����� һ�㲻����ôת
	phuang->fun();*/

	cin.get();
}