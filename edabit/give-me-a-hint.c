/*

Given a sentence, return an array of strings which gradually reveals the next letter in every word at the same time.
Use underscores to hide the remaining letters.

Examples

grantTheHint("Mary Queen of Scots") ➞ [
  "____ _____ __ _____",
  "M___ Q____ o_ S____",
  "Ma__ Qu___ of Sc___",
  "Mar_ Que__ of Sco__",
  "Mary Quee_ of Scot_",
  "Mary Queen of Scots"
]

grantTheHint("The Life of Pi") ➞ [
  "___ ____ __ __",
  "T__ L___ o_ P_",
  "Th_ Li__ of Pi",
  "The Lif_ of Pi",
  "The Life of Pi"
]

Notes

Maintain capitalisation.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char **
hint(const char *s)
{
	size_t i, j, k, n;
	char **p, *q;
	int f;

	n = strlen(s);
	p = calloc(n + 1, sizeof(*p));
	q = calloc((n + 1) * (n + 1), sizeof(*q));
	if (!p || !q)
		goto error;

	for (i = 0; i < n; i++) {
		p[i] = &q[i * (n + 1)];
		for (j = 0; s[j]; j++)
			p[i][j] = (isspace(s[j])) ? s[j] : '_';
	}

	for (i = 1; i < n; i++) {
		f = 0;
		for (j = 0; s[j];) {
			while (isspace(s[j]))
				j++;

			k = 0;
			while (s[j] && !isspace(s[j])) {
				if (k < i)
					p[i][j] = s[j];
				j++;
				k++;
			}

			f |= (i < k);
		}

		if (f == 0)
			break;
	}

	if (0) {
	error:
		free(p);
		free(q);
		p = NULL;
	}
	return p;
}

void
test(const char *s, const char **r, size_t n)
{
	char **p;
	size_t i;

	assert(p = hint(s));

	for (i = 0; i < n; i++) {
		printf("%s\n", p[i]);
		assert(!strcmp(p[i], r[i]));
	}
	printf("\n");

	free(p[0]);
	free(p);
}

int
main(void)
{
	const char *s1[] = {
	    "____ _____ __ _____",
	    "M___ Q____ o_ S____",
	    "Ma__ Qu___ of Sc___",
	    "Mar_ Que__ of Sco__",
	    "Mary Quee_ of Scot_",
	    "Mary Queen of Scots",
	};
	const char *s2[] = {
	    "___ ____ __ __",
	    "T__ L___ o_ P_",
	    "Th_ Li__ of Pi",
	    "The Lif_ of Pi",
	    "The Life of Pi",
	};
	const char *s3[] = {
	    "___ _____ ____",
	    "T__ R____ N___",
	    "Th_ Ri___ Ni__",
	    "The Riv__ Nil_",
	    "The Rive_ Nile",
	    "The River Nile",
	};
	const char *s4[] = {
	    "___ ______ ______",
	    "T__ C_____ P_____",
	    "Th_ Co____ Pu____",
	    "The Col___ Pur___",
	    "The Colo__ Purp__",
	    "The Colou_ Purpl_",
	    "The Colour Purple",
	};
	const char *s5[] = {
	    "___ ______ __ ________",
	    "T__ B_____ o_ H_______",
	    "Th_ Ba____ of Ha______",
	    "The Bat___ of Has_____",
	    "The Batt__ of Hast____",
	    "The Battl_ of Hasti___",
	    "The Battle of Hastin__",
	    "The Battle of Hasting_",
	    "The Battle of Hastings",
	};
	const char *s6[] = {
	    "_______ ___ ___ ____",
	    "A______ a__ t__ W___",
	    "An_____ an_ th_ Wa__",
	    "Ant____ and the Was_",
	    "Ant-___ and the Wasp",
	    "Ant-M__ and the Wasp",
	    "Ant-Ma_ and the Wasp",
	    "Ant-Man and the Wasp",
	};
	const char *s7[] = {
	    "_ _______ _______ __ ______ __ _____",
	    "A b______ s______ i_ a_____ 3_ y____",
	    "A bi_____ se_____ is al____ 32 ye___",
	    "A bil____ sec____ is alm___ 32 yea__",
	    "A bill___ seco___ is almo__ 32 year_",
	    "A billi__ secon__ is almos_ 32 years",
	    "A billio_ second_ is almost 32 years",
	    "A billion seconds is almost 32 years",
	};

	test("Mary Queen of Scots", s1, nelem(s1));
	test("The Life of Pi", s2, nelem(s2));
	test("The River Nile", s3, nelem(s3));
	test("The Colour Purple", s4, nelem(s4));
	test("The Battle of Hastings", s5, nelem(s5));
	test("Ant-Man and the Wasp", s6, nelem(s6));
	test("A billion seconds is almost 32 years", s7, nelem(s7));

	return 0;
}
