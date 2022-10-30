/*

Create a function to determine if the sum of all the individual even digits are greater than the sum of all the indiviudal odd digits in a string of numbers.

    If the sum of odd numbers is greater than the sum of even numbers, return "Odd is greater than Even".
    If the sum of even numbers is greater than the odd numbers, return "Even is greater than Odd".
    If the sum of both even and odd numbers are equal, return "Even and Odd are the same".

Examples

even_or_odd("22471") ➞ "Even and Odd are the same"

even_or_odd("213613") ➞ "Even and Odd are the same"

even_or_odd("23456") ➞ "Even is greater than Odd"

Notes

The input will be a string of numbers.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
evenorodd(const char *s)
{
	unsigned long v[2], n;
	size_t i;

	v[0] = v[1] = 0;
	for (i = 0; s[i]; i++) {
		if (!('0' <= s[i] && s[i] <= '9'))
			continue;

		n = s[i] - '0';
		v[n & 1] += n;
	}

	if (v[0] > v[1])
		return "Even is greater than Odd";
	if (v[1] > v[0])
		return "Odd is greater than Even";
	return "Even and Odd are the same";
}

void
test(const char *s, const char *r)
{
	assert(!strcmp(evenorodd(s), r));
}

int
main(void)
{
	test("12345", "Odd is greater than Even");
	test("143", "Even and Odd are the same");
	test("2221", "Even is greater than Odd");
	test("23456", "Even is greater than Odd");
	test("4321", "Even is greater than Odd");
	test("3245", "Odd is greater than Even");
	test("14256", "Even is greater than Odd");
	test("11234", "Even is greater than Odd");
	test("1734", "Odd is greater than Even");
	test("145", "Odd is greater than Even");
	test("22471", "Even and Odd are the same");
	test("213613", "Even and Odd are the same");
	test("23456", "Even is greater than Odd");
	test("9738", "Odd is greater than Even");
	test("34522", "Even and Odd are the same");
	test("12378", "Odd is greater than Even");
	test("45228", "Even is greater than Odd");
	test("4455", "Odd is greater than Even");
	test("6721", "Even and Odd are the same");
	test("92184", "Even is greater than Odd");
	test("12", "Even is greater than Odd");
	test("123", "Odd is greater than Even");
	test("112", "Even and Odd are the same");
	test("124", "Even is greater than Odd");

	return 0;
}
