#include <iostream>
#include<Windows.h>
#include "./ThunderOpenSDK/xldl.h"

using namespace std;

void main()
{
	
	cout << "hello world" << endl;
	if (hDLL)
	{
		cout << "success" << endl;
		auto url = "http://mirrors.shu.edu.cn/apache/hadoop/common/hadoop-2.9.2/hadoop-2.9.2-src.tar.gz";
		DownEngine::XL_Init();
	}
	else
	{
		cout << "faile" << endl;
	}

	cin.get();
}