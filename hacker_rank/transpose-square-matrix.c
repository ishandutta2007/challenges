// transpose a square matrix
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void
transpose(double **m, size_t n)
{
	size_t i, j;
	double t;

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			t = m[j][i];
			m[j][i] = m[i][j];
			m[i][j] = t;
		}
	}
}

void
print(double **m, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%3.3f ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

double **
make(size_t n, ...)
{
	double **m, *p;
	size_t i, j;
	va_list ap;

	m = calloc(n, sizeof(*m));
	p = calloc(n * n, sizeof(*p));
	if (m == NULL || p == NULL) {
		free(m);
		free(p);
		return NULL;
	}

	for (i = 0; i < n; i++)
		m[i] = &p[i * n];

	va_start(ap, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			m[i][j] = va_arg(ap, double);
	}
	va_end(ap);

	return m;
}

void
destroy(double **m)
{
	if (m == NULL)
		return;

	free(m[0]);
	free(m);
}

void
test(double **m, size_t n)
{
	print(m, n);
	transpose(m, n);
	print(m, n);
	transpose(m, n);
	print(m, n);
	destroy(m);
}

int
main(void)
{
	double **m;

	m = make(1, 3.14);
	test(m, 1);

	m = make(2,
	         1.0, 0.0,
	         0.0, 1.0);
	test(m, 2);

	m = make(3,
	         1.0, 2.0, 3.0,
	         4.0, 5.0, 6.0,
	         7.0, 8.0, 9.0);
	test(m, 3);

	m = make(4,
	         1.0, 2.0, 3.0, 4.0,
	         5.0, 6.0, 7.0, 8.0,
	         9.0, 10.0, 11.0, 12.0,
	         13.0, 14.0, 15.0, 16.0);
	test(m, 4);

	return 0;
}
