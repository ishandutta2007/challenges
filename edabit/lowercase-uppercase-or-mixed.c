/*

Create a function which returns "upper" if all the letters in a word are uppercase, "lower" if lowercase and "mixed" for any mix of the two.

Notes

Ignore punctuation, spaces and numbers.

*/

#include <stdio.h>
#include <ctype.h>

const char *
getcase(const char *s)
{
	size_t i, x, y;

	x = y = 0;
	for (i = 0; s[i]; i++) {
		x += islower(s[i]);
		y += isupper(s[i]);
	}
	if (x && !y)
		return "lower";
	if (!x && y)
		return "upper";
	return "mixed";
}

int
main(void)
{
	printf("%s\n", getcase("whisper..."));
	printf("%s\n", getcase("SHOUT!"));
	printf("%s\n", getcase("Indoor Voice"));
	printf("%s\n", getcase("324324Indoor66453546Voice434"));
	printf("%s\n", getcase("!!!!SHOUT!!!!"));
	printf("%s\n", getcase("......313whisper2131232..."));
	return 0;
}
