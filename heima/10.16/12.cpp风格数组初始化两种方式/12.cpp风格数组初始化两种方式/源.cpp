#include <iostream>
using namespace std;

void main()
{
	// ջ�Ϸ���
	int a[5]{1, 2, 3, 4, 5};
	for (auto i : a){
		cout << i << " ";
	}
	cout << endl;

	// ���Ϸ���
	int *p(new int[5]{1, 2, 3, 4, 5});
	for (int i=0; i < 5; i++){
		cout << p[i] << " ";
	}
	cout << endl;


	cin.get();
}