#include <iostream>

using namespace std;

//����˳��ԭ����������ģ�庯��

int add(int a, int b){
	cout << "int" << endl;
	return a + b;
}

// ����ģ�����ģ���κ��������ͣ��޷�ģ���ʱ��ͱ���
template <class T>
T add(T a, T b){
	cout << 'T' << endl;
	return a + b;
}

void main1(){
	cout << add(1, 2) << endl;
	// ���ﺯ��ģ�����ַ�1��2������aciis����ӣ��γ��µ��ַ�
	cout << add('1', '2') << endl;

	//����ǿ��ָ������
	cout << add<int>(20.0, 20.9) << endl;

	cin.get();
}
