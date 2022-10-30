/*

Challenge: I want to know about the real roots of polynomials. As a pure mathematician, I care about the existence of such roots, rather than their numeric values.

The challenge is to write the shortest program that takes a polynomial, of degree at most 4, and simply returns how many distinct real roots said polynomial has.
Polynomials with degree 4 or less have the unique property that there exist closed forms (such as the quadratic formula), which give all their roots.
You can google these forms or find some useful related information in the appendix.

Input: the coefficients of a polynomial. For simplicity, we shall only care about polynomials with integer coefficients.

You may input this as a list, get the coefficients one at a time, or use any other reasonable method. You may, for example, require polynomials of degree d to inputted as lists of length d+1.

You should specify how you convert a polynomial of degree at most 4 into a valid input.

Output: the number of distinct real roots of said polynomial. (meaning roots with multiplicity are only counted once)

You must output one of the integers 0,1,2,3,4 for valid polynomials, and trailing spaces are completely fine. (the special case of the polynomial, P(x)=0, is discussed in the scoring section)

Examples: in these examples, we represent a polynomial, P, as a list L, where L[i] contains the coefficient of xi in P. (with index starting at 0)

P(x)=1, input: [1], output: 0

P(x)=1+2x, input: [1,2],  output: 1

P(x)=1+x2, input: [1,0,1], output: 0

P(x)=1+x+x2+x3=(x+1)(1+x2), input: [1,1,1,1], output: 1

P(x)=2+3x+x2=(x+2)(x+1), input: [2,3,1], output: 2

P(x)=1−2x+x2=(x−1)2, input: [1,-2,1], output: 1

Scoring:

-5 bytes if the polynomial, P(x)=0, outputs a representation of infinity, such as: the infinity float in python, the Unicode symbol ∞, or a string that can be mathematically interpreted to evaluate to infinity, like "1/0". (otherwise, you don't need to handle this case)

Otherwise, shortest code wins. (however I am personally quite interested in seeing answers which don't rely on built-in root finders)

Appendix: Closed Forms

Starting with the basics:

Degree 0: P(x)=a, roots: none, (or all reals, if a = 0)

Degree 1: P(x)=ax+b, roots: x=−b/a

Degree 2: P(x)=ax^2+bx+c, roots: x=-b ± (b^2 - (4ac)) / sqrt(2a)

Then, we have the harder ones. For these, it becomes quite verbose to state the closed forms. I've paraphrased some ways you can deduce the number of roots by considering discriminants, you may also seek to find the closed forms of the roots.

Degree 3: From Wikipedia. P(x)=ax3+bx2+cx+d. We define the discriminant as Δ=18abcd−4b^3d+b^2d^2−4ac^3−27a^3d^2.

If Δ>0 then there are 3 distinct roots, if Δ=0, then there are two distinct real roots, otherwise then Δ<0 and there is only one real root.

Degree 4: From Wikipedia.P(x)=ax^4+bx^3+cx^2+dx+e. We define the discriminant as
Δ = 256a^3e^3 - 192a^2bde^2 - 128a^2c^2e^2 + 144a^2cd^2e - 27a^2d^4 + 144ab^2ce^2 - 6ab^2d^2e - 80abc^2de + 18abcd^3 + 16ac^4e - 4ac^3d^2 - 27b^4e^2 + 18b^3cde - 4b^3d^3 - 4b^2c^3e + b^2c^2d^2
P = 8ac - 3b^2
D = 64a^3e - 16a^2c^2 + 16ab^2c - 16a^2bd - 3b^4

If Δ>0 then all four roots are distinct or none of them are.
if P<0 and D<0 then there is four distinct real roots.
if P>0 and D>0 then there is two pairs of non-real complex conjugate roots.

Otherwise things get more complicated.
If Δ<0 and P<0 and D<0 then there are 4 distinct real roots. Otherwise, if Δ<0, there are 2 distinct real roots.

Finally, if Δ=0, we define Δ0 = c^2 - 3bd + 12ae and R = b^3 + 8da^2 - 4abc.

If D=0, then:

P<0 implies two distinct real roots
P>0 implies zero distinct real roots
P=0 implies four distinct real roots
Else, if Δ0=0, then there are two distinct real roots.

Else, if P<0 and D<0 there are three distinct real roots.

Else, there are one real root.

*/

#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

void
unpack(vlong *p, size_t n, ...)
{
	va_list ap;
	vlong *r;
	size_t i;

	va_start(ap, n);
	for (i = 0; i < n; i++) {
		r = va_arg(ap, vlong *);
		*r = p[i];
	}
	va_end(ap);
}

vlong
r0(vlong p[1])
{
	if (p[0] == 0)
		return LLONG_MAX;
	return 0;
}

