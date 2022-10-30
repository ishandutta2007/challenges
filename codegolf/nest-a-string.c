/*

To "function nest" a string, you must:

    Treat the first character as a function, and the following characters as the arguments to that function. For example, if the input string was Hello, then the first step would be:

    H(ello)

    Then, repeat this same step for every substring. So we get:

    H(ello)
    H(e(llo))
    H(e(l(lo)))
    H(e(l(l(o))))

Your task is to write a program or function that "function nests" a string. For example, if the input string was Hello world!, then you should output:

H(e(l(l(o( (w(o(r(l(d(!)))))))))))

The input will only ever contain printable ASCII, and you may take the input and the output in any reasonable format. For example, STDIN/STDOUT, function arguments and return value, reading and writing to a file, etc.

For simplicity's sake, you may also assume the input will not contain parentheses, and will not be empty.

Input:
Nest a string
Output:
N(e(s(t( (a( (s(t(r(i(n(g))))))))))))

Input:
foobar
Output:
f(o(o(b(a(r)))))

Input:
1234567890
Output:
1(2(3(4(5(6(7(8(9(0)))))))))

Input:
code-golf
Output:
c(o(d(e(-(g(o(l(f))))))))

Input:
a
Output:
a

Input:
42
Output:
4(2)

As usual, all of our default rules and loopholes apply, and the shortest answer scored in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
nest(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		b[j++] = s[i];
		if (s[i + 1])
			b[j++] = '(';
	}

	for (; i > 1; i--)
		b[j++] = ')';
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	nest(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Hello", "H(e(l(l(o))))");
	test("Hello world!", "H(e(l(l(o( (w(o(r(l(d(!)))))))))))");
	test("Nest a string", "N(e(s(t( (a( (s(t(r(i(n(g))))))))))))");
	test("foobar", "f(o(o(b(a(r)))))");
	test("1234567890", "1(2(3(4(5(6(7(8(9(0)))))))))");
	test("code-golf", "c(o(d(e(-(g(o(l(f))))))))");
	test("a", "a");
	test("42", "4(2)");

	return 0;
}
