/*

In the popular (and essential) computer science book, An Introduction to Formal Languages and Automata by Peter Linz, the following formal language is frequently stated:

definition

mainly because this language can not be processed with finite-state automata. This expression mean "Language L consists all strings of 'a's followed by 'b's, in which the number of 'a's and 'b's are equal and non-zero".

Challenge

Write a working program/function which gets a string, containing "a"s and "b"s only, as input and returns/outputs a truth value, saying if this string is valid the formal language L.

    Your program cannot use any external computation tools, including network, external programs, etc. Shells are an exception to this rule; Bash, e.g., can use command line utilities.

    Your program must return/output the result in a "logical" way, for example: returning 10 instead of 0, "beep" sound, outputting to stdout etc. More info here.

    Standard code golf rules apply.

This is a code-golf. Shortest code in bytes wins. Good luck!
Truthy test cases

"ab"
"aabb"
"aaabbb"
"aaaabbbb"
"aaaaabbbbb"
"aaaaaabbbbbb"

Falsy test cases

""
"a"
"b"
"aa"
"ba"
"bb"
"aaa"
"aab"
"aba"
"abb"
"baa"
"bab"
"bba"
"bbb"
"aaaa"
"aaab"
"aaba"
"abaa"
"abab"
"abba"
"abbb"
"baaa"
"baab"
"baba"
"babb"
"bbaa"
"bbab"
"bbba"
"bbbb"

Leaderboard

Here is a Stack Snippet to generate both a regular leaderboard and an overview of winners by language.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
count(const char *s)
{
	size_t i, n, m;

	n = m = 0;
	for (i = 0; s[i] == 'a'; i++)
		n++;
	for (; s[i] == 'b'; i++)
		m++;
	return !s[i] && n && n == m;
}

int
main(void)
{
	static const char *truthy[] = {
	    "ab",
	    "aabb",
	    "aaabbb",
	    "aaaabbbb",
	    "aaaaabbbbb",
	    "aaaaaabbbbbb",
	};
	static const char *falsy[] = {
	    "",
	    "a",
	    "b",
	    "aa",
	    "ba",
	    "bb",
	    "aaa",
	    "aab",
	    "aba",
	    "abb",
	    "baa",
	    "bab",
	    "bba",
	    "bbb",
	    "aaaa",
	    "aaab",
	    "aaba",
	    "abaa",
	    "abab",
	    "abba",
	    "abbb",
	    "baaa",
	    "baab",
	    "baba",
	    "babb",
	    "bbaa",
	    "bbab",
	    "bbba",
	    "bbbb",
	};

	size_t i;

	for (i = 0; i < nelem(truthy); i++)
		assert(count(truthy[i]) == true);
	for (i = 0; i < nelem(falsy); i++)
		assert(count(falsy[i]) == false);

	return 0;
}
