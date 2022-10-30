/*

Your task is to print this exact text: (the Greek alphabet in words)

alpha beta gamma delta epsilon zeta eta theta iota kappa lambda mu nu xi omicron pi rho sigma tau upsilon phi chi psi omega

Capitalization does not matter.

Remember, this is code-golf, so the code with the smallest number of bytes wins.

*/

#include <stdio.h>

int
main(void)
{
	static const char *text = "alpha beta gamma delta epsilon zeta eta theta iota kappa lambda mu nu xi omicron pi rho sigma tau upsilon phi chi psi omega";

	printf("%s\n", text);
	return 0;
}
