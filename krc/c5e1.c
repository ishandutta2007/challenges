// As written, getint treats a + or - not followed by a digit as a valid representation of zero.
// Fix it to push such a character back on the input.

#include <stdio.h>
#include <ctype.h>

int
getint(FILE *fp, int *x)
{
	int c, d, sign;

	*x = 0;

	while (isspace(c = fgetc(fp)))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetc(c, fp);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		d = c;
		if (!isdigit(c = fgetc(fp))) {
			if (c != EOF)
				ungetc(c, fp);
			ungetc(d, fp);
			return d;
		}
	}

	for (*x = 0; isdigit(c); c = fgetc(fp))
		*x = 10 * *x + (c - '0');
	*x *= sign;
	if (c != EOF)
		ungetc(c, fp);

	return c;
}

int
main(void)
{
	int c, x;
	while ((c = getint(stdin, &x)) && c != EOF)
		printf("%d\n", x);

	return 0;
}
