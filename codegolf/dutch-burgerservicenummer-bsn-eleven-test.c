/*

Introduction:

A Dutch BSN (BurgerServiceNummer) is valid when it complies to the following rules:

    It only contains digits.
    The length should be either 8 or 9 in length.
    When the digits are indexed as A through I, the result of the following sum: 9xA + 8xB + 7xC + 6xD + 5xE + 4xF + 3xG + 2xH + -1xI (NOTE the -1 instead of 1!) should be divisible by 11, and should not be 0.

Challenge:

Input: A string or char-array representing the BSN.

Output: A truthy or falsey result whether the input is a valid BSN.
Challenge Rules:

    The input format should be a string or char-array. You are not allowed to use an int-array of digits, or a (possibly octal) number. (You are allowed to convert it to an int-array of digits yourself, though, but not directly as argument.)
    Despite the restriction on the input above, you can assume all test cases will contain one or more digits ([0-9]+)
    Regarding the BSN with length 8 instead of 9, the Dutch Wikipedia states the following: "For the eleven-test and for other practical uses, a leading zero is added to make the number of length 9." (source)

General rules:

    This is code-golf, so shortest answer in bytes wins.
    Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
    Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters, full programs. Your call.
    Default Loopholes are forbidden.
    If possible, please add a link with a test for your code.
    Also, please add an explanation if necessary.

Test cases:

// Truthy test cases:
111222333
123456782
232262536
010464554
10464554
44016773

// Falsey test cases:
000000000
192837465
247594057
88888888
73
3112223342
000000012

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool
isbsn(const char *s)
{
	size_t i, n;
	int r, v;

	for (n = 0; s[n] && n < 10; n++) {
		if (!isdigit(s[n]))
			return false;
	}

	if (n != 8 && n != 9)
		return false;

	r = 0;
	v = n;
	for (i = 0; i < n; i++) {
		r += v * (s[i] - '0');
		v = (v > 2) ? v - 1 : -1;
	}
	return r && !(r % 11);
}

int
main(void)
{
	assert(isbsn("111222333") == true);
	assert(isbsn("123456782") == true);
	assert(isbsn("232262536") == true);
	assert(isbsn("010464554") == true);
	assert(isbsn("10464554") == true);
	assert(isbsn("44016773") == true);

	assert(isbsn("000000000") == false);
	assert(isbsn("192837465") == false);
	assert(isbsn("247594057") == false);
	assert(isbsn("88888888") == false);
	assert(isbsn("73") == false);
	assert(isbsn("3112223342") == false);
	assert(isbsn("000000012") == false);

	return 0;
}
