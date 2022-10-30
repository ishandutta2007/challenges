/*
You are provided a matrix A =

       [-2     -9 ]                  
       [ 1      4 ]          

The 1000th power of A, i.e. A^1000 =

        [A  B]
        [C  D]
*/
#include <stdio.h>
#include <string.h>

void
zero(int m[2][2])
{
	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++)
			m[i][j] = 0;
	}
}

void
copy(int p[2][2], int m[2][2])
{
	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++)
			p[i][j] = m[i][j];
	}
}

void
mul(int c[2][2], int a[2][2], int b[2][2])
{
	int i, j, k, t[2][2];
	zero(t);
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++)
				t[i][j] += a[i][k] * b[k][j];
		}
	}
	copy(c, t);
}

void
mexp(int m[2][2], int n)
{
	int p[2][2], i;
	copy(p, m);
	for (i = 1; i < n; i++)
		mul(p, p, m);
	copy(m, p);
}

void
print(int m[2][2])
{
	int i, j;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++)
			printf("%d\n", m[i][j]);
	}
}

int
main(void)
{
	int a[2][2] = {
	    {-2, -9},
	    {1, 4},
	};
	mexp(a, 1000);
	print(a);
	return 0;
}
