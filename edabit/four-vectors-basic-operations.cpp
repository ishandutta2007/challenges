/*

This is the first challenge of the "Four Vectors" collection. Four Vectors are vectors with four components that are used to describe relativistic physics.
For details please refer to this wiki entry.

In this challenge, create a class FourVector with the following properties:

    If called with a list of length 4 as a parameter, it uses the list entries as components of the FourVector (FV) instance.
    If called without a parameter, the components should be [0.0, 0.0, 0.0, 0.0].
    Getter and Setter methods GetComponents and SetComponents, see test cases
    Methods two add and subtract two FV instances.
    Support comparing two Four Vectors.
    Support printing a FV in the form (0.5, 1.0, -2.0, 10.0) where the components are rounded to three decimal places.

Consider using magic methods like __add__, __eq__ and __str__ to solve the last three bullet points.
Examples

v = FourVector([1, 2, 3, 4])
print(v) ➞ (1, 2, 3, 4)

v2 = FourVector([1, 0, 1, 0])
print(v + v2) ➞ (2, 2, 4, 4)

Notes

Please save your FourVector class for later use, we will add new methods in upcoming challenges in this series!

*/

#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

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

	bool operator==(const FourVector &v) const
	{
		static const auto eps = 1e-8;
		return fabs(t - v.t) < eps &&
			   fabs(x - v.x) < eps &&
			   fabs(y - v.y) < eps &&
			   fabs(z - v.z) < eps;
	}

	void components(double r[4]) const
	{
		r[0] = t;
		r[1] = x;
		r[2] = y;
		r[3] = z;
	}

	char *string(char *b) const
	{
		sprintf(b, "(%.3f, %.3f, %.3f, %.3f)", t, x, y, z);
		return b;
	}
};

void test_eq(FourVector v, const vector<double> &r)
{
	double p[4];

	v.components(p);
	assert(!memcmp(&r[0], p, sizeof(p)));
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

	test_eq(v5, { -1, 37, 55, -108 });
	test_eq(v8, { -1, 2, -3, 4 });
	v8 = FourVector(7, 3, 5, -6);
	test_eq(v8, { 7, 3, 5, -6 });
	auto v9 = FourVector();
	test_eq(v9, { 0, 0, 0, 0 });
	v9 = FourVector(2.5, -1.5, 3.7, -7.4);
	test_eq(v9, { 2.5, -1.5, 3.7, -7.4 });

	assert(v0 == v0a);
	assert(v0 + v1 == FourVector(1, 2, 3, 4));
	assert(v2 + v3 == FourVector(2, 0, 1, 1));
	assert(v2 + v5 == FourVector(0, 37, 55, -107));
	assert(v2 + v5 + v4 == FourVector(-1, 41, 56, -105));
	assert(v0 + v1 + v2 + v3 + v4 + v5 == FourVector(1, 43, 60, -101));
	assert(v1 + v6 == FourVector(1.5, 3.0, 1.0, 14.0));
	assert(v6 + v7 == FourVector(0.25, 2.2, -4.7, 43.3));
	assert(v0 + v4 + v6 + v7 == FourVector(-0.75, 6.2, -3.7, 45.3));

	char s[128], t[128];
	assert(v2 - v1 == FourVector(0, -2, -3, -3));
	assert(v4 - v2 == FourVector(-2, 4, 1, 1));
	assert(v5 - v0 == FourVector(-1, 37, 55, -108));
	assert(v5 - v1 - v6 == FourVector(-2.5, 34.0, 54.0, -122.0));
	(v4 - v7).string(s);
	FourVector(-0.75, 2.8, 3.7, -31.3).string(t);
	assert(!strcmp(s, t));

	assert(v5 - v2 + v4 == FourVector(-3, 41, 56, -107));
	assert(v6 + v3 - v6 == v3);
	assert(v5 - v7 + v1 - v0 + v2 == FourVector(1.25, 37.8, 60.7, -136.3));

	v1.string(s);
	assert(!strcmp(s, "(1.000, 2.000, 3.000, 4.000)"));
	v6.string(s);
	assert(!strcmp(s, "(0.500, 1.000, -2.000, 10.000)"));
	(v0 + v4 + v6 + v7).string(s);
	assert(!strcmp(s, "(-0.750, 6.200, -3.700, 45.300)"));

	return 0;
}