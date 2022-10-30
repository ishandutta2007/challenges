/*

The Challenge

The goal of this challenge is to determine whether a given String can be typed using only one line of a standard UK QWERTY keyboard.

This is code golf, so shortest solution in bytes wins!

IO
Input will be a single String of zero or more characters in the ASCII decimal range of 32-126 inclusive. You may assume for this challenge that an empty String requires no typing and thus can be typed using a single line.

You may take the input as a String, list of characters, or equivalent form for your language.

Output should be a truthy value for any String that can be typed using a single line, or falsey for one that cannot.

Keyboard layout
To clarify any ambiguity over what the standard keyboard layout is below is a list of keys available on each line, including alternate upper keys (accessed using shift).

Line 1
Standard: `1234567890-=
Line 2
Standard: qwertyuiop[]
Line 3
Standard: asdfghjkl;'#
Uppercase: ASDFGHJKL
Special: Caps Lock
Line 4
Standard: \zxcvbnm,./
Alternate: |<>?
Uppercase: ZXCVBNM
Special: Shift
Line 5
Special: Space Bar
Alternate upper keys can only be pressed if Shift is also on the same line, and uppercase keys can only be accessed through Caps Lock or Shift. You really can only use one keyboard line!

Test cases
            -> true     (empty string)
45-2=43     -> true     (line 1)
qwerty      -> true     (line 2)
tryitout    -> true     (line 2)
Qwerty      -> false    (no shift or caps on line 2)
#sad        -> true     (line 3)
AsDf        -> true     (caps lock used)
@sDF        -> false    (no shift for alternate upper)
zxcvbn?     -> true     (line 4)
zxc vbn     -> false    (spacebar on separate line)
123abc      -> false    (multiple lines)
            -> true     (just space bar)
!!!         -> false    (exclamation marks cannot be printed by a single line)

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
olkb(const char *s)
{
	static const char keys[][32] = {
	    "`1234567890-=",
	    "qwertyuiop[]",
	    "asdfghjkl;'#ASDFGHJKL",
	    "\\zxcvbnm,./|<>?ZXCVBNM",
	    " ",
	};

	size_t i, n, m;

	for (i = 0; s[i]; i++) {
		for (n = 0; n < nelem(keys); n++) {
			if (strchr(keys[n], s[i]))
				break;
		}

		if (i == 0)
			m = n;

		if (n == nelem(keys) || n != m)
			return false;
	}

	return true;
}

int
main(void)
{
	assert(olkb("") == true);
	assert(olkb("45-2=43") == true);
	assert(olkb("qwerty") == true);
	assert(olkb("tryitout") == true);
	assert(olkb("Qwerty") == false);
	assert(olkb("#sad") == true);
	assert(olkb("AsDf") == true);
	assert(olkb("@sDF") == false);
	assert(olkb("zxcvbn?") == true);
	assert(olkb("zxc vbn") == false);
	assert(olkb("123abc") == false);
	assert(olkb(" ") == true);
	assert(olkb("!!!") == false);

	return 0;
}
