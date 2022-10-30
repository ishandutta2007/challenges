/*

Given an ASCII string, output the exploded suffixes of it. For example, if the string was abcde, there are 5 suffixes, ordered longest to shortest:

abcde
bcde
cde
de
e
Each suffix is then exploded, meaning each character is copied as many times as its one-indexed location in that suffix. For example, exploding the suffixes of abcde,

abcde
12345
abbcccddddeeeee

bcde
1234
bccdddeeee

cde
123
cddeee

de
12
dee

e
1
e
Altogether, the exploded suffixes of abcde are

abbcccddddeeeee
bccdddeeee
cddeee
dee
e
Rules
This is code-golf so the shortest code wins.
The input will consist of the printable ASCII characters. (This excludes newlines but includes spaces.)
The output will have each string on a separate line.
Trailing spaces are allowed on each line and there may be an extra newline at the end.
Test Cases
''

'a'
a

'bc'
bcc
c

'xyz'
xyyzzz
yzz
z

'code-golf'
coodddeeee-----ggggggooooooollllllllfffffffff
oddeee----gggggoooooolllllllffffffff
dee---ggggooooollllllfffffff
e--gggoooolllllffffff
-ggooollllfffff
goolllffff
ollfff
lff
f

's p a c e'
s  ppp    aaaaa      ccccccc        eeeeeeeee
 pp   aaaa     cccccc       eeeeeeee
p  aaa    ccccc      eeeeeee
 aa   cccc     eeeeee
a  ccc    eeeee
 cc   eeee
c  eee
 ee
e

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
explode(const char *s, char *b)
{
	size_t i, j, k, l, n;
	char *p;

	p = b;
	n = strlen(s);
	for (i = 0; i < n; i++) {
		for (j = i, l = 1; j < n; j++, l++) {
			for (k = 0; k < l; k++)
				*p++ = s[j];
		}
		if (i + 1 < n)
			*p++ = '\n';
	}
	*p = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[256];

	explode(s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("", "");
	test("a", "a");
	test("bc", "bcc\nc");
	test("xyz", "xyyzzz\nyzz\nz");
	test("code-golf", "coodddeeee-----ggggggooooooollllllllfffffffff\noddeee----gggggoooooolllllllffffffff\ndee---ggggooooollllllfffffff\ne--gggoooolllllffffff\n-ggooollllfffff\ngoolllffff\nollfff\nlff\nf");
	test("s p a c e", "s  ppp    aaaaa      ccccccc        eeeeeeeee\n pp   aaaa     cccccc       eeeeeeee\np  aaa    ccccc      eeeeeee\n aa   cccc     eeeeee\na  ccc    eeeee\n cc   eeee\nc  eee\n ee\ne");

	return 0;
}
