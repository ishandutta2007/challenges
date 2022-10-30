/*

The 2020-05-29 xkcd comic showed us the numbers that Randall Munroe feels would be most likely to result from multiplication, other than the correct answers. The table does seem to have some sort of twisted logic to it.

For your convenience, the Wrong Times Table is reproduced here in selectable format:

+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
|     | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  |
+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
| 1   | 0   | ½   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 9   |
| 2   | ½   | 8   | 5   | 6   | 12  | 14  | 12  | 18  | 19  | 22  |
| 3   | 4   | 5   | 10  | 16  | 13  | 12  | 24  | 32  | 21  | 33  |
| 4   | 5   | 6   | 16  | 32  | 25  | 25  | 29  | 36  | 28  | 48  |
| 5   | 6   | 12  | 13  | 25  | 50  | 24  | 40  | 45  | 40  | 60  |
| 6   | 7   | 14  | 12  | 25  | 24  | 32  | 48  | 50  | 72  | 72  |
| 7   | 8   | 12  | 24  | 29  | 40  | 48  | 42  | 54  | 60  | 84  |
| 8   | 9   | 18  | 32  | 36  | 45  | 50  | 54  | 48  | 74  | 56  |
| 9   | 10  | 19  | 21  | 28  | 40  | 72  | 60  | 74  | 72  | 81  |
| 10  | 9   | 22  | 33  | 48  | 60  | 72  | 84  | 56  | 81  | 110 |
+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
Flattened text version without headers:

0 ½ 4 5 6 7 8 9 10 9 ½ 8 5 6 12 14 12 18 19 22 4 5 10 16 13 12 24 32 21 33 5 6 16 32 25 25 29 36 28 48 6 12 13 25 50 24 40 45 40 60 7 14 12 25 24 32 48 50 72 72 8 12 24 29 40 48 42 54 60 84 9 18 32 36 45 50 54 48 74 56 10 19 21 28 40 72 60 74 72 81 9 22 33 48 60 72 84 56 81 110

Challenge

Your goal is to write a program or function that accepts two numbers as input and returns the corresponding value of the Wrong Times Table as output.

The inputs and output can be in any format and data type, as long as it is self-evidently clear which number a given value represents. So representing ½ as the floating point number 0.5 or the string "1/2" is fine, but representing it as -1 is not.
The inputs can be assumed to be integers in the range 1 to 10 inclusive.
Standard code-golf rules and loophole restrictions apply. The shortest code in bytes wins.
Example Input and Output

Input:

5
3

Output:

13

Some possible avenues for golfing
The table is symmetric across the diagonal.
There are some patterns in the numbers, e.g. f(1, n) = n + 1 for 3 ≤ n ≤ 9.
The values in the table are usually numerically close to the actual multiplication table, so you could store the differences instead.
The explain xkcd wiki page for this comic has a table showing how each number might have been derived. It may take fewer bits to store these offsets than to store the output numbers directly.

*/

#include <assert.h>
#include <stdio.h>

double
times(int a, int b)
{
	static const double tab[10][10] = {
	    {0, 0.5, 4, 5, 6, 7, 8, 9, 10, 9},
	    {0.5, 8, 5, 6, 12, 14, 12, 18, 19, 22},
	    {4, 5, 10, 16, 13, 12, 24, 32, 21, 33},
	    {5, 6, 16, 32, 25, 25, 29, 36, 28, 48},
	    {6, 12, 13, 25, 50, 24, 40, 45, 40, 60},
	    {7, 14, 12, 25, 24, 32, 48, 50, 72, 72},
	    {8, 12, 24, 29, 40, 48, 42, 54, 60, 84},
	    {9, 18, 32, 36, 45, 50, 54, 48, 74, 56},
	    {10, 19, 21, 28, 40, 72, 60, 74, 72, 81},
	    {9, 22, 33, 48, 60, 72, 84, 56, 81, 110},
	};

	if (a < 1 || a > 10 || b < 1 || b > 10)
		return -1;
	return tab[a - 1][b - 1];
}

int
main(void)
{
	assert(times(6, 6) == 32);
	assert(times(5, 3) == 13);

	return 0;
}
