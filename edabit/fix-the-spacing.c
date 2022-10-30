/*

Additional spaces have been added to a sentence. Return the correct sentence by removing them.
All words should be separated by one space, and there should be no spaces at the beginning or end of the sentence.

*/

#include <stdio.h>
#include <ctype.h>

char *
fixspace(char *s)
{
	size_t i, j;

	i = 0;
	while (isspace(s[i]))
		i++;

	for (j = 0; s[i];) {
		s[j++] = s[i++];
		if (isspace(s[i - 1])) {
			while (isspace(s[i]))
				i++;
		}
	}

	if (j > 0 && isspace(s[j - 1]))
		s[j - 1] = '\0';
	else
		s[j] = '\0';

	return s;
}

int
main(void)
{
	char s1[] = "The film   starts       at      midnight. ";
	char s2[] = "The     waves were crashing  on the     shore.   ";
	char s3[] = " Always look on    the bright   side of  life.";
	char s4[] = " A  glittering  gem     is    not   enough.  ";
	char s5[] = "   She      did  her best  to  help    him.  ";
	char s6[] = "  They      made  sure   to get   there  early. ";
	char s7[] = "  She  did   her      best     to   help him. ";
	char s8[] = "      I     love  eating    toasted  cheese   and tuna  sandwiches.";
	char s9[] = "  There     were  foggy   conditions on   the      trail.   ";
	char s10[] = "     The  roads   were  impassable  due to      snow.  ";
	char s11[] = " Better   to      paint  with  bold  colors.   ";
	char s12[] = "     Remember to  stretch      before you  run.  ";
	char s13[] = "  You  rarely    see  a royal   flush     in   poker. ";
	char s14[] = "  She was too      short     to   see    over  the   fence.   ";
	char s15[] = "   I   will  post     the letter      tonight.  ";
	char s16[] = " He      could  not remember   a     thing.   ";
	char s17[] = "      Sometimes     it    is  better   to  just walk away.";
	char s18[] = " A   lack   of      stirring  makes  the sauce     stick.  ";
	char s19[] = "   I      really   want  my dessert.  ";
	char s20[] = "   Let      me help you  with     your    bags.   ";
	char s21[] = "      Around  the world     in   eighty   days.  ";
	char s22[] = "      The soup   of    the  day   is     lentil. ";
	char s23[] = "    Winter is   coming. ";
	char s24[] = "";
	char s25[] = "       ";

	printf("\"%s\"\n", fixspace(s1));
	printf("\"%s\"\n", fixspace(s2));
	printf("\"%s\"\n", fixspace(s3));
	printf("\"%s\"\n", fixspace(s4));
	printf("\"%s\"\n", fixspace(s5));
	printf("\"%s\"\n", fixspace(s6));
	printf("\"%s\"\n", fixspace(s7));
	printf("\"%s\"\n", fixspace(s8));
	printf("\"%s\"\n", fixspace(s9));
	printf("\"%s\"\n", fixspace(s10));
	printf("\"%s\"\n", fixspace(s11));
	printf("\"%s\"\n", fixspace(s12));
	printf("\"%s\"\n", fixspace(s13));
	printf("\"%s\"\n", fixspace(s14));
	printf("\"%s\"\n", fixspace(s15));
	printf("\"%s\"\n", fixspace(s16));
	printf("\"%s\"\n", fixspace(s17));
	printf("\"%s\"\n", fixspace(s18));
	printf("\"%s\"\n", fixspace(s19));
	printf("\"%s\"\n", fixspace(s20));
	printf("\"%s\"\n", fixspace(s21));
	printf("\"%s\"\n", fixspace(s22));
	printf("\"%s\"\n", fixspace(s23));
	printf("\"%s\"\n", fixspace(s24));
	printf("\"%s\"\n", fixspace(s25));

	return 0;
}
