// Write a pointer version of the function strcat that we showed in Chapter 2:
// strcat(s,t) copies the string t to the end of s.
#include <stdio.h>

char *
xstrcat(char *s, const char *t)
{
	char *p;

	p = s;
	while (*p)
		p++;
	while ((*p++ = *t++))
		;
	return s;
}

int
main(void)
{
	char buf[80] = {0};

	printf("%s\n", xstrcat(buf, "hello"));
	printf("%s\n", xstrcat(buf, ","));
	printf("%s\n", xstrcat(buf, " world!"));
	printf("%s\n", xstrcat(buf, " goodbye"));
	printf("%s\n", xstrcat(buf, ","));
	printf("%s\n", xstrcat(buf, " world."));
	return 0;
}
