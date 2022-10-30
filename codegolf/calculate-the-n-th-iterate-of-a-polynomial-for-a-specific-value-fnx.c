/*

Given a polynomial function f (e.g. as a list p of real coefficients in ascending or descending order), a non-negative integer n, and a real value x, return:
   f n(x)

i.e. the value of f (f (f (…f (x)…))) for n applications of f on x.

Use reasonable precision and rounding.

Solutions that take f as a list of coefficients will probably be the most interesting, but if you are able to take f as an actual function (thereby reducing this challenge to the trivial "apply a function n times"),
feel free to include it after your non-trivial solution.

Example cases

p =[1,0,0] or f =x^2, n =0, x =3: f 0(3) =3

p =[1,0,0] or f =x^2, n =1, x =3: f 1(3) =9

p =[0.1,-2.3,-4] or f =0.1x^2-2.3x-4, n =0, x =2.3: f 0(2.3) =2.3

p =[0.1,-2.3,-4] or f =0.1x^2-2.3x-4, n =1, x =2.3: f 1(2.3) =-8.761

p =[0.1,-2.3,-4] or f =0.1x^2-2.3x-4, n =2, x =2.3: f 2(2.3) =23.8258

p =[0.1,-2.3,-4] or f =0.1x^2-2.3x-4, n =3, x =2.3: f 3(2.3) =-2.03244

p =[0.1,-2.3,-4] or f =0.1x^2-2.3x-4, n =4, x =2.3: f 4(2.3) =1.08768

p =[0.1,-2.3,-4] or f =0.1x^2-2.3x-4, n =5, x =2.3: f 5(2.3) =-6.38336

p =[0.1,-2.3,-4] or f =0.1x^2-2.3x-4, n =6, x =2.3: f 6(2.3) =14.7565

p =[0.1,-2.3,-4] or f =0.1x^2-2.3x-4, n =7, x =2.3: f 7(2.3) =-16.1645

p =[0.1,-2.3,-4] or f =0.1x^2-2.3x-4, n =8, x =2.3: f 8(2.3) =59.3077

p =[0.1,-2.3,-4] or f =0.1x^2-2.3x-4, n =9, x =2.3: f 9(2.3) =211.333

p =[0.1,-2.3,-4] or f =0.1x^2-2.3x-4, n =10, x =2.3: f 10(2.3) =3976.08

p =[0.1,-2.3,-4] or f =0.1x^2-2.3x-4, n =11, x =2.3: f 11(2.3) =1571775

p =[-0.1,2.3,4] or f =−0.1x^2+2.3x+4, n =0, x =-1.1: f 0(-1.1) =-1.1

p =[-0.1,2.3,4] or f =−0.1x^2+2.3x+4, n =1, x =-1.1: f 1(-1.1) =1.349

p =[-0.1,2.3,4] or f =−0.1x^2+2.3x+4, n =2, x =-1.1: f 2(-1.1) =6.92072

p =[-0.1,2.3,4] or f =−0.1x^2+2.3x+4, n =14, x =-1.1: f 14(-1.1) =15.6131

p =[0.02,0,0,0,-0.05] or f =0.02x^4-0.05, n =25, x =0.1: f 25(0.1) =-0.0499999

p =[0.02,0,-0.01,0,-0.05] or f =0.02x^4-0.01x^2-0.05, n =100, x =0.1: f 100(0.1) =-0.0500249

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
evalp(double *p, size_t n, double x)
{
	double r, y;
	size_t i;

	r = 0;
	y = 1;
	for (i = n; i > 0; i--) {
		r += y * p[i - 1];
		y *= x;
	}
	return r;
}

double
evalpn(double *p, size_t n, unsigned l, double x)
{
	size_t i;

	for (i = 0; i < l; i++)
		x = evalp(p, n, x);
	return x;
}

void
test(double *p, size_t n, unsigned l, double x)
{
	unsigned i;

	for (i = 0; i <= l; i++)
		printf("%u %f\n", i, evalpn(p, n, i, x));
	printf("\n");
}

int
main(void)
{
	double p1[] = {1, 0, 0};
	double p2[] = {0.1, -2.3, -4};
	double p3[] = {-0.1, 2.3, 4};
	double p4[] = {0.02, 0, -0.01, 0, -0.05};

	test(p1, nelem(p1), 1, 3);
	test(p2, nelem(p2), 11, 2.3);
	test(p3, nelem(p3), 14, -1.1);
	test(p4, nelem(p4), 100, 0.1);

	return 0;
}
