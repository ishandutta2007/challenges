/*

According to some controversial story, the odrer of ltteres in a wrod deos not mttaer much for raednig, as lnog as the frist and lsat lteter macth with the orignial wrod.

So, for fun, what would be the shortest function to randomize letter order in a word while keeping the first and the last letter in place?

Here's my stab at it with JavaScript. All whitespace removed it's at 124 130 characters.

function r(w) {
  var l=w.length-1;
  return l<3?w:w[0]+w.slice(1,l).split("").sort(function(){return Math.random()-.5}).join("")+w[l];
}

Shorter JavaScript always welcome.

    Edit: length check added. Function should not fail for short words.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
swap(char *x, char *y)
{
	char t;

	t = *y;
	*y = *x;
	*x = t;
}

void
shuffle(char *a, size_t n)
{
	size_t i, j;

	if (n < 2)
		return;

	if (n < 3) {
		swap(&a[0], &a[1]);
		return;
	}

	for (i = 0; i < n - 2; i++) {
		j = i + (rand() % (n - i));
		swap(&a[i], &a[j]);
	}
}

char *
randomize(const char *s, char *b)
{
	size_t i;

	for (i = 0; s[i]; i++)
		b[i] = s[i];
	b[i] = '\0';

	if (i > 2)
		shuffle(b + 1, i - 2);

	return b;
}

void
test(const char *s)
{
	char b[128];

	randomize(s, b);
	printf("%s -> %s\n", s, b);
}

int
main(void)
{
	srand(time(NULL));

	test("order");
	test("time");
	test("ti");
	test("sandwich");
	test("letter");
	test("return");

	return 0;
}
