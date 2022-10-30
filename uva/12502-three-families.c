/*

Three families share a garden. They usually clean the garden together at the end of each week, but last week, family C was on holiday, so family A spent 5 hours, family B spent 4 hours and had everything done.
After coming back, family C is willing to pay $90 to the other two families. How much should family A get?
You may assume both families were cleaning at the same speed.
$90/(5+4)*5=$50? No no no. Think hard. The correct answer is $60. When you figured out why, answer the following question: If family A and B spent x and y hours respectively, and family C paid $z, how much should family A get?
It is guaranteed that both families should get non-negative integer dollars.
WARNING: Try to avoid floating-point numbers. If you really need to, be careful!

Input

The first line contains an integer T (T ≤ 100), the number of test cases. Each test case contains three integers x, y, z (1 ≤ x, y ≤ 10, 1 ≤ z ≤ 1000).

Output

For each test case, print an integer, representing the amount of dollars that family A should get.

Sample Input

2
5 4 90
8 4 123

Sample Output

60
123

*/

#include <assert.h>

int
dollars(int a, int b, int c)
{
	if (a + b == 0)
		return -1;
	return c * (2 * a - b) / (a + b);
}

int
main(void)
{
	assert(dollars(5, 4, 90) == 60);
	assert(dollars(8, 4, 123) == 123);

	return 0;
}
