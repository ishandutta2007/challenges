/*

CodeDrawing one-liner
Teaser

Behold this formidable drawing:


Can you draw this in a single stroke? Give it a try.

Can you do this one, now:


Give it a try.

How it works

These "make this drawing with one pen stroke" problems are graph-theory problems with a rather simple solution.
For each vertex, compute its degree. If all vertices have an even degree or if only two vertices have an odd degree, this is possible.
In any other case, it is impossible. This is the same as finding an Eulerian path in the graph. This is also related to the very famous seven bridges of Königsberg puzzle.

For the first drawing, the degrees are

   2
 /   \
4-----4
|\   /|
|  4  |
|/   \|
3-----3

so we are in the second possible case, as all numbers are even except for the two 3s in the bottom. What is more, when we have odd numbers, we have to start in one of them and finish in the other.
When everything is even, we can start wherever we want but we will finish where we started.

For the second drawing it is impossible, as there are too many odd degrees:

     2
   /   \
  5-----5
 /|\   /|\
2 |  4  | 2
 \|/   \|/
  5-----5
   \   /
     2

Task

Given the degrees of the edges as input, decide if a corresponding drawing could be done in a single pen stroke. Output Truthy if such a feat is possible and output Falsy otherwise.

Input

The degrees of the vertices in any sensible format, such as

an array of integers like [2,4,4,4,3,3] or [2,5,5,2,4,2,5,5,2]
separate arguments to a function, like f(2,4,4,4,3,3) or f(2,5,5,2,4,2,5,5,2)

Output

A Truthy value if all numbers are even or exactly two of them are odd, Falsy otherwise.

Test cases

Truthy
[2, 4, 4, 3, 3]
[2, 2]
[1, 2, 3, 4, 6, 8]
[2, 4, 2, 4, 2, 4, 2, 4]
[8, 6, 8, 2, 2, 3, 11]
[1, 3]
[8]

Falsy
[1, 2, 3, 4, 5, 6]
[2, 3]
[9]
[7, 2, 2, 2]
[4, 2, 7]
[3, 3, 3, 3]
[1, 2, 3, 1, 1]
[1, 1, 4, 1, 1]
[7, 7, 7, 7, 7, 7, 7, 7]

This is code-golf so shortest submission in bytes, wins! If you liked this challenge, consider upvoting it... And happy golfing!

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
eulerian(unsigned *a, size_t n)
{
	size_t i, o;

	o = 0;
	for (i = 0; i < n && o < 3; i++)
		o += (a[i] & 1);

	if (o && o != 2)
		return false;
	return true;
}

int
main(void)
{
	unsigned a1[] = {2, 4, 4, 3, 3};
	unsigned a2[] = {2, 2};
	unsigned a3[] = {1, 2, 3, 4, 6, 8};
	unsigned a4[] = {2, 4, 2, 4, 2, 4, 2, 4};
	unsigned a5[] = {1, 3};
	unsigned a6[] = {8};

	unsigned a7[] = {2, 5, 5, 2, 4, 2, 5, 5, 2};
	unsigned a8[] = {1, 2, 3, 4, 5, 6};
	unsigned a9[] = {2, 3};
	unsigned a10[] = {9};
	unsigned a11[] = {7, 2, 2, 2};
	unsigned a12[] = {4, 2, 7};
	unsigned a13[] = {3, 3, 3, 3};
	unsigned a14[] = {1, 2, 3, 1, 1};
	unsigned a15[] = {1, 1, 4, 1, 1};
	unsigned a16[] = {7, 7, 7, 7, 7, 7, 7, 7};

	assert(eulerian(a1, nelem(a1)) == true);
	assert(eulerian(a2, nelem(a2)) == true);
	assert(eulerian(a3, nelem(a3)) == true);
	assert(eulerian(a4, nelem(a4)) == true);
	assert(eulerian(a5, nelem(a5)) == true);
	assert(eulerian(a6, nelem(a6)) == true);

	assert(eulerian(a7, nelem(a7)) == false);
	assert(eulerian(a8, nelem(a8)) == false);
	assert(eulerian(a9, nelem(a9)) == false);
	assert(eulerian(a10, nelem(a10)) == false);
	assert(eulerian(a11, nelem(a11)) == false);
	assert(eulerian(a12, nelem(a12)) == false);
	assert(eulerian(a13, nelem(a13)) == false);
	assert(eulerian(a14, nelem(a14)) == false);
	assert(eulerian(a15, nelem(a15)) == false);
	assert(eulerian(a16, nelem(a16)) == false);

	return 0;
}
