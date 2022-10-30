/*

How many words contained in this dictionary have their letters in alphabetical order? So, for instance the letters in "ghost" and "bee" is in alphabetical order, but the letters in "cab" are not.

Thanks to EvanHahn for suggesting this problem at r/dailyprogrammer_ideas!

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef long long vlong;

int
sorted(const char *s)
{
	size_t i;

	for (i = 0; s[i] && s[i + 1]; i++) {
		if (s[i] > s[i + 1])
			return 0;
	}
	return 1;
}

char *
trimspace(char *p)
{
	size_t i;

	while (isspace(*p))
		p++;

	i = 0;
	while (p[i])
		i++;
	while (i > 0 && isspace(p[i - 1]))
		p[--i] = '\0';

	return p;
}

vlong
alphawords(const char *name)
{
	FILE *fp;
	char b[1024];
	char *p;
	vlong c;

	fp = fopen(name, "rb");
	if (!fp)
		return -1;

	c = 0;
	while (fgets(b, sizeof(b), fp)) {
		p = trimspace(b);
		c += sorted(p);
	}

	fclose(fp);
	return c;
}

int
main(void)
{
	printf("%lld\n", alphawords("enable1.txt"));

	return 0;
}
