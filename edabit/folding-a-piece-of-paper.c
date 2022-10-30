/*

Create a function that returns the thickness (in meters) of a piece of paper after folding it n number of times. The paper starts off with a thickness of 0.5mm.
Examples

numLayers(1) ➞ "0.001m"
// Paper folded once is 1mm (equal to 0.001m)

numLayers(4) ➞ "0.008m"
// Paper folded 4 times is 8mm (equal to 0.008m)

numLayers(21) ➞ "1048.576m"
// Paper folded 21 times is 1048576mm (equal to 1048.576m)

Notes

    There are 1000mm in a single meter.
    Don't round answers.

*/

#include <stdio.h>

double
numlayers(unsigned n)
{
	return 0.0005 * (1ull << n);
}

int
main(void)
{
	unsigned i;

	for (i = 1; i <= 60; i++)
		printf("%u %lf\n", i, numlayers(i));

	return 0;
}
