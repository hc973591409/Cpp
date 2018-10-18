#include <iostream>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
using namespace std;

void main2()
{
	srand((unsigned)time(NULL));
	int num = rand() % 1000;
	cout << num << endl;
	wstring str;
	for (size_t i = 0; i < num;i++)
	{
		str.append(1, L'A' + rand() % (L'Z' - L'A' + 1));
	}
	cout << str.c_str();

	cin.get();
}

void main()
{
	int num = 1;
	while (true)
	{
		if (num % 10000 == 0){
			break;
		}

		num++;
	}
	cout << "num=" << num << endl;

	DWORD xnum = 0;
	bool x(xnum);
	cout << x << endl;

	cin.get();
}