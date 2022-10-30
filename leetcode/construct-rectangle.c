/*

For a web developer, it is very important to know how to design a web page's size.
So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page,
whose length L and width W satisfy the following requirements:

1. The area of the rectangular web page you designed must equal to the given target area.

2. The width W should not be larger than the length L, which means L >= W.

3. The difference between length L and width W should be as small as possible.

You need to output the length L and the width W of the web page you designed in sequence.

Note:

    The given area won't exceed 10,000,000 and is a positive integer
    The web page's width and length you designed must be positive integers.

Example:

Input: 4
Output: [2, 2]

Explanation: The target area is 4, and all the possible ways to construct it are [1,4], [2,2], [4,1]. 
But according to requirement 2, [1,4] is illegal; according to requirement 3, 
[4,1] is not optimal compared to [2,2]. So the length L is 2, and the width W is 2.

*/

#include <stdio.h>

int
conrect(int a, int r[2])
{
	int i;

	r[0] = r[1] = -1;
	for (i = 1; i <= a / i; i++) {
		if (a % i == 0) {
			r[0] = a / i;
			r[1] = i;
		}
	}
	return r[0] != -1;
}

int
main(void)
{
	int i, r[2];

	for (i = 0; i <= 10000; i++) {
		if (conrect(i, r))
			printf("%d [%d,%d]\n", i, r[0], r[1]);
		else
			printf("%d - no rectangle\n", i);
	}

	return 0;
}
