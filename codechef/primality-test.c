/*

Alice and Bob are meeting after a long time. As usual they love to play some math games. This times Alice takes the call and decides the game.
The game is very simple, Alice says out an integer and Bob has to say whether the number is prime or not.
Bob as usual knows the logic but since Alice doesn't give Bob much time to think, so Bob decides to write a computer program.

Help Bob accomplish this task by writing a computer program which will calculate whether the number is prime or not .

*/
#include <stdio.h>
#include <math.h>

const char *
isprime(int n)
{
	int i, l;

	if (n <= 1)
		return 0;

	l = sqrt(n);
	for (i = 2; i <= l; i++) {
		if (n % i == 0)
			return "no";
	}
	return "yes";
}

int
main(void)
{
	printf("%s\n", isprime(23));
	printf("%s\n", isprime(13));
	printf("%s\n", isprime(20));
	printf("%s\n", isprime(1000));
	printf("%s\n", isprime(99991));
	return 0;
}
