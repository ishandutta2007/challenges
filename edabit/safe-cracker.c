/*

Traditional safes use a three-wheel locking mechanism, with the safe combination entered using a dial on the door of the safe.
The dial is marked with clockwise increments between 0 and 99. The three-number combination is entered by first dialling to the right (clockwise),
then to the left (anti-clockwise), and then to the right (clockwise) again. Combination numbers are read from the top of the dial:

Given the starting (top) position of the dial and the increments used for each turn of the dial, return an array containing the combination of the safe.
Step-By-Step Example

safecracker(0, [3, 10, 5]) ➞ [97, 7, 2]

Starting dial position of 0 (same as the diagram above).

First turn (rightward) of 3 increments:
0 -> 99, 98, 97
First number of combination = 97

Second turn (leftward) of 10 increments:
97 -> 98, 99, 0, 1, 2, 3, 4, 5, 6, 7
Second number of combination = 7

Third turn (rightward) of 5 increments:
7 -> 6, 5, 4, 3, 2
Third number of combination = 2

The final combination is [97, 7, 2]

Other Examples

safecracker(96, [54, 48, 77]) ➞ [42, 90, 13]

safecracker(43, [51, 38, 46]) ➞ [92, 30, 84]

safecracker(4, [69, 88, 55]) ➞ [35, 23, 68]

Notes

Each of the three combination numbers will be different.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

void
safecracker(int p, int s[3], int r[3])
{
	r[0] = mod(p - s[0], 100);
	r[1] = mod(r[0] + s[1], 100);
	r[2] = mod(r[1] - s[2], 100);
}

void
test(int p, int s[3], int r[3])
{
	int t[3];

	safecracker(p, s, t);
	assert(!memcmp(r, t, sizeof(t)));
}

int
main(void)
{
	int s1[] = {3, 10, 5};
	int r1[] = {97, 7, 2};

	int s2[] = {54, 48, 77};
	int r2[] = {42, 90, 13};

	int s3[] = {51, 38, 46};
	int r3[] = {92, 30, 84};

	int s4[] = {69, 88, 55};
	int r4[] = {35, 23, 68};

	int s5[] = {87, 61, 91};
	int r5[] = {12, 73, 82};

	int s6[] = {22, 16, 35};
	int r6[] = {41, 57, 22};

	int s7[] = {10, 57, 96};
	int r7[] = {8, 65, 69};

	int s8[] = {91, 4, 91};
	int r8[] = {91, 95, 4};

	int s9[] = {37, 12, 7};
	int r9[] = {46, 58, 51};

	int s10[] = {44, 86, 23};
	int r10[] = {87, 73, 50};

	int s11[] = {47, 76, 89};
	int r11[] = {49, 25, 36};

	int s12[] = {41, 5, 66};
	int r12[] = {41, 46, 80};

	int s13[] = {59, 79, 99};
	int r13[] = {72, 51, 52};

	int s14[] = {71, 93, 93};
	int r14[] = {96, 89, 96};

	int s15[] = {14, 35, 34};
	int r15[] = {81, 16, 82};

	int s16[] = {73, 98, 55};
	int r16[] = {4, 2, 47};

	int s17[] = {86, 4, 40};
	int r17[] = {92, 96, 56};

	int s18[] = {21, 94, 92};
	int r18[] = {79, 73, 81};

	int s19[] = {63, 96, 30};
	int r19[] = {82, 78, 48};

	int s20[] = {25, 93, 94};
	int r20[] = {73, 66, 72};

	int s21[] = {64, 25, 63};
	int r21[] = {63, 88, 25};

	int s22[] = {6, 81, 49};
	int r22[] = {46, 27, 78};

	int s23[] = {70, 88, 70};
	int r23[] = {86, 74, 4};

	int s24[] = {25, 24, 73};
	int r24[] = {60, 84, 11};

	test(0, s1, r1);
	test(96, s2, r2);
	test(43, s3, r3);
	test(4, s4, r4);
	test(99, s5, r5);
	test(63, s6, r6);
	test(18, s7, r7);
	test(82, s8, r8);
	test(83, s9, r9);
	test(31, s10, r10);
	test(96, s11, r11);
	test(82, s12, r12);
	test(31, s13, r13);
	test(67, s14, r14);
	test(95, s15, r15);
	test(77, s16, r16);
	test(78, s17, r17);
	test(0, s18, r18);
	test(45, s19, r19);
	test(98, s20, r20);
	test(27, s21, r21);
	test(52, s22, r22);
	test(56, s23, r23);
	test(85, s24, r24);

	return 0;
}
