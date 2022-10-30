/*

Peter has n cigarettes. He smokes them one by one keeping all the butts. Out of k > 1 butts he can roll a new cigarette.
How many cigarettes can Peter have?

Input

Input is a sequence of lines. Each line contains two integer numbers giving the values of n and k. The
input is terminated by end of file.

Output

For each line of input, output one integer number on a separate line giving the maximum number of
cigarettes that Peter can have.

Sample Input

4 3
10 3
100 5

Sample Output

5
14
124

*/

#include <assert.h>

int
cigs(int n, int k)
{
	int d, e, r;

	r = n;
	do {
		d = n / k;
		e = n % k;
		r += d;
		n = d + e;
	} while (n >= k);

	return r;
}

int
main(void)
{
	assert(cigs(4, 3) == 5);
	assert(cigs(10, 3) == 14);
	assert(cigs(100, 5) == 124);

	return 0;
}
