#include <iostream>

using namespace std;

void main1()
{
	int data = 3.9;			// ��ʽת�� ����С��
	cout << data << endl;

	auto t = 8.9 + data;     // data��ת��double �ɵ;�����߾���ת��
	cout << t << endl;

	auto num = 3 + 'A';		// char ---> int ����  С����-->������   ������ת��Ϊ�޷���
	cout << num << endl;

	cin.get();
}

// CPP�ļ�����ʾת��
// ��������   cast-name<type>(expression)
void main()
{
	// ������������ת��static_cast  ����const������
	int j = 9;
	double slope = static_cast<double>(j) / 10;
	cout << slope << endl;

	void *p = nullptr;
	double *pd = static_cast<double *>(p);

	// ֻ�ܸı��const��
	const char *pc;
	char *p = const_cast<char *>(pc); // һ������ȥ��const����

	// һ�����ڸı�ָ���ʱ����, һ�㲻�Ƽ���
	int *ip;		// һ�����ڴӸ߾���ָ��ת�����;���ָ�� 
	char *pc = reinterpret_cast<char *>(ip);

	cin.get();
}