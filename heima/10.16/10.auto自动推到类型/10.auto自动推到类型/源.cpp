#include <iostream>
using namespace std;

template <class T1,class T2>
auto add(T1 t1, T2 t2)->decltype(t1 + t2)   //auto��Ϊ��������ֵ���ͣ������Զ��Ƶ�
{											//c14���Բ���decltype(t1 + t2)�Ƶ�
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
	// auto ���Ը�����ֵ�Զ��Ƶ�����
	/*int
	  double
	  class std::initializer_list<int>*/

	cout << add(11, 12.1) << endl;
	cout << add(19.9, 29) << endl;

	// auto��������
	int arr[5]{1, 2, 3, 4, 5};
	for (auto i : arr){            //�����i�Ǹ���
		i++;
		cout << i << endl;
	}

	for (auto &i : arr){		//�����i��ԭ��
		i++;
		cout << i << endl;
	}

	for (auto i : arr){		//�����i��ԭ��
		cout << i << endl;
	}

	cin.get();
}