// Write the function strend(s,t) which returns 1 if the string t
// occurs at the end of the string s and zero otherwise.

#include <stdio.h>
#include <string.h>

int
strend(const char *s, const char *t)
{
	size_t n, m;

	n = strlen(s);
	m = strlen(t);
	if (m > n)
		return 0;
	return strcmp(s + n - m, t) == 0;
}

int
main(void)
{
	printf("%d\n", strend("abc", "def"));
	printf("%d\n", strend("abc", "bc"));
	printf("%d\n", strend("Hello, World", "ld"));
	printf("%d\n", strend("Daiki", "iki"));
	printf("%d\n", strend("modem", "baudrate"));
	return 0;
}
