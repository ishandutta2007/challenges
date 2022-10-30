/*

Not everyone probably knows that Chef has younder brother Jeff. Currently Jeff learns to read.

He knows some subset of the letter of Latin alphabet. In order to help Jeff to study, Chef gave him a book with the text consisting of N words.
Jeff can read a word iff it consists only of the letters he knows.

Now Chef is curious about which words his brother will be able to read, and which are not. Please help him!

*/
#include <stdio.h>
#include <string.h>

const char *
know(const char *d, const char *s)
{
	char w[256];
	size_t i;

	memset(w, 0, sizeof(w));
	for (i = 0; d[i]; i++)
		w[d[i] & 0xff] = 1;
	for (i = 0; s[i]; i++) {
		if (!w[s[i] & 0xff])
			return "No";
	}
	return "Yes";
}

int
main(void)
{
	printf("%s\n", know("act", "cat"));
	printf("%s\n", know("act", "dog"));
	return 0;
}
