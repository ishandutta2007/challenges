/*

In atomic physics and quantum chemistry, the electron configuration is the distribution of electrons of an atom in atomic orbitals. For example, the electron configuration of the neon atom is 1s2 2s2 2p6. (From Wikipedia)

Challenge
Your challenge is to take a number representing the atomic number of an element and output the electron configuration of that element as defined by the Aufbau principle.

Iron (26) has the electron configuration 1s2 2s2 2p6 3s2 3p6 3d6 4s2. However, superscripts are unnecessary; the output for 26 should be along the lines of 1s2 2s2 2p6 3s2 3p6 3d6 4s2.

Specification
You do not have to handle any inputs outside of the range 1 <= n <= 118.
Your output should look something like the test cases, but you may use any non-digit character/characters (aside from s, p, d, and f) to delimit the different orbitals.
You must return/print a string containing the orbital names/values/delmiters; you cannot simply return/print an array.
You do not need to handle any exceptions to the Aufbau principle; where there are exceptions, printing the "incorrect" configuration is fine.

Examples:

Input -> Valid output            -> Invalid output
16    -> 1s2 2s2 2p6 3s2 3p4     -> 1s22s22p63s23p4
16    -> 1s2, 2s2, 2p6, 3s2, 3p4 -> [[1, 2], [2, 2], [2, 6], [3, 2], [3, 4]]
17    -> 1s2+2s2+2p6+3s2+3p5     -> 1s2s2s2s2p6p3s2s3p5
Here is a list of all the electronic orbitals. The maximum values they can contain are below the name:

name: 1s 2s 2p 3s 3p 3d 4s 4p 4d 5s 5p 4f 5d 6s 6p 5f 6d 7s 7p
max:  2  2  6  2  6  10 2  6  10 2  6  14 10 2  6  14 10 2  6
Test Cases
Input -> Output
1     -> 1s1
2     -> 1s2
16    -> 1s2 2s2 2p6 3s2 3p4
50    -> 1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p2
115   -> 1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d10 7s2 7p3
Here is a complete list and a reference implementation of sorts (Try it online!)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
configuration(int n, char *b)
{
	static const int otab[] = {2, 2, 6, 2, 6, 10, 2, 6, 10, 2, 6, 14, 10, 2, 6, 14, 10, 2, 6};
	static const char *stab[] = {"1s", "2s", "2p", "3s", "3p", "3d", "4s", "4p", "4d", "5s", "5p", "4f", "5d", "6s", "6p", "5f", "6d", "7s", "7p"};

	size_t i;
	int m, v;
	int l;

	b[0] = '\0';
	if (n <= 0 || n > 118)
		return b;

	l = 0;
	for (i = 0; i < nelem(otab); i++) {
		m = otab[i];
		n = n - m;
		v = (n < 0) ? m + n : m;
		l += sprintf(b + l, "%s%d ", stab[i], v);
		if (n <= 0)
			break;
	}

	if (l)
		b[l - 1] = '\0';

	return b;
}

void
test(int n, const char *r)
{
	char b[128];

	configuration(n, b);
	printf("%d -> %s\n", n, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	static const struct {
		int n;
		char r[128];
	} tab[] = {
	    {1, "1s1"},
	    {2, "1s2"},
	    {3, "1s2 2s1"},
	    {4, "1s2 2s2"},
	    {5, "1s2 2s2 2p1"},
	    {6, "1s2 2s2 2p2"},
	    {7, "1s2 2s2 2p3"},
	    {8, "1s2 2s2 2p4"},
	    {9, "1s2 2s2 2p5"},
	    {10, "1s2 2s2 2p6"},
	    {11, "1s2 2s2 2p6 3s1"},
	    {12, "1s2 2s2 2p6 3s2"},
	    {13, "1s2 2s2 2p6 3s2 3p1"},
	    {14, "1s2 2s2 2p6 3s2 3p2"},
	    {15, "1s2 2s2 2p6 3s2 3p3"},
	    {16, "1s2 2s2 2p6 3s2 3p4"},
	    {17, "1s2 2s2 2p6 3s2 3p5"},
	    {18, "1s2 2s2 2p6 3s2 3p6"},
	    {19, "1s2 2s2 2p6 3s2 3p6 3d1"},
	    {20, "1s2 2s2 2p6 3s2 3p6 3d2"},
	    {21, "1s2 2s2 2p6 3s2 3p6 3d3"},
	    {22, "1s2 2s2 2p6 3s2 3p6 3d4"},
	    {23, "1s2 2s2 2p6 3s2 3p6 3d5"},
	    {24, "1s2 2s2 2p6 3s2 3p6 3d6"},
	    {25, "1s2 2s2 2p6 3s2 3p6 3d7"},
	    {26, "1s2 2s2 2p6 3s2 3p6 3d8"},
	    {27, "1s2 2s2 2p6 3s2 3p6 3d9"},
	    {28, "1s2 2s2 2p6 3s2 3p6 3d10"},
	    {29, "1s2 2s2 2p6 3s2 3p6 3d10 4s1"},
	    {30, "1s2 2s2 2p6 3s2 3p6 3d10 4s2"},
	    {31, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p1"},
	    {32, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p2"},
	    {33, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p3"},
	    {34, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p4"},
	    {35, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p5"},
	    {36, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6"},
	    {37, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d1"},
	    {38, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d2"},
	    {39, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d3"},
	    {40, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d4"},
	    {41, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d5"},
	    {42, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d6"},
	    {43, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d7"},
	    {44, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d8"},
	    {45, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d9"},
	    {46, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10"},
	    {47, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s1"},
	    {48, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2"},
	    {49, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p1"},
	    {50, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p2"},
	    {51, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p3"},
	    {52, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p4"},
	    {53, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p5"},
	    {54, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6"},
	    {55, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f1"},
	    {56, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f2"},
	    {57, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f3"},
	    {58, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f4"},
	    {59, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f5"},
	    {60, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f6"},
	    {61, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f7"},
	    {62, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f8"},
	    {63, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f9"},
	    {64, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f10"},
	    {65, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f11"},
	    {66, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f12"},
	    {67, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f13"},
	    {68, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14"},
	    {69, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d1"},
	    {70, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d2"},
	    {71, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d3"},
	    {72, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d4"},
	    {73, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d5"},
	    {74, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d6"},
	    {75, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d7"},
	    {76, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d8"},
	    {77, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d9"},
	    {78, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10"},
	    {79, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s1"},
	    {80, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2"},
	    {81, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p1"},
	    {82, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p2"},
	    {83, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p3"},
	    {84, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p4"},
	    {85, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p5"},
	    {86, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6"},
	    {87, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f1"},
	    {88, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f2"},
	    {89, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f3"},
	    {90, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f4"},
	    {91, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f5"},
	    {92, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f6"},
	    {93, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f7"},
	    {94, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f8"},
	    {95, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f9"},
	    {96, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f10"},
	    {97, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f11"},
	    {98, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f12"},
	    {99, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f13"},
	    {100, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14"},
	    {101, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d1"},
	    {102, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d2"},
	    {103, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d3"},
	    {104, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d4"},
	    {105, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d5"},
	    {106, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d6"},
	    {107, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d7"},
	    {108, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d8"},
	    {109, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d9"},
	    {110, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d10"},
	    {111, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d10 7s1"},
	    {112, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d10 7s2"},
	    {113, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d10 7s2 7p1"},
	    {114, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d10 7s2 7p2"},
	    {115, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d10 7s2 7p3"},
	    {116, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d10 7s2 7p4"},
	    {117, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d10 7s2 7p5"},
	    {118, "1s2 2s2 2p6 3s2 3p6 3d10 4s2 4p6 4d10 5s2 5p6 4f14 5d10 6s2 6p6 5f14 6d10 7s2 7p6"},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		test(tab[i].n, tab[i].r);

	return 0;
}
