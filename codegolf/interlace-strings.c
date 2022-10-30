/*

Your challenge is to write a program or function that, when given two strings of equal length, swaps every other character and outputs/returns the resulting strings in either order.

Examples
"Hello," "world!" --> "Hollo!" "werld,"
"code" "golf" --> "codf" "gole"
"happy" "angry" --> "hnpry" "aagpy"
"qwerty" "dvorak" --> "qvertk" "dworay"
"1, 2, 3" "a, b, c" --> "1, b, 3" "a, 2, c"
"3.141592653589" "2.718281828459" --> "3.111291623489" "2.748582858559"
"DJMcMayhem" "trichoplax" --> "DrMcMoylex" "tJichapham"
"Doorknob" "Downgoat" --> "Doonkoot" "Dowrgnab"
"Halloween" "Challenge" --> "Hhlloeegn" "Caallwnee"

Rules
The strings will only contain ASCII chars (32-126).
The strings will always be the same length, and will never be empty.
You may accept input in any suitable format: separate parameters, items in an array, separated by one or more newlines, even concatenated. The only restriction is that one string must come fully before the other (e.g. a1\nb2\nc3 for "abc", "123" is invalid).
The output may be in either order (i.e. you can start swapping from the first or the second char), and in any valid format mentioned above. (2-item array, separated by newline(s), concatenated, etc.)

Scoring
This is code-golf, so the shortest code in bytes for each language wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
swapc(char *x, char *y)
{
	char t;

	t = *y;
	*y = *x;
	*x = t;
}

void
interlace(char *s, char *t)
{
	while (s[0] && s[1] && t[0] && t[1]) {
		swapc(&s[1], &t[1]);
		s += 2;
		t += 2;
	}
}

void
test(char *s, char *t, const char *rs, const char *rt)
{
	interlace(s, t);
	printf("%s %s\n", s, t);
	assert(!strcmp(s, rs));
	assert(!strcmp(t, rt));
}

int
main(void)
{
	char s1[] = "Hello,";
	char t1[] = "world!";

	char s2[] = "code";
	char t2[] = "golf";

	char s3[] = "happy";
	char t3[] = "angry";

	char s4[] = "qwerty";
	char t4[] = "dvorak";

	char s5[] = "1, 2, 3";
	char t5[] = "a, b, c";

	char s6[] = "3.141592653589";
	char t6[] = "2.718281828459";

	char s7[] = "DJMcMayhem";
	char t7[] = "trichoplax";

	char s8[] = "Doorknob";
	char t8[] = "Downgoat";

	char s9[] = "Halloween";
	char t9[] = "Challenge";

	test(s1, t1, "Hollo!", "werld,");
	test(s2, t2, "codf", "gole");
	test(s3, t3, "hnpry", "aagpy");
	test(s4, t4, "qvertk", "dworay");
	test(s5, t5, "1, b, 3", "a, 2, c");
	test(s6, t6, "3.111291623489", "2.748582858559");
	test(s7, t7, "DrMcMoylex", "tJichapham");
	test(s8, t8, "Doonkoot", "Dowrgnab");
	test(s9, t9, "Hhlloeegn", "Caallwnee");

	return 0;
}
