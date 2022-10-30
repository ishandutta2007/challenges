/*
You are given a positive integer . Print a numerical triangle of height

like the one below:

1
22
333
4444
55555
......

Can you do it using only arithmetic operations, a single for loop and print statement?

Use no more than two lines. The first line (the for statement) is already written for you. You have to complete the print statement.

Note: Using anything related to strings will give a score of 0.
*/

#include <stdio.h>
#include <math.h>

void
print(int n)
{
	for (int i = 1; i <= n; i++)
		printf("%d\n", (int)(pow(10, i) / 9) * i);
}

int
main(void)
{
	print(5);
	print(9);
	return 0;
}
