/*

Your task is to create a Circle constructor that creates a circle with a radius provided by an argument. The circles constructed must have two getters getArea() (PIr^2) and getPerimeter() (2PI*r) which give both respective areas and perimeter (circumference).

For help with this class, I have provided you with a Rectangle constructor which you can use as a base example.

Notes

Don't worry about floating point precision - I've factored in the chance that your answer may be more or less accurate than mine. This is more of a tutorial than a challenge so the topic covered may be considered advanced, yet the challenge is more simple - so if this challenge gets labelled as easy, don't worry too much.

*/

#include <iostream>
#include <cmath>

using namespace std;

class Circle
{
public:
	double radius;

	Circle(double r) : radius(r)
	{
	}

	double getArea()
	{
		return M_PI * radius * radius; 
	}

	double getPerimeter()
	{
		return 2 * M_PI * radius;
	}
};

int main()
{
	Circle c1(11);
	cout << c1.getArea() << endl;

	Circle c2(4.44);
	cout << c2.getPerimeter() << endl;

	return 0;
}
