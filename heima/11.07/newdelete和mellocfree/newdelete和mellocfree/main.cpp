#include<iostream>
#include<Windows.h>
#include<cstdlib>
using namespace std;

void main1()
{
	//������������,int double char

	int *p = new int(5);
	cout << (void*)p << "   p=" << p << endl;
	delete(p);
	cout << "   p=" << p << endl;
	p = nullptr;//delete����ı�ָ���ֵ��Ϊ�˱�����;ָ�룬ָ���趨Ϊnullptr
	delete p;

	//delete free���ڻ����������ͣ��ͷţ��ͷ����ζ������
	//free���ı�ָ���ֵ��delete��ı�


	cin.get();
}

void main2()
{
	int *p = (int*)malloc(4);
	*p = 4;

	free(p);//�����������ͣ�free malloc new deleteЧ��һ��

	cin.get();
}

class mydata
{
public:
	void *p;
	mydata()//���캯��
	{
		p = malloc(1024 * 1024 * 1024);//����
		cout << "mydata create" << endl;
	}
	~mydata()//��������
	{
		free(p);//�ͷ�
		cout << "mydata delete" << endl;
	}


};

//mydata d1;//���������Զ����ù��캯��
void test()
{
	mydata d1;//ջ�ϣ��������ù��죬���ٵ�����������
}

void main()
{
	//mydata *p = new mydata;

	//delete p;//�Զ����� ���죬����
	//test(); malloc ������ù��캯���������������ʱ����new delete
	mydata *p = (mydata *)malloc(sizeof(mydata));

	//delete p; 
	//free(p);//free���������������

	cin.get();
}