#include<iostream>
#include<cstdlib>

using namespace std;

char str[1024] = { 0 };//内存静态区
//静态区，栈区， 堆区，
//int *p2= new (str) int[10]{ 1,2,3,4,5,6,7,8,9,0 };//分配内存，str开始的地址
//堆区，可以覆盖重写  delete p2
//栈区，静态区，可以覆盖重写，不可以 delete p2


void main()
{
	//char str[1024] = { 0 };//内存栈区
	//char *str = new char[1024]{ 0 };//堆区
	int *p1 = new int[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//一定在堆区
	int *p2 = new (str) int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//分配内存，str开始的地址，战区分配


	for (int i = 0; i < 10; i++)
	{
		cout << p1[i] << " " << p1 + i << "  " << p2[i] << "  " << p2 + i << endl;
	}
	cout << "\n\n";
	free(str);//释放

	for (int i = 0; i < 10; i++)
	{
		cout << p1[i] << " " << p1 + i << "  " << p2[i] << "  " << p2 + i << endl;
	}
	cout << "\n\n";
	p1 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	p2 = new (str) int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//强行制定内存，再次
	for (int i = 0; i < 10; i++)
	{
		cout << p1[i] << " " << p1 + i << "  " << p2[i] << "  " << p2 + i << endl;
	}
	cout << "\n\n";


	//p1 = new int[10]{ 1,2,3,4,5,6,7,8,9,0 };
	//p2 = new (str) int[10]{ 1,2,3,4,5,6,7,8,9,0 };
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << p1[i] << " " << p1 + i << "  " << p2[i] << "  " << p2 + i << endl;
	//}
	//cout << "\n\n";
	cin.get();

}