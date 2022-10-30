/*

I'm a mentor at RubyLearning and one of the exercises we give to our students is the "Deaf Grandma" exercise from Chris Pine's book "Learn to Program". Here's the description:

    Write a Deaf Grandma program. Whatever you say to grandma (whatever you type in), she should respond with: "Huh?! Speak up, sonny!", unless you shout it (type in all capitals).
	If you shout, she can hear you (or at least she thinks so) and yells back: "No, not since 1938!"

    To make your program really believable, have grandma shout a different year each time; maybe any year at random between 1930 and 1950.
	(This part is optional, and would be much easier if you read the section on Ruby's random number generator at the end of the methods chapter.)
	You can't stop talking to grandma until you shout "BYE".

After several course iterations I tried to see how small I can get this and now have it down to 112 characters:

puts (s||='').upcase==s ? "NO, NOT SINCE #{1930+rand(21)}!":"HUH?! SPEAK UP, SONNY!" until(s=gets.chomp)=="BYE"

I'm curious to see in how few characters this can be achieved in the language of your choice, because I think Ruby is already doing really well here.

Edit: The Perl solution posted below led to

ruby -nle 'puts($_=="BYE"?exit: $_.upcase!? "HUH?! SEPAK UP, SONNY!":"NO, NOT SINCE #{1930+rand(21)}!")'

which is 92 characters for the expression + 2 more for the n and l options.


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int
allcaps(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (isalpha(s[i]) && !isupper(s[i]))
			return 0;
	}
	return 1;
}

void
deafness(FILE *fp)
{
	char b[4096];

	while (fgets(b, sizeof(b), fp)) {
		if (!allcaps(b))
			printf("Huh?! Speak up, sonny!\n");
		else
			printf("No, not since %d!\n", 1930 + (rand() % 21));
	}
}

int
main(void)
{
	srand(time(NULL));
	deafness(stdin);
	return 0;
}
