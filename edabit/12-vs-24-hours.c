/*

Create a function that converts 12-hour time to 24-hour time or vice versa.
Return the output as a string.

Examples

convertTime("12:00 am") ➞ "0:00"

convertTime("6:20 pm") ➞ "18:20"

convertTime("21:00") ➞ "9:00 pm"

convertTime("5:05") ➞ "5:05 am"

Notes

    A 12-hour time input will be denoted with an am or pm suffix.
    A 24-hour input time contains no suffix.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
conv(const char *s, char *b)
{
	unsigned h, m;
	char p[8];
	int r;

	r = sscanf(s, "%u:%u %2s", &h, &m, p);
	if (m >= 60 || h >= 24)
		return NULL;

	if (r == 3 && h <= 12) {
		h %= 12;
		if (!strcmp(p, "pm"))
			h += 12;
		else if (strcmp(p, "am"))
			return NULL;

		sprintf(b, "%d:%02d", h, m);
	} else if (r == 2)
		sprintf(b, "%d:%02d %s", h % 12, m, (h < 12) ? "am" : "pm");
	else
		return NULL;

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128], *p;

	p = conv(s, b);
	if (!r)
		assert(!p);
	else {
		printf("%s\n", b);
		assert(!strcmp(b, r));
	}
}

int
main(void)
{
	test("12:00 am", "0:00");
	test("6:20 pm", "18:20");
	test("21:00", "9:00 pm");
	test("5:05", "5:05 am");
	test("23:59", "11:59 pm");
	test("45:00", NULL);
	test("5:124 pm", NULL);
	test("6:1 fc", NULL);

	return 0;
}
