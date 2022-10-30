/*

A troop of Etruscan warriors is organized as follows. In the first row, there is only one warrior; then, the second row contains two warriors; the third row contains three warriors, and so on.
In general, each row i contains i warriors.
We know the number of Etruscan warriors of a given troop. You have to compute the number of rows in which they are organized.
Please note that there may be some remaining warriors (this could happen if they are not enough to form the next row).
For example, 3 warriors are organized in 2 rows. With 6 warriors you can form 3 rows; but you can also form 3 rows with 7, 8 or 9 warriors.

Input

The first line of the input contains an integer indicating the number of test cases.
For each test case, there is a single integer, n, indicating the number of Etruscan warriors. You can assume that 0 ≤ n ≤ 10^18.

Output

For each test case, the output should contain a single integer indicating the number of rows that can be formed.

Sample Input

6
3
6
7
8
9
10

Sample Output

2
3
3
3
3
4

*/

#include <assert.h>

int
rows(int n)
{
	int i;

	for (i = 1; n >= i; i++)
		n -= i;
	return i - 1;
}

int
main(void)
{
	assert(rows(3) == 2);
	assert(rows(6) == 3);
	assert(rows(7) == 3);
	assert(rows(8) == 3);
	assert(rows(9) == 3);
	assert(rows(10) == 4);

	return 0;
}
