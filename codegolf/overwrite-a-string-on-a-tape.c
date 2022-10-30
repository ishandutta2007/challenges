/*

Take the string abcdfghjk. To overwrite it, starting from f, with the string wxyz, you would continue along the original, replacing each character with the one from the replacement string. The result would be abcdwxyzk.

Now, consider a string which would be too long to fit, like lmnopqrs. Starting at f you would get abcdlmnop, then hit the end of the string.
In order to continue, you wrap back to the beginning, resulting in qrsdefghi. With a long enough string, you could even wrap around multiple times.

Task:

You should take three inputs: the original string, the replacement string, and an index to start replacing at. This can be zero or one indexed.

Test Cases:

"This is a string"  "That"                  0   ->  "That is a string"
"This is a string"  "That"                  5   ->  "This That string"
"This is a string"  "That"                  14  ->  "atis is a striTh"
"hi"                "Hello there!"          0   ->  "e!"
"hi"                "Hello there!"          1   ->  "!e"
"over"              "write multiple times"  0   ->  "imes"
"over"              "write multiple times"  3   ->  "mesi"

Other:

This is code-golf, shortest answer per language in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
overwrite(char *b, size_t n, const char *s, size_t i)
{
	size_t j;

	if (n == 0)
		return b;

	for (j = 0; s[j]; j++)
		b[(i + j) % n] = s[j];
	b[n] = '\0';
	return b;
}

void
test(const char *t, const char *s, size_t i, const char *r)
{
	char b[128];
	size_t n;

	n = snprintf(b, sizeof(b), "%s", t);
	overwrite(b, n, s, i);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("This is a string", "That", 0, "That is a string");
	test("This is a string", "That", 5, "This That string");
	test("hi", "Hello there!", 0, "e!");
	test("hi", "Hello there!", 1, "!e");
	test("over", "write multiple times", 0, "imes");
	test("over", "write multiple times", 3, "mesi");

	return 0;
}
