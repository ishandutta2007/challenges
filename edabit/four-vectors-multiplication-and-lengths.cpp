/*

In this challenge, we extend the FourVector class we created in the first installment of the FourVector collection.

So, please add the following features to the class FourVector:

    Support multiplication of Four Vectors (FV). This should include multiplication of two FVs as well as multiplications 'scalar times FV' and 'FV times scalar'. Think about magic methods like __mul__...
    A method GetLength which returns the length of the FV. The length is the square root of the absolute value of the product of the FV with itself. Attention: contrasting to 'normal' vectors the product of a FV with itself may be negative! For details refer to the Wiki article (see resources).
    A method GetCausalStructure. Let p the product of the FV with itself. The method then returns "lightlike" if p=0, "spacelike" if p<0 and "timelike" if p>0. The causal structure has an important meaning in special relativity: a lightlike FV can be connected to the origin (0, 0, 0, 0) by a ray a light, a timelike FV is connected to the origin by 'more time than space' which means there can be a causal connection (cause and effect) between the origin and the event represented by the FV. In contrast, for a spacelike FV there is 'more space than time' and there can't be a causal connection without violating the 'speed limit' of special relativity.

Examples

v1 = FourVector([1, 2, 3, 4])
v2 = FourVector([1, 0, 0, 1])
2 * v1 ➞ FourVector([2, 4, 6, 8])
v2 * 3 ➞ FourVector([3, 0, 0, 3])
v1 * v3 ➞ -3
v1.GetLength() ➞ 5.291502622129181
v1.GetCausalStructure() ➞ "spacelike"

Notes

Please save your FourVector class for later use, we will add new methods in upcoming challenges in this series!

*/

#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

using namespace std;

struct FourVector
{
	double t, x, y, z;

	FourVector()
	{
		t = x = y = z = 0;
	}

	FourVector(double t, double x, double y, double z)
		: t(t), x(x), y(y), z(z)
	{
	}

	FourVector operator+(const FourVector &v) const
	{
		return FourVector(t + v.t, x + v.x, y + v.y, z + v.z);
	}

	FourVector operator-(const FourVector &v) const
	{
		return FourVector(t - v.t, x - v.x, y - v.y, z - v.z);
	}

	FourVector operator*(double s) const
	{
		return FourVector(s * t, s * x, s * y, s * z);
	}

	double operator*(const FourVector &v) const
	{
		return t * v.t - x * v.x - y * v.y - z * v.z;
	}

	bool operator==(const FourVector &v) const
	{
		static const auto eps = 1e-8;
		return fabs(t - v.t) < eps &&
			   fabs(x - v.x) < eps &&
			   fabs(y - v.y) < eps &&
			   fabs(z - v.z) < eps;
	}

	double length() const
	{
		return sqrt(fabs(t * t - x * x - y * y - z * z));
	}

	void components(double r[4]) const
	{
		r[0] = t;
		r[1] = x;
		r[2] = y;
		r[3] = z;
	}

	const char *structure()
	{
		double p = t * t - x * x - y * y - z * z;
		if (p < 0)
			return "spacelike";
		if (p > 0)
			return "timelike";
		return "lightlike";
	}

	char *string(char *b) const
	{
		sprintf(b, "(%.3f, %.3f, %.3f, %.3f)", t, x, y, z);
		return b;
	}
};

FourVector operator*(double s, const FourVector &v)
{
	return FourVector(s * v.t, s * v.x, s * v.y, s * v.z);
}

void test_dot(FourVector a, FourVector b, double v)
{
	auto u = a * b;
	assert(fabs(u - v) < 1e-4);
}

int main()
{
	auto v0a = FourVector();
	auto v0 = FourVector(0, 0, 0, 0);
	auto v1 = FourVector(1, 2, 3, 4);
	auto v2 = FourVector(1, 0, 0, 1);
	auto v3 = FourVector(1, 0, 1, 0);
	auto v4 = FourVector(-1, 4, 1, 2);
	auto v5 = FourVector(-1, 37, 55, -108);
	auto v6 = FourVector(0.5, 1.0, -2.0, 10.0);
	auto v7 = FourVector(-0.25, 1.2, -2.7, 33.3);
	auto v8 = FourVector(-1, 2, -3, 4);

	test_dot(v1, v2, -3);
	test_dot(v3, v4, -2);
	test_dot(v4, v3, -2);
	test_dot(v5, v5, -16057);
	test_dot(v5, v6, 1152.5);
	test_dot(v7, v6, -339.725);

	assert(2 * v1 == FourVector(2, 4, 6, 8));
	assert(1 * v3 == v3);
	assert(0 * v3 == v0a);
	assert(-5 * v4 == FourVector(5, -20, -5, -10));
	assert(-0.25 * v7 == FourVector(0.0625, -0.3, 0.675, -8.325));

	assert(v1 * 2 == FourVector(2, 4, 6, 8));
	assert(v3 * 1 == v3);
	assert(v3 * 0 == v0a);
	assert(v4 * -5 == FourVector(5, -20, -5, -10));
	assert(v7 * -0.25 == FourVector(0.0625, -0.3, 0.675, -8.325));

	double lengths[] = { 0.0, 5.291502622129181, 0.0, 0.0, 4.47213595499958, 126.7162183779172, 10.23474474522936, 33.42988932078597, 5.291502622129181 };
	const char *structures[] = { "lightlike", "spacelike", "lightlike", "lightlike", "spacelike", "spacelike", "spacelike", "spacelike", "spacelike" };
	FourVector vectors[] = { v0, v1, v2, v3, v4, v5, v6, v7, v8 };
	for (size_t i = 0; i < nelem(lengths); i++)
	{
		assert(fabs(vectors[i].length() - lengths[i]) < 1e-4);
		assert(!strcmp(vectors[i].structure(), structures[i]));
	}

	return 0;
}
