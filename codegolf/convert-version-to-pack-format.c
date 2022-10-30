/*

When making a Minecraft data/resource pack, you need to include a pack.mcmeta file, which specifies information about it. pack.mcmeta contains a description, but it also contains a pack_format number, which tells Minecraft which versions this pack is for.

Your task is to take a version string, and output what pack_format number matches the string.

Your input must be a string, and you can assume it's either 1.x or 1.x.y.

As of when this challenge was posted, the conversion goes like so:

1.6.1 - 1.8.9 -> 1
1.9 - 1.10.2 -> 2
1.11 - 1.12.2 -> 3
1.13 - 1.14.4 -> 4
1.15 - 1.16.1 -> 5
1.16.2 - 1.16.5 -> 6
1.17 -> 7

These are all the possible inputs, and what they need to be mapped to:

1.6.1 -> 1
1.6.2 -> 1
1.6.4 -> 1
1.7.2 -> 1
1.7.4 -> 1
1.7.5 -> 1
1.7.6 -> 1
1.7.7 -> 1
1.7.8 -> 1
1.7.9 -> 1
1.7.10 -> 1
1.8 -> 1
1.8.1 -> 1
1.8.2 -> 1
1.8.3 -> 1
1.8.4 -> 1
1.8.5 -> 1
1.8.6 -> 1
1.8.7 -> 1
1.8.8 -> 1
1.8.9 -> 1
1.9 -> 2
1.9.1 -> 2
1.9.2 -> 2
1.9.3 -> 2
1.9.4 -> 2
1.10 -> 2
1.10.1 -> 2
1.10.2 -> 2
1.11 -> 3
1.11.1 -> 3
1.11.2 -> 3
1.12 -> 3
1.12.1 -> 3
1.12.2 -> 3
1.13.1 -> 4
1.13.2 -> 4
1.14 -> 4
1.14.1 -> 4
1.14.2 -> 4
1.14.3 -> 4
1.14.4 -> 4
1.15 -> 5
1.15.1 -> 5
1.15.2 -> 5
1.16 -> 5
1.16.1 -> 5
1.16.2 -> 6
1.16.3 -> 6
1.16.4 -> 6
1.16.5 -> 6
1.17 -> 7

This is code golf, so the shortest answer wins. Good luck!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const int a[3], const int b[3])
{
	int i;

	for (i = 0; i < 3; i++) {
		if (a[i] < b[i])
			return -1;
		if (a[i] > b[i])
			return 1;
	}
	return 0;
}

int
packformat(const char *s)
{
	static const int vers[][3] = {
	    {1, 6, 1},
	    {1, 8, 9},
	    {1, 9, 0},
	    {1, 10, 2},
	    {1, 11, 0},
	    {1, 12, 2},
	    {1, 13, 0},
	    {1, 14, 4},
	    {1, 15, 0},
	    {1, 16, 1},
	    {1, 16, 2},
	    {1, 16, 5},
	    {1, 17, 0},
	};

	size_t i;
	int v[3];

	memset(v, 0, sizeof(v));
	if (sscanf(s, "%d.%d.%d", &v[0], &v[1], &v[2]) < 2)
		return -1;

	if (cmp(v, vers[0]) < 0)
		return 0;

	for (i = 0; i < nelem(vers) - 1; i++) {
		if (cmp(vers[i], v) <= 0 && cmp(v, vers[i + 1]) < 0)
			break;
	}
	return (i + 2) / 2;
}

int
main(void)
{
	static const struct {
		const char *version;
		int packnum;
	} tab[] = {
	    {"1.6.1", 1},
	    {"1.6.2", 1},
	    {"1.6.4", 1},
	    {"1.7.2", 1},
	    {"1.7.4", 1},
	    {"1.7.5", 1},
	    {"1.7.6", 1},
	    {"1.7.7", 1},
	    {"1.7.8", 1},
	    {"1.7.9", 1},
	    {"1.7.10", 1},
	    {"1.8", 1},
	    {"1.8.1", 1},
	    {"1.8.2", 1},
	    {"1.8.3", 1},
	    {"1.8.4", 1},
	    {"1.8.5", 1},
	    {"1.8.6", 1},
	    {"1.8.7", 1},
	    {"1.8.8", 1},
	    {"1.8.9", 1},
	    {"1.9", 2},
	    {"1.9.1", 2},
	    {"1.9.2", 2},
	    {"1.9.3", 2},
	    {"1.9.4", 2},
	    {"1.10", 2},
	    {"1.10.1", 2},
	    {"1.10.2", 2},
	    {"1.11", 3},
	    {"1.11.1", 3},
	    {"1.11.2", 3},
	    {"1.12", 3},
	    {"1.12.1", 3},
	    {"1.12.2", 3},
	    {"1.13.1", 4},
	    {"1.13.2", 4},
	    {"1.14", 4},
	    {"1.14.1", 4},
	    {"1.14.2", 4},
	    {"1.14.3", 4},
	    {"1.14.4", 4},
	    {"1.15", 5},
	    {"1.15.1", 5},
	    {"1.15.2", 5},
	    {"1.16", 5},
	    {"1.16.1", 5},
	    {"1.16.2", 6},
	    {"1.16.3", 6},
	    {"1.16.4", 6},
	    {"1.16.5", 6},
	    {"1.17", 7},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(packformat(tab[i].version) == tab[i].packnum);

	return 0;
}
