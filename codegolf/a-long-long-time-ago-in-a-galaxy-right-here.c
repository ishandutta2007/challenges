/*

Task

Given a positive integer return the geologic era and period it was that many million years ago.
Input/output

The input is a string or integer; the output is a string. Eras and periods are separated by slashes (/). Input will always be between 0 and 542 inclusive
Data

The possible outputs for eras and periods and their corresponding time periods (in millions of years) are:

    Cenozoic 0 - 66
        Quaternary 0 - 3
        Neogene 4 - 23
        Paleogene 24 - 66
    Mesozoic 67 - 252
        Cretaceous 67 - 145
        Jurassic 146 - 201
        Triassic 202 - 252
    Paleozoic 253 - 542
        Permian 253 - 299
        Carboniferous 300 - 359
        Devonian 360 - 419
        Silurian 420 - 444
        Ordovician 445 - 485
        Cambrian 486 - 542

Submissions will be scored by byte count. Lowest byte count wins.
Test cases

314 -> Paleozoic/Carboniferous
0 -> Cenozoic/Quaternary
542 -> Paleozoic/Cambrian
100 -> Mesozoic/Cretaceous

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	int start;
	int end;
} Epoch;

char *
epoch(int y, char *b, size_t n)
{
	static const Epoch periods[] = {
	    {"Cenozoic", 0, 66},
	    {"Mesozoic", 67, 252},
	    {"Paleozoic", 253, 542},
	};
	static const Epoch eras[][8] = {
	    {{"Quaternary", 0, 3}, {"Neogene", 4, 23}, {"Paleogene", 24, 66}},
	    {{"Cretaceous", 67, 145}, {"Jurassic", 146, 201}, {"Triassic", 202, 252}},
	    {{"Permian", 253, 299}, {"Carboniferous", 300, 359}, {"Devonian", 360, 419}, {"Silurian", 420, 444}, {"Ordovician", 445, 485}, {"Cambrian", 486, 542}},
	};

	const Epoch *p, *e;
	size_t i, j;

	for (i = 0; i < nelem(periods); i++) {
		p = &periods[i];
		if (p->start <= y && y <= p->end)
			break;
	}
	if (i == nelem(periods))
		return NULL;

	for (j = 0; j < nelem(eras[i]); j++) {
		e = &eras[i][j];
		if (e->name[0] == '\0')
			return NULL;

		if (e->start <= y && y <= e->end)
			break;
	}
	snprintf(b, n, "%s/%s", p->name, e->name);
	return b;
}

void
test(int y, const char *r)
{
	char b[128];

	assert(epoch(y, b, sizeof(b)));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(314, "Paleozoic/Carboniferous");
	test(0, "Cenozoic/Quaternary");
	test(542, "Paleozoic/Cambrian");
	test(100, "Mesozoic/Cretaceous");
	test(253, "Paleozoic/Permian");

	return 0;
}
