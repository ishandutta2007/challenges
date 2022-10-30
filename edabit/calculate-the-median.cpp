/*

Create a function that takes an array of numbers and return its median. If the input array is even length, take the average of the two medians, else, take the single median.
Examples

median([2, 5, 6, 2, 6, 3, 4]) ➞ 4

median([21.4323, 432.54, 432.3, 542.4567]) ➞ 432.4

median([-23, -43, -29, -53, -67]) ➞ -43

Notes

    Input can be any negative or positive number.
    Input array will contain at least four numbers.
    See Resources tab for info on calculating the median.

*/

#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
T median(vector<T> a)
{
	sort(a.begin(), a.end());
	auto l = a.size();
	if (l == 0)
		return 0;
	if ((l & 1) == 0)
		return (a[l / 2 - 1] + a[l / 2]) / 2;
	return a[l / 2];
}

int main()
{
	assert(median<int>({ 342, 98, 5456, 32, 786, 432, 890, 321 }) == 387);
	assert(median<int>({ 32786, 7837, 83736, 83736, 10383, 738393 }) == 58261);
	assert(median<int>({ 0, 0, 0, 0 }) == 0);
	assert(median<int>({ 238, 432, 897, 710 }) == 571);

	assert(median<int>({ 20, 40, 20, 30, 50, 60, 70, 0, 20 }) == 30);
	assert(median<int>({ 32, 5, 78, 32, 4, 5, 3 }) == 5);
	assert(median<int>({ 7685, 83736, 38376, 73638, 7337 }) == 38376);

	assert(median<double>({ 1, 0, 1, 0, 0, 0, 1, 1 }) == 0.5);

	assert(median<int>({ -20, 40, 30, -2, 40, -13 }) == 14);
	assert(median<int>({ -30, -42, -60, -10, -30, -50 }) == -36);

	return 0;
}
