#include <iostream>
#include <list>

using namespace std;

class Shape
{
public:
	virtual void Draw() = 0;	// 定义虚继承接口，由子类实现
};

class Circle : public Shape
{
public:
	virtual void Draw()
	{
		cout << "绘制圆形" << endl;
	}
};

class Rectangle : public Shape
{
public:
	virtual void Draw()
	{
		cout << "绘制矩形" << endl;
	}
};

class Triangle : public Shape
{
public:
	virtual void Draw()
	{
		cout << "绘制三角行" << endl;
	}
};

void main()
{
	Circle *myc = new Circle;
	Rectangle *myR = new Rectangle;
	Triangle *myT = new Triangle;
	list<Shape *>mylist{ myc, myR, myT };					//用指向父类的指针，实现对子类的调用
	for (auto &ib : mylist)
	{
		(*ib).Draw();
	}

	cin.get();
}