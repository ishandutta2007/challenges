/*

You are given the sizes of angles of a simple quadrilateral (in degrees) A, B, C and D, in some order along its perimeter.
Determine whether the quadrilateral is cyclic.

Note: A quadrilateral is cyclic if and only if the sum of opposite angles is 180∘.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains four space-separated integers A, B, C and D.

Output

Print a single line containing the string "YES" if the given quadrilateral is cyclic or "NO" if it is not (without quotes).
You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints

1≤T≤104
1≤A,B,C,D≤357
A+B+C+D=360

*/

#include <assert.h>

int
cyclic(int a, int b, int c, int d)
{
	return (a + c == 180) && (b + d == 180);
}

int
main(void)
{
	assert(cyclic(10, 20, 30, 300) == 0);
	assert(cyclic(10, 20, 170, 160) == 1);
	assert(cyclic(179, 1, 179, 1) == 0);

	return 0;
}
