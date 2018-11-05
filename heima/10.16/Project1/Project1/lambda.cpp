#include <iostream>
#include <array>

using namespace std;

void main1()
{
	// ����lambda
	[] {cout << "hello world" << endl; }();
	// 
	auto fun = [] { cout << "���Ǻ���ָ�룬ָ����������lambda" << endl; };
	fun();                    // ����

	[](const char * str) {cout << str << endl; }("��һ��С���Ų������ڶ����Ǵ��ݵĲ���");

	auto add = [](auto a, auto b = 0) {cout << a + b << endl; };
	add(10.9,19.9);                    // auto a, auto b = 0 Ĭ�ϲ�������Ч��

	// lambda�ı���Ϊ�࣬������ȫ��������ָ�룬���Բ��ܸ�lambdaȡ��ַ

	cin.get();
}


void main3()
{
	auto fun = [](auto a, auto b)->decltype(a + b) {return a + b; };
	cout << fun(10, 25.1) << endl;
	int num = 10;
	// [] {cout << num << endl; }(); lambda���������ⲿ����
	[=] {cout << num << endl; }();		// =���������ⲿ������ֻ����д
	[&] {num = 20; cout << num << endl; }(); // [&] ���������ⲿ�������޸�������
	cout << num << endl;

	int a = 10, b = 20, c = 30;
	[&a,b,c] {a= 10; cout << a << " "<< c << " "<<  b << endl; }(); // �����б�

	int m = 20, n = 25;
	// mutable ����lambda  ���������ⲿ�����������Ǹ���
	[=]()mutable {m += 20; cout << m << " " << n << endl; }();
	cout << m << endl;

	cin.get();
}

void main()
{
	array <int, 10> myint{ 1,2,3,4,5,6,7,8,9,0 };
	// lambda�������   ����
	for_each(myint.begin(), myint.end(), [] (auto num){
		cout << num <<  "   "; });
	cout << endl;

	// [&] ��ԭ��
	for_each(myint.begin(), myint.end(), [](int &num) {
		num += 1;
		cout << num << "   "; });
	cout << endl;

	// lambda�������   ����
	for_each(myint.begin(), myint.end(), [](int num) {
		cout << num << "   "; });
	cout << endl;

	cin.get();
}