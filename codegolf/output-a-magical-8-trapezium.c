/*

Your task is to output a Magical 8 Trapezium:

        1 × 8 + 1 = 9
       12 × 8 + 2 = 98
      123 × 8 + 3 = 987
     1234 × 8 + 4 = 9876
    12345 × 8 + 5 = 98765
   123456 × 8 + 6 = 987654
  1234567 × 8 + 7 = 9876543
 12345678 × 8 + 8 = 98765432
123456789 × 8 + 9 = 987654321

    Output in your chosen language in the fewest bytes possible.
    Note the number of spaces at the start of each line to maintain the trapezium shape.
    Trailing spaces are allowed.
    You can use × or the letter x - whichever you prefer.

*/

#include <stdio.h>

typedef unsigned long long uvlong;

void
trapezium(void)
{
	uvlong i, m, p;

	p = 0;
	m = 8;
	for (i = 1; i <= 9; i++) {
		p = (p * 10) + i;
		printf("%9llu x %llu + %llu = %llu\n", p, m, i, p * m + i);
	}
}

int
main(void)
{
	trapezium();
	return 0;
}
