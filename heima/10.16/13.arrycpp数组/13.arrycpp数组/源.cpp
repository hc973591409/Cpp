#include <iostream>
#include <array>
using namespace std;

void main()
{
	// ���������ջ�ϵ�
	array<int, 5>myint={ 1, 2, 3, 4, 5 };        //c14����ʡ�ԵȺ�
	for (auto i : myint)
	{
		cout << i << " ";
	}
	cout << endl;

	//��ά����
	array<int, 5>myint1 = { 1, 2, 3, 4, 5 };
	array<int, 5>myint2 = { 1, 2, 3, 4, 5 };
	array<int, 5>myint3 = { 1, 2, 3, 4, 5 };
	array < array<int, 5>, 3> myint2w = { myint1, myint2, myint3 };

	// ����auto������ά����
	for (auto i : myint2w){
		for (auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}

	cin.get();
}