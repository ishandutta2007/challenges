/*

(Easy): Repulsion-Force

Colomb's Law describes the repulsion force for two electrically charged particles. In very general terms, it describes the rate at which particles move away from each-other based on each particle's mass and distance from one another.

Your goal is to compute the repulsion force for two electrons in 2D space. Assume that the two particles have the same mass and charge. The function that computes force is as follows:

Force = (Particle 1's mass x Particle 2's mass) / Distance^2

Note that Colomb's Law uses a constant, but we choose to omit that for the sake of simplicity. For those not familiar with vector math, you can compute the distance between two points in 2D space using the following formula:

deltaX = (Particle 1's x-position - Particle 2's x-position)
deltaY = (Particle 1's y-position - Particle 2's y-position)
Distance = Square-root( deltaX * deltaX + deltaY * deltaY )

Author: nint22
Formal Inputs & Outputs
Input Description

On standard console input, you will be given two rows of numbers: first row represents the first particle, with the second row representing the second particle.
Each row will have three space-delimited real-numbers (floats), representing mass, x-position, and y-position. The mass will range, inclusively, from 0.001 to 100.0. The x and y positions will range inclusively from -100.0 to 100.0.
Output Description

Print the force as a float at a minimum three decimal places precision.
Sample Inputs & Outputs
Sample Input 1

1 -5.2 3.8
1 8.7 -4.1

Sample Output 1

0.0039

Sample Input 2

4 0.04 -0.02
4 -0.02 -0.03

Sample Output 2

4324.3279

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	double m;
	double x, y;
} Particle;

double
force(Particle *p, Particle *q)
{
	double d;

	d = hypot(p->x - q->x, p->y - q->y);
	if (d == 0)
		return 0;
	return (p->m * q->m) / (d * d);
}

void
test(Particle *p, Particle *q, double r)
{
	double f;

	f = force(p, q);
	printf("%f\n", f);
	assert(fabs(f - r) < 1e-2);
}

int
main(void)
{
	Particle p1 = {1, -5.2, 3.8};
	Particle q1 = {1, 8.7, -4.1};

	Particle p2 = {4, 0.04, -0.02};
	Particle q2 = {4, -0.02, -0.03};

	test(&p1, &q1, 0.0039);
	test(&p2, &q2, 4324.3279);

	return 0;
}
