/*

Given a list of numbers, create a function that removes 25% from every number in the list except the smallest number, and adds the total amount removed to the smallest number.
Examples

showTheLove([4, 1, 4]) ➞ [3, 3, 3]

showTheLove([16, 10, 8]) ➞ [12, 7.5, 14.5]

showTheLove([2, 100]) ➞ [27, 75]

Notes

There will only be one smallest number in a given list.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
showlove(double *a, size_t n)
{
	size_t i, j;
	double x;

	x = DBL_MAX;
	for (i = j = 0; i < n; i++) {
		if (x > a[i]) {
			x = a[i];
			j = i;
		}
	}
	for (i = 0; i < n; i++) {
		if (i != j) {
			a[j] += a[i] / 4;
			a[i] -= a[i] / 4;
		}
	}
}

void
test(double *a, size_t n, double *b)
{
	size_t i;

	showlove(a, n);
	for (i = 0; i < n; i++)
		assert(fabs(a[i] - b[i]) < 1e-8);
}

int
main(void)
{
	double a1[] = {4, 1, 4};
	double b1[] = {3, 3, 3};

	double a2[] = {16, 10, 8};
	double b2[] = {12, 7.5, 14.5};

	double a3[] = {2, 100};
	double b3[] = {27, 75};

	double a4[] = {75, 64, 55};
	double b4[] = {56.25, 48.0, 89.75};

	double a5[] = {84, 94, 26, 80, 16};
	double b5[] = {63.0, 70.5, 19.5, 60.0, 87.0};

	double a6[] = {55, 27};
	double b6[] = {41.25, 40.75};

	double a7[] = {13, 80, 75, 45, 11};
	double b7[] = {9.75, 60.0, 56.25, 33.75, 64.25};

	double a8[] = {48, 28, 18};
	double b8[] = {36.0, 21.0, 37.0};

	double a9[] = {17, 9};
	double b9[] = {12.75, 13.25};

	double a10[] = {38, 23, 31, 16};
	double b10[] = {28.5, 17.25, 23.25, 39.0};

	double a11[] = {54, 62, 59};
	double b11[] = {84.25, 46.5, 44.25};

	double a12[] = {44, 46};
	double b12[] = {55.5, 34.5};

	double a13[] = {21, 97, 45, 58};
	double b13[] = {71.0, 72.75, 33.75, 43.5};

	double a14[] = {43, 9};
	double b14[] = {32.25, 19.75};

	double a15[] = {53, 0, 14, 58};
	double b15[] = {39.75, 31.25, 10.5, 43.5};

	double a16[] = {16, 19, 42, 43, 6};
	double b16[] = {12.0, 14.25, 31.5, 32.25, 36.0};

	double a17[] = {26, 17, 28, 31, 79};
	double b17[] = {19.5, 58.0, 21.0, 23.25, 59.25};

	double a18[] = {47, 57, 18, 2, 72};
	double b18[] = {35.25, 42.75, 13.5, 50.5, 54.0};

	double a19[] = {27, 77};
	double b19[] = {46.25, 57.75};

	double a20[] = {22, 52};
	double b20[] = {35.0, 39.0};

	double a21[] = {85, 49, 60, 78, 6};
	double b21[] = {63.75, 36.75, 45.0, 58.5, 74.0};

	double a22[] = {96, 38};
	double b22[] = {72.0, 62.0};

	double a23[] = {29, 73, 81};
	double b23[] = {67.5, 54.75, 60.75};

	double a24[] = {51, 46, 81, 85};
	double b24[] = {38.25, 100.25, 60.75, 63.75};

	double a25[] = {26, 48, 84, 70, 8};
	double b25[] = {19.5, 36.0, 63.0, 52.5, 65.0};

	double a26[] = {69, 64};
	double b26[] = {51.75, 81.25};

	double a27[] = {33, 26, 39, 58};
	double b27[] = {24.75, 58.5, 29.25, 43.5};

	double a28[] = {4, 51, 66};
	double b28[] = {33.25, 38.25, 49.5};

	double a29[] = {0, 52, 83, 55, 40};
	double b29[] = {57.5, 39.0, 62.25, 41.25, 30.0};

	double a30[] = {39, 3, 36, 52, 25};
	double b30[] = {29.25, 41.0, 27.0, 39.0, 18.75};

	double a31[] = {32, 78, 12};
	double b31[] = {24.0, 58.5, 39.5};

	double a32[] = {75, 51, 24};
	double b32[] = {56.25, 38.25, 55.5};

	double a33[] = {42, 21, 93, 47};
	double b33[] = {31.5, 66.5, 69.75, 35.25};

	double a34[] = {72, 97, 26, 1};
	double b34[] = {54.0, 72.75, 19.5, 49.75};

	double a35[] = {90, 45, 12};
	double b35[] = {67.5, 33.75, 45.75};

	double a36[] = {37, 47, 82};
	double b36[] = {69.25, 35.25, 61.5};

	double a37[] = {54, 11};
	double b37[] = {40.5, 24.5};

	double a38[] = {78, 86, 19, 46, 51};
	double b38[] = {58.5, 64.5, 84.25, 34.5, 38.25};

	double a39[] = {7, 31, 74, 69};
	double b39[] = {50.5, 23.25, 55.5, 51.75};

	double a40[] = {100, 26, 3, 28, 19};
	double b40[] = {75.0, 19.5, 46.25, 21.0, 14.25};

	double a41[] = {87, 29, 92, 57};
	double b41[] = {65.25, 88.0, 69.0, 42.75};

	double a42[] = {64, 24};
	double b42[] = {48.0, 40.0};

	double a43[] = {82, 89, 52, 25, 50};
	double b43[] = {61.5, 66.75, 39.0, 93.25, 37.5};

	double a44[] = {90, 17, 11};
	double b44[] = {67.5, 12.75, 37.75};

	double a45[] = {14, 24, 27};
	double b45[] = {26.75, 18.0, 20.25};

	double a46[] = {21, 4};
	double b46[] = {15.75, 9.25};

	double a47[] = {70, 64, 25, 16};
	double b47[] = {52.5, 48.0, 18.75, 55.75};

	double a48[] = {50, 17, 87, 20};
	double b48[] = {37.5, 56.25, 65.25, 15.0};

	double a49[] = {60, 27, 56};
	double b49[] = {45.0, 56.0, 42.0};

	double a50[] = {99, 21};
	double b50[] = {74.25, 45.75};

	double a51[] = {80, 0, 45, 84};
	double b51[] = {60.0, 52.25, 33.75, 63.0};

	test(a1, nelem(a1), b1);
	test(a2, nelem(a2), b2);
	test(a3, nelem(a3), b3);
	test(a4, nelem(a4), b4);
	test(a5, nelem(a5), b5);
	test(a6, nelem(a6), b6);
	test(a7, nelem(a7), b7);
	test(a8, nelem(a8), b8);
	test(a9, nelem(a9), b9);
	test(a10, nelem(a10), b10);
	test(a11, nelem(a11), b11);
	test(a12, nelem(a12), b12);
	test(a13, nelem(a13), b13);
	test(a14, nelem(a14), b14);
	test(a15, nelem(a15), b15);
	test(a16, nelem(a16), b16);
	test(a17, nelem(a17), b17);
	test(a18, nelem(a18), b18);
	test(a19, nelem(a19), b19);
	test(a20, nelem(a20), b20);
	test(a21, nelem(a21), b21);
	test(a22, nelem(a22), b22);
	test(a23, nelem(a23), b23);
	test(a24, nelem(a24), b24);
	test(a25, nelem(a25), b25);
	test(a26, nelem(a26), b26);
	test(a27, nelem(a27), b27);
	test(a28, nelem(a28), b28);
	test(a29, nelem(a29), b29);
	test(a30, nelem(a30), b30);
	test(a31, nelem(a31), b31);
	test(a32, nelem(a32), b32);
	test(a33, nelem(a33), b33);
	test(a34, nelem(a34), b34);
	test(a35, nelem(a35), b35);
	test(a36, nelem(a36), b36);
	test(a37, nelem(a37), b37);
	test(a38, nelem(a38), b38);
	test(a39, nelem(a39), b39);
	test(a40, nelem(a40), b40);
	test(a41, nelem(a41), b41);
	test(a42, nelem(a42), b42);
	test(a43, nelem(a43), b43);
	test(a44, nelem(a44), b44);
	test(a45, nelem(a45), b45);
	test(a46, nelem(a46), b46);
	test(a47, nelem(a47), b47);
	test(a48, nelem(a48), b48);
	test(a49, nelem(a49), b49);
	test(a50, nelem(a50), b50);
	test(a51, nelem(a51), b51);

	return 0;
}
