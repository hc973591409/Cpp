#include <iostream>
#include <vector>
#include <cstdarg>		// �ɱ����
#include <thread>

using namespace std;

void Go(const char *fmt,...)
{
	va_list ap;				// �����ɱ����ָ��
	va_start(ap,fmt);
	vprintf(fmt, ap);
	va_end(ap);
}

// �ɱ����ģ��ĵݹ����, �ɱ����ʵ����Pythonһ���Ĵ�ӡ����
void print()
{
	cout << endl;
	return;
}

template <typename T, typename ...Args>
void print(T head, Args ...args)
{
	cout << head << " ";
	print(args...);
}

void main1()
{
	thread t(Go, "%d---%s---%c----%x", 123, "abc", 'W', 0xA);
	t.join();

	cin.get();
}

void main2()
{
	print();
	print(1);
	print(1, 'c');
	print(1, 2, "hello");
	print(1, 2, "\n", 4, 5);

	cin.get();
}

// �ɱ����ʵ���������͵ļӷ�����

template <typename T>
T addit(T t)
{
	return t;
}

template <typename T, typename ...Args>
T addit(T first, Args ...args)
{
	return first + addit<T>(args...);
}
//����Ŀɱ�ģ������Ķ��嵱�У�ʡ�Ժŵ�������������
//1.����һ��������T... args������������п��԰���0�������ģ������� ���
//2.��ģ�嶨����ұߣ����Խ�������չ����һ��һ�������Ĳ������� ���
void main()
{
	print( addit(1, 2.2) );
	print(addit(1, 2.2, 4));

	cin.get();
}