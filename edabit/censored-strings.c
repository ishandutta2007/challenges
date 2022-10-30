/*

Someone has attempted to censor my strings by replacing every vowel with a *, l*k* th*s.
Luckily, I've been able to find the vowels that were removed.

Given a censored string and a string of the censored vowels,
return the original uncensored string.

Notes

The number of vowels will match the number of * characters in the censored string.

*/

#include <stdio.h>
#include <string.h>

char *
uncensor(char *s, const char *v)
{
	char *p;

	p = s;
	while ((p = strchr(p, '*'))) {
		if (*v != '\0')
			*p++ = *v++;
		else
			break;
	}
	return s;
}

int
main(void)
{
	char s1[] = "Wh*r* d*d my v*w*ls g*?";
	char s2[] = "abcd";
	char s3[] = "*PP*RC*S*";
	char s4[] = "Ch**s*, Gr*mm*t -- ch**s*";
	char s5[] = "*l*ph*nt";

	printf("%s\n", uncensor(s1, "eeioeo"));
	printf("%s\n", uncensor(s2, ""));
	printf("%s\n", uncensor(s3, "UEAE"));
	printf("%s\n", uncensor(s4, "eeeoieee"));
	printf("%s\n", uncensor(s5, "Eea"));

	return 0;
}
