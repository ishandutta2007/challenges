/*

The task

Given any array of integers, e.g.:

[-1,476,578,27,0,1,-1,1,2]

and an index of that array (this example uses 0 based indexing, though you can use 1 based indexing as well.):

         index = 5
                 v
[-1,476,578,27,0,1,-1,1,2]

Then return the nearest number greater than the element at that index. In the example, the closest number greater than 1 is 27 (at 2 indices away).

         index = 5
                 v
[-1,476,578,27,0,1,-1,1,2]
            ^
Nearest greater number

Output = 27

Assumptions

    Nearest does not include wrapping.
    The program will never be given an array of length 1 (e.g; [55]).
    You are to assume there is always a number greater than the given element.
    If there are 2 numbers greater than the element at equal distances, you can return either one.

This is code-golf so the shortest code in bytes wins
I/O pairs

Input:
Index = 45
Array = [69, 43, 89, 93, 62, 25, 4, 11, 115, 87, 174, 60, 84, 58, 28, 67, 71, 157, 47, 8, 33, 192, 187, 87, 175, 32, 135, 25, 137, 92, 183, 151, 147, 7, 133, 7, 41, 12, 96, 147, 9, 134, 197, 3, 107, 164, 90, 199, 21, 71, 77, 62, 190, 122, 33, 127, 185, 58, 92, 106, 26, 24, 56, 79, 71, 24, 24, 114, 17, 84, 121, 188, 6, 177, 114, 159, 159, 102, 50, 136, 47, 32, 1, 199, 74, 141, 125, 23, 118, 9, 12, 100, 94, 166, 12, 9, 179, 147, 149, 178, 90, 71, 141, 49, 74, 100, 199, 160, 120, 14, 195, 112, 176, 164, 68, 88, 108, 72, 124, 173, 155, 146, 193, 30, 2, 186, 102, 45, 147, 99, 178, 84, 83, 93, 153, 11, 171, 186, 157, 32, 90, 57, 181, 5, 157, 106, 20, 5, 194, 130, 100, 97, 3, 87, 116, 57, 125, 157, 190, 83, 148, 90, 44, 156, 167, 131, 100, 58, 139, 183, 53, 91, 151, 65, 121, 61, 40, 80, 40, 68, 73, 20, 135, 197, 124, 190, 108, 66, 21, 27, 147, 118, 192, 29, 193, 27, 155, 93, 33, 129]
Output = 199

Input:
Index = 2
Array = [4,-2,1,-3,5]
Output = 4 OR 5

Input:
Index = 0
Array = [2124, -173, -155, 146, 193, -30, 2, 186, 102, 4545]
Output = 4545

Input:
Index = 0
Array = [1,0,2,3]
Output = 2

Input:
Index = 2
Array = [3,-1,-3,-2,5]
Output = -1 OR -2

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
ngn(int *a, size_t n, size_t i)
{
	size_t j, k;
	int x, y;

	j = k = i;
	while (j > 0 || k < n) {
		x = y = a[i];
		if (j > 0)
			x = a[--j];
		if (k + 1 < n)
			y = a[++k];

		if (x > a[i])
			return x;
		if (y > a[i])
			return y;
	}
	return INT_MIN;
}

int
main(void)
{
	int a1[] = {-1, 476, 578, 27, 0, 1, -1, 1, 2};
	int a2[] = {69, 43, 89, 93, 62, 25, 4, 11, 115, 87, 174, 60, 84, 58, 28, 67, 71, 157, 47, 8, 33, 192, 187, 87, 175, 32, 135, 25, 137, 92, 183, 151, 147, 7, 133, 7, 41, 12, 96, 147, 9, 134, 197, 3, 107, 164, 90, 199, 21, 71, 77, 62, 190, 122, 33, 127, 185, 58, 92, 106, 26, 24, 56, 79, 71, 24, 24, 114, 17, 84, 121, 188, 6, 177, 114, 159, 159, 102, 50, 136, 47, 32, 1, 199, 74, 141, 125, 23, 118, 9, 12, 100, 94, 166, 12, 9, 179, 147, 149, 178, 90, 71, 141, 49, 74, 100, 199, 160, 120, 14, 195, 112, 176, 164, 68, 88, 108, 72, 124, 173, 155, 146, 193, 30, 2, 186, 102, 45, 147, 99, 178, 84, 83, 93, 153, 11, 171, 186, 157, 32, 90, 57, 181, 5, 157, 106, 20, 5, 194, 130, 100, 97, 3, 87, 116, 57, 125, 157, 190, 83, 148, 90, 44, 156, 167, 131, 100, 58, 139, 183, 53, 91, 151, 65, 121, 61, 40, 80, 40, 68, 73, 20, 135, 197, 124, 190, 108, 66, 21, 27, 147, 118, 192, 29, 193, 27, 155, 93, 33, 129};
	int a3[] = {4, -2, 1, -3, 5};
	int a4[] = {2124, -173, -155, 146, 193, -30, 2, 186, 102, 4545};
	int a5[] = {1, 0, 2, 3};
	int a6[] = {3, -1, -3, -2, 5};

	assert(ngn(a1, nelem(a1), 5) == 27);
	assert(ngn(a2, nelem(a2), 45) == 199);
	assert(ngn(a3, nelem(a3), 2) == 4);
	assert(ngn(a4, nelem(a4), 0) == 4545);
	assert(ngn(a5, nelem(a5), 0) == 2);
	assert(ngn(a6, nelem(a6), 2) == -1);

	return 0;
}
