/*
Joseph and Jane are making a contest for apes.
During the process, they have to communicate frequently with each other.
Since they are not completely human, they cannot speak properly.
They have to transfer messages using postcards of small sizes.
To save space on the small postcards, they devise a string compression algorithm:

If a character, ch, occurs (n>1)times in a row, then it will be represented by {ch}{n}, where {x} is the value of x.
For example, if the substring is a sequence of 4 'a' ("aaaa"), it will be represented as "a4".

If a character, ch, occurs exactly one time in a row, then it will be simply represented as
{ch}. For example, if the substring is "a", then it will be represented as "a".

Help Joseph to compress a message, msg.
*/
#include <stdio.h>

char *
compress(char *dst, const char *src)
{
	size_t i, j, k;

	i = 0;
	j = 0;
	k = 1;
	for (;;) {
		if (k > 1) {
			i += sprintf(&dst[i], "%zu", k);
			k = 1;
		}
		dst[i++] = src[j];
		if (src[j] == '\0')
			break;

		while (dst[i - 1] == src[++j])
			k++;
	}
	return dst;
}

int
main(void)
{
	char a[] = "abcaaabbb";
	char b[sizeof(a)];
	printf("%s\n", compress(b, a));

	char c[] = "abcd";
	char d[sizeof(c)];
	printf("%s\n", compress(d, c));

	char e[] = "aaabaaaaccaaaaba";
	char f[sizeof(e)];
	printf("%s\n", compress(f, e));

	char g[] = "a";
	char h[sizeof(g)];
	printf("%s\n", compress(h, g));

	return 0;
}
