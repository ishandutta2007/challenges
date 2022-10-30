/*

We say that a string contains the word hackerrank if a subsequence of its characters spell the word hackerrank.
For example, if string s=haacckkerrannkk it does contain hackerrank, but s=haacckkerannk does not.
In the second case, the second r is missing. If we reorder the first string as
s=hccaakkerrannkk, it no longer contains the subsequence due to ordering.

For each query, print YES on a new line if the string contains hackerrank, otherwise, print NO. 

*/
#include <stdio.h>

const char *
inside(const char *s)
{
	static const char w[] = "hackerrank";
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (s[i] == w[j])
			j++;

		if (j == sizeof(w) - 1)
			return "YES";
	}
	return "NO";
}

int
main(void)
{
	printf("%s\n", inside("haacckkerrann"));
	printf("%s\n", inside("haacckkerrannkk"));
	printf("%s\n", inside("haacckkerannk"));
	printf("%s\n", inside("hccaakkerrannkk"));
	printf("%s\n", inside("hereiamstackerrank"));
	printf("%s\n", inside("hackerworld"));
	printf("%s\n", inside("hhaacckkekraraannk"));
	printf("%s\n", inside("rhbaasdndfsdskgbfefdbrsdfhuyatrjtcrtyytktjjt"));
	return 0;
}
