/*

Given two integers, A and B, output A if A-B (A minus B) is in A-B (A to B), otherwise output B.

"A minus B" is standard subtraction.

"A to B" is the range of integers starting at A and ending at B, including both A and B. For example:

1 to 4: 1, 2, 3, 4
-2 to 5: -2, -1, 0, 1, 2, 3, 4, 5
3 to -1: 3, 2, 1, 0, -1
7 to 7: 7
The shortest code in bytes wins.

Test Cases
A B Output
1 4 4
-2 5 5
3 -1 -1
7 7 7
90 30 90
90 -30 -30
-90 30 30
-90 -30 -90
-2 -2 -2
-2 -1 -2
-2 0 -2
-2 1 1
-2 2 2
-1 -2 -2
-1 -1 -1
-1 0 -1
-1 1 1
-1 2 2
0 -2 -2
0 -1 -1
0 0 0
0 1 1
0 2 2
1 -2 -2
1 -1 -1
1 0 1
1 1 1
1 2 2
2 -2 -2
2 -1 -1
2 0 2
2 1 2
2 2 2

*/

#include <assert.h>
#include <stdlib.h>

/*

@xnor:
An arithmetic formula. Why is the negation of 2*b*b>a*b equivalent to the problem condition a-b in symrange(a,b)?

Note that x in symrange(a,b) is equivalent to 0 in symrange(a-x,b-x). Applying this to x=a-b gives 0 in symrange(b,2*b-a).
The value 0 is included in the interval unless it stretches between two positive values or two negative values.
This can be stated arithmetically as "their product b*(2*b-a) is not positive.

Finally, take b*(2*b-a)<=0, and rewrite to 2*b*b<=a*b. A byte is saved by flipping <= to > and switching the cases.

*/

int
pick(int a, int b)
{
	if ((2 * b * b) > (a * b))
		return b;
	return a;
}

int
main(void)
{
	assert(pick(1, 4) == 4);
	assert(pick(-2, 5) == 5);
	assert(pick(3, -1) == -1);
	assert(pick(7, 7) == 7);
	assert(pick(90, 30) == 90);
	assert(pick(90, -30) == -30);
	assert(pick(-90, 30) == 30);
	assert(pick(-90, -30) == -90);
	assert(pick(-2, -2) == -2);
	assert(pick(-2, -1) == -2);
	assert(pick(-2, 0) == -2);
	assert(pick(-2, 1) == 1);
	assert(pick(-2, 2) == 2);
	assert(pick(-1, -2) == -2);
	assert(pick(-1, -1) == -1);
	assert(pick(-1, 0) == -1);
	assert(pick(-1, 1) == 1);
	assert(pick(-1, 2) == 2);
	assert(pick(0, -2) == -2);
	assert(pick(0, -1) == -1);
	assert(pick(0, 0) == 0);
	assert(pick(0, 1) == 1);
	assert(pick(0, 2) == 2);
	assert(pick(1, -2) == -2);
	assert(pick(1, -1) == -1);
	assert(pick(1, 0) == 1);
	assert(pick(1, 1) == 1);
	assert(pick(1, 2) == 2);
	assert(pick(2, -2) == -2);
	assert(pick(2, -1) == -1);
	assert(pick(2, 0) == 2);
	assert(pick(2, 1) == 2);
	assert(pick(2, 2) == 2);

	return 0;
}
