/*

In music, notes can be written out in multiple ways (especially for notes on the black keys).
Although these notes are spelled out differently, they still are the same note physically.

Given a musical note, create a function that returns its enharmonic equivalent. The examples below should make this clear.

Notes

    Note names will always be a capital letter followed by either # or b.
    Remember that the note after G is A and vice versa.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
equivalent(const char *s)
{
	static const char *tab[] = {
	    "C#",
	    "Db",
	    "D#",
	    "Eb",
	    "F#",
	    "Gb",
	    "G#",
	    "Ab",
	    "A#",
	    "Bb",
	};
	size_t i;

	for (i = 0; i < nelem(tab); i += 2) {
		if (!strcmp(s, tab[i]))
			return tab[i + 1];
		if (!strcmp(s, tab[i + 1]))
			return tab[i];
	}
	return s;
}

int
main(void)
{
	printf("%s\n", equivalent("C#"));
	printf("%s\n", equivalent("Db"));
	printf("%s\n", equivalent("D#"));
	printf("%s\n", equivalent("Eb"));
	printf("%s\n", equivalent("F#"));
	printf("%s\n", equivalent("Gb"));
	printf("%s\n", equivalent("G#"));
	printf("%s\n", equivalent("Ab"));
	printf("%s\n", equivalent("A#"));
	printf("%s\n", equivalent("Bb"));
	return 0;
}
