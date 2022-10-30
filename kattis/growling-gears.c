/*

The Best Acceleration Production Company specializes in multi-gear engines.
The performance of an engine in a certain gear, measured in the amount of torque produced, is not constant: the amount of torque depends on the RPM of the engine.
This relationship can be described using a torque-RPM curve.

\includegraphics[width=0.5\textwidth ]{torque-rpm-graph}

Figure 1: The torque-RPM curve of the gears given in the second sample input. The second gear can produce the highest torque.

For the latest line of engines, the torque-RPM curve of all gears in the engine is a parabola of the form T=−aR2+bR+c, where R is the RPM of the engine, and T is the resulting torque.

Given the parabolas describing all gears in an engine, determine the gear in which the highest torque is produced.
The first gear is gear 1, the second gear is gear 2, etc.
There will be only one gear that produces the highest torque: all test cases are such that the maximum torque is at least 1 higher than the maximum torque in all the other gears.

Input

On the first line one positive number: the number of test cases, at most 100. After that per test case:

    one line with a single integer n (1≤n≤10): the number of gears in the engine.
        n lines, each with three space-separated integers a, b and c (1≤a,b,c≤10000): the parameters of the parabola T=−aR2+bR+c describing the torque-RPM curve of each engine.

Output

Per test case:

    one line with a single integer: the gear in which the maximum torque is generated.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
gear(int p[][3], size_t n)
{
	double a, b, c;
	double m, v, x;
	size_t i, l;

	m = -INFINITY;
	l = 0;
	for (i = 0; i < n; i++) {
		a = p[i][0];
		b = p[i][1];
		c = p[i][2];

		x = b / (2 * a);
		v = -a * x * x + b * x + c;
		if (v > m) {
			m = v;
			l = i + 1;
		}
	}
	return l;
}

int
main(void)
{
	int p1[][3] = {
	    {1, 4, 2},
	};
	int p2[][3] = {
	    {3, 126, 1400},
	    {2, 152, 208},
	};
	int p3[][3] = {
	    {3, 127, 1400},
	    {2, 154, 208},
	};

	assert(gear(p1, nelem(p1)) == 1);
	assert(gear(p2, nelem(p2)) == 2);
	assert(gear(p3, nelem(p3)) == 2);

	return 0;
}
