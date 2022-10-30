/*

Some people count sheep to get to sleep. Others count goats.

Write a program or function that takes in a positive integer N and outputs N-1 awake goats followed by one sleeping goat, as if someone was counting N goats and at the very last one they fell asleep.

Awake goats look like this:

      \
  ___/o>
-(___)"
 '' ''
Sleeping goats look like this:

      \
  ___/->
,(___)"
 `` ``
They are chained together with a single space between beard and tail of adjacent goats:

      \       \       \
  ___/o>  ___/o>  ___/->
-(___)" -(___)" ,(___)"
 '' ''   '' ''   `` ``
The output is allowed to have trailing spaces and a single trailing newline.

The shortest code in bytes wins.

Examples
N = 1:

      \
  ___/->
,(___)"
 `` ``
N = 2:

      \       \
  ___/o>  ___/->
-(___)" ,(___)"
 '' ''   `` ``
N = 3:

      \       \       \
  ___/o>  ___/o>  ___/->
-(___)" -(___)" ,(___)"
 '' ''   '' ''   `` ``
N = 4:

      \       \       \       \
  ___/o>  ___/o>  ___/o>  ___/->
-(___)" -(___)" -(___)" ,(___)"
 '' ''   '' ''   '' ''   `` ``
Larger N should work just as well.

*/

#include <stdio.h>

void
goat(int n)
{
	static const char *awake[] = {
	    "      \\ ",
	    "  ___/o>",
	    "-(___)\" ",
	    " '' ''  ",
	};

	static const char *sleep[] = {
	    "       \\",
	    "  ___/->",
	    ",(___)\" ",
	    " `` ``  ",
	};

	const char *p;
	int i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < n; j++) {
			p = (j + 1 < n) ? awake[i] : sleep[i];
			printf("%s\t", p);
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	int i;

	for (i = 1; i <= 10; i++)
		goat(i);

	return 0;
}
