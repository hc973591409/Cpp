#include <iostream>
using namespace std;

template <typename T>
void show(T *t){
	cout << *t << endl;
	decltype(*t)num(*t);           //ָ�뱸��
	cout << num << endl;
	return;
}

void main()
{
	int num = 10;      //decltype(num) ���ݲ�������һ�����ͣ����Դ���ָ�룬�����
	decltype(num) a[10]{0};
	for (auto i : a){
		cout << i << endl;
	}
	double db = 10;
	show(&db);
	cin.get();
}