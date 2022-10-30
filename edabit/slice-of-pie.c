/*

Create a function that determines whether or not it's possible to split a pie fairly given these three parameters:

Total number of slices.
Number of recipients.
How many slices each person gets.

The function will be in this form:

EqualSlices(total slices, no. recipients, slices each)

Notes
Return (trivially) true if there are zero people.
It's fine not to use the entire pie.
All test parameters are integers.
Don't forget to return the result.
If you get stuck on a challenge, find help in the Resources tab.
If you're really stuck, unlock solutions in the Solutions tab.

*/

#include <stdio.h>

int
equalslices(int t, int r, int e)
{
	if (r <= 0 || e <= 0)
		return 1;
	return t >= r * e;
}

int
main(void)
{
	printf("%d\n", equalslices(8, 3, 2));
	printf("%d\n", equalslices(8, 3, 3));
	printf("%d\n", equalslices(24, 12, 2));
	printf("%d\n", equalslices(5, 6, 1));
	printf("%d\n", equalslices(5, 0, 100));
	printf("%d\n", equalslices(15, 2, 7));
	printf("%d\n", equalslices(15, 2, 8));
	printf("%d\n", equalslices(11, 5, 2));
	printf("%d\n", equalslices(11, 5, 3));
	printf("%d\n", equalslices(11, 0, 3));
	printf("%d\n", equalslices(0, 0, 3));
	printf("%d\n", equalslices(0, 0, 0));
	printf("%d\n", equalslices(0, -3, -2));
	printf("%d\n", equalslices(-5, -3, -2));
	printf("%d\n", equalslices(-5, 3, 2));
	printf("%d\n", equalslices(-5, 3, -2));
	return 0;
}
