#include<iostream>
#include<cstdlib>

using namespace std;

char str[1024] = { 0 };//�ڴ澲̬��
//��̬����ջ���� ������
//int *p2= new (str) int[10]{ 1,2,3,4,5,6,7,8,9,0 };//�����ڴ棬str��ʼ�ĵ�ַ
//���������Ը�����д  delete p2
//ջ������̬�������Ը�����д�������� delete p2


void main()
{
	//char str[1024] = { 0 };//�ڴ�ջ��
	//char *str = new char[1024]{ 0 };//����
	int *p1 = new int[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//һ���ڶ���
	int *p2 = new (str) int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//�����ڴ棬str��ʼ�ĵ�ַ��ս������


	for (int i = 0; i < 10; i++)
	{
		cout << p1[i] << " " << p1 + i << "  " << p2[i] << "  " << p2 + i << endl;
	}
	cout << "\n\n";
	free(str);//�ͷ�

	for (int i = 0; i < 10; i++)
	{
		cout << p1[i] << " " << p1 + i << "  " << p2[i] << "  " << p2 + i << endl;
	}
	cout << "\n\n";
	p1 = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	p2 = new (str) int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//ǿ���ƶ��ڴ棬�ٴ�
	for (int i = 0; i < 10; i++)
	{
		cout << p1[i] << " " << p1 + i << "  " << p2[i] << "  " << p2 + i << endl;
	}
	cout << "\n\n";


	//p1 = new int[10]{ 1,2,3,4,5,6,7,8,9,0 };
	//p2 = new (str) int[10]{ 1,2,3,4,5,6,7,8,9,0 };
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << p1[i] << " " << p1 + i << "  " << p2[i] << "  " << p2 + i << endl;
	//}
	//cout << "\n\n";
	cin.get();

}