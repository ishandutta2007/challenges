/*

Louise joined a social networking site to stay in touch with her friends.
The signup page required her to input a name and a password. However, the password must be strong.
The website considers a password to be strong if it satisfies the following criteria:

Its length is at least 6.
It contains at least one digit.
It contains at least one lowercase English character.
It contains at least one uppercase English character.
It contains at least one special character. The special characters are: !@#$%^&*()-+
She typed a random string of length n in the password field but wasn't sure if it was strong.
Given the string she typed, can you find the minimum number of characters she must add to make her password strong?

Note: Here's the set of types of characters in a form you can paste in your solution:

numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"

*/

#include <stdio.h>
#include <string.h>

int
strongify(const char *s)
{
	const char *number = "0123456789";
	const char *lower = "abcdefghijklmnopqrstuvwxyz";
	const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char *special = "!@#$%^&*()-+";

	size_t i;
	unsigned f, j;
	int n;

	f = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (strchr(number, s[i]))
			f |= 0x1;
		else if (strchr(lower, s[i]))
			f |= 0x2;
		else if (strchr(upper, s[i]))
			f |= 0x4;
		else if (strchr(special, s[i]))
			f |= 0x8;
	}

	n = 0;
	for (j = 0; j < 4; j++)
		n += !(f & (1 << j));

	if (i + n < 6)
		n += 6 - (i + n);

	return n;
}

int
main(void)
{
	printf("%d\n", strongify("Ab1"));
	printf("%d\n", strongify("#HackerRank"));
	printf("%d\n", strongify("#1AbDD"));
	printf("%d\n", strongify("hello"));
	printf("%d\n", strongify("helloABC1"));
	printf("%d\n", strongify(""));
	return 0;
}
