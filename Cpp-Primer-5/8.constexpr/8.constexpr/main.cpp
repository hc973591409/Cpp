#include <iostream>
#include <cmath>
#include <array>

using namespace std;

constexpr                 // 声明函数的实参必须为常量表达式  那么返回值也是一个常量表达式
int my_pow(int base, int exp) noexcept
{
	return pow(base, exp);
}

void main()
{
	constexpr auto num = 5;
	std::array<int, my_pow(3, num)>result;

	cin.get();
}