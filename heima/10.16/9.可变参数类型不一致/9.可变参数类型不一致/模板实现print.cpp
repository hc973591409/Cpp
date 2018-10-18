#include <iostream>
#include <cstdarg>
using namespace std;

// ģ��ʵ��printf
void show(const char *str){
	cout << str;
	return;
}

// ���ڴ����������ȷ���� ����Ҳ��ȷ����ʱ��
template <typename T, typename...Args>
void show(const char *str, T t, Args...args){
	while (*str && str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			str++;
			cout << t;
			show(++str, args...);
			return;
		}
		else
		{
			cout << *str++;
		}
	}
}

void main()
{
	printf("%dABCD%c1234%%%f789||\n", 12, 'X', 19.8);
	/*show(1, 'A', "hello world", 12.9);*/
	show("%dABCD%c1234%%f789||", 12, 'X', 19.8);

	cin.get();
}