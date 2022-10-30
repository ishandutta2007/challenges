/*

In this challenge, we extend the FourVector class we created in the first and second installment of the FourVector collection. We will now add Lorentz transformations namely "Pure Rotations" and "Pure Boosts". For details on this operation, please refer to the Wiki page linked in the Resources.

So, please add the following features to the class FourVector:

    A helper method KroneckerDelta which takes two integers (say i and j) and returns 1 if i=j and 0 otherwise.
    A helper method LeviCivitaSymbol which takes three integers (say i, j and k) and returns 1 if (i,j,k) is an even permutation of (1,2,3) (i.e. (i,j,k) is (1,2,3), (2,3,1) or (3,1,2)), -1if (i,j,k) is an odd permutation of (1,2,3) (i.e. (i,j,k) is (1,3,2), (2,1,3) or (3,2,1)) and 0 otherwise (i.e. if i=j or i=k or j=k).
    A method PureRotation which takes a 3D-vector and an angle (in degrees) as arguments. It should perform a pure rotation (no boost) as specified here. In the test cases, the 3D-vector is not always a unit vector, so please normalize it. The return value is a new Four Vector, i.e. the original FV is not changed.
    A method PureBoost which takes a 3D-vector as an argument representing a 3-velocity between the two reference frames as specified here. It should perform a pure boost (no rotation by the 3-velocity passed as argument). The return value is a new Four Vector, i.e. the original FV is not changed. Please use a value of 299792458 for the speed of light (in meters per second).

Examples

u1 = FourVector([0, 1, 0, 0])
u1.KroneckerDelta(1, 1) ➞ 1
u1.KroneckerDelta(1, 2) ➞ 0
u1.LeviCivitaSymbol(1, 3, 2) ➞ -1
u1.LeviCivitaSymbol(1, 3, 1) ➞ 0
u1.PureRotation([0, 1, 0], 90) ➞ FourVector([0.0, 0.0, 0.0, -1.0])
c = 299792458.0
u1.PureBoost([c/100., 0, 0]) ➞ FourVector([-0.010000500037503126, 1.0000500037503126, 0.0, 0.0])

Notes

Please save your FourVector class for later use, we will add new features in upcoming challenges in this series! You may assume valid test cases (e.g. no boost with v=[0,0,0]).

*/

#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define deg2rad(x) (((x)*M_PI) / 180)

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
		static const auto eps = 1e-6;
		return fabs(t - v.t) < eps &&
			   fabs(x - v.x) < eps &&
			   fabs(y - v.y) < eps &&
			   fabs(z - v.z) < eps;
	}

	double length() const
	{
		return sqrt(fabs(t * t - x * x - y * y - z * z));
	}

	static int kronecker_delta(int i, int j)
	{
		return i == j;
	}

	static int levi_civita(int i, int j, int k)
	{
		if (i == j || i == k || j == k)
			return 0;

		if (i == 1 && j == 2 && k == 3)
			return 1;
		if (i == 2 && j == 3 && k == 1)
			return 1;
		if (i == 3 && j == 1 && k == 2)
			return 1;

		if (i == 1 && j == 3 && k == 2)
			return -1;
		if (i == 2 && j == 1 && k == 3)
			return -1;
		if (i == 3 && j == 2 && k == 1)
			return -1;

		assert(0);
		return 0;
	}

	static FourVector normalize_3d_vector(const FourVector &v)
	{
		double l = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		if (l == 0)
			return FourVector();
		return FourVector(0, v.x / l, v.y / l, v.z / l);
	}

	FourVector transform(double m[4][4], const FourVector &v) const
	{
		double t = m[0][0] * v.t + m[0][1] * v.x + m[0][2] * v.y + m[0][3] * v.z;
		double x = m[1][0] * v.t + m[1][1] * v.x + m[1][2] * v.y + m[1][3] * v.z;
		double y = m[2][0] * v.t + m[2][1] * v.x + m[2][2] * v.y + m[2][3] * v.z;
		double z = m[3][0] * v.t + m[3][1] * v.x + m[3][2] * v.y + m[3][3] * v.z;
		return FourVector(t, x, y, z);
	}

	// circular rotations
	FourVector pure_rotation(FourVector axis, double angle) const
	{
		auto r = deg2rad(angle);
		auto c = cos(r);
		auto s = sin(r);
		auto w = normalize_3d_vector(axis);
		double xfm[4][4] = { 0 };
		xfm[1][1] = c + w.x * w.x * (1 - c);
		xfm[1][2] = w.x * w.y * (1 - c) - w.z * s;
		xfm[1][3] = w.y * s + w.x * w.z * (1 - c);
		xfm[2][1] = w.z * s + w.x * w.y * (1 - c);
		xfm[2][2] = c + w.y * w.y * (1 - c);
		xfm[2][3] = -w.x * s + w.y * w.z * (1 - c);
		xfm[3][1] = -w.y * s + w.x * w.z * (1 - c);
		xfm[3][2] = w.x * s + w.y * w.z * (1 - c);
		xfm[3][3] = c + w.z * w.z * (1 - c);
		xfm[0][0] = 1;
		return transform(xfm, *this);
	}

	// hyperbolic rotations
	FourVector pure_boost(FourVector vel) const
	{
		static const double c = 299792458;

		double B[] = { 0, vel.x / c, vel.y / c, vel.z / c };
		double L = B[1] * B[1] + B[2] * B[2] + B[3] * B[3];
		double y = 1 / sqrt(1 - L);

		double xfm[4][4] = { 0 };
		xfm[0][0] = y;
		for (int i = 1; i <= 3; i++)
			xfm[i][0] = xfm[0][i] = -y * B[i];
		for (int i = 1; i <= 3; i++)
		{
			for (int j = 1; j <= 3; j++)
				xfm[i][j] = ((y - 1) * (B[i] * B[j]) / L) + kronecker_delta(i, j);
		}

		return transform(xfm, *this);
	}

	void components(double r[4]) const
	{
		r[0] = t;
		r[1] = x;
		r[2] = y;
		r[3] = z;
	}

	const char *structure() const
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

