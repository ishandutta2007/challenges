/*

Introduction
I have decided that this Christmas, as a "present" to a friend, I wish to purchase the things described in the classic song "The 12 Days of Christmas". The only problem is, I don't know how to calculate the total price!

Your Task
Given a list of prices (in order from first to last), calculate the total price of all the items if they were ordered as described by the song. Remember, each item is ordered once more than the one before it, and this repeats for as many days as there are items!

Example
The first few lines of the song:

On the 1st day of Christmas, my true love gave to me
A partridge in a pear tree

On the 2nd day of Christmas, my true love gave to me
Two turtle doves,
And a partridge in a pear tree.

On the 3rd day of Christmas, my true love gave to me
Three French hens,
Two turtle doves,
And a partridge in a pear tree.
⋮

The song then continues, each day adding in a new present, with the number increasing each time (e.g. "4 calling birds", "5 gold rings", etc.). up to a total of 12 days.

Therefore, the total number of each item as the song continues for 12 days goes: 1 partridge on day 1, 2 partridges and 2 doves on day 2, 3 partridges, 4 doves, and 3 French hens on day 3, etc.

Rules and Scoring
Your program should take as input a list of prices (which can be of any length), and calculate the total price in the manner described above. Programs which give me the wrong answer for their inputs will be disqualified. Shortest size in bytes wins!

Examples
[20, 20, 20]: 200
[25, 10]: 70
[10, 25, 10, 75]: 550
Example price table
Feel free to use this table to test your program. The correct output should be 51765.02.

Item	Price
A partridge in a pear tree	27.50
A turtle dove	25.00
One French hen	5.00
One calling bird	70.00
A gold ring	65.00
One goose a-laying	25.00
One swimming swan	500.00
A milkmaid hired for 1hr	4.25
One lady dancing	289.65
One lord leaping	318.26
One piper piping	100.83
One drummer drumming	100.13
Or, as a single list of prices:

[27.50, 25.00, 5.00, 70.00, 65.00, 25.00, 500.00, 4.25, 289.65, 318.26, 100.83, 100.13]

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
cost(double *a, size_t n)
{
	double r, v;
	size_t i;

	r = v = 0;
	for (i = 0; i < n; i++) {
		v += a[i] * (i + 1);
		r += v;
	}
	return r;
}

void
test(double *a, size_t n, double r)
{
	double c;

	c = cost(a, n);
	printf("%f\n", c);
	assert(fabs(c - r) < 1e-3);
}

int
main(void)
{
	double a1[] = {20, 20, 20};
	double a2[] = {25, 10};
	double a3[] = {10, 25, 10, 75};
	double a4[] = {27.50, 25.00, 5.00, 70.00, 65.00, 25.00, 500.00, 4.25, 289.65, 318.26, 100.83, 100.13};

	test(a1, nelem(a1), 200);
	test(a2, nelem(a2), 70);
	test(a3, nelem(a3), 550);
	test(a4, nelem(a4), 51765.02);

	return 0;
}
