/*

You're able to call numbers like 1-800-flowers which replace the characters with the associated numbers on a cellular device keyboard.
Conversion

abc  = 2
def  = 3
ghi  = 4
jkl  = 5
mno  = 6
pqrs = 7
tuv  = 8
wxyz = 9

This is your task:

    Create a function that takes a string as argument.
    Convert all letters to numbers by using a cellular device keyboard as reference and leave any other characters in.
    Return a string containing the argument with replaced letters.

Examples

dial("1-800-HOTLINEBLING") ➞ "1-800-468546325464"

dial("abc-def-ghi-jkl!!") ➞ "222-333-444-555!!"

dial("adgjmptw :)") ➞ "23456789 :)"

Notes

    While when you would write a SMS back in the day, to enter "b", you would have to press "2" twice. When calling numbers this is not the case as the range a-c gets converted to "2".
    Given string can contain upper and lowercase letters.
    Enjoy and good luck!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
dial(const char *s, char *b)
{
	static const char tab[256] = {
	    ['a'] = '2',
	    ['b'] = '2',
	    ['c'] = '2',
	    ['d'] = '3',
	    ['e'] = '3',
	    ['f'] = '3',
	    ['g'] = '4',
	    ['h'] = '4',
	    ['i'] = '4',
	    ['j'] = '5',
	    ['k'] = '5',
	    ['l'] = '5',
	    ['m'] = '6',
	    ['n'] = '6',
	    ['o'] = '6',
	    ['p'] = '7',
	    ['q'] = '7',
	    ['r'] = '7',
	    ['s'] = '7',
	    ['t'] = '8',
	    ['u'] = '8',
	    ['v'] = '8',
	    ['w'] = '9',
	    ['x'] = '9',
	    ['y'] = '9',
	    ['z'] = '9',
	};

	size_t i;

	for (i = 0; s[i]; i++) {
		b[i] = tab[tolower(s[i]) & 0xff];
		if (!b[i])
			b[i] = s[i];
	}
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[256];
	dial(s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("1-800-HOTLINEBLING", "1-800-468546325464");
	test("hello-world!", "43556-96753!");
	test("aaaabcccdefggg", "22222222333444");
	test("01023468adghijgkmz?", "010234682344454569?");
	test("SwApPeDcAsE", "79277332273");
	test("VAPORWAVE", "827679283");

	return 0;
}
