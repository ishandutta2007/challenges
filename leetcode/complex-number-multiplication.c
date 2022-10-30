/*

 Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition. 

Note:

    The input strings will not have extra blank.
    The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.

*/

#include <stdio.h>

typedef struct {
	int r, i;
} Complex;

Complex
cmplxmul(Complex a, Complex b)
{
	return (Complex){
	    a.r * b.r - a.i * b.i,
	    a.r * b.i + a.i * b.r,
	};
}

char *
cmplxstr(Complex c, char *b, size_t n)
{
	snprintf(b, n, "%d+%di", c.r, c.i);
	return b;
}

char *
cmplxmulstr(char *b, size_t n, const char *s, const char *t)
{
	Complex x, y, z;

	if (sscanf(s, "%d+%di", &x.r, &x.i) != 2)
		return NULL;
	if (sscanf(t, "%d+%di", &y.r, &y.i) != 2)
		return NULL;
	z = cmplxmul(x, y);
	return cmplxstr(z, b, n);
}

int
main(void)
{
	char s[80];
	printf("%s\n", cmplxmulstr(s, sizeof(s), "1+1i", "1+1i"));
	printf("%s\n", cmplxmulstr(s, sizeof(s), "1+-1i", "1+-1i"));
	printf("%s\n", cmplxmulstr(s, sizeof(s), "3+2i", "1+4i"));
	printf("%s\n", cmplxmulstr(s, sizeof(s), "3+2i", "1+7i"));
	printf("%s\n", cmplxmulstr(s, sizeof(s), "1+1i", "1+1i"));
	return 0;
}
