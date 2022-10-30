/*

For those with a little linear algebra background, the challenge is as simple as this: determine the eigenvalues and eigenvectors of a given complex 2x2 matrix.
You may skip ahead to The Challenge for I/O details, etc. For those who need a little refresher on eigensystems, read on.

Background

The characteristic equation of a matrix A

is defined by

det|A−λI|=0

where λ is a complex (scalar) parameter, I is the identity matrix and det|...| is the determinant. The left-hand side evaluates to a polynomial in λ, the characteristic polynomial, which is quadratic in the case of 2x2 matrices.
The solutions of this characteristic equation are the eigenvalues of A, which we will denote as λ1 and λ2.

Now the eigenvectors vi of A satisfy

Avi=λivi

For each λi, this gives you a system of two equations in two unknowns (the components of vi), which can be solved quite easily. You will notice that the system is actually underspecified, and the magnitude of the eigenvectors are not determined by the equations.
We will usually want the eigenvectors to be normalised, that is |x|2+|y|2−−−−−−−−√=1, where x and y are the vector components, |x|2 is x multiplied by its complex conjugate.

Note that the eigenvalues may be degenerate, i.e. λ1=λ2.
In this case, you may or may not be able to satisfy the single system of equations with two linearly independent eigenvectors.

The Challenge

Given a 2x2 matrix with complex elements, determine its two (possibly identical) eigenvalues and a normalised eigenvector for each eigenvalue.
The resulting numbers must be accurate to at least 3 (decimal) significant digits. You may assume that the real and imaginary parts of any matrix element is in the range [−1,1].

You may write a function or a program, taking input via STDIN, command-line argument, prompt or function argument. You may output the result to STDOUT, a dialog box or as the function return value.

You may use any convenient (but unambiguous) string or list format for input and output. You can also choose between pairs of floats or complex types to represent the individual numbers.

You must not use built-in functions for solving eigensystems (like Mathematica's Eigenvectors or Eigensystem) or equation solvers.

This is code golf, so the shortest answer (in bytes) wins.

Examples

Each example is three lines: the input, the eigenvalues and the corresponding eigenvectors in the same order. Note that the eigenvectors are only determined up to their phase, and that in the case of degenerate eigenvalues,
the eigenvectors may actually be arbitrary (as in the first example).

[[1.0, 0.0], [0.0, 1.0]]
[1.0, 1.0]
[[1.0, 0.0], [0.0, 1.0]]

[[0.0, 0.4], [-0.1, -0.4]]
[-0.2, -0.2]
[[0.894427, -0.447214], [0.894427, -0.447214]]

[[0.3, 0.1], [0.4, -0.9]]
[-0.932456, 0.332456]
[[-0.0808731, 0.996724], [0.951158, 0.308703]]

[[0.5, -1.0], [0.8, -0.5]]
[0.74162i, - 0.74162i]
[[0.745356, 0.372678 - 0.552771i], [0.745356, 0.372678 + 0.552771i]]

[[-0.0539222 + 0.654836i, -0.016102 + 0.221334i], [0.739514 - 0.17735i, -0.0849216 + 0.77977i]]
[0.238781 + 0.984333i, -0.377625 + 0.450273i]
[[0.313668 + 0.322289i, 0.893164], [-0.236405 - 0.442194i, 0.865204]]

[[-0.703107 - 0.331792i, 0.286719 - 0.587305i], [-0.418476 + 0.396347i, -0.885934 + 0.50534i]]
[-1.13654 - 0.32678i, -0.4525 + 0.500329i]
[[0.833367, -0.248208 - 0.493855i], [-0.441133 - 0.408236i, 0.799215]]

[[-0.156312 + 0.788441i, 0.045056 - 0.579167i], [0.130741 - 0.97017i, 0.049183 - 0.590768i]]
[-0.181759 + 1.11738i, 0.0746298 - 0.919707i]
[[0.86955, -0.493846 + 0.000213145i], [0.318856 - 0.0181135i, 0.94763]]

*/

