/*

In this exercise the goal is to extend the Math() object adding four methods for calculate different types of averages.

    Arithmetic Mean: The division of the sum of the numbers by the quantity of numbers.
        avg of [A, B, C] ➞ (A + B + C) / 3
    Quadratic Mean: Also called Root Mean Square, is the square root of the arithmetic mean of the squared numbers.
        qAvg of [A, B, C] ➞ ²√ ( (A² + B² + C²) / 3 )
    Harmonic Mean: is the reciprocal of the arithmetic mean of the numbers reciprocals.
        hAvg of [A, B, C] ➞ ( (A⁻¹ + B⁻¹ + C⁻¹) / 3 )⁻¹
    Geometric Mean: is the n-th root of the product of the numbers, where n is the quantity of numbers.
        gAvg of [A, B, C] ➞ ³√ (A * B * C)

For each average type build a function that, given a required parameter (the array containing the numbers) and an optional one (the precision, or number of floating digits to return) returns the result as a number.
Examples

Math.avg([3, 5, 7])➞ 5
//Precision is an optional parameter.
// (3 + 5 + 7) / 3 = 15 / 3 = 5

Math.qAvg([3, 5, 7], 1) ➞ 5.3
// ²√ ( (3² + 5² + 7²) / 3 ) = ²√ (83 / 3) = 5.3

Math.hAvg([3, 5, 7], 1) ➞ 4.4
// Precision is required only for the final result.
// (3⁻¹ + 5⁻¹ + 7⁻¹) / 3 )⁻¹ = (0.676... / 3)⁻¹ = 4.4

Math.gAvg([3, 5, 7], 1) ➞ 4.7
// ³√ (3 * 5 * 7) = ³√ 105 = 4.7

Notes

    Pay attention to cumulative rounding errors! Precision is required only if the parameter is indicated and only for the final result.
    All given arrays are valid ones containing positive numbers greater than zero, either integers or float.
    REVISION NOTE: Implementing a method for to get the n-th root of a number can lead to rounding imprecisions if you use a combination of exponential and logarithm instead of a direct formula. Thanks to @Pustur and @xAlien95, see the Comments tab for more info. After the update, some old solution could fail the last test for the geometric average.

	https://stackoverflow.com/questions/7308627/javascript-calculate-the-nth-root-of-a-number
*/

#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

template <typename T>
T avg(const vector<T> &v)
{
	auto l = v.size();
	if (l == 0)
		return 0;

	T s = 0;
	for (auto x : v)
		s += x;
	return s / l;
}

template <typename T>
T qavg(const vector<T> &v)
{
	auto l = v.size();
	if (l == 0)
		return 0;

	T s = 0;
	for (auto x : v)
		s += x * x;
	return sqrt(s / l);
}

template <typename T>
T havg(const vector<T> &v)
{
	auto l = v.size();
	if (l == 0)
		return 0;

	T s = 0;
	for (auto x : v)
		s += 1.0 / x;
	return l / s;
}

template <typename T>
T gavg(const vector<T> &v)
{
	auto l = v.size();
	if (l == 0)
		return 0;

	T s = 1;
	for (auto x : v)
		s *= x;
	return pow(s, 1.0 / l);
}

template <typename T>
T abs(T x)
{
	if (x < 0)
		return -x;
	return x;
}

template <typename T>
void eq(T (*f)(const vector<T> &), const vector<T> &v, T r, T eps)
{
	assert(abs(f(v) - r) <= pow(10.0, -eps));
}

int main()
{
	eq<int>(avg, { 3, 5, 7 }, 5, 0);
	eq<double>(qavg, { 3, 5, 7 }, 5.3, 1);
	eq<double>(havg, { 3, 5, 7 }, 4.4, 1);
	eq<double>(gavg, { 3, 5, 7 }, 4.7, 1);

	eq<int>(avg, { 1, 4, 4 }, 3, 0);
	eq<double>(qavg, { 1, 4, 4 }, 3.317, 3);
	eq<double>(havg, { 1, 4, 4 }, 2, 5);
	eq<double>(gavg, { 1, 4, 4 }, 2.5198421, 7);

	eq<double>(avg, { 0.11, 0.22, 0.33 }, 0.2, 1);
	eq<double>(qavg, { 0.11, 0.22, 0.33 }, 0.237627, 6);
	eq<double>(havg, { 0.11, 0.22, 0.33 }, 0.18, 4);
	eq<double>(gavg, { 0.11, 0.22, 0.33 }, 0.2, 2);

	eq<double>(avg, { 1, 23, 456, 7890 }, 2092.5, 1);
	eq<double>(qavg, { 1, 23, 456, 7890 }, 3951.599865877111, 12);
	eq<double>(havg, { 1, 23, 456, 7890 }, 3.8248304676450755, 12);
	eq<double>(gavg, { 1, 23, 456, 7890 }, 95.37672823128207, 13);

	return 0;
}
