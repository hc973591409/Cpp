#include<thread>
#include<iostream>
#include<windows.h>


using namespace std;

void showmsg(const char *str1, const char *str2, int num)
{
	MessageBoxA(0, str1, str2, num);
}

void main()
{
	thread t1(showmsg, "hello", "world", 0);
	thread t2(showmsg, "hello1", "world1", 1);
	thread t31(showmsg, "hello2", "world2", 2);
	cin.get();
}