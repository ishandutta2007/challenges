/*

Given a character and a value between 0 and 100, return a string that represents a simple progress bar.

    The value represents a percentage.
    The bar should begin and end with "|"
    Repeat the character to fill the bar, with each character equivalent to 10%
    Use spaces to pad the bar to a length of 10 characters.
    A single space comes after the bar, then a message with the % of completion (e.g. "Progress: 60%")
    If the value is 100, the message should be "Completed!".

Examples

progress_bar("#", 0) ➞ "|          | Progress: 0%"

progress_bar("=", 40) ➞ "|====      | Progress: 40%"

progress_bar("#", 60) ➞ "|######    | Progress: 60%"

progress_bar(">", 100) ➞ "|>>>>>>>>>>| Completed!"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
progress(const char *s, unsigned n, char *b)
{
	size_t i, j, l;

	if (n > 100)
		n = 100;

	j = n / 10;
	l = sprintf(b, "|");
	for (i = 0; i < j; i++)
		l += sprintf(b + l, "%s", s);
	for (; i < 10; i++)
		l += sprintf(b + l, " ");
	l += sprintf(b + l, "| ");
	if (n == 100)
		l += sprintf(b + l, "Completed!");
	else
		l += sprintf(b + l, "Progress: %u%%", n);
	return b;
}

void
test(const char *s, int n, const char *r)
{
	char b[128];

	progress(s, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("=", 10, "|=         | Progress: 10%");
	test("#", 90, "|######### | Progress: 90%");
	test("*", 100, "|**********| Completed!");
	test("#", 50, "|#####     | Progress: 50%");
	test("*", 60, "|******    | Progress: 60%");
	test("#", 100, "|##########| Completed!");
	test("*", 60, "|******    | Progress: 60%");
	test("=", 30, "|===       | Progress: 30%");
	test(">", 70, "|>>>>>>>   | Progress: 70%");
	test("=", 40, "|====      | Progress: 40%");
	test(">", 20, "|>>        | Progress: 20%");
	test("*", 0, "|          | Progress: 0%");
	test("=", 60, "|======    | Progress: 60%");
	test(">", 90, "|>>>>>>>>> | Progress: 90%");
	test("*", 80, "|********  | Progress: 80%");
	test("#", 20, "|##        | Progress: 20%");
	test("*", 30, "|***       | Progress: 30%");
	test("=", 70, "|=======   | Progress: 70%");
	test("=", 0, "|          | Progress: 0%");
	test(">", 100, "|>>>>>>>>>>| Completed!");

	return 0;
}
