/*

Challenge

Given a string made of ijk, interpret it as the product of imaginary units of quaternion and simplify it into one of the eight possible values 1, -1, i, -i, j, -j, k, -k.

The evaluation rules are as follows:

ii=jj=kk=−1ij=k,jk=i,ki=jji=−k,kj=−i,ik=−j

The multiplication of quaternions is associative but not commutative. This means that you may do the simplification in any order, but you cannot reorder the items.

For the I/O format, function parameter and return from a function should be done as a string (list of chars or list of codepoints is also OK).
You may assume the input is not empty. You may output any amount of leading and trailing whitespace (spaces, tabs, newlines).

Test cases

i -> i
j -> j
k -> k
ij -> k
ji -> -k
kk -> -1
ijkj -> -j
iikkkkkjj -> k
kikjkikjk -> -k
kjijkjikijkjiki -> 1
jikjjikjikjikjjjj -> j

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int x, y, z, w;
} quat;

quat
qc(int c)
{
	switch (c) {
	case '1':
		return (quat){0, 0, 0, 1};
	case 'i':
		return (quat){1, 0, 0, 0};
	case 'j':
		return (quat){0, 1, 0, 0};
	case 'k':
		return (quat){0, 0, 1, 0};
	}
	return (quat){0, 0, 0, 0};
}

quat
qmul(quat a, quat b)
{
	return (quat){
	    .x = a.x * b.w + a.w * b.x + a.y * b.z - a.z * b.y,
	    .y = a.y * b.w + a.w * b.y + a.z * b.x - a.x * b.z,
	    .z = a.z * b.w + a.w * b.z + a.x * b.y - a.y * b.x,
	    .w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
	};
}

char *
qstr(quat a, char *b)
{
	const char *elts = " ijk";
	const int elms[] = {
	    a.w,
	    a.x,
	    a.y,
	    a.z,
	};

	int i, l, v;

	l = 0;
	for (i = 0; i < 4; i++) {
		v = elms[i];
		if (v < 0) {
			l += sprintf(b + l, "-");
			v = -v;
		}
		if (v == 0)
			continue;
		if (v != 1 || i == 0)
			l += sprintf(b + l, "%d", v);
		if (i > 0)
			l += sprintf(b + l, "%c", elts[i]);
		l += sprintf(b + l, "+");
	}
	if (l)
		b[l - 1] = '\0';
	else
		sprintf(b, "0");

	return b;
}

char *
simplify(const char *s, char *b)
{
	quat r;
	size_t i;

	r = qc('1');
	for (i = 0; s[i]; i++)
		r = qmul(r, qc(s[i]));
	return qstr(r, b);
}

void
test(const char *s, const char *r)
{
	char b[128];

	simplify(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("i", "i");
	test("j", "j");
	test("k", "k");
	test("ij", "k");
	test("ji", "-k");
	test("kk", "-1");
	test("ijkj", "-j");
	test("iikkkkkjj", "k");
	test("kikjkikjk", "-k");
	test("kjijkjikijkjiki", "1");
	test("jikjjikjikjikjjjj", "j");
	test("0", "0");

	return 0;
}
