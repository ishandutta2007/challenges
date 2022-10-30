/*

You are an eccentric billionaire with an affinity for sending stuff to Mars.
In an ideal world you would send stuff to Mars all the time, but your engineers tell you that it is most efficient to do it when Earth and Mars are somewhat close to each other.

Your engineers have calculated that optimal launch windows occur once every 26 months, and that one of them occurs in April 2018.
They also tell you that they will not have any Big Finished Rockets by then, so you will have to wait for a later launch window.

Since your rocket scientists apparently can not be bothered to tell you about the optimal launch windows before it is too late, you have to keep track of that yourself.
Write a program that determines if there is an optimal launch window in any given year.

Input

The only line of input contains an integer y (2018≤y≤10000), the year you are interested in.

Output

Output “yes” if there is an optimal launch window in the year y, otherwise output “no”.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
optimal(unsigned y)
{
	unsigned p;

	p = ((y - 2017) * 12 - 4) % 26;
	return (p < 12) ? "yes" : "no";
}

void
test(unsigned y, const char *r)
{
	assert(!strcmp(optimal(y), r));
}

int
main(void)
{
	test(2018, "yes");
	test(2019, "no");
	test(2020, "yes");
	test(2028, "no");
	return 0;
}
