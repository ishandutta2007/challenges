// https://www.cs.princeton.edu/courses/archive/fall10/cos126/assignments/stock.html

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

float *
load(const char *name, size_t *len)
{
	FILE *fp;
	float *v, p;
	long i, n;

	v = NULL;
	fp = fopen(name, "rb");
	if (!fp)
		goto error;

	fseek(fp, 0, SEEK_END);
	n = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	if (n < 0)
		goto error;

	v = calloc(n, sizeof(*v));
	if (!v)
		goto error;

	i = 0;
	while (fscanf(fp, "%f", &p) != EOF && i < n)
		v[i++] = p;
	*len = i;

	if (0) {
	error:
		free(v);
		v = NULL;
		*len = 0;
	}

	if (fp)
		fclose(fp);

	return v;
}

int
dilbert(float *p, size_t i, int *u, int *d)
{
	int r;

	r = 0;
	if (i == 0)
		return r;

	if (p[i] > p[i - 1]) {
		*u += 1;
		if (*d >= 3)
			r = 'b';
		*d = 0;
	} else if (p[i] < p[i - 1]) {
		*d += 1;
		if (*u >= 3)
			r = 's';
		*u = 0;
	} else
		*u = *d = 0;

	return r;
}

void
stats(float *p, size_t n)
{
	int c, u, d;
	int x, y;
	size_t i;

	c = u = d = 0;
	for (i = 0; i < n; i++) {
		c = dilbert(p, i, &u, &d);
		printf("%4zu %7.3f ", i + 1, p[i]);
		printf("%-4s ", (c == 'b') ? "buy" : (c == 's') ? "sell" : "");
		if (c)
			c = 0;

		for (x = 0, y = p[i]; x < y; x++)
			printf("*");
		printf("\n");
	}
	printf("\n\n");
}

void
invest(float *p, size_t n, double m)
{
	int c, u, d;
	double s;
	size_t i;

	printf("%-7s\t%-8s\t%-8s\t%-8s\t%-8s\n", "period", "price", "cash", "shares", "value");
	for (i = 0; i < 80; i++)
		printf("-");
	printf("\n");

	u = d = 0;
	s = 0;
	for (i = 0; i < n; i++) {
		c = dilbert(p, i, &u, &d);
		if (c == 'b' && m > 0) {
			s = m / p[i];
			m = 0;
		} else if (c == 's' && s > 0) {
			m = p[i] * s;
			s = 0;
		}

		printf("%6zu\t%8.3f\t%8.3f\t%8.3f\t%8.3f\n", i + 1, p[i], m, s, max(m, s * p[i]));
	}
}

void
test(const char *name)
{
	size_t n;
	float *p;

	printf("test: \"%s\"\n", name);
	p = load(name, &n);
	if (!p) {
		printf("failed to load file %s: %s\n", name, strerror(errno));
		return;
	}
	stats(p, n);
	invest(p, n, 10000);
	printf("\n------------\n");

	free(p);
}

int
main(void)
{
	test("stock15.txt");
	test("stock1000.txt");
	return 0;
}
