/*

Write a program that prints out the lyrics for "Ninety-nine bottles of beer", "Old McDonald had a farm" or "12 days of Christmas".

If you choose "Ninety-nine bottles of beer", you need to spell out the number, not just write the digits down. It's "Ninety-nine bottles of beer on the wall", not "99 bottles of beer"!

For Old McDonald, you need to include at least 6 animals: a cow, a chicken, a turkey, a kangaroo, a T-Rex and an animal of your choosing (Old McDonald has a weird farm).
The cow goes "moo", the chicken goes "cluck", the turkey goes "gobble", the kangaroo goes "g'day mate" and the T-Rex goes "GAAAAARGH". You can have more animals if you like.

Make your code shorter than the song it prints out!

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
lyrics(void)
{
	static const char *animals[] = {"cow", "chicken", "turkey", "kangaroo", "t-rex", "road runner"};
	static const char *sounds[] = {"moo", "cluck", "gobble", "G'day", "raagh", "meep-meep"};

	size_t i;

	for (i = 0; i < nelem(animals); i++) {
		printf("old mc donald had a farm e-i e-i o\n");
		printf("and on this farm he had an %s\n", animals[i]);
		printf("e-i e-i o\n");
		printf("with a %s and a %s there\n", sounds[i], sounds[i]);
		printf("old mc donald had a farm e-i e-i o\n");
		printf("old mc donald made strange investmets in livestock e-i-e-i-o\n");
	}
}

int
main(void)
{
	lyrics();
	return 0;
}
