/*

Andy, Ben and Charlotte are playing a board game. The three of them decided to come up with a new scoring system. A player's first initial ("A", "B" or "C") denotes that player scoring a single point. Given a string of capital letters, return an array of the players' scores.

For instance, if ABBACCCCAC is written when the game is over, then Andy scored 3 points, Ben scored 2 points, and Charlotte scored 5 points, since there are 3 instances of letter A, 2 instances of letter B, and 5 instances of letter C. So the array [3, 2, 5] should be returned.
Examples

calculateScores("A") ➞ [1, 0, 0]

calculateScores("ABC") ➞ [1, 1, 1]

calculateScores("ABCBACC") ➞ [2, 2, 3]

Notes

If given an empty string as an input, return [0, 0, 0].

*/

#include <assert.h>
#include <string.h>

int *
scores(const char *s, int r[3])
{
	size_t i;

	r[0] = r[1] = r[2] = 0;
	for (i = 0; s[i]; i++) {
		r[0] += (s[i] == 'A');
		r[1] += (s[i] == 'B');
		r[2] += (s[i] == 'C');
	}
	return r;
}

int
main(void)
{
	int r[3];

	char s1[] = "AAB";
	char s2[] = "ABC";
	char s3[] = "ABCBACC";
	char s4[] = "CCBBBB";
	char s5[] = "CCAABBAABBCC";
	char s6[] = "A";
	char s7[] = "";
	char s8[] = "ACCCA";

	int r1[] = { 2, 1, 0 };
	int r2[] = { 1, 1, 1 };
	int r3[] = { 2, 2, 3 };
	int r4[] = { 0, 4, 2 };
	int r5[] = { 4, 4, 4 };
	int r6[] = { 1, 0, 0 };
	int r7[] = { 0, 0, 0 };
	int r8[] = { 2, 0, 3 };

	assert(memcmp(scores(s1, r), r1, sizeof(r1)) == 0);
	assert(memcmp(scores(s2, r), r2, sizeof(r2)) == 0);
	assert(memcmp(scores(s3, r), r3, sizeof(r3)) == 0);
	assert(memcmp(scores(s4, r), r4, sizeof(r4)) == 0);
	assert(memcmp(scores(s5, r), r5, sizeof(r5)) == 0);
	assert(memcmp(scores(s6, r), r6, sizeof(r6)) == 0);
	assert(memcmp(scores(s7, r), r7, sizeof(r7)) == 0);
	assert(memcmp(scores(s8, r), r8, sizeof(r8)) == 0);

	return 0;
}
