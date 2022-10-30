/*

Have the function PentagonalNumber(num) read num which will be a positive integer and determine how many dots exist in a pentagonal shape around a center dot on the Nth iteration.
For example, in the image below you can see that on the first iteration there is only a single dot, on the second iteration there are 6 dots,
on the third there are 16 dots, and on the fourth there are 31 dots. 

*/

#include <stdio.h>

int
pentagonalnumber_slow(int n)
{
	int i, s;

	if (n <= 0)
		return 0;

	s = 1;
	for (i = 2; i <= n; i++)
		s += 5 * (i - 1);
	return s;
}

int
pentagonalnumber(int n)
{
	if (n <= 0)
		return 0;
	return 1 + 5 * (n - 1) * n / 2;
}

int
main(void)
{
	int i;
	for (i = 0; i <= 100; i++)
		printf("%d %d %d\n", i, pentagonalnumber_slow(i), pentagonalnumber(i));
	return 0;
}
