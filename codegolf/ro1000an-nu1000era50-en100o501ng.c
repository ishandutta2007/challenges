/*

In the hovertext of this xkcd:

100he100k out th1s 1nno5at4e str1ng en100o501ng 15e been 500e5e50op1ng! 1t's 6rtua100y perfe100t! ...hang on, what's a "virtuacy"?

There's an "encoding" based on replacing runs of roman numerals with their sums. To do this:

Find all runs of at least 1 roman numeral (IVXLCDM)
Replace them with their sums, as numbers
The Roman Numerals are IVXLCDM, corresponding respectively to 1, 5, 10, 50, 100, 500, 1000. You should match them in either case.

For example, if we take encoding, c is the roman numeral 100, so it gets replaced with 100, leaving en100oding. Then, di are both roman numerals, respectively 500 and 1, so it gets replaced with their sum, 501, leaving en100o501ng.

Your challenge is to implement this, given a string. This is code-golf, shortest wins!

Note: the xkcd implements some more complex rules regarding consecutive characters like iv. This can create some ambiguities so I'm going with this simpler version.

Testcases
xkcd -> 10k600
encodingish -> en100o501ng1sh
Hello, World! -> He100o, Wor550!
Potatoes are green -> Potatoes are green
Divide -> 1007e
bacillicidic -> ba904

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
value(int c)
{
	static const int tab[][2] = {
	    {'I', 1},
	    {'V', 5},
	    {'X', 10},
	    {'L', 50},
	    {'C', 100},
	    {'D', 500},
	    {'M', 1000},
	};

	size_t i;

	c = toupper(c);
	for (i = 0; i < nelem(tab); i++) {
		if (c == tab[i][0])
			return tab[i][1];
	}
	return 0;
}

char *
encode(const char *s, char *b)
{
	size_t i, j;
	int v, t;

	i = j = 0;
	t = 0;
	do {
		v = value(s[i]);
		t += v;
		if (!v) {
			if (t) {
				j += sprintf(b + j, "%d", t);
				t = 0;
			}
			b[j++] = s[i];
		}
	} while (s[i++]);

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	encode(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("xkcd", "10k600");
	test("encodingish", "en100o501ng1sh");
	test("Hello, World!", "He100o, Wor550!");
	test("Potatoes are green", "Potatoes are green");
	test("Divide", "1007e");
	test("bacillicidic", "ba904");

	return 0;
}
