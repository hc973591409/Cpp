#include <iostream>
#include <windows.h>
#include <memory>


using namespace std;

void auto_cppptr()
{
	while (true)
	{
		Sleep(6000);   // ����ָ�롣��ֹ�������죬�Զ��ͷţ���ֹ�ڴ�й©
		unique_ptr<double> p(new double[1024 * 1024 * 10]);
		Sleep(6000);
	}
}

void main()
{
	auto_cppptr();



	cin.get();
}