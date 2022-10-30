/*

Ujan is a software developer. He is developing a software that takes two integers L and R and outputs the count of integers in the sequence L,L+1,…,R−1,R whose sum of digits (SOD) is divisible by 3.

He has developed the user interface (UI) quite easily. He is having a hard time finding the logic to solve the problem. As you are not only a good friend of Ujan but also a good problem solver, he asks you to help him out.

Can you solve the problem for your friend, Ujan?

Input Format

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The only line of each test case contains two integer L,R.

Output Format

For each test case, print a single line containing one integer equal to the count of of integers in the sequence, whose sum of digits is divisible by 3 .

Constraints
1≤T≤10^4
1≤L≤R≤101^8

*/

#include <assert.h>

typedef unsigned long long uvlong;

uvlong
solve(uvlong l, uvlong r)
{
	return (r / 3) - (l - 1) / 3;
}

int
main(void)
{
	assert(solve(139, 141) == 1);
	assert(solve(100, 1235) == 378);
	assert(solve(1000, 2537) == 512);
	assert(solve(998244353ULL, 1000000007ULL) == 585218ULL);
	assert(solve(27182818284ULL, 31415926535897ULL) == 10462914572538ULL);

	return 0;
}
