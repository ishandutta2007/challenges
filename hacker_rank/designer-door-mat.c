/*

Mr. Vincent works in a door mat manufacturing company. One day, he designed a new door mat with the following specifications:

Mat size must be NxM. (N is an odd natural number, and M is 3 times N.)
The design should have 'WELCOME' written in the center.
The design pattern should only use |, . and - characters.

Sample Designs

    Size: 7 x 21
    ---------.|.---------
    ------.|..|..|.------
    ---.|..|..|..|..|.---
    -------WELCOME-------
    ---.|..|..|..|..|.---
    ------.|..|..|.------
    ---------.|.---------

    Size: 11 x 33
    ---------------.|.---------------
    ------------.|..|..|.------------
    ---------.|..|..|..|..|.---------
    ------.|..|..|..|..|..|..|.------
    ---.|..|..|..|..|..|..|..|..|.---
    -------------WELCOME-------------
    ---.|..|..|..|..|..|..|..|..|.---
    ------.|..|..|..|..|..|..|.------
    ---------.|..|..|..|..|.---------
    ------------.|..|..|.------------
    ---------------.|.---------------
*/

#include <stdio.h>

void
center(int a, int b, int *s, int *e)
{
	*s = (b - a) / 2;
	*e = *s + a - 1;
}

void
doormat(int n, int m)
{
	static const char pat[] = ".|.";
	static const char msg[] = "WELCOME";
	static const int patsz = sizeof(pat) - 1;
	static const int msgsz = sizeof(msg) - 1;

	int i, j, l, x, y, s[2], e[2];
	const char *p;

	center(msgsz, m, &s[0], &e[0]);
	center(patsz, m, &s[1], &e[1]);

	for (i = 0; i < n; i++) {
		if (i != n / 2) {
			p = pat;
			l = patsz;
			x = s[1];
			y = e[1];
		} else {
			p = msg;
			l = msgsz;
			x = s[0];
			y = e[0];
		}

		for (j = 0; j < m; j++) {
			if (x <= j && j <= y)
				printf("%c", p[(j - x) % l]);
			else
				printf("-");
		}
		printf("\n");

		if (i < n / 2) {
			s[1] -= patsz;
			e[1] += patsz;
		} else {
			s[1] += patsz;
			e[1] -= patsz;
		}
	}
	printf("\n");
}

int
main(void)
{
	doormat(7, 21);
	doormat(11, 33);
	doormat(9, 27);
	return 0;
}
