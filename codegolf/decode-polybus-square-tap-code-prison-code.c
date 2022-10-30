/*

The code has a lot of names, but is very simple:

  1 2 3 4 5
1 A B C D E
2 F G H I J
3 L M N O P
4 Q R S T U
5 V W X Y Z
A letter is coded by its coordinates, with the row first, then the column. Ex:

M = 3, 2
     V
   1 2 3 4 5
 1 A B C D E
 2 F G H I J
>3 L M N O P
 4 Q R S T U
 5 V W X Y Z
Note the letter 'K' is missing, as a letter needs to be removed to make the alphabet fit in the grid. In some versions, the letter 'J' is removed but K is easier to remove because every line stays in order.

More info here on Wikipedia.

Challenge: Make a program that takes in a message encoded in this way, that outputs the decoded message. Input can be in any reasonable format.

23 15 31 31 34 52 34 42 31 14
23153131345234423114
etc
Are all reasonable input formats. Standard loopholes apply.

Test Cases
23 15 31 31 34 52 34 42 31 14 => HELLOWORLD
24 25 31 32 => IJLM
11 22 33 44 55 => AGNTZ

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
polybusdec(unsigned *a, size_t n, char *b)
{
	static const char tab[5][5] = {
	    {'A', 'B', 'C', 'D', 'E'},
	    {'F', 'G', 'H', 'I', 'J'},
	    {'L', 'M', 'N', 'O', 'P'},
	    {'Q', 'R', 'S', 'T', 'U'},
	    {'V', 'W', 'X', 'Y', 'Z'},
	};

	unsigned x, y;
	size_t i, j;

	for (i = j = 0; i < n; i++) {
		x = (a[i] / 10) % 10;
		y = a[i] % 10;
		if (x < 1 || x > 5 || y < 1 || y > 5)
			b[j++] = ' ';
		else
			b[j++] = tab[x - 1][y - 1];
	}
	b[j] = '\0';

	return b;
}

void
test(unsigned *a, size_t n, const char *r)
{
	char b[128];

	polybusdec(a, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	unsigned a1[] = {23, 15, 31, 31, 34, 52, 34, 42, 31, 14};
	unsigned a2[] = {24, 25, 31, 32};
	unsigned a3[] = {11, 22, 33, 44, 55};

	test(a1, nelem(a1), "HELLOWORLD");
	test(a2, nelem(a2), "IJLM");
	test(a3, nelem(a3), "AGNTZ");

	return 0;
}
