#include<iostream>
using namespace std;
class Rectangle
{
private:
	float width;
	float length;
	
public:
	float getwidth();// this function will return the width of rectangle
	float getlength();// this function will return the length of rectangle
	void setlength();// this function will take length as  parameter and sets with the length of rectangle object
	void setwidth(); //this function will take width as  parameter and sets with the length of rectangle object
	void GetArea();//returns area
	void RotateRectangel();// swap values of lenght and width
	void draw();//draw rectangle



};
