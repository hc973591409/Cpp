#include <iostream>
#include <cstdarg>
using namespace std;

// ��ǰ����һ���յĺ�������Ϊ�ݹ�ĳ���
void show1(){
	return;
}

// ���ڴ����������ȷ���� ����Ҳ��ȷ����ʱ��
template <typename T, typename...Args>
void show1(T t, Args...args){
	cout << t << " ";
	show1(args...);            // �������� �ݹ����
}

void main1()
{
	show1(1, 'A', "hello world", 12.9);

	cin.get();
}