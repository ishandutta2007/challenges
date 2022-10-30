/*

From the infinite triangular array of positive integers, suppose we select every 2nd numbers on every 2nd row as shown below:

           [1]
           2 3
        [4] 5 [6]
        7 8 9 10
  [11] 12 [13] 14 [15]
   16 17 18 19 20 21
[22] 23 [24] 25 [26] 27 [28]

The resulting sequence (A185868) is as follows:

1, 4, 6, 11, 13, 15, 22, 24, 26, 28, 37, 39, 41, 43, 45, 56, 58, 60, 62, 64, 66,
79, 81, 83, 85, 87, 89, 91, 106, 108, 110, 112, 114, 116, 118, 120, 137, ...
The task is to output this sequence.

sequence I/O rules apply. You can choose to implement one of the following:

Given the index n (0- or 1-based), output the nth term of the sequence.
Given a positive integer n, output the first n terms of the sequence.
Take no input and output the entire sequence by
printing infinitely or
returning a lazy list or a generator.
Standard code-golf rules apply. The shortest code in bytes wins.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// http://oeis.org/A185868
int
polka(int n)
{
	int a, b, c;
	int i;

	a = b = c = 1;
	for (i = 0; i < n; i++) {
		b -= 1;
		if (b != 0)
			a += 2;
		else {
			a += c + c + 1;
			c += 1;
			b = c;
		}
	}
	return a;
}

int
main(void)
{
	static const int tab[] = {1, 4, 6, 11, 13, 15, 22, 24, 26, 28, 37, 39, 41, 43, 45, 56, 58, 60, 62, 64, 66, 79, 81, 83, 85, 87, 89, 91, 106, 108, 110, 112, 114, 116, 118, 120, 137};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(polka(i) == tab[i]);

	return 0;
}
