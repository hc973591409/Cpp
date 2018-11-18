#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <cstdlib>
#include <mutex>

#define COUNT 1000000

using namespace std;

int add(vector<int>&v, int start, int end)
{
	static mutex m;
	int sum = 0;
	for (int i = start; i < end; i++){
		sum += v.at(i);
	}
	lock_guard<mutex>lck(m);							// 自动加锁自动解锁
	cout << "sum:  " << sum << "\tid:  " << this_thread::get_id() << endl;
	return sum;
}



void main()
{
	vector<int>myint(COUNT);
	for (size_t i = 0; i < COUNT; i++)
	{
		myint[i] = i % 1000;
	}
	vector<future<int>>res;									// 保存结果数组		
	int cpu_count = thread::hardware_concurrency();

	for (size_t i = 0; i < cpu_count * 2; i++)
	{
		// 分割 但是不想做。。。

		res.push_back(async(add, myint, i * 10, i * 10  + 10000));
	}
	int last_num = 0;
	for (size_t i = 0; i < cpu_count * 2; i++)
	{
		last_num += res[i].get();
	}
	cout << last_num << endl;
	cin.get();
}