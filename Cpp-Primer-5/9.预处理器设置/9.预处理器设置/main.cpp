#include <iostream>

using namespace std;


void f()
{
#ifdef _DEBUG										// ��C++��Ԥ�������ж���_DEBUG������������룬���ڵ���
	cout << "debug" << endl; 
#else 
	cout << "release" << endl;
#endif
} 

void main1()
{
	f();
	cout << __cplusplus << endl;					// ħ���꣬���嵱ǰ��д����CPP����
	

	cin.get();
}
// ����---> ���Ŀ¼���������ɵ����ղ�Ʒ����ʲôĿ¼����ſ�ִ���ļ����⣬��DLL
// ����---> �м�Ŀ¼���м��ļ���ҪΪlog�ļ���obj�ļ���������Ʒ����Ҫ��Щ