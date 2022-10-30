/*

Create a function that reverses letters in a string but keeps digits in their current order.

Examples

reverse("ab89c") ➞ "cb89a"

reverse("jkl5mn923o") ➞ "onm5lk923j"

reverse("123a45") ➞ "123a45"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
swapc(char *x, char *y)
{
	char t;

	t = *y;
	*y = *x;
	*x = t;
}

char *
reverse(const char *s, char *b)
{
	size_t i, j, n;

	for (n = 0; s[n]; n++)
		b[n] = s[n];
	b[n] = '\0';

	if (n == 0)
		return b;

	i = 0;
	j = n - 1;
	while (i < j) {
		if (isdigit(b[i]))
			i++;
		else if (isdigit(b[j]))
			j--;
		else
			swapc(&b[i++], &b[j--]);
	}

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	reverse(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("ab89c", "cb89a");
	test("jkl5mn923o", "onm5lk923j");
	test("123a45", "123a45");
	test("a1b1c", "c1b1a");

	return 0;
}
