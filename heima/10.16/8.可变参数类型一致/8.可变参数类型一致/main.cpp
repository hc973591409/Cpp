#include <iostream>
#include <cstdarg>
using namespace std;

//�ɱ����ģ�塣����һ��
template <typename T>
T run(int n, T t...)
{
	va_list ptr;               //���忪ͷָ��
	va_start(ptr, n);          // ��ָ����ַ��ȡn������
	T res(0);					//������
	for (int i = 0; i < n; i++){
		res += va_arg(ptr, T);	//��������ÿ�ζ�ȡָ��������
		cout << res << " ";
	}
	va_end(ptr);					// ������ȡ

	return res;
}

void main()
{
	cout << run(3, 1, 2, 3) << endl;
	cout << run(3, 1.1, 2.2, 3.3) << endl;

	cin.get();
}