/*

Make a function that encrypts a given input with these steps:

Input: "apple"

Step 1: Reverse the input: "elppa"

Step 2: Replace all vowels using the following chart:

a => 0
e => 1
o => 2
u => 3

# "1lpp0"

Step 3: Add "aca" to the end of the word: "1lpp0aca"

Output: "1lpp0aca"

Notes

All inputs are strings, no uppercases and all output must be strings.

*/

#include <stdio.h>
#include <string.h>

void
rev(char *s, size_t n)
{
	size_t i;
	char t;

	for (i = 0; i < n / 2; i++) {
		t = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = t;
	}
}

char *
encrypt(const char *s, char *d)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		d[i] = s[i];
		if (d[i] == 'a')
			d[i] = '0';
		else if (d[i] == 'e')
			d[i] = '1';
		else if (d[i] == 'o')
			d[i] = '2';
		else if (d[i] == 'u')
			d[i] = '3';
	}
	rev(d, i);
	strcpy(d + i, "aca");
	return d;
}

int
main(void)
{
	char buf[80];

	printf("%s\n", encrypt("apple", buf));
	printf("%s\n", encrypt("banana", buf));
	printf("%s\n", encrypt("karaca", buf));
	printf("%s\n", encrypt("burak", buf));
	printf("%s\n", encrypt("alpaca", buf));
	printf("%s\n", encrypt("hello", buf));
	return 0;
}
