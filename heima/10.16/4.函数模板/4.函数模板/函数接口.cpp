#include <iostream>

using namespace std;

void show(int num){
	cout << num << endl;
}

// ����ʵ��һ��ͨ�ú����ṹ���������⺯����������ִ��
template <class T, class F>
void run(T t, F f){
	f(t);
}

void main()
{
	run(1, show);

	cin.get();
}