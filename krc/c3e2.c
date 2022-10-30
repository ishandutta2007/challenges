// Write a function escape(s,t) that converts characters like newline and tab
// into visible escape sequences like \n and \t as it copies the string t to s. Use
// a switch. Write a function for the other direction as well, converting escape
// sequences into the real characters.

#include <stdio.h>

char *
escape(char *s, const char *t)
{
	size_t i, j;

	for (i = j = 0; t[i] != '\0'; i++) {
		switch (t[i]) {
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';
	return s;
}

char *
unescape(char *s, const char *t)
{
	size_t i, j;

	for (i = j = 0; t[i] != '\0'; i++) {
		if (t[i] != '\\')
			s[j++] = t[i];
		else {
			switch (t[++i]) {
			case 'n':
				s[j++] = '\n';
				break;
			case 't':
				s[j++] = '\t';
				break;
			default:
				s[j++] = '\\';
				s[j++] = t[i];
				break;
			}
		}
	}
	s[j] = '\0';
	return s;
}

int
main(void)
{
	char s[80];
	printf("%s\n", escape(s, "abc\tdef\n"));
	printf("%s\n", escape(s, "a\ttt\t\t\t\t\t\tbc\t\t\t\txn\n\n\n"));
	printf("%s", unescape(s, "\\n"));
	printf("%s", unescape(s, "a\\tlll\\nhh\n"));
	return 0;
}
