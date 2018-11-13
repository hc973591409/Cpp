#include <iostream>
#include <list>

using namespace std;

class Shape
{
public:
	virtual void Draw() = 0;	// ������̳нӿڣ�������ʵ��
};

class Circle : public Shape
{
public:
	virtual void Draw()
	{
		cout << "����Բ��" << endl;
	}
};

class Rectangle : public Shape
{
public:
	virtual void Draw()
	{
		cout << "���ƾ���" << endl;
	}
};

class Triangle : public Shape
{
public:
	virtual void Draw()
	{
		cout << "����������" << endl;
	}
};

void main()
{
	Circle *myc = new Circle;
	Rectangle *myR = new Rectangle;
	Triangle *myT = new Triangle;
	list<Shape *>mylist{ myc, myR, myT };					//��ָ�����ָ�룬ʵ�ֶ�����ĵ���
	for (auto &ib : mylist)
	{
		(*ib).Draw();
	}

	cin.get();
}