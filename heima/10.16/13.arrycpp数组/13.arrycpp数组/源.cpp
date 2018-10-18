#include <iostream>
#include <array>
using namespace std;

void main()
{
	// 数组分配在栈上的
	array<int, 5>myint={ 1, 2, 3, 4, 5 };        //c14可以省略等号
	for (auto i : myint)
	{
		cout << i << " ";
	}
	cout << endl;

	//二维数组
	array<int, 5>myint1 = { 1, 2, 3, 4, 5 };
	array<int, 5>myint2 = { 1, 2, 3, 4, 5 };
	array<int, 5>myint3 = { 1, 2, 3, 4, 5 };
	array < array<int, 5>, 3> myint2w = { myint1, myint2, myint3 };

	// 利用auto遍历二维数组
	for (auto i : myint2w){
		for (auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}

	cin.get();
}