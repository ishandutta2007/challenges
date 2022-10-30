/*

Obviously this challenge would be trivial with separate functions and libraries, so they aren't allowed.

Your code must conform to an ECMAscript specification (any spec will do), so no browser-specific answers.

The array must be accessible after it is instantiated.

I have an answer that I'll withhold for now.

Note: this challenge is specific to javascript because it is notoriously inconvenient to make multi-dimensional arrays in javascript.

*/

#include <stdio.h>
#include <string.h>

void
gen(char m[10][10])
{
	memset(m, 1, 10 * 10);
}

void
dump(char m[10][10])
{
	int i, j;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
}

int
main(void)
{
	char m[10][10];

	gen(m);
	dump(m);

	return 0;
}
