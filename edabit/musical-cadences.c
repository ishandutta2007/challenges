/*

In music, cadences act as punctuation in musical phrases, and help to mark the end of phrases. Cadences are the two chords at the end of a phrase. The different cadences are as follows:

    V followed by I is a Perfect Cadence
    IV followed by I is a Plagal Cadence
    V followed by Any chord other than I is an Interrupted Cadence
    Any chord followed by V is an Imperfect Cadence

Create a function where given a chord progression as a list, return the type of cadence the phrase ends on.

Notes

    Return strings all in lowercase.
    Only focus on the last two chords of a progression.
    Return "no cadence" if none of the criterea match up.
    I is a capital i not a lowercase L.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
cadence(const char **s, size_t n)
{
	if (n < 2)
		return "no cadence";

	if (!strcmp(s[n - 1], "V"))
		return "imperfect";

	if (!strcmp(s[n - 2], "V"))
		return (!strcmp(s[n - 1], "I")) ? "perfect" : "interrupted";

	if (!strcmp(s[n - 2], "IV") && !strcmp(s[n - 1], "I"))
		return "plagal";

	return "no cadence";
}

int
main(void)
{
	const char *c1[] = {"I", "IV", "V"};
	const char *c2[] = {"ii", "V", "I"};
	const char *c3[] = {"I", "IV", "I", "V", "vi"};
	const char *c4[] = {"I", "IV", "I", "V", "IV"};
	const char *c5[] = {"I", "III", "IV", "V"};
	const char *c6[] = {"I", "IV", "I"};
	const char *c7[] = {"V", "IV", "I"};
	const char *c8[] = {"V", "IV", "V", "I"};
	const char *c9[] = {"V", "IV", "V", "I", "vi"};
	const char *c10[] = {"V", "IV", "V", "III", "vi"};

	printf("%s\n", cadence(c1, nelem(c1)));
	printf("%s\n", cadence(c2, nelem(c2)));
	printf("%s\n", cadence(c3, nelem(c3)));
	printf("%s\n", cadence(c4, nelem(c4)));
	printf("%s\n", cadence(c5, nelem(c5)));
	printf("%s\n", cadence(c6, nelem(c6)));
	printf("%s\n", cadence(c7, nelem(c7)));
	printf("%s\n", cadence(c8, nelem(c8)));
	printf("%s\n", cadence(c9, nelem(c9)));
	printf("%s\n", cadence(c10, nelem(c10)));

	return 0;
}
