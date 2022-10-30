#include <stdio.h>

size_t
xstrlen(const char *s)
{
	size_t n;
	for (n = 0; s[n]; n++)
		;
	return n;
}

char *
xstrncpy(char *s, const char *t, size_t n)
{
	char *p;

	p = s;
	for (; *t && n > 0; n--)
		*s++ = *t++;
	for (; n > 0; n--)
		*s++ = '\0';
	return p;
}

char *
xstrncat(char *s, const char *t, size_t n)
{
	return xstrncpy(s + xstrlen(s), t, n);
}

int
xstrncmp(const char *s, const char *t, size_t n)
{
	for (; *s == *t; s++, t++) {
		if (n > 0)
			n--;
		if (*s == '\0' || n == 0)
			return 0;
	}
	return *s - *t;
}

int
main(void)
{
	char buf[80] = {0};

	printf("%d\n", xstrncmp("hello", "world", 80));
	printf("%d\n", xstrncmp("bell", "bell", 80));
	printf("%d\n", xstrncmp("bell", "labs", 80));

	xstrncat(buf, "onto", 4);
	xstrncat(buf, "logy", 4);
	xstrncat(buf, "ism", 3);
	printf("%s\n", buf);
	return 0;
}
