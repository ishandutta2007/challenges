/*

Specs

    You have a cubic 3D space x,y,z of size S integer units, such as 0 <= x,y,z <= S.
    You get from default input methods an array of points P represented as x,y,z integer coordinates, in any reasonable format as you like, for example: [x1,y1,z1],[x2,y2,z2],[x3,y3,z3] ... [xn,yn,zn].
    All the P values will be in the above said cubic 3D space, such as 0 <= x,y,z <= S.
    The possible total number of P will be 1 <= P <= S3.
    You also get as input the x,y,z integer coordinates of the base point B and the 3D cube size S.

Task

Your goal is to output, in your preferred format, the points P sorted by the linear (Euclidean) distance from the base point B.

Rules

    If you find more than one point P that are equidistant from B you must output all of the equidistant P's in your preferred order.
    It is possible that a point P will coincide with B, so that their distance is 0, you must output that point.
    This is a code-golf challenge, so the shortest code wins.
    Standard loopholes are forbidden.
    Code explanations are appreciated.

Test cases

Input:
S (size), [B (base point x,y,z)], [P1 (x,y,z)], [P2], [P3], [P4], [P5], [...], [Pn]
10, [5,5,5], [0,0,0], [10,10,10], [2,0,8], [10,3,1], [4,4,5], [5,5,5], [5,5,4]

Output:
[5,5,5], [5,5,4], [4,4,5], [2,0,8], [10,3,1], [0,0,0], [10,10,10]

- - -

Input:
5, [2, 3, 3], [3, 0, 4], [5, 0, 3], [0, 2, 4], [0, 3, 5], [4, 2, 1], [2, 2, 2], [3, 1, 2], [3, 1, 0], [1, 3, 2], [2, 3, 1], [3, 1, 5], [4, 0, 0], [4, 3, 1], [0, 5, 5], [1, 5, 1], [3, 1, 4], [2, 2, 2], [0, 2, 5], [3, 3, 5], [3, 3, 0], [5, 4, 5], [4, 1, 3], [5, 1, 1], [3, 5, 3], [1, 5, 3], [0, 5, 2], [4, 3, 3], [2, 1, 1], [3, 3, 0], [5, 0, 4], [1, 5, 2], [4, 2, 3], [4, 2, 1], [2, 5, 5], [3, 4, 0], [3, 0, 2], [2, 3, 2], [3, 5, 1], [5, 1, 0], [2, 4, 3], [1, 0, 5], [0, 2, 5], [3, 4, 4], [2, 4, 0], [0, 1, 5], [0, 5, 4], [1, 5, 1], [2, 1, 0], [1, 3, 4], [2, 2, 2], [4, 2, 4], [5, 5, 4], [4, 4, 0], [0, 4, 1], [2, 0, 3], [3, 1, 5], [4, 4, 0], [2, 5, 1], [1, 2, 4], [4, 3, 1], [0, 2, 4], [4, 5, 2], [2, 0, 1], [0, 0, 2], [4, 1, 0], [5, 4, 3], [2, 5, 2], [5, 4, 4], [4, 4, 3], [5, 5, 1], [4, 0, 2], [1, 3, 5], [4, 2, 0], [0, 3, 1], [2, 2, 0], [0, 4, 5], [3, 2, 0], [0, 2, 1], [1, 2, 2], [2, 5, 3], [5, 5, 2], [5, 2, 4], [4, 5, 5], [2, 1, 2], [5, 4, 3], [4, 5, 4], [2, 3, 1], [4, 4, 4], [3, 0, 0], [2, 4, 5], [4, 3, 3], [3, 5, 3], [4, 0, 0], [1, 1, 1], [3, 1, 3], [2, 5, 5], [0, 0, 5], [2, 0, 2], [1, 0, 3], [3, 1, 4], [1, 2, 5], [4, 1, 3], [1, 4, 5], [3, 1, 4], [3, 5, 1], [5, 1, 4], [1, 0, 4], [2, 2, 0], [5, 2, 1], [0, 5, 3], [2, 1, 1], [0, 3, 0], [4, 5, 5], [3, 4, 2], [5, 3, 3], [3, 1, 1], [4, 0, 1], [5, 0, 5], [5, 0, 4], [1, 4, 3], [5, 4, 2], [5, 4, 0], [5, 1, 0], [0, 0, 1], [5, 3, 0]

Output:
[2, 4, 3], [2, 3, 2], [1, 3, 4], [1, 3, 2], [2, 2, 2], [1, 4, 3], [2, 2, 2], [2, 2, 2], [1, 2, 2], [3, 4, 2], [1, 2, 4], [3, 4, 4], [2, 5, 3], [4, 3, 3], [2, 3, 1], [4, 3, 3], [2, 3, 1], [1, 3, 5], [4, 4, 3], [2, 5, 2], [3, 1, 3], [1, 5, 3], [4, 2, 3], [2, 1, 2], [3, 5, 3], [2, 4, 5], [3, 3, 5], [3, 5, 3], [3, 1, 4], [0, 2, 4], [0, 2, 4], [1, 2, 5], [3, 1, 2], [3, 1, 4], [3, 1, 4], [4, 2, 4], [1, 4, 5], [4, 4, 4], [1, 5, 2], [4, 3, 1], [0, 5, 3], [2, 1, 1], [4, 1, 3], [4, 3, 1], [2, 5, 5], [0, 3, 5], [4, 1, 3], [2, 5, 1], [2, 1, 1], [0, 3, 1], [2, 5, 5], [1, 1, 1], [0, 4, 5], [4, 5, 4], [4, 5, 2], [0, 2, 1], [1, 5, 1], [5, 3, 3], [0, 5, 2], [3, 5, 1], [3, 5, 1], [0, 2, 5], [1, 5, 1], [4, 2, 1], [3, 1, 5], [3, 1, 1], [0, 2, 5], [4, 2, 1], [0, 5, 4], [0, 4, 1], [2, 0, 3], [3, 1, 5], [2, 4, 0], [2, 2, 0], [2, 0, 2], [3, 3, 0], [3, 3, 0], [5, 4, 3], [1, 0, 3], [5, 4, 3], [2, 2, 0], [3, 0, 2], [5, 4, 4], [5, 4, 2], [1, 0, 4], [3, 0, 4], [5, 2, 4], [3, 2, 0], [3, 4, 0], [0, 1, 5], [0, 5, 5], [4, 5, 5], [4, 5, 5], [0, 3, 0], [2, 0, 1], [2, 1, 0], [4, 4, 0], [5, 1, 4], [5, 5, 4], [5, 2, 1], [3, 1, 0], [5, 4, 5], [4, 4, 0], [1, 0, 5], [4, 2, 0], [0, 0, 2], [4, 0, 2], [5, 5, 2], [4, 1, 0], [5, 5, 1], [0, 0, 1], [5, 1, 1], [4, 0, 1], [0, 0, 5], [5, 0, 3], [5, 3, 0], [5, 4, 0], [3, 0, 0], [5, 0, 4], [5, 0, 4], [5, 1, 0], [4, 0, 0], [4, 0, 0], [5, 0, 5], [5, 1, 0]

- - -

Input:
10, [1, 9, 4], [4, 6, 2], [7, 5, 3], [10, 5, 2], [9, 8, 9], [10, 5, 10], [1, 5, 4], [8, 1, 1], [8, 6, 9], [10, 4, 1], [3, 4, 10], [4, 7, 0], [7, 10, 9], [5, 7, 3], [6, 7, 9], [5, 1, 4], [4, 3, 8], [4, 4, 9], [6, 9, 3], [8, 2, 6], [3, 5, 1], [0, 9, 0], [8, 4, 3], [0, 1, 1], [6, 7, 6], [4, 6, 10], [3, 9, 10], [8, 3, 1], [10, 1, 1], [9, 10, 6], [2, 3, 9], [10, 5, 0], [3, 2, 1], [10, 2, 7], [8, 4, 9], [5, 2, 4], [0, 8, 9], [10, 1, 6], [0, 8, 10], [5, 10, 1], [7, 4, 5], [4, 5, 2], [0, 2, 0], [8, 3, 3], [6, 6, 6], [3, 0, 2], [0, 1, 1], [10, 10, 8], [6, 2, 8], [8, 8, 6], [5, 4, 7], [10, 7, 4], [0, 9, 2], [1, 6, 6], [8, 5, 9], [3, 7, 4], [5, 6, 6], [3, 1, 1], [10, 4, 5], [1, 5, 7], [8, 6, 6], [4, 3, 7], [2, 1, 0], [6, 4, 2], [0, 7, 8], [8, 3, 6], [9, 2, 0], [1, 3, 8], [4, 4, 6], [5, 8, 9], [9, 4, 4], [0, 7, 3], [8, 3, 4], [6, 7, 9], [8, 7, 0], [0, 7, 7], [8, 10, 10], [10, 2, 5], [6, 9, 5], [6, 2, 7], [0, 9, 6], [1, 4, 1], [4, 3, 1], [5, 7, 3], [9, 6, 8], [4, 1, 7], [4, 0, 8], [3, 4, 7], [2, 3, 6], [0, 0, 7], [5, 3, 6], [7, 3, 4], [6, 7, 8], [3, 7, 9], [1, 9, 10], [2, 1, 2], [2, 8, 2], [0, 3, 0], [1, 1, 9], [3, 5, 2], [10, 5, 3], [5, 2, 9], [6, 9, 0], [9, 5, 0], [7, 1, 10], [3, 3, 8], [2, 5, 1], [3, 10, 10], [6, 2, 2], [10, 7, 2], [4, 3, 1], [4, 2, 1], [4, 2, 8], [6, 8, 5], [3, 10, 0], [1, 1, 7], [6, 9, 6], [6, 2, 4], [5, 5, 7], [5, 4, 5], [9, 8, 1], [9, 8, 1], [0, 10, 6], [1, 1, 9], [3, 8, 8], [3, 1, 5], [5, 7, 4], [4, 3, 6], [5, 4, 7], [6, 0, 8], [7, 8, 1], [9, 8, 4], [2, 10, 0], [3, 4, 5], [9, 3, 10], [7, 4, 1], [2, 1, 9], [10, 8, 1], [10, 3, 7], [2, 0, 6], [3, 8, 4], [10, 0, 2], [9, 9, 10], [8, 9, 5], [4, 10, 2], [8, 3, 4], [4, 2, 10], [9, 1, 6], [6, 1, 3], [4, 1, 3], [2, 9, 0], [5, 6, 5], [8, 8, 3], [5, 5, 0], [7, 6, 9], [1, 1, 5], [3, 0, 4], [1, 10, 6], [8, 0, 2], [0, 7, 3], [8, 9, 8], [2, 1, 8], [3, 1, 10], [4, 5, 9], [7, 6, 10], [3, 6, 10], [5, 9, 8], [9, 3, 3], [2, 2, 3], [9, 9, 0], [7, 2, 2], [0, 0, 9], [8, 7, 4], [9, 2, 9], [0, 6, 4], [9, 4, 3], [10, 1, 3], [5, 9, 10], [5, 10, 6], [6, 3, 10], 

Output: 
[1, 10, 6], [3, 8, 4], [0, 9, 6], [0, 9, 2], [2, 8, 2], [0, 7, 3], [0, 7, 3], [0, 10, 6], [3, 7, 4], [0, 6, 4], [1, 6, 6], [0, 7, 7], [4, 10, 2], [1, 5, 4], [0, 9, 0], [2, 9, 0], [2, 10, 0], [5, 7, 4], [5, 7, 3], [5, 10, 6], [5, 7, 3], [0, 7, 8], [3, 10, 0], [3, 8, 8], [4, 6, 2], [3, 5, 2], [1, 5, 7], [5, 10, 1], [6, 9, 3], [6, 9, 5], [5, 6, 5], [2, 5, 1], [0, 8, 9], [6, 8, 5], [5, 6, 6], [6, 9, 6], [4, 5, 2], [4, 7, 0], [3, 5, 1], [3, 4, 5], [5, 9, 8], [6, 7, 6], [3, 7, 9], [1, 4, 1], [1, 9, 10], [4, 4, 6], [0, 8, 10], [6, 6, 6], [3, 4, 7], [3, 9, 10], [5, 5, 7], [3, 10, 10], [2, 3, 6], [6, 9, 0], [5, 8, 9], [5, 4, 5], [6, 7, 8], [7, 8, 1], [5, 5, 0], [4, 3, 6], [3, 6, 10], [8, 9, 5], [5, 4, 7], [4, 5, 9], [5, 4, 7], [2, 2, 3], [8, 8, 3], [1, 3, 8], [5, 9, 10], [0, 3, 0], [7, 5, 3], [8, 7, 4], [4, 3, 1], [8, 8, 6], [6, 4, 2], [4, 3, 7], [6, 7, 9], [4, 6, 10], [4, 3, 1], [6, 7, 9], [3, 3, 8], [5, 3, 6], [4, 4, 9], [4, 3, 8], [8, 6, 6], [3, 2, 1], [7, 4, 5], [7, 10, 9], [2, 3, 9], [5, 2, 4], [1, 1, 5], [3, 4, 10], [8, 9, 8], [9, 8, 4], [0, 2, 0], [4, 2, 1], [3, 1, 5], [2, 1, 2], [8, 7, 0], [9, 10, 6], [7, 4, 1], [7, 6, 9], [7, 3, 4], [1, 1, 7], [0, 1, 1], [4, 2, 8], [9, 8, 1], [0, 1, 1], [4, 1, 3], [6, 2, 4], [9, 8, 1], [8, 4, 3], [3, 1, 1], [6, 2, 2], [5, 1, 4], [9, 9, 0], [7, 6, 10], [2, 1, 0], [2, 1, 8], [4, 1, 7], [8, 6, 9], [6, 2, 7], [8, 3, 4], [8, 3, 4], [10, 7, 4], [3, 0, 4], [8, 3, 3], [8, 10, 10], [2, 0, 6], [9, 6, 8], [10, 7, 2], [1, 1, 9], [8, 3, 6], [1, 1, 9], [7, 2, 2], [3, 0, 2], [9, 4, 4], [8, 5, 9], [2, 1, 9], [6, 1, 3], [6, 2, 8], [5, 2, 9], [9, 4, 3], [9, 8, 9], [0, 0, 7], [10, 8, 1], [4, 2, 10], [8, 3, 1], [9, 5, 0], [6, 3, 10], [10, 10, 8], [10, 5, 3], [8, 4, 9], [9, 9, 10], [10, 5, 2], [9, 3, 3], [8, 2, 6], [3, 1, 10], [4, 0, 8], [0, 0, 9], [10, 4, 5], [10, 5, 0], [10, 4, 1], [8, 1, 1], [6, 0, 8], [10, 3, 7], [9, 2, 0], [10, 2, 5], [9, 1, 6], [10, 5, 10], [8, 0, 2], [9, 3, 10], [7, 1, 10], [9, 2, 9], [10, 2, 7], [10, 1, 3], [10, 1, 6], [10, 1, 1], [10, 0, 2]

- - -

Input:
10000, [8452, 3160, 6109], [7172, 5052, 4795], [9789, 4033, 2952], [8242, 213, 3835], [177, 7083, 908], [3788, 3129, 3018], [9060, 464, 2701], [6537, 8698, 291], [9048, 3860, 6099], [4600, 2696, 4854], [2319, 3278, 9825]

Output:
[9048, 3860, 6099], [7172, 5052, 4795], [9789, 4033, 2952], [8242, 213, 3835], [4600, 2696, 4854], [9060, 464, 2701], [3788, 3129, 3018], [2319, 3278, 9825], [6537, 8698, 291], [177, 7083, 908]

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y, z;
} vec3;

int
distsq(vec3 a, vec3 b)
{
	int dx, dy, dz;

	dx = a.x - b.x;
	dy = a.y - b.y;
	dz = a.z - b.z;
	return dx * dx + dy * dy + dz * dz;
}

int
cmp(const void *a, const void *b, void *ud)
{
	vec3 x, y, p;
	int u, v;

	x = *(vec3 *)a;
	y = *(vec3 *)b;
	p = *(vec3 *)ud;

	u = distsq(p, x);
	v = distsq(p, y);
	if (u < v)
		return -1;
	if (u == v)
		return 0;
	return 1;
}

void
test(int s, vec3 p, vec3 *a, size_t n)
{
	size_t i;

	qsort_r(a, n, sizeof(*a), cmp, &p);
	for (i = 0; i < n; i++)
		printf("[%d,%d,%d] ", a[i].x, a[i].y, a[i].z);
	printf("\n\n");

	(void)s;
}

int
main(void)
{
	vec3 a1[] = {{0, 0, 0}, {10, 10, 10}, {2, 0, 8}, {10, 3, 1}, {4, 4, 5}, {5, 5, 5}, {5, 5, 4}};
	vec3 p1 = {5, 5, 5};

	vec3 a2[] = {
	    {3, 0, 4},
	    {5, 0, 3},
	    {0, 2, 4},
	    {0, 3, 5},
	    {4, 2, 1},
	    {2, 2, 2},
	    {3, 1, 2},
	    {3, 1, 0},
	    {1, 3, 2},
	    {2, 3, 1},
	    {3, 1, 5},
	    {4, 0, 0},
	    {4, 3, 1},
	    {0, 5, 5},
	    {1, 5, 1},
	    {3, 1, 4},
	    {2, 2, 2},
	    {0, 2, 5},
	    {3, 3, 5},
	    {3, 3, 0},
	    {5, 4, 5},
	    {4, 1, 3},
	    {5, 1, 1},
	    {3, 5, 3},
	    {1, 5, 3},
	    {0, 5, 2},
	    {4, 3, 3},
	    {2, 1, 1},
	    {3, 3, 0},
	    {5, 0, 4},
	    {1, 5, 2},
	    {4, 2, 3},
	    {4, 2, 1},
	    {2, 5, 5},
	    {3, 4, 0},
	    {3, 0, 2},
	    {2, 3, 2},
	    {3, 5, 1},
	    {5, 1, 0},
	    {2, 4, 3},
	    {1, 0, 5},
	    {0, 2, 5},
	    {3, 4, 4},
	    {2, 4, 0},
	    {0, 1, 5},
	    {0, 5, 4},
	    {1, 5, 1},
	    {2, 1, 0},
	    {1, 3, 4},
	    {2, 2, 2},
	    {4, 2, 4},
	    {5, 5, 4},
	    {4, 4, 0},
	    {0, 4, 1},
	    {2, 0, 3},
	    {3, 1, 5},
	    {4, 4, 0},
	    {2, 5, 1},
	    {1, 2, 4},
	    {4, 3, 1},
	    {0, 2, 4},
	    {4, 5, 2},
	    {2, 0, 1},
	    {0, 0, 2},
	    {4, 1, 0},
	    {5, 4, 3},
	    {2, 5, 2},
	    {5, 4, 4},
	    {4, 4, 3},
	    {5, 5, 1},
	    {4, 0, 2},
	    {1, 3, 5},
	    {4, 2, 0},
	    {0, 3, 1},
	    {2, 2, 0},
	    {0, 4, 5},
	    {3, 2, 0},
	    {0, 2, 1},
	    {1, 2, 2},
	    {2, 5, 3},
	    {5, 5, 2},
	    {5, 2, 4},
	    {4, 5, 5},
	    {2, 1, 2},
	    {5, 4, 3},
	    {4, 5, 4},
	    {2, 3, 1},
	    {4, 4, 4},
	    {3, 0, 0},
	    {2, 4, 5},
	    {4, 3, 3},
	    {3, 5, 3},
	    {4, 0, 0},
	    {1, 1, 1},
	    {3, 1, 3},
	    {2, 5, 5},
	    {0, 0, 5},
	    {2, 0, 2},
	    {1, 0, 3},
	    {3, 1, 4},
	    {1, 2, 5},
	    {4, 1, 3},
	    {1, 4, 5},
	    {3, 1, 4},
	    {3, 5, 1},
	    {5, 1, 4},
	    {1, 0, 4},
	    {2, 2, 0},
	    {5, 2, 1},
	    {0, 5, 3},
	    {2, 1, 1},
	    {0, 3, 0},
	    {4, 5, 5},
	    {3, 4, 2},
	    {5, 3, 3},
	    {3, 1, 1},
	    {4, 0, 1},
	    {5, 0, 5},
	    {5, 0, 4},
	    {1, 4, 3},
	    {5, 4, 2},
	    {5, 4, 0},
	    {5, 1, 0},
	    {0, 0, 1},
	    {5, 3, 0},
	};
	vec3 p2 = {2, 3, 3};

	vec3 a3[] = {
	    {4, 6, 2},
	    {7, 5, 3},
	    {10, 5, 2},
	    {9, 8, 9},
	    {10, 5, 10},
	    {1, 5, 4},
	    {8, 1, 1},
	    {8, 6, 9},
	    {10, 4, 1},
	    {3, 4, 10},
	    {4, 7, 0},
	    {7, 10, 9},
	    {5, 7, 3},
	    {6, 7, 9},
	    {5, 1, 4},
	    {4, 3, 8},
	    {4, 4, 9},
	    {6, 9, 3},
	    {8, 2, 6},
	    {3, 5, 1},
	    {0, 9, 0},
	    {8, 4, 3},
	    {0, 1, 1},
	    {6, 7, 6},
	    {4, 6, 10},
	    {3, 9, 10},
	    {8, 3, 1},
	    {10, 1, 1},
	    {9, 10, 6},
	    {2, 3, 9},
	    {10, 5, 0},
	    {3, 2, 1},
	    {10, 2, 7},
	    {8, 4, 9},
	    {5, 2, 4},
	    {0, 8, 9},
	    {10, 1, 6},
	    {0, 8, 10},
	    {5, 10, 1},
	    {7, 4, 5},
	    {4, 5, 2},
	    {0, 2, 0},
	    {8, 3, 3},
	    {6, 6, 6},
	    {3, 0, 2},
	    {0, 1, 1},
	    {10, 10, 8},
	    {6, 2, 8},
	    {8, 8, 6},
	    {5, 4, 7},
	    {10, 7, 4},
	    {0, 9, 2},
	    {1, 6, 6},
	    {8, 5, 9},
	    {3, 7, 4},
	    {5, 6, 6},
	    {3, 1, 1},
	    {10, 4, 5},
	    {1, 5, 7},
	    {8, 6, 6},
	    {4, 3, 7},
	    {2, 1, 0},
	    {6, 4, 2},
	    {0, 7, 8},
	    {8, 3, 6},
	    {9, 2, 0},
	    {1, 3, 8},
	    {4, 4, 6},
	    {5, 8, 9},
	    {9, 4, 4},
	    {0, 7, 3},
	    {8, 3, 4},
	    {6, 7, 9},
	    {8, 7, 0},
	    {0, 7, 7},
	    {8, 10, 10},
	    {10, 2, 5},
	    {6, 9, 5},
	    {6, 2, 7},
	    {0, 9, 6},
	    {1, 4, 1},
	    {4, 3, 1},
	    {5, 7, 3},
	    {9, 6, 8},
	    {4, 1, 7},
	    {4, 0, 8},
	    {3, 4, 7},
	    {2, 3, 6},
	    {0, 0, 7},
	    {5, 3, 6},
	    {7, 3, 4},
	    {6, 7, 8},
	    {3, 7, 9},
	    {1, 9, 10},
	    {2, 1, 2},
	    {2, 8, 2},
	    {0, 3, 0},
	    {1, 1, 9},
	    {3, 5, 2},
	    {10, 5, 3},
	    {5, 2, 9},
	    {6, 9, 0},
	    {9, 5, 0},
	    {7, 1, 10},
	    {3, 3, 8},
	    {2, 5, 1},
	    {3, 10, 10},
	    {6, 2, 2},
	    {10, 7, 2},
	    {4, 3, 1},
	    {4, 2, 1},
	    {4, 2, 8},
	    {6, 8, 5},
	    {3, 10, 0},
	    {1, 1, 7},
	    {6, 9, 6},
	    {6, 2, 4},
	    {5, 5, 7},
	    {5, 4, 5},
	    {9, 8, 1},
	    {9, 8, 1},
	    {0, 10, 6},
	    {1, 1, 9},
	    {3, 8, 8},
	    {3, 1, 5},
	    {5, 7, 4},
	    {4, 3, 6},
	    {5, 4, 7},
	    {6, 0, 8},
	    {7, 8, 1},
	    {9, 8, 4},
	    {2, 10, 0},
	    {3, 4, 5},
	    {9, 3, 10},
	    {7, 4, 1},
	    {2, 1, 9},
	    {10, 8, 1},
	    {10, 3, 7},
	    {2, 0, 6},
	    {3, 8, 4},
	    {10, 0, 2},
	    {9, 9, 10},
	    {8, 9, 5},
	    {4, 10, 2},
	    {8, 3, 4},
	    {4, 2, 10},
	    {9, 1, 6},
	    {6, 1, 3},
	    {4, 1, 3},
	    {2, 9, 0},
	    {5, 6, 5},
	    {8, 8, 3},
	    {5, 5, 0},
	    {7, 6, 9},
	    {1, 1, 5},
	    {3, 0, 4},
	    {1, 10, 6},
	    {8, 0, 2},
	    {0, 7, 3},
	    {8, 9, 8},
	    {2, 1, 8},
	    {3, 1, 10},
	    {4, 5, 9},
	    {7, 6, 10},
	    {3, 6, 10},
	    {5, 9, 8},
	    {9, 3, 3},
	    {2, 2, 3},
	    {9, 9, 0},
	    {7, 2, 2},
	    {0, 0, 9},
	    {8, 7, 4},
	    {9, 2, 9},
	    {0, 6, 4},
	    {9, 4, 3},
	    {10, 1, 3},
	    {5, 9, 10},
	    {5, 10, 6},
	    {6, 3, 10},
	};
	vec3 p3 = {1, 9, 4};

	vec3 a4[] = {
	    {7172, 5052, 4795},
	    {9789, 4033, 2952},
	    {8242, 213, 3835},
	    {177, 7083, 908},
	    {3788, 3129, 3018},
	    {9060, 464, 2701},
	    {6537, 8698, 291},
	    {9048, 3860, 6099},
	    {4600, 2696, 4854},
	    {2319, 3278, 9825},
	};
	vec3 p4 = {8452, 3160, 6109};

	test(10, p1, a1, nelem(a1));
	test(5, p2, a2, nelem(a2));
	test(10, p3, a3, nelem(a3));
	test(10000, p4, a4, nelem(a4));

	return 0;
}
