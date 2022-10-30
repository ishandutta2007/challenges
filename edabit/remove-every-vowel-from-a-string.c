/*

Create a function that takes a string and returns a new string with all vowels removed.

Notes

    "y" is not considered a vowel.
    Expect a valid string for all test cases.

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isvowel(int c)
{
	return strchr("aeiou", tolower(c)) != NULL;
}

char *
rmvow(char *s)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (isvowel(s[i]))
			continue;
		s[j++] = s[i];
	}
	s[j] = '\0';
	return s;
}

int
main(void)
{
	char s1[] = "If Obama resigns from office NOW, thereby doing a great service to the country—I will give him free lifetime golf at any one of my courses!";
	printf("%s\n", rmvow(s1));

	char s2[] = "This election is a total sham and a travesty. We are not a democracy!";
	printf("%s\n", rmvow(s2));

	char s3[] = "I have never seen a thin person drinking Diet Coke.";
	printf("%s\n", rmvow(s3));

	char s4[] = "Everybody wants me to talk about Robert Pattinson and not Brian Williams—I guess people just don’t care about Brian!";
	printf("%s\n", rmvow(s4));

	char s5[] = "Katy, what the hell were you thinking when you married loser Russell Brand. There is a guy who has got nothing going, a waste!";
	printf("%s\n", rmvow(s5));

	char s6[] = "Windmills are the greatest threat in the US to both bald and golden eagles. Media claims fictional ‘global warming’ is worse.";
	printf("%s\n", rmvow(s6));

	char s7[] = "Sorry losers and haters, but my I.Q. is one of the highest -and you all know it! Please don’t feel so stupid or insecure,it’s not your fault";
	printf("%s\n", rmvow(s7));

	char s8[] = "Happy Thanksgiving to all--even the haters and losers!";
	printf("%s\n", rmvow(s8));

	char s9[] = "Watch Kasich squirm --- if he is not truthful in his negative ads I will sue him just for fun!";
	printf("%s\n", rmvow(s9));

	char s10[] = "Obama is, without question, the WORST EVER president. I predict he will now do something really bad and totally stupid to show manhood!";
	printf("%s\n", rmvow(s10));

	char s11[] = "I have never seen a thin person drinking Diet Coke.";
	printf("%s\n", rmvow(s11));

	char s12[] = "We're gonna build a wall!";
	printf("%s\n", rmvow(s12));

	return 0;
}
