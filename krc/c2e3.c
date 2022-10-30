// Write a function that converts a hex string to an integer
#include <stdio.h>
#include <ctype.h>

int
htoi(const char *s)
{
	int h, c, v, n, sgn;
	size_t i;

	sgn = 1;
	for (i = 0; s[i] == '-'; i++)
		sgn = -sgn;

	if (s[i] == '0') {
		i++;
		if (tolower(s[i]) == 'x')
			i++;
	}

	n = 0;
	for (h = 1; h; i++) {
		c = tolower(s[i]);
		if ('0' <= c && c <= '9')
			v = s[i] - '0';
		else if ('a' <= c && c <= 'f')
			v = s[i] - 'a' + 10;
		else {
			h = 0;
			continue;
		}

		n = 16 * n + v;
	}
	if (sgn == -1)
		n = ~n;

	return n;
}

int
main(void)
{
	printf("%#x\n", htoi("-0x2"));
	printf("%#x\n", htoi("0xf"));
	printf("%#x\n", htoi("-0x1"));
	printf("%#x\n", htoi("-0x2"));
	printf("%#x\n", htoi("deadbeef"));
	printf("%#x\n", htoi("p0np0n"));
	printf("%#x\n", htoi("-0x123456"));
	printf("%#x\n", htoi("0xcafebabe"));
	return 0;
}
