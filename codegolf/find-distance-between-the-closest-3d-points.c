/*

Your task is to take n≥2 points in 3D space, represented as 3 floating point values, and output the Euclidean distance between the two closest points.
For example

A=(0,0,0)B=(1,1,1)C=(4,0,2)

would output 3–√=1.7320508075688772..., the distance between A and B.

The Euclidean distance, E, between any two points in 3D space X=(a1,b1,c1) and Y=(a2,b2,c2)

is given by the formula

E=sqrt((a2−a1)^2 + (b2−b1)^2 + (c2−c1)^2)

This is code-golf so the shortest code in bytes wins

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y, z;
} vec3;

double
distsq(vec3 p, vec3 q)
{
	double x, y, z;

	x = p.x - q.x;
	y = p.y - q.y;
	z = p.z - q.z;
	return x * x + y * y + z * z;
}

double
closest(vec3 *p, size_t n)
{
	double d, r;
	size_t i, j;

	r = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (j == i)
				continue;

			d = distsq(p[i], p[j]);
			if (d < r || r == 0)
				r = d;
		}
	}
	return sqrt(r);
}

void
test(vec3 *p, size_t n, double r)
{
	double d;

	d = closest(p, n);
	printf("%f\n", d);
	assert(fabs(d - r) < 1e-6);
}

int
main(void)
{
	vec3 p1[] = {
	    {0, 0, 0},
	    {1, 1, 1},
	    {4, 0, 2},
	};

	test(p1, nelem(p1), sqrt(3));

	return 0;
}
