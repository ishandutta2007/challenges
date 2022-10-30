/*

"You have a reason to leave this place, but I don't."

In the fourth game, Sang-Woo and Ali are competing against each other.
Sang-Woo is the more intelligent one between them, and he plans to win the game by cheating.
Ali is your childhood friend and you want to help him win this game. The game goes as follows.

Both of them are given 2 strings — S and P — of equal length (say N).
The task is to find the minimum number of operations required to convert the string P into S.
Every character of both S and P is either a lowercase English alphabet or ?.

First, before performing any operation, you must choose a single lowercase character from the English alphabet, and replace every occurrence of ? with this character.
Note that every ? present in either S or P is replaced by the exact same character. This does not count as an operation.

Once the above step is done, you are allowed to perform the following two operations on P any number of times:

Pick an index 1≤i≤N such that Pi is a vowel, and change Pi to any consonant.
Pick an index 1≤i≤N such that Pi is a consonant, and change Pi to any vowel.
Note: The vowels are the 5 characters {a,e,i,o,u} — the other 21 are consonants.

Find the minimum number of operations required to convert P into S.

Input Format

The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains an integer N, denoting the length of strings S and P.
The second and third lines contain strings S and P respectively.

Output Format

For each test case, output in a single line the minimum number of operations required to convert P into S.

Constraints
1≤T≤10^4
1≤N≤10^5
The sum of all N across all test cases does not exceed 5∗10^5.
|S|=|P|
Every character of both S and P is either a lowercase English alphabet or ?.
Every ? present in S and P should be assigned the same character.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
isvowel(int c)
{
	return strchr("aeiou", c) != NULL;
}

int
operations(const char *s, const char *p)
{
	int c, r, v, x, y;
	size_t i;

	r = INT_MAX;
	for (c = 'a'; c <= 'z'; c++) {
		v = 0;
		for (i = 0; s[i] && p[i]; i++) {
			x = (s[i] == '?') ? c : s[i];
			y = (p[i] == '?') ? c : p[i];
			if (x == y)
				continue;

			v += (isvowel(x) != isvowel(y)) ? 1 : 2;
		}
		r = min(r, v);
	}
	return r;
}

int
main(void)
{
	assert(operations("ab?c?", "aeg?k") == 4);
	assert(operations("abcde?", "ehio??") == 6);
	assert(operations("abcd", "abcd") == 0);

	return 0;
}
