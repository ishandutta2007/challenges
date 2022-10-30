/*

In golf, the standard scratch of a course is calculated using this formula:

(3*num_of_3_par_holes + 4*num_of_4_par_holes + 5*num_of_5_par_holes) - difficulty_rating

Your task is to calculate the standard scratch of a golf course, given these 4 inputs.

You should take input in any standard form in the format

[num_of_3_pars, num_of_4_pars, num_of_5_pars], difficulty rating

but if it saves bytes, you many take input in a different way.

You should output the final result by any accepted method on meta, such as returning from a function.

Shortest code wins because this is code-golf!

*/

#include <assert.h>

int
scratch(int p3, int p4, int p5, int dr)
{
	return (p3 * 3) + (p4 * 4) + (p5 * 5) - dr;
}

int
main(void)
{
	assert(scratch(1, 2, 3, 4) == 22);
	return 0;
}
