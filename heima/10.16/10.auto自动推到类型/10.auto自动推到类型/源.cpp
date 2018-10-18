#include <iostream>
using namespace std;

template <class T1,class T2>
auto add(T1 t1, T2 t2)->decltype(t1 + t2)   //auto作为函数返回值类型，可以自动推到
{											//c14可以不用decltype(t1 + t2)推导
	return t1 + t2;
}

void main()
{
	auto num = 10;
	cout << typeid(num).name() << endl;
	auto data = 10.1;
	cout << typeid(data).name() << endl;
	auto a = {1,2,3,4,5};
	cout << typeid(a).name() << endl;
	// auto 可以根据右值自动推导类型
	/*int
	  double
	  class std::initializer_list<int>*/

	cout << add(11, 12.1) << endl;
	cout << add(19.9, 29) << endl;

	// auto遍历数组
	int arr[5]{1, 2, 3, 4, 5};
	for (auto i : arr){            //这里的i是副本
		i++;
		cout << i << endl;
	}

	for (auto &i : arr){		//这里的i是原本
		i++;
		cout << i << endl;
	}

	for (auto i : arr){		//这里的i是原本
		cout << i << endl;
	}

	cin.get();
}