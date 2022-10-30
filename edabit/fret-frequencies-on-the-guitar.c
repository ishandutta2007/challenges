/*

Create a function that takes a number of a guitar string and the number of the fret and returns the corresponding frequency of the note.

    Check the Resources Tab, for the correct frequencies per string.
    The formula to calculate the frequency is: String Frequency * 2^(fret/12).
    Round the frequency to the nearest hundreth.
    For this challenge, we use "Standard Tuning".

So, one fret = a semitone = a half step. From D to D♯ for instance.

*/

#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
fretfreq(unsigned s, unsigned f)
{
	// https://en.wikipedia.org/wiki/Guitar_tunings
	// E2–A2–D3–G3–B3–E4
	static const double tab[] = {
	    329.63,
	    246.94,
	    196.00,
	    146.83,
	    110.00,
	    82.41,
	};

	if (!(1 <= s && s <= nelem(tab)))
		return 0;

	return tab[s - 1] * pow(2, f * 1.0 / 12);
}

int
main(void)
{
	printf("%.2f\n", fretfreq(3, 21));
	printf("%.2f\n", fretfreq(3, 15));
	printf("%.2f\n", fretfreq(6, 17));
	printf("%.2f\n", fretfreq(5, 12));
	printf("%.2f\n", fretfreq(2, 5));
	printf("%.2f\n", fretfreq(3, 9));
	printf("%.2f\n", fretfreq(1, 16));
	printf("%.2f\n", fretfreq(1, 4));
	printf("%.2f\n", fretfreq(3, 16));
	printf("%.2f\n", fretfreq(4, 6));
	printf("%.2f\n", fretfreq(2, 13));
	printf("%.2f\n", fretfreq(6, 12));
	printf("%.2f\n", fretfreq(5, 16));
	printf("%.2f\n", fretfreq(5, 19));
	printf("%.2f\n", fretfreq(4, 0));
	printf("%.2f\n", fretfreq(2, 6));
	printf("%.2f\n", fretfreq(3, 9));
	printf("%.2f\n", fretfreq(3, 5));
	printf("%.2f\n", fretfreq(5, 18));
	printf("%.2f\n", fretfreq(2, 23));
	printf("%.2f\n", fretfreq(2, 16));
	printf("%.2f\n", fretfreq(4, 6));
	printf("%.2f\n", fretfreq(4, 9));
	printf("%.2f\n", fretfreq(5, 8));
	printf("%.2f\n", fretfreq(3, 1));
	printf("%.2f\n", fretfreq(5, 17));
	printf("%.2f\n", fretfreq(6, 18));
	printf("%.2f\n", fretfreq(3, 23));
	printf("%.2f\n", fretfreq(6, 14));
	printf("%.2f\n", fretfreq(1, 2));

	return 0;
}
