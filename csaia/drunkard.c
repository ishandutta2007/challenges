/*

A drunkard's walk. A drunkard begins walking aimlessly, starting at a lamp post. At each time step, the drunkard forgets where he or she is, and takes one step at random, either north, east, south, or west, with probability 25%. How far will the drunkard be from the lamp post after N steps?

    Write a program RandomWalker.java that takes an integer command-line argument N and simulates the motion of a random walker for N steps. After each step, print the location of the random walker, treating the lamp post as the origin (0, 0). Also, print the square of the final distance from the origin.

        % java RandomWalker 10             % java RandomWalker 20
        (0, -1)                           (0, 1)
        (0, 0)                            (-1, 1)
        (0, 1)                            (-1, 2)
        (0, 2)                            (0, 2)
        (-1, 2)                           (1, 2)
        (-2, 2)                           (1, 3)
        (-2, 1)                           (0, 3)
        (-1, 1)                           (-1, 3)
        (-2, 1)                           (-2, 3)
        (-3, 1)                           (-3, 3)
        squared distance = 10             (-3, 2)
                                          (-4, 2)
                                          (-4, 1)
                                          (-3, 1)
                                          (-3, 0)
                                          (-4, 0)
                                          (-4, -1)
                                          (-3, -1)
                                          (-3, -2)
                                          (-3, -3)
                                          squared distance = 18

    Write a program RandomWalkers.java that takes two integer command-line arguments N and T. In each of T independent experiments, simulate a random walk of N steps and compute the squared distance. Output the mean squared distance (the average of the T squared distances).

        % java RandomWalkers 100 100000         % java RandomWalkers 400 100000
        mean squared distance = 100.15086       mean squared distance = 401.22024

        % java RandomWalkers 100 100000         % java RandomWalkers 800 100000
        mean squared distance = 99.95274        mean squared distance = 797.5106

        % java RandomWalkers 200 100000         % java RandomWalkers 1600 100000
        mean squared distance = 199.57664       mean squared distance = 1600.13064

    As N increases, we expect the random walker to end up further and further away from the origin. But how much further? Use RandomWalkers to formulate a hypothesis as to how the mean squared distance grows as a function of N. Use T = 100,000 trials to get a sufficiently accurate estimate.

Remark: this process is a discrete version of a natural phenomenon known as Brownian motion. It serves as a scientific model for an astonishing range of physical processes from the dispersion of ink flowing in water, to the formation of polymer chains in chemistry, to cascades of neurons firing in the brain.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int x, y;
} Point;

int
walk(int n, int pr)
{
	Point p;
	int i, d;

	p.x = p.y = 0;
	for (i = 0; i < n; i++) {
		switch (rand() & 3) {
		case 0:
			p.y++;
			break;
		case 1:
			p.x++;
			break;
		case 2:
			p.y--;
			break;
		case 3:
			p.x--;
			break;
		}
		if (pr)
			printf("(%d, %d)\n", p.x, p.y);
	}

	d = p.x * p.x + p.y * p.y;
	if (pr)
		printf("squared distance: %d\n\n", d);
	return d;
}

void
trial(int N, int T)
{
	double d;
	int i;

	for (i = 0; i < T; i++)
		d += walk(N, 0);
	d /= T;
	printf("mean squared distance: %f\n", d);
}

int
main(int argc, char *argv[])
{
	int N, T;

	srand(time(NULL));

	walk(10, 1);
	walk(20, 1);

	if (argc == 3) {
		N = atoi(argv[1]);
		T = atoi(argv[2]);
		trial(N, T);
	}
	return 0;
}
