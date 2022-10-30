/*

YouTube currently displays a like and a dislike button, allowing you to express your opinions about particular content. It's set up in such a way that you cannot like and dislike a video at the same time.

There are two other interesting rules to be noted about the interface:

    Pressing a button, which is already active, will undo your press.
    If you press the like button after pressing the dislike button, the like button overwrites the previous "dislike" state. The same is true for the other way round.

Create a function that takes an array of button inputs and returns the final state.
Examples

likeOrDislike(["Dislike"]) ➞ "Dislike"

likeOrDislike(["Like", "Like"]) ➞ "Nothing"

likeOrDislike(["Dislike", "Like"]) ➞ "Like"

likeOrDislike(["Like", "Dislike", "Dislike"]) ➞ "Nothing"

Notes

    If no button is currently active, return "Nothing".
    If the array is empty, return "Nothing".

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
rate(const char **s, size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++) {
		if (!strcmp(s[i], "Like"))
			r = (r == 1) ? 0 : 1;
		else if (!strcmp(s[i], "Dislike"))
			r = (r == 2) ? 0 : 2;
	}

	if (r == 0)
		return "Nothing";
	if (r == 1)
		return "Like";
	return "Dislike";
}

int
main(void)
{
	const char *s1[] = {"Dislike"};
	const char *s2[] = {"Like", "Like"};
	const char *s3[] = {"Dislike", "Like"};
	const char *s4[] = {"Dislike", "Dislike"};
	const char *s5[] = {"Like", "Dislike", "Dislike"};
	const char *s6[] = {"Like", "Like", "Like"};
	const char *s7[] = {"Like", "Dislike"};
	const char *s8[] = {"Dislike", "Like"};
	const char *s9[] = {"Like", "Dislike", "Dislike"};
	const char *s10[] = {"Dislike", "Like", "Dislike"};
	const char *s11[] = {"Like", "Like", "Dislike", "Like", "Like", "Like", "Like", "Dislike"};
	const char *s12[] = {"Like", "Like", "Dislike", "Like", "Dislike", "Like", "Like", "Like"};
	const char *s13[] = {"Like", "Like", "Dislike", "Like", "Like", "Like", "Like", "Dislike", "Dislike", "Like", "Like", "Like", "Like", "Dislike", "Dislike", "Like", "Like", "Like", "Dislike", "Dislike"};
	const char *s14[] = {"Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike", "Like", "Dislike"};

	assert(!strcmp(rate(s1, nelem(s1)), "Dislike"));
	assert(!strcmp(rate(s2, nelem(s2)), "Nothing"));
	assert(!strcmp(rate(s3, nelem(s3)), "Like"));
	assert(!strcmp(rate(s4, nelem(s4)), "Nothing"));
	assert(!strcmp(rate(s5, nelem(s5)), "Nothing"));
	assert(!strcmp(rate(s6, nelem(s6)), "Like"));
	assert(!strcmp(rate(s7, nelem(s7)), "Dislike"));
	assert(!strcmp(rate(s8, nelem(s8)), "Like"));
	assert(!strcmp(rate(s9, nelem(s9)), "Nothing"));
	assert(!strcmp(rate(s10, nelem(s10)), "Dislike"));
	assert(!strcmp(rate(NULL, 0), "Nothing"));
	assert(!strcmp(rate(s11, nelem(s11)), "Dislike"));
	assert(!strcmp(rate(s12, nelem(s12)), "Like"));
	assert(!strcmp(rate(s13, nelem(s13)), "Nothing"));
	assert(!strcmp(rate(s14, nelem(s14)), "Dislike"));

	return 0;
}
