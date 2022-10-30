/*

While bored in high-school (when I was half my current age...), I found that f(x)=xx−1 had some interesting properties, including e.g. that the maximum f for 0≤x is f(e), and that the binding energy per nucleon of an isotope can be approximated as 6×f(x÷21)

...

Anyway, write the shortest function or program that calculates the xth root of x for any number in your language's domain.

Examples cases

For all languages

     -1   >       -1
   ¯0.2   >    -3125
   ¯0.5   >        4
    0.5   >     0.25
      1   >        1
      2   >    1.414
      e   >    1.444 
      3   >    1.442
    100   >    1.047
  10000   >    1.001

For languages that handle complex numbers

   -2   >        -0.7071i
    i   >            4.81         
   2i   >    2.063-0.745i
 1+2i   >   1.820-0.1834i
 2+2i   >   1.575-0.1003i

For languages that handle infinities

-1/∞   >   0    (or ∞ or ̃∞)
   0   >   0    (or 1 or ∞)
 1/∞   >   0
   ∞   >   1
  -∞   >   1

For languages that handle both infinities and complex numbers

 -∞-2i   >   1      (or ̃∞)

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>
#include <complex.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
main(void)
{
	double complex tab[] = {
	    -1.0,
	    -0.2,
	    -0.5,
	    0.5,
	    1.0,
	    2.0,
	    M_E,
	    3.0,
	    100.0,
	    10000.0,

	    -2,
	    I,
	    2 * I,
	    1 + 2 * I,
	    2 + 2 * I,

	    -1 / INFINITY,
	    0.0,
	    1 / INFINITY,
	    INFINITY,
	    -INFINITY,
	    -INFINITY - 2 * I,
	};

	double complex x, r;
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		x = tab[i];
		r = cpow(x, 1 / x);
		printf("%.3f%+.4fi\n", creal(r), cimag(r));
	}

	return 0;
}
