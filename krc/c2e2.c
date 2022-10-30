// Write a loop equivalent to the for loop above without using && or ||.

#include <stdio.h>

char *
oldloop(char *buf, int lim)
{
	int i, c;

	for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; i++)
		buf[i] = c;
	buf[i] = '\0';
	return buf;
}

char *
newloop(char *buf, int lim)
{
	int state, i, c;

	i = 0;
	state = 1;
	while (state == 1) {
		if (i >= lim - 1)
			state = 0;
		else if ((c = getchar()) == '\n')
			state = 0;
		else if (c == EOF)
			state = 0;
		else
			buf[i++] = c;
	}
	buf[i] = '\0';
	return buf;
}

int
main(void)
{
	char buf[80];
	printf("%s\n", oldloop(buf, sizeof(buf)));
	printf("%s\n", newloop(buf, sizeof(buf)));
	return 0;
}
