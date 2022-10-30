/*

Create a function that takes a string consisting of lowercase letters, uppercase letters and numbers and
returns the string sorted in the same way as the examples below.

Examples

sorting("eA2a1E") ➞ "aAeE12"

sorting("Re4r") ➞ "erR4"

sorting("6jnM31Q") ➞ "jMnQ136"

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int
prec(int c)
{
	if (isalpha(c))
		return 0;
	if (isdigit(c))
		return 1;
	return 2;
}

int
cmp(const void *a, const void *b)
{
	int x, y, p, q;

	x = *(char *)a;
	y = *(char *)b;

	p = prec(x);
	q = prec(y);
	if (p < q)
		return -1;
	if (p > q)
		return 1;

	p = tolower(x);
	q = tolower(y);
	if (p < q)
		return -1;
	if (p > q)
		return 1;

	if (islower(x))
		return -1;
	if (islower(y))
		return 1;
	return 0;
}

void
test(char *s, const char *t)
{
	qsort(s, strlen(s), sizeof(*s), cmp);
	assert(strcmp(s, t) == 0);
}

int
main(void)
{
	char s1[] = "eA2a1E";
	char s2[] = "Re4r";
	char s3[] = "6jnM31Q";
	char s4[] = "f5Eex";
	char s5[] = "846ZIbo";
	char s6[] = "2lZduOg1jB8SPXf5rakC37wIE094Qvm6Tnyh";

	test(s1, "aAeE12");
	test(s2, "erR4");
	test(s3, "jMnQ136");
	test(s4, "eEfx5");
	test(s5, "bIoZ468");
	test(s6, "aBCdEfghIjklmnOPQrSTuvwXyZ0123456789");

	return 0;
}
