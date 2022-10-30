/*

Create a function that returns True if two lines rhyme and False otherwise.
For the purposes of this exercise, two lines rhyme if the last word from each sentence contains the same vowels.

Notes

Case insensitive.
Here we are disregarding cases like "thyme" and "lime".
We are also disregarding cases like "away" and "today" (which technically rhyme, even though they contain different vowels).

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void
count(const char *s, size_t c[5])
{
	static const char v[] = "aeiou";

	size_t i;
	char *p;

	memset(c, 0, sizeof(*c) * 5);
	i = strlen(s);
	while (i > 0 && !isspace(s[i - 1])) {
		if ((p = strchr(v, tolower(s[i - 1]))))
			c[p - v]++;
		i--;
	}
}

int
rhyme(const char *s, const char *t)
{
	size_t c[2][5];

	count(s, c[0]);
	count(t, c[1]);
	return memcmp(c[0], c[1], sizeof(c[0])) == 0;
}

int
main(void)
{
	printf("%d\n", rhyme("Sam I am!", "Green eggs and ham."));
	printf("%d\n", rhyme("Sam I am!", "Green eggs and HAM."));
	printf("%d\n", rhyme("head straight to town", "give me not a frown"));
	printf("%d\n", rhyme("with an unpleasant bump", "in a slump"));
	printf("%d\n", rhyme("your elbow and chin!", "how much can you win?"));
	printf("%d\n", rhyme("you will start to race", "the waiting Place"));
	printf("%d\n", rhyme("All that waiting and staying.", "where the band are playing."));

	printf("%d\n", rhyme("You are off to the races", "a splendid day."));
	printf("%d\n", rhyme("and frequently do?", "you gotta move."));
	printf("%d\n", rhyme("down by the bay", "where the watermelons grow"));
	printf("%d\n", rhyme("back to my home", "i dare not go"));

	return 0;
}
