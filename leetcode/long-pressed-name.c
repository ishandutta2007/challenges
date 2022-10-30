/*

Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

*/

#include <stdio.h>

int
longpressed(const char *name, const char *typed)
{
	size_t i, j;
	int f;

	i = j = 0;
	for (;;) {
		if (!name[i] && !typed[j])
			break;

		if (name[i] != typed[j])
			return 0;

		while (name[i] == typed[j]) {
			j++;
			f = 0;
			if (name[i] == name[i + 1]) {
				i++;
				f = 1;
			}
		}
		if (!f)
			i++;
	}
	return 1;
}

int
main(void)
{
	printf("%d\n", longpressed("alex", "aaleex"));
	printf("%d\n", longpressed("saeed", "ssaaedd"));
	printf("%d\n", longpressed("saeed", "ssaaeedd"));
	printf("%d\n", longpressed("leelee", "lleeelee"));
	printf("%d\n", longpressed("laiden", "laiden"));
	return 0;
}
