#include <iostream>
#include <forward_list>

using namespace std;

void main()
{
	forward_list<int>mylist{ 1, 2, 3, 4 };
	for (auto i : mylist)
	{
		cout << i << "  ";
	}
	cout << endl;

	cin.get();
}