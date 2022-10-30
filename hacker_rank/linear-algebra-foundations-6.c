/*
Given the following matrix A:

            [1   1   0 ]
      A =   [0   1   0 ]
            [0   0   1 ]

Calculate the real numbers x and y such that:

A^2 + xA+ Iy = 0 (I is the 3 x 3 identity matrix)
*/
#include <stdio.h>
#include <string.h>

int
equal(int m[3][3], int n[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (m[i][j] != n[i][j])
				return 0;
		}
	}
	return 1;
}

void
zero(int m[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			m[i][j] = 0;
	}
}

void
id(int m[3][3])
{
	int i;
	zero(m);
	for (i = 0; i < 3; i++)
		m[i][i] = 1;
}

void
copy(int m[3][3], int n[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			m[i][j] = n[i][j];
	}
}

void
add(int m[3][3], int a[3][3], int b[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			m[i][j] = a[i][j] + b[i][j];
	}
}

void
mul(int m[3][3], int a[3][3], int b[3][3])
{
	int t[3][3];
	int i, j, k;
	zero(t);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++)
				t[i][j] += a[i][k] * b[k][j];
		}
	}
	copy(m, t);
}

void
mexp(int m[3][3], int n)
{
	int p[3][3], i;
	copy(p, m);
	for (i = 1; i < n; i++)
		mul(p, p, m);
	copy(m, p);
}

void
scale(int m[3][3], int s)
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			m[i][j] *= s;
	}
}

void
print(int m[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%d\n", m[i][j]);
	}
}

void
solve(int a[3][3])
{
	const int N = 100;
	int x, y;
	int l[3][3], r[3][3], t[3][3][3];
	zero(r);
	for (x = -N; x <= N; x++) {
		for (y = -N; y <= N; y++) {
			copy(t[0], a);
			mexp(t[0], 2);
			copy(t[1], a);
			scale(t[1], x);
			id(t[2]);
			scale(t[2], y);
			add(l, t[0], t[1]);
			add(l, l, t[2]);
			if (equal(l, r)) {
				printf("(%d, %d)\n", x, y);
				return;
			}
		}
	}
	printf("no solution found in radius [%d, %d]\n", -N, N);
}

int
main(void)
{
	int a[3][3] = {
	    {1, 1, 0},
	    {0, 1, 0},
	    {0, 0, 1},
	};
	solve(a);
	return 0;
}
