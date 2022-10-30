/*

Create a function to check if a candidate is qualified in an imaginary coding interview of an imaginary tech startup.

The criteria for a candidate to be qualified in the coding interview is:

    The candidate should have complete all the questions.
    The maximum time given to complete the interview is 120 minutes.
    The maximum time given for very easy questions is 5 minutes each.
    The maximum time given for easy questions is 10 minutes each.
    The maximum time given for medium questions is 15 minutes each.
    The maximum time given for hard questions is 20 minutes each.

If all the above conditions are satisfied, return "qualified", else return "disqualified".

You will be given an array of time taken by a candidate to solve a particular question and the total time taken by the candidate to complete the interview.

Given an array, in a true condition will always be in the format [very easy, very easy, easy, easy, medium, medium, hard, hard].

The maximum time to complete the interview includes a buffer time of 20 minutes.
Examples

interview([5, 5, 10, 10, 15, 15, 20, 20], 120) ➞ "qualified"

interview([2, 3, 8, 6, 5, 12, 10, 18], 64) ➞  "qualified"

interview([5, 5, 10, 10, 25, 15, 20, 20], 120) ➞ "disqualified"
// Exceeded the time limit for a medium question.

interview([5, 5, 10, 10, 15, 15, 20], 120) ➞ "disqualified"
// Did not complete all the questions.

interview([5, 5, 10, 10, 15, 15, 20, 20], 130) ➞ "disqualified"
// Solved all the questions in their respected time limits but exceeded the total time limit of the interview.

Notes

Try to solve the problem using only array methods.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
interview(unsigned *a, size_t n, unsigned t)
{
	static const unsigned tab[] = {
	    5,
	    5,
	    10,
	    10,
	    15,
	    15,
	    20,
	    20,
	};
	size_t i;

	if (n < nelem(tab) || t > 120)
		return "disqualified";

	for (i = 0; i < n; i++) {
		if (a[i] > tab[i])
			return "disqualified";
	}
	return "qualified";
}

int
main(void)
{
	unsigned a1[] = {5, 5, 10, 10, 15, 15, 20, 20};
	unsigned a2[] = {2, 3, 8, 6, 5, 12, 10, 18};
	unsigned a3[] = {5, 5, 10, 10, 25, 15, 20, 20};
	unsigned a4[] = {5, 5, 10, 10, 15, 15, 20};
	unsigned a5[] = {5, 5, 10, 10, 15, 15, 20, 20};
	unsigned a6[] = {5, 5, 10, 10, 15, 20, 50};
	unsigned a7[] = {5, 5, 10, 10, 15, 15, 40};
	unsigned a8[] = {10, 10, 15, 15, 20, 20};
	unsigned a9[] = {5, 5, 10, 20, 15, 15, 20, 20};

	assert(!strcmp(interview(a1, nelem(a1), 120), "qualified"));
	assert(!strcmp(interview(a2, nelem(a2), 120), "qualified"));
	assert(!strcmp(interview(a2, nelem(a2), 64), "qualified"));
	assert(!strcmp(interview(a3, nelem(a3), 120), "disqualified"));
	assert(!strcmp(interview(a4, nelem(a4), 120), "disqualified"));
	assert(!strcmp(interview(a5, nelem(a5), 130), "disqualified"));
	assert(!strcmp(interview(a6, nelem(a6), 160), "disqualified"));
	assert(!strcmp(interview(a7, nelem(a7), 120), "disqualified"));
	assert(!strcmp(interview(a8, nelem(a8), 150), "disqualified"));
	assert(!strcmp(interview(a9, nelem(a9), 140), "disqualified"));

	return 0;
}
