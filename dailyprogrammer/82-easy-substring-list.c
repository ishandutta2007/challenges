/*

Write a function that takes a number n as an argument and returns (or outputs) every possible unique substrings (not counting "") of the first n letters of the alphabet (in any order you like). For example, substrings(5) could be:

a
ab
abc
abcd
abcde
b
bc
bcd
bcde
c
cd
cde
d
de
e

BONUS 1: Find a way to quickly determine how many strings this function returns for a given input. If the alphabet were 500 letters long, how much possible substrings would it have?

BONUS 2: Modify your function to take a string as an argument. Make sure all substrings in your output are still unique (i.e., there are two "l" substrings in "hello", but you should output only one).

*/

#include <stdio.h>

void
alphabet(int i, int j)
{
	for (; i < j; i++)
		printf("%c", 'a' + (i % 26));
	printf("\n");
}

void
substrings(int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; i + j <= n; j++) {
			if (i != i + j)
				alphabet(i, i + j);
		}
	}
}

int
main(void)
{
	substrings(5);
	return 0;
}
