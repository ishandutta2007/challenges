/*

Given an expression matching the regex /^[-~]*x$/, evaluate it in terms of x and output a string matching the regex /^-?x[+-]\d+$/.

For example, the string -~x evaluates to x+1, while the string -~-x evaluates to -x+1, and the string -~-~--x evaluates to x+2.

We start from x and evaluate the string right to left. - negates the term, while ~ converts y to -y-1.

Testcases:

    x  x+0
   ~x -x-1
  -~x  x+1
 ~-~x -x-2
-~-~x  x+2
--~~x  x+0
  ~-x  x-1
 -~-x -x+1
This is code-golf. Shortest answer in bytes wins.

The input/output format is strict. The "x" is mandatory.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

char *
eval(const char *s, char *b)
{
	vlong g, x;
	size_t n;

	n = strlen(s);
	if (n == 0 || s[n - 1] != 'x')
		return NULL;

	g = 1;
	x = 0;
	for (n--; n > 0; n--) {
		switch (s[n - 1]) {
		case '~':
			x = ~x;
			break;
		case '-':
			x = -x;
			break;
		default:
			return NULL;
		}
		g = -g;
	}

	sprintf(b, "%sx%+lld", (g > 0) ? "" : "-", x);
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128], *p;

	p = eval(s, b);
	assert(p);
	printf("%s\n", p);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("x", "x+0");
	test("~x", "-x-1");
	test("-~x", "x+1");
	test("~-~x", "-x-2");
	test("-~-~x", "x+2");
	test("--~~x", "x+0");
	test("~-x", "x-1");
	test("-~-x", "-x+1");

	return 0;
}
