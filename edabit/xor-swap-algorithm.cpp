/*

This is more informational than a challenge. You can actually switch 2 variables with the XOR operation ^. XOR works with two arguments. It turns both arguments in their binary representation, and for each bit, returns 1 if they are different, 0 otherwise.

The return value is the decimal representation of the new binary string. So, if you don't know how to do it, go play around with it! After some time on paper, you will understand what is going on, and how it works.

Your job is to switch 2 variables using the XOR operator, which means your return statement should be return std::make_pair(a, b), but the variables need to be switched.
Examples

XOR(10, 41) ➞ (41, 10)

XOR(69, 420) ➞ (420, 69)

XOR(12345, 890412) ➞ (890412, 12345)

Notes

    Remember to use std::make_pair() instead of just make_pair() (if you don't put using namespace std after #include <utility>).
    If you're stuck, or don't have time to test out different cases, check the Resources tab.

*/

#include <cassert>
#include <utility>

using namespace std;

pair<int, int> XOR(int a, int b)
{
	auto t = a ^ b;
	a ^= t;
	b ^= t;
	return make_pair(a, b);
}

int main()
{
	assert(XOR(10, 41) == make_pair(41, 10));
	assert(XOR(69, 420) == make_pair(420, 69));
	assert(XOR(12345, 890412) == make_pair(890412, 12345));
	assert(XOR(10, 20) == make_pair(20, 10));
	assert(XOR(1, 2) == make_pair(2, 1));
	assert(XOR(555, 666) == make_pair(666, 555));
	assert(XOR(3434, 4343) == make_pair(4343, 3434));
	assert(XOR(5, 6) == make_pair(6, 5));
	assert(XOR(666, 999) == make_pair(999, 666));
	
	return 0;
}
