/*

Nesting level, for this challenge, refers to the depth of the parentheses surrounding an integer.
For example, the string "(5((10)8))", 5 has a nesting level of 1 because it has one set of parentheses around it, 10 has a nesting level of 3 because it has 3 sets of parentheses around it, and 8 has a nesting level of 2.

We can score this string by multiplying each number with its nesting level and then summing up the results, as follows:

"(5((10)8))" ➞ 5*1 + 10*3 + 8*2 ➞ 51

Create a function that takes a string as its argument and returns its score.
Examples

scoreIt("()") ➞ 0

scoreIt("4(123)") ➞ 123
// 4*0 + 123*1 = 123

scoreIt("((((1)2)3)4)") ➞ 20
// 1*4 + 2*3 + 3*2 + 4*1 = 20

scoreIt("(6)8((34(7)))") ➞ 95
// 6*1 + 8*0 + 34*2 + 7*3 = 95

Notes

    The nesting for all test cases is balanced and logically consistent (there are no missing or extra parentheses).
    Test cases contain only positive integers.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef long long vlong;

vlong
score(const char *s)
{
	size_t i, p;
	char *ep;
	vlong r;

	r = 0;
	for (i = p = 0; s[i]; i++) {
		if (s[i] == '(')
			p++;
		else if (s[i] == ')')
			p--;
		else if (isdigit(s[i])) {
			r += strtoll(s + i, &ep, 10) * p;
			i = ep - s - 1;
		}
	}
	return (p) ? -1 : r;
}

int
main(void)
{
	assert(score("(5((10)8))") == 51);
	assert(score("()") == 0);
	assert(score("4(123)") == 123);
	assert(score("((((1)2)3)4)") == 20);
	assert(score("(6)8((34(7)))") == 95);
	assert(score("((()))") == 0);
	assert(score("5abc8de") == 0);
	assert(score("5(abc8de)") == 8);
	assert(score("(((((20)))))") == 100);
	assert(score("1(11(111(1111(11111))))") == 48010ll);
	assert(score("(((258(7(23))67))6)") == 1124);
	assert(score("()45((1)(((123(1)16(((34)3)2)5)56)))") == 1017);
	assert(score("(8(6(4(2(1)3)5)7)9)") == 95);
	assert(score("((76(87))7((765))876(((90(6(12))))))") == 4053);
	assert(score("(1((2(((3((((4(((((5((((((6(((((((7((((((((8(((((((((9)))))))))))))))))))))))))))))))))))))))))))))") == 1155);
	assert(score("9(99(999(9999()(99999(999999)))))") == 5432085ll);

	return 0;
}
