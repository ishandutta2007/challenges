/*

Chef has learned a new technique for comparing two recipes. A recipe contains a list of ingredients in increasing order of the times they will be processed.
An ingredient is represented by a letter 'a'-'z'. The i-th letter in a recipe denotes the i-th ingredient. An ingredient can be used multiple times in a recipe.

The technique is as follows. Compare two recipes by comparing their respective lists.
If the sets of ingredients used in both recipes are equal and each ingredient is used the same number of times in both of them (processing order does not matter), they are declared as granama recipes.
("granama" is the Chef-ian word for "similar".)

Chef took two recipes he invented yesterday. He wanted to compare them using the technique.
Unfortunately, Chef forgot to keep track of the number of times each ingredient has been used in a recipe.
He only compared the ingredients but NOT their frequencies.
More precisely, Chef considers two recipes as granama if there are no ingredients which are used in one recipe and not used in the other recipe.

Your task is to report whether Chef has correctly classified the two recipes (as granama or not granama) although he forgot to keep track of the frequencies.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description for T test cases follows.
Each test case consists of a single line containing two space-separated strings R and S denoting the two recipes.

Output

For each test case, output a single line containing "YES" (quotes for clarity) if Chef correctly classified the two recipes as granama or not granama.
Otherwise, output a single line containing "NO" (quotes for clarity) if Chef declared two recipes as granama when they actually are not.

Constraints

1 ≤ T ≤ 100
1 ≤ |R|, |S| ≤ 1000

*/

#include <assert.h>
#include <stdbool.h>
#include <string.h>

void
histogram(const char *s, size_t h[256])
{
	size_t i;

	memset(h, 0, sizeof(*h) * 256);
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;
}

bool
match(size_t a[256], size_t b[256])
{
	size_t i;

	for (i = 'a'; i <= 'z'; i++) {
		if (!a[i] && b[i])
			return true;
		if (a[i] && !b[i])
			return true;
		if (a[i] != b[i])
			return false;
	}
	return true;
}

bool
correct(const char *r, const char *s)
{
	size_t a[256];
	size_t b[256];

	histogram(r, a);
	histogram(s, b);
	return match(a, b);
}

int
main(void)
{
	assert(correct("alex", "axle") == true);
	assert(correct("paradise", "diapers") == false);
	assert(correct("alice", "bob") == true);

	return 0;
}
