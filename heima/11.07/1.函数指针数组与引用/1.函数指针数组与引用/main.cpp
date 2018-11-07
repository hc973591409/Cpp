#include <iostream>

using namespace std;

auto add(int a, int b)->decltype(a + b)
{
	return a + b;
}

auto sub(int a, int b)->decltype(a - b)
{
	return a - b;
}

auto mul (int a, int b)->decltype(a - b)
{
	return a * b;
}


auto divv(int a, int b)->decltype(a / b)
{
	return a / b;
}

void main()
{
	// �½�����ָ������
	int(*p[4])(int a, int b){add,sub,mul,divv};
	for (int i = 0; i < 4; i++)
	{
		cout << p[i](19,8) << endl;
	}

	// ���Ͽ��ٶ�������ָ�� ��ź���ָ������
	int(**pp)(int a, int b) = new (int(*[4])(int, int)){ add, sub, mul, divv };
	for (int i = 0; i < 4; i++)
	{
		cout << pp[i](19, 8) << endl;
	}

	// ���ú���ָ������Ͷ�������ָ��
	int(* (&rp) [4])(int a, int b)(p);
	for (int i = 0; i < 4; i++)
	{
		cout << rp[i](19, 8) << endl;
	}

	int(**(&rpp))(int a, int b)(pp);
	for (int i = 0; i < 4; i++)
	{
		cout << rpp[i](19, 8) << endl;
	}

	// ָ�뷨����
	for (auto *ip = p; ip < p + 3; ip++)
	{
		cout << (*ip)(19, 8) << endl;
	}

	// ���ö�������ָ�� ָ�뷨����
	for (auto *ip = rpp; ip < rpp + 3; ip++)
	{
		cout << (*ip)(19, 8) << endl;
	}

	cin.get();
}