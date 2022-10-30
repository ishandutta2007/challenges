/*

You run a political website, and have determined that people have a better intuitive understanding when the chance of winning or losing an election is expressed as a ratio ("5 in 7") than when it is expressed as a percentage ("71%").

But you also don't want to display confusing ratios like "58 in 82", you'd like them to be more easily understood, even if they aren't quite as precise.

So, given a percentage between 0.1% and 99.9%, return the closest "easy-to-understand" ratio "x in y", using the following rules:

Most values (see exceptions below) should return the closest ratio out of 10 or lower. 55% should return "5 in 9", not "11 in 20".
Ratios should be reduced to their lowest terms. 65% should return "2 in 3", not "4 in 6".
Values under 10% should return the closest ratio of the form "1 in n" where n is one of (10,12,15,20,30,40,50,60,70,80,90,100). For example, 6% should return "1 in 15".
Values over 90% should return the closest ratio of the form "n-1 in n" where n is one of (10,12,15,20,30,40,50,60,70,80,90,100). For example, 98.7% should return "79 in 80".
Values under 1% should return "<1 in 100"
Values over 99% should return ">99 in 100"
Or, to think about it another way, your program should return the closest ratio from the following possible outputs (I've included their approximate values for your convenience):

<1 in 100
 1 in 100  = 1.00%
 1 in 90   = 1.11%
 1 in 80   = 1.25%
 1 in 70   = 1.43%
 1 in 60   = 1.67%
 1 in 50   = 2.00%
 1 in 40   = 2.50%
 1 in 30   = 3.33%
 1 in 20   = 5.00%
 1 in 15   = 6.67%
 1 in 12   = 8.33%
 1 in 10   = 10.00%
 1 in 9    = 11.11%
 1 in 8    = 12.50%
 1 in 7    = 14.29%
 1 in 6    = 16.67%
 1 in 5    = 20.00%
 2 in 9    = 22.22%
 1 in 4    = 25.00%
 2 in 7    = 28.57%
 3 in 10   = 30.00%
 1 in 3    = 33.33%
 3 in 8    = 37.50%
 2 in 5    = 40.00%
 3 in 7    = 42.86%
 4 in 9    = 44.44%
 1 in 2    = 50.00%
 5 in 9    = 55.56%
 4 in 7    = 57.14%
 3 in 5    = 60.00%
 5 in 8    = 62.50%
 2 in 3    = 66.67%
 7 in 10   = 70.00%
 5 in 7    = 71.43%
 3 in 4    = 75.00%
 7 in 9    = 77.78%
 4 in 5    = 80.00%
 5 in 6    = 83.33%
 6 in 7    = 85.71%
 7 in 8    = 87.50%
 8 in 9    = 88.89%
 9 in 10   = 90.00%
 11 in 12  = 91.67%
 14 in 15  = 93.33%
 19 in 20  = 95.00%
 29 in 30  = 96.67%
 39 in 40  = 97.50%
 49 in 50  = 98.00%
 59 in 60  = 98.33%
 69 in 70  = 98.57%
 79 in 80  = 98.75%
 89 in 90  = 98.89%
 99 in 100 = 99.00%
>99 in 100
Other stipulations:

Numeric input can be in the range of 0.1 to 99.9 or in the range of 0.001 to 0.999, whichever is more convenient. You must handle at least 3 significant digits.
You must output a ratio ("3 in 4"), not the equivalent fraction ("3/4").
If there are two ratios equally close to the input, your program can return either one. 7.5% could return "1 in 12" or "1 in 15".
Leading/trailing white space and/or new lines are fine
Examples:

Input  :   Output
 0.5   :  <1 in 100
 1.0   :   1 in 100
 1.5   :   1 in 70
 7.5   :   1 in 15  or  1 in 12 (either is acceptable)
 9.2   :   1 in 10
13.1   :   1 in 8
29.2   :   2 in 7
29.3   :   3 in 10
52.7   :   1 in 2
52.8   :   5 in 9
72.0   :   5 in 7
73.9   :   3 in 4
88.8   :   8 in 9
90.8   :   9 in 10
94.2   :  19 in 20
98.7   :  79 in 80
98.9   :  89 in 90
99.0   :  99 in 100
99.1   : >99 in 100
This is a code-golf challenge, shortest code in each language wins.

(Similar to, but not duplicate of: Convert a decimal to a fraction, Closest fraction, Approximate floating point number with n-digit precision)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
ratio(double p, char *b)
{
	static const int tab[][2] = {
	    {1, 100},
	    {1, 90},
	    {1, 80},
	    {1, 70},
	    {1, 60},
	    {1, 50},
	    {1, 40},
	    {1, 30},
	    {1, 20},
	    {1, 15},
	    {1, 12},
	    {1, 10},
	    {1, 9},
	    {1, 8},
	    {1, 7},
	    {1, 6},
	    {1, 5},
	    {2, 9},
	    {1, 4},
	    {2, 7},
	    {3, 10},
	    {1, 3},
	    {3, 8},
	    {2, 5},
	    {3, 7},
	    {4, 9},
	    {1, 2},
	    {5, 9},
	    {4, 7},
	    {3, 5},
	    {5, 8},
	    {2, 3},
	    {7, 10},
	    {5, 7},
	    {3, 4},
	    {7, 9},
	    {4, 5},
	    {5, 6},
	    {6, 7},
	    {7, 8},
	    {8, 9},
	    {9, 10},
	    {11, 12},
	    {14, 15},
	    {19, 20},
	    {29, 30},
	    {39, 40},
	    {49, 50},
	    {59, 60},
	    {69, 70},
	    {79, 80},
	    {89, 90},
	    {99, 100},
	};

	double x, y, d, m;
	size_t i, n;

	if (p < 1) {
		sprintf(b, "<1 in 100");
		return b;
	}

	if (p > 99) {
		sprintf(b, ">99 in 100");
		return b;
	}
	p /= 100;

	m = DBL_MAX;
	for (i = 0; i < nelem(tab); i++) {
		x = tab[i][0];
		y = tab[i][1];
		d = fabs(p - x / y);
		if (d < m) {
			m = d;
			n = i;
		}
	}

	sprintf(b, "%d in %d", tab[n][0], tab[n][1]);
	return b;
}

void
test(double p, const char *r)
{
	char b[128];

	ratio(p, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(0.5, "<1 in 100");
	test(1.0, "1 in 100");
	test(1.5, "1 in 70");
	test(7.5, "1 in 15");
	test(9.2, "1 in 10");
	test(13.1, "1 in 8");
	test(29.2, "2 in 7");
	test(29.3, "3 in 10");
	test(52.7, "1 in 2");
	test(52.8, "5 in 9");
	test(72.0, "5 in 7");
	test(73.9, "3 in 4");
	test(88.8, "8 in 9");
	test(90.8, "9 in 10");
	test(94.2, "19 in 20");
	test(98.7, "79 in 80");
	test(98.9, "89 in 90");
	test(99.0, "99 in 100");
	test(99.1, ">99 in 100");

	return 0;
}
