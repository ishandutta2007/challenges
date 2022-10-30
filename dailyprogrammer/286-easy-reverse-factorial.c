/*

Description

Nearly everyone is familiar with the factorial operator in math. 5! yields 120 because factorial means "multiply successive terms where each are one less than the previous":

5! -> 5 * 4 * 3 * 2 * 1 -> 120

Simple enough.

Now let's reverse it. Could you write a function that tells us that "120" is "5!"?

Hint: The strategy is pretty straightforward, just divide the term by successively larger terms until you get to "1" as the resultant:

120 -> 120/2 -> 60/3 -> 20/4 -> 5/5 -> 1 => 5!

Sample Input

You'll be given a single integer, one per line. Examples:

120
150

Sample Output

Your program should report what each number is as a factorial, or "NONE" if it's not legitimately a factorial. Examples:

120 = 5!
150   NONE

Challenge Input

3628800
479001600
6
18

Challenge Output

3628800 = 10!
479001600 = 12!
6 = 3!
18  NONE

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
factinv(uvlong n)
{
	uvlong v;

	for (v = 0; n > 1;) {
		if (n % ++v)
			return 0;
		n /= v;
	}
	return v;
}

int
main(void)
{
	assert(factinv(120ull) == 5);
	assert(factinv(150ull) == 0);
	assert(factinv(3628800ull) == 10);
	assert(factinv(479001600ull) == 12);
	assert(factinv(6ull) == 3);
	assert(factinv(18ull) == 0);
	return 0;
}