vlong
r1(vlong p[2])
{
	if (p[0] == 0)
		return 0;
	return 1;
}

vlong
r2(vlong p[3])
{
	vlong a, b, c;
	vlong D;

	unpack(p, 3, &a, &b, &c);

	if (a == 0)
		return 0;

	D = ((b * b) - (4 * a * c));
	if (D < 0 || a == 0)
		return 0;
	if (D == 0)
		return 1;
	return 2;
}

vlong
r3(vlong p[4])
{
	vlong a, b, c, d;
	vlong D;

	unpack(p, 4, &a, &b, &c, &d);

	D = (18 * a * b * c * d);
	D -= (4 * b * b * b * d);
	D += (b * b * d * d);
	D -= (4 * a * c * c * c);
	D -= (27 * a * a * a * d * d);
	if (D > 0)
		return 3;
	if (D == 0)
		return 2;
	return 1;
}

vlong
r4(vlong p[5])
{
	vlong a, b, c, d, e;
	vlong a2, a3, b2, b3, b4, c2, c3, c4, d2, d3, d4, e2, e3;
	vlong D, D0, P, Q;

	unpack(p, 5, &a, &b, &c, &d, &e);

	a2 = a * a;
	a3 = a * a * a;
	b2 = b * b;
	b3 = b * b * b;
	b4 = b * b * b * b;
	c2 = c * c;
	c3 = c * c * c;
	c4 = c * c * c * c;
	d2 = d * d;
	d3 = d * d * d;
	d4 = d * d * d * d;
	e2 = e * e;
	e3 = e * e * e;

	D = (256 * a3 * e3);
	D -= (192 * a2 * b * d * e2);
	D -= (128 * a2 * c2 * e2);
	D += (144 * a2 * c * d2 * e);
	D -= (27 * a2 * d4);
	D += (144 * a * b2 * c * e2);
	D -= (6 * a * b2 * d2 * e);
	D -= (80 * a * b * c2 * d * e);
	D += (18 * a * b * c * d3);
	D += (16 * a * c4 * e);
	D -= (4 * a * c3 * d2);
	D -= (27 * b4 * e2);
	D += (18 * b3 * c * d * e);
	D -= (4 * b3 * d3);
	D -= (4 * b2 * c3 * e);
	D += (b2 * c2 * d2);

	P = (8 * a * c) - (3 * b2);
	Q = (64 * a3 * e) - (16 * a2 * c2) + (16 * a * b2 * c) - (16 * a2 * b * d) - (3 * b4);

	if (D > 0)
		return (P < 0 && Q < 0) ? 4 : 0;

	if (D < 0)
		return (P < 0 && Q < 0) ? 4 : 2;

	D0 = c2 - (3 * b * d) + (12 * a * e);
	if (Q == 0) {
		if (P < 0)
			return 2;
		if (P > 0)
			return 0;
		return 4;
	}
	if (D0 == 0)
		return 2;
	if (P < 0 && Q < 0)
		return 3;

	return 1;
}

vlong
roots(vlong *p, size_t n)
{
	switch (n) {
	case 1:
		return r0(p);
	case 2:
		return r1(p);
	case 3:
		return r2(p);
	case 4:
		return r3(p);
	case 5:
		return r4(p);
	}
	return -1;
}

int
main(void)
{
	vlong p1[] = {1};
	vlong p2[] = {1, 2};
	vlong p3[] = {1, 0, 1};
	vlong p4[] = {1, 1, 1, 1};
	vlong p5[] = {2, 3, 1};
	vlong p6[] = {1, -2, 1};
	vlong p7[] = {1, 1, 1, 1, 1};
	vlong p8[] = {4, -4, -3, 2, 1};
	vlong p9[] = {1, 2, -1, 2, 1};
	vlong p10[] = {204, 45, -12, 10, 6};
	vlong p11[] = {34, 0, 2, 5, 1};
	vlong p12[] = {34, 0, 2, 5, 100};

	assert(roots(p1, nelem(p1)) == 0);
	assert(roots(p2, nelem(p2)) == 1);
	assert(roots(p3, nelem(p3)) == 0);
	assert(roots(p4, nelem(p4)) == 1);
	assert(roots(p5, nelem(p5)) == 2);
	assert(roots(p6, nelem(p6)) == 1);
	assert(roots(p7, nelem(p7)) == 0);
	assert(roots(p8, nelem(p8)) == 2);
	assert(roots(p9, nelem(p9)) == 4);
	assert(roots(p10, nelem(p10)) == 0);
	assert(roots(p11, nelem(p11)) == 2);
	assert(roots(p12, nelem(p12)) == 0);

	return 0;
}
