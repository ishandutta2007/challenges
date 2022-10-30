/*

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image. 

Note:
The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

*/

#include <stdio.h>

void
print(size_t m, size_t n, int a[m][n])
{
	size_t r, c;

	printf("[");
	for (r = 0; r < m; r++) {
		printf("[");
		for (c = 0; c < n; c++) {
			printf("%d", a[r][c]);
			if (c + 1 < n)
				printf(",");
		}
		printf("]");
		if (r + 1 < m)
			printf(",");
		else
			printf("]");
		printf("\n");
	}
	printf("\n");
}

void
floodfill(size_t m, size_t n, int a[m][n], size_t r, size_t c, int p, int q)
{
	if (r >= m || c >= n || a[r][c] != p)
		return;

	a[r][c] = q;
	if (r > 0)
		floodfill(m, n, a, r - 1, c, p, q);
	if (r + 1 < m)
		floodfill(m, n, a, r + 1, c, p, q);
	if (c > 0)
		floodfill(m, n, a, r, c - 1, p, q);
	if (c + 1 < n)
		floodfill(m, n, a, r, c + 1, p, q);
}

void
test(size_t m, size_t n, int a[m][n], size_t r, size_t c, int q)
{
	print(m, n, a);
	floodfill(m, n, a, r, c, a[r][c], q);
	print(m, n, a);
}

int
main(void)
{
	int m1[3][3] = {
	    {1, 1, 1},
	    {1, 1, 0},
	    {1, 0, 1},
	};
	test(3, 3, m1, 1, 1, 2);

	return 0;
}
