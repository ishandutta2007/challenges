/*

Create a function that takes in a sentence and returns the average length of each word in that sentence.
Round your result to two decimal places.

Notes

Ignore punctuation when counting the length of a word.

*/

#include <stdio.h>
#include <ctype.h>

double
awl(const char *s)
{
	size_t i, j, n, m;

	n = 0;
	m = 0;
	i = 0;
	for (;;) {
		j = 0;
		while (s[i] && !isspace(s[i])) {
			if (!ispunct(s[i]))
				j++;
			i++;
		}
		if (j) {
			n += j;
			m += 1;
		}

		if (s[i] == '\0')
			break;

		while (isspace(s[i]))
			i++;
	}

	if (m == 0)
		return 0;

	return n * 1.0 / m;
}

int
main(void)
{
	printf("%.2f\n", awl("A B C."));
	printf("%.2f\n", awl("What a gorgeous day."));
	printf("%.2f\n", awl("Dude, this is so awesome!"));
	printf("%.2f\n", awl("Working on my tan right now."));
	printf("%.2f\n", awl("Having a blast partying in Las Vegas."));
	printf("%.2f\n", awl("Have you ever wondered what Saturn looks like?"));
	printf("%.2f\n", awl("I just planted a young oak tree, wonder how tall it will grow in a few years?"));
	printf("%.2f\n", awl(""));
	printf("%.2f\n", awl("abdet"));
	return 0;
}
