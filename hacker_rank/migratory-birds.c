/*

You have been asked to help study the population of birds migrating across the continent.
Each type of bird you are interested in will be identified by an integer value.
Each time a particular kind of bird is spotted, its id number will be added to your array of sightings.
You would like to be able to find out which type of bird is most common given a list of sightings.
Your task is to print the type number of that bird and if two or more types of birds are equally common, choose the type with the smallest ID number.

For example, assume your bird sightings are of types [1 1 2 2 3]. 
There are two each of types 1 and 2, and one sighting of type 3.
Pick the lower of the two types seen twice: type 1.

*/
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
sightings(int *a, size_t n)
{
	size_t i, m, c;
	int v, t;

	qsort(a, n, sizeof(*a), cmp);

	m = 0;
	t = -1;
	for (i = 0; i < n;) {
		v = a[i];
		c = 1;
		while (a[++i] == v)
			c++;
		if (m < c) {
			m = c;
			t = v;
		}
	}

	return t;
}

int
main(void)
{
	int a[] = {1, 1, 2, 3, 3};
	printf("%d\n", sightings(a, nelem(a)));

	int b[] = {1, 4, 4, 4, 5, 3};
	printf("%d\n", sightings(b, nelem(b)));

	int c[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 3, 4};
	printf("%d\n", sightings(c, nelem(c)));

	return 0;
}
