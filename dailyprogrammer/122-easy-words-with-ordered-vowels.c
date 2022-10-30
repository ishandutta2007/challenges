/*

Find words in a word list that contain all the vowels in alphabetical order, non-repeated, where vowels are defined as A E I O U Y.

Author: ikea_riot

Formal Inputs & Outputs
Input Description
A text file with one word on each line.

Output Description
All words in the list that contains all the vowels A E I O U Y in alphabetical order.

Sample Inputs & Outputs
Sample Input
Use this word list

Sample Output
abstemiously ...

Challenge Input
Nothing special, see sample input

Challenge Input Solution
Nothing special, see sample output

Note
We are starting to fill the queue with new challenges! Please help out by posting suggestions to r/dailyprogrammer_ideas

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

int
ordered(const char *s)
{
	static const char vowels[] = "aeiouy";

	const char *p;
	int n, m;

	for (m = 0; *s; s++) {
		p = strchr(vowels, tolower(*s));
		if (p) {
			n = p - vowels + 1;
			if (n - m != 1)
				return 0;
			m = n;
		}
	}
	return m == 6;
}

int
words(const char *name)
{
	FILE *fp;
	char b[256];

	fp = fopen(name, "rb");
	if (!fp)
		return -errno;

	while (fgets(b, sizeof(b), fp)) {
		if (ordered(b))
			printf("%s", b);
	}

	fclose(fp);
	return 0;
}

int
main(void)
{
	words("enable1.txt");
	return 0;
}
