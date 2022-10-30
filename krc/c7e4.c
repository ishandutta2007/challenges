// Write a private version of scanf analogous to minrpintf from the previous section.

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

int
minscanf(const char *fmt, ...)
{
	const char *p;
	char lfmt[BUFSIZ];
	va_list ap;
	size_t i;
	int n;

	n = 0;
	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			lfmt[i++] = *p;
			continue;
		}

		i = 0;
		lfmt[i++] = '%';
		while (p[1] && !isalpha(p[1])) {
			if (i + 2 < sizeof(lfmt))
				lfmt[i++] = *++p;
			else
				p++;
		}
		lfmt[i++] = p[1];
		lfmt[i] = '\0';

		switch (*++p) {
		case 'c':
		case 's':
			n += scanf(lfmt, va_arg(ap, char *));
			break;

		case 'd':
		case 'i':
			n += scanf(lfmt, va_arg(ap, int *));
			break;

		case 'x':
		case 'X':
		case 'u':
		case 'o':
			n += scanf(lfmt, va_arg(ap, unsigned *));
			break;

		case 'f':
			n += scanf(lfmt, va_arg(ap, float *));
			break;

		default:
			break;
		}
	}
	va_end(ap);
	return n;
}

int
main(void)
{
	int x, y, z;
	float w;
	char buf[80];

	if (minscanf("%d %d %d", &x, &y, &z) == 3)
		printf("%d %d %d\n", x, y, z);

	if (minscanf("%f", &w) == 1)
		printf("%f\n", w);

	if (minscanf("%s", buf) == 1)
		printf("str '%s'\n", buf);

	return 0;
}
