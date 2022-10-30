/*

lPaeesh le pemu mnxit ehess rtnisg! Oh, sorry, that was supposed to say: Please help me unmix these strings!

Somehow my strings have all become mixed up; every pair of characters has been swapped. Help me undo this so I can understand my strings again.

Notes

The length of a string can be odd — in this case the last character is not altered (as there's nothing to swap it with).

*/

#include <stdio.h>

void
swapc(char *x, char *y)
{
	char t;

	t = *x;
	*x = *y;
	*y = t;
}

char *
unmix(char *s)
{
	size_t i;

	for (i = 0; s[i] != '\0' && s[i + 1] != '\0'; i += 2)
		swapc(&s[i], &s[i + 1]);
	return s;
}

int
main(void)
{
	char s1[] = "lPaeesh le pemu mnxit ehess rtnisg!";
	char s2[] = "123456";
	char s3[] = "hTsii  s aimex dpus rtni.g";
	char s4[] = "badce";
	char s5[] = " Imaf eeilgna l tilt eidzz!y";
	char s6[] = "";

	printf("%s\n", unmix(s1));
	printf("%s\n", unmix(s2));
	printf("%s\n", unmix(s3));
	printf("%s\n", unmix(s4));
	printf("%s\n", unmix(s5));
	printf("%s\n", unmix(s6));

	return 0;
}
