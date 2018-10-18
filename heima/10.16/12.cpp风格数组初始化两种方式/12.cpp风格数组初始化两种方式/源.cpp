#include <iostream>
using namespace std;

void main()
{
	// 栈上分配
	int a[5]{1, 2, 3, 4, 5};
	for (auto i : a){
		cout << i << " ";
	}
	cout << endl;

	// 堆上分配
	int *p(new int[5]{1, 2, 3, 4, 5});
	for (int i=0; i < 5; i++){
		cout << p[i] << " ";
	}
	cout << endl;


	cin.get();
}