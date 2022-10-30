/*

Background

Quaternion is a number system that extends complex numbers. A quaternion has the following form

a+bi+cj+dk

where a,b,c,d
are real numbers and i,j,k

are three fundamental quaternion units. The units have the following properties:

i2=j2=k2=−1
ij=k,jk=i,ki=j
ji=−k,kj=−i,ik=−j

Note that quaternion multiplication is not commutative.
Task

Given a non-real quaternion, compute at least one of its square roots.
How?

According to this Math.SE answer, we can express any non-real quaternion in the following form:

q=a+bu⃗ 

where a,b are real numbers and u⃗  is the imaginary unit vector in the form xi+yj+zk with x2+y2+z2=1. Any such u⃗  has the property u⃗ 2=−1, so it can be viewed as the imaginary unit.

Then the square of q

looks like this:

q2=(a2−b2)+2abu⃗ 

Inversely, given a quaternion q′=x+yu⃗, we can find the square root of q′

by solving the following equations

x=a2−b2,y=2ab

which is identical to the process of finding the square root of a complex number.

Note that a negative real number has infinitely many quaternion square roots, but a non-real quaternion has only two square roots.
Input and output

Input is a non-real quaternion. You can take it as four real (floating-point) numbers, in any order and structure of your choice. Non-real means that at least one of b,c,d

is non-zero.

Output is one or two quaternions which, when squared, are equal to the input.
Test cases

   Input (a, b, c, d)  =>  Output (a, b, c, d) rounded to 6 digits

 0.0,  1.0,  0.0,  0.0 =>  0.707107,  0.707107,  0.000000,  0.000000
 1.0,  1.0,  0.0,  0.0 =>  1.098684,  0.455090,  0.000000,  0.000000
 1.0, -1.0,  1.0,  0.0 =>  1.168771, -0.427800,  0.427800,  0.000000
 2.0,  0.0, -2.0, -1.0 =>  1.581139,  0.000000, -0.632456, -0.316228
 1.0,  1.0,  1.0,  1.0 =>  1.224745,  0.408248,  0.408248,  0.408248
 0.1,  0.2,  0.3,  0.4 =>  0.569088,  0.175720,  0.263580,  0.351439
99.0,  0.0,  0.0,  0.1 =>  9.949876,  0.000000,  0.000000,  0.005025

Generated using this Python script. Only one of the two correct answers is specified for each test case; the other is all four values negated.
Scoring & winning criterion

Standard code-golf rules apply. The shortest program or function in bytes in each language wins.

*/

#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y, z, w;
} quat;

double
qnorm(quat a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

quat
qmul(quat a, quat b)
{
	return (quat){
	    .x = a.x * b.w + a.w * b.x + a.y * b.z - a.z * b.y,
	    .y = a.y * b.w + a.w * b.y + a.z * b.x - a.x * b.z,
	    .z = a.z * b.w + a.w * b.z + a.x * b.y - a.y * b.x,
	    .w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
	};
}

/*

https://www.johndcook.com/blog/2021/01/06/quaternion-square-roots/

x^2 = y has
one solution if y = 0
infinitely many solutions if y is negative and real (all points on the sphere)
two solutions x = ±√r (cos θ/2 + u sin θ/2)

this function return the positive root

*/

quat
qsqrt(quat a)
{
	double r, t;
	double l, z;
	double s, c;
	quat u;

	u = (quat){a.x, a.y, a.z, 0};
	l = qnorm(u);
	if (l == 0)
		return (quat){0};

	r = qnorm(a);
	t = acos(a.w / r);
	z = sqrt(r);

	s = sin(t / 2);
	c = cos(t / 2);

	return (quat){
	    z * s * u.x / l,
	    z * s * u.y / l,
	    z * s * u.z / l,
	    z * c,
	};
}

char *
qstr(quat a, char *b)
{
	sprintf(b, "(%.6f %.6f %.6f %.6f)", a.w, a.x, a.y, a.z);
	return b;
}

void
test(double w, double x, double y, double z)
{
	char b[3][128];
	quat q, r, p;

	q = (quat){x, y, z, w};
	r = qsqrt(q);
	p = qmul(r, r);
	printf("%s | %s | %s\n", qstr(q, b[0]), qstr(r, b[1]), qstr(p, b[2]));
}

int
main(void)
{
	test(0, 1, 0, 0);
	test(1, 1, 0, 0);
	test(1, -1, 1, 0);
	test(2, 0, -2, -1);
	test(1, 1, 1, 1);
	test(0.1, 0.2, 0.3, 0.4);
	test(99, 0, 0, 0.1);
	test(0, 0, 0, 0);
	test(4, 1, 2, 3);

	return 0;
}
