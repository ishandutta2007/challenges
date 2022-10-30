/*

Create a function that flips M's to W's (all uppercase).
Examples

wumbo("I LOVE MAKING CHALLENGES") ➞ "I LOVE WAKING CHALLENGES"

wumbo("MEET ME IN WARSAW") ➞ "WEET WE IN WARSAW"

wumbo("WUMBOLOGY") ➞ "WUWBOLOGY"

*/

#include <assert.h>
#include <string.h>

char *
wumbo(char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] == 'M')
			s[i] = 'W';
	}
	return s;
}

int
main(void)
{
	char s1[] = "I LOVE MAKING CHALLENGES";
	char t1[] = "I LOVE WAKING CHALLENGES";

	char s2[] = "MEET ME IN WARSAW";
	char t2[] = "WEET WE IN WARSAW";

	char s3[] = "WUMBOLOGY";
	char t3[] = "WUWBOLOGY";

	char s4[] = "WHAT DO YOU MEAN WE'RE OUT OF MONEY";
	char t4[] = "WHAT DO YOU WEAN WE'RE OUT OF WONEY";

	char s5[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char t5[] = "ABCDEFGHIJKLWNOPQRSTUVWXYZ";

	char s6[] = "1 WUMBO 2 WUMBO 3 WUMBO 4";
	char t6[] = "1 WUWBO 2 WUWBO 3 WUWBO 4";

	assert(!strcmp(wumbo(s1), t1));
	assert(!strcmp(wumbo(s2), t2));
	assert(!strcmp(wumbo(s3), t3));
	assert(!strcmp(wumbo(s4), t4));
	assert(!strcmp(wumbo(s5), t5));
	assert(!strcmp(wumbo(s6), t6));

	return 0;
}
