/*

Write a function to replace all instances of character c1 with character c2 and vice versa.
Examples

doubleSwap( "aabbccc", "a", "b") ➞ "bbaaccc"

doubleSwap("random w#rds writt&n h&r&", "#", "&")
➞ "random w&rds writt#n h#r#"

doubleSwap("128 895 556 788 999", "8", "9")
➞ "129 985 556 799 888"

Notes

Both characters will show up at least once in the string.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
doubleswap(char *s, int a, int b)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] == a)
			s[i] = b;
		else if (s[i] == b)
			s[i] = a;
	}
	return s;
}

void
test(char *s, char a, char b, const char *t)
{
	doubleswap(s, a, b);
	assert(strcmp(s, t) == 0);
}

int
main(void)
{
	char s1[] = "aabbccc";
	char s2[] = "random w#rds writt&n h&r&";
	char s3[] = "128 895 556 788 999";
	char s4[] = "mamma mia";
	char s5[] = "**##**";
	char s6[] = "123456789";
	char s7[] = "445566&&";
	char s8[] = "!?@,.";
	char s9[] = "Q_Q T_T =.= >.<";
	char s10[] = "(Q_Q) (T_T) (=.=) (>.<)";
	char s11[] = "<>";
	char s12[] = "001101";
	char s13[] = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

	test(s1, 'a', 'b', "bbaaccc");
	test(s2, '#', '&', "random w&rds writt#n h#r#");
	test(s3, '8', '9', "129 985 556 799 888");
	test(s4, 'm', 'a', "amaam aim");
	test(s5, '*', '#', "##**##");
	test(s6, '4', '5', "123546789");
	test(s7, '4', '&', "&&556644");
	test(s8, ',', '.', "!?@.,");
	test(s9, 'Q', 'T', "T_T Q_Q =.= >.<");
	test(s10, ')', '(', ")Q_Q( )T_T( )=.=( )>.<(");
	test(s11, '>', '<', "><");
	test(s12, '1', '0', "110010");
	test(s13, 'a', 'b', "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`bacdefghijklmnopqrstuvwxyz{|}~");

	return 0;
}
