/*

Musical instruments have a range of notes to play, some instruments having a much larger range than others.

Given the following ranges for the instrument, create a function that returns true if a given note is within a given instrument's range. Otherwise, return false.

Instrument	Range
Piccolo	D4-C7
Tuba	D1-F4
Guitar	E3-E6
Piano	A0-C8
Violin	G3-A7
Examples

instrumentRange("Piccolo", "A3") ➞ false

instrumentRange("Violin", "G6") ➞ true

instrumentRange("Piano", "C8") ➞ true

Notes

    Tests will only include natural notes (i.e. you will only deal with letters and numbers, no special characters).
    The musical scale follows this pattern: ... A1, B1, C1, D1, E1, F1, G1, A2, B2 ...
    You don't need to worry about invalid inputs.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	char start[4];
	char end[4];
} Instrument;

int
conv(const char *n)
{
	if (!('A' <= n[0] && n[0] <= 'G'))
		return -1;
	return (n[0] - 'A') + 7 * atoi(n + 1);
}

bool
instrument(const char *s, const char *n)
{
	static const Instrument instruments[] = {
	    {"Piccolo", "D4", "C7"},
	    {"Tuba", "D1", "F4"},
	    {"Guitar", "E3", "E6"},
	    {"Piano", "A0", "C8"},
	    {"Violin", "G3", "A7"},
	};

	const Instrument *p;
	int a, b, v;
	size_t i;

	for (i = 0; i < nelem(instruments); i++) {
		p = instruments + i;
		if (!strcmp(p->name, s))
			break;
	}
	if (i >= nelem(instruments))
		return false;

	a = conv(p->start);
	b = conv(p->end);
	v = conv(n);
	return v >= 0 && (a <= v && v <= b);
}

int
main(void)
{
	assert(instrument("Piccolo", "A3") == false);
	assert(instrument("Violin", "G6") == true);
	assert(instrument("Piano", "C8") == true);
	assert(instrument("Piano", "C9") == false);
	assert(instrument("Tuba", "C8") == false);
	assert(instrument("Guitar", "F4") == true);
	assert(instrument("Guitar", "C4") == true);
	assert(instrument("Piccolo", "F4") == true);
	assert(instrument("Tuba", "F6") == false);

	return 0;
}
