#include <iostream>
#include <functional>

using namespace std;        //ʹ�������ռ�
using std::function;        // �����ռ��һ����
using MYFUN = std::ios::fmtflags;         //���������ռ��ڵĺ��������

typedef double DB;
using MYINT = int;         // ԭ���ϸ���������ö���usiing��typdef�������ࡢģ���
using CPPARRY = int[10];     // ������������� �������ʱ�򣬰��������壬Ȼ��ȥ������������
using PPFUN = void(*[10])(int, int); // ����ָ������
typedef int a[10];                   // a ��ʵ�Ǹ�int[10] ��������ȥ����

void main1()
{
	cout << sizeof(a) << endl;
	cout << sizeof(CPPARRY) << endl;

	cin.get();
}

namespace china{
	template <typename T>
	T add(T t)
	{
		return t * 2;
	}
}

void main(){
	cout << china::add(3) << endl;

	cin.get();
}