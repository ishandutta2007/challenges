/*

I'd be interested to see who can come up with the fastest function to produce multiplication tables, in the following format:

   1   2   3   4   5   6   7   8   9  10  11  12
   2   4   6   8  10  12  14  16  18  20  22  24
   3   6   9  12  15  18  21  24  27  30  33  36
   4   8  12  16  20  24  28  32  36  40  44  48
   5  10  15  20  25  30  35  40  45  50  55  60
   6  12  18  24  30  36  42  48  54  60  66  72
   7  14  21  28  35  42  49  56  63  70  77  84
   8  16  24  32  40  48  56  64  72  80  88  96
   9  18  27  36  45  54  63  72  81  90  99 108
  10  20  30  40  50  60  70  80  90 100 110 120
  11  22  33  44  55  66  77  88  99 110 121 132
  12  24  36  48  60  72  84  96 108 120 132 144

Use the following template to benchmark your code using a 12-width table, and post your code and the resulting time here.

#!/usr/bin/python
import timeit
cycles = 100000

referencecode = r'''

def multable(width):
  '\n'.join(''.join('{0:4}'.format(x*y) for x in range(1,width+1)) for y in range(1,width+1))

'''

yourcode = r'''

def multable(width):
  pass # Your function here

'''

referencetime = timeit.Timer('multable(12)', setup=referencecode).timeit(number=cycles)
yourtime = timeit.Timer('multable(12)', setup=yourcode).timeit(number=cycles)

print 'Your code completed', referencetime / yourtime, 'times faster than the reference implementation'

*/

#include <stdio.h>
#include <math.h>

void
gen(unsigned n)
{
	unsigned i, j, p;

	p = (n) ? log2(n + 1) : 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			printf("%*u ", p, i * j);
		printf("\n");
	}
}

int
main(void)
{
	gen(12);
	return 0;
}