#include <stdio.h>
#include <string.h>
#include <complex.h>
#include <math.h>

typedef double complex cmplx;
typedef cmplx mat2[2][2];

void
prints(cmplx v)
{
	printf("%f%+fi\n", creal(v), cimag(v));
}

void
printv(cmplx v[2])
{
	printf("%f%+fi %f%+fi\n", creal(v[0]), cimag(v[0]), creal(v[1]), cimag(v[1]));
}

void
printm(mat2 m)
{
	size_t i, j;

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++)
			printf("%f%+fi ", creal(m[i][j]), cimag(m[i][j]));
		printf("\n");
	}
}

int
quadratic(cmplx a, cmplx b, cmplx c, cmplx r[2])
{
	cmplx d;

	d = csqrt(b * b - 4 * a * c);
	r[0] = (-b + d) / (2 * a);
	r[1] = (-b - d) / (2 * a);
	return (d == 0) ? 1 : 2;
}

cmplx
trace(mat2 m)
{
	return m[0][0] + m[1][1];
}

cmplx
det(mat2 m)
{
	return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

void
eigv(mat2 m, cmplx ev, cmplx ew[2])
{
	cmplx a, b, t;

	a = m[0][0];
	b = m[0][1];
	if (b == 0) {
		a = m[1][0];
		b = m[1][1];
	}

	t = catan((ev - a) / b);
	ew[0] = ccos(t);
	ew[1] = csin(t);
}

// https://lpsa.swarthmore.edu/MtrxVibe/EigMat/MatrixEigen.html
// http://math.colgate.edu/~wweckesser/math312Spring06/handouts/IMM_2x2linalg.pdf
void
solve(mat2 m, cmplx ev[2], cmplx ew[2][2])
{
	quadratic(1, -trace(m), det(m), ev);
	eigv(m, ev[0], ew[0]);
	eigv(m, ev[1], ew[1]);
}

void
test(mat2 m)
{
	cmplx ev[2], ew[2][2];

	solve(m, ev, ew);
	printf("Matrix\n");
	printm(m);
	printf("Eigenvalues\n");
	prints(ev[0]);
	prints(ev[1]);
	printf("Eigenvectors\n");
	printv(ew[0]);
	printv(ew[1]);
	printf("\n");
}

int
main(void)
{
	mat2 m1 = {
	    {1, 0},
	    {0, 1},
	};
	mat2 m2 = {
	    {0.0, 0.4},
	    {-0.1, -0.4},
	};
	mat2 m3 = {
	    {0.3, 0.1},
	    {0.4, -0.9},
	};
	mat2 m4 = {
	    {0.5, -1.0},
	    {0.8, -0.5},
	};
	mat2 m5 = {
	    {-0.0539222 + 0.654836 * I, -0.016102 + 0.221334 * I},
	    {0.739514 - 0.17735 * I, -0.0849216 + 0.77977 * I},
	};
	mat2 m6 = {
	    {-0.703107 - 0.331792 * I, 0.286719 - 0.587305 * I},
	    {-0.418476 + 0.396347 * I, -0.885934 + 0.50534 * I},
	};
	mat2 m7 = {
	    {-0.156312 + 0.788441 * I, 0.045056 - 0.579167 * I},
	    {0.130741 - 0.97017 * I, 0.049183 - 0.590768 * I},
	};
	mat2 m8 = {
	    {0, 1},
	    {-2, -3},
	};
	mat2 m9 = {
	    {-1, -3},
	    {4, 3},
	};
	mat2 m10 = {
	    {1, 2},
	    {3, 4},
	};

	test(m1);
	test(m2);
	test(m3);
	test(m4);
	test(m5);
	test(m6);
	test(m7);
	test(m8);
	test(m9);
	test(m10);

	return 0;
}
