/*

Create a function that takes a whole number as input and returns the shape with that number's amount of sides. Here are the expected outputs to get from these inputs.

Inputs	Outputs
1	"circle"
2	"semi-circle"
3	"triangle"
4	"square"
5	"pentagon"
6	"hexagon"
7	"heptagon"
8	"octagon"
9	"nonagon"
10	"decagon"

Notes

    There won't be any tests with a number below 1 or greater than 10.
    Return the output in lowercase.
    The challenge is intended to be completed without conditionals (it would take too long)!

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
nsidedshape(int n)
{
	static const char *tab[] = {
	    "circle",
	    "semi-circle",
	    "triangle",
	    "square",
	    "pentagon",
	    "hexagon",
	    "heptagon",
	    "octagon",
	    "nonagon",
	    "decagon",
	};

	n--;
	if (0 <= n && n < (int)nelem(tab))
		return tab[n];
	return "";
}

int
main(void)
{
	int i;

	for (i = 1; i <= 10; i++)
		printf("%s\n", nsidedshape(i));
	return 0;
}
