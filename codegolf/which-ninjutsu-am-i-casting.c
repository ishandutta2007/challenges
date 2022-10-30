/*

In the MMORPG Final Fantasy XIV, the Ninja class has the ability to use combinations of up to three handsigns (Ten, Chi and Jin) to perform a variety of ninjutsu skills.

The skill you cast depends on the last sign used, and using two or more of the same sign makes the ninjutsu skill fail and puts a little bunny on your head.

Challenge
Your job is to take up to three handsigns as input, and output the name of the ninjutsu skill this combination does. Of course, since this is code-golf, the goal is to make your code as short as possible!

Input
The program should take between 1 and 3 handsigns as input via STDIN or function arguments. You can use any kind of input format you prefer.

Example inputs:

TCJ
Ten Chi Jin
["T", "C", "J"]
["Ten", "Chi", "Jin"]
Output
The program should output the name (in title case) of the ninjutsu skill you get from the handsigns sent to it via input. Here's a table of each combination and their resulting skill.

Mudra table:

| Handsigns                     | Ninjutsu Skill |
|-------------------------------|----------------|
| Any one                       | Fuma Shuriken  |
| Any one + Ten                 | Katon          |
| Any one + Chi                 | Raiton         |
| Any one + Jin                 | Hyoton         |
| Any two + Ten                 | Huton          |
| Any two + Chi                 | Doton          |
| Any two + Jin                 | Suiton         |
| Contains two of the same sign | Bunny          |
Bunny takes precedence over any other ninjutsu.

Examples
TCJ                -> Suiton
J                  -> Fuma Shuriken
['Ten', 'Chi']     -> Raiton
"Jin" "Jin" "Ten"  -> Bunny

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
match(const char *s, const char *p)
{
	size_t i;

	for (i = 0; s[i] && p[i]; i++) {
		if (p[i] == '?')
			continue;

		if (p[i] != s[i])
			return false;
	}
	return (p[i] == '\0' && s[i] == '\0');
}

const char *
ninjutsu(const char *s)
{
	static const char *tab[][2] = {
	    {"TT?", "Bunny"},
	    {"T?T", "Bunny"},
	    {"CC?", "Bunny"},
	    {"C?C", "Bunny"},
	    {"JJ?", "Bunny"},
	    {"J?J", "Bunny"},
	    {"T", "Fuma Shuriken"},
	    {"C", "Fuma Shuriken"},
	    {"J", "Fuma Shuriken"},
	    {"?T", "Katon"},
	    {"?C", "Raiton"},
	    {"?J", "Hyoton"},
	    {"??T", "Huton"},
	    {"??C", "Doton"},
	    {"??J", "Suiton"},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (match(s, tab[i][0]))
			return tab[i][1];
	}
	return "";
}

void
test(const char *s, const char *r)
{
	const char *p;

	p = ninjutsu(s);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("TCJ", "Suiton");
	test("J", "Fuma Shuriken");
	test("TC", "Raiton");
	test("JJT", "Bunny");
	test("CT", "Katon");
	test("JCT", "Huton");
	test("CTJ", "Suiton");
	test("TTJ", "Bunny");
	test("C", "Fuma Shuriken");
	test("JT", "Katon");

	return 0;
}
