// Write getfloat, the floating-point analog of getint
// What type does getfloat return as its function value?

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
getfloat(FILE *fp, float *x)
{
	int c, s;
	float p;

	*x = 0;
	do {
		c = getc(fp);
	} while (isspace(c));

	if (!isdigit(c) && c != EOF && !strchr("+-.", c)) {
		ungetc(c, fp);
		return 0;
	}

	s = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = fgetc(fp);

	// integer part
	for (*x = 0.0f; isdigit(c); c = getc(fp))
		*x = 10.0f * *x + (c - '0');

	// fractional part
	if (c == '.')
		c = getc(fp);
	for (p = 1.0f; isdigit(c); c = getc(fp)) {
		*x = 10.0f * *x + (c - '0');
		p *= 10.0f;
	}

	*x *= s / p;
	if (c != EOF)
		ungetc(c, fp);

	return c;
}

int
main(void)
{
	float x;
	getfloat(stdin, &x);
	printf("%f\n", x);
	return 0;
}
