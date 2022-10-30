/*

Given a string, determine if it is an int, a float or neither.

Examples
123 - int
62727.0033 - float
644c.33 - neither
Your code should output a different value depending on which it is. For example it could return "i" for int, "f" for float and "n" for neither.

Details
The following are floats:

1.00 -0.0 1.0
The following are not floats:

 1e3 1.0ec3 -1e3 1e-3 1e+3 --1.0 +1.0 NaN 1.0.0 1. .1
The following are ints:

42 -2 -0
The following are not ints:

042 00
In short, the rule for floats is that it is a sequence of digits following by a . followed by a sequence of digits. Optionally - is prepended. If it starts with 0 then the . must follow directly afterwards.

The rule for ints is that it is a sequence of digits where the first digit is not 0. The only exception is that 0 and -0 are ints.

Either sort of number can have - optionally prepended to it.

You can assume the input will only contain printable-ASCII.

*/

#include <assert.h>
#include <string.h>
#include <ctype.h>

int
isint(const char *s)
{
	if (*s == '-')
		s++;

	if (!strcmp(s, "0"))
		return 1;

	if (*s == '0')
		return 0;

	while (isdigit(*s))
		s++;

	return *s == '\0';
}

int
isfloat(const char *s)
{
	const char *p;

	if (*s == '-')
		s++;

	p = s;
	while (isdigit(*s))
		s++;
	if (s == p || *s != '.')
		return 0;

	p = ++s;
	while (isdigit(*s))
		s++;

	return s != p && *s == '\0';
}

int
classify(const char *s)
{
	if (isint(s))
		return 'i';
	if (isfloat(s))
		return 'f';
	return 'n';
}

int
main(void)
{
	assert(classify("42") == 'i');
	assert(classify("-2") == 'i');
	assert(classify("-0") == 'i');

	assert(classify("1.00") == 'f');
	assert(classify("-0.0") == 'f');
	assert(classify("1.0") == 'f');

	assert(classify("1e3") == 'n');
	assert(classify("1.0ec3") == 'n');
	assert(classify("-1e3") == 'n');
	assert(classify("1e-3") == 'n');
	assert(classify("1e+3") == 'n');
	assert(classify("--1.0") == 'n');
	assert(classify("+1.0") == 'n');
	assert(classify("NaN") == 'n');
	assert(classify("1.0.0") == 'n');
	assert(classify("1.") == 'n');
	assert(classify(".1") == 'n');

	assert(classify("042") == 'n');
	assert(classify("00") == 'n');

	return 0;
}
