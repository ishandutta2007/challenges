/*

Inspired by Does the start equal the end

Given a string s and an integer n, output a truthy/falsey as to whether the nth char in s equals the nth from the end char in s.

Input
A non-empty string and an integer. You can use 0-based indexing or 1-based indexing. The integer is guaranteed to be valid based on the string.
For example, if the string is "supercalifragalistic123", the integer can be from 1 to 23 for 1-based indexing, and 0 to 22 for 0-based indexing. Please note that n can be larger than half the length of s.

Input is limited to printable ASCII.

Output
A truthy/falsey value based on whether the nth value in s equals the nth from last value in s.

Please note that the last char is in position 0 for 0-based indexing and position 1 for 1-based indexing. Think of it as comparing the string to its reverse.

Test Cases
0-indexed

"1", 0         Truthy 1 == 1
"abc", 1       Truthy b == b
"aaaaaaa", 3   Truthy a == a
"[][]", 1      Falsey ] != [
"[][]", 0      Falsey [ != ]
"ppqqpq", 2    Truthy q == q
"ababab", 5    Falsey a != b
"12345", 0     Falsey 1 != 5
"letter", 1    Truthy e == e
"zxywv", 3     Falsey w != x
1-indexed

"1", 1         Truthy 1 == 1
"abc", 2       Truthy b == b
"aaaaaaa", 4   Truthy a == a
"[][]", 2      Falsey ] != [
"[][]", 1      Falsey [ != ]
"ppqqpq", 3    Truthy q == q
"ababab", 6    Falsey a != b
"12345", 1     Falsey 1 != 5
"letter", 2    Truthy e == e
"zxywv", 4     Falsey w != x

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool
equal(const char *s, size_t i)
{
	size_t n;

	n = strlen(s);
	if (i >= n)
		return false;
	return s[i] == s[n - i - 1];
}

int
main(void)
{
	assert(equal("1", 0) == true);
	assert(equal("abc", 1) == true);
	assert(equal("aaaaaaa", 3) == true);
	assert(equal("[][]", 1) == false);
	assert(equal("[][]", 0) == false);
	assert(equal("ppqqpq", 2) == true);
	assert(equal("ababab", 5) == false);
	assert(equal("12345", 0) == false);
	assert(equal("letter", 1) == true);
	assert(equal("zxywv", 3) == false);

	return 0;
}
