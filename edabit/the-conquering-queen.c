/*

In chess, queens can move any number of squares horizontally, vertically or diagonally.

Given the location of your queen and your opponents' queen, determine whether or not you're able to capture your opponent's queen.
Your location and your opponents' location are the first and second elements of the array, respectively.
Examples

canCapture(["A1", "H8"]) ➞ true
// Your queen can move diagonally to capture opponents' piece.

canCapture(["A1", "C2"]) ➞ false
// Your queen cannot reach C2 from A1 (although a knight could).

canCapture(["G3", "E5"]) ➞ true

Notes

Assume there are no blocking pieces.

*/

// https://www.chessprogramming.org/Square_Mapping_Considerations#Little-Endian_Rank-File_Mapping
// https://www.chessprogramming.org/Kogge-Stone_Algorithm#Fillonanemptyboard

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef unsigned long long uvlong;

#define AFILE 0x0101010101010101ULL
#define HFILE 0x8080808080808080ULL

void
print(uvlong b)
{
	int i, j, s;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			s = 8 * (7 - i) + j;
			if (b & (1ULL << s))
				printf("X");
			else
				printf(".");
		}
		printf("\n");
	}
	printf("\n");
}

uvlong
south(uvlong gen)
{
	gen |= (gen >> 8);
	gen |= (gen >> 16);
	gen |= (gen >> 32);
	return gen;
}

uvlong
north(uvlong gen)
{
	gen |= (gen << 8);
	gen |= (gen << 16);
	gen |= (gen << 32);
	return gen;
}

uvlong
east(uvlong gen)
{
	uvlong pr0, pr1, pr2;

	pr0 = ~AFILE;
	pr1 = pr0 & (pr0 << 1);
	pr2 = pr1 & (pr1 << 2);
	gen |= pr0 & (gen << 1);
	gen |= pr1 & (gen << 2);
	gen |= pr2 & (gen << 4);
	return gen;
}

uvlong
northeast(uvlong gen)
{
	uvlong pr0, pr1, pr2;

	pr0 = ~AFILE;
	pr1 = pr0 & (pr0 << 9);
	pr2 = pr1 & (pr1 << 18);
	gen |= pr0 & (gen << 9);
	gen |= pr1 & (gen << 18);
	gen |= pr2 & (gen << 36);
	return gen;
}

uvlong
southeast(uvlong gen)
{
	uvlong pr0, pr1, pr2;

	pr0 = ~AFILE;
	pr1 = pr0 & (pr0 >> 7);
	pr2 = pr1 & (pr1 >> 14);
	gen |= pr0 & (gen >> 7);
	gen |= pr1 & (gen >> 14);
	gen |= pr2 & (gen >> 28);
	return gen;
}

uvlong
west(uvlong gen)
{
	uvlong pr0, pr1, pr2;

	pr0 = ~HFILE;
	pr1 = pr0 & (pr0 >> 1);
	pr2 = pr1 & (pr1 >> 2);
	gen |= pr0 & (gen >> 1);
	gen |= pr1 & (gen >> 2);
	gen |= pr2 & (gen >> 4);
	return gen;
}

uvlong
southwest(uvlong gen)
{
	uvlong pr0, pr1, pr2;

	pr0 = ~HFILE;
	pr1 = pr0 & (pr0 >> 9);
	pr2 = pr1 & (pr1 >> 18);
	gen |= pr0 & (gen >> 9);
	gen |= pr1 & (gen >> 18);
	gen |= pr2 & (gen >> 36);
	return gen;
}

uvlong
northwest(uvlong gen)
{
	uvlong pr0, pr1, pr2;

	pr0 = ~HFILE;
	pr1 = pr0 & (pr0 << 7);
	pr2 = pr1 & (pr1 << 14);
	gen |= pr0 & (gen << 7);
	gen |= pr1 & (gen << 14);
	gen |= pr2 & (gen << 28);
	return gen;
}

uvlong
sq(const char *s)
{
	uvlong i, j;

	i = s[0] - 'A';
	j = s[1] - '1';
	return 8 * j + i;
}

uvlong
gen(uvlong sq)
{
	uvlong p;

	p = 1ULL << sq;
	return north(p) | south(p) | east(p) | west(p) | northeast(p) | northwest(p) | southeast(p) | southwest(p);
}

bool
capture(const char *s, const char *t)
{
	return (gen(sq(s)) & (1ULL << sq(t))) != 0;
}

int
main(void)
{
	assert(capture("A1", "H8") == true);
	assert(capture("A1", "C2") == false);
	assert(capture("G3", "E5") == true);
	assert(capture("D3", "C2") == true);
	assert(capture("F4", "C1") == true);
	assert(capture("H1", "A7") == false);
	assert(capture("H1", "A8") == true);
	assert(capture("G1", "G2") == true);
	assert(capture("A5", "G5") == true);
	assert(capture("A5", "E2") == false);

	return 0;
}
