// ttt.cpp 是程序入口

#include "stdafx.h"
#include <math.h>
#include <string>
#include<iostream>

using namespace std;

int fun(int a){
	if (a < 0){
		printf("erro parm: %d\n", a);
		return -1;
	}

	if (a == 0)
	{
		return 0;
	}

	int mask = 0xffffffff;         // -1 代表任务
	int testMask = 0;				//
	int index = 0;					//
	int left = a;					// 记录还有多少人在线
	int step = 3;
	int cStep = 0;					//定义当前走的步数

	while (left>1)
	{
		// a=5 index数到6就让6=0
		if (index >= a){
			index = 0;
		}
		testMask = 1 << index;
		if ((mask&testMask) > 0){
			cStep++;
		}

		if (cStep > step)
		{
			testMask = 1 << index;
			testMask = ~testMask;
			mask = mask&testMask;

			cStep = 1;
			--left;
			printf("out:====%d\n", index);
		}
		index++;
		cout << "teskmast:" << testMask << "  mask:" << mask << endl;
	}
	int leftNum = 0;
	int reValue = 0;
	for (int i = 0; i < a; ++i){
		testMask = 1 << i;
		if ((mask&testMask)>0)
		{
			printf("left:==== %d\n", i);
			reValue = i;
			leftNum++;
		}
	}
	if (leftNum != 1){
		printf("erro leftnum=%d\n", leftNum);
		return -1;
	}


	return reValue;
}


int _tmain1(int argc, _TCHAR* argv[]){
	// int argc, _TCHAR* argv[] 命令行参数，argc代表命令个数，第一个是路径
	// _TCHAR* argv[] 是一个字符串列表
	printf("Test! == %d, %s\n", argc, argv[1]);
	if (argc != 2){
		printf("erro parm: %d\n", argc);
		return 0;
	}

	int input = atoi((char *)argv[1]);
	// 传入参数
	int ret_value = fun(input);

	// 打印结果
	printf("Fun(%d)=%d", input, ret_value);

	cin.get();
}