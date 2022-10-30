/*

Mubashir is going on a secret mission. He needs your help but you have to learn how to encode a secret password to communicate safely with other agents. Create a function that takes an argument message and returns the encoded password.

There are some variations on the rules of encipherment. One version of the cipher rules are outlined below:

secretPassword("mubashirh") ➞ "hsajsi13u2"

Step 1: Message length should be of nine characters containing only lowercase letters from 'a' to 'z'. If the argument doesn't meet this requirement you must return "BANG! BANG! BANG!" (Remember, there are no second chances in the spy world!)

Step 2: Divide the string into three equal parts of three characters each:

1 - mub
2 - ash
3 - irh

Step 3: Convert the first and third letter to the corresponding number, according to the English alphabets (ex. a = 1, b = 2, c = 3 ... z = 26, etc).

mub = 13u2

Step 4: Reverse the fourth, fifth, and sixth letters:

ash = hsa

Step 5: Replace seventh, eighth, and ninth letter with next letter (z will be substituted with a).

irh = jsi

Step 6: Return the string in the following order: "Part_2+Part_3+Part_1"

"hsajsi13u2"

See the below examples for a better understanding:
Examples

secretPassword("mubashirh") ➞ "hsajsi13u2"

secretPassword("mattedabi") ➞ "detbcj13a20"

secretPassword("HeLen-eda") ➞ "BANG! BANG! BANG!"
// Length is not equal to 9
// Contains characters other than lower alphabets

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
secretize(const char *s, char *b, size_t n)
{
	size_t i;

	for (i = 0; s[i] && i < 10; i++) {
		if (!('a' <= s[i] && s[i] <= 'z'))
			break;
	}
	if (i != 9) {
		snprintf(b, n, "BANG! BANG! BANG!");
		return b;
	}

	snprintf(b, n, "%c%c%c%c%c%c%d%c%d",
	         s[5], s[4], s[3],
	         (s[6] != 'z') ? s[6] + 1 : 'a',
	         (s[7] != 'z') ? s[7] + 1 : 'a',
	         (s[8] != 'z') ? s[8] + 1 : 'a',
	         s[0] - 'a' + 1,
	         s[1],
	         s[2] - 'a' + 1);

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	secretize(s, b, sizeof(b));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("mubashirh", "hsajsi13u2");
	test("mattedabi", "detbcj13a20");
	test("HeLen-eda", "BANG! BANG! BANG!");
	test("pakistani", "tsiboj16a11");
	test("airforce1", "BANG! BANG! BANG!");
	test("airforces", "rofdft1i18");
	test("Airforcee", "BANG! BANG! BANG!");
	test("pilotmuba", "mtovcb16i12");
	test("a_rforcee", "BANG! BANG! BANG!");
	test("iloveherh", "hevfsi9l15");
	test("airforcess", "BANG! BANG! BANG!");
	test("edabit", "BANG! BANG! BANG!");

	return 0;
}
