/*

In this challenge, you are going to take a number and turn it into a string, but not in the common way. You will use the aaaaa way!

The aaaaa way is simply replacing each digit of the input number with the letter at that position in the alphabet.
For example, 11111 would become aaaaa and 21223 would become babbc. If the number is less that 5 digits you need to left-pad it with an "A", for example 12 would be AAAab.

Rules
Your code can be a function or a complete program that outputs to STDOUT.
The returned string must be 5 letters.
It's obvious that the input would be a 1 to 5 digits number that has digits from 1 to 9.
You can get both input and output in number and strings or in array form like [1,2,1,3,1] and ['a','b','a','c','a'].
Test cases
In: 43213 -> Out: dcbac
In: 8645  -> Out: Ahfde
In: 342   -> Out: AAcdb
In: 99991 -> Out: iiiia
This is code-golf, so smallest program wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
aaaaa(int *a, size_t n, char *b)
{
	char *p;
	size_t i;

	p = b;
	for (i = n; i < 5; i++)
		*p++ = 'A';
	for (i = 0; i < n && i < 5; i++)
		*p++ = 'a' + (a[i] - 1);
	*p = '\0';

	return b;
}

void
test(int *a, size_t n, const char *r)
{
	char b[128];

	aaaaa(a, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	int a1[] = {4, 3, 2, 1, 3};
	int a2[] = {8, 6, 4, 5};
	int a3[] = {3, 4, 2};
	int a4[] = {9, 9, 9, 9, 1};

	test(a1, nelem(a1), "dcbac");
	test(a2, nelem(a2), "Ahfde");
	test(a3, nelem(a3), "AAcdb");
	test(a4, nelem(a4), "iiiia");

	return 0;
}
