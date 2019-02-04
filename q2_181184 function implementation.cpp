#include<iostream>
using namespace std;
#include"Header.h"
float Rectangle::getwidth()
{
	cout << "please enter width?" << endl;
	float a;
	cin >> a;
	if (a < 0)
	{
		a = (-1) * a;
	}
	return a;
}
float Rectangle::getlength()
{
	cout << "please enter length?" << endl;
	float b;
	cin >> b;
	if (b < 0)
	{
		b = (-1) * b;
	}
	return b;
}
void Rectangle::GetArea()
{
	float area = length*width;
	cout << "area" << area << endl;
}
void Rectangle::setlength()
{
	length = getlength();
	cout << "lenght" << length << endl;
}
void Rectangle::setwidth()
{
	width = getwidth();
	cout << "width" << width << endl;
}
void Rectangle::RotateRectangel()
{
	float temp;
	temp = width;
	width = length;
	length = temp;
	cout << "swapped values" << endl;
	cout << "width" << width << endl;
	cout << "lenght" << length << endl;
}

void Rectangle::draw()
{
	for (int i = 0; i <width ; i++)
	{
		for (int i = 0; i < length; i++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
