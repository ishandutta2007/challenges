// Rewrite appropriate programs from earlier chapters and exercises with pointers
// instead of array indexing. Good possibilities include getline (Chapters 1 and
// 4) atoi and their variants (Chapters 2, 3. and 4), reverse (Chapter
// 3), and strindex and getop (Chapter 4).

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
getline(char *s, int lim)
{
	char *t, c;

	t = s;
	c = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
	return s - t;
}

int
xatoi(const char *s)
{
	int n, sgn;

	while (isspace(*s))
		s++;
	sgn = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	for (n = 0; isdigit(*s); s++)
		n = 10 * n + *s - '0';
	return sgn * n;
}

double
xatof(const char *s)
{
	double v, p;
	int sgn;

	while (isspace(*s))
		s++;
	sgn = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	for (v = 0.0; isdigit(*s); s++)
		v = 10 * v + (*s - '0');
	if (*s == '.')
		s++;
	for (p = 1; isdigit(*s); s++) {
		v = 10 * v + (*s - '0');
		p *= 10;
	}
	return sgn * v / p;
}

void
reverse(char *s)
{
	char *t;
	int c;

	t = s + strlen(s) - 1;
	while (s < t) {
		c = *s;
		*s = *t;
		*t = c;
		s++;
		t--;
	}
}

char *
itoa(int n, char *s)
{
	char *t;
	int sgn;

	t = s;
	sgn = n;
	if (n < 0)
		n = -n;
	do {
		*s++ = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sgn < 0)
		*s++ = '-';
	*s = '\0';
	reverse(t);
	return t;
}

int
strindex(char *s, char *t)
{
	char *b, *p, *r;

	b = s;
	for (; *s; s++) {
		for (p = s, r = t; *r && *p == *r; p++, r++)
			;
		if (r > t && *r == '\0')
			return s - b;
	}
	return -1;
}

#define NUMBER '0'

int
getop(char *s)
{
	int c;

	while ((*s = c = fgetc(stdin)) == ' ' || c == '\t')
		;

	*(s + 1) = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	if (isdigit(c)) {
		while (isdigit(*++s = c = fgetc(stdin)))
			;
	}
	if (c == '.') {
		while (isdigit(*++s = c = fgetc(stdin)))
			;
	}
	*s = '\0';
	if (c != EOF)
		ungetc(c, stdin);
	return NUMBER;
}

int
main(void)
{
	char buf[80];
	getline(buf, sizeof(buf));
	printf("%s", buf);
	printf("%d\n", xatoi("123564"));
	printf("%f\n", xatof("12.4325"));
	printf("%s\n", itoa(245, buf));
	printf("%d\n", strindex("sureg", "reg"));
	return 0;
}
