/*

Mubashir needs your help to identify the spread of a deadly virus. He can provide you with the following parameters:

    A two-dimensional array persons, containing affected persons 'V' and unaffected persons 'P'.
    Number of hours n, each infected person is spreading the virus to one person up, down, left and right each hour.

Your function should return the updated array containing affected and unaffected persons after n hours.
Examples

persons = [
  ["P", "P", "P", "P", "P"],
  ["V", "P", "P", "P", "P"],
  ["P", "P", "P", "P", "P"],
  ["P", "P", "P", "P", "P"],
  ["P", "P", "P", "P", "P"]
]


deadlyVirus(persons, 0) ➞ [
  ["P", "P", "P", "P", "P"],
  ["V", "P", "P", "P", "P"],
  ["P", "P", "P", "P", "P"],
  ["P", "P", "P", "P", "P"],
  ["P", "P", "P", "P", "P"]
]

deadlyVirus(persons, 1) ➞ [
  ["V", "P", "P", "P", "P"],
  ["V", "V", "P", "P", "P"],
  ["V", "P", "P", "P", "P"],
  ["P", "P", "P", "P", "P"],
  ["P", "P", "P", "P", "P"]
]

deadlyVirus(persons, 2) ➞ [
  ["V", "V", "P", "P", "P"],
  ["V", "V", "V", "P", "P"],
  ["V", "V", "P", "P", "P"],
  ["V", "P", "P", "P", "P"],
  ["P", "P", "P", "P", "P"]
]

Notes

N/A

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>

void
dump(ssize_t n, int m[n][n])
{
	ssize_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%c ", m[i][j]);
		printf("\n");
	}
	printf("\n");
}

void
set(ssize_t n, int m[n][n], ssize_t i, ssize_t j)
{
	if (i < 0 || i >= n || j < 0 || j >= n)
		return;
	m[i][j] = 'V';
}

void
spread(ssize_t n, int m[n][n], int p[n][n])
{
	ssize_t i, j;

	memcpy(p, m, sizeof(int) * n * n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (m[i][j] == 'V') {
				set(n, p, i, j - 1);
				set(n, p, i, j + 1);
				set(n, p, i - 1, j);
				set(n, p, i + 1, j);
			}
		}
	}
}

void
infect(ssize_t n, int m[n][n], ssize_t h, int p[n][n])
{
	int t[n][n], (*x)[n], (*y)[n];
	ssize_t i;

	x = (h & 1) ? t : p;
	y = (h & 1) ? p : t;

	memcpy(x, m, sizeof(t));
	for (i = 0; i < h; i++) {
		if (!(i & 1))
			spread(n, x, y);
		else
			spread(n, y, x);
	}
}

void
test(ssize_t n, int m[n][n], ssize_t h, int r[n][n])
{
	int p[n][n];

	infect(n, m, h, p);
	dump(n, p);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	int m1[5][5] = {
	    {'P', 'P', 'P', 'P', 'P'},
	    {'V', 'P', 'P', 'P', 'P'},
	    {'P', 'P', 'P', 'P', 'P'},
	    {'P', 'P', 'P', 'P', 'P'},
	    {'P', 'P', 'P', 'P', 'P'},
	};
	int r2[5][5] = {
	    {'V', 'P', 'P', 'P', 'P'},
	    {'V', 'V', 'P', 'P', 'P'},
	    {'V', 'P', 'P', 'P', 'P'},
	    {'P', 'P', 'P', 'P', 'P'},
	    {'P', 'P', 'P', 'P', 'P'},
	};
	int r3[5][5] = {
	    {'V', 'V', 'P', 'P', 'P'},
	    {'V', 'V', 'V', 'P', 'P'},
	    {'V', 'V', 'P', 'P', 'P'},
	    {'V', 'P', 'P', 'P', 'P'},
	    {'P', 'P', 'P', 'P', 'P'},
	};

	int m2[5][5] = {
	    {'P', 'P', 'P', 'P', 'P'},
	    {'P', 'P', 'P', 'P', 'P'},
	    {'P', 'P', 'V', 'P', 'P'},
	    {'P', 'P', 'P', 'P', 'P'},
	    {'P', 'P', 'P', 'P', 'P'},
	};
	int r4[5][5] = {
	    {'P', 'P', 'P', 'P', 'P'},
	    {'P', 'P', 'V', 'P', 'P'},
	    {'P', 'V', 'V', 'V', 'P'},
	    {'P', 'P', 'V', 'P', 'P'},
	    {'P', 'P', 'P', 'P', 'P'},
	};
	int r5[5][5] = {
	    {'P', 'P', 'V', 'P', 'P'},
	    {'P', 'V', 'V', 'V', 'P'},
	    {'V', 'V', 'V', 'V', 'V'},
	    {'P', 'V', 'V', 'V', 'P'},
	    {'P', 'P', 'V', 'P', 'P'},
	};
	int r6[5][5] = {
	    {'P', 'V', 'V', 'V', 'P'},
	    {'V', 'V', 'V', 'V', 'V'},
	    {'V', 'V', 'V', 'V', 'V'},
	    {'V', 'V', 'V', 'V', 'V'},
	    {'P', 'V', 'V', 'V', 'P'},
	};
	int r7[5][5] = {
	    {'V', 'V', 'V', 'V', 'V'},
	    {'V', 'V', 'V', 'V', 'V'},
	    {'V', 'V', 'V', 'V', 'V'},
	    {'V', 'V', 'V', 'V', 'V'},
	    {'V', 'V', 'V', 'V', 'V'},
	};

	test(5, m1, 0, m1);
	test(5, m1, 1, r2);
	test(5, m1, 2, r3);
	test(5, m2, 1, r4);
	test(5, m2, 2, r5);
	test(5, m2, 3, r6);
	test(5, m2, 4, r7);

	return 0;
}
