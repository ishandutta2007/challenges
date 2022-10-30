/*

Create a function that takes a number as an argument and returns "even" for even numbers and "odd" for odd numbers.
Examples

isEvenOrOdd(3) ➞ "odd"

isEvenOrOdd(146) ➞ "even"

isEvenOrOdd(19) ➞ "odd"

Notes

    Dont forget to return the result.
    Input will always be a valid integer.
    Expect negative integers (whole numbers).
    Tests are case sensitive (return "even" or "odd" in lowercase).

*/

#include <assert.h>
#include <string.h>

const char *
evenorodd(int n)
{
	return (n & 1) ? "odd" : "even";
}

int
main(void)
{
	assert(!strcmp(evenorodd(3), "odd"));
	assert(!strcmp(evenorodd(0), "even"));
	assert(!strcmp(evenorodd(7), "odd"));
	assert(!strcmp(evenorodd(12), "even"));
	assert(!strcmp(evenorodd(6474), "even"));
	assert(!strcmp(evenorodd(563), "odd"));
	assert(!strcmp(evenorodd(3), "odd"));
	assert(!strcmp(evenorodd(1111100000), "even"));
	assert(!strcmp(evenorodd(301), "odd"));
	assert(!strcmp(evenorodd(-3), "odd"));
	assert(!strcmp(evenorodd(-0), "even"));
	assert(!strcmp(evenorodd(-7), "odd"));
	assert(!strcmp(evenorodd(-12), "even"));
	assert(!strcmp(evenorodd(-6474), "even"));
	assert(!strcmp(evenorodd(-563), "odd"));
	assert(!strcmp(evenorodd(-3), "odd"));
	assert(!strcmp(evenorodd(-1111100000), "even"));
	assert(!strcmp(evenorodd(-301), "odd"));

	return 0;
}
