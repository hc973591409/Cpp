#include <iostream>
#include <cmath>
#include <array>

using namespace std;

constexpr                 // ����������ʵ�α���Ϊ�������ʽ  ��ô����ֵҲ��һ���������ʽ
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