// Revise minprintf to handle more of the other facilities of printf.

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

int
minprintf(const char *fmt, ...)
{
	const char *p;
	char lfmt[BUFSIZ];
	size_t i;
	va_list ap;
	int n;

	n = 0;
	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			n++;
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
			n += printf(lfmt, va_arg(ap, int));
			break;
		case 'd':
		case 'i':
			n += printf(lfmt, va_arg(ap, int));
			break;
		case 'x':
		case 'X':
		case 'u':
		case 'o':
			n += printf(lfmt, va_arg(ap, unsigned));
			break;
		case 'p':
			n += printf(lfmt, va_arg(ap, void *));
			break;
		case 'f':
			n += printf(lfmt, va_arg(ap, double));
			break;
		case 's':
			n += printf(lfmt, va_arg(ap, const char *));
			break;
		default:
			n += printf("%s", lfmt);
			break;
		}
	}
	va_end(ap);

	return n;
}

int
main(void)
{
	minprintf("Hello World!\n");
	minprintf("%d %d %d %d %f %d %f\n", 1, 2, 3, 4, 5.5, 6, 7.2);
	minprintf("%d\n", minprintf("%s %c\n", "char is", 'i'));
	minprintf("%p\n", NULL);
	minprintf("%p\n", main);
	return 0;
}
