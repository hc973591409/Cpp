// ttt.cpp �ǳ������

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

	int mask = 0xffffffff;         // -1 ��������
	int testMask = 0;				//
	int index = 0;					//
	int left = a;					// ��¼���ж���������
	int step = 3;
	int cStep = 0;					//���嵱ǰ�ߵĲ���

	while (left>1)
	{
		// a=5 index����6����6=0
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
	// int argc, _TCHAR* argv[] �����в�����argc���������������һ����·��
	// _TCHAR* argv[] ��һ���ַ����б�
	printf("Test! == %d, %s\n", argc, argv[1]);
	if (argc != 2){
		printf("erro parm: %d\n", argc);
		return 0;
	}

	int input = atoi((char *)argv[1]);
	// �������
	int ret_value = fun(input);

	// ��ӡ���
	printf("Fun(%d)=%d", input, ret_value);

	cin.get();
}