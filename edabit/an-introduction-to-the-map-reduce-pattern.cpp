/*

You will be implementing a basic case of the map-reduce pattern in programming. Use the built in C++ array functions std::transform for map and std::accumulate for reduce to solve the following problem.

Given a vector stored as an array of numbers, find the magnitude of the vector (this is similar to the function hypot()). Use the standard distance formula for n-dimensional Cartesian coordinates.
Examples

magnitude([3, 4]) ➞ 5

magnitude([0, 0, -10]) ➞ 10

magnitude([]) ➞ 0

magnitude([2, 3, 6, 1, 8] ) ➞ 10.677078252031311

Notes

    The array can have any length.
    The input array will contain integers (except for empty array [] ➞ 0).
    Use both std::transform(...) and std::accumulate(...).
    Don't use hypot().

*/

#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

double magnitude(vector<int> p)
{
	transform(p.begin(), p.end(), p.begin(), [](int x) -> int { return x * x; });
	return sqrt(accumulate(p.begin(), p.end(), 0, plus<int>()));
}

void eq(double x, double y)
{
	assert(fabs(x - y) < 1e-8);
}

int main()
{
	eq(magnitude({ 3, 4 }), 5);
	eq(magnitude({ 0, 0, -10 }), 10);
	eq(magnitude({}), 0);
	eq(magnitude({ 2, 3, 6, 1, 8 }), 10.677078252031311);
	eq(magnitude({ 9, -9, 3 }), 13.076696830622021);
	eq(magnitude({ -24, 94, 4, 0, 10 }), 97.61147473529944);

	return 0;
}
