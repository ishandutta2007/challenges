/*

Create a function that takes in a current mood and return a sentence in the following format: "Today, I am feeling {mood}". However, if no argument is passed, return "Today, I am feeling neutral".

*/

#include <stdio.h>

char *
mood(const char *m, char *b, size_t n)
{
	if (!m || m[0] == '\0')
		m = "neutral";
	snprintf(b, n, "Today, I am feeling %s", m);
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", mood("happy", b, sizeof(b)));
	printf("%s\n", mood("sad", b, sizeof(b)));
	printf("%s\n", mood("very happy", b, sizeof(b)));
	printf("%s\n", mood("rather empty inside", b, sizeof(b)));
	printf("%s\n", mood("confused", b, sizeof(b)));
	printf("%s\n", mood("", b, sizeof(b)));
	return 0;
}
