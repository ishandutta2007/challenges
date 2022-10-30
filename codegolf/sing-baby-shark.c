/*

"Baby Shark" is a children's song about a family of sharks. Having long been popular as a campfire song, it has been popularized since the mid-2000s by social media, online video and radio. - Wikipedia

Write program that takes no input, and writes the following text to the standard output or an arbitrary file:

Baby Shark doo doo doo doo doo doo
Baby Shark doo doo doo doo doo doo
Baby Shark doo doo doo doo doo doo
Baby Shark!
Daddy Shark doo doo doo doo doo doo
Daddy Shark doo doo doo doo doo doo
Daddy Shark doo doo doo doo doo doo
Daddy Shark!
Mommy Shark doo doo doo doo doo doo
Mommy Shark doo doo doo doo doo doo
Mommy Shark doo doo doo doo doo doo
Mommy Shark!
Grandpa Shark doo doo doo doo doo doo
Grandpa Shark doo doo doo doo doo doo
Grandpa Shark doo doo doo doo doo doo
Grandpa Shark!
Grandma Shark doo doo doo doo doo doo
Grandma Shark doo doo doo doo doo doo
Grandma Shark doo doo doo doo doo doo
Grandma Shark!
This is code golf — shortest code wins.

Found this on Reddit^1^2, and it seems like an interesting challenge to golf.

Updates:

No newline between stanzas, that makes it too easy :)

Leading/trailing newlines are okay.

*/

#include <stdio.h>

void
sing(void)
{
	puts("Baby Shark doo doo doo doo doo doo");
	puts("Baby Shark doo doo doo doo doo doo");
	puts("Baby Shark doo doo doo doo doo doo");
	puts("Baby Shark!");
	puts("Daddy Shark doo doo doo doo doo doo");
	puts("Daddy Shark doo doo doo doo doo doo");
	puts("Daddy Shark doo doo doo doo doo doo");
	puts("Daddy Shark!");
	puts("Mommy Shark doo doo doo doo doo doo");
	puts("Mommy Shark doo doo doo doo doo doo");
	puts("Mommy Shark doo doo doo doo doo doo");
	puts("Mommy Shark!");
	puts("Grandpa Shark doo doo doo doo doo doo");
	puts("Grandpa Shark doo doo doo doo doo doo");
	puts("Grandpa Shark doo doo doo doo doo doo");
	puts("Grandpa Shark!");
	puts("Grandma Shark doo doo doo doo doo doo");
	puts("Grandma Shark doo doo doo doo doo doo");
	puts("Grandma Shark doo doo doo doo doo doo");
	puts("Grandma Shark!");
}

int
main(void)
{
	sing();
	return 0;
}
