/*

Your task is to generate a graph with 54 vertices, each corresponds to a facet on a Rubik's cube. There is an edge between two vertices iff the corresponding facets share a side.

Rules
You may choose to output an adjacency list, adjacency matrix, edge list, or any reasonable format to represent a graph in an algorithm. (A visual graph readable by a human is generally not a reasonable format in an algorithm in most cases.)
You may make either every vertex adjacent to itself, or none adjacent to itself.
You may either include both directions for each edge (count one or two times for self-loops), or output exactly one time for each edge, but not mix the ways.
You may renumber the vertices, skip some numbers, or even use non-number labels for the vertices in any way you want. You should also post the numbering if it isn't obvious, so others could check your answer in easier ways.
This is code-golf. Shortest code in bytes wins.
Example output
This is the numbering of vertices used in the example:

          0  1  2
          3  4  5
          6  7  8
 9 10 11 18 19 20 27 28 29 36 37 38
12 13 14 21 22 23 30 31 32 39 40 41
15 16 17 24 25 26 33 34 35 42 43 44
         45 46 47
         48 49 50
         51 52 53

Output as an adjacency list (vertex number before each list is optional):

0 [1 3 9 38]
1 [2 4 0 37]
2 [29 5 1 36]
3 [4 6 10 0]
4 [5 7 3 1]
5 [28 8 4 2]
6 [7 18 11 3]
7 [8 19 6 4]
8 [27 20 7 5]
9 [10 12 38 0]
10 [11 13 9 3]
11 [18 14 10 6]
12 [13 15 41 9]
13 [14 16 12 10]
14 [21 17 13 11]
15 [16 51 44 12]
16 [17 48 15 13]
17 [24 45 16 14]
18 [19 21 11 6]
19 [20 22 18 7]
20 [27 23 19 8]
21 [22 24 14 18]
22 [23 25 21 19]
23 [30 26 22 20]
24 [25 45 17 21]
25 [26 46 24 22]
26 [33 47 25 23]
27 [28 30 20 8]
28 [29 31 27 5]
29 [36 32 28 2]
30 [31 33 23 27]
31 [32 34 30 28]
32 [39 35 31 29]
33 [34 47 26 30]
34 [35 50 33 31]
35 [42 53 34 32]
36 [37 39 29 2]
37 [38 40 36 1]
38 [9 41 37 0]
39 [40 42 32 36]
40 [41 43 39 37]
41 [12 44 40 38]
42 [43 53 35 39]
43 [44 52 42 40]

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
vertices(void)
{
	static const int cube[54][4] = {
	    {1, 3, 9, 38},
	    {2, 4, 0, 37},
	    {29, 5, 1, 36},
	    {4, 6, 10, 0},
	    {5, 7, 3, 1},
	    {28, 8, 4, 2},
	    {7, 18, 11, 3},
	    {8, 19, 6, 4},
	    {27, 20, 7, 5},
	    {10, 12, 38, 0},
	    {11, 13, 9, 3},
	    {18, 14, 10, 6},
	    {13, 15, 41, 9},
	    {14, 16, 12, 10},
	    {21, 17, 13, 11},
	    {16, 51, 44, 12},
	    {17, 48, 15, 13},
	    {24, 45, 16, 14},
	    {19, 21, 11, 6},
	    {20, 22, 18, 7},
	    {27, 23, 19, 8},
	    {22, 24, 14, 18},
	    {23, 25, 21, 19},
	    {30, 26, 22, 20},
	    {25, 45, 17, 21},
	    {26, 46, 24, 22},
	    {33, 47, 25, 23},
	    {28, 30, 20, 8},
	    {29, 31, 27, 5},
	    {36, 32, 28, 2},
	    {31, 33, 23, 27},
	    {32, 34, 30, 28},
	    {39, 35, 31, 29},
	    {34, 47, 26, 30},
	    {35, 50, 33, 31},
	    {42, 53, 34, 32},
	    {37, 39, 29, 2},
	    {38, 40, 36, 1},
	    {9, 41, 37, 0},
	    {40, 42, 32, 36},
	    {41, 43, 39, 37},
	    {12, 44, 40, 38},
	    {43, 53, 35, 39},
	    {44, 52, 42, 40},
	    {15, 51, 43, 41},
	    {46, 48, 17, 24},
	    {47, 49, 45, 25},
	    {33, 50, 46, 26},
	    {49, 51, 16, 45},
	    {50, 52, 48, 46},
	    {34, 53, 49, 47},
	    {52, 44, 15, 48},
	    {53, 43, 51, 49},
	    {35, 42, 52, 50},
	};

	size_t i, j;

	for (i = 0; i < nelem(cube); i++) {
		printf("%2zu [ ", i);
		for (j = 0; j < nelem(cube[i]); j++)
			printf("%2d ", cube[i][j]);
		printf("]\n");
	}
}

int
main(void)
{
	vertices();
	return 0;
}
