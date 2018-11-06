#include <iostream>
#include <tuple>

using namespace std;

void main()
{
	const char * str("hello world");
	int num(10);
	double db(199.99);
	int *p(new int(5));

	tuple<const char*, int, double, int *>mytp{ str, num, db, p };
	
	// tuple 不能用auto遍历，只能一个一个查看，且 <> 中只能放常量，tuple必须用小括号包起来
	auto a0 = get<0>(mytp);
	cout << a0 << endl;

	auto a1 = get<1>(mytp);
	cout << a1 << endl;

	auto a2 = get<2>(mytp);
	cout << a2 << endl;

	auto a3 = get<3>(mytp);
	cout << *a3 << endl;


	cin.get();
}