int main()
{
	auto u1 = FourVector(0, 1, 0, 0);
	auto u3 = FourVector(0, 0, 0, 1);
	auto v5 = FourVector(-1, 37, 55, -108);
	auto v6 = FourVector(0.5, 1.0, -2.0, 10.0);
	auto v7 = FourVector(-0.25, 1.2, -2.7, 33.3);
	auto v8 = FourVector(-1, 2, -3, 4);

	assert(FourVector::kronecker_delta(1, 1) == 1);
	assert(FourVector::kronecker_delta(1, 2) == 0);
	assert(FourVector::kronecker_delta(1, 3) == 0);
	assert(FourVector::kronecker_delta(3, 1) == 0);
	assert(FourVector::kronecker_delta(3, 2) == 0);
	assert(FourVector::kronecker_delta(2, 2) == 1);

	assert(FourVector::levi_civita(1, 2, 3) == 1);
	assert(FourVector::levi_civita(2, 3, 1) == 1);
	assert(FourVector::levi_civita(3, 1, 2) == 1);
	assert(FourVector::levi_civita(1, 3, 2) == -1);
	assert(FourVector::levi_civita(2, 1, 3) == -1);
	assert(FourVector::levi_civita(3, 2, 1) == -1);
	assert(FourVector::levi_civita(1, 1, 2) == 0);
	assert(FourVector::levi_civita(2, 2, 2) == 0);
	assert(FourVector::levi_civita(3, 1, 3) == 0);

	auto r1 = u1.pure_rotation(FourVector(0, 1, 0, 0), 90);
	auto r2 = u1.pure_rotation(FourVector(0, 0, 1, 0), 90);
	auto r3 = u1.pure_rotation(FourVector(0, 0, 0, 1), 90);
	auto r4 = u1.pure_rotation(FourVector(0, 1, 1, 0), 90);
	auto r5 = u1.pure_rotation(FourVector(0, 0, 1, 1), 90);
	auto r6 = u1.pure_rotation(FourVector(0, 1, 0, 1), 90);
	auto r7 = u1.pure_rotation(FourVector(0, 1, 1, 1), 45);
	auto r8 = r7.pure_rotation(FourVector(0, 1, 1, 1), -45);
	assert(r1 == FourVector(0, 1, 0, 0));
	assert(r2 == FourVector(0, 0, 0, -1));
	assert(r3 == FourVector(0, 0, 1, 0));
	assert(r4 == FourVector(0.0, 0.5, 0.5, -0.7071067811865475));
	assert(r5 == FourVector(0.0, 0.0, 0.7071067811865475, -0.7071067811865475));
	assert(r6 == FourVector(0.0, 0.5, 0.7071067811865475, 0.5));
	assert(r8 == u1);

	static const double c = 299792458;
	auto b1 = u1.pure_boost(FourVector(0, c / 100, 0, 0));
	auto b2 = u3.pure_boost(FourVector(0, c / 10, 0, 0));
	auto b3 = v5.pure_boost(FourVector(0, c / 10., c / 5., c / 5.));
	auto b4 = v6.pure_boost(FourVector(0, 0., 0.999 * c, 0.));
	auto b5 = v7.pure_boost(FourVector(0, 0., 0, 0.99999999 * c));
	auto b6 = v8.pure_boost(FourVector(0, c / 10., c / 10., c / 10.));
	auto b7 = (v5 + v7).pure_boost(FourVector(0, 0, c / 2., 0.));
	assert(b1 == FourVector(-0.010000500037503126, 1.0000500037503126, 0.0, 0.0));
	assert(b2 == FourVector(0.0, 0.0, 0.0, 1.0));
	assert(b3 == FourVector(6.184880536659318, 36.73464473547082, 54.46928947094164, -108.53071052905835));
	assert(b4 == FourVector(55.87094756123916, 1.0, -55.90449696930236, 10.0));
	assert(b5 == FourVector(-237234.324112771, 1.2, -2.7, 237234.32644975893));
	assert(b6 == FourVector(-1.3199500146737049, 2.1168807816469806, -2.8831192183530185, 4.116880781646981));
	assert(b7 == FourVector(-31.638794751591494, 38.2, 61.112525993721896, -74.7));

	return 0;
}