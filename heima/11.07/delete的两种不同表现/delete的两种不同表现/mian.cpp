#include<iostream>

using namespace std;


//������������ ���飬delete  ��delete[]һ��
//�����������ͣ����Ի�����ʹ��

//������������
//mydata *p(new mydata);   delete p;
//mydata *p(new mydata[10]);    delete[] p;


void main2()
{
	int *p1 = new int(4);//ָ��һ������
	int *p2 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//ָ������
	delete p1;//delete p1    int *p1 = new int(4);
	delete[] p2;//delete[] p2  int *p2 = new int[10]{ 1,2,3,4,5,6,7,8,9,0 };
	//�����������ͣ����Ի�����ʹ��
	cin.get();
}
void main1()
{
	int *p = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << p << endl;



	cout << "--------------" << endl;
	delete[] p;





	cin.get();
}
void main3()
{
	int *p1 = new int(4);//ָ��һ������
	cout << p1 << endl;

	cout << "--------------" << endl;
	//delete p1;
	delete[] p1;


	//delete[] p1;

	cin.get();
}

class mydata
{
public:
	mydata()
	{
		cout << "create" << endl;
	}
	~mydata()
	{
		cout << "delete" << endl;
	}

};

void main()
{
	//mydata *p(new mydata);
	//delete p;

	//mydata *p(new mydata);
	//delete []p;//�������ϵĶ��󣬲����� delete [],����delete

	// �����������ͣ�delete [] ��delete���ܻ��ʹ�ã�����������delete��������delete [] 

	mydata *p(new mydata[10]);
	//delete  p;//�쳣
	cin.get();
}