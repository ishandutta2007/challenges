/*

Given a string, create a function to reverse the case. All lower-cased letters should be upper-cased, and vice versa.

Examples

ReverseCase("Happy Birthday") ➞ "hAPPY bIRTHDAY"

ReverseCase("MANY THANKS") ➞ "many thanks"

ReverseCase("sPoNtAnEoUs") ➞ "SpOnTaNeOuS"

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
revcase(const char *s, char *b)
{
	size_t i;
	for (i = 0; s[i]; i++)
		b[i] = (islower(s[i])) ? toupper(s[i]) : tolower(s[i]);
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	assert(!strcmp(revcase(s, b), r));
}

int
main(void)
{
	test("Happy Birthday", "hAPPY bIRTHDAY");
	test("MANY THANKS", "many thanks");
	test("sPoNtAnEoUs", "SpOnTaNeOuS");
	test("eXCELLENT, yOuR mAJESTY", "Excellent, YoUr Majesty");

	return 0;
}
