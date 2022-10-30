// Write the function strrindex(s,t), which returns the position of the
// rightmost occurrence of t in s, or -1 if there is none.
#include <stdio.h>
#include <unistd.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

ssize_t
strrindex(const char *s, int t)
{
	ssize_t p;
	size_t i;

	p = -1;
	for (i = 0; s[i]; i++) {
		if (s[i] == t)
			p = i;
	}
	return p;
}

int
main(void)
{
	static const struct {
		const char *str;
		int ch;
	} tab[] = {
	    {"Hello world", 'o'},
	    {"This string is littered with iiiis", 'i'},
	    {"No 'see' letters in here", 'c'},
	    {"cqabcdef", 'b'},
	    {"QQQQ", 'Q'},
	};
	size_t i;

	for (i = 0; i < nelem(tab); i++)
		printf("strrindex(\"%s\", '%c') -> %zd\n", tab[i].str, tab[i].ch, strrindex(tab[i].str, tab[i].ch));
	return 0;
}
