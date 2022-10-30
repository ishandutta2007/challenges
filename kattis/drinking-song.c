/*

Ninety-Nine Bottles of Beer is an anonymous folk song dating to the mid-20th century.
It is a traditional reverse counting song, sometimes used to sing on long trips, as it has a very repetitive format which is easy to memorize and can take a long time to sing.
The lyrics describe a quantity of bottles that is reduced by 1 in every verse, until no bottles are left, at which point the song ends somewhat abruptly.

Many variations and similar songs are known in other languages.

Input

The input consists of exactly two lines. On the first line, the number N of bottles 1≤N≤99.
On the second line, a single word of at most 20 lower- or uppercase characters from the English alphabet, not using whitespace, describing a beverage.

Output

The full lyrics of the song, starting with N, and counting down until the last bottle gets taken.
The lyrics are given by example below. Note the grammatical changes in the last two verses.

*/

#include <stdio.h>

void
sing(int n, const char *w)
{
	for (; n > 0; n--) {
		if (n > 2) {
			printf("%d bottles of %s on the wall, %d bottles of %s.\n", n, w, n, w);
			printf("Take one down, pass it around, %d bottles of %s on the wall.\n", n - 1, w);
		} else if (n == 2) {
			printf("%d bottles of %s on the wall, %d bottles of %s.\n", n, w, n, w);
			printf("Take one down, pass it around, %d bottle of %s on the wall.\n", n - 1, w);
		} else {
			printf("%d bottle of %s on the wall, %d bottle of %s.\n", n, w, n, w);
			printf("Take one down, pass it around, no more bottles of %s.\n", w);
		}
		printf("\n");
	}
}

int
main(void)
{
	sing(3, "milk");
	sing(99, "beer");

	return 0;
}
