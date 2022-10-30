/*

Excel column names are in the following format:

A, B, ..., Z, AA, ..., AZ, BA, ..., ZZ, AAA, AAB, ...

Write a function that returns the column number from the row name.
Examples

column("A") ➞ 1

column("Z") ➞ 26

column("AA") ➞ 27

column("BA") ➞ 53

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

long
column(const char *s)
{
	size_t i;
	long v;
	int c;

	v = 0;
	for (i = 0; s[i]; i++) {
		v *= 26;
		c = tolower(s[i]);
		if ('1' <= c && c <= '9')
			v += c - '0';
		else if ('a' <= c && c <= 'z')
			v += c - 'a' + 1;
		else
			return -1;
	}
	return v;
}

int
main(void)
{
	assert(column("A") == 1);
	assert(column("B") == 2);
	assert(column("Z") == 26);
	assert(column("AA") == 27);
	assert(column("BA") == 53);
	assert(column("BB") == 54);
	assert(column("CW") == 101);
	assert(column("DD") == 108);
	assert(column("PQ") == 433);
	assert(column("ZZ") == 702);
	assert(column("ABC") == 731);
	assert(column("ZZT") == 18272);
	assert(column("STVW") == 348059);

	return 0;
}
