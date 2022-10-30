/*

Everybody loves geometry. So why don't we try and code golf it? This challenge involves taking in letters and numbers and making shapes depending on it.

The Input

The input will be in the form of (shapeIdentifier)(size)(inverter).

But what are shapeIdentifier, size, and inverter?

The shape identifier is the identifier for the type of shape you will be making with *s. The following are the shape identifiers:

    s - Square
    t - Triangle

The size will be between 1-20, and it is the size of the figure.

The inverter is whether or not the shape will be upside down, which is denoted by a + or a -. Do note: s3- == (equals) s3+ because squares are symmetric. However, t5- != (does not equal) t5+.

Trailing whitespace is okay in the output but leading whitespace is not.
Output Examples

Input: s3+
Output:
***
***
***

Input: t5+

Output:
  *
 ***
*****

Input: t3-
Output:
***
 *
 

Special Notes

The triangle input will always be an odd number, so the triangles will always end with 1 * at the top.

The size of the triangle is the size of the base if the inverter is + and is the size of the top if the inverter is -.

*/

#include <stdio.h>

int
square(unsigned n)
{
	unsigned i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}

int
triangle(unsigned n, int f)
{
	unsigned s, d, m;
	unsigned i, j;

	if (!(n & 1))
		return -1;

	m = (n - 1) / 2 + 1;
	for (i = 0; i < m; i++) {
		d = 2 * i + 1;
		if (f)
			d = 2 * (m - i) - 1;
		s = n - d;

		for (j = 0; j < s / 2; j++)
			printf(" ");
		for (j = 0; j < d; j++)
			printf("*");
		for (j = 0; j < s / 2; j++)
			printf(" ");
		printf("\n");
	}

	return 0;
}

void
shape(const char *s)
{
	unsigned n;
	char t, f;
	int r;

	printf("Input: %s\n", s);
	printf("Output:\n");
	if (sscanf(s, "%c%u%c", &t, &n, &f) != 3 || (f != '+' && f != '-'))
		goto error;

	r = -1;
	switch (t) {
	case 's':
		r = square(n);
		break;
	case 't':
		r = triangle(n, (f == '-'));
		break;
	}

	if (r < 0) {
	error:
		printf("Invalid Input\n");
	}

	printf("\n");
}

int
main(void)
{
	shape("s3+");
	shape("t5+");
	shape("t3-");
	shape("t11+");
	shape("t13-");
	shape("s20+");

	return 0;
}
