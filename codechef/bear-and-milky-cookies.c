/*

Limak is a little polar bear, who loves eating cookies and drinking milk. For this reason he often visits Chef's kitchen.

Limak is going to spend N minutes in the kitchen. Each minute he either eats a cookie or drinks milk.
Cookies are very sweet and thus Limak's parents have instructed him, that after eating a cookie, he has to drink milk in the next minute.

You are given whether he ate a cookie or drank milk in each of the N minutes.
Your task is to check if Limak followed his parents' instructions.
That is, you need to verify whether after each eaten cookie he drinks milk in the next minute.
Print "YES" or "NO" for each test case accordingly.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains an integer N denoting the number of minutes.
The second line of a test case contains N space-separated strings S1, S2, ..., SN. The string Si is either "cookie" (if Limak eats a cookie in the i-th minute) or "milk" (otherwise).

Output

For each test case, output a single line containing the answer — "YES" if Limak followed his parents' instructions, and "NO" otherwise, both without the quotes.

Constraints
1 ≤ T ≤ 50
1 ≤ N ≤ 50
Each Si is either "cookie" or "milk" (without the quotes).

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
digested(const char **s, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		if (strcmp(s[i], "cookie"))
			continue;

		if (i + 1 >= n || strcmp(s[i + 1], "milk"))
			return false;
	}
	return true;
}

int
main(void)
{
	const char *s1[] = {
	    "cookie",
	    "milk",
	    "milk",
	    "cookie",
	    "milk",
	    "cookie",
	    "milk",
	};

	const char *s2[] = {
	    "cookie",
	    "cookie",
	    "milk",
	    "milk",
	    "milk",
	};

	const char *s3[] = {
	    "milk",
	    "milk",
	    "milk",
	    "milk",
	};

	const char *s4[] = {
	    "cookie",
	};

	assert(digested(s1, nelem(s1)) == true);
	assert(digested(s2, nelem(s2)) == false);
	assert(digested(s3, nelem(s3)) == true);
	assert(digested(s4, nelem(s4)) == false);

	return 0;
}
