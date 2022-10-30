/*

This was related to a program I am writing. Although the title is simple, the challenge is a lot more complicated.

Your challenge
You must write a program that takes an input, and your answer must match the sample outputs in this question.

What the program should be is that you must output "HelloWorld" with the length of the input matching the length of what you output.
If the input's length is not divisible with 10, you should cut off the last few letters until it matches the length of the last few letters of the input.
More clarification in the examples.

Standard loopholes apply, except that answers should be full programs, and the input has to be printable ASCII.

Example inputs
Input:how are you
Output:HelloWorldH

Note: In the above example, there is an extra H due to the
characters in the input being 11, so we add an extra letter

Input:hrienehwnv
Output:HelloWorld

Input:kill him at dawn
Output:HelloWorldHelloW

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
rep(const char *s, char *b)
{
	static const char text[] = "HelloWorld";

	size_t i;

	for (i = 0; s[i]; i++)
		b[i] = text[i % (sizeof(text) - 1)];
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	rep(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("how are you", "HelloWorldH");
	test("hrienehwnv", "HelloWorld");
	test("kill him at dawn", "HelloWorldHelloW");

	return 0;
}
