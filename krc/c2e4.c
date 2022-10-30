// Write an alternate version of squeeze(s1,s2) that deletes each character in the string s1 that matches any character in the string s2.
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
squeeze(char *s1, const char *s2)
{
	size_t i, j;

	for (i = j = 0; s1[i]; i++) {
		if (!strchr(s2, s1[i]))
			s1[j++] = s1[i];
	}
	s1[j] = '\0';

	return s1;
}

int
main(void)
{
	const char *lhs[] = {
	    "",
	    "a",
	    "antidisestablishmentarianism",
	    "beautifications",
	    "characteristically",
	    "deterministically",
	    "electroencephalography",
	    "familiarisation",
	    "gastrointestinal",
	    "heterogeneousness",
	    "incomprehensibility",
	    "justifications",
	    "knowledgeable",
	    "lexicographically",
	    "microarchitectures",
	    "nondeterministically",
	    "organizationally",
	    "phenomenologically",
	    "quantifications",
	    "representationally",
	    "straightforwardness",
	    "telecommunications",
	    "uncontrollability",
	    "vulnerabilities",
	    "wholeheartedly",
	    "xylophonically",
	    "youthfulness",
	    "zoologically",
	};
	const char *rhs[] = {
	    "",
	    "a",
	    "the",
	    "quick",
	    "brown",
	    "dog",
	    "jumps",
	    "over",
	    "lazy",
	    "fox",
	    "get",
	    "rid",
	    "of",
	    "windows",
	    "and",
	    "install",
	    "linux",
	    "plan9",
	};

	char buf[128];
	size_t i, j;

	for (i = 0; i < nelem(lhs); i++) {
		for (j = 0; j < nelem(rhs); j++) {
			snprintf(buf, sizeof(buf), "%s", lhs[i]);
			printf("squeeze(\"%s\", \"%s\") -> \"%s\"\n", lhs[i], rhs[j], squeeze(buf, rhs[j]));
		}
	}

	return 0;
}
