#include<iostream>

using namespace std;


//基本数据类型 数组，delete  ，delete[]一致
//基本数据类型，可以互相混合使用

//复合数据类型
//mydata *p(new mydata);   delete p;
//mydata *p(new mydata[10]);    delete[] p;


void main2()
{
	int *p1 = new int(4);//指向一个变量
	int *p2 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//指向数组
	delete p1;//delete p1    int *p1 = new int(4);
	delete[] p2;//delete[] p2  int *p2 = new int[10]{ 1,2,3,4,5,6,7,8,9,0 };
	//基本数据类型，可以互相混合使用
	cin.get();
}
void main1()
{
	int *p = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << p << endl;



	cout << "--------------" << endl;
	delete[] p;





	cin.get();
}
void main3()
{
	int *p1 = new int(4);//指向一个变量
	cout << p1 << endl;

	cout << "--------------" << endl;
	//delete p1;
	delete[] p1;


	//delete[] p1;

	cin.get();
}

class mydata
{
public:
	mydata()
	{
		cout << "create" << endl;
	}
	~mydata()
	{
		cout << "delete" << endl;
	}

};

void main()
{
	//mydata *p(new mydata);
	//delete p;

	//mydata *p(new mydata);
	//delete []p;//单个堆上的对象，不可以 delete [],反复delete

	// 复合数据类型，delete [] 和delete不能混合使用，单个对象用delete，数组用delete [] 

	mydata *p(new mydata[10]);
	//delete  p;//异常
	cin.get();
}