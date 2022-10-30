/*

1000 Lockers Problem.

In an imaginary high school there exist 1000 lockers labelled 1, 2, ..., 1000. All of them are closed. 1000 students are to "toggle" a locker's state.
 * The first student toggles all of them * The second one toggles every other one (i.e, 2, 4, 6, ...) * The third one toggles the multiples of 3 (3, 6, 9, ...) and so on until all students have finished.

To toggle means to close the locker if it is open, and to open it if it's closed.

How many and which lockers are open in the end?

Thanks to ladaghini for submitting this challenge to /r/dailyprogrammer_ideas!

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

@luxgladius:

Let the factors of a number n be f1, f2, f3, f4,... where f1 * f2=f3 * f4 ...= n.
Naturally all the factors must be less than or equal to n. Equally naturally, they all must occur in pairs EXCEPT if f1=f2, which is to say that n is a perfect square.
So each number in an interval has an even number of factors unless it is a perfect square. An even number of toggles equates to a closed state since counting by each factor you will pass over the number once,
so each locker is closed except for those perfect squares.

Example: 8 has factors 1, 2, 4, and 8. 9 has factors 1, 3, and 9. Therefore 8 will be toggled four times (closed) and 9 will be toggled 3 times (open).

*/

void
solve(void)
{
	size_t i, j, k, n;
	char l[1000];

	memset(l, 0, sizeof(l));
	for (i = k = 1; i <= nelem(l); i++, k++) {
		for (j = i; j <= nelem(l); j += k)
			l[j - 1] = !l[j - 1];
	}

	n = 0;
	for (i = 0; i < nelem(l); i++) {
		if (l[i]) {
			printf("%zu ", i + 1);
			n++;
		}
	}
	printf("\n");
	printf("%zu lockers opened\n", n);
}

int
main(void)
{
	solve();
	return 0;
}
