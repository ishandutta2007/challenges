/*

POV: You are in an exam and time has just run out. While the teacher's back is turned, you hastily take the opportunity to finish scribbling down the last few words of the conclusion.

For this challenge, it takes 0.5 seconds to write a character (not including spaces).
Given the full sentence and the unfinished sentence as inputs, return the time it takes to finish writing in seconds.

Worked Example

timeToFinish(
  "And so brings my conclusion to its conclusion.",
  "And so brings my conclusion to"
) ➞ 7

// "its" has 3 characters
// "conclusion." has 11 characters, including punctuation.
// 11 + 3 = 14
// 14 x 0.5 = 7
// Remember not to include spaces.

Examples

timeToFinish(
  "And so brings my conclusion to its conclusion.",
  "And so brings my conclusion to its conclus"
) ➞ 2

timeToFinish(
  "As a result, my point is still valid.",
  "As a result, my"
) ➞ 9

timeToFinish(
  "Thank you for reading my essay.",
  "T"
) ➞ 12.5

Notes

The unfinished sentence is always found at the start of a complete sentence.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double
finish(const char *s, const char *t)
{
	size_t c, i, n, m;

	n = strlen(s);
	m = strlen(t);
	c = 0;
	for (i = m; i < n; i++)
		c += !isspace(s[i]);
	return c * 0.5;
}

void
test(const char *s, const char *t, double r)
{
	double p;

	p = finish(s, t);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-8);
}

int
main(void)
{
	test("And so brings my conclusion to its conclusion.", "And so brings my conclusion to", 7);
	test("And so brings my conclusion to its conclusion.", "And so brings my conclusion to its conclus", 2);
	test("As a result, my point is still valid.", "As a result, my", 9);
	test("Thank you for reading my essay.", "T", 12.5);
	test("Therefore, there was over there their only answer.", "Therefore, there w", 13.5);
	test("And there, I end this thesis with a rock solid conclusion.", "And there, I end this thesis with a rock solid conclusion.", 0);
	test("", "", 0);
	test("What? Who? Where? Why? I pondered these things upon reading the first question.", "", 33.5);

	return 0;
}
