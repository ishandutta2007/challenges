/*

Julius Caesar protected his confidential information by encrypting it using a cipher.
Caesar's cipher shifts each letter by a number of letters.
If the shift takes you past the end of the alphabet, just rotate back to the front of the alphabet.
In the case of a rotation by 3, w, x, y and z would map to z, a, b and c.

Original alphabet:      abcdefghijklmnopqrstuvwxyz
Alphabet rotated +3:    defghijklmnopqrstuvwxyzabc

Note: The cipher only encrypts letters; symbols, such as -, remain unencrypted.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *
caesar(const char *s, int k)
{
	size_t i;
	char *p;

	p = malloc(strlen(s) + 1);
	if (p == NULL)
		return NULL;

	for (i = 0; s[i]; i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			p[i] = 'A' + ((s[i] - 'A' + k) % 26);
		else if ('a' <= s[i] && s[i] <= 'z')
			p[i] = 'a' + ((s[i] - 'a' + k) % 26);
		else
			p[i] = s[i];
	}
	p[i] = '\0';
	return p;
}

int
main(void)
{
	printf("%s\n", caesar("There's-a-starman-waiting-in-the-sky", 3));
	printf("%s\n", caesar("middle-Outz", 2));
	return 0;
}